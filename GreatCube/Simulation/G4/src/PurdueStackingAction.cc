#include <G4VProcess.hh>
#include <G4StackManager.hh>

#include "PurdueAnalysisManager.hh"

#include "PurdueStackingAction.hh"

PurdueStackingAction::PurdueStackingAction(PurdueAnalysisManager *pAnalysisManager)
{
	m_pAnalysisManager = pAnalysisManager;
}

PurdueStackingAction::~PurdueStackingAction()
{
}

G4ClassificationOfNewTrack
PurdueStackingAction::ClassifyNewTrack(const G4Track *pTrack)
{
	G4ClassificationOfNewTrack hTrackClassification = fUrgent;

	if(pTrack->GetDefinition()->GetParticleType() == "nucleus" && !pTrack->GetDefinition()->GetPDGStable())
	{
		if(pTrack->GetParentID() > 0 && pTrack->GetCreatorProcess()->GetProcessName() == "RadioactiveDecay")
			hTrackClassification = fPostpone;
	}

	return hTrackClassification;
}

void
PurdueStackingAction::NewStage()
{
}

void
PurdueStackingAction::PrepareNewEvent()
{ 
}






