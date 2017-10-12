//Main header
#include <Xenon1tNeutronGenerator.hh>
//Shapes
#include <G4Tubs.hh>
#include <G4Cons.hh>
#include <G4Box.hh>
#include <G4Torus.hh>
//Visualisation
#include <G4Color.hh>
#include <G4VisAttributes.hh>
//Materials
#include <G4Material.hh>
//Other
#include <G4NistManager.hh>
#include <G4PVPlacement.hh>

#include <math.h>
#define pi 3.14159265359

//******************************************************************************
//*                                 Disclaimer                                 *
//*                                                                            *
//* This  simulation  is  produced  from  information provided  by NSD Fusion  *
//* pertaining to the interior geometry and construction of a NSD-35-DD-C-W-S  *
//* Neutron Generator. It is not intended for publication.                     *
//*                                                                            *
//* The  information  contained  within  is  provided  in order to aid in the  *
//* writing of simulation code for the Xenon1T collaboration. This information *
//* is not to be used to infringe upon the copyrights or intellectual property *
//* rights of NSD Fusion.                                                      *
//* http://www.nsd-fusion.com                                                  *
//******************************************************************************

//Andrew, Jacques
 
map<G4String, G4double> Xenon1tNeutronGenerator::m_hGeometryParameters;

Xenon1tNeutronGenerator::Xenon1tNeutronGenerator
(G4LogicalVolume *MotherLogicalVolume, double x, double y, double z) : 
  m_pMotherLogicalVolume(MotherLogicalVolume), xPos(x), yPos(y), zPos(z)
{
  G4cout << "Beginning Neutron Generator construction" << G4endl;
  DefineMaterials();
  DefineGeometryParameters();
  Construct();
  G4cout << "Neutron Generator construction complete" << G4endl;
}

Xenon1tNeutronGenerator::~Xenon1tNeutronGenerator()
{
  delete m_pCathodeLogicalVolume;
  delete m_pCathodePhysicalVolume;

  delete m_pTopBulkheadLogicalVolume;
  delete m_pTopBulkheadPhysicalVolume;

  delete m_pMiddleBulkheadLogicalVolume;
  delete m_pMiddleBulkheadPhysicalVolume;

  delete m_pBottomBulkheadLogicalVolume;
  delete m_pBottomBulkheadPhysicalVolume;
  
  delete m_pGetterMainCylinderLogicalVolume;
  delete m_pGetterMainCylinderPhysicalVolume;

  delete m_pGetterMainConeLogicalVolume;
  delete m_pGetterMainConePhysicalVolume;

  delete m_pGetterMediumPipeLogicalVolume;
  delete m_pGetterMediumPipePhysicalVolume;

  delete m_pGetterSmallPipeLogicalVolume;
  delete m_pGetterSmallPipePhysicalVolume;

  delete m_pGetterTopPortLogicalVolume;
  delete m_pGetterTopPortPhysicalVolume;
  
  delete m_pContainerLogicalVolume;
  delete m_pContainerPhysicalVolume;

  delete m_pCoaxialInnerConductorLogicalVolume;
  delete m_pCoaxialInnerConductorPhysicalVolume;

  delete m_pCoaxialDielectricLogicalVolume;
  delete m_pCoaxialDielectricPhysicalVolume;

  delete m_pCoaxialOuterConductorLogicalVolume;
  delete m_pCoaxialOuterConductorPhysicalVolume;

  delete m_pCoaxialSheathLogicalVolume;
  delete m_pCoaxialSheathPhysicalVolume;
 
  delete m_pPlexiglassTubeLogicalVolume;
  delete m_pPlexiglassTubePhysicalVolume;

  delete m_pCeramicPortLogicalVolume;
  delete m_pCeramicPortPhysicalVolume;

  delete m_pCeramicNeckLogicalVolume;
  delete m_pCeramicNeckPhysicalVolume;

  delete m_pCeramicBodyLogicalVolume;
  delete m_pCeramicBodyPhysicalVolume;

  delete m_pCeramicRimLogicalVolume;
  delete m_pCeramicRimPhysicalVolume;

  delete m_pCeramicBigRingLogicalVolume;
  delete m_pCeramicBigRingPhysicalVolume;

  delete m_pCeramicSmallRingLogicalVolume;
  delete m_pCeramicSmallRingPhysicalVolume;

  delete m_pCeramicRingNeckLogicalVolume;
  delete m_pCeramicRingNeckPhysicalVolume;
 
  delete m_pSteelPortLogicalVolume;
  delete m_pSteelPortPhysicalVolume;

  delete m_pSteelNeckLogicalVolume;
  delete m_pSteelNeckPhysicalVolume;

  delete m_pSteelBodyLogicalVolume;
  delete m_pSteelBodyPhysicalVolume;

  delete m_pTubeLogicalVolume;
  for (unsigned int i=0; i<m_pTubePhysicalVolumes.size(); ++i)
    delete m_pTubePhysicalVolumes[i];

  delete m_pChamberBodyLogicalVolume;
  delete m_pChamberBodyPhysicalVolume;

  delete m_pFinLogicalVolume;
  for (unsigned int i=0; i<m_pFinPhysicalVolumes.size(); ++i)
    delete m_pFinPhysicalVolumes[i];

  delete m_pWaterGlycolLogicalVolume;
  delete m_pWaterGlycolPhysicalVolume;

  delete m_pTransformerOilLogicalVolume;
  delete m_pTransformerOilPhysicalVolume;

  delete m_pDeuteriumLogicalVolume;
  delete m_pDeuteriumPhysicalVolume;

  delete m_pGetterMainCylinderGasLogicalVolume;
  delete m_pGetterMainCylinderGasPhysicalVolume;

  delete m_pGetterMainConeGasLogicalVolume;
  delete m_pGetterMainConeGasPhysicalVolume;

  delete m_pGetterMediumPipeGasLogicalVolume;
  delete m_pGetterMediumPipeGasPhysicalVolume;

  delete m_pGetterSmallPipeGasLogicalVolume;
  delete m_pGetterSmallPipeGasPhysicalVolume;

  delete m_pDelrinPortLogicalVolume;
  delete m_pDelrinPortPhysicalVolume;
 
  delete m_pDelrinBodyLogicalVolume;
  delete m_pDelrinBodyPhysicalVolume;

  delete m_pGetterTopPortGasLogicalVolume;
  delete m_pGetterTopPortGasPhysicalVolume;

  delete m_pCeramicNeckOilLogicalVolume;
  delete m_pCeramicNeckOilPhysicalVolume;

  delete m_pTempInnerRingLogicalVolume;
  delete m_pTempInnerRingPhysicalVolume;
 
}  
 
void Xenon1tNeutronGenerator::DefineMaterials() 
{
  G4NistManager* pNistManager = G4NistManager::Instance();
  
  //===============================Elements====================================
  
  G4Element *Fe = pNistManager->FindOrBuildElement("Fe");
  G4Element *C  = pNistManager->FindOrBuildElement("C");
  G4Element *Ni = pNistManager->FindOrBuildElement("Ni");
  G4Element *Cr = pNistManager->FindOrBuildElement("Cr");
  G4Element *Mo = pNistManager->FindOrBuildElement("Mo");
  G4Element *Mn = pNistManager->FindOrBuildElement("Mn");
  G4Element *Si = pNistManager->FindOrBuildElement("Si");
  G4Element *S  = pNistManager->FindOrBuildElement("S");
  G4Element *P  = pNistManager->FindOrBuildElement("P");
  G4Element *Ti = pNistManager->FindOrBuildElement("Ti");
  G4Element *H  = pNistManager->FindOrBuildElement("H");
  G4Element *O  = pNistManager->FindOrBuildElement("O");
  G4Element *Al = pNistManager->FindOrBuildElement("Al");
  G4Isotope *D_Iso = new G4Isotope("D_Iso",1,2,2.014102*g/mole);
  G4Element *D  = new G4Element("Deuterium", "D", 1);
  D->AddIsotope(D_Iso, 1);
         
  //===============================Materials===================================

  double fractionmass;
  int atomnumber;

  //-------------------------------Aluminium-----------------------------------
  pNistManager->FindOrBuildMaterial("G4_Al");

  //--------------------------------Copper-------------------------------------
  pNistManager->FindOrBuildMaterial("G4_Cu");

  //-------------------------Temp inner material-------------------------------
  pNistManager->FindOrBuildMaterial("G4_AIR");
  
  //----------------------------1.4571 NiCrSteel-------------------------------
  //List of fractions by mass obtained from datasheets
  G4Material *NiCrSteel = 
    new G4Material("NiCrSteel", 8.*g/cm3, 10, kStateSolid);
  NiCrSteel->AddElement(Fe, fractionmass=0.5811);
  NiCrSteel->AddElement(C,  fractionmass=0.0008);
  NiCrSteel->AddElement(Si, fractionmass=0.01);
  NiCrSteel->AddElement(Mn, fractionmass=0.02);
  NiCrSteel->AddElement(P,  fractionmass=0.00045);
  NiCrSteel->AddElement(S,  fractionmass=0.00015);
  NiCrSteel->AddElement(Cr, fractionmass=0.175);
  NiCrSteel->AddElement(Mo, fractionmass=0.0225);
  NiCrSteel->AddElement(Ni, fractionmass=0.12);
  NiCrSteel->AddElement(Ti, fractionmass=0.070);

  //------------------------------Polyethylene---------------------------------
  G4Material *Polyethylene = 
    new G4Material("Polyethylene", .925*g/cm3, 2, kStateSolid);
  Polyethylene->AddElement(H, atomnumber=4);
  Polyethylene->AddElement(C,  atomnumber=2);

  //---------------------------------Delrin------------------------------------
  G4Material *Delrin = 
    new G4Material("Delrin", 1.415*g/cm3, 3, kStateSolid);
  Delrin->AddElement(C, atomnumber=1);
  Delrin->AddElement(H, atomnumber=2);
  Delrin->AddElement(O, atomnumber=1);

  //-------------------------------Plexiglass----------------------------------
  pNistManager->FindOrBuildMaterial("G4_PLEXIGLASS");

  //---------------------------------Air---------------------------------------
  pNistManager->FindOrBuildMaterial("G4_AIR");
  
  //---------------------------------Ceramic-----------------------------------
  G4Material *Al2O3 = new G4Material("Al2O3", 3.97*g/cm3, 2, kStateSolid);
  Al2O3->AddElement(Al, atomnumber=2);
  Al2O3->AddElement(O, atomnumber=3);
  
  //------------------------------Ethylene Glycol------------------------------
  G4Material *Glycol = new G4Material("Glycol", 1.11*g/cm3, 3, kStateLiquid);
  Glycol->AddElement(C, atomnumber=2);
  Glycol->AddElement(O,  atomnumber=2);
  Glycol->AddElement(H, atomnumber=6);
  
  //-----------------------------------Water-----------------------------------
  G4Material *H2O = new G4Material("H2O", 1.*g/cm3, 2, kStateLiquid);
  H2O->AddElement(H, atomnumber=2);
  H2O->AddElement(O, atomnumber=1);

  //----------------------------Water Glycol Mixture---------------------------
  G4Material *WaterGlycol = 
    new G4Material("WaterGlycol", 1.04*g/cm3, 2, kStateLiquid);
  WaterGlycol->AddMaterial(H2O, fractionmass = 0.61855);
  WaterGlycol->AddMaterial(Glycol, fractionmass = 0.38145);

  //--------------------------------Deuterium Gas------------------------------
  G4Material *DeuteriumGas = 
    new G4Material("DeuteriumGas", 0.08*g/m3, 2, kStateGas, 308.15*kelvin,
		   0.0297*bar);
  DeuteriumGas->AddElement(D, atomnumber=1);
  DeuteriumGas->AddElement(D, atomnumber=1);

  //------------------------------Transformer Oil------------------------------
  G4Material *TransformerOil = 
    new G4Material("TransformerOil", 0.89*g/cm3, 2, kStateLiquid);
  TransformerOil->AddElement(H, atomnumber=2);
  TransformerOil->AddElement(C, atomnumber=1); 
}

