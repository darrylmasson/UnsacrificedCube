// Great Unsacrificed Cube
// CubeEventAction.cc
//
// copyright iNeat 2018
// please not to sacrifice the great cube

#include "CubeEventAction.hh"
#include "CubePanelSD.hh"
#include "CubeHit.hh"
#include "CubeAnalysisManager.hh"

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4UnitsTable.hh"

#include "Randomize.hh"
#include <iomanip>

CubeEventAction::CubeEventAction() : G4VUserEventAction() {
    m_PanelHCID = -1;
}

CubeEventAction::~CubeEventAction() {}

void CubeEventAction::BeginOfEventAction(const G4Event* event) {}

void CubeEventAction::EndOfEventAction(const G4Event* event) {
    if (m_PanelHCID == -1) m_PanelHCID = GetSDMpointer()->GetCollectionID("PanelHitsCollection");

    auto PanelHC = GetHitsCollection(m_PanelHCID, event);
    auto PanelHit = (*PanelHC)[PanelHC->entries()-1];

    auto iEventID = event->GetEventID();

    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillNtupleDColumn(0, panelHit->GetEdep());
    analysisManager->AddNtupleRow();
}

CubeHitsCollection* CubeEventAction::GetHitsCollection(G4int hcID, const G4event* event) const {
    auto hitsCollection = static_cast<CubeHitsCollection*>(event>GetHCofThisEvent()->GetHC(hcID));
    if (!hitsCollection) {
        G4ExceptionDescription msg;
        msg << "Cannot access hcID " << hcID;
        G4Exception("CubeEventAction::GetHitsCollection", "Code X", FatalException, msg);
    }
    return hitsCollection;
}

