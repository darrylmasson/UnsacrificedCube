
#include <G4SDManager.hh>
#include <G4Run.hh>
#include <G4Event.hh>
#include <G4HCofThisEvent.hh>
#include <G4EmCalculator.hh>
#include <G4Material.hh>
#include <G4HadronicProcessStore.hh>
#include <G4ParticleTable.hh>
#include <G4NistManager.hh>
#include <G4ElementTable.hh>
#include <G4Version.hh>
//#include <G4Element.hh> 
#include <numeric>

#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TParameter.h>
#include <TDirectory.h>
#include <TH1.h>

#include "CubeDetectorConstruction.hpp"
#include "CubeEljenDetectorHit.hpp"
#include "CubePrimaryGeneratorAction.hpp"
#include "CubeEventData.hpp"

#include "CubeAnalysisManager.hpp"

CubeAnalysisManager::CubeAnalysisManager(CubePrimaryGeneratorAction *pPrimaryGeneratorAction) :
    m_iEljenDetectorHitsCollectionID(-1), m_hDataFilename("events.root"), m_iNbEventsToSimulate(0),
    m_pTreeFile(0), m_pTree(0), _events(0),
    m_pNbEventsToSimulateParameter(0), m_pPrimaryGeneratorAction(pPrimaryGeneratorAction),
    m_pEventData(0), plotPhysics(true), runTime(0),
    writeEmptyEvents(false)
    
{
    runTime = new G4Timer();
    m_pEventData = new CubeEventData();
}

CubeAnalysisManager::~CubeAnalysisManager() {}

void
CubeAnalysisManager::BeginOfRun(const G4Run *) {
    // start a timer for this run....
    runTime->Start();
    // do we write empty events or not?
    writeEmptyEvents = m_pPrimaryGeneratorAction->GetWriteEmpty();
    
    m_pTreeFile = new TFile(m_hDataFilename.c_str(), "RECREATE");//, "File containing event data for Xenon1T");
    // make tree structure
    TNamed *G4version = new TNamed("G4VERSION_TAG",G4VERSION_TAG);
    G4version->Write();
      
    _events = m_pTreeFile->mkdir("events");
    _events->cd();

    G4cout <<"CubeAnalysisManager:: Init data tree ..."<<G4endl;
    m_pTree = new TTree("events", "Tree containing event data for Cube Detector");

    gROOT->ProcessLine("#include <vector>");
    
    m_pTree->Branch("eventid", &m_pEventData->m_iEventId, "eventid/I");
    //Figure Uit watter tak om te hou en verander verder soos nodig
    m_pTree->Branch("neljendetectorhits", &m_pEventData->m_iNbEljenDetectorHits);
    m_pTree->Branch("eljendetectorhits", "vector<int>", &m_pEventData->m_pEljenHits);

    m_pTree->Branch("etot", &m_pEventData->m_fTotalEnergyDeposited, "etot/F");
    m_pTree->Branch("nsteps", &m_pEventData->m_iNbSteps, "nsteps/I");
    m_pTree->Branch("trackid", "vector<int>", &m_pEventData->m_pTrackId);
    m_pTree->Branch("type", "vector<string>", &m_pEventData->m_pParticleType);
    m_pTree->Branch("parentid", "vector<int>", &m_pEventData->m_pParentId);
    m_pTree->Branch("parenttype", "vector<string>", &m_pEventData->m_pParentType);
    m_pTree->Branch("creaproc", "vector<string>", &m_pEventData->m_pCreatorProcess);
    m_pTree->Branch("edproc", "vector<string>", &m_pEventData->m_pDepositingProcess);
    m_pTree->Branch("PreStepEnergy", "vector<float>", &m_pEventData->m_pPreStepEnergy);
    m_pTree->Branch("PostStepEnergy", "vector<float>", &m_pEventData->m_pPostStepEnergy);
    m_pTree->Branch("xp", "vector<float>", &m_pEventData->m_pX);
    m_pTree->Branch("yp", "vector<float>", &m_pEventData->m_pY);
    m_pTree->Branch("zp", "vector<float>", &m_pEventData->m_pZ);
    m_pTree->Branch("ed", "vector<float>", &m_pEventData->m_pEnergyDeposited);
    m_pTree->Branch("time", "vector<float>", &m_pEventData->m_pTime);

    m_pTree->Branch("type_pri", "vector<string>", &m_pEventData->m_pPrimaryParticleType);
    m_pTree->Branch("xp_pri", &m_pEventData->m_fPrimaryX, "xp_pri/F");
    m_pTree->Branch("yp_pri", &m_pEventData->m_fPrimaryY, "yp_pri/F");
    m_pTree->Branch("zp_pri", &m_pEventData->m_fPrimaryZ, "zp_pri/F");
    m_pTree->Branch("xp_fcd", &m_pEventData->m_fForcedPrimaryX, "xp_fcd/F");
    m_pTree->Branch("yp_fcd", &m_pEventData->m_fForcedPrimaryY, "yp_fcd/F");
    m_pTree->Branch("zp_fcd", &m_pEventData->m_fForcedPrimaryZ, "zp_fcd/F");
    m_pTree->Branch("e_pri",  &m_pEventData->m_fPrimaryE, "e_pri/F");
    m_pTree->Branch("w_pri",  &m_pEventData->m_fPrimaryW, "w_pri/F");
    
    m_pNbEventsToSimulateParameter = new TParameter<int>("nbevents", m_iNbEventsToSimulate);
    m_pNbEventsToSimulateParameter->Write();

    m_pTreeFile->cd();

}

