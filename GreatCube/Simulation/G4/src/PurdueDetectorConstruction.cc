#include <G4Material.hh>
#include <G4NistManager.hh>
#include <G4Box.hh>
#include <G4Tubs.hh>
#include "TMath.h"


#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
//#include <G4PVParameterised.hh>

#include <G4SDManager.hh>
#include <G4SubtractionSolid.hh>
#include <G4ThreeVector.hh>
#include <G4RotationMatrix.hh>
#include <G4VisAttributes.hh>
#include <G4Colour.hh>
#include <globals.hh>

#include <vector>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cassert>

using std::vector;
using std::stringstream;
using std::max;

#include "PurdueDetectorMessenger.hh"
#include "PurdueEljenSensitiveDetector.hh"
#include "PurdueDetectorConstruction.hh"

#include "G4PhysicalVolumeStore.hh"

#include "TFile.h"
#include "TParameter.h"

#include <cmath>
#define pi (acos(-1.0))

map<G4String, G4double> PurdueDetectorConstruction::m_hGeometryParameters;

PurdueDetectorConstruction::PurdueDetectorConstruction(G4String fName)
{ 
  detRootFile = fName;
  pLeadSleeves = true;
  pMeasurement = "Energy";
  
  G4ThreeVector hZero(0., 0., 0.);
  m_hThirdDetector = hZero;
  m_hSecondDetector = hZero;
  m_hFirstDetector = hZero;
  m_pDetectorMessenger = new PurdueDetectorMessenger(this);
}

PurdueDetectorConstruction::~PurdueDetectorConstruction()
{
  delete m_pDetectorMessenger;
}

void PurdueDetectorConstruction::DefineMaterials()
{
  G4NistManager* pNistManager = G4NistManager::Instance();
  G4int atomnumber;
  
  //===============================Elements====================================
  
  G4Element *C  = pNistManager->FindOrBuildElement("C");
  G4Element *H  = pNistManager->FindOrBuildElement("H");;
  //G4Element *Al = pNistManager->FindOrBuildElement("Al");

  //=============================Materials=====================================

  //---------------------------------Air---------------------------------------
  pNistManager->FindOrBuildMaterial("G4_AIR");

  //--------------------------------Water-----------------------------------
  pNistManager->FindOrBuildMaterial("G4_WATER");

  //-------------------------------Polyetheylene-----------------------------------
  pNistManager->FindOrBuildMaterial("G4_POLYETHYLENE");

}

void PurdueDetectorConstruction::DefineGeometryParameters()
{
  m_hGeometryParameters["tolerance"] = 10. *mm;
  
  //============================Laboratory=====================================

  m_hGeometryParameters["Lab_height"] = 10000. *mm;
  m_hGeometryParameters["Lab_width"] = 10000. *mm;
  m_hGeometryParameters["Lab_depth"] = 10000. *mm;

  //===============================Walls=======================================
  m_hGeometryParameters["Room_height"] = 3500. *mm;
  m_hGeometryParameters["Room_width"] = 2800. *mm;
  m_hGeometryParameters["Room_depth"] = 5000. *mm;

  m_hGeometryParameters["FrontWall_thickness"] = 790. *mm;
  m_hGeometryParameters["BackWall_thickness"] = 180. *mm;
  m_hGeometryParameters["LeftWall_thickness"] = 400. *mm;
  m_hGeometryParameters["RightWall_thickness"] = 500. *mm;
  m_hGeometryParameters["Floor_thickness"] = 420. *mm;
  m_hGeometryParameters["Ceiling_thickness"] = 200. *mm;

  //===============================Detectors====================================
  m_hGeometryParameters["Container_height"] = 76. *mm;//76 
  m_hGeometryParameters["Container_iD"] = 0. *mm;
  m_hGeometryParameters["Container_oD"] = 79. *mm; 

  m_hGeometryParameters["Seperation"] = pSeperation;
  m_hGeometryParameters["Angle"] = pAngle;

  m_hGeometryParameters["Det1_x"] = 0;
  m_hGeometryParameters["Det1_y"] = pFirstDetector;
  m_hGeometryParameters["Det1_z"] = -898. *mm;
 
  //===============================Generator====================================
  m_hGeometryParameters["GeneratorContainer_x"] = 0. *mm;
  m_hGeometryParameters["GeneratorContainer_y"] = 0. *mm;
  m_hGeometryParameters["GeneratorContainer_z"] = -950. *mm;

  //===============================Frame========================================
  m_hGeometryParameters["FrameLeg_height"] = 1250. *mm;
  m_hGeometryParameters["FrameLeg_width"] = 45. *mm;

  m_hGeometryParameters["FrameStrut_length"] = 300. *mm;
  m_hGeometryParameters["FrameStrut_width"] = 45. *mm;

  m_hGeometryParameters["FrameStrut_lower_z"] = 370 *mm;
  m_hGeometryParameters["FrameStrut_upper_z"] = 150 *mm;

  m_hGeometryParameters["FramePlate_upper_thickness"] = 6.25 *mm;
  m_hGeometryParameters["FramePlate_lower_thickness"] = 12.5 *mm;
  m_hGeometryParameters["UpperPlateHole_oD"] = 140. *mm;
  m_hGeometryParameters["LowerPlateHole_oD"] = 89. *mm;

   //===============================Sleeves=====================================
  m_hGeometryParameters["Sleeves_height"] = 600. *mm;
  m_hGeometryParameters["Sleeves_iD"] = 133. *mm;
  m_hGeometryParameters["Sleeves_oD"] = 155. *mm;

  m_hGeometryParameters["Sleeves_z"] = - GetGeometryParameter("Room_height")/2
    + GetGeometryParameter("FrameStrut_lower_z") 
    + GetGeometryParameter("FrameStrut_width")
    + GetGeometryParameter("Sleeves_height")/2;

  //===========================Lead Bricks=====================================
  m_hGeometryParameters["Brick_x"] = 200. *mm;
  m_hGeometryParameters["Brick_y"] = 50. *mm;
  m_hGeometryParameters["Brick_z"] = 100. *mm;
  
}

