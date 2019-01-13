// Great Unsacrificed Cube
// CubeRunAction.hh
//
// Copyright iNeat 2018
// please not to sacrifice the great cube

#ifndef _CUBE_RUN_ACTION_H_
#define _CUBE_RUN_ACTION_H_ 1

#include "G4VUserRunAction.hh"
#include "globals.hh"
#include <memory>
#include "CubeAnalysis.hh"

class G4Run;

class CubeRunAction : public G4VUserRunAction {
    public:
        CubeRunAction(G4int);
        virtual ~CubeRunAction();

        virtual void BeginOfRunAction(const G4Run*);
        virtual void EndOfRunAction(const G4Run*);

    private:
        std::unique_ptr<G4AnalysisManager> m_AnalysisManager;
        G4int m_iNumPanels;
};

#endif // _CUBE_RUN_ACTION_H_
