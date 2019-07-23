// Great Unsacrificed Cube
// CubeEventAction.hh
//
// Copyright iNeat 2018
// please not to sacrifice the great cube

#ifndef _CUBE_EVENT_ACTION_H_
#define _CUBE_EVENT_ACTION_H_ 1

#include "G4UserEventAction.hh"
#include "CubeHit.hh"
#include <vector>

class G4Event;

class CubeEventAction : public G4UserEventAction {
    public:
        CubeEventAction(G4int NumPanels);
        virtual ~CubeEventAction();

        virtual void BeginOfEventAction(const G4Event* event);
        virtual void EndOfEventAction(const G4Event* event);

    private:
        CubeHitsCollection* GetHitsCollection(G4int hcID, const G4Event* event) const;
        std::vector<G4double> m_vEdep;

        G4int m_PanelHCID;
};
#endif // _CUBE_EVENT_ACTION_H_