void CubeAnalysisManager::EndOfRun(const G4Run *) {
    runTime->Stop();
    G4double dt = runTime->GetRealElapsed();
    // make tree structure
    TParameter<G4double> *dtPar = new TParameter<G4double>("G4RUNTIME",dt);
    dtPar->Write();

    m_pTreeFile->cd();

    m_pTreeFile->Write();
    m_pTreeFile->Close();
}

void CubeAnalysisManager::BeginOfEvent(const G4Event *) {
    if(m_iEljenDetectorHitsCollectionID == -1) {
        G4SDManager *pSDManager = G4SDManager::GetSDMpointer();
        m_iEljenDetectorHitsCollectionID = pSDManager->GetCollectionID("EljenDetectorHitsCollection");
    } 
    //G4cout<<"The HC ID is "<<m_iEljenDetectorHitsCollectionID<<G4endl;
}

void CubeAnalysisManager::EndOfEvent(const G4Event *pEvent) {
    _events->cd();

    G4HCofThisEvent* pHCofThisEvent = pEvent->GetHCofThisEvent();
    // G4cout<<"pHCofThisEvent is"<<pHCofThisEvent<<G4endl;
    //G4cout << pHCofThisEvent->GetCapacity() << G4endl;
    //G4cout << pHCofThisEvent->GetNumberOfCollections() << G4endl;
    CubeEljenDetectorHitsCollection* pEljenDetectorHitsCollection = 0;
 

    G4int iNbEljenDetectorHits = 0; 

    //G4cout<<"pEljenDetectorHitsCollection is "<<pEljenDetectorHitsCollection<<G4endl;
    //G4cout<<"m_iEljenDetectorHitsCollectionID is "<<m_iEljenDetectorHitsCollectionID<<G4endl;
	
    if ((pHCofThisEvent) and (m_iEljenDetectorHitsCollectionID != -1)) {
        pEljenDetectorHitsCollection = (CubeEljenDetectorHitsCollection *)(pHCofThisEvent->GetHC(m_iEljenDetectorHitsCollectionID));
        iNbEljenDetectorHits = (pEljenDetectorHitsCollection)?(pEljenDetectorHitsCollection->entries()):(0);
    }

    // G4cout<<"pEljenDetectorHitsCollection is "<<pEljenDetectorHitsCollection<<G4endl;
    
    // G4cout<<"pEljenDetectorHitsCollection name is "<<pEljenDetectorHitsCollection->GetName()<<G4endl;
    

    // get the event ID and primary particle information
    m_pEventData->m_iEventId = pEvent->GetEventID();
    m_pEventData->m_pPrimaryParticleType->push_back(m_pPrimaryGeneratorAction->GetParticleTypeOfPrimary());
    
    m_pEventData->m_fPrimaryX = m_pPrimaryGeneratorAction->GetPositionOfPrimary().x();
    m_pEventData->m_fPrimaryY = m_pPrimaryGeneratorAction->GetPositionOfPrimary().y();
    m_pEventData->m_fPrimaryZ = m_pPrimaryGeneratorAction->GetPositionOfPrimary().z();

    m_pEventData->m_fForcedPrimaryX = m_pPrimaryGeneratorAction->GetForcedPositionOfPrimary().x();
    m_pEventData->m_fForcedPrimaryY = m_pPrimaryGeneratorAction->GetForcedPositionOfPrimary().y();
    m_pEventData->m_fForcedPrimaryZ = m_pPrimaryGeneratorAction->GetForcedPositionOfPrimary().z();

    m_pEventData->m_fPrimaryE = m_pPrimaryGeneratorAction->GetEnergyOfPrimary() / keV;
    m_pEventData->m_fPrimaryW = pEvent->GetPrimaryVertex()->GetWeight();
 
    
    G4int iNbSteps = 0;
    G4float fTotalEnergyDeposited = 0.;
    
    if(iNbEljenDetectorHits) {
        //  hits
        //G4cout << " I HAVE " << iNbEljenDetectorHits << " HITS " << G4endl;
        for(G4int i=0; i<iNbEljenDetectorHits; i++) {
            CubeEljenDetectorHit *pHit = (*pEljenDetectorHitsCollection)[i];
            // G4cout <<"PARTICLE TYPE IS:" << pHit << G4endl;
            //  pHit->Print();
            //  G4cout <<1111<<G4endl;
            //  G4cout << pHit->GetParticleType() << G4endl;
            //G4cout <<"JOLLY GOOD" << G4endl;
            if(pHit->GetParticleType() != "opticalphoton") {
                m_pEventData->m_pTrackId->push_back(pHit->GetTrackId());
                m_pEventData->m_pParentId->push_back(pHit->GetParentId());

                m_pEventData->m_pParticleType->push_back(pHit->GetParticleType());
                m_pEventData->m_pParentType->push_back(pHit->GetParentType());
                m_pEventData->m_pCreatorProcess->push_back(pHit->GetCreatorProcess());
                m_pEventData->m_pDepositingProcess->push_back(pHit->GetDepositingProcess());

                m_pEventData->m_pX->push_back(pHit->GetPosition().x()/mm);
                m_pEventData->m_pY->push_back(pHit->GetPosition().y()/mm);
                m_pEventData->m_pZ->push_back(pHit->GetPosition().z()/mm);

                fTotalEnergyDeposited += pHit->GetEnergyDeposited()/keV;
                m_pEventData->m_pEnergyDeposited->push_back(pHit->GetEnergyDeposited()/keV);
                m_pEventData->m_pKineticEnergy->push_back(pHit->GetKineticEnergy()/keV);
                m_pEventData->m_pPreStepEnergy->push_back(pHit->GetPreStepEnergy()/keV);
                m_pEventData->m_pPostStepEnergy->push_back(pHit->GetPostStepEnergy()/keV);
                m_pEventData->m_pTime->push_back(pHit->GetTime()/second);

                iNbSteps++;
            }
            // G4cout <<"SUCCESS"<<G4endl;
        }
    }
    
    // also write the header information + primary vertex of the empty events....
    m_pEventData->m_iNbSteps = iNbSteps;
    m_pEventData->m_fTotalEnergyDeposited = fTotalEnergyDeposited;
    
    // save only energy depositing events
    if(writeEmptyEvents) {
        m_pTree->Fill(); // write all events to the tree
    } else {
        if ((fTotalEnergyDeposited > 0.) || (iNbEljenDetectorHits > 0)) m_pTree->Fill(); // only events with some activity are written to the tree
    }
    
    m_pEventData->Clear(); 
    m_pTreeFile->cd();
}

void CubeAnalysisManager::Step(const G4Step *) {
}