void Xenon1tNeutronGenerator::DefineGeometryParameters() 
{
  m_hGeometryParameters["tolerance"] = 0.01 *mm;
 
  //=================================Container=================================
  //Positions are taken from xPos, yPos, zPos
  m_hGeometryParameters["Container_height"] = 815. *mm;
  m_hGeometryParameters["Container_iD"] = 128. *mm;
  m_hGeometryParameters["Container_oD"] = 138. *mm;

  //==================================Getter===================================
  //Getter positioned at low-voltage end of main cylinder. 
  
  //--------------------------------Main cylinder------------------------------
  m_hGeometryParameters["GetterMainCylinder_height"] = 85*mm;
  m_hGeometryParameters["GetterMainCylinder_iD"] =  88*mm;
  m_hGeometryParameters["GetterMainCylinder_oD"] =  98*mm;

  m_hGeometryParameters["GetterMainCylinder_x"] =  0*mm;
  m_hGeometryParameters["GetterMainCylinder_y"] =  0*mm;
  m_hGeometryParameters["GetterMainCylinder_z"] =  
	GetGeometryParameter("Container_height")/2. - (128+85)*mm 
	+ GetGeometryParameter("GetterMainCylinder_height")/2.;
    
  //==================================Bulkheads================================
  //Tree aluminium bulkheads, at either end of the main container, 
  //and seperating the  air and coolant filled volumes.

  //------------------------------------Top------------------------------------
  m_hGeometryParameters["TopBulkhead_height"] = 19. *mm;
  m_hGeometryParameters["TopBulkhead_iD"] = 0 *mm;
  m_hGeometryParameters["TopBulkhead_oD"] = 
	GetGeometryParameter("Container_iD");

  m_hGeometryParameters["TopBulkhead_x"] = 0. *mm;
  m_hGeometryParameters["TopBulkhead_y"] = 0. *mm;
  m_hGeometryParameters["TopBulkhead_z"] = 
	GetGeometryParameter("Container_height")/2. 
	- GetGeometryParameter("TopBulkhead_height")/2.;

  //---------------------------------Middle------------------------------------
  m_hGeometryParameters["MiddleBulkhead_height"] = 19. *mm;
  m_hGeometryParameters["MiddleBulkhead_iD"] = 98. *mm;
  m_hGeometryParameters["MiddleBulkhead_oD"] = 
	GetGeometryParameter("Container_iD");
  m_hGeometryParameters["MiddleBulkhead_x"] = 0. *mm;
  m_hGeometryParameters["MiddleBulkhead_y"] = 0. *mm;
  m_hGeometryParameters["MiddleBulkhead_z"] = 
	GetGeometryParameter("Container_height")/2. - 167. * mm 
	- GetGeometryParameter("MiddleBulkhead_height")/2.;

  //----------------------------------Bottom-----------------------------------
  m_hGeometryParameters["BottomBulkhead_height"] = 93. *mm;
  m_hGeometryParameters["BottomBulkhead_iD"] = 69 *mm;
  m_hGeometryParameters["BottomBulkhead_oD"] = 
	GetGeometryParameter("Container_iD");

  m_hGeometryParameters["BottomBulkhead_x"] = 0. *mm;
  m_hGeometryParameters["BottomBulkhead_y"] = 0 *mm;
  m_hGeometryParameters["BottomBulkhead_z"] = 
	- GetGeometryParameter("Container_height")/2. 
        + GetGeometryParameter("BottomBulkhead_height")/2.;

  //-------------------------------Air Cavity----------------------------------
  m_hGeometryParameters["TempInner_height"] = 
    GetGeometryParameter("TopBulkhead_z") 
    - GetGeometryParameter("TopBulkhead_height")/2. 
    - GetGeometryParameter("GetterMainCylinder_z")
    - GetGeometryParameter("GetterMainCylinder_height")/2.;
  m_hGeometryParameters["TempInner_iD"] = 0 *mm;
  m_hGeometryParameters["TempInner_oD"] = 
	GetGeometryParameter("Container_iD");

  m_hGeometryParameters["TempInner_x"] = 0 *mm;
  m_hGeometryParameters["TempInner_y"] = 0 *mm;
  m_hGeometryParameters["TempInner_z"] = 
	GetGeometryParameter("Container_height")/2. 
        - GetGeometryParameter("TopBulkhead_height")
        - GetGeometryParameter("TempInner_height")/2.;

  //--------------------------------Air Ring-----------------------------------
  m_hGeometryParameters["TempInnerRing_height"] = 
        GetGeometryParameter("TempInner_z") 
        - GetGeometryParameter("TempInner_height")/2. 
        - GetGeometryParameter("MiddleBulkhead_z")
        - GetGeometryParameter("MiddleBulkhead_height")/2.;
  m_hGeometryParameters["TempInnerRing_iD"] = 
        GetGeometryParameter("GetterMainCylinder_oD");
  m_hGeometryParameters["TempInnerRing_oD"] = 
	GetGeometryParameter("Container_iD");

  m_hGeometryParameters["TempInnerRing_x"] = 0 *mm;
  m_hGeometryParameters["TempInnerRing_y"] = 0 *mm;
  m_hGeometryParameters["TempInnerRing_z"] = 
	GetGeometryParameter("Container_height")/2. 
        - GetGeometryParameter("TopBulkhead_height")
        - GetGeometryParameter("TempInner_height")
        - GetGeometryParameter("TempInnerRing_height")/2.;

  //===================================Tubes===================================
  // 16 Aluminium tubes in lower bulkhead/water manifold, 10mm OD.

  m_hGeometryParameters["Tubes_height"] = 
        GetGeometryParameter("BottomBulkhead_height");
  m_hGeometryParameters["Tubes_iD"] =  0*mm; 
  m_hGeometryParameters["Tubes_oD"] =  10*mm;
  m_hGeometryParameters["Tubes_rad_from_axis"] = 55*mm;
  m_hGeometryParameters["Tubes_number"] =  16;
  
  m_hGeometryParameters["TubesAxis_x"] = 0 *mm;
  m_hGeometryParameters["TubesAxis_y"] = 0 *mm;
  m_hGeometryParameters["TubesAxis_z"] = 0 *mm;

  //===============================Reaction Chamber============================
  //Approximately 60 

  //--------------------------------Chamber Body-------------------------------
  m_hGeometryParameters["ChamberBody_height"] = 223*mm;
  m_hGeometryParameters["ChamberBody_iD"] =  80*mm; 
  m_hGeometryParameters["ChamberBody_oD"] =  100*mm;

  m_hGeometryParameters["ChamberBody_x"] = 0 *mm;
  m_hGeometryParameters["ChamberBody_y"] = 0 *mm;
  m_hGeometryParameters["ChamberBody_z"] =  
        - GetGeometryParameter("Container_height")/2. 
        + (133+13+173+13)*mm + GetGeometryParameter("ChamberBody_height")/2.;

  //-----------------------------------Fins------------------------------------
  m_hGeometryParameters["Fins_height"] = 223*mm;
  m_hGeometryParameters["Fins_depth"] =  14*mm; 
  m_hGeometryParameters["Fins_width"] =  2.5*mm;
  m_hGeometryParameters["Fins_rad_from_axis"] = 57*mm;
  m_hGeometryParameters["Fins_number"] =  50;
  
  m_hGeometryParameters["FinsAxis_x"] = 0 *mm;
  m_hGeometryParameters["FinsAxis_y"] = 0 *mm;
  m_hGeometryParameters["FinsAxis_z"] =
        - GetGeometryParameter("Container_height")/2. 
        + (133+13+173+13)*mm + GetGeometryParameter("ChamberBody_height")/2.;

  //==================================Getter===================================
  //Getter positioned at low-voltage end of main cylinder. 
  
  //----------------------------------Main cone--------------------------------
  m_hGeometryParameters["GetterMainCone_height"] = 10*mm;
  m_hGeometryParameters["GetterMainCone_iD"] =  88*mm;
  m_hGeometryParameters["GetterMainCone_oD"] =  98*mm; 

  m_hGeometryParameters["GetterMainCone_x"] = 0*mm;
  m_hGeometryParameters["GetterMainCone_y"] = 0*mm;
  m_hGeometryParameters["GetterMainCone_z"] = 
	- GetGeometryParameter("TempInner_height")/2. 
	+ GetGeometryParameter("GetterMainCone_height")/2.;

  //------------------------------------Top port-------------------------------
  m_hGeometryParameters["GetterTopPort_iD"] =  18*mm; 
  m_hGeometryParameters["GetterTopPort_oD"] =  28*mm;
  //Radius of curvature
  m_hGeometryParameters["GetterTopPort_rad_curv"] =  67*mm;
  //Angle swept
  m_hGeometryParameters["GetterTopPort_ang_swept"] =  pi / 2 * radian;

  m_hGeometryParameters["GetterTopPort_x"] = 0 *mm;
  m_hGeometryParameters["GetterTopPort_y"] = 
	+ GetGeometryParameter("GetterTopPort_rad_curv") 
	- GetGeometryParameter("GetterMainCylinder_oD")/2 
	+ GetGeometryParameter("GetterTopPort_oD")/2;
  m_hGeometryParameters["GetterTopPort_z"] = -43 *mm;
        + GetGeometryParameter("GetterMainCone_height"); 
        

  //------------------------------Medium (middle) pipe-------------------------
  m_hGeometryParameters["GetterMediumPipe_height"] = 47*mm;
  m_hGeometryParameters["GetterMediumPipe_iD"] =  69*mm; 
  m_hGeometryParameters["GetterMediumPipe_oD"] =  79*mm;

  m_hGeometryParameters["GetterMediumPipe_x"] = 0 *mm;
  m_hGeometryParameters["GetterMediumPipe_y"] = 0 *mm;
  m_hGeometryParameters["GetterMediumPipe_z"] = 
	GetGeometryParameter("Container_height")/2. - (128+85+47)*mm 
	+ GetGeometryParameter("GetterMediumPipe_height")/2.;

  //-------------------------------Small (bottom) pipe-------------------------
  m_hGeometryParameters["GetterSmallPipe_height"] = 21*mm;
  m_hGeometryParameters["GetterSmallPipe_iD"] =  49*mm; 
  m_hGeometryParameters["GetterSmallPipe_oD"] =  59*mm;

  m_hGeometryParameters["GetterSmallPipe_x"] = 0 *mm;
  m_hGeometryParameters["GetterSmallPipe_y"] = 0 *mm;
  m_hGeometryParameters["GetterSmallPipe_z"] = 	
	GetGeometryParameter("ChamberBody_height")/2.  
	- GetGeometryParameter("GetterSmallPipe_height")/2.;

  //================================SteelHousing===============================
  //Steel Housing surrounds part of HV Ceramic Housing
  //not within reaction chamber

  //----------------------------------Steel Port-------------------------------
  m_hGeometryParameters["SteelPort_height"] = 133*mm;
  m_hGeometryParameters["SteelPort_iD"] =  59*mm; 
  m_hGeometryParameters["SteelPort_oD"] =  69*mm;

  m_hGeometryParameters["SteelPort_x"] = 0 *mm;
  m_hGeometryParameters["SteelPort_y"] = 0 *mm;
  m_hGeometryParameters["SteelPort_z"] =  
        - GetGeometryParameter("Container_height")/2. 
        + GetGeometryParameter("SteelPort_height")/2.;

  //----------------------------------Steel Neck-------------------------------
  m_hGeometryParameters["SteelNeck_height"] = 13*mm;
  m_hGeometryParameters["SteelNeck_iD"] =  59*mm; 
  m_hGeometryParameters["SteelNeck_oD"] =  69*mm;

  m_hGeometryParameters["SteelNeck_x"] = 0 *mm;
  m_hGeometryParameters["SteelNeck_y"] = 0 *mm;
  m_hGeometryParameters["SteelNeck_z"] =  
        - GetGeometryParameter("Container_height")/2. 
        + (133)*mm + GetGeometryParameter("SteelNeck_height")/2.;

  //----------------------------------Steel Body-------------------------------
  m_hGeometryParameters["SteelBody_height"] = 170*mm;
  m_hGeometryParameters["SteelBody_iD"] =  73*mm; 
  m_hGeometryParameters["SteelBody_oD"] =  83*mm;

  m_hGeometryParameters["SteelBody_x"] = 0 *mm;
  m_hGeometryParameters["SteelBody_y"] = 0 *mm;
  m_hGeometryParameters["SteelBody_z"] =  
        - GetGeometryParameter("Container_height")/2. 
       + (133+13)*mm + GetGeometryParameter("SteelBody_height")/2.;

  //==============================Ceramic Structure============================
  //HV Ceramic Housing. 
  //Assumed to be solid within the reaction chamber, 
  // i.e. all components after Ceramic Rim. 

  //---------------------------------Ceramic Port------------------------------
  m_hGeometryParameters["CeramicPort_height"] = 36*mm;
  m_hGeometryParameters["CeramicPort_iD"] =  22*mm; 
  m_hGeometryParameters["CeramicPort_oD"] =  31*mm;

  m_hGeometryParameters["CeramicPort_x"] = 0 *mm;
  m_hGeometryParameters["CeramicPort_y"] = 0 *mm;
  m_hGeometryParameters["CeramicPort_z"] = 
        GetGeometryParameter("SteelPort_height")/2.
        + GetGeometryParameter("SteelNeck_height")/2. 
        - GetGeometryParameter("CeramicPort_height")/2.;

  //----------------------------------Ceramic Body-----------------------------
  m_hGeometryParameters["CeramicBody_height"] = 160*mm;
  m_hGeometryParameters["CeramicBody_iD"] =  44*mm; 
  m_hGeometryParameters["CeramicBody_oD"] =  50*mm;

  m_hGeometryParameters["CeramicBody_x"] = 0 *mm;
  m_hGeometryParameters["CeramicBody_y"] = 0 *mm;
  m_hGeometryParameters["CeramicBody_z"] =  
        GetGeometryParameter("SteelBody_height")/2. 
        - GetGeometryParameter("CeramicBody_height")/2.;
  
  //---------------------------------Ceramic Neck------------------------------
  m_hGeometryParameters["CeramicNeck_height"] = 10*mm;
  m_hGeometryParameters["CeramicNeck_iD"] =  44*mm; 
  m_hGeometryParameters["CeramicNeck_oD"] =  50*mm;

  m_hGeometryParameters["CeramicNeck_x"] = 0 *mm;
  m_hGeometryParameters["CeramicNeck_y"] = 0 *mm;
  m_hGeometryParameters["CeramicNeck_z"] = 
        GetGeometryParameter("SteelBody_height")/2. 
        - GetGeometryParameter("CeramicBody_height") 
        - GetGeometryParameter("CeramicNeck_height")/2.;
  
  //----------------------------------Ceramic Rim------------------------------
  m_hGeometryParameters["CeramicRim_height"] = 13*mm;
  m_hGeometryParameters["CeramicRim_iD"] =  14*mm; 
  m_hGeometryParameters["CeramicRim_oD"] =  90*mm;

  m_hGeometryParameters["CeramicRim_x"] = 0 *mm;
  m_hGeometryParameters["CeramicRim_y"] = 0 *mm;
  m_hGeometryParameters["CeramicRim_z"] = 
        GetGeometryParameter("ChamberBody_z") 
        - GetGeometryParameter("ChamberBody_height")/2. 
        - GetGeometryParameter("CeramicRim_height")/2.;

  //--------------------------------Ceramic Big Ring----------------------------
  m_hGeometryParameters["CeramicBigRing_height"] = 36*mm;
  m_hGeometryParameters["CeramicBigRing_iD"] =  0*mm; 
  m_hGeometryParameters["CeramicBigRing_oD"] =  80*mm;

  m_hGeometryParameters["CeramicBigRing_x"] = 0 *mm;
  m_hGeometryParameters["CeramicBigRing_y"] = 0 *mm;
  m_hGeometryParameters["CeramicBigRing_z"] =  
        - GetGeometryParameter("ChamberBody_height")/2. 
        + GetGeometryParameter("CeramicBigRing_height")/2.; 

  //------------------------------Ceramic Ring Neck----------------------------
  m_hGeometryParameters["CeramicRingNeck_height"] = 27*mm;
  m_hGeometryParameters["CeramicRingNeck_iD"] =  0*mm; 
  m_hGeometryParameters["CeramicRingNeck_oD"] =  80*mm;

  m_hGeometryParameters["CeramicRingNeck_x"] = 0 *mm;
  m_hGeometryParameters["CeramicRingNeck_y"] = 0 *mm;
  m_hGeometryParameters["CeramicRingNeck_z"] =  
        - GetGeometryParameter("ChamberBody_height")/2. 
        + GetGeometryParameter("CeramicRingNeck_height")/2.
        + GetGeometryParameter("CeramicBigRing_height"); 

   //-------------------------------Ceramic Small Ring--------------------------
  m_hGeometryParameters["CeramicSmallRing_height"] = 43*mm;
  m_hGeometryParameters["CeramicSmallRing_iD"] =  0*mm; 
  m_hGeometryParameters["CeramicSmallRing_oD"] =  45*mm;

  m_hGeometryParameters["CeramicSmallRing_x"] = 0 *mm;
  m_hGeometryParameters["CeramicSmallRing_y"] = 0 *mm;
  m_hGeometryParameters["CeramicSmallRing_z"] =  
        - GetGeometryParameter("ChamberBody_height")/2. 
        + GetGeometryParameter("CeramicRingNeck_height")
        + GetGeometryParameter("CeramicBigRing_height")
        + GetGeometryParameter("CeramicSmallRing_height")/2.;
 	
  //================================Coaxial HV Cable===========================
  //Coaxial HV Cable enters from low voltage end.
  //Encase within plexiglass tube.
  //Outer conductor and sheath removed within HV housing.

  //--------------------------------Inner Conductor----------------------------
  m_hGeometryParameters["CoaxialInnerConductor_height"] = 
        GetGeometryParameter("Container_height")/2.
        + GetGeometryParameter("CeramicRim_z")
        + GetGeometryParameter("CeramicRim_height")/2.;
  m_hGeometryParameters["CoaxialInnerConductor_iD"] =  0*mm; 
  m_hGeometryParameters["CoaxialInnerConductor_oD"] =  3*mm;

  m_hGeometryParameters["CoaxialInnerConductor_x"] = 0 *mm;
  m_hGeometryParameters["CoaxialInnerConductor_y"] = 0 *mm;
  m_hGeometryParameters["CoaxialInnerConductor_z"] =  
        - GetGeometryParameter("Container_height")/2. 
   	+ GetGeometryParameter("CoaxialInnerConductor_height")/2.;

  //----------------------------------Dielectric-------------------------------
  m_hGeometryParameters["CoaxialDielectric_height"] = 
        GetGeometryParameter("CoaxialInnerConductor_height");
  m_hGeometryParameters["CoaxialDielectric_iD"] =  3*mm; 
  m_hGeometryParameters["CoaxialDielectric_oD"] =  8*mm;//!!!!!!!!

  m_hGeometryParameters["CoaxialDielectric_x"] = 0 *mm;
  m_hGeometryParameters["CoaxialDielectric_y"] = 0 *mm;
  m_hGeometryParameters["CoaxialDielectric_z"] =  
        - GetGeometryParameter("Container_height")/2. 
   	+ GetGeometryParameter("CoaxialDielectric_height")/2.;

  //--------------------------------Outer Conductor---------------------------- 
  m_hGeometryParameters["CoaxialOuterConductor_height"] = 
        GetGeometryParameter("CoaxialInnerConductor_height")
        - GetGeometryParameter("CeramicRim_height");
  m_hGeometryParameters["CoaxialOuterConductor_iD"] =  8*mm; 
  m_hGeometryParameters["CoaxialOuterConductor_oD"] =  10*mm;

  m_hGeometryParameters["CoaxialOuterConductor_x"] = 0 *mm;
  m_hGeometryParameters["CoaxialOuterConductor_y"] = 0 *mm;
  m_hGeometryParameters["CoaxialOuterConductor_z"] =  
        - GetGeometryParameter("Container_height")/2. 
   	+ GetGeometryParameter("CoaxialOuterConductor_height")/2.;

  //------------------------------------Sheath---------------------------------
  m_hGeometryParameters["CoaxialSheath_height"] = 
        GetGeometryParameter("CoaxialOuterConductor_height");
  m_hGeometryParameters["CoaxialSheath_iD"] =  10*mm; 
  m_hGeometryParameters["CoaxialSheath_oD"] =  14*mm;

  m_hGeometryParameters["CoaxialSheath_x"] = 0 *mm;
  m_hGeometryParameters["CoaxialSheath_y"] = 0 *mm;
  m_hGeometryParameters["CoaxialSheath_z"] =  
        - GetGeometryParameter("Container_height")/2. 
   	+ GetGeometryParameter("CoaxialSheath_height")/2.;

  //-------------------------------Plexiglass Tube-----------------------------
  m_hGeometryParameters["PlexiglassTube_height"] = 
        GetGeometryParameter("CoaxialOuterConductor_height");
  m_hGeometryParameters["PlexiglassTube_iD"] =  14*mm; 
  m_hGeometryParameters["PlexiglassTube_oD"] =  20*mm;

  m_hGeometryParameters["PlexiglassTube_x"] = 0 *mm;
  m_hGeometryParameters["PlexiglassTube_y"] = 0 *mm;
  m_hGeometryParameters["PlexiglassTube_z"] =  
        - GetGeometryParameter("Container_height")/2. 
   	+ GetGeometryParameter("PlexiglassTube_height")/2.;
  
  //================================Cathode====================================
  //Dimensions still to verified with NSD
  //This is the neutron producing region
  m_hGeometryParameters["Cathode_height"] = 43 *mm;
  m_hGeometryParameters["Cathode_iD"] = 18 *mm;
  m_hGeometryParameters["Cathode_oD"] = 20 *mm;
     
  m_hGeometryParameters["Cathode_x"] = 0 *mm;
  m_hGeometryParameters["Cathode_y"] = 0 *mm;
  m_hGeometryParameters["Cathode_z"] =
        - GetGeometryParameter("ChamberBody_height")/2. 
        + GetGeometryParameter("CeramicRingNeck_height")
        + GetGeometryParameter("CeramicBigRing_height")
        + GetGeometryParameter("CeramicSmallRing_height")
        + GetGeometryParameter("Cathode_height")/2.;
}
  
