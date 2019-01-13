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
#include "G4Orb.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4VisAtributes.hh"
#include "G4Color.hh"
#include "G4SystemOfUnits.hh"

CubeDetectorConstruction::CubeDetectorConstruction() : G4VUserDetectorConstruction() {
    m_pMessenger = std::unique_ptr<CubeDetectorMessenger>(new CubeDetectorMessenger(this));

    m_dPanelEdge = 30*cm;
    m_dPanelThick = 25*mm;
    m_iTileCount = 1;
    m_iPanelCount = 0;

    m_pWorldSolid = nullptr;
    m_pWorldLV = nullptr;
    m_pWorldPV = nullptr;

    m_pWaterSolid = nullptr;
    m_pWaterLV = nullptr;
    m_pWaterPV = nullptr;

    m_pPanelSolid = nullptr;
    m_pWaterLV = nullptr;
}

CubeDetectorConstruction::~CubeDetectorConstruction() {
    m_pMessenger.reset();
    for (int i = 0; i < NUM_DIMS; i++) {
        for (unsigned j = 0; i < m_pWaterPV.size(); j++) {
            delete m_aPanelPVs[i][j];
    }   }
    delete m_pPanelLV;
    delete m_pPanelSolid;

    delete m_pWaterPV;
    delete m_pWaterLV;
    delete m_pWaterSolid;

    delete m_pWorldPV;
    delete m_pWorldLV;
    delete m_pWorldSolid;
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
    if (m_pWorldPV) return m_pWorldPV;
    // get materials
    G4Material* air = G4Material::GetMaterial("G4_AIR");
    G4Material* h2o = G4Material::GetMaterial("G4_WATER");
    G4Material* scint = G4Material::GetMaterial("G4_PLASTIC_SC_VINYLTOLUENE");

    // set geometry parameters
    m_dWorldRadius = m_iTileCount * m_dPanelEdge;
    G4double fudgefactor = 5*mm; // gaps between panels for cables etc

    // World volumes
    m_pWorldSolid = new G4Orb("world", m_dWorldRadius);
    m_pWorldLV = new G4LogicalVolume(SolidWorld, air, "world");
    m_pWorldPV = new G4PVPlacement(0,               // rotation
                                   G4ThreeVector(), // location
                                   m_pWorldLV,      // logical volume
                                   "world",         // name
                                   nullptr,         // mother volume
                                   false,           // boolean operations
                                   0,               // copy number
                                   false);          // check overlap

    G4double water_size = m_iTileCount*m_dPanelEdge + \
                          (m_iTileCount+1)*m_dPanelThick + \
                          2*m_iTileCount*fudgefactor;
    m_dCubeFullEdge = water_size;

    m_pWaterSolid = new G4Box("water", water_size/2, water_size/2, water_size/2);
    m_pWaterLV = new G4LogicalVolume(m_pWaterSolid,  h2o, "water");
    m_pWaterPV = new G4PVPlacement(0,
            G4ThreeVector(),
            m_pWaterLV,
            "water",
            m_pWorldLV,
            false,
            0,
            false);

    // panel volumes
    m_pPanelSolid = new G4Box("panel", m_dPanelEdge/2, m_dPanelEdge/2, m_dPanelThick/2);
    m_pPanelLV = new G4LogicalVolume(panelSolid, scint, "panel");
    G4ThreeVector       pos;
    G4RotationMatrix*   rotator;
    G4double x, y, z;
    for (int axis = _x; axis <= _z; axis++) {
        for (double plane = -m_iTileCount/2.; plane < m_iTileCount/2.+0.1; plane+=1.) {
            for (double row = -(m_iTileCount-1)/2.; row < (m_iTileCount-1)/2.+0.1; row+=1.) {
                for (double col = -(m_iTileCount-1)/2.; col < (m_iTileCount-1)/2.+0.1; col+=1.) {
                    rotator = new G4RotationMatrix();
                    if (axis == _x) {
                        rotator->rotateY(90*deg);
                        x = plane * m_dPanelEdge + 2*plane*fudge_factor + plane*m_dPanelThick;
                        y = row;
                        z = col;
                    } else if (axis == _y) {
                        rotator->rotateX(90*deg);
                        x = row;
                        y = plane * m_dPanelEdge + 2*plane*fudge_factor + plane*m_dPanelThick;
                        z = col;
                    } else {
                        x = row;
                        y = col;
                        z = plane * m_dPanelEdge + 2*plane*fudge_factor + plane*m_dPanelThick;
                    }
                    G4cout << "Generating panel " << copy << G4endl;
                    m_vPanelPVs.push_back(new G4PVPlacement(
                            rotator,
                            G4ThreeVector(x, y, z),
                            panelLV,
                            "panel",
                            m_pWaterLV,
                            false,
                            m_iPanelCount++,
                            false));
                }
            }
        }
    }

    // visualization attributes
    m_pWorldLV->SetVisAttributes(G4VisAttributes::GetInvisible());
    auto PanelVisAtt = new G4VisAttributes(G4Color(0,1,0,0.7));
    PanelVisAtt->SetVisibility(true);
    m_pPanelLV->SetVisAttributes(PanelVisAtt);
    auto WaterVisAtt = new G4VisAttributes(G4Color(0,0,1,0.1));
    WaterVisAtt->SetVisibility(true);
    m_pWaterLV->SetVisAttributes(WaterVisAtt);

    return m_pWorldPV;
}

void CubeDetectorConstruction::ConstructSDandField() {
    auto panelSD = new CubeSensitiveDetector("Panel", "PanelCollection");
    G4SDManager::GetSDMpointer()->AddNewDetector(panelSD);
    m_pPanelLV->SetSensitiveDetector(panelSD);
}

