// Great Unsacrificed Cube
// CubeRunAction.cc
//
// copyright ineat 2018
// please not to sacrifice the great cube

#include "CubeRunAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

CubeRunAction::CubeRunAction(const G4String& name) : G4VUserRunAction () {
    m_sName = name;
    G4RunManager::GetRunManager()->SetPrintProgress(1);

    m_AnalysisManager = std::make_unique<G4AnalysisManager>(G4AnalysisManager::Instance());
    G4cout << "Using " << m_AnalysisManager->GetType() << G4endl;

    m_AnalysisManager->SetVerboseLevel(1);

    m_AnalysisManager->CreateNtuple("Cube", "Panel Edep");
    m_AnalysisManager->CreateNtupleDColumn("Panel1_Edep");
    m_AnalysisManager->CreateNtupleDColumn("Panel2_Edep");
    m_AnalysisManager->FinishNtuple();
}

CubeRunAction::~CubeRunAction() {
    m_AnalysisManager.reset();
}

void CubeRunAction::BeginOfRunAction(const G4Run*) {
    m_AnalysisManager->OpenFile(m_sName);
}

void CubeRunAction::EndOfRunAction(const G4Run*) {
    m_AnalysisManager->Write();
    m_AnalysisManager->CloseFile();
}
