#include "G4RunManager.hh"
#include "G4UIManager.hh"

#include "CubeDetectorConstruction.hpp"
#include "CubePhysicsList.hpp"
#include "CubeActionInitializer.hpp"

int main(int argc, char** argv) {
    G4RunManager* runMan = new G4RunManager;
    
    runMan->SetUserInitialization(new CubeDetectorConstruction);
    runMan->SetUserInitialization(new CubePhysicsList);
    runMan->SetUserInitialization(new CubeActionInitializer);
    
    runMan->Initialize();
    
    G4UIManager* UI = G4UIManager::GetUIpointer();
    UI->RunCommand("/run/verbose 1");
    UI->RunCommand("/event/verbose 1");
    UI->RunCommand("/tracking/verbose 1");
    
    int iNumEvents = 3;
    runMan->BeamOn(iNumEvents);
    
    delete runMan;
    return 0;
}