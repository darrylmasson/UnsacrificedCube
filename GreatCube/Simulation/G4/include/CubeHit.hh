// Great Unsacrificed Cube
// CubeHit.hh
//
// copyright iNeat 2018
// please not to sacrifice the great cube

#ifndef _CUBE_HIT_H_
#define _CUBE_HIT_H_ 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

class CubeHit : public G4VHit {
    public:
        CubeHit();
        CubeHit(const CubeHit&);
        virtual ~CubeHit();

        const CubeHit& operator=(const CubeHit&);
        G4bool operator==(const CubeHit&) const;

        inline void* operator new(size_t);
        inline void operator delete(void*);

        virtual void Draw();
        virtual void Print();

        G4double GetEdep()      const {return m_Edep;}
        G4ThreeVector GetPos()  const {return m_Pos;}
        G4int GetPanelNb()      const {return m_PanelNb;}

        void SetEdep(G4double edep)     {m_Edep = edep;}
        void SetPos(G4ThreeVector pos)  {m_Pos = pos;}
        void SetPanelNb(G4int PanelNB)  {m_PanelNb = PanelNB;}

    private:
        G4double m_Edep;
        G4ThreeVector m_Pos;
        G4int m_TrackID;
        G4int m_PanelNb;
};

typedef G4THitsCollection<CubeHit> CubeHitsCollection;

extern G4ThreadLocal G4Allocator<CubeHit>* CubeHitAllocator;

inline void* CubeHit::operator new(size_t) {
    if (!CubeHitAllocator) CubeHitAllocator = new G4Allocator<CubeHit>;
    return (void*) CubeHitAllocator->MallocSingle();
}

inline void CubeHit::operator delete(void* hit) {
    CubeHitAllocator->FreeSingle((CubeHit*)hit);
}

#endif // _CUBE_H_ defined
