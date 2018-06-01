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
class G4VLogicalVolume;
class G4VMaterial;

class CubeDetectorMessenger;

using std::vector;
using std::unique_ptr;

class CubeDetectorConstruction : public G4VUserDetectorConstruction {
    public:
        CubeDetectorConstruction();
        virtual ~CubeDetectorConstruction();

        virtual G4VPhysicalVolume* Construct();
        virtual void ConstructSDandField();

    private:
        void DefineMaterials();
        G4VPhysicalVolume* DefineVolumes();

        unique_ptr<CubeDetectorMessenger> m_pMessenger;
        m_bCheckOverlap;
};

#endif // _CUBE_DETECTOR_CONSTRUCTION_H_
