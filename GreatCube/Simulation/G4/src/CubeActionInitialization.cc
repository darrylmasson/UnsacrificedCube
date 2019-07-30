// Great Unsacrificed Cube
// CubeActionInitialization.cc
//
// copyright iNeat 2018
// please not to sacrifice the great cube

#include "CubeActionInitialization.hh"
#include "CubeDetectorConstruction.hh"
#include "CubePrimaryGeneratorAction.hh"
#include "CubeRunAction.hh"
#include "CubeEventAction.hh"

CubeActionInitialization::CubeActionInitialization(CubeDetectorConstruction* detcon) : G4VUserActionInitialization() {
    m_pDetCon = detcon;
}

CubeActionInitialization::~CubeActionInitialization() {
    m_pDetCon = nullptr;
}

void CubeActionInitialization::BuildForMaster() const {
    SetUserAction(new CubeRunAction());
}

void CubeActionInitialization::Build() const {
    SetUserAction(new CubePrimaryGeneratorAction(m_pDetCon->GetWorldSize()));
    SetUserAction(new CubeRunAction());
    SetUserAction(new CubeEventAction(m_pDetCon->GetPanelCount()));
}
