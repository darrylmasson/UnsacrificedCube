#include <G4Event.hh>

#include "PurdueEventAction.hh"

PurdueEventAction::PurdueEventAction(PurdueAnalysisManager *pAnalysisManager)
{
  m_pAnalysisManager = pAnalysisManager;
}

PurdueEventAction::~PurdueEventAction()
{
}

void
PurdueEventAction::BeginOfEventAction(const G4Event *pEvent)
{
  if(pEvent->GetEventID() % 1000 == 0)
    {
      G4cout << "------ Begin event " << pEvent->GetEventID()<< "------" << G4endl;
    }
  
  if(m_pAnalysisManager)
    m_pAnalysisManager->BeginOfEvent(pEvent);
}

void PurdueEventAction::EndOfEventAction(const G4Event *pEvent)
{
  //G4cout <<"pEvent at End " << pEvent ->GetEventID()<< G4endl;
    if(m_pAnalysisManager)
    m_pAnalysisManager->EndOfEvent(pEvent);
}