G4VPhysicalVolume* PurdueDetectorConstruction::Construct()
{
  DefineMaterials();
  DefineGeometryParameters();
  ConstructLab();
  ConstructFrame();

  if (pLeadSleeves == true)
    {
      ConstructSleeves();
    }
  ConstructNeutronGenerator();
  ConstructDetectorArray();
  //ConstructDetectors();
  //ConstructBrickShield();

  return m_pLabPhysicalVolume;
}

void PurdueDetectorConstruction::ConstructLab()
{
  G4double tolerance = GetGeometryParameter("tolerance");

  //Materials
  G4Material *Air = G4Material::GetMaterial("G4_AIR");
  G4Material *Concrete = G4Material::GetMaterial("G4_CONCRETE");
     
  //==============================Laboratory=================================== 
  //The lab is orientated such that the front wall of the lab would be facing 
  //room 398.

  //Dimensions
  G4double Lab_height = GetGeometryParameter("Lab_height");
  G4double Lab_width = GetGeometryParameter("Lab_width");
  G4double Lab_depth = GetGeometryParameter("Lab_depth");

  //Lab
  G4Box *Lab = new G4Box("Lab", Lab_width/2, Lab_depth/2, Lab_height/2);
	
  m_pLabLogicalVolume =	new G4LogicalVolume(Lab, Air, "Lab_log");
	
  m_pLabPhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(),
		      m_pLabLogicalVolume, "Lab_phys",
		      0, false, 0); 

   m_pLabLogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);

  //=================================Walls=====================================

  //--------------------------------Front Wall---------------------------------
  //Dimensions
  G4double FrontWall_height = 
    GetGeometryParameter("Room_height")
    + GetGeometryParameter("Floor_thickness")
    + GetGeometryParameter("Ceiling_thickness");
  G4double FrontWall_width = 
    GetGeometryParameter("Room_width")
    + GetGeometryParameter("LeftWall_thickness")
    + GetGeometryParameter("RightWall_thickness");
  G4double FrontWall_depth = GetGeometryParameter("FrontWall_thickness");

  //Position
  G4double FrontWall_x = 0;
  G4double FrontWall_y = 
    GetGeometryParameter("Room_depth")/2 + FrontWall_depth/2 + tolerance;
  G4double FrontWall_z = 0;
 
  G4Box *FrontWall = 
    new G4Box("FrontWall", 
	      FrontWall_width/2, FrontWall_depth/2, FrontWall_height/2);
	
  m_pFrontWallLogicalVolume = 
    new G4LogicalVolume(FrontWall, Concrete, "FrontWall_log");
	
  m_pFrontWallPhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(FrontWall_x, FrontWall_y, FrontWall_z),
		      m_pFrontWallLogicalVolume, "FrontWall_phys",
		      m_pLabLogicalVolume, false, 0); 

  G4Colour FrontWallColor(G4Colour::Red());
  G4VisAttributes *pFrontWallVisAtt = 
       new G4VisAttributes(FrontWallColor);
  pFrontWallVisAtt->SetForceAuxEdgeVisible(true);
  m_pFrontWallLogicalVolume->SetVisAttributes(pFrontWallVisAtt);

  // m_pFrontWallLogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);

  //--------------------------------Back Wall----------------------------------
  //Dimensions
  G4double BackWall_height = FrontWall_height;
  G4double BackWall_width = FrontWall_width;
  G4double BackWall_depth = GetGeometryParameter("BackWall_thickness");

  //Position
  G4double BackWall_x = 0;
  G4double BackWall_y = 
    - GetGeometryParameter("Room_depth")/2 - BackWall_depth/2 - tolerance;
  G4double BackWall_z = 0;
 
  G4Box *BackWall = 
    new G4Box("BackWall", 
	      BackWall_width/2, BackWall_depth/2, BackWall_height/2);
	
  m_pBackWallLogicalVolume = 
    new G4LogicalVolume(BackWall, Concrete, "BackWall_log");
	
  m_pBackWallPhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(BackWall_x, BackWall_y, BackWall_z),
		      m_pBackWallLogicalVolume, "BackWall_phys",
		      m_pLabLogicalVolume, false, 0); 

  G4Colour BackWallColor(G4Colour::Red());
  G4VisAttributes *pBackWallVisAtt = 
       new G4VisAttributes(BackWallColor);
  pBackWallVisAtt->SetForceAuxEdgeVisible(true);
  m_pBackWallLogicalVolume->SetVisAttributes(pBackWallVisAtt);

  //m_pBackWallLogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);

  //--------------------------------Left Wall---------------------------------
  //Dimensions
  G4double LeftWall_height = FrontWall_height;
  G4double LeftWall_width = GetGeometryParameter("LeftWall_thickness");;
  G4double LeftWall_depth = GetGeometryParameter("Room_depth");

  //Position
  G4double LeftWall_x = 
    GetGeometryParameter("Room_width")/2 + LeftWall_width/2 + tolerance;
  G4double LeftWall_y = 0;
  G4double LeftWall_z = 0;
 
  G4Box *LeftWall = 
    new G4Box("LeftWall", 
	      LeftWall_width/2, LeftWall_depth/2, LeftWall_height/2);
	
  m_pLeftWallLogicalVolume = 
    new G4LogicalVolume(LeftWall, Concrete, "LeftWall_log");
	
  m_pLeftWallPhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(LeftWall_x, LeftWall_y, LeftWall_z),
		      m_pLeftWallLogicalVolume, "LeftWall_phys",
		      m_pLabLogicalVolume, false, 0); 

  G4Colour LeftWallColor(G4Colour::Magenta());
  G4VisAttributes *pLeftWallVisAtt = 
       new G4VisAttributes(LeftWallColor);
  pLeftWallVisAtt->SetForceAuxEdgeVisible(true);
  m_pLeftWallLogicalVolume->SetVisAttributes(pLeftWallVisAtt);

  //m_pLeftWallLogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);

  //--------------------------------Right Wall---------------------------------
  //Dimensions
  G4double RightWall_height = FrontWall_height;
  G4double RightWall_width = GetGeometryParameter("RightWall_thickness");
  G4double RightWall_depth = GetGeometryParameter("Room_depth");

  //Position
  G4double RightWall_x = 
    - GetGeometryParameter("Room_width")/2 - RightWall_width/2 - tolerance;
  G4double RightWall_y = 0;
  G4double RightWall_z = 0;
 
  G4Box *RightWall = 
    new G4Box("RightWall", 
	      RightWall_width/2, RightWall_depth/2, RightWall_height/2);
	
  m_pRightWallLogicalVolume = 
    new G4LogicalVolume(RightWall, Concrete, "RightWall_log");
	
  m_pRightWallPhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(RightWall_x, RightWall_y, RightWall_z),
		      m_pRightWallLogicalVolume, "RightWall_phys",
		      m_pLabLogicalVolume, false, 0); 

  G4Colour RightWallColor(G4Colour::Green());
  G4VisAttributes *pRightWallVisAtt = 
       new G4VisAttributes(RightWallColor);
  pRightWallVisAtt->SetForceAuxEdgeVisible(true);
  m_pRightWallLogicalVolume->SetVisAttributes(pRightWallVisAtt);

  // m_pRightWallLogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);

  //------------------------------------Floor----------------------------------
  //Dimensions
  G4double Floor_height = GetGeometryParameter("Floor_thickness");
  G4double Floor_width = GetGeometryParameter("Room_width");
  G4double Floor_depth = GetGeometryParameter("Room_depth");

  //Position
  G4double Floor_x = 0;
  G4double Floor_y = 0;
  G4double Floor_z = 
    - GetGeometryParameter("Room_height")/2 - Floor_height/2;
 
  G4Box *Floor = 
    new G4Box("Floor", 
	      Floor_width/2, Floor_depth/2, Floor_height/2);
	
  m_pFloorLogicalVolume = 
    new G4LogicalVolume(Floor, Concrete, "Floor_log");
	
  m_pFloorPhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(Floor_x, Floor_y, Floor_z),
		      m_pFloorLogicalVolume, "Floor_phys",
		      m_pLabLogicalVolume, false, 0); 

  G4Colour FloorColor(G4Colour::Cyan());
  G4VisAttributes *pFloorVisAtt = 
       new G4VisAttributes(FloorColor);
  pFloorVisAtt->SetForceAuxEdgeVisible(true);
  m_pFloorLogicalVolume->SetVisAttributes(pFloorVisAtt);

  //m_pFloorLogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);

  //---------------------------------Ceiling-----------------------------------
  //Dimensions
  G4double Ceiling_height = GetGeometryParameter("Ceiling_thickness");
  G4double Ceiling_width = GetGeometryParameter("Room_width");
  G4double Ceiling_depth = GetGeometryParameter("Room_depth");

  //Position
  G4double Ceiling_z = 
    GetGeometryParameter("Room_height")/2 + Ceiling_height/2;
  G4double Ceiling_y = 0;
  G4double Ceiling_x = 0;
 
  G4Box *Ceiling = 
    new G4Box("Ceiling", 
	      Ceiling_width/2, Ceiling_depth/2, Ceiling_height/2);
	
  m_pCeilingLogicalVolume = 
    new G4LogicalVolume(Ceiling, Concrete, "Ceiling_log");
	
  m_pCeilingPhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(Ceiling_x, Ceiling_y, Ceiling_z),
		      m_pCeilingLogicalVolume, "Ceiling_phys",
		      m_pLabLogicalVolume, false, 0); 

  G4Colour CeilingColor(G4Colour::Blue());
  G4VisAttributes *pCeilingVisAtt = 
       new G4VisAttributes(CeilingColor);
  pCeilingVisAtt->SetForceAuxEdgeVisible(true);
  m_pCeilingLogicalVolume->SetVisAttributes(pCeilingVisAtt);

  //m_pCeilingLogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);
}