//==============================Neutron Generator==============================

G4VPhysicalVolume* Xenon1tNeutronGenerator::Construct()
{
  ConstructContainer();
  ConstructBulkheads();
  ConstructReactionChamber();
  ConstructCathode();
  ConstructGetter();
  ConstructSteelHousing();
  ConstructCeramic();
  ConstructCoaxialCable();
  ConstructTubes();
  return m_pContainerPhysicalVolume;
}
//==========================Neutron Generator Main Body========================
//Fill Neutron Generator with Water-Glycol coolant mixture.

void Xenon1tNeutronGenerator::ConstructContainer()
{
  G4double tolerance = GetGeometryParameter("tolerance");
  G4double opendeg  = 0.0 *deg;
  G4double closedeg = 360.0 *deg;  

  //Materials
  G4Material *Aluminium = G4Material::GetMaterial("G4_Al");
  G4Material *Coolant = G4Material::GetMaterial("WaterGlycol");
   
  //---------------------------Aluminium Housing-------------------------------

  //Dimensions
  G4double Container_height = GetGeometryParameter("Container_height");
  G4double Container_iD = GetGeometryParameter("Container_iD");
  G4double Container_oD = GetGeometryParameter("Container_oD");

  //Container
  G4Tubs *Container = 
        new G4Tubs("Container", 0,
		   Container_oD/2, Container_height/2,
		   opendeg, closedeg);
	
  m_pContainerLogicalVolume =
	new G4LogicalVolume(Container, Aluminium, "Container_log");
	
  m_pContainerPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(xPos, yPos, zPos),
			  m_pContainerLogicalVolume, "Container_phys",
			  m_pMotherLogicalVolume, false, 0);

  G4Colour ContainerColor(G4Colour::Green());
  G4VisAttributes *pContainerVisAtt = new G4VisAttributes(ContainerColor);
  pContainerVisAtt->SetForceAuxEdgeVisible(true);
  m_pContainerLogicalVolume->SetVisAttributes(pContainerVisAtt);
  
  //------------------------Water Glycol Coolant Mixture-----------------------
 
  //Dimensions
  G4double WaterGlycol_height = Container_height-tolerance;
  G4double WaterGlycol_iD = 0*mm;
  G4double WaterGlycol_oD = Container_iD - 2*tolerance;

  G4Tubs *WaterGlycol =
	new G4Tubs("WaterGlycol", WaterGlycol_iD/2,
		   WaterGlycol_oD/2, WaterGlycol_height/2,
		   opendeg, closedeg);
    
  m_pWaterGlycolLogicalVolume =
	new G4LogicalVolume(WaterGlycol, Coolant, "WaterGlycol");
    
  m_pWaterGlycolPhysicalVolume =
    new G4PVPlacement(0, G4ThreeVector(0,0,0), 
			  m_pWaterGlycolLogicalVolume, "WaterGlycol_phys", 
			  m_pContainerLogicalVolume, false, 0);
  
}

