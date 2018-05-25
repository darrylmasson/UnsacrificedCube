#include <G4Event.hh>

#include "CubeEventAction.hpp"

CubeEventAction::CubeEventAction(CubeAnalysisManager *pAnalysisManager) {
    m_pAnalysisManager = pAnalysisManager;
}

CubeEventAction::~CubeEventAction() {
      m_pAnalysisManager = nullptr;
}

void
CubeEventAction::BeginOfEventAction(const G4Event *pEvent) {
    if(pEvent->GetEventID() % 1000 == 0) {
        G4cout << "------ Begin event " << pEvent->GetEventID()<< "------" << G4endl;
    }
    
    if(m_pAnalysisManager)
        m_pAnalysisManager->BeginOfEvent(pEvent);
}

void CubeEventAction::EndOfEventAction(const G4Event *pEvent) {
    //G4cout <<"pEvent at End " << pEvent ->GetEventID()<< G4endl;
    if(m_pAnalysisManager)
        m_pAnalysisManager->EndOfEvent(pEvent);
}