void PurdueDetectorConstruction::ConstructNeutronGenerator()
{
   //Positions
   G4double GeneratorContainer_x = 
     GetGeometryParameter("GeneratorContainer_x");
   G4double GeneratorContainer_y = 
     GetGeometryParameter("GeneratorContainer_y");
   G4double GeneratorContainer_z = 
     GetGeometryParameter("GeneratorContainer_z");
	
   m_pNeutronGenerator = new Xenon1tNeutronGenerator(m_pLabLogicalVolume, 
						     GeneratorContainer_x, 
						     GeneratorContainer_y, 
						     GeneratorContainer_z);
}

G4VPhysicalVolume* PurdueDetectorConstruction::LeadBrick(G4ThreeVector BrickPos, G4RotationMatrix* BrickRot)
{
  G4double tolerance = GetGeometryParameter("tolerance");

  //Materials
  G4Material *Lead = G4Material::GetMaterial("G4_Pb");
   
  //---------------------------Lead Brick------------------------------

  //Dimensions
  G4double Brick_x = GetGeometryParameter("Brick_x");
  G4double Brick_y = GetGeometryParameter("Brick_y");
  G4double Brick_z = GetGeometryParameter("Brick_z");

  //Container
  G4Box *Brick = 
        new G4Box("Container", Brick_x/2,
		   Brick_y/2, Brick_z/2);
	
  m_pBrickLogicalVolume =
	new G4LogicalVolume(Brick, Lead, "Brick_log");
	
  m_pBrickPhysicalVolume =
	new G4PVPlacement(BrickRot, BrickPos,
			  m_pBrickLogicalVolume, "Container_phys",
			  m_pLabLogicalVolume, false, 0);

  G4Colour BrickColor(G4Colour::Green());
  G4VisAttributes *pBrickVisAtt = new G4VisAttributes(BrickColor);
  pBrickVisAtt->SetForceAuxEdgeVisible(true);
  m_pBrickLogicalVolume->SetVisAttributes(pBrickVisAtt);

 return m_pBrickPhysicalVolume;
}