//==================================Bulkheads==================================
//Fill region between middle and upper bulkhead with air.
 
void Xenon1tNeutronGenerator::ConstructBulkheads()
{
  G4double tolerance = GetGeometryParameter("tolerance");
  G4double opendeg  = 0.0 *deg;
  G4double closedeg = 360.0 *deg;

  //Materials  
  G4Material *Aluminium = G4Material::GetMaterial("G4_Al");
  G4Material *Air = G4Material::GetMaterial("G4_AIR");
  
  //---------------------------------Top Bulkhead------------------------------

  //Dimensions
  G4double TopBulkhead_height = GetGeometryParameter("TopBulkhead_height");
  G4double TopBulkhead_iD = GetGeometryParameter("TopBulkhead_iD");
  G4double TopBulkhead_oD = GetGeometryParameter("TopBulkhead_oD");

  //Position
  G4double TopBulkhead_x = GetGeometryParameter("TopBulkhead_x");
  G4double TopBulkhead_y = GetGeometryParameter("TopBulkhead_y");
  G4double TopBulkhead_z= GetGeometryParameter("TopBulkhead_z");
 
  G4Tubs *TopBulkhead =
	new G4Tubs("TopBulkhead", TopBulkhead_iD/2,
		   TopBulkhead_oD/2, TopBulkhead_height/2,
		   opendeg, closedeg);
    
  m_pTopBulkheadLogicalVolume =
	new G4LogicalVolume(TopBulkhead, Aluminium, "TopBulkhead");
    
  m_pTopBulkheadPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(TopBulkhead_x,
                                           TopBulkhead_y, TopBulkhead_z), 
		          m_pTopBulkheadLogicalVolume, "TopBulkhead_phys", 
			  m_pWaterGlycolLogicalVolume, false, 0);

  G4Colour TopBulkheadColor(G4Colour::Blue());
  G4VisAttributes *pTopBulkheadVisAtt = new G4VisAttributes(TopBulkheadColor);
  pTopBulkheadVisAtt->SetForceAuxEdgeVisible(true);
  m_pTopBulkheadLogicalVolume->SetVisAttributes(pTopBulkheadVisAtt); 
	
  //--------------------------------Middle Bulkhead----------------------------

  //Dimensions
  G4double MiddleBulkhead_height = GetGeometryParameter("MiddleBulkhead_height");
  G4double MiddleBulkhead_iD = GetGeometryParameter("MiddleBulkhead_iD");
  G4double MiddleBulkhead_oD = GetGeometryParameter("MiddleBulkhead_oD");

  //Position
  G4double MiddleBulkhead_x = GetGeometryParameter("MiddleBulkhead_x");
  G4double MiddleBulkhead_y = GetGeometryParameter("MiddleBulkhead_y");
  G4double MiddleBulkhead_z = GetGeometryParameter("MiddleBulkhead_z");

  G4Tubs *MiddleBulkhead =
	new G4Tubs("MiddleBulkhead", MiddleBulkhead_iD/2,
		   MiddleBulkhead_oD/2, MiddleBulkhead_height/2,
		   opendeg, closedeg);
    
  m_pMiddleBulkheadLogicalVolume =
	new G4LogicalVolume(MiddleBulkhead, Aluminium, "MiddleBulkhead");
    
  m_pMiddleBulkheadPhysicalVolume =
 	new G4PVPlacement(0, G4ThreeVector(MiddleBulkhead_x,
					   MiddleBulkhead_y, MiddleBulkhead_z), 
			  m_pMiddleBulkheadLogicalVolume, "MiddleBulkhead_phys",
 			  m_pWaterGlycolLogicalVolume, false, 0);

  G4Colour MiddleBulkheadColor(G4Colour::Blue());
  G4VisAttributes *pMiddleBulkheadVisAtt = 
       new G4VisAttributes(MiddleBulkheadColor);
  pMiddleBulkheadVisAtt->SetForceAuxEdgeVisible(true);
  m_pMiddleBulkheadLogicalVolume->SetVisAttributes(pMiddleBulkheadVisAtt); 

  //-----------------------------Bottom Bulkhead-------------------------------

  //Dimensions 
  G4double BottomBulkhead_height 
	   = GetGeometryParameter("BottomBulkhead_height");
  G4double BottomBulkhead_iD = GetGeometryParameter("BottomBulkhead_iD");
  G4double BottomBulkhead_oD = GetGeometryParameter("BottomBulkhead_oD")
           - tolerance;
  
  //Position
  G4double BottomBulkhead_x = GetGeometryParameter("BottomBulkhead_x");
  G4double BottomBulkhead_y = GetGeometryParameter("BottomBulkhead_y");
  G4double BottomBulkhead_z = GetGeometryParameter("BottomBulkhead_z");
  
  G4Tubs *BottomBulkhead =
	new G4Tubs("BottomBulkhead", BottomBulkhead_iD/2,
		   BottomBulkhead_oD/2, BottomBulkhead_height/2,
		   opendeg, closedeg);
    
  m_pBottomBulkheadLogicalVolume =
	new G4LogicalVolume(BottomBulkhead, Aluminium, "BottomBulkhead");
    
  m_pBottomBulkheadPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(BottomBulkhead_x,
		 		           BottomBulkhead_y, BottomBulkhead_z), 
			  m_pBottomBulkheadLogicalVolume, 
			  "BottomBulkhead_phys",
 			  m_pWaterGlycolLogicalVolume, false, 0);

  G4Colour BottomBulkheadColor(G4Colour::Blue());
  G4VisAttributes *pBottomBulkheadVisAtt = 
       new G4VisAttributes(BottomBulkheadColor);
  pBottomBulkheadVisAtt->SetForceAuxEdgeVisible(true);
  m_pBottomBulkheadLogicalVolume->SetVisAttributes(pBottomBulkheadVisAtt); 
   
  //--------------------------------Air Volume---------------------------------
  
  //Dimensions 
  G4double TempInner_height 
	   = GetGeometryParameter("TempInner_height");
  G4double TempInner_iD = GetGeometryParameter("TempInner_iD");
  G4double TempInner_oD = GetGeometryParameter("TempInner_oD")
           - tolerance;
  
  //Position
  G4double TempInner_x = GetGeometryParameter("TempInner_x");
  G4double TempInner_y = GetGeometryParameter("TempInner_y");
  G4double TempInner_z = GetGeometryParameter("TempInner_z");
  
  G4Tubs *TempInner = 
        new G4Tubs("TempInner", TempInner_iD/2,
		   TempInner_oD/2 - tolerance, TempInner_height/2,
		   opendeg, closedeg);
	
  m_pTempInnerLogicalVolume =
	new G4LogicalVolume(TempInner, Air, "TempInner");
	
  m_pTempInnerPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(TempInner_x,
					   TempInner_y, TempInner_z),
			  m_pTempInnerLogicalVolume, "TempInner",
			  m_pWaterGlycolLogicalVolume, false, 0);
  
  G4Colour TempInnerColor(G4Colour::Cyan());
  G4VisAttributes *pTempInnerVisAtt = new G4VisAttributes(TempInnerColor);
  pTempInnerVisAtt->SetForceAuxEdgeVisible(true);
  m_pTempInnerLogicalVolume->SetVisAttributes(pTempInnerVisAtt);

  //---------------------------Ring Air Volume---------------------------------
  
  //Dimensions 
  G4double TempInnerRing_height 
	   = GetGeometryParameter("TempInnerRing_height");
  G4double TempInnerRing_iD = GetGeometryParameter("TempInnerRing_iD");
  G4double TempInnerRing_oD = GetGeometryParameter("TempInnerRing_oD")
           - tolerance;
  
  //Position
  G4double TempInnerRing_x = GetGeometryParameter("TempInnerRing_x");
  G4double TempInnerRing_y = GetGeometryParameter("TempInnerRing_y");
  G4double TempInnerRing_z = GetGeometryParameter("TempInnerRing_z");
  
  G4Tubs *TempInnerRing = 
        new G4Tubs("TempInnerRing", TempInnerRing_iD/2,
		   TempInnerRing_oD/2 - tolerance, TempInnerRing_height/2,
		   opendeg, closedeg);
	
  m_pTempInnerRingLogicalVolume =
	new G4LogicalVolume(TempInnerRing, Air, "TempInnerRing");
	
  m_pTempInnerRingPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(TempInnerRing_x,
					   TempInnerRing_y, TempInnerRing_z),
			  m_pTempInnerRingLogicalVolume, "TempInner",
			  m_pWaterGlycolLogicalVolume, false, 0);
  
  G4Colour TempInnerRingColor(G4Colour::Cyan());
  G4VisAttributes *pTempInnerRingVisAtt = 
       new G4VisAttributes(TempInnerRingColor);
  pTempInnerRingVisAtt->SetForceAuxEdgeVisible(true);
  m_pTempInnerRingLogicalVolume->SetVisAttributes(pTempInnerRingVisAtt);
  
}

//============================Al Water Manifold Tubes==========================
 
void Xenon1tNeutronGenerator::ConstructTubes()
{
  G4double opendeg  = 0.0 *deg;
  G4double closedeg = 360.0 *deg;

  //Materials
  G4Material *WaterGlycol = G4Material::GetMaterial("WaterGlycol");

  //---------------------------------Tubes------------------------------------
  
  //Dimensions
  G4double Tubes_height = GetGeometryParameter("Tubes_height");
  G4double Tubes_iD = GetGeometryParameter("Tubes_iD"); 
  G4double Tubes_oD = GetGeometryParameter("Tubes_oD");
  G4double Tubes_rad_from_axis = GetGeometryParameter("Tubes_rad_from_axis");
  G4int Tubes_number = G4int(GetGeometryParameter("Tubes_number"));
  
  //Position
  G4double TubesAxis_x = GetGeometryParameter("TubesAxis_x");
  G4double TubesAxis_y = GetGeometryParameter("TubesAxis_y");
  G4double TubesAxis_z = GetGeometryParameter("TubesAxis_z");

  G4Tubs * SingleTube = new G4Tubs("SingleTube", Tubes_iD/2,
				   Tubes_oD/2, Tubes_height/2,
				   opendeg, closedeg);
  
  m_pTubeLogicalVolume =
	new G4LogicalVolume(SingleTube, WaterGlycol, "SingleTube");
  
  for (int i=0; i<Tubes_number; ++i) 
    {
    G4double Tube_x = TubesAxis_x 
      + Tubes_rad_from_axis*cos(i*2*pi/G4double(Tubes_number));
    G4double Tube_y = TubesAxis_y 
      + Tubes_rad_from_axis*sin(i*2*pi/G4double(Tubes_number));
    G4double Tube_z = TubesAxis_z;
 
    m_pTubePhysicalVolumes.push_back(new G4PVPlacement(0, 
				     G4ThreeVector(Tube_x, Tube_y, Tube_z),
				     m_pTubeLogicalVolume, "Tubes_phys",
				     m_pBottomBulkheadLogicalVolume, false, i)
				     );				     
    }

  G4Colour TubeColor(G4Colour::White());
  G4VisAttributes *pTubeVisAtt = new G4VisAttributes(TubeColor);
  pTubeVisAtt->SetForceAuxEdgeVisible(true);
  m_pTubeLogicalVolume->SetVisAttributes(pTubeVisAtt);
}

//================================Getter Pump Module===========================
//Getter Pump Module filled with deuterium gas.
 
