// Great Unsacrificed Cube
// CubePanelSD.hh
//
// copyright iNeat 2018
// please not to sacrifice the great cube

#ifndef _CUBE_PANEL_SD_H_
#define _CUBE_PANEL_SD_H_ 1

#include "G4VSensitiveDetector.hh"
#include "CubeHit.hh"

#include <vector>

class G4Step;
class G4HCofThisEvent;

class CubePanelSD : public G4VSensitiveDetector {
    public:
        CubePanelSD(const G4String& name, const G4String& hitCollectionName);
        virtual ~CubePanelSD();

        virtual void Initialize(G4HCofThisEvent* hitCollection);
        virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
        virtual void EndOfEvent(G4HCofThisEvent* hitCollection);

    private:
        CubeHitsCollection* m_pHitCollection;
};

#endif // _CUBE_PANEL_SD_H_
