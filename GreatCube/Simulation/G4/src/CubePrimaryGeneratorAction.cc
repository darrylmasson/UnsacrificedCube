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

CubePrimaryGeneratorAction::CubePrimaryGeneratorAction() : G4VUserPrimaryGeneratorAction() {
    G4int iNumParticles = 1;
    m_pParticleGun = std::make_unique(new G4ParticleGun(iNumParticles));

    auto particleDef = G4ParticleTable::GetParticleTable()->FindParticle("mu-");
    m_pParticleGun->SetParticleDefinition(partDef);
}

CubePrimaryGeneratorAction::~CubePrimaryGeneratorAction() {
    m_pParticleGun.reset();
}

// this is called at the beginning of an event
void CubePrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {
    G4double dWorldHalfZ = 0.;
    auto WorldLV = G4LogicalVolumeStore::GetInstance()->GetVolume("world");
    G4box* worldBox = nullptr;
    if (WorldLV) worldBox = dynamic_cast<G4Box*>(WorldLV->GetSolid());
    if (worldBox) dWorldHalfZ = worldBox->GetZHalfLength();

    m_pParticleGun->SetParticlePosition(G4ThreeVector(0, 0, dWorldHalfz));
    m_pParticleGun->SetParticleMomentumDirection(G4ThreeVector(0, 0, -1));
    m_pParticleGun->SetParticleEnergy(1.*GeV);

    m_pParticleGun->GeneratePrimaryVertex(event);
}
