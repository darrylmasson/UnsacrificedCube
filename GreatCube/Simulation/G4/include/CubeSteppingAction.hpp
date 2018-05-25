#ifndef PurdueSteppingAction_H
#define PurdueSteppingAction_H 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class PurdueAnalysisManager;

class PurdueSteppingAction : public G4UserSteppingAction {
public:
	PurdueSteppingAction(PurdueAnalysisManager* );
	~PurdueSteppingAction(){};

	void UserSteppingAction(const G4Step*);

private:

G4String particle;
PurdueAnalysisManager* myAnalysisManager;


};

#endif
