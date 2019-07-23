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

CubeRunAction::CubeRunAction(G4int num_panels) : G4UserRunAction () {
    G4RunManager::GetRunManager()->SetPrintProgress(1);

    m_AnalysisManager = std::unique_ptr<G4AnalysisManager>(G4AnalysisManager::Instance());
    G4cout << "Using " << m_AnalysisManager->GetType() << G4endl;
    m_iNumPanels = num_panels;

    m_AnalysisManager->SetVerboseLevel(1);
}

CubeRunAction::~CubeRunAction() {
    m_AnalysisManager.reset();
}

void CubeRunAction::BeginOfRunAction(const G4Run*) {
    m_AnalysisManager->OpenFile("testing");

    m_AnalysisManager->CreateNtuple("truth", "MC truth");
    m_AnalysisManager->CreateNtupleDColumn("energy");
    m_AnalysisManager->CreateNtupleDColumn("target_x");
    m_AnalysisManager->CreateNtupleDColumn("target_y");
    m_AnalysisManager->CreateNtupleDColumn("target_z");
    m_AnalysisManager->CreateNtupleDColumn("px");
    m_AnalysisManager->CreateNtupleDColumn("py");
    m_AnalysisManager->CreateNtupleDColumn("pz");
    m_AnalysisManager->FinishNtuple();

    char name[20];
    m_AnalysisManager->CreateNtuple("Cube", "Panel Edep");
    for (int i = 0; i < m_iNumPanels; i++) {
        sprintf(name, "panel_%03i", i);
        m_AnalysisManager->CreateNtupleDColumn(name);
    }
    m_AnalysisManager->FinishNtuple();

    //m_AnalysisManager->CreateNtuple("hitpos", "Hit positions");
}

void CubeRunAction::EndOfRunAction(const G4Run*) {
    m_AnalysisManager->Write();
    m_AnalysisManager->CloseFile();
}
