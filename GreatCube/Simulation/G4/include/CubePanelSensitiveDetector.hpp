#ifndef __CUBESENSITIVEDETECTOR_H__
#define __CUBESENSITIVEDETECTOR_H__

#include <G4VSensitiveDetector.hh>

#include "CubeDetectorHit.hh"

class G4Step;
class G4HCofThisEvent;

class CubeSensitiveDetector: public G4VSensitiveDetector {
public:
	CubeSensitiveDetector(G4String hName);
	~CubeSensitiveDetector();

	void Initialize(G4HCofThisEvent *pHitsCollectionOfThisEvent);
	G4bool ProcessHits(G4Step *pStep, G4TouchableHistory *pHistory);
	void EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent);

private:
	CubeDetectorHitsCollection* m_pEljenDetectorHitsCollection;
    std::map<int,G4String> m_hParticleTypes;
};

#endif 