void Xenon1tNeutronGenerator::ConstructGetter()
{
  G4double tolerance = GetGeometryParameter("tolerance");
  G4double opendeg  = 0.0 *deg;
  G4double closedeg = 360.0 *deg;  

  //Materials
  G4Material *NiCrSteel = G4Material::GetMaterial("NiCrSteel");
  G4Material *DeuteriumGas = G4Material::GetMaterial("DeuteriumGas");
  
  //-------------------------------Main cylinder-------------------------------
  
  //Dimensions
  double GetterMainCylinder_height = 
         GetGeometryParameter("GetterMainCylinder_height");
  double GetterMainCylinder_iD = GetGeometryParameter("GetterMainCylinder_iD");
  double GetterMainCylinder_oD = GetGeometryParameter("GetterMainCylinder_oD");

  //Position
  double GetterMainCylinder_x = GetGeometryParameter("GetterMainCylinder_x");
  double GetterMainCylinder_y = GetGeometryParameter("GetterMainCylinder_y");
  double GetterMainCylinder_z = GetGeometryParameter("GetterMainCylinder_z");
  
  
  G4Tubs *GetterMainCylinder =
	new G4Tubs("GetterMainCylinder", 0,
		   GetterMainCylinder_oD/2, GetterMainCylinder_height/2,
		   opendeg, closedeg);

  G4Tubs *GetterMainCylinderGas =
        new G4Tubs("GetterMainCylinderGas", 0,
		   GetterMainCylinder_iD/2 - tolerance,
		   GetterMainCylinder_height/2,
		   opendeg, closedeg);
    
  m_pGetterMainCylinderLogicalVolume =
	new G4LogicalVolume(GetterMainCylinder, NiCrSteel, 
                            "GetterMainCylinder");

  m_pGetterMainCylinderGasLogicalVolume =
	new G4LogicalVolume(GetterMainCylinderGas, DeuteriumGas, 
                            "GetterMainCylinderGas");
    
  m_pGetterMainCylinderPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(GetterMainCylinder_x,
					   GetterMainCylinder_y,
					   GetterMainCylinder_z), 
			 m_pGetterMainCylinderLogicalVolume, 
                         "GetterMainCylinder_phys",
                         m_pWaterGlycolLogicalVolume, false, 0);
 
  m_pGetterMainCylinderGasPhysicalVolume =
    new G4PVPlacement(0, G4ThreeVector(0,0,0), 
		      m_pGetterMainCylinderGasLogicalVolume, 
		      "GetterMainCylinderGas_phys", 
                      m_pGetterMainCylinderLogicalVolume, false, 0);

  G4Colour GetterMainCylinderColor(G4Colour::Red());
  G4VisAttributes *pGetterMainCylinderVisAtt = 
       new G4VisAttributes(GetterMainCylinderColor);
  pGetterMainCylinderVisAtt->SetForceAuxEdgeVisible(true);
  m_pGetterMainCylinderLogicalVolume->
  SetVisAttributes(pGetterMainCylinderVisAtt); 


  //--------------------------------Main Cone----------------------------------
  
  //Dimensions
  double GetterMainCone_height = GetGeometryParameter("GetterMainCone_height");
  double GetterMainCone_iD = GetGeometryParameter("GetterMainCone_iD");
  double GetterMainCone_oD = GetGeometryParameter("GetterMainCone_oD");
 
  //Position
  double GetterMainCone_x = GetGeometryParameter("GetterMainCone_x");
  double GetterMainCone_y = GetGeometryParameter("GetterMainCone_y");
  double GetterMainCone_z = GetGeometryParameter("GetterMainCone_z");

  G4Cons *GetterMainCone =
	new G4Cons("GetterMainCone", 
		   0, GetterMainCone_oD/2,  0, 10 *mm,
		   GetterMainCone_height/2,  opendeg, closedeg);

 G4Cons *GetterMainConeGas =
	new G4Cons("GetterMainConeGas", 
		   0, GetterMainCone_iD/2,  0, 0,
		   GetterMainCone_height/2,  opendeg, closedeg);
    
  m_pGetterMainConeLogicalVolume =
	new G4LogicalVolume(GetterMainCone, NiCrSteel, "GetterMainCone");

  m_pGetterMainConeGasLogicalVolume =
	new G4LogicalVolume(GetterMainConeGas, DeuteriumGas, 
                            "GetterMainConeGas");
    
  m_pGetterMainConePhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(GetterMainCone_x,
					   GetterMainCone_y, GetterMainCone_z), 
			  m_pGetterMainConeLogicalVolume, 
			  "GetterMainCone_phys", 
			  m_pTempInnerLogicalVolume, false, 0);

  m_pGetterMainConeGasPhysicalVolume =
    new G4PVPlacement(0, G4ThreeVector(0,0,0), 
			  m_pGetterMainConeGasLogicalVolume, 
                          "GetterMainConeGas_phys", 
			  m_pGetterMainConeLogicalVolume, false, 0);

  G4Colour GetterMainConeColor(G4Colour::Red());
  G4VisAttributes *pGetterMainConeVisAtt = 
       new G4VisAttributes(GetterMainConeColor);
  pGetterMainConeVisAtt->SetForceAuxEdgeVisible(true);
  m_pGetterMainConeLogicalVolume->SetVisAttributes(pGetterMainConeVisAtt); 
  
  //-------------------------------Medium Pipe---------------------------------

  //Dimensions
  double GetterMediumPipe_height = 
         GetGeometryParameter("GetterMediumPipe_height");
  double GetterMediumPipe_iD = GetGeometryParameter("GetterMediumPipe_iD");
  double GetterMediumPipe_oD = GetGeometryParameter("GetterMediumPipe_oD");

  //Position
  double GetterMediumPipe_x = GetGeometryParameter("GetterMediumPipe_x");
  double GetterMediumPipe_y = GetGeometryParameter("GetterMediumPipe_y");
  double GetterMediumPipe_z = GetGeometryParameter("GetterMediumPipe_z");
  
  G4Tubs *GetterMediumPipe =
	new G4Tubs("GetterMediumPipe", 0,
		   GetterMediumPipe_oD/2, GetterMediumPipe_height/2,
		   opendeg, closedeg);

  G4Tubs *GetterMediumPipeGas =
        new G4Tubs("GetterMediumPipeGas", 0,
		   GetterMediumPipe_iD/2 - tolerance, GetterMediumPipe_height/2,
		   opendeg, closedeg);
    
  m_pGetterMediumPipeLogicalVolume =
	new G4LogicalVolume(GetterMediumPipe, NiCrSteel, "GetterMediumPipe");

  m_pGetterMediumPipeGasLogicalVolume =
	new G4LogicalVolume(GetterMediumPipeGas, DeuteriumGas, 
                            "GetterMediumPipeGas");
    
  m_pGetterMediumPipePhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(GetterMediumPipe_x,
					   GetterMediumPipe_y,
					   GetterMediumPipe_z), 
			 m_pGetterMediumPipeLogicalVolume, 
                         "GetterMediumPipe_phys", 
                         m_pWaterGlycolLogicalVolume, false, 0);
 
  m_pGetterMediumPipeGasPhysicalVolume =
    new G4PVPlacement(0, G4ThreeVector(0,0,0), 
			 m_pGetterMediumPipeGasLogicalVolume, 
                         "GetterMediumPipeGas_phys", 
                         m_pGetterMediumPipeLogicalVolume, false, 0);

  G4Colour GetterMediumPipeColor(G4Colour::Red());
  G4VisAttributes *pGetterMediumPipeVisAtt = 
       new G4VisAttributes(GetterMediumPipeColor);
  pGetterMediumPipeVisAtt->SetForceAuxEdgeVisible(true);
  m_pGetterMediumPipeLogicalVolume->SetVisAttributes(pGetterMediumPipeVisAtt); 
  
  //---------------------------------Small pipe--------------------------------
  
  //Dimensions
  double GetterSmallPipe_height = 
         GetGeometryParameter("GetterSmallPipe_height");
  double GetterSmallPipe_iD = GetGeometryParameter("GetterSmallPipe_iD");
  double GetterSmallPipe_oD = GetGeometryParameter("GetterSmallPipe_oD");

  //Position
  double GetterSmallPipe_x = GetGeometryParameter("GetterSmallPipe_x");
  double GetterSmallPipe_y = GetGeometryParameter("GetterSmallPipe_y");
  double GetterSmallPipe_z = GetGeometryParameter("GetterSmallPipe_z");

  G4Tubs *GetterSmallPipe =
	new G4Tubs("GetterSmallPipe", 0,
		   GetterSmallPipe_oD/2, GetterSmallPipe_height/2,
		   opendeg, closedeg);

  G4Tubs *GetterSmallPipeGas =
        new G4Tubs("GetterSmallPipeGas", 0,
		   GetterSmallPipe_iD/2 - tolerance, GetterSmallPipe_height/2,
		   opendeg, closedeg);
    
  m_pGetterSmallPipeLogicalVolume =
	new G4LogicalVolume(GetterSmallPipe, NiCrSteel, "GetterSmallPipe");

  m_pGetterSmallPipeGasLogicalVolume =
	new G4LogicalVolume(GetterSmallPipeGas, DeuteriumGas, 
                            "GetterSmallPipeGas");
    
  m_pGetterSmallPipePhysicalVolume =
    new G4PVPlacement(0, G4ThreeVector(GetterSmallPipe_x,
				       GetterSmallPipe_y,
				       GetterSmallPipe_z), 
			 m_pGetterSmallPipeLogicalVolume, 
                         "GetterSmallPipe_phys", 
                         m_pDeuteriumLogicalVolume, false, 0);
 
  m_pGetterSmallPipeGasPhysicalVolume =
    new G4PVPlacement(0, G4ThreeVector(0,0,0), 
		      m_pGetterSmallPipeGasLogicalVolume, 
                      "GetterSmallPipeGas_phys", 
                      m_pGetterSmallPipeLogicalVolume, false, 0);

  G4Colour GetterSmallPipeColor(G4Colour::Red());
  G4VisAttributes *pGetterSmallPipeVisAtt = 
       new G4VisAttributes(GetterSmallPipeColor);
  pGetterSmallPipeVisAtt->SetForceAuxEdgeVisible(true);
  m_pGetterSmallPipeLogicalVolume->SetVisAttributes(pGetterSmallPipeVisAtt); 
  
  //-------------------------------Top Port------------------------------------
  G4RotationMatrix *pTopPort = new G4RotationMatrix();
  pTopPort->rotateX(180.*deg);
  pTopPort->rotateY(270.*deg);
  pTopPort->rotateZ(0.*deg);

  //Dimensions
  double GetterTopPort_iD = GetGeometryParameter("GetterTopPort_iD");
  double GetterTopPort_oD = GetGeometryParameter("GetterTopPort_oD");
  double GetterTopPort_rad_curv = 
         GetGeometryParameter("GetterTopPort_rad_curv");
  double GetterTopPort_ang_swept = 
         GetGeometryParameter("GetterTopPort_ang_swept");

  //Position
  double GetterTopPort_x = GetGeometryParameter("GetterTopPort_x");
  double GetterTopPort_y = GetGeometryParameter("GetterTopPort_y");
  double GetterTopPort_z = GetGeometryParameter("GetterTopPort_z");

  G4Torus *GetterTopPort =
	new G4Torus("GetterTopPort", 0, GetterTopPort_oD/2, 
		    GetterTopPort_rad_curv, 0, GetterTopPort_ang_swept);

   G4Torus *GetterTopPortGas =
	new G4Torus("GetterTopPortGas", 0, GetterTopPort_iD/2 - tolerance, 
		    GetterTopPort_rad_curv, 0, GetterTopPort_ang_swept);
    
  m_pGetterTopPortLogicalVolume =
	new G4LogicalVolume(GetterTopPort, NiCrSteel, "GetterTopPort");

  m_pGetterTopPortGasLogicalVolume =
	new G4LogicalVolume(GetterTopPortGas, DeuteriumGas, "GetterTopPortGas");
    
  m_pGetterTopPortPhysicalVolume =
	new G4PVPlacement(pTopPort, G4ThreeVector(GetterTopPort_x,
						  GetterTopPort_y,
						  GetterTopPort_z), 
			  m_pGetterTopPortLogicalVolume, "GetterTopPort_phys", 
			  m_pTempInnerLogicalVolume, false, 0);
 
 m_pGetterTopPortGasPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(0,0,0), 
			  m_pGetterTopPortGasLogicalVolume, 
                          "GetterTopPortGas_phys", 
		          m_pGetterTopPortLogicalVolume, false, 0);


  G4Colour GetterTopPortColor(G4Colour::Red());
  G4VisAttributes *pGetterTopPortVisAtt = 
       new G4VisAttributes(GetterTopPortColor);
  pGetterTopPortVisAtt->SetForceAuxEdgeVisible(true);
  m_pGetterTopPortLogicalVolume->SetVisAttributes(pGetterTopPortVisAtt);
  
}


 
//================================Reaction Chamber=============================
//The reaction chamber has 50 cooling fins on its outside surface.
//The reaction chamber is filled with deuterium gas.

