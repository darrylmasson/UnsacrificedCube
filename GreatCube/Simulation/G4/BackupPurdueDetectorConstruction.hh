#ifndef __PURDUEDETECTORCONSTRUCTION_H__
#define __PURDUEDETECTORCONSTRUCTION_H__

#include <globals.hh>

#include <vector>
#include <map>
#include "TFile.h"
#include "TDirectory.h"

using std::vector;
using std::map;

class G4Sphere;
class G4Colour;
class G4LogicalVolume;
class G4VPhysicalVolume;
class PurdueDetectorMessenger;

#include <G4UnionSolid.hh>

#include <G4UImanager.hh>

#include "Xenon1tNeutronGenerator.hh"
#include <G4VUserDetectorConstruction.hh>
#include "PurdueEljenSensitiveDetector.hh"

class PurdueDetectorConstruction: public G4VUserDetectorConstruction
{
public:
  PurdueDetectorConstruction(G4String fname);
  ~PurdueDetectorConstruction();

  G4VPhysicalVolume* Construct();
  G4VPhysicalVolume* LeadBrick(G4ThreeVector BrickPos, G4RotationMatrix* BrickRot);
  void DefineMaterials();
  void DefineGeometryParameters();
  void ConstructNeutronGenerator();
  void ConstructLab();
  void ConstructFrame();
  void ConstructSleeves();
  void ConstructCastle();
  void ConstructDetectors(); 
  void ConstructBrickShield();
  G4double GetGeometryParameter(const char *szParameter);

  //For communication with the messenger
  void SetDetectorSeperation(G4double dSeperation){pSeperation = dSeperation;};
  void SetDetectorAngle(G4double dAngle){pAngle = dAngle;}; 
  void SetFirstDetector(G4double dFirstDetector){pFirstDetector = dFirstDetector;}; 
  void SetLeadSleeves(G4bool dLeadSleeves){pLeadSleeves = dLeadSleeves;};
  void SetMeasurement(G4String dMeasurement){pMeasurement = dMeasurement; G4cout<<"MEASUREMENT TYPE SET TO "<<pMeasurement<<G4endl;}; 
  void ThirdDetectorCoord(G4ThreeVector hThirdDetector){m_hThirdDetector = hThirdDetector;};
  void SecondDetectorCoord(G4ThreeVector hSecondDetector){m_hSecondDetector = hSecondDetector;};
  void FirstDetectorCoord(G4ThreeVector hFirstDetector){m_hFirstDetector = hFirstDetector;};
  
 
private:
  static map<G4String, G4double> m_hGeometryParameters;

  PurdueDetectorMessenger *m_pDetectorMessenger;

  // ROOT stuff
  TFile      *_fGeom;
  G4String    detRootFile;
  TDirectory *_detector;

  //Neutron Generator
  Xenon1tNeutronGenerator * m_pNeutronGenerator;

  //Lead Bricks
  G4LogicalVolume   *m_pBrickLogicalVolume;
  G4VPhysicalVolume *m_pBrickPhysicalVolume;  
  G4VPhysicalVolume *m_pLeadBrick1;
G4VPhysicalVolume *m_pLeadBrick2;
G4VPhysicalVolume *m_pLeadBrick3;
G4VPhysicalVolume *m_pLeadBrick4;
G4VPhysicalVolume *m_pLeadBrick5;
G4VPhysicalVolume *m_pLeadBrick6;

 
  //Laboratory
  G4LogicalVolume   *m_pLabLogicalVolume;
  G4VPhysicalVolume *m_pLabPhysicalVolume;

  //Walls
  G4LogicalVolume   *m_pFrontWallLogicalVolume;
  G4VPhysicalVolume *m_pFrontWallPhysicalVolume;

  G4LogicalVolume   *m_pBackWallLogicalVolume;
  G4VPhysicalVolume *m_pBackWallPhysicalVolume;

  G4LogicalVolume   *m_pLeftWallLogicalVolume;
  G4VPhysicalVolume *m_pLeftWallPhysicalVolume;

  G4LogicalVolume   *m_pRightWallLogicalVolume;
  G4VPhysicalVolume *m_pRightWallPhysicalVolume;

  G4LogicalVolume   *m_pFloorLogicalVolume;
  G4VPhysicalVolume *m_pFloorPhysicalVolume;

  G4LogicalVolume   *m_pCeilingLogicalVolume;
  G4VPhysicalVolume *m_pCeilingPhysicalVolume;

  //Detectors
  G4LogicalVolume   *m_pDetectorContainer1LogicalVolume;
  G4VPhysicalVolume *m_pDetectorContainer1PhysicalVolume;

  G4LogicalVolume   *m_pScintillator1LogicalVolume;
  G4VPhysicalVolume *m_pScintillator1PhysicalVolume;

  PurdueEljenSensitiveDetector *pEljenSD1;

  G4LogicalVolume   *m_pDetectorContainer2LogicalVolume;
  G4VPhysicalVolume *m_pDetectorContainer2PhysicalVolume;

  G4LogicalVolume   *m_pScintillator2LogicalVolume;
  G4VPhysicalVolume *m_pScintillator2PhysicalVolume;

  G4LogicalVolume   *m_pDetectorContainer3LogicalVolume;
  G4VPhysicalVolume *m_pDetectorContainer3PhysicalVolume;

  G4LogicalVolume   *m_pScintillator3LogicalVolume;
  G4VPhysicalVolume *m_pScintillator3PhysicalVolume;

  //Frame
  G4LogicalVolume   *m_pFrameLegLogicalVolume;
  std::vector<G4VPhysicalVolume*> m_pFrameLegPhysicalVolumes;

  G4LogicalVolume   *m_pFrameStrutLogicalVolume;
  std::vector<G4VPhysicalVolume*> m_pFrameStrutPhysicalVolumes;

  G4LogicalVolume   *m_pUpperPlateLogicalVolume;
  G4VPhysicalVolume *m_pUpperPlatePhysicalVolume;

  G4LogicalVolume   *m_pLowerPlateLogicalVolume;
  G4VPhysicalVolume *m_pLowerPlatePhysicalVolume;

  //Sleeves
  G4LogicalVolume   *m_pSleevesLogicalVolume;
  G4VPhysicalVolume *m_pSleevesPhysicalVolume;


  //Messenger Parameters
  G4double pSeperation; 
  G4double pAngle;
  G4double pFirstDetector;
  G4bool pLeadSleeves;
  G4String pMeasurement;
  G4ThreeVector m_hThirdDetector;
  G4ThreeVector m_hSecondDetector;  
  G4ThreeVector m_hFirstDetector;  
};

#endif
