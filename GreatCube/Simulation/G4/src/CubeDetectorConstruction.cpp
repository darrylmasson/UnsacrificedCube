#include <G4Material.hh>
#include <G4NistManager.hh>
#include <G4Box.hh>


#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>

#include <G4SDManager.hh>
#include <G4ThreeVector.hh>
#include <G4VisAttributes.hh>
#include <G4Colour.hh>
#include <globals.hh>

#include "CubeSensitiveDetector.hpp"
#include "CubeDetectorConstruction.hpp"

map<G4String, G4double> CubeDetectorConstruction::m_hGeometryParameters;

CubeDetectorConstruction::CubeDetectorConstruction() {
}

CubeDetectorConstruction::~CubeDetectorConstruction() {
}

void CubeDetectorConstruction::DefineMaterials() {
    G4NistManager* pNistManager = G4NistManager::Instance();

    //=============================Materials=====================================

    //---------------------------------Air---------------------------------------
    pNistManager->FindOrBuildMaterial("G4_AIR");

    //--------------------------------Water-----------------------------------
    pNistManager->FindOrBuildMaterial("G4_WATER");

    //-------------------------------Plastic scintillator-----------------------
    pNistManager->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
}

void CubeDetectorConstruction::DefineGeometryParameters()
{
    m_hGeometryParameters["tolerance"] = 10. *mm;
    
    //============================Laboratory=====================================

    m_hGeometryParameters["Lab_size"] = 10000. *mm;

    //===============================Panels====================================
    m_hGeometryParameters["Panel_width"] = 300. *mm; 
    m_hGeometryParameters["Panel_length"] = 300. *mm;
    m_hGeometryParameters["Panel_thickness"] = 25. *mm; 

    m_hGeometryParameters["Panel_seperation"] = 300.* mm;
    
    m_hPanel1Pos = G4ThreeVector(0, 0, 0.5*(m_hGeometryParameters["Panel_seperation"] + m_hGeometryParameters["Panel_thickness"]]));
    m_hPanel2Pos = G4ThreeVector(0, 0, -0.5*(m_hGeometryParameters["Panel_seperation"] + m_hGeometryParameters["Panel_thickness"]]));
}

G4VPhysicalVolume* CubeDetectorConstruction::Construct() {
    DefineMaterials();
    DefineGeometryParameters();
    ConstructLab();
    ConstructDetectors();

    return m_pLabPhys;
}

void CubeDetectorConstruction::ConstructLab() {
    G4double tolerance = GetGeometryParameter("tolerance");

    //Materials
    G4Material* Air = G4Material::GetMaterial("G4_AIR");
       
    //==============================Laboratory=================================== 

    //Dimensions
    G4double Lab_size = GetGeometryParameter("Lab_size");

    //Lab
    G4Box* Lab = new G4Box("Lab", Lab_size/2, Lab_size/2, Lab_size/2);
	
    m_pLabLog = new G4LogicalVolume(Lab, Air, "Lab_log");
	
    m_pLabPhys = new G4PVPlacement(0, G4ThreeVector(), m_pLabLog, "Lab_phys", nullptr, false, 0); 

    m_pLabLog->SetVisAttributes(G4VisAttributes::Invisible);
}

void CubeDetectorConstruction::ConstructDetectors() {
    //Materials
    G4Material *Scint = G4Material::GetMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
    G4Material* Water = G4Material::GetMaterial("G4_WATER");

    G4double Panel_length = GetGeometryParameter("Panel_length");
    G4double Panel_width = GetGeometryParameter("Panel_width");
    G4double Panel_thickness = GetGeometryParameter("Panel_thickness");
    G4double Panel_seperation = GetGeometryParameter("Panel_seperation");
    
    G4SDManager *pSDManager = G4SDManager::GetSDMpointer();
    
    //==============================Panel 1===================================

    G4Box *Panel1 = new G4Box("Panel1", Panel_length/2, Panel_width/2, Panel_thickness/2);
	
    m_pPanel1Log = new G4LogicalVolume(Panel1, Scint, "Panel1_log");
    
    m_pCSD1 = new CubeSensitiveDetector("Panel1");
    pSDManager->AddNewDetector(m_pCSD1);
    m_pPanel1Log->SetSensitiveDetector(m_pCSD1);
    
    G4VisAttributes *pPanel1VisAtt = new G4VisAttributes(G4Colour::Green());
    pPanel1VisAtt->SetForceAuxEdgeVisible(true);
    m_pPanel1Log->SetVisAttributes(pPanel1VisAtt);
    
    m_pPanel1Phys = new G4PVPlacement(0, m_hPanel1Pos, m_pPanel1Log, "Panel1_phys", m_pLabLog, false, 0);

    //==============================Panel 2===================================

    G4Box *Panel2 = new G4Box("Panel2", Panel_length/2, Panel_width/2, Panel_thickness/2);
    
    m_pPanel2Log = new G4LogicalVolume(Panel2, Scint, "Panel2_log");
    
    m_pCSD2 = new CubeSensitiveDetector("Panel2");
    pSDManager->AddNewDetector(m_pCSD2);
    m_pPanel2Log->SetSensitiveDetector(m_pCSD2);
    
    G4VisAttributes *pPanel2VisAtt = new G4VisAttributes(G4Colour::Green());
    pPanel2VisAtt->SetForceAuxEdgeVisible(true);
    m_pPanel2Log->SetVisAttributes(pPanel2VisAtt);
    
    m_pPanel2Phys = new G4PVPlacement(0, m_hPanel2Pos, m_pPanel2Log, "Panel2_phys", m_pLabLog, false, 0);

    //==============================Water shield===================================
    
    G4Box* water = new G4Box("water", Panel_length/2, Panel_width/2, Panel_seperation/2);
    
    m_pWaterLog = new G4LogicalVolume(water, Water, "water_log");
    
    G4VisAttributes* pWaterVisAtt = new G4VisAttributes(G4Color::Blue());
    pWaterVisAtt->SetForceAuxEdgeVisible(true);
    m_pWaterLog->SetVisAttributes(pWaterVisAtt);
    
    m_pWaterPhys = new G4PVPlacement(0, G4ThreeVector(0,0,0), m_pWater, "water_phys", m_pLabLog, false, 0);
}

G4double CubeDetectorConstruction::GetGeometryParameter(const char *szParameter) {
    if (m_hGeometryParameters.find(szParameter) != m_hGeometryParameters.end()) {
      return m_hGeometryParameters[szParameter];
    }
    else {
      G4cout<< "Parameter: " << szParameter << " is not defined!!!!!" << G4endl;
      return 0;
    }
}