void PurdueDetectorConstruction::ConstructBrickShield()
{
	G4double detectorangle = 0.65; // in radians;
	G4RotationMatrix* Brick1_rot = new G4RotationMatrix;
	G4RotationMatrix* Brick2_rot = new G4RotationMatrix;
	G4RotationMatrix* Brick3_rot = new G4RotationMatrix;
	Brick1_rot->rotateZ(0);
	Brick2_rot->rotateZ(-pi+detectorangle);
	Brick3_rot->rotateZ(pi-detectorangle);
 	G4double ynear = 125*cos(detectorangle);
  	G4double yfar = 175*cos(detectorangle);
	G4double xnear = 125*sin(detectorangle);
  	G4double xfar = 175*sin(detectorangle);
        m_pLeadBrick1 = LeadBrick(G4ThreeVector(0, -125., 0.), Brick1_rot);
	m_pLeadBrick2 = LeadBrick(G4ThreeVector(0, -175., 0.), Brick1_rot);
	m_pLeadBrick3 = LeadBrick(G4ThreeVector(xnear, ynear, 0.), Brick2_rot);
	m_pLeadBrick4 = LeadBrick(G4ThreeVector(xfar, yfar, 0.), Brick2_rot);
	m_pLeadBrick5 = LeadBrick(G4ThreeVector(-xnear, ynear, 0.), Brick3_rot);
	m_pLeadBrick6 = LeadBrick(G4ThreeVector(-xfar, yfar, 0.), Brick3_rot);

}

void PurdueDetectorConstruction::ConstructDetectors()
{
  G4double opendeg = 0.0 *deg;
  G4double closedeg = 360.0 *deg;
  G4double seperation = GetGeometryParameter("Seperation");
  G4double angle = GetGeometryParameter("Angle");

  //Materials
  G4Material *Aluminium = G4Material::GetMaterial("G4_Al");
  G4Material *EJ301 = G4Material::GetMaterial("Scintillator");
     
  //==============================Detector 1===================================

  //------------------------------Container------------------------------------
 
  //Dimensions
  G4double Container_height = GetGeometryParameter("Container_height");
  G4double Container_iD = GetGeometryParameter("Container_iD");
  G4double Container_oD = GetGeometryParameter("Container_oD");

  //Container
  G4Tubs *Detector1 = new G4Tubs
    ("Detector1",Container_iD/2, Container_oD/2, Container_height/2, opendeg, closedeg);
	
  m_pDetectorContainer1LogicalVolume =	
    new G4LogicalVolume(Detector1, Aluminium, "Det1_log");
	
  m_pDetectorContainer1PhysicalVolume = 
    new G4PVPlacement(0, m_hFirstDetector,
		      m_pDetectorContainer1LogicalVolume, "Det1_phys",
		      m_pLabLogicalVolume, false, 0); 

   m_pDetectorContainer1LogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);

  //------------------------------Scintillator----------------------------------
  G4Tubs *Scintillator1 = new G4Tubs
    ("Scintillator1", 0, Container_oD/2 - 1.5, Container_height/2 - 1.5, opendeg, closedeg);
	
  m_pScintillator1LogicalVolume =	
    new G4LogicalVolume(Scintillator1, EJ301, "Scintillator1_log");

  G4SDManager *pSDManager = G4SDManager::GetSDMpointer();
  pEljenSD1 = new PurdueEljenSensitiveDetector("Eljen1_SD");
  pSDManager->AddNewDetector(pEljenSD1);
  m_pScintillator1LogicalVolume->SetSensitiveDetector(pEljenSD1);
	
  m_pScintillator1PhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(0,0,0),
		      m_pScintillator1LogicalVolume, "Scintillator1_phys",
		      m_pDetectorContainer1LogicalVolume, false, 0); 

  G4Colour Scintillator1Color(G4Colour::Green());
  G4VisAttributes *pScintillator1VisAtt = 
       new G4VisAttributes(Scintillator1Color);
  pScintillator1VisAtt->SetForceAuxEdgeVisible(true);
  m_pScintillator1LogicalVolume->SetVisAttributes(pScintillator1VisAtt);
  
  //==============================Detector 2===================================

  //------------------------------Container------------------------------------
  G4ThreeVector m_hSecondDetectorRel;
  G4cout<<"DIE GEVRAAGDE BEREKENING IS"<< pMeasurement<<endl;
  //Position
  if (pMeasurement == "Flux")
    {
      m_hSecondDetectorRel = m_hSecondDetector; 
    }
  else if (pMeasurement == "Energy")
    {
      G4double Det2_x = seperation*sin(angle*pi/180.);
      G4double Det2_y = seperation*cos(angle*pi/180.);
      G4double Det2_z = 0.;
      G4ThreeVector m_hSecondRelative(Det2_x,Det2_y,Det2_z);
      m_hSecondDetectorRel = m_hFirstDetector + m_hSecondRelative;
    }
 
 //Container
  G4Tubs *Detector2 = new G4Tubs
    ("Detector2",Container_iD/2, Container_oD/2, Container_height/2, opendeg, closedeg);
	
  m_pDetectorContainer2LogicalVolume =	
    new G4LogicalVolume(Detector2, Aluminium, "Det2_log");
	
  m_pDetectorContainer2PhysicalVolume = 
    new G4PVPlacement(0, m_hSecondDetectorRel,
		      m_pDetectorContainer2LogicalVolume, "Det2_phys",
		      m_pLabLogicalVolume, false, 0); 

  /*G4Colour Container2Color(G4Colour::Blue());
  G4VisAttributes *pContainer2VisAtt = new G4VisAttributes(Container2Color);
  pContainer2VisAtt->SetForceAuxEdgeVisible(true);
  m_pDetectorContainer2LogicalVolume->SetVisAttributes(pContainer2VisAtt);
  */
  
  m_pDetectorContainer2LogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);

  //------------------------------Scintillator----------------------------------
  G4Tubs *Scintillator2 = new G4Tubs
    ("Scintillator2", 0, Container_oD/2 - 1.5, Container_height/2 - 1.5, opendeg, closedeg);
	
  m_pScintillator2LogicalVolume =	
    new G4LogicalVolume(Scintillator2, EJ301, "Scintillator2_log");

  m_pScintillator2LogicalVolume->SetSensitiveDetector(pEljenSD1);
	
  m_pScintillator2PhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(0,0,0),
		      m_pScintillator2LogicalVolume, "Scintillator2_phys",
		      m_pDetectorContainer2LogicalVolume, false, 0); 

  G4Colour Scintillator2Color(G4Colour::Red());
  G4VisAttributes *pScintillator2VisAtt = new G4VisAttributes(Scintillator2Color);
  pScintillator2VisAtt->SetForceAuxEdgeVisible(true);
  m_pScintillator2LogicalVolume->SetVisAttributes(pScintillator2VisAtt);

   
  //==============================Detector 3===================================

  //------------------------------Container------------------------------------
  G4ThreeVector m_hThirdDetectorRel;

  //Position
  if (pMeasurement == "Flux")
    {
      m_hThirdDetectorRel = m_hThirdDetector; 
    }
  else if (pMeasurement == "Energy")
    {
      G4double Det3_x = -seperation*sin(angle*pi/180.);
      G4double Det3_y = seperation*cos(angle*pi/180.);
      G4double Det3_z = 0.;
      G4ThreeVector m_hThirdRelative(Det3_x,Det3_y,Det3_z);
      m_hThirdDetectorRel = m_hFirstDetector + m_hThirdRelative;
    }
  
  //Container
  G4Tubs *Detector3 = new G4Tubs
    ("Detector3",Container_iD/2, Container_oD/2, Container_height/2, opendeg, closedeg);
  
  m_pDetectorContainer3LogicalVolume =	
    new G4LogicalVolume(Detector3, Aluminium, "Det3_log");
  
  m_pDetectorContainer3PhysicalVolume = 
    new G4PVPlacement(0, m_hThirdDetectorRel,
		      m_pDetectorContainer3LogicalVolume, "Det3_phys",
		      m_pLabLogicalVolume, false, 0); 
  
  /*G4Colour Container2Color(G4Colour::Blue());
    G4VisAttributes *pContainer2VisAtt = new G4VisAttributes(Container2Color);
    pContainer2VisAtt->SetForceAuxEdgeVisible(true);
    m_pDetectorContainer2LogicalVolume->SetVisAttributes(pContainer2VisAtt);
  */
  
  m_pDetectorContainer3LogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);
  
  //------------------------------Scintillator----------------------------------
  G4Tubs *Scintillator3 = new G4Tubs
    ("Scintillator3", 0, Container_oD/2 - 1.5, Container_height/2 - 1.5, opendeg, closedeg);
  
  m_pScintillator3LogicalVolume =	
    new G4LogicalVolume(Scintillator3, EJ301, "Scintillator3_log");
  
  m_pScintillator3LogicalVolume->SetSensitiveDetector(pEljenSD1);
  
  m_pScintillator3PhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(0,0,0),
		      m_pScintillator3LogicalVolume, "Scintillator3_phys",
		      m_pDetectorContainer3LogicalVolume, false, 0); 
  
  G4Colour Scintillator3Color(G4Colour::Blue());
  G4VisAttributes *pScintillator3VisAtt = new G4VisAttributes(Scintillator3Color);
  pScintillator3VisAtt->SetForceAuxEdgeVisible(true);
  m_pScintillator3LogicalVolume->SetVisAttributes(pScintillator3VisAtt);
}

