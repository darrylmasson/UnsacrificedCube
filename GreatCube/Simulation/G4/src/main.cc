// THE GREAT UNSACRIFICED CUBE
//
// copywrite iNeat 2018
// Please not to sacrifice the great cube

#include "CubeDetectorConstruction.hh"
#include "CubeActionInitialization.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"

#include "Randomize.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "FTFP_BERT.hh"

#include <memory>

int main(int argc, char** argv) {
    G4Random::setTheEngine(new CLHEP::RanecuEngine);

    std::unique_ptr<G4RunManager> runManager = std::unique_ptr<G4RunManager>(new G4RunManager);

    auto detcon = new CubeDetectorConstruction();
    runManager->SetUserInitialization(detcon);
    runManager->SetUserInitialization(new FTFP_BERT());
    runManager->SetUserInitialization(new CubeActionInitialization(detcon));

    auto visMan = std::unique_ptr<G4VisExecutive>(new G4VisExecutive);
    visMan->Initialize();
    auto UIman = G4UImanager::GetUIpointer();

    UIman->ApplyCommand("/run/beamOn 3");

    visMan.reset();
    runManager.reset();
    return 0;
}