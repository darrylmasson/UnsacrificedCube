#ifndef __PURDUERUNACTION_H__
#define __PURDUERUNACTION_H__

#include <G4UserRunAction.hh>
//#include "PurdueRunActionMessenger.hh"

class G4Run;

class PurdueAnalysisManager;


class PurdueRunAction: public G4UserRunAction
{
public:
	PurdueRunAction(PurdueAnalysisManager *pAnalysisManager=0);
	~PurdueRunAction();

public:
	void BeginOfRunAction(const G4Run *pRun);
	void EndOfRunAction(const G4Run *pRun);
				
	//void SetRanSeed(G4int hRanSeed) { m_hRanSeed = hRanSeed; }

private:
	G4int m_hRanSeed;
	PurdueAnalysisManager *m_pAnalysisManager;
	//PurdueRunActionMessenger *m_pMessenger;
};

#endif // __XENON10PRUNACTION_H__
