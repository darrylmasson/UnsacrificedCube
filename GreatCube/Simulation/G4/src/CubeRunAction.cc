// Great Unsacrificed Cube
// CubeRunAction.cc
//
// copyright ineat 2018
// please not to sacrifice the great cube

#include "CubeRunAction.hh"
#include "CubeAnalysis.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

CubeRunAction::CubeRunAction() : G4UserRunAction () {
    G4cout << "RunAction c'tor\n";
    G4RunManager::GetRunManager()->SetPrintProgress(1);

}

CubeRunAction::~CubeRunAction() {
    G4cout << "RunAction d'tor\n";
}

void CubeRunAction::BeginOfRunAction(const G4Run*) {
    //m_AnalysisManager->CreateNtuple("hitpos", "Hit positions");
}

void CubeRunAction::EndOfRunAction(const G4Run*) {
    G4AnalysisManager::Instance()->Write();
    G4AnalysisManager::Instance()->CloseFile();
}
