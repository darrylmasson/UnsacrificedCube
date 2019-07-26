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
#include <getopt.h>

int main(int argc, char** argv) {
    option opts[] = {
        {"interactive", no_argument, 0, 'i'},
        {"output-file", required_argument, 0, 'o'}
    };

    G4String output_filename = "testing";  // .hdf extension added automatically
    bool bInteractive = false;

    int option_index, c;
    while ((c = getopt_long_only(argc, argv, "io:", opts, &option_index)) != -1) {
        switch(c) {
            case 'i':
                bInteractive = true; break;
            case 'o':
                output_filename = optarg; break;
            default:
                std::cout << "Unknown option " << c << '\n'; break;
        }
    }

    G4Random::setTheEngine(new CLHEP::RanecuEngine);

    std::unique_ptr<G4RunManager> runManager = std::unique_ptr<G4RunManager>(new G4RunManager);

    auto detcon = new CubeDetectorConstruction();
    runManager->SetUserInitialization(detcon);
    runManager->SetUserInitialization(new FTFP_BERT());
    runManager->SetUserInitialization(new CubeActionInitialization(detcon, output_filename));

    auto visMan = std::unique_ptr<G4VisExecutive>(new G4VisExecutive);
    visMan->Initialize();
    auto UIman = G4UImanager::GetUIpointer();
    G4UIExecutive* ui = nullptr;
    G4String session;

    if (bInteractive) {
        ui = new G4UIExecutive(argc, argv, session);
        ui->SessionStart();
        delete ui;
    } else {
        UIman->ApplyCommand("/control/verbose 2");
        UIman->ApplyCommand("/run/verbose 2");
        UIman->ApplyCommand("/tracking/verbose 1");
        UIman->ApplyCommand("/run/initialize");
        UIman->ApplyCommand("/run/beamOn 3");
    }

    visMan.reset();
    runManager.reset();
    return 0;
}
