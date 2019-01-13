#ifndef TRACKER_SD_H_
#define TRACKER_SD_H_ 1

#include "G4VSensitiveDetector.hh"
#include "TrackerHit.hh"
#include <vector>

class G4Step;
class G4HCofThisEvent;

class TrackerSD : public G4VSensitiveDetector {
    public:
        TrackerSD(const G4String& name, const G4String& hitColName);
        virtual ~TrackerSD();

        virtual void Initialize(G4HCofThisEvent* hitCollection);
        virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
        virtual void EndOfEvent(G4HCofThisEvent* hitCollection);

    private:
        TrackerHitsCollection* m_pHitsCollection;
};

#endif // TRACKER_SD_H_ defined
