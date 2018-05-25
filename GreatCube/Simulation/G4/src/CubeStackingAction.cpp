#include <G4VProcess.hh>
#include <G4StackManager.hh>

#include "CubeAnalysisManager.hpp"

#include "CubeStackingAction.hpp"

CubeStackingAction::CubeStackingAction(CubeAnalysisManager *pAnalysisManager)
{
	m_pAnalysisManager = pAnalysisManager;
}

CubeStackingAction::~CubeStackingAction()
{
}

G4ClassificationOfNewTrack
CubeStackingAction::ClassifyNewTrack(const G4Track *pTrack)
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
CubeStackingAction::NewStage()
{
}

void
CubeStackingAction::PrepareNewEvent()
{ 
}






