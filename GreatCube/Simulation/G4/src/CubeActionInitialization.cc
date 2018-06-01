// Great Unsacrificed Cube
// CubeActionInitialization.cc
//
// copyright iNeat 2018
// please not to sacrifice the great cube

#include "CubeActionInitialization.hh"
#include "CubePrimaryGeneratorAction.hh"
#include "CubeRunAction.hh"
#include "CubeEventAction.hh"

CubeActionInitialization::CubeActionInitialization() : G4VUserActionInitialization() {}

CubeActionInitialization::~CubeActionInitialization() {}

void CubeActionInitalization::BuildForMaster() const {
    SetUserAction(new CubeRunAction);
}

void CubeActionInitialization::Build() const {
    SetUserAction(new CubePrimaryGeneratorAction);
    SetUserAction(new CubeRunAction);
    SetUserAction(new CubeEventAction);
}
