// Great Unsacrificed Cube
// CubePrimaryGeneratorAction.hh
//
// Copyright iNeat 2018
// please not to sacrifice the great cube

#ifndef _CUBE_PRIMARY_GENERATOR_ACTION_H_
#define _CUBE_PRIMARY_GENERATOR_ACTION_H_ 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include <memory>

class G4ParticleGun;
class G4Event;

class CubePrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
    public:
        CubePrimaryGeneratorAction(G4double);
        virtual ~CubePrimaryGeneratorAction();

        virtual void GeneratePrimaries(G4Event*);

    private:
        std::unique_ptr<G4ParticleGun> m_pParticleGun;
        G4double m_dWorldRadius;
        G4double m_dCubeSize;
};

#endif // _CUBE_PRIMARY_GENERATOR_ACTION_H_