void PurdueDetectorConstruction::ConstructFrame()
{
  G4double opendeg = 0.0 *deg;
  G4double closedeg = 360.0 *deg;
 
  //Materials
  G4Material *Aluminium = G4Material::GetMaterial("G4_Al");
     
  //==================================Frame====================================
  
  //------------------------------Frame Legs-----------------------------------
  //Dimensions
  G4double FrameLeg_height = GetGeometryParameter("FrameLeg_height");
  G4double FrameLeg_width = GetGeometryParameter("FrameLeg_width");
  G4double FrameStrut_length = GetGeometryParameter("FrameStrut_length");
  G4double FrameStrut_width = GetGeometryParameter("FrameStrut_width");

  //Positions
  G4double FramePos_x = GetGeometryParameter("GeneratorContainer_x");
  G4double FramePos_y = GetGeometryParameter("GeneratorContainer_y");
  G4double FrameStrut_lower = GetGeometryParameter("FrameStrut_lower_z");
  G4double FrameStrut_upper = GetGeometryParameter("FrameStrut_upper_z");
  G4double Room_height = GetGeometryParameter("Room_height");
  G4double FramePos_z = -Room_height/2 + FrameLeg_height/2;
  G4double FrameStrut_lower_z = -Room_height/2 + FrameStrut_lower + FrameStrut_width/2;
  G4double FrameStrut_upper_z = -Room_height/2 + FrameLeg_height - FrameStrut_upper - FrameStrut_width/2;
  
  G4RotationMatrix* zRot = new G4RotationMatrix;
  zRot->rotateZ(pi/2);
 
  
  //FrameLeg
  G4Box *FrameLeg = new G4Box
    ("FrameLeg", FrameLeg_width/2, FrameLeg_width/2, FrameLeg_height/2);
	
  m_pFrameLegLogicalVolume =	
    new G4LogicalVolume(FrameLeg, Aluminium, "FrameLeg_log");
	
  
  m_pFrameLegPhysicalVolumes.push_back(new G4PVPlacement(0, 
							 G4ThreeVector(FramePos_x + FrameStrut_length/2 + FrameLeg_width/2,
								       FramePos_y + FrameStrut_length/2 + FrameLeg_width/2, 
								       FramePos_z),
							 m_pFrameLegLogicalVolume, "FrameLeg_phys",
							 m_pLabLogicalVolume, false, 0));

  m_pFrameLegPhysicalVolumes.push_back(new G4PVPlacement(0, 
							 G4ThreeVector(FramePos_x + FrameStrut_length/2 + FrameLeg_width/2,
								       FramePos_y - FrameStrut_length/2 - FrameLeg_width/2, 
								       FramePos_z),
							 m_pFrameLegLogicalVolume, "FrameLeg_phys",
							 m_pLabLogicalVolume, false, 1));
  
  m_pFrameLegPhysicalVolumes.push_back(new G4PVPlacement(0, 
							 G4ThreeVector(FramePos_x - FrameStrut_length/2 - FrameLeg_width/2,
								       FramePos_y + FrameStrut_length/2 + FrameLeg_width/2, 
								       FramePos_z),
							 m_pFrameLegLogicalVolume, "FrameLeg_phys",
							 m_pLabLogicalVolume, false, 2));

  m_pFrameLegPhysicalVolumes.push_back(new G4PVPlacement(0, 
							 G4ThreeVector(FramePos_x - FrameStrut_length/2 - FrameLeg_width/2,
								       FramePos_y - FrameStrut_length/2 - FrameLeg_width/2, 
								       FramePos_z),
							 m_pFrameLegLogicalVolume, "FrameLeg_phys",
							 m_pLabLogicalVolume, false, 3));

  G4Colour FrameLegColor(G4Colour::Red());
  G4VisAttributes *pFrameLegVisAtt = new G4VisAttributes(FrameLegColor);
  pFrameLegVisAtt->SetForceAuxEdgeVisible(true);
  m_pFrameLegLogicalVolume->SetVisAttributes(pFrameLegVisAtt);


  //m_pFrameLegLogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);
  
  //------------------------------Frame Struts-----------------------------------
  G4Box *FrameStrut = new G4Box
    ("FrameStrut", FrameStrut_length/2, FrameStrut_width/2, FrameStrut_width/2);
	
  m_pFrameStrutLogicalVolume =	
    new G4LogicalVolume(FrameStrut, Aluminium, "FrameStrut_log");
	
  
  m_pFrameStrutPhysicalVolumes.push_back(new G4PVPlacement(zRot, 
							 G4ThreeVector(FramePos_x + FrameStrut_length/2 + FrameStrut_width/2,
								       FramePos_y, FrameStrut_lower_z),
							 m_pFrameStrutLogicalVolume, "FrameStrut_phys",
							 m_pLabLogicalVolume, false, 0));

  m_pFrameStrutPhysicalVolumes.push_back(new G4PVPlacement(0, 
							 G4ThreeVector(FramePos_x,
								       FramePos_y + FrameStrut_length/2 + FrameStrut_width/2, 
								       FrameStrut_lower_z),
							 m_pFrameStrutLogicalVolume, "FrameStrut_phys",
							 m_pLabLogicalVolume, false, 1));
  
  m_pFrameStrutPhysicalVolumes.push_back(new G4PVPlacement(zRot, 
							 G4ThreeVector(FramePos_x - FrameStrut_length/2 - FrameStrut_width/2,
								       FramePos_y, FrameStrut_lower_z),
							 m_pFrameStrutLogicalVolume, "FrameStrut_phys",
							 m_pLabLogicalVolume, false, 2));

  m_pFrameStrutPhysicalVolumes.push_back(new G4PVPlacement(0, 
							 G4ThreeVector(FramePos_x,
								       FramePos_y - FrameStrut_length/2 - FrameStrut_width/2, 
								       FrameStrut_lower_z),
							 m_pFrameStrutLogicalVolume, "FrameStrut_phys",
							 m_pLabLogicalVolume, false, 3));
  
   m_pFrameStrutPhysicalVolumes.push_back(new G4PVPlacement(zRot, 
							 G4ThreeVector(FramePos_x + FrameStrut_length/2 + FrameStrut_width/2,
								       FramePos_y, FrameStrut_upper_z),
							 m_pFrameStrutLogicalVolume, "FrameStrut_phys",
							 m_pLabLogicalVolume, false, 4));

  m_pFrameStrutPhysicalVolumes.push_back(new G4PVPlacement(0, 
							 G4ThreeVector(FramePos_x,
								       FramePos_y + FrameStrut_length/2 + FrameStrut_width/2, 
								       FrameStrut_upper_z),
							 m_pFrameStrutLogicalVolume, "FrameStrut_phys",
							 m_pLabLogicalVolume, false, 5));
  
  m_pFrameStrutPhysicalVolumes.push_back(new G4PVPlacement(zRot, 
							 G4ThreeVector(FramePos_x - FrameStrut_length/2 - FrameStrut_width/2,
								       FramePos_y, FrameStrut_upper_z),
							 m_pFrameStrutLogicalVolume, "FrameStrut_phys",
							 m_pLabLogicalVolume, false, 6));

  m_pFrameStrutPhysicalVolumes.push_back(new G4PVPlacement(0, 
							 G4ThreeVector(FramePos_x,
								       FramePos_y - FrameStrut_length/2 - FrameStrut_width/2, 
								       FrameStrut_upper_z),
							 m_pFrameStrutLogicalVolume, "FrameStrut_phys",
							 m_pLabLogicalVolume, false, 7));

  G4Colour FrameStrutColor(G4Colour::Red());
  G4VisAttributes *pFrameStrutVisAtt = new G4VisAttributes(FrameStrutColor);
  pFrameStrutVisAtt->SetForceAuxEdgeVisible(true);
  m_pFrameStrutLogicalVolume->SetVisAttributes(pFrameStrutVisAtt);

  //m_pFrameStrutLogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);
  
  //--------------------------------------Plates------------------------------------
  //Dimensions
  G4double FramePlate_upper_thickness = GetGeometryParameter("FramePlate_upper_thickness");
  G4double UpperPlateHole_oD = GetGeometryParameter("UpperPlateHole_oD");
  G4double FramePlate_lower_thickness = GetGeometryParameter("FramePlate_lower_thickness");
  G4double LowerPlateHole_oD = GetGeometryParameter("LowerPlateHole_oD");
  
  //-----------------------------------Upper Plate----------------------------------
  G4Box *FramePlateUpper = new G4Box
    ("FramePlateUpper", FrameStrut_length/2, FrameStrut_length/2, FramePlate_upper_thickness/2);

  G4Tubs *FramePlateUpperHole = new G4Tubs
    ("FramePlateUpperHole", 0, UpperPlateHole_oD/2, FramePlate_upper_thickness , opendeg, closedeg);

  G4SubtractionSolid* UpperPlate = new G4SubtractionSolid("UpperPlate", FramePlateUpper, FramePlateUpperHole);

  m_pUpperPlateLogicalVolume =	
    new G4LogicalVolume(UpperPlate, Aluminium, "UpperPlate_log");

  m_pUpperPlatePhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(FramePos_x,FramePos_y, 
				       FrameStrut_upper_z + FrameStrut_width/2),
		      m_pUpperPlateLogicalVolume, "UpperPlate_phys",
		      m_pLabLogicalVolume, false, 0); 

  G4Colour UpperPlateColor(G4Colour::Blue());
  G4VisAttributes *pUpperPlateVisAtt = new G4VisAttributes(UpperPlateColor);
  pUpperPlateVisAtt->SetForceAuxEdgeVisible(true);
  m_pUpperPlateLogicalVolume->SetVisAttributes(pUpperPlateVisAtt);
  
  //----------------------------------Lower Plate---------------------------------------

  G4Box *FramePlateLower = new G4Box
    ("FramePlateLower", FrameStrut_length/2, FrameStrut_length/2, FramePlate_lower_thickness/2);
  
  G4Tubs *FramePlateLowerHole = new G4Tubs
    ("FramePlateLowerHole", 0, LowerPlateHole_oD/2, FramePlate_lower_thickness , opendeg, closedeg);
  
  G4SubtractionSolid* LowerPlate = new G4SubtractionSolid("LowerPlate", FramePlateLower, FramePlateLowerHole);
  
  m_pLowerPlateLogicalVolume =	
    new G4LogicalVolume(LowerPlate, Aluminium, "LowerPlate_log");

  m_pLowerPlatePhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(FramePos_x,FramePos_y, 
				       FrameStrut_lower_z + FrameStrut_width/2),
		      m_pLowerPlateLogicalVolume, "LowerPlate_phys",
		      m_pLabLogicalVolume, false, 0); 

  G4Colour LowerPlateColor(G4Colour::Blue());
  G4VisAttributes *pLowerPlateVisAtt = new G4VisAttributes(LowerPlateColor);
  pLowerPlateVisAtt->SetForceAuxEdgeVisible(true);
  m_pLowerPlateLogicalVolume->SetVisAttributes(pLowerPlateVisAtt);

}

