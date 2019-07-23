// Great Unsacrificed Cube
// CubeHit.cc
//
// copyright iNeat 2018
// please not to sacrifice the great cube

#include "CubeHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Color.hh"
#include "G4VisAttributes.hh"
#include <iomanip>

G4ThreadLocal G4Allocator<CubeHit>* CubeHitAllocator = 0;

CubeHit::CubeHit() : G4VHit() {
    m_Edep = 0.;
    m_PanelNb = -1;
    m_Pos = G4ThreeVector();
}

CubeHit::CubeHit(const CubeHit& other) : G4VHit() {
    m_Edep = other.m_Edep;
    m_PanelNb = other.m_PanelNb;
    m_Pos = other.m_Pos;
}

CubeHit::~CubeHit() {}

const CubeHit& CubeHit::operator=(const CubeHit& rhs) {
    m_Edep = rhs.m_Edep;
    m_PanelNb = rhs.m_PanelNb;
    m_Pos = rhs.m_Pos;

    return *this;
}

G4bool CubeHit::operator==(const CubeHit& rhs) const {
    return (this == &rhs) ? true : false;
}

void CubeHit::Draw() {
    G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
    if (pVVisManager) {
        G4Circle circle(m_Pos);
        circle.SetScreenSize(4);
        circle.SetFillStyle(G4Circle::filled);
        circle.SetVisAttributes(G4VisAttributes(G4Color(1., 0., 0.)));
        pVVisManager->Draw(circle);
    }
}

void CubeHit::Print() {
    G4cout << " panelNb: " << m_PanelNb
           << "Edep: " << std::setw(4) << G4BestUnit(m_Edep, "Energy")
           << "Pos: " << std::setw(4) << G4BestUnit(m_Pos, "Length")
           << G4endl;
}
