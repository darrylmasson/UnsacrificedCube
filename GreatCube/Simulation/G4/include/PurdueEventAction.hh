#ifndef __PURDUEEVENTACTION_H__
#define __PURDUEVENTACTION_H__

#include <G4UserEventAction.hh>

#include "PurdueAnalysisManager.hh"

class G4Event;

class PurdueEventAction : public G4UserEventAction
{
public:
	PurdueEventAction(PurdueAnalysisManager *pAnalysisManager = 0);
	~PurdueEventAction();

public:
	void BeginOfEventAction(const G4Event *pEvent);
	void EndOfEventAction(const G4Event *pEvent);

private:
	PurdueAnalysisManager *m_pAnalysisManager;
};

#endif 