void Xenon1tNeutronGenerator::ConstructReactionChamber()
{
  G4double tolerance = GetGeometryParameter("tolerance");
  G4double opendeg  = 0.0 *deg;
  G4double closedeg = 360.0 *deg;

  //Materials
  G4Material *Aluminium = G4Material::GetMaterial("G4_Al");
  G4Material *DeuteriumGas = G4Material::GetMaterial("DeuteriumGas");
  
  //--------------------------------Chamber Body-------------------------------

  //Dimensions
  G4double ChamberBody_height = GetGeometryParameter("ChamberBody_height");
  G4double ChamberBody_iD = GetGeometryParameter("ChamberBody_iD");
  G4double ChamberBody_oD = GetGeometryParameter("ChamberBody_oD");

  //Position
  G4double ChamberBody_x = GetGeometryParameter("ChamberBody_x");
  G4double ChamberBody_y = GetGeometryParameter("ChamberBody_y");
  G4double ChamberBody_z = GetGeometryParameter("ChamberBody_z");
 
  G4Tubs *ChamberBody =
	new G4Tubs("ChamberBody", 0,
		   ChamberBody_oD/2, ChamberBody_height/2,
		   opendeg, closedeg);
    
  m_pChamberBodyLogicalVolume =
	new G4LogicalVolume(ChamberBody, Aluminium, "ChamberBody_log");
    
  m_pChamberBodyPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(ChamberBody_x, 
					   ChamberBody_y, ChamberBody_z), 
			  m_pChamberBodyLogicalVolume, "ChamberBody_phys", 
			  m_pWaterGlycolLogicalVolume, false, 0);

 
  G4Colour ChamberBodyColor(G4Colour::Magenta());
  G4VisAttributes *pChamberBodyVisAtt = new G4VisAttributes(ChamberBodyColor);
  pChamberBodyVisAtt->SetForceAuxEdgeVisible(true);
  //Comment out this line to see the chamber body
  pChamberBodyVisAtt->SetVisibility(false);
  m_pChamberBodyLogicalVolume->SetVisAttributes(pChamberBodyVisAtt);
   
  //------------------------------Deuterium Gas--------------------------------
  
  G4Tubs *Deuterium =
         new G4Tubs("Deuterium", 0,
		    ChamberBody_iD/2 - tolerance, ChamberBody_height/2,
		    opendeg, closedeg);
    
  m_pDeuteriumLogicalVolume =
	new G4LogicalVolume(Deuterium, DeuteriumGas, "Deuterium_log");
    
  m_pDeuteriumPhysicalVolume =
    new G4PVPlacement(0, G4ThreeVector(0,0,0), 
			  m_pDeuteriumLogicalVolume, "Deuterium_phys", 
			  m_pChamberBodyLogicalVolume, false, 0);
  
  //---------------------------Cooling Fins------------------------------------

  //Dimensions
  G4double Fins_height = GetGeometryParameter("Fins_height");
  G4double Fins_width = GetGeometryParameter("Fins_width"); 
  G4double Fins_depth = GetGeometryParameter("Fins_depth") - 2*tolerance;
  G4double Fins_rad_from_axis = GetGeometryParameter("Fins_rad_from_axis");
  G4int Fins_number = G4int(GetGeometryParameter("Fins_number"));
  
  //Position
  G4double FinsAxis_x = GetGeometryParameter("FinsAxis_x");
  G4double FinsAxis_y = GetGeometryParameter("FinsAxis_y");
  G4double FinsAxis_z = GetGeometryParameter("FinsAxis_z");

  G4Box *SingleFin = new G4Box("SingleFin", Fins_depth/2,
				   Fins_width/2, Fins_height/2);

  m_pFinLogicalVolume =
	new G4LogicalVolume(SingleFin, Aluminium, "SingleFin");
  
  for (int i=0; i<Fins_number; ++i) {
    G4RotationMatrix* zRot = new G4RotationMatrix;
    zRot->rotateZ(-i*2*pi/G4double(Fins_number));
    G4double Fin_x = FinsAxis_x 
      + Fins_rad_from_axis*cos(i*2*pi/G4double(Fins_number));
    G4double Fin_y = FinsAxis_y 
      + Fins_rad_from_axis*sin(i*2*pi/G4double(Fins_number));
    G4double Fin_z = FinsAxis_z; 
    m_pFinPhysicalVolumes.push_back(new G4PVPlacement(zRot, 
				    G4ThreeVector(Fin_x, Fin_y, Fin_z),
				    m_pFinLogicalVolume, "Fins_phys",
				    m_pWaterGlycolLogicalVolume, false, i)
				    );
    }
  
  G4Colour FinColor(G4Colour::Magenta());
  G4VisAttributes *pFinVisAtt = new G4VisAttributes(FinColor);
  pFinVisAtt->SetForceAuxEdgeVisible(true);
  //Comment out this line to see the fins
  pFinVisAtt->SetVisibility(false);
  m_pFinLogicalVolume->SetVisAttributes(pFinVisAtt);
   
}

//===================================Cathode===================================

void Xenon1tNeutronGenerator::ConstructCathode()
{
  G4double opendeg  = 0.0 *deg;
  G4double closedeg = 360.0 *deg; 

  //Materials
  G4Material *Aluminium = G4Material::GetMaterial("G4_Al");
  
  //---------------------------------Cathode-----------------------------------

  //Dimensions
  G4double Cathode_height = GetGeometryParameter("Cathode_height");
  G4double Cathode_iD = GetGeometryParameter("Cathode_iD");
  G4double Cathode_oD = GetGeometryParameter("Cathode_oD");

  //Position
  G4double Cathode_x = GetGeometryParameter("Cathode_x");
  G4double Cathode_y = GetGeometryParameter("Cathode_y");
  G4double Cathode_z = GetGeometryParameter("Cathode_z");

  G4Tubs *Cathode =
	new G4Tubs("Cathode", Cathode_iD/2,
		   Cathode_oD/2, Cathode_height/2,
		   opendeg, closedeg);
    
  m_pCathodeLogicalVolume =
	new G4LogicalVolume(Cathode, Aluminium, "Cathode");
    
  m_pCathodePhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(Cathode_x,
					   Cathode_y, Cathode_z), 
			  m_pCathodeLogicalVolume, "Cathode_phys", 
			  m_pDeuteriumLogicalVolume, false, 0);

  G4Colour CathodeColor(G4Colour::White());
  G4VisAttributes *pCathodeVisAtt = new G4VisAttributes(CathodeColor);
  pCathodeVisAtt->SetForceAuxEdgeVisible(true);
  m_pCathodeLogicalVolume->SetVisAttributes(pCathodeVisAtt);
}

//============================HV Coaxial Cable=================================

void Xenon1tNeutronGenerator::ConstructCoaxialCable()
{
  G4double tolerance = GetGeometryParameter("tolerance");
  G4double opendeg  = 0.0 *deg;
  G4double closedeg = 360.0 *deg;

  //Materials
  G4Material *Copper = G4Material::GetMaterial("G4_Cu");
  G4Material *PE = G4Material::GetMaterial("Polyethylene");
  G4Material *Plexiglass = G4Material::GetMaterial("G4_PLEXIGLASS");
  
  //------------------------------Inner Conductor------------------------------
  
  //Dimensions
  G4double CoaxialInnerConductor_height = 
           GetGeometryParameter("CoaxialInnerConductor_height");
  G4double CoaxialInnerConductor_iD = 
           GetGeometryParameter("CoaxialInnerConductor_iD");
  G4double CoaxialInnerConductor_oD = 
           GetGeometryParameter("CoaxialInnerConductor_oD");

  //Position
  G4double CoaxialInnerConductor_x = 
           GetGeometryParameter("CoaxialInnerConductor_x");
  G4double CoaxialInnerConductor_y = 
           GetGeometryParameter("CoaxialInnerConductor_y");
  G4double CoaxialInnerConductor_z= 
           GetGeometryParameter("CoaxialInnerConductor_z");
 
  G4Tubs *CoaxialInnerConductor =
	new G4Tubs("CoaxialInnerConductor", CoaxialInnerConductor_iD/2,
		   CoaxialInnerConductor_oD/2, CoaxialInnerConductor_height/2,
		   opendeg, closedeg);
    
  m_pCoaxialInnerConductorLogicalVolume =
	new G4LogicalVolume(CoaxialInnerConductor, Copper, 
                            "CoaxialInnerConductor");
    
  m_pCoaxialInnerConductorPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(CoaxialInnerConductor_x,
					   CoaxialInnerConductor_y,
					   CoaxialInnerConductor_z), 
			  m_pCoaxialInnerConductorLogicalVolume, 
                          "CoaxialInnerConductor_phys", 
			  m_pWaterGlycolLogicalVolume, false, 0);

  G4Colour CoaxialInnerConductorColor(G4Colour::Red());
  G4VisAttributes *pCoaxialInnerConductorVisAtt = 
       new G4VisAttributes(CoaxialInnerConductorColor);
  pCoaxialInnerConductorVisAtt->SetForceAuxEdgeVisible(true);
  m_pCoaxialInnerConductorLogicalVolume->
    SetVisAttributes(pCoaxialInnerConductorVisAtt);

  //----------------------------------Dielectric-------------------------------
  
  //Dimensions
  G4double CoaxialDielectric_height = 
           GetGeometryParameter("CoaxialDielectric_height");
  G4double CoaxialDielectric_iD = GetGeometryParameter("CoaxialDielectric_iD");
  G4double CoaxialDielectric_oD = GetGeometryParameter("CoaxialDielectric_oD");

  //Position
  G4double CoaxialDielectric_x 	= GetGeometryParameter("CoaxialDielectric_x");
  G4double CoaxialDielectric_y 	= GetGeometryParameter("CoaxialDielectric_y");
  G4double CoaxialDielectric_z	= GetGeometryParameter("CoaxialDielectric_z");
 
  G4Tubs *CoaxialDielectric =
	new G4Tubs("CoaxialDielectric", CoaxialDielectric_iD/2,
		   CoaxialDielectric_oD/2, CoaxialDielectric_height/2,
		   opendeg, closedeg);
    
  m_pCoaxialDielectricLogicalVolume =
	new G4LogicalVolume(CoaxialDielectric, PE, "CoaxialDielectric");
    
  m_pCoaxialDielectricPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(CoaxialDielectric_x,
					   CoaxialDielectric_y,
					   CoaxialDielectric_z), 
			  m_pCoaxialDielectricLogicalVolume, 
			  "CoaxialDielectric_phys", 
			  m_pWaterGlycolLogicalVolume, false, 0);

  G4Colour CoaxialDielectricColor(G4Colour::Blue());
  G4VisAttributes *pCoaxialDielectricVisAtt = 
       new G4VisAttributes(CoaxialDielectricColor);
  pCoaxialDielectricVisAtt->SetForceAuxEdgeVisible(true);
  m_pCoaxialDielectricLogicalVolume->SetVisAttributes(pCoaxialDielectricVisAtt);

  //-----------------------------OuterConductor--------------------------------
  
  //Dimensions
  G4double CoaxialOuterConductor_height = 
           GetGeometryParameter("CoaxialOuterConductor_height");
  G4double CoaxialOuterConductor_iD = 
           GetGeometryParameter("CoaxialOuterConductor_iD");
  G4double CoaxialOuterConductor_oD = 
           GetGeometryParameter("CoaxialOuterConductor_oD");

  //Position
  G4double CoaxialOuterConductor_x = 
           GetGeometryParameter("CoaxialOuterConductor_x");
  G4double CoaxialOuterConductor_y =
           GetGeometryParameter("CoaxialOuterConductor_y");
  G4double CoaxialOuterConductor_z= 
           GetGeometryParameter("CoaxialOuterConductor_z");
 
  G4Tubs *CoaxialOuterConductor =
	new G4Tubs("CoaxialOuterConductor", CoaxialOuterConductor_iD/2,
		   CoaxialOuterConductor_oD/2, CoaxialOuterConductor_height/2,
		   opendeg, closedeg);
    
  m_pCoaxialOuterConductorLogicalVolume =
	new G4LogicalVolume(CoaxialOuterConductor, Copper, 
                            "CoaxialOuterConductor");
    
  m_pCoaxialOuterConductorPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(CoaxialOuterConductor_x,
					   CoaxialOuterConductor_y,
					   CoaxialOuterConductor_z), 
			  m_pCoaxialOuterConductorLogicalVolume, 
			  "CoaxialOuterConductor_phys", 
			  m_pWaterGlycolLogicalVolume, false, 0);

  G4Colour CoaxialOuterConductorColor(G4Colour::Yellow());
  G4VisAttributes *pCoaxialOuterConductorVisAtt = 
       new G4VisAttributes(CoaxialOuterConductorColor);
  pCoaxialOuterConductorVisAtt->SetForceAuxEdgeVisible(true);
  m_pCoaxialOuterConductorLogicalVolume->
    SetVisAttributes(pCoaxialOuterConductorVisAtt);

  //------------------------------Sheath---------------------------------------
  
  //Dimensions
  G4double CoaxialSheath_height = GetGeometryParameter("CoaxialSheath_height");
  G4double CoaxialSheath_iD = GetGeometryParameter("CoaxialSheath_iD");
  G4double CoaxialSheath_oD = GetGeometryParameter("CoaxialSheath_oD");


  //Position
  G4double CoaxialSheath_x 	= GetGeometryParameter("CoaxialSheath_x");
  G4double CoaxialSheath_y 	= GetGeometryParameter("CoaxialSheath_y");
  G4double CoaxialSheath_z	= GetGeometryParameter("CoaxialSheath_z");
 
  G4Tubs *CoaxialSheath =
	new G4Tubs("CoaxialSheath", CoaxialSheath_iD/2,
		   CoaxialSheath_oD/2, CoaxialSheath_height/2,
		   opendeg, closedeg);
    
  m_pCoaxialSheathLogicalVolume =
	new G4LogicalVolume(CoaxialSheath, PE, "CoaxialSheath");
    
  m_pCoaxialSheathPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(CoaxialSheath_x,
					   CoaxialSheath_y,
					   CoaxialSheath_z), 
			  m_pCoaxialSheathLogicalVolume, "CoaxialSheath_phys", 
			  m_pWaterGlycolLogicalVolume, false, 0);

  G4Colour CoaxialSheathColor(G4Colour::Red());
  G4VisAttributes *pCoaxialSheathVisAtt = 
       new G4VisAttributes(CoaxialSheathColor);
  pCoaxialSheathVisAtt->SetForceAuxEdgeVisible(true);
  m_pCoaxialSheathLogicalVolume->SetVisAttributes(pCoaxialSheathVisAtt);

  //-----------------------------Plexiglass Tube-------------------------------
  
  //Dimensions
  G4double PlexiglassTube_height = 
           GetGeometryParameter("PlexiglassTube_height");
  G4double PlexiglassTube_iD = GetGeometryParameter("PlexiglassTube_iD");
  G4double PlexiglassTube_oD = GetGeometryParameter("PlexiglassTube_oD");

  //Position
  G4double PlexiglassTube_x 	= GetGeometryParameter("PlexiglassTube_x");
  G4double PlexiglassTube_y 	= GetGeometryParameter("PlexiglassTube_y");
  G4double PlexiglassTube_z	= GetGeometryParameter("PlexiglassTube_z");
 
  G4Tubs *PlexiglassTube =
	new G4Tubs("PlexiglassTube", PlexiglassTube_iD/2,
		   PlexiglassTube_oD/2 - tolerance, PlexiglassTube_height/2,
		   opendeg, closedeg);
    
  m_pPlexiglassTubeLogicalVolume =
	new G4LogicalVolume(PlexiglassTube, Plexiglass, "PlexiglassTube");
    
  m_pPlexiglassTubePhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(PlexiglassTube_x,
					   PlexiglassTube_y, PlexiglassTube_z), 
			  m_pPlexiglassTubeLogicalVolume, 
			  "PlexiglassTube_phys", 
			  m_pWaterGlycolLogicalVolume, false, 0);

  G4Colour PlexiglassTubeColor(G4Colour::Yellow());
  G4VisAttributes *pPlexiglassTubeVisAtt = 
       new G4VisAttributes(PlexiglassTubeColor);
  pPlexiglassTubeVisAtt->SetForceAuxEdgeVisible(true);
  m_pPlexiglassTubeLogicalVolume->SetVisAttributes(pPlexiglassTubeVisAtt);
}


