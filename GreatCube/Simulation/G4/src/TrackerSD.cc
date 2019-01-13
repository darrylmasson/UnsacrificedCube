#include "TrackerSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"

TrackerSD::TrackerSD(const G4String& name, const G4String& hitColName) : G4VSensitiveDetector(name) {
    G4cout << "TrackSD: ctor\n";
    m_pHitsCollection = nullptr;
    collectionName.insert(hitColName);
}

TrackerSD::~TrackerSD() {}

void TrackerSD::Initialize(G4HCofThisEvent* hce) {
    //G4cout << "TrackSD: init start\n";
    m_pHitsCollection = new TrackerHitsCollection(SensitiveDetectorName, collectionName[0]);

    G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    hce->AddHitsCollection(hcID, m_pHitsCollection);
    //G4cout << "TrackSD: init end\n";
}

G4bool TrackerSD::ProcessHits(G4Step* step, G4TouchableHistory*) {
    //G4cout << "TrackSD: process start\n";
    G4double edep = step->GetTotalEnergyDeposit();

    if (edep == 0.) return false;

    TrackerHit* newHit = new TrackerHit();
    newHit->SetTrackID(step->GetTrack()->GetTrackID());
    newHit->SetEdep(edep);
    newHit->SetPos(step->GetPostStepPoint()->GetPosition());
    m_pHitsCollection->insert(newHit);

    //G4cout << "TrackSD: process end\n";
    return true;
}

void TrackerSD::EndOfEvent(G4HCofThisEvent*) {
    //G4cout << "TrackSD: End\n";
    if (verboseLevel > 1) {
        G4int nHits = m_pHitsCollection->entries();
        G4cout << G4endl << "----->Hits collection: in this event there are " << nHits
            << " hits in the trackers:" << G4endl;
        for (G4int i = 0; i < nHits; i++) (*m_pHitsCollection)[i]->Print();
    }
}
