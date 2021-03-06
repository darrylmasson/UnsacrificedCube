// Great Unsacrificed Cube
// CubeDetectorConstruction.cc
//
// copyright iNeat 2018
// please not to sacrifice the great cube

#include "CubeDetectorConstruction.hh"

#include "CubeDetectorMessenger.hh"
#include "CubePanelSD.hh"
#include "CubeAnalysis.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4SDManager.hh"

#include "G4Box.hh"
#include "G4Orb.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4VisAttributes.hh"
#include "G4Color.hh"
#include "G4SystemOfUnits.hh"

CubeDetectorConstruction::CubeDetectorConstruction(G4String fn) : G4VUserDetectorConstruction() {
    m_pMessenger = std::unique_ptr<CubeDetectorMessenger>(new CubeDetectorMessenger(this));

    m_dPanelEdge = 30*cm;
    m_dPanelThick = 25*mm;
    m_iTileCount = 2;
    m_iPanelCount = 0;

    m_pWorldSolid = nullptr;
    m_pWorldLV = nullptr;
    m_pWorldPV = nullptr;

    m_pWaterSolid = nullptr;
    m_pWaterLV = nullptr;
    m_pWaterPV = nullptr;

    m_sFilename = fn;
}

CubeDetectorConstruction::~CubeDetectorConstruction() {
    m_pMessenger.reset();
    delete m_pPanelVis;
    for (unsigned i = 0; i < m_vPanelSolids.size(); i++) {
        delete m_vPanelPVs[i];
        delete m_vPanelLVs[i];
        delete m_vPanelSolids[i];
    }
    m_vPanelPVs.clear();
    m_vPanelLVs.clear();
    m_vPanelSolids.clear();

    delete m_pWaterVis;
    delete m_pWaterPV;
    delete m_pWaterLV;
    delete m_pWaterSolid;

    delete m_pWorldPV;
    delete m_pWorldLV;
    delete m_pWorldSolid;
}

G4VPhysicalVolume* CubeDetectorConstruction::Construct() {
    DefineMaterials();
    BuildAnalysisManager();

    return DefineVolumes();
}

void CubeDetectorConstruction::BuildAnalysisManager() {
    auto AM = G4AnalysisManager::Instance();
    AM->OpenFile(m_sFilename);

    AM->CreateNtuple("truth", "MC truth");
    AM->CreateNtupleDColumn("energy");
    AM->CreateNtupleDColumn("target_x");
    AM->CreateNtupleDColumn("target_y");
    AM->CreateNtupleDColumn("target_z");
    AM->CreateNtupleDColumn("px");
    AM->CreateNtupleDColumn("py");
    AM->CreateNtupleDColumn("pz");
    AM->FinishNtuple();

    char name[20];
    G4int num_panels = GetPanelCount();
    AM->CreateNtuple("edep", "Panel Edep");
    for (int i = 0; i < num_panels; i++) {
        sprintf(name, "panel_%03i", i);
        AM->CreateNtupleDColumn(name);
    }
    AM->FinishNtuple();

    AM->CreateNtuple("detcon", "Construction params");
    AM->CreateNtupleIColumn("axis");
    AM->CreateNtupleDColumn("x");
    AM->CreateNtupleDColumn("y");
    AM->CreateNtupleDColumn("z");
    AM->FinishNtuple();
}

