// Great Unsacrificed Cube
// CubePrimaryGeneratorAction.cc
//
// copyright iNeat 2018
// please not to sacrifice the great cube

#include "CubePrimaryGeneratorAction.hh"

#include "G4RunManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include <cmath>

const G4double pi = acos(-1.0);

CubePrimaryGeneratorAction::CubePrimaryGeneratorAction(G4double world, G4double edge) : G4VUserPrimaryGeneratorAction() {
    G4int iNumParticles = 1;
    m_pParticleGun = std::make_unique(new G4ParticleGun(iNumParticles));

    auto particleDef = G4ParticleTable::GetParticleTable()->FindParticle("mu-");
    m_pParticleGun->SetParticleDefinition(partDef);
    m_dWorldSize = world;
    m_dCubeSize = edge;
}

CubePrimaryGeneratorAction::~CubePrimaryGeneratorAction() {
    m_pParticleGun.reset();
}

// this is called at the beginning of an event
void CubePrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {
    G4double dWorldHalfZ = 10.;
    auto WorldLV = G4LogicalVolumeStore::GetInstance()->GetVolume("world");
    G4box* worldBox = nullptr;
    if (WorldLV) worldBox = dynamic_cast<G4Box*>(WorldLV->GetSolid());
    if (worldBox) dWorldHalfZ = worldBox->GetZHalfLength();

    G4double theta = pi*G4UniformRand();
    G4double phi = 2*pi*G4UniformRand();
    G4double x_pri = m_dWorldSize * cos(phi) * sin(theta);
    G4double y_pri = m_dWorldSize * sin(phi) * sin(theta);
    G4double z_pri = m_dWorldSize * cos(theta);
    G4ThreeVector pos_pri = G4ThreeVector(x_pri, y_pri, z_pri);
    m_pParticleGun->SetParticlePosition(pos_pri);

    G4double x_tgt = m_dCubeSize * (G4UniformRand() - 0.5);
    G4double y_tgt = m_dCubeSize * (G4UniformRand() - 0.5);
    G4double z_tgt = m_dCubeSize * (G4UniformRand() - 0.5);
    G4ThreeVector pos_tgt = G4ThreeVector(x_tgt, y_tgt, z_tgt);
    G4ThreeVector direc = pos_tgt - pos_pri;

    m_pParticleGun->SetParticleMomentumDirection(direc/direc.mag());
    m_pParticleGun->SetParticleEnergy(10.*GeV);

    auto AM = G4AnalysisManager::Instance();
    AM->FillNtupleDColumn(0, 0, 10*GeV);
    AM->FillNtupleDColumn(0, 1, x_tgt);
    AM->FillNtupleDColumn(0, 2, y_tgt);
    AM->FillNtupleDColumn(0, 3, z_tgt);
    AM->FillNtupleDColumn(0, 4, direc[0]/direc.mag());
    AM->FillNtupleDColumn(0, 5, direc[1]/direc.mag());
    AM->FillNtupleDColumn(0, 6, direc[2]/direc.mag());
    AM->AddNtupleRow(0);

    m_pParticleGun->GeneratePrimaryVertex(event);
}
