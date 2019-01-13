#ifndef _CUBE_DETECTOR_MESSENGER_H_
#define _CUBE_DETECTOR_MESSENGER_H_ 1

#include "globals.hh"
#include "G4UImessenger.hh"

class CubeDetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithAnInteger;

class CubeDetectorMessenger : public G4UIMessenger {
    public:
        CubeDetectorMessenger(CubeDetectorConstruction*);
        virtual ~CubeDetectorMessenger();

        virtual void SetNewValue(G4UIcommand*, G4String);

    private:
        G4UIdirectory*              m_pUIDir;

        G4UIcmdWithADoubleAndUnit*  m_pPanelThicknessCmd;
        G4UIcmdWithADoubleAndUnit*  m_pPanelSizeCmd;
        G4UIcmdWithAnInteger*       m_pPanelTileCountCmd;
};

#endif // _CUBE_DETECTOR_MESSENGER_H_ defined
