// Great Unsacrificed Cube
// CubeActionInitialization.hh
//
// Copyright iNeat 2018
// please not to sacrifice the great cube

#ifndef _CUBE_ACTION_INIT_H_
#define _CUBE_ACTION_INIT_H_ 1

#include "G4VUserActionInitialization.hh"

class CubeActionInitialization : public G4VUserActionInitialization {
    public:
        CubeActionInitialization();
        virtual ~CubeActionInitialization();

        virtual void BuildForMaster() const;
        virtual void Build() const;

#endif // _CUBE_ACTION_INIT_H_
