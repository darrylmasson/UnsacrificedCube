#ifndef __PURDUEELJENSENSITIVEDETECTOR_H__
#define __PURDUEELJENSENSITIVEDETECTOR_H__

#include <G4VSensitiveDetector.hh>

#include "PurdueEljenDetectorHit.hh"

class G4Step;
class G4HCofThisEvent;

class PurdueEljenSensitiveDetector: public G4VSensitiveDetector
{
public:
	PurdueEljenSensitiveDetector(G4String hName);
	~PurdueEljenSensitiveDetector();

	void Initialize(G4HCofThisEvent *pHitsCollectionOfThisEvent);
	G4bool ProcessHits(G4Step *pStep, G4TouchableHistory *pHistory);
	void EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent);

private:
	PurdueEljenDetectorHitsCollection* m_pEljenDetectorHitsCollection;
        std::map<int,G4String> m_hParticleTypes;
};

#endif 