void CubeDetectorConstruction::DefineMaterials() {
    G4NistManager* nistMan = G4NistManager::Instance();

    nistMan->FindOrBuildMaterial("G4_AIR");
    nistMan->FindOrBuildMaterial("G4_WATER");
    nistMan->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");

    G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

G4VPhysicalVolume* CubeDetectorConstruction::DefineVolumes() {
    if (m_pWorldPV) return m_pWorldPV;
    // get materials
    G4Material* air = G4Material::GetMaterial("G4_AIR");
    G4Material* h2o = G4Material::GetMaterial("G4_WATER");
    G4Material* scint = G4Material::GetMaterial("G4_PLASTIC_SC_VINYLTOLUENE");

    // set geometry parameters
    m_dWorldRadius = m_iTileCount * m_dPanelEdge;
    G4double fudgefactor = 15*mm; // gaps between panels for cables etc

    // World volumes
    m_pWorldSolid = new G4Orb("world", m_dWorldRadius);
    m_pWorldLV = new G4LogicalVolume(m_pWorldSolid, air, "world");
    m_pWorldPV = new G4PVPlacement(0,               // rotation
                                   G4ThreeVector(), // location
                                   m_pWorldLV,      // logical volume
                                   "world",         // name
                                   nullptr,         // mother volume
                                   false,           // boolean operations
                                   0,               // copy number
                                   false);          // check overlap
    m_pWorldLV->SetVisAttributes(G4VisAttributes::GetInvisible());

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
    m_pWaterVis = new G4VisAttributes(G4Color(0,0,1,0.1));
    m_pWaterVis->SetVisibility(true);
    m_pWaterLV->SetVisAttributes(m_pWaterVis);

    // panel volumes
    G4ThreeVector       pos;
    G4RotationMatrix*   rotator;
    G4double x, y, z;
    m_pPanelVis = new G4VisAttributes(G4Color(0,1,0,0.7));
    m_pPanelVis->SetVisibility(true);
    //G4cout << "Constructing with " << m_iTileCount << " tiling\n";
    auto AM = G4AnalysisManager::Instance();
    for (int axis = _x; axis <= _z; axis++) {
        //G4cout << "Constructing axis " << axis << '\n';
        for (double plane = -m_iTileCount/2.; plane < m_iTileCount/2.+0.1; plane+=1.) {
            //G4cout << "Plane " << plane << '\n';
            for (double row = -(m_iTileCount-1)/2.; row < (m_iTileCount-1)/2.+0.1; row+=1.) {
                //G4cout << "Row " << row << '\n';
                for (double col = -(m_iTileCount-1)/2.; col < (m_iTileCount-1)/2.+0.1; col+=1.) {
                    //G4cout << "Column " << col << '\n';
                    rotator = new G4RotationMatrix();
                    if (axis == _x) {
                        rotator->rotateY(90*deg);
                        x = plane * m_dPanelEdge + 2*plane*fudgefactor + plane*m_dPanelThick;
                        y = row * m_dPanelEdge + 2*row*fudgefactor;
                        z = col * m_dPanelEdge + 2*col*fudgefactor;
                    } else if (axis == _y) {
                        rotator->rotateX(90*deg);
                        x = row * m_dPanelEdge + 2*row*fudgefactor;
                        y = plane * m_dPanelEdge + 2*plane*fudgefactor + plane*m_dPanelThick;
                        z = col * m_dPanelEdge + 2*col*fudgefactor;
                    } else {
                        x = row * m_dPanelEdge + 2*row*fudgefactor;
                        y = col * m_dPanelEdge + 2*col*fudgefactor;
                        z = plane * m_dPanelEdge + 2*plane*fudgefactor + plane*m_dPanelThick;
                    }
                    //G4cout << "Coords " << x << ' ' << y << ' ' << z << '\n';
                    m_vPanelSolids.push_back(new G4Box("panel", m_dPanelEdge/2, m_dPanelEdge/2, m_dPanelThick/2));
                    m_vPanelLVs.push_back(new G4LogicalVolume(m_vPanelSolids.back(), scint, "panel"));
                    m_vPanelLVs.back()->SetVisAttributes(m_pPanelVis);
                    //G4cout << "Generating panel " << m_iPanelCount << G4endl;
                    AM->FillNtupleIColumn(2, 0, axis);
                    AM->FillNtupleDColumn(2, 1, x);
                    AM->FillNtupleDColumn(2, 2, y);
                    AM->FillNtupleDColumn(2, 3, z);
                    AM->AddNtupleRow(2);
                    m_vPanelPVs.push_back(new G4PVPlacement(
                            rotator,
                            G4ThreeVector(x, y, z),
                            m_vPanelLVs.back(),
                            "panel",
                            m_pWaterLV,
                            false,
                            m_iPanelCount++,
                            false));

                }
            }
        }
    }

    return m_pWorldPV;
}

void CubeDetectorConstruction::ConstructSDandField() {
    auto panelSD = new CubePanelSD("Panel", "PanelHitsCollection");
    G4SDManager::GetSDMpointer()->AddNewDetector(panelSD);
    for (auto& panel : m_vPanelLVs) panel->SetSensitiveDetector(panelSD);
}

G4int CubeDetectorConstruction::GetPanelCount() {
    return m_iTileCount*m_iTileCount*(m_iTileCount+1)*NUM_AXES;
}
