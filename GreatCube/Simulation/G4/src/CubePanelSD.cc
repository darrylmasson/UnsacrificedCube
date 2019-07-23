// Great Unsacrificed Cube
// CubePanelSD.cc
//
// copyright iNeat 2018
// please not to sacrifice the great cube

#include "CubePanelSD.hh"

#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"

CubePanelSD::CubePanelSD(const G4String& name, const G4String& hitsCollectionName) : G4VSensitiveDetector(name) {
    m_pHitCollection = nullptr;
    collectionName.insert(hitsCollectionName);
}

CubePanelSD::~CubePanelSD() {}

void CubePanelSD::Initialize(G4HCofThisEvent* hce) {
    m_pHitCollection = new CubeHitsCollection(SensitiveDetectorName, collectionName[0]);
    auto hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    hce->AddHitsCollection(hcID, m_pHitCollection);
}

G4bool CubePanelSD::ProcessHits(G4Step* step, G4TouchableHistory*) {
    // energy deposit
    auto edep = step->GetTotalEnergyDeposit();

    if (edep == 0.) return false;

    CubeHit* hit = new CubeHit();
    auto prestep = step->GetPreStepPoint();
    auto poststep = step->GetPostStepPoint();
    hit->SetPanelNb(prestep->GetTouchableHandle()->GetCopyNumber());
    hit->SetEdep(edep);
    hit->SetPos(0.5*(prestep->GetPosition() + poststep->GetPosition()));

    m_pHitCollection->insert(hit);

    return true;
}

void CubePanelSD::EndOfEvent(G4HCofThisEvent*) {
    if (verboseLevel > 1) {
        auto NumHits = m_pHitCollection->entries();
        G4cout << "Hit collection: this event has " << NumHits << "hits: " << G4endl;
        for (G4int i = 0; i < NumHits; i++) (*m_pHitCollection)[i]->Print();
    }
}
