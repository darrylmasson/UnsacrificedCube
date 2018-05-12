#include <G4HCofThisEvent.hh>
#include <G4Step.hh>
#include <G4VProcess.hh>
#include <G4ThreeVector.hh>
#include <G4SDManager.hh>
#include <G4ios.hh>

#include <map>

using namespace std;

#include "CubeSensitiveDetector.hh"

CubeSensitiveDetector::CubeSensitiveDetector(G4String hName): G4VSensitiveDetector(hName)
{
	collectionName.insert("CubeDetectorHitsCollection");
}

CubeSensitiveDetector::~CubeSensitiveDetector()
{
}

void CubeSensitiveDetector::Initialize(G4HCofThisEvent* pHitsCollectionOfThisEvent)
{
	m_pCubeDetectorHitsCollection = new CubeDetectorHitsCollection(SensitiveDetectorName, collectionName[0]);

	static G4int iHitsCollectionID = -1;

	if(iHitsCollectionID < 0)
		iHitsCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);

	pHitsCollectionOfThisEvent->AddHitsCollection(iHitsCollectionID, m_pCubeDetectorHitsCollection);
}

G4bool CubeSensitiveDetector::ProcessHits(G4Step* pStep, G4TouchableHistory *)
{
	G4double dEnergyDeposited = pStep->GetTotalEnergyDeposit();	
	G4Track *pTrack = pStep->GetTrack();

	//if(pTrack->GetDefinition()->GetParticleName() == "neutron")
	// {

	// G4cout << G4endl << "I MADE A NEW HIT " << G4endl;
	CubeDetectorHit* pHit = new CubeDetectorHit();
	pHit->SetTrackId(pTrack->GetTrackID());
	if(!m_hParticleTypes.count(pTrack->GetTrackID()))
	  m_hParticleTypes[pTrack->GetTrackID()] = pTrack->GetDefinition()->GetParticleName();

	pHit->SetParentId(pTrack->GetParentID());
	pHit->SetParticleType(pTrack->GetDefinition()->GetParticleName());

	if(pTrack->GetParentID())
	    pHit->SetParentType(m_hParticleTypes[pTrack->GetParentID()]);
	else
	    pHit->SetParentType(G4String("none"));

	if(pTrack->GetCreatorProcess())
	    pHit->SetCreatorProcess(pTrack->GetCreatorProcess()->GetProcessName());
	else
	    pHit->SetCreatorProcess(G4String("Null"));

	pHit->SetPosition(pStep->GetPostStepPoint()->GetPosition());
	pHit->SetDepositingProcess(pStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName());
	pHit->SetEnergyDeposited(dEnergyDeposited);
	pHit->SetKineticEnergy(pTrack->GetKineticEnergy());
	pHit->SetPreStepEnergy(pStep->GetPreStepPoint()->GetKineticEnergy());
 	pHit->SetPostStepEnergy(pStep->GetPostStepPoint()->GetKineticEnergy());

	pHit->SetTime(pTrack->GetGlobalTime());

	m_pCubeDetectorHitsCollection->insert(pHit);

	    //   pHit->Print();

	    //		pHit->Print();
	    //		pHit->Draw();

	return true;
}
//	else return false;
//}

void CubeSensitiveDetector::EndOfEvent(G4HCofThisEvent *)
{
//  if (verboseLevel>0)
// { 
//     G4int NbHits = trackerCollection->entries();
//     G4cout << "\n-------->Hits Collection: in this event they are " << NbHits 
//            << " hits in the tracker chambers: " << G4endl;
//     for (G4int i=0;i<NbHits;i++) (*trackerCollection)[i]->Print();
//    } 
}
