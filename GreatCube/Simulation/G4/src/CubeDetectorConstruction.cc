// Great Unsacrificed Cube
// CubeDetectorConstruction.cc
//
// copyright iNeat 2018
// please not to sacrifice the great cube

#include "CubeDetectorConstruction.hh"

#include "CubeDetectorMessenger.hh"
#include "CubePanelSD.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4SDManager.hh"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4VisAtributes.hh"
#include "G4Color.hh"
#include "G4SystemOfUnits.hh"

CubeDetectorConstruction::CubeDetectorConstruction() : G4VUserDetectorConstruction() {
    m_pMessenger = std::make_unique(new CubeDetectorMessenger(this));
    m_bCheckOverlap = true;
}

CubeDetectorConstruction::~CubeDetectorConstruction() {
    m_pMessenger.reset();
}

G4VPhysicalVolume* CubeDetectorConstruction::Construct() {
    DefineMaterials();

    return DefineVolumes();
}

void CubeDetectorConstruction::DefineMaterials() {
    G4NistManager* nistMan = G4NistManager::Instance();

    nistMan->FindOrBuildMaterial("G4_AIR");
    nistMan->FindOrBuildMaterial("G4_WATER");
    nistMan->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");

    G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

G4PhysicalVolume* CubeDetectorConstruction::DefineVolumes() {
    // get materials
    G4Material* air = G4Material::GetMaterial("G4_AIR");
    G4Material* h2o = G4Material::GetMaterial("G4_WATER");
    G4Material* scint = G4Material::GetMaterial("G4_PLASTIC_SC_VINYLTOLUENE");

    // set geometry parameters
    G4double dWorldSize = 10.*m;
    G4double dPanelWidth = 30.*cm;
    G4double dPanelLength = 30.*cm;
    G4double dPanelThickness = 25.*mm;
    G4double dPanelSeparation = 30.*cm; // center to center

    // World volumes
    auto SolidWorld = new G4Box("world", dWorldSize/2., dWorldSize/2., dWorldSize/2.);
    auto LogicWorld = new G4LogicalVolume(SolidWorld, air, "world");
    auto PhysWorld = new G4PVPlacement(0,               // rotation
                                       G4ThreeVector(), // location
                                       LogicWorld,      // logical volume
                                       "world",         // name
                                       nullptr,         // mother volume
                                       false,           // boolean operations
                                       0,               // copy number
                                       m_bCheckOverlap);// check overlap

    // panel volumes
    auto SolidPanel1 = new G4Box("panel1", dPanelWidth/2., dPanelLength/2., dPanelThickness/2.);
    auto LogicPanel1 = new G4LogicalVolume(SolidPanel1, scint, "panel1");
    auto PhysPanel1 = new G4PVPlacement(0,
                                        G4ThreeVector(0, 0, dPanelSeparation/2. + dPanelThickness/2.),
                                        LogicPanel1,
                                        "panel1",
                                        PhysWorld,
                                        false,
                                        0,
                                        m_bCheckOverlap);

    auto SolidPanel2 = new G4Box("panel2", dPanelWidth/2., dPanelLength/2., dPanelThickness/2.);
    auto LogicPanel2 = new G4LogicalVolume(SolidPanel2, scint, "panel2");
    auto PhysPanel2 = new G4PVPlacement(0,
                                        G4ThreeVector(0, 0, -dPanelSeparation/2. - dPanelThickness/2.),
                                        LogicPanel2,
                                        "panel2",
                                        PhysWorld,
                                        false,
                                        0,
                                        m_bCheckOverlap);

    // water buffer
    auto SolidWater = new G4Box("water", dPanelWidth/2., dPanelLength/2., dPanelSeparation - dPanelThickness);
    auto LogicWater = new G4LogicalVolume(solidWater, h2o, "water");
    auto PhysWater = new G4PVPlacement(0,
                                       G4ThreeVector(0, 0, 0);
                                       LogicWater,
                                       "water",
                                       PhysWorld,
                                       false,
                                       0,
                                       m_bCheckOverlap);

    // visualization attributes
    LogicWorld->SetVisAttributes(G4VisAttributes::GetInvisible());
    auto PanelVisAtt = new G4VisAttributes(G4Color(0,1,0));
    PanelVisAtt->SetVisibility(true);
    LogicPanel1->SetVisAttributes(PanelVisAtt);
    LogicPanel2->SetVisAttributes(PanelVisAtt);
    auto WaterVisAtt = new G4VisAttributes(G4Color(0,0,1));
    WaterVisAtt->SetVisibility(true);
    LogicWater->SetVisAttributes(WaterVisAtt);

    return PhysWorld;
}

void CubeDetectorConstruction::ConstructSDandField() {
    auto panelSD = new CubeSensitiveDetector("Panel", "PanelCollection");
    G4SDManager::GetSDMpointer()->AddNewDetector(panelSD);
    SetSensitiveDetector("Panel", panelSD);
}