void PurdueDetectorConstruction::ConstructSleeves()
{
  G4double opendeg = 0.0 *deg;
  G4double closedeg = 360.0 *deg;
  
  //Materials
  G4Material *Lead = G4Material::GetMaterial("G4_Pb");
       
  //==============================Sleeves======================================
   
  //Position
  G4double Sleeves_x = GetGeometryParameter("GeneratorContainer_x");
  G4double Sleeves_y = GetGeometryParameter("GeneratorContainer_y");
  G4double Sleeves_z = GetGeometryParameter("Sleeves_z"); 

  //Dimensions
  G4double Sleeves_height = GetGeometryParameter("Sleeves_height");
  G4double Sleeves_iD = GetGeometryParameter("Sleeves_iD");
  G4double Sleeves_oD = GetGeometryParameter("Sleeves_oD");

  //Container
  G4Tubs *Sleeves = new G4Tubs
    ("Sleeves",Sleeves_iD/2, Sleeves_oD/2, Sleeves_height/2, opendeg, closedeg);
	
  m_pSleevesLogicalVolume =	
    new G4LogicalVolume(Sleeves, Lead, "Det1_log");
	
  m_pSleevesPhysicalVolume = 
    new G4PVPlacement(0, G4ThreeVector(Sleeves_x,Sleeves_y,Sleeves_z),
		      m_pSleevesLogicalVolume, "Sleeves_phys",
		      m_pLabLogicalVolume, false, 0); 

  G4Colour SleevesColor(G4Colour::Magenta());
  G4VisAttributes *pSleevesVisAtt = new G4VisAttributes(SleevesColor);
  pSleevesVisAtt->SetForceAuxEdgeVisible(true);
  m_pSleevesLogicalVolume->SetVisAttributes(pSleevesVisAtt);

}


