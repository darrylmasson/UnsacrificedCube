#ifndef TRACKER_HIT_H_
#define TRACKER_HIT_H_ 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "tls.hh"

class TrackerHit : public G4VHit {
    public:
        TrackerHit();
        TrackerHit(const TrackerHit&);
        virtual ~TrackerHit();

        const TrackerHit& operator=(const TrackerHit&);
        G4bool operator==(const TrackerHit&) const;
        inline void* operator new(size_t);
        inline void operator delete(void*);

        virtual void Draw();
        virtual void Print();

        void SetTrackID(G4int track)        {m_iTrackID = track;};
        void SetEdep(G4double edep)         {m_dEdep = edep;};
        void SetPos(G4ThreeVector pos)      {m_Pos = pos;};

        G4int GetTrackID() const            {return m_iTrackID;};
        G4double GetEdep() const            {return m_dEdep;};
        G4ThreeVector GetPos() const        {return m_Pos;};

    private:
        G4int           m_iTrackID;
        G4double        m_dEdep;
        G4ThreeVector   m_Pos;
};

typedef G4THitsCollection<TrackerHit> TrackerHitsCollection;

extern G4ThreadLocal G4Allocator<TrackerHit>* TrackerHitAllocator;

inline void* TrackerHit::operator new(size_t) {
    if (!TrackerHitAllocator) TrackerHitAllocator = new G4Allocator<TrackerHit>;
    return (void*) TrackerHitAllocator->MallocSingle();
}

inline void TrackerHit::operator delete(void* hit) {
    TrackerHitAllocator->FreeSingle((TrackerHit*) hit);
}

#endif // TRACKER_HIT_H_ defined