//==============================Ceramic HV Housing =============================
//The volume between the coaxial cable and
//the ceramic housing is filled with transformer oil.

void Xenon1tNeutronGenerator::ConstructCeramic()
{
  G4double tolerance = GetGeometryParameter("tolerance");
  G4double opendeg  = 0.0 *deg;
  G4double closedeg = 360.0 *deg;

  //Materials
  G4Material *Al2O3 = G4Material::GetMaterial("Al2O3");
  G4Material *TransformerOil = G4Material::GetMaterial("TransformerOil");
  
  //These sections lie outside the reaction chamber.
  //------------------------------Ceramic Port---------------------------------
  
  //Dimensions
  G4double CeramicPort_height = GetGeometryParameter("CeramicPort_height");
  G4double CeramicPort_iD = GetGeometryParameter("CeramicPort_iD");
  G4double CeramicPort_oD = GetGeometryParameter("CeramicPort_oD");
  
  //Position
  G4double CeramicPort_x = GetGeometryParameter("CeramicPort_x");
  G4double CeramicPort_y = GetGeometryParameter("CeramicPort_y");
  G4double CeramicPort_z = GetGeometryParameter("CeramicPort_z");
 
  G4Tubs *CeramicPort =
	new G4Tubs("CeramicPort", CeramicPort_iD/2,
		   CeramicPort_oD/2, CeramicPort_height/2,
		   opendeg, closedeg);
    
  m_pCeramicPortLogicalVolume =
	new G4LogicalVolume(CeramicPort, Al2O3, "CeramicPort");
    
  m_pCeramicPortPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(CeramicPort_x,
					   CeramicPort_y, CeramicPort_z), 
			  m_pCeramicPortLogicalVolume, "CeramicPort_phys", 
			  m_pDelrinPortLogicalVolume, false, 0);

  G4Colour CeramicPortColor(G4Colour::Red());
  G4VisAttributes *pCeramicPortVisAtt = new G4VisAttributes(CeramicPortColor);
  pCeramicPortVisAtt->SetForceAuxEdgeVisible(true);
  m_pCeramicPortLogicalVolume->SetVisAttributes(pCeramicPortVisAtt);
  
  //-----------------------------Ceramic Neck--------------------------------
  
  //Dimensions
  double CeramicNeck_height = GetGeometryParameter("CeramicNeck_height");
  double CeramicNeck_iD = GetGeometryParameter("CeramicNeck_iD");
  double CeramicNeck_oD = GetGeometryParameter("CeramicNeck_oD");
 
  //Position
  double CeramicNeck_x = GetGeometryParameter("CeramicNeck_x");
  double CeramicNeck_y = GetGeometryParameter("CeramicNeck_y");
  double CeramicNeck_z = GetGeometryParameter("CeramicNeck_z");
  G4double TransformerOil_iD = GetGeometryParameter("PlexiglassTube_oD");

  G4Cons *CeramicNeck =
	new G4Cons("CeramicNeck", TransformerOil_iD/2, CeramicPort_oD/2, 
		   TransformerOil_iD/2, CeramicNeck_oD/2, 
		   CeramicNeck_height/2,
		   opendeg, closedeg);

  G4Cons *CeramicNeckOil =
	new G4Cons("CeramicNeckOil", TransformerOil_iD/2, 
		   CeramicPort_iD/2- tolerance, 
		   TransformerOil_iD/2, 
		   CeramicNeck_iD/2 - tolerance, 
		   CeramicNeck_height/2,
		   opendeg, closedeg);
    
  m_pCeramicNeckLogicalVolume =
	new G4LogicalVolume(CeramicNeck, Al2O3, "CeramicNeck");

  m_pCeramicNeckOilLogicalVolume =
	new G4LogicalVolume(CeramicNeckOil, TransformerOil, "NeckOil");
    
  m_pCeramicNeckPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(CeramicNeck_x,
					   CeramicNeck_y, CeramicNeck_z), 
			  m_pCeramicNeckLogicalVolume, "CeramicNeck_phys", 
			  m_pDelrinBodyLogicalVolume, false, 0);

  m_pCeramicNeckOilPhysicalVolume =
    new G4PVPlacement(0, G4ThreeVector(0, 0, 0), 
			  m_pCeramicNeckOilLogicalVolume, "CeramicNeckOil_phys", 
			  m_pCeramicNeckLogicalVolume, false, 0);

  G4Colour CeramicNeckColor(G4Colour::Red());
  G4VisAttributes *pCeramicNeckVisAtt = new G4VisAttributes(CeramicNeckColor);
  pCeramicNeckVisAtt->SetForceAuxEdgeVisible(true);
  m_pCeramicNeckLogicalVolume->SetVisAttributes(pCeramicNeckVisAtt);
  
  //----------------------------Ceramic Body-----------------------------------

  //Dimensions
  G4double CeramicBody_height = GetGeometryParameter("CeramicBody_height");
  G4double CeramicBody_iD = GetGeometryParameter("CeramicBody_iD");
  G4double CeramicBody_oD = GetGeometryParameter("CeramicBody_oD"); 

  //Position
  G4double CeramicBody_x = GetGeometryParameter("CeramicBody_x");
  G4double CeramicBody_y = GetGeometryParameter("CeramicBody_y");
  G4double CeramicBody_z = GetGeometryParameter("CeramicBody_z");
 
  G4Tubs *CeramicBody =
	new G4Tubs("CeramicBody", TransformerOil_iD/2,
		   CeramicBody_oD/2, CeramicBody_height/2,
		   opendeg, closedeg);
  
 G4Tubs *Oil =
        new G4Tubs("Oil", TransformerOil_iD/2,  CeramicBody_iD/2 - tolerance,
		   CeramicBody_height/2,
		   opendeg, closedeg);
    
  m_pCeramicBodyLogicalVolume =
	new G4LogicalVolume(CeramicBody, Al2O3, "CeramicBody");

  m_pTransformerOilLogicalVolume =
	new G4LogicalVolume(Oil, TransformerOil, "Oil");
        
  m_pCeramicBodyPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(CeramicBody_x,
					   CeramicBody_y, CeramicBody_z), 
			  m_pCeramicBodyLogicalVolume, 
                          "CeramicBody_phys", 
			  m_pDelrinBodyLogicalVolume, false, 0);

   m_pTransformerOilPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(0,
					   0, 0), 
			  m_pTransformerOilLogicalVolume, 
                          "CeramicBodyTransformerOil_phys", 
			  m_pCeramicBodyLogicalVolume, false, 0);

  G4Colour CeramicBodyColor(G4Colour::Red());
  G4VisAttributes *pCeramicBodyVisAtt = new G4VisAttributes(CeramicBodyColor);
  pCeramicBodyVisAtt->SetForceAuxEdgeVisible(true);
  m_pCeramicBodyLogicalVolume->SetVisAttributes(pCeramicBodyVisAtt);
  
  //----------------------------Ceramic Rim-----------------------------------
  
  //Dimensions
  G4double CeramicRim_height = GetGeometryParameter("CeramicRim_height");
  G4double CeramicRim_iD = GetGeometryParameter("CeramicRim_iD");
  G4double CeramicRim_oD = GetGeometryParameter("CeramicRim_oD");

  //Position
  G4double CeramicRim_x = GetGeometryParameter("CeramicRim_x");
  G4double CeramicRim_y = GetGeometryParameter("CeramicRim_y");
  G4double CeramicRim_z	= GetGeometryParameter("CeramicRim_z");
 
  G4Tubs *CeramicRim =
	new G4Tubs("CeramicRim", CeramicRim_iD/2,
		   CeramicRim_oD/2, CeramicRim_height/2,
		   opendeg, closedeg);
    
  m_pCeramicRimLogicalVolume =
    new G4LogicalVolume(CeramicRim, Al2O3, "CeramicRim");
    
  m_pCeramicRimPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(CeramicRim_x,
					   CeramicRim_y, CeramicRim_z), 
			  m_pCeramicRimLogicalVolume, "CeramicRim_phys", 
			  m_pWaterGlycolLogicalVolume, false, 0);

  G4Colour CeramicRimColor(G4Colour::Red());
  G4VisAttributes *pCeramicRimVisAtt = new G4VisAttributes(CeramicRimColor);
  pCeramicRimVisAtt->SetForceAuxEdgeVisible(true);
  m_pCeramicRimLogicalVolume->SetVisAttributes(pCeramicRimVisAtt);

  //These sections lie within the reacion chamber, assumed to be solid.
  //!!!!!!!!!!!!!!!!!!!!!!!!!!!Check with NSD!!!!!!!!!!!!!!!!!!!!!!!!!

  //------------------------Ceramic Small Ring--------------------------------
  
  //Dimensions
  G4double CeramicSmallRing_height = 
           GetGeometryParameter("CeramicSmallRing_height");
  G4double CeramicSmallRing_iD = GetGeometryParameter("CeramicSmallRing_iD");
  G4double CeramicSmallRing_oD = GetGeometryParameter("CeramicSmallRing_oD");

  //Position
  G4double CeramicSmallRing_x 	= GetGeometryParameter("CeramicSmallRing_x");
  G4double CeramicSmallRing_y 	= GetGeometryParameter("CeramicSmallRing_y");
  G4double CeramicSmallRing_z	= GetGeometryParameter("CeramicSmallRing_z");
 
  G4Tubs *CeramicSmallRing =
	new G4Tubs("CeramicSmallRing", CeramicSmallRing_iD/2,
		   CeramicSmallRing_oD/2, CeramicSmallRing_height/2,
		   opendeg, closedeg);
    
  m_pCeramicSmallRingLogicalVolume =
	new G4LogicalVolume(CeramicSmallRing, Al2O3, "CeramicSmallRing");
    
  m_pCeramicSmallRingPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(CeramicSmallRing_x,
					   CeramicSmallRing_y,
					   CeramicSmallRing_z), 
			  m_pCeramicSmallRingLogicalVolume, 
			  "CeramicSmallRing_phys", 
			  m_pDeuteriumLogicalVolume, false, 0);

  G4Colour CeramicSmallRingColor(G4Colour::Red());
  G4VisAttributes *pCeramicSmallRingVisAtt = 
       new G4VisAttributes(CeramicSmallRingColor);
  pCeramicSmallRingVisAtt->SetForceAuxEdgeVisible(true);
  m_pCeramicSmallRingLogicalVolume->SetVisAttributes(pCeramicSmallRingVisAtt);

  //-----------------------------Ceramic Big Ring------------------------------
  
  //Dimensions
  G4double CeramicBigRing_height = 
           GetGeometryParameter("CeramicBigRing_height");
  G4double CeramicBigRing_iD = GetGeometryParameter("CeramicBigRing_iD");
  G4double CeramicBigRing_oD = GetGeometryParameter("CeramicBigRing_oD");

  //Position
  G4double CeramicBigRing_x = GetGeometryParameter("CeramicBigRing_x");
  G4double CeramicBigRing_y = GetGeometryParameter("CeramicBigRing_y");
  G4double CeramicBigRing_z = GetGeometryParameter("CeramicBigRing_z");
 
  G4Tubs *CeramicBigRing =
	new G4Tubs("CeramicBigRing", CeramicBigRing_iD/2,
		   CeramicBigRing_oD/2 - tolerance, CeramicBigRing_height/2,
		   opendeg, closedeg);
    
  m_pCeramicBigRingLogicalVolume =
    new G4LogicalVolume(CeramicBigRing, Al2O3, "CeramicBigRing");
    
  m_pCeramicBigRingPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(CeramicBigRing_x,
					   CeramicBigRing_y, CeramicBigRing_z), 
			  m_pCeramicBigRingLogicalVolume, "CeramicBigRing_phys",   	
			  m_pDeuteriumLogicalVolume, false, 0);

  G4Colour CeramicBigRingColor(G4Colour::Red());
  G4VisAttributes *pCeramicBigRingVisAtt = 
       new G4VisAttributes(CeramicBigRingColor);
  pCeramicBigRingVisAtt->SetForceAuxEdgeVisible(true);
  m_pCeramicBigRingLogicalVolume->SetVisAttributes(pCeramicBigRingVisAtt);

  //--------------------------Ceramic Ring Neck--------------------------------
  
  //Dimensions
  G4double CeramicRingNeck_height = 
           GetGeometryParameter("CeramicRingNeck_height");
  G4double CeramicRingNeck_iD = GetGeometryParameter("CeramicRingNeck_iD");
  G4double CeramicRingNeck_oD = GetGeometryParameter("CeramicRingNeck_oD");
 
  //Position
  G4double CeramicRingNeck_x = GetGeometryParameter("CeramicRingNeck_x");
  G4double CeramicRingNeck_y = GetGeometryParameter("CeramicRingNeck_y");
  G4double CeramicRingNeck_z = GetGeometryParameter("CeramicRingNeck_z");
 
  G4Cons *CeramicRingNeck =
	new G4Cons("CeramicRingNeck", 
		   CeramicRingNeck_iD/2, CeramicRingNeck_oD/2, 
		   CeramicSmallRing_iD/2, CeramicSmallRing_oD/2, 
		   CeramicRingNeck_height/2,
		   opendeg, closedeg); 
   
  m_pCeramicRingNeckLogicalVolume =
    new G4LogicalVolume(CeramicRingNeck, Al2O3, "CeramicRingNeck");
    
  m_pCeramicRingNeckPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(CeramicRingNeck_x,
					   CeramicRingNeck_y,
					   CeramicRingNeck_z), 
			  m_pCeramicRingNeckLogicalVolume, 
			  "CeramicRingNeck_phys", 
			  m_pDeuteriumLogicalVolume, false, 0);

  G4Colour CeramicRingNeckColor(G4Colour::Red());
  G4VisAttributes *pCeramicRingNeckVisAtt = 
       new G4VisAttributes(CeramicRingNeckColor);
  pCeramicRingNeckVisAtt->SetForceAuxEdgeVisible(true);
  m_pCeramicRingNeckLogicalVolume->SetVisAttributes(pCeramicRingNeckVisAtt);

}

