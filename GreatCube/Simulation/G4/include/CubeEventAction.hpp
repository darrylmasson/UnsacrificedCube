#ifndef __CUBEEVENTACTION_H__
#define __CUBEEVENTACTION_H__

#include <G4UserEventAction.hh>

#include "CubeAnalysisManager.hh"

class G4Event;

class CubeEventAction : public G4UserEventAction {
public:
	CubeEventAction(CubeAnalysisManager *pAnalysisManager = 0);
	~CubeEventAction();

public:
	void BeginOfEventAction(const G4Event *pEvent);
	void EndOfEventAction(const G4Event *pEvent);

private:
	CubeAnalysisManager *m_pAnalysisManager;
};

#endif 