void PurdueDetectorConstruction::ConstructDetectorArray(){

	G4double opendeg = 0.0 *deg;	
	G4double closedeg = 360.0 *deg;
	G4double seperation = GetGeometryParameter("Seperation");
	G4double angle = GetGeometryParameter("Angle");

  	//Materials
	G4Material *Aluminium = G4Material::GetMaterial("G4_Al");
	G4Material *EJ301 = G4Material::GetMaterial("Scintillator");
     
 	//==============================Detector 1===================================
	//------------------------------Container------------------------------------
 
	//Dimensions
  	G4double Container_height = GetGeometryParameter("Container_height");
	G4double Container_iD = GetGeometryParameter("Container_iD");
	G4double Container_oD = GetGeometryParameter("Container_oD");

	//Container
	G4Tubs *Detector1 = new G4Tubs("Detector1",Container_iD/2, Container_oD/2, Container_height/2, opendeg, closedeg);
	
 	m_pDetectorContainer1LogicalVolume = new G4LogicalVolume(Detector1, Aluminium, "Det1_log");
	
	m_pDetectorContainer1PhysicalVolume = new G4PVPlacement(0, m_hFirstDetector, m_pDetectorContainer1LogicalVolume, "Det1_phys", m_pLabLogicalVolume, false, 0); 

 	m_pDetectorContainer1LogicalVolume->SetVisAttributes(G4VisAttributes::Invisible);

  	//------------------------------Scintillator----------------------------------
  	G4Tubs *Scintillator1 = new G4Tubs
   	("Scintillator1", 0, Container_oD/2 - 1.5, Container_height/2 - 1.5, opendeg, closedeg);
	
 	m_pScintillator1LogicalVolume =	new G4LogicalVolume(Scintillator1, EJ301, "Scintillator1_log");

	G4SDManager *pSDManager = G4SDManager::GetSDMpointer();
	pEljenSD1 = new PurdueEljenSensitiveDetector("Eljen1_SD");
	pSDManager->AddNewDetector(pEljenSD1);
	m_pScintillator1LogicalVolume->SetSensitiveDetector(pEljenSD1);
	
	m_pScintillator1PhysicalVolume = new G4PVPlacement(0, G4ThreeVector(0,0,0), m_pScintillator1LogicalVolume, "Scintillator1_phys",m_pDetectorContainer1LogicalVolume, false, 0); 

	G4Colour Scintillator1Color(G4Colour::Green());
	G4VisAttributes *pScintillator1VisAtt = new G4VisAttributes(Scintillator1Color);
	pScintillator1VisAtt->SetForceAuxEdgeVisible(true);
	m_pScintillator1LogicalVolume->SetVisAttributes(pScintillator1VisAtt);

	//==============================Detector Array===================================

	//Dimensions
	G4double DetectorsArray_Rad = 2.0 *m; //GetGeometryParameter("Fins_rad_from_axis");
  	G4int Detector_number = 16 ; //G4int(GetGeometryParameter("Fins_number"));
  
 	//Position
 	G4double DetectorsAxis_x = 0; //GetGeometryParameter("FinsAxis_x");
	G4double DetectorsAxis_y = 0; //GetGeometryParameter("FinsAxis_y");
	G4double DetectorsAxis_z = 0; //GetGeometryParameter("FinsAxis_z");

	for (int i=0; i<Detector_number; ++i) {
  		G4RotationMatrix* zRot = new G4RotationMatrix;
	  	zRot->rotateY(pi/2);
	  	zRot->rotateZ(-i*10.*deg);
  		G4double Det_x = DetectorsAxis_x + DetectorsArray_Rad*cos(i*10.*deg);
  		G4double Det_y = DetectorsAxis_y + DetectorsArray_Rad*sin(i*10.*deg);
  		G4double Det_z = DetectorsAxis_z; 
  		m_pDetectorArrayPhysicalVolumes.push_back(new G4PVPlacement(zRot, G4ThreeVector(Det_x, Det_y, Det_z), m_pDetectorContainer1LogicalVolume, "DetectorArray_phys", m_pLabLogicalVolume, false, i));
  	}	
  
}

G4double PurdueDetectorConstruction::GetGeometryParameter(const char *szParameter)
{
  if (m_hGeometryParameters.find(szParameter) != m_hGeometryParameters.end()){
    return m_hGeometryParameters[szParameter];
  }
  else {
    G4cout<< "Parameter: " << szParameter << " is not defined!!!!!" << G4endl;
    return 0;
  }
}
