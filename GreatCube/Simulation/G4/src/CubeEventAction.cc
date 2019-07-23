// Great Unsacrificed Cube
// CubeEventAction.cc
//
// copyright iNeat 2018
// please not to sacrifice the great cube

#include "CubeEventAction.hh"
#include "CubeAnalysis.hh"

#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"

CubeEventAction::CubeEventAction(G4int NumPanels) : G4UserEventAction() {
    m_PanelHCID = -1;
    m_vEdep.assign(NumPanels, 0);
}

CubeEventAction::~CubeEventAction() {}

void CubeEventAction::BeginOfEventAction(const G4Event* event) {
    m_vEdep.assign(m_vEdep.size(), 0);
}

void CubeEventAction::EndOfEventAction(const G4Event* event) {
    if (m_PanelHCID == -1) m_PanelHCID = G4SDManager::GetSDMpointer()->GetCollectionID("PanelHitsCollection");

    auto HitColl = GetHitsCollection(m_PanelHCID, event);
    CubeHit* PanelHit = (CubeHit*)(*HitColl)[HitColl->entries()-1];

    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillNtupleDColumn(0, PanelHit->GetEdep());
    analysisManager->AddNtupleRow();
}

CubeHitsCollection* CubeEventAction::GetHitsCollection(G4int hcID, const G4Event* event) const {
    auto hitsCollection = static_cast<CubeHitsCollection*>(event->GetHCofThisEvent()->GetHC(hcID));
    if (!hitsCollection) {
        G4ExceptionDescription msg;
        msg << "Cannot access hcID " << hcID;
        G4Exception("CubeEventAction::GetHitsCollection", "Code X", FatalException, msg);
    }
    return hitsCollection;
}

