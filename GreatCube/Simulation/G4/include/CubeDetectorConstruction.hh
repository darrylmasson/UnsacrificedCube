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
class CubeDetectorMessenger;

#include <G4UnionSolid.hh>

#include <G4UImanager.hh>

#include <G4VUserDetectorConstruction.hh>
#include "CubeSensitiveDetector.hh"

class CubeDetectorConstruction: public G4VUserDetectorConstruction
{
public:
	CubeDetectorConstruction(G4String fname);
	~CubeDetectorConstruction();

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
	void ConstructDetectorArray();
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

	CubeDetectorMessenger *m_pDetectorMessenger;

	// ROOT stuff
	TFile			*_fGeom;
	G4String		detRootFile;
	TDirectory *_detector;

	//Water spacers
	G4LogicalVolume	 *m_pSpacerLogicalVolume;
	G4VPhysicalVolume *m_pSpacerPhysicalVolume;
	G4VPhysicalVolume *m_pSpacer1;
    G4VPhysicalVolume *m_pSpacer2;
    G4VPhysicalVolume *m_pSpacer3;
    G4VPhysicalVolume *m_pSpacer4;
    G4VPhysicalVolume *m_pSpacer5;
    G4VPhysicalVolume *m_pSpacer6;


	//Laboratory
	G4LogicalVolume	 *m_pLabLogicalVolume;
	G4VPhysicalVolume *m_pLabPhysicalVolume;

	//Detectors
	G4LogicalVolume	 *m_pDetectorContainer1LogicalVolume;
	G4VPhysicalVolume *m_pDetectorContainer1PhysicalVolume;

	G4LogicalVolume	 *m_pScintillator1LogicalVolume;
	G4VPhysicalVolume *m_pScintillator1PhysicalVolume;

	CubeSensitiveDetector *pEljenSD1;

	G4LogicalVolume	 *m_pDetectorContainer2LogicalVolume;
	G4VPhysicalVolume *m_pDetectorContainer2PhysicalVolume;

	G4LogicalVolume	 *m_pScintillator2LogicalVolume;
	G4VPhysicalVolume *m_pScintillator2PhysicalVolume;

	G4LogicalVolume	 *m_pDetectorContainer3LogicalVolume;
	G4VPhysicalVolume *m_pDetectorContainer3PhysicalVolume;

	G4LogicalVolume	 *m_pScintillator3LogicalVolume;
	G4VPhysicalVolume *m_pScintillator3PhysicalVolume;

	std::vector<G4VPhysicalVolume*> m_pDetectorArrayPhysicalVolumes;

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
