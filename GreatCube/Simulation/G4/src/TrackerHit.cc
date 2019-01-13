#include "TrackerHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Color.hh"
#include "G4VisAttributes.hh"

#include <iomanip>

G4ThreadLocal G4Allocator<TrackerHit>* TrackerHitAllocator = nullptr;

TrackerHit::TrackerHit() : G4VHit() {
    //G4cout << "TrackHit: ctor\n";
    m_iTrackID = -1;
    m_dEdep = 0;
    m_Pos = G4ThreeVector();
}

TrackerHit::TrackerHit(const TrackerHit& rhs) {
    //G4cout << "TrackHit: cctor\n";
    m_iTrackID = rhs.m_iTrackID;
    m_dEdep = rhs.m_dEdep;
    m_Pos = rhs.m_Pos;
}

TrackerHit::~TrackerHit() {}

const TrackerHit& TrackerHit::operator=(const TrackerHit& rhs) {
    m_iTrackID = rhs.m_iTrackID;
    m_dEdep = rhs.m_dEdep;
    m_Pos = rhs.m_Pos;

    return *this;
}

G4bool TrackerHit::operator==(const TrackerHit& rhs) const {
    return (this == &rhs) ? 1 : 0;
}

void TrackerHit::Draw() {
    G4VVisManager* pVisMan = G4VVisManager::GetConcreteInstance();
    if (pVisMan) {
        G4Circle circle(m_Pos);
        circle.SetScreenSize(4.);
        circle.SetFillStyle(G4Circle::filled);
        circle.SetVisAttributes(G4VisAttributes(G4Color(1,0,0)));
        pVisMan->Draw(circle);
    }
}

void TrackerHit::Print() {
    G4cout << " trackID: " << m_iTrackID << " Edep: "
        << std::setw(7) << G4BestUnit(m_dEdep, "Energy")
        << " Position "
        << std::setw(7) << G4BestUnit(m_Pos, "Length")
        << G4endl;
}
