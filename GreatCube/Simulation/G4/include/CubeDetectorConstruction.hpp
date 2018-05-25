#ifndef __CUBEDETECTORCONSTRUCTION_H__
#define __CUBEDETECTORCONSTRUCTION_H__

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
#include "CubeSensitiveDetector.hpp"

class CubeDetectorConstruction: public G4VUserDetectorConstruction {
public:
	CubeDetectorConstruction();
	~CubeDetectorConstruction();

	G4VPhysicalVolume* Construct();
	void DefineMaterials();
	void DefineGeometryParameters();
	void ConstructLab();
	void ConstructDetectors();
	G4double GetGeometryParameter(const char *szParameter);
 
private:
	static map<G4String, G4double> m_hGeometryParameters;

	//Water spacers
	G4LogicalVolume* m_pWaterLog;
	G4VPhysicalVolume* m_pWaterPhys;

	//Laboratory
	G4LogicalVolume* m_pLabLog;
	G4VPhysicalVolume* m_pLabPhys;

	//Detectors
	G4LogicalVolume* m_pPanel1Log;
	G4VPhysicalVolume* m_pPanel1Phys;

	CubeSensitiveDetector* m_pCSD1;
    CubeSensitiveDetector* m_pCSD2;

	G4LogicalVolume* m_pPanel2Log;
	G4VPhysicalVolume* m_pPanel2Phys;

	G4ThreeVector m_hPanel1Pos;
	G4ThreeVector m_hPanel2Pos;
};

#endif // __CUBEDETECTORCONSTRUCTION_H__