//===============================Steel Housing=================================
//The region between the steel and ceramic housings is filled
// with acetyl homoplymer (POM) delrin.
 
void Xenon1tNeutronGenerator::ConstructSteelHousing()
{
  G4double tolerance = GetGeometryParameter("tolerance");
  G4double opendeg  = 0.0 *deg;
  G4double closedeg = 360.0 *deg;
 
  //Materials
  G4Material *NiCrSteel = G4Material::GetMaterial("NiCrSteel");
  G4Material *Delrin = G4Material::GetMaterial("Delrin");

  
  //Dimensions
  G4double SteelBody_height = GetGeometryParameter("SteelBody_height");
  G4double SteelBody_iD = GetGeometryParameter("SteelBody_iD");
  G4double SteelBody_oD = GetGeometryParameter("SteelBody_oD");
  G4double DelrinBody_iD = GetGeometryParameter("PlexiglassTube_oD");

  //Position
  G4double SteelBody_x 	= GetGeometryParameter("SteelBody_x");
  G4double SteelBody_y 	= GetGeometryParameter("SteelBody_y");
  G4double SteelBody_z	= GetGeometryParameter("SteelBody_z");
 
  G4Tubs *SteelBody =
	new G4Tubs("SteelBody", DelrinBody_iD/2,
		   SteelBody_oD/2, SteelBody_height/2,
		   opendeg, closedeg);

  G4Tubs *DelrinBody =
	new G4Tubs("DelrinBody", DelrinBody_iD/2.,
		   SteelBody_iD/2. - tolerance, SteelBody_height/2,
		   opendeg, closedeg);
    
  m_pSteelBodyLogicalVolume =
	new G4LogicalVolume(SteelBody, NiCrSteel, "SteelBody");

  m_pDelrinBodyLogicalVolume =
    new G4LogicalVolume(DelrinBody, Delrin, "DelrinBody");
    
  m_pSteelBodyPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(SteelBody_x,
					   SteelBody_y, SteelBody_z), 
			  m_pSteelBodyLogicalVolume, "SteelBody_phys", 
			  m_pWaterGlycolLogicalVolume, false, 0);

  m_pDelrinBodyPhysicalVolume =
    new G4PVPlacement(0, G4ThreeVector(0,0,0), 
		      m_pDelrinBodyLogicalVolume, "SteelDelrin_phys", 
		      m_pSteelBodyLogicalVolume, false, 0);

  G4Colour SteelBodyColor(G4Colour::Magenta());
  G4VisAttributes *pSteelBodyVisAtt = new G4VisAttributes(SteelBodyColor);
  pSteelBodyVisAtt->SetForceAuxEdgeVisible(true);
  m_pSteelBodyLogicalVolume->SetVisAttributes(pSteelBodyVisAtt);

  //-----------------------------Steel Neck------------------------------------
  
  //Dimensions
  double SteelNeck_height = GetGeometryParameter("SteelNeck_height");
  double SteelNeck_iD = GetGeometryParameter("SteelNeck_iD");
  double SteelNeck_oD = GetGeometryParameter("SteelNeck_oD");

  //Position
  double SteelNeck_x = GetGeometryParameter("SteelNeck_x");
  double SteelNeck_y = GetGeometryParameter("SteelNeck_y");
  double SteelNeck_z = GetGeometryParameter("SteelNeck_z");

  G4Cons *SteelNeck =
	new G4Cons("SteelNeck", SteelNeck_iD/2, SteelNeck_oD/2, 
		   SteelNeck_iD/2, SteelBody_oD/2, 
		   SteelNeck_height/2, opendeg, closedeg);
 
  m_pSteelNeckLogicalVolume =
	new G4LogicalVolume(SteelNeck, NiCrSteel, "SteelNeck");
       
  m_pSteelNeckPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(SteelNeck_x,
					   SteelNeck_y, SteelNeck_z), 
			  m_pSteelNeckLogicalVolume, "SteelNeck_phys", 
			  m_pWaterGlycolLogicalVolume, false, 0);

  G4Colour SteelNeckColor(G4Colour::Magenta());
  G4VisAttributes *pSteelNeckVisAtt = new G4VisAttributes(SteelNeckColor);
  pSteelNeckVisAtt->SetForceAuxEdgeVisible(true);
  m_pSteelNeckLogicalVolume->SetVisAttributes(pSteelNeckVisAtt);

  //------------------------------Steel Port-----------------------------------
  
  //Dimensions
  G4double SteelPort_height = GetGeometryParameter("SteelPort_height");
  G4double SteelPort_iD = GetGeometryParameter("SteelPort_iD");
  G4double SteelPort_oD = GetGeometryParameter("SteelPort_oD");
  G4double DelrinPort_iD = GetGeometryParameter("PlexiglassTube_oD");

  //Position
  G4double SteelPort_x 	= GetGeometryParameter("SteelPort_x");
  G4double SteelPort_y 	= GetGeometryParameter("SteelPort_y");
  G4double SteelPort_z	= GetGeometryParameter("SteelPort_z");
 
  G4Tubs *SteelPort =
	new G4Tubs("SteelPort", SteelPort_iD/2,
		   SteelPort_oD/2, SteelPort_height/2,
		   opendeg, closedeg);

  G4Tubs *DelrinPort =
	new G4Tubs("DelrinPort", DelrinPort_iD/2.,
		   SteelPort_iD/2- tolerance, 
                   (SteelPort_height + SteelNeck_height)/2.,
		   opendeg, closedeg);
    
  m_pSteelPortLogicalVolume =
	new G4LogicalVolume(SteelPort, NiCrSteel, "SteelPort");

  m_pDelrinPortLogicalVolume =
	new G4LogicalVolume(DelrinPort, Delrin, "DelrinPort");
    
  m_pSteelPortPhysicalVolume =
	new G4PVPlacement(0, G4ThreeVector(SteelPort_x,
					   SteelPort_y, SteelPort_z), 
			  m_pSteelPortLogicalVolume, "SteelPort_phys", 
			  m_pWaterGlycolLogicalVolume, false, 0);

  m_pDelrinPortPhysicalVolume =
    new G4PVPlacement(0, G4ThreeVector(SteelPort_x, SteelPort_y, SteelPort_z+0.5*(SteelNeck_height)), 
			  m_pDelrinPortLogicalVolume, "SteelPortDelrin_phys", 
			  m_pWaterGlycolLogicalVolume, false, 0);

  G4Colour SteelPortColor(G4Colour::Magenta());
  G4VisAttributes *pSteelPortVisAtt = new G4VisAttributes(SteelPortColor);
  pSteelPortVisAtt->SetForceAuxEdgeVisible(true);
  m_pSteelPortLogicalVolume->SetVisAttributes(pSteelPortVisAtt);

}

G4double Xenon1tNeutronGenerator::GetGeometryParameter(const char *szParameter)
{
  if (m_hGeometryParameters.find(szParameter) != m_hGeometryParameters.end()){
    return m_hGeometryParameters[szParameter];
  }
  else {
    G4cout<< "Parameter: " << szParameter << " is not defined!!!!!" << G4endl;
    return 0;
  }
}

