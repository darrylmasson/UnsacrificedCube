#ifndef __PURDUESTACKINGACTION_H__
#define __PURDUESTACKINGACTION_H__

#include <globals.hh>
#include <G4UserStackingAction.hh>

class PurdueAnalysisManager;

class PurdueStackingAction: public G4UserStackingAction
{
public:
	PurdueStackingAction(PurdueAnalysisManager *pAnalysisManager=0);
	~PurdueStackingAction();
  
	virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track* aTrack);
	virtual void NewStage();
	virtual void PrepareNewEvent();

private:
	PurdueAnalysisManager *m_pAnalysisManager;
};

#endif 

