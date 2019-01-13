// Great Unsacrificed Cube
// CubeDetectorConstruction.hh
//
// Copyright iNeat 2018
// please not to sacrifice the great cube

#ifndef _CUBE_DETECTOR_CONSTRUCTION_H_
#define _CUBE_DETECTOR_CONSTRUCTION_H_ 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

#include <vector>
#include <memory>

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Box;
class G4Orb;

class CubeDetectorMessenger;

using std::vector;
using std::unique_ptr;

class CubeDetectorConstruction : public G4VUserDetectorConstruction {
    public:
        CubeDetectorConstruction();
        virtual ~CubeDetectorConstruction();

        virtual G4VPhysicalVolume* Construct();
        virtual void ConstructSDandField();

        void SetPanelThickness(G4double thick)  {m_dPanelThick = thick;};
        void SetPanelSize(G4double size)        {m_dPanelEdge = size;};
        void SetTiling(G4int num)               {m_iTileCount = num;};

        G4int GetPanelCount()                    {return m_iPanelCount;};

    private:
        enum {
            _x = 0,
            _y,
            _z};
        void DefineMaterials();
        G4VPhysicalVolume* DefineVolumes();

        unique_ptr<CubeDetectorMessenger> m_pMessenger;

        G4Orb*                  m_pWorldSolid;
        G4LogicalVolume*        m_pWorldLV;
        G4VPhysicalVolume*      m_pWorldPV;

        G4Box*              m_pWaterSolid;
        G4LogicalVolume*    m_pWaterLV;
        G4VPhysicalVolume*  m_pWaterPV;

        G4Box*                          m_pPanelSolid;
        G4LogicalVolume*                m_pPanelLV;
        vector<G4VPhysicalVolume*>      m_vPanelPVs;

        G4double m_dPanelEdge;
        G4double m_dPanelThick;
        G4int m_iTileCount;
        G4int m_iPanelCount;
        G4double m_dWorldRadius;
        G4double m_dCubeFullEdge;
};

#endif // _CUBE_DETECTOR_CONSTRUCTION_H_
