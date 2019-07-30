// Great Unsacrificed Cube
// CubeRunAction.hh
//
// Copyright iNeat 2018
// please not to sacrifice the great cube

#ifndef _CUBE_RUN_ACTION_H_
#define _CUBE_RUN_ACTION_H_ 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include <memory>

class G4Run;

class CubeRunAction : public G4UserRunAction {
    public:
        CubeRunAction();
        virtual ~CubeRunAction();

        virtual void BeginOfRunAction(const G4Run*);
        virtual void EndOfRunAction(const G4Run*);

    private:
        G4int m_iNumPanels;
        G4String m_sFilename;
};

#endif // _CUBE_RUN_ACTION_H_
