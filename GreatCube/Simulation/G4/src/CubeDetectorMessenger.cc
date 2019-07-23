#include "CubeDetectorMessenger.hh"
#include "CubeDetectorConstruction.hh"

#include <sstream>

#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithAnInteger.hh"


CubeDetectorMessenger::CubeDetectorMessenger(CubeDetectorConstruction* detcon) : G4UImessenger(),
    m_pDetCon(detcon) {
    m_pUIDir = new G4UIdirectory("/panel/");
    m_pUIDir->SetGuidance("UI commands aviable");

    m_pPanelThicknessCmd = new G4UIcmdWithADoubleAndUnit("/panel/setThickness", this);
    m_pPanelThicknessCmd->SetGuidance("Set thickness of a single panel");
    m_pPanelThicknessCmd->SetParameterName("thickness", false);
    m_pPanelThicknessCmd->SetRange("thickness>0.");
    m_pPanelThicknessCmd->SetUnitCategory("Length");
    m_pPanelThicknessCmd->AvailableForStates(G4State_PreInit);
    m_pPanelThicknessCmd->SetToBeBroadcasted(false);

    m_pPanelSizeCmd = new G4UIcmdWithADoubleAndUnit("/panel/setSize", this);
    m_pPanelSizeCmd->SetGuidance("Set edge length of a single panel");
    m_pPanelSizeCmd->SetParameterName("size", false);
    m_pPanelSizeCmd->SetRange("size>0.");
    m_pPanelSizeCmd->SetUnitCategory("Length");
    m_pPanelSizeCmd->AvailableForStates(G4State_PreInit);
    m_pPanelSizeCmd->SetToBeBroadcasted(false);

    m_pPanelTileCountCmd = new G4UIcmdWithAnInteger("/panel/setPanelTiling", this);
    m_pPanelTileCountCmd->SetGuidance("Set number of panels per dimension");
    m_pPanelTileCountCmd->SetParameterName("Tiling", false);
    m_pPanelTileCountCmd->SetRange("1<Tiling && Tiling<10");
    m_pPanelTileCountCmd->AvailableForStates(G4State_PreInit);
    m_pPanelTileCountCmd->SetToBeBroadcasted(false);
}

CubeDetectorMessenger::~CubeDetectorMessenger() {
    delete m_pPanelTileCountCmd;
    delete m_pPanelSizeCmd;
    delete m_pPanelThicknessCmd;
    delete m_pUIDir;
}

void CubeDetectorMessenger::SetNewValue(G4UIcommand* command, G4String value) {
    if (command == m_pPanelThicknessCmd) {
        m_pDetCon->SetPanelThickness(m_pPanelThicknessCmd->GetNewDoubleValue(value));
    } else if (command == m_pPanelSizeCmd) {
        m_pDetCon->SetPanelSize(m_pPanelSizeCmd->GetNewDoubleValue(value));
    } else if (command == m_pPanelTileCountCmd) {
        m_pDetCon->SetTiling(m_pPanelTileCountCmd->GetNewIntValue(value));
    }
}
