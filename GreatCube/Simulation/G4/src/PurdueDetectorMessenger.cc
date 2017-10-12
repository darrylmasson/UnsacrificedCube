#include <G4ThreeVector.hh>
#include <G4RotationMatrix.hh>
#include <G4ParticleTable.hh>
#include <G4UIdirectory.hh>
#include <G4UIcmdWithoutParameter.hh>
#include <G4UIcmdWithAString.hh>
#include <G4UIcmdWithADoubleAndUnit.hh>
#include <G4UIcmdWith3Vector.hh>
#include <G4UIcmdWith3VectorAndUnit.hh>
#include <G4UIcmdWithAnInteger.hh>
#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithABool.hh>
#include <G4Tokenizer.hh>
#include <G4ios.hh>
#include <fstream>
#include <iomanip>

#include "PurdueDetectorMessenger.hh"

#include "PurdueDetectorConstruction.hh"

PurdueDetectorMessenger::PurdueDetectorMessenger(PurdueDetectorConstruction *pPurdueDetector)
:m_pPurdueDetector(pPurdueDetector)
{ 
  m_pDetectorDir = new G4UIdirectory("/NG/detector/");
  m_pDetectorDir->SetGuidance("detector control.");

  //Detector Seperation
  G4double dSeperationDefault = 0; //  mm
  m_pDetectorSeperationCmd = new G4UIcmdWithADoubleAndUnit("/Purdue/detector/setDetectorSeperation", this);
  m_pDetectorSeperationCmd->SetGuidance("Seperation between detectors");
  m_pDetectorSeperationCmd->SetParameterName("DetectorSeperation", false);
  m_pDetectorSeperationCmd->SetDefaultValue(dSeperationDefault);
  m_pDetectorSeperationCmd->SetUnitCategory("Length");
  m_pDetectorSeperationCmd->SetDefaultUnit("mm");
  m_pDetectorSeperationCmd->AvailableForStates(G4State_PreInit);

  //Detector Seperation
  G4double dFirstDetectorDefault = 0; //  mm
  m_pFirstDetectorCmd = new G4UIcmdWithADoubleAndUnit("/Purdue/detector/setFirstDetector", this);
  m_pFirstDetectorCmd->SetGuidance("Distance between N and first detector");
  m_pFirstDetectorCmd->SetParameterName("FirstDetector", false);
  m_pFirstDetectorCmd->SetDefaultValue(dFirstDetectorDefault);
  m_pFirstDetectorCmd->SetUnitCategory("Length");
  m_pFirstDetectorCmd->SetDefaultUnit("mm");
  m_pFirstDetectorCmd->AvailableForStates(G4State_PreInit);
 	
  //Angle between detectors
  G4double dAngleDefault = 0; 
  m_pDetectorAngleCmd = new G4UIcmdWithADouble("/Purdue/detector/setDetectorAngle", this);
  m_pDetectorAngleCmd->SetGuidance("Angle between detectors");
  m_pDetectorAngleCmd->SetParameterName("DetectorAngle", false);
  m_pDetectorAngleCmd->SetDefaultValue(dAngleDefault);
  m_pDetectorAngleCmd->AvailableForStates(G4State_PreInit);

  //Lead Sleeves around NeutronGenerator
  m_pLeadSleevesCmd = new G4UIcmdWithABool("/Purdue/detector/setLeadSleeves", this);
  m_pLeadSleevesCmd->SetGuidance("Choice of lead sleeves surrounding neutron generator.");
  m_pLeadSleevesCmd->SetParameterName("leadSleeves", false);
  m_pLeadSleevesCmd->AvailableForStates(G4State_PreInit);

  //Set Position of Third detector
  G4ThreeVector hThirdDetectorDefault(0.,0.,0.);
  m_pThirdDetectorPositionCmd = new G4UIcmdWith3VectorAndUnit("/Purdue/detector/ThirdDetectorCoord", this);
  m_pThirdDetectorPositionCmd->SetGuidance("Set position of the third detector");
  m_pThirdDetectorPositionCmd->SetParameterName("X", "Y", "Z", true, true);
  m_pThirdDetectorPositionCmd->SetDefaultValue(hThirdDetectorDefault);
  m_pThirdDetectorPositionCmd->SetUnitCategory("Length");
  m_pThirdDetectorPositionCmd->SetDefaultUnit("mm");
  m_pThirdDetectorPositionCmd->AvailableForStates(G4State_PreInit);

  //Set Position of Second detector
  G4ThreeVector hSecondDetectorDefault(0.,0.,0.);
  m_pSecondDetectorPositionCmd = new G4UIcmdWith3VectorAndUnit("/Purdue/detector/SecondDetectorCoord", this);
  m_pSecondDetectorPositionCmd->SetGuidance("Set position of the second detector");
  m_pSecondDetectorPositionCmd->SetParameterName("X", "Y", "Z", true, true);
  m_pSecondDetectorPositionCmd->SetDefaultValue(hSecondDetectorDefault);
  m_pSecondDetectorPositionCmd->SetUnitCategory("Length");
  m_pSecondDetectorPositionCmd->SetDefaultUnit("mm");
  m_pSecondDetectorPositionCmd->AvailableForStates(G4State_PreInit);

  //Set Position of First detector
  G4ThreeVector hFirstDetectorDefault(0.,0.,0.);
  m_pFirstDetectorPositionCmd = new G4UIcmdWith3VectorAndUnit("/Purdue/detector/FirstDetectorCoord", this);
  m_pFirstDetectorPositionCmd->SetGuidance("Set position of the third detector");
  m_pFirstDetectorPositionCmd->SetParameterName("X", "Y", "Z", true, true);
  m_pFirstDetectorPositionCmd->SetDefaultValue(hFirstDetectorDefault);
  m_pFirstDetectorPositionCmd->SetUnitCategory("Length");
  m_pFirstDetectorPositionCmd->SetDefaultUnit("mm");
  m_pFirstDetectorPositionCmd->AvailableForStates(G4State_PreInit);

  //Choice of Measurement
  m_pMeasurementCmd = new G4UIcmdWithAString("/Purdue/detector/setMeasurement", this);
  m_pMeasurementCmd->SetGuidance("Choice of measurement: (1) Flux (2) Energy");
  m_pMeasurementCmd->SetParameterName("measurementType", false);
  m_pMeasurementCmd->AvailableForStates(G4State_PreInit);

}

PurdueDetectorMessenger::~PurdueDetectorMessenger()
{
  delete m_pDetectorSeperationCmd;
  delete m_pFirstDetectorCmd;
  delete m_pDetectorAngleCmd;
  delete m_pLeadSleevesCmd;
  delete m_pThirdDetectorPositionCmd;
  delete m_pSecondDetectorPositionCmd;
  delete m_pFirstDetectorPositionCmd;
  delete m_pMeasurementCmd;
}

void PurdueDetectorMessenger::SetNewValue(G4UIcommand *pUIcommand, G4String hNewValue)
{
  //Detector Seperation
  if(pUIcommand == m_pDetectorSeperationCmd)
    m_pPurdueDetector->SetDetectorSeperation(m_pDetectorSeperationCmd->GetNewDoubleValue(hNewValue));

  //Position of First Detector 
  if(pUIcommand == m_pFirstDetectorCmd)
    m_pPurdueDetector->SetFirstDetector(m_pFirstDetectorCmd->GetNewDoubleValue(hNewValue));
    
  //Detector Angle
  if(pUIcommand == m_pDetectorAngleCmd)
    m_pPurdueDetector->SetDetectorAngle(m_pDetectorAngleCmd->GetNewDoubleValue(hNewValue));

  //Lead Sleeves
  if(pUIcommand == m_pLeadSleevesCmd)
    m_pPurdueDetector->SetLeadSleeves(m_pLeadSleevesCmd->GetNewBoolValue(hNewValue));

  //Third Detector
  if(pUIcommand == m_pThirdDetectorPositionCmd)
    m_pPurdueDetector->ThirdDetectorCoord(m_pThirdDetectorPositionCmd->GetNew3VectorValue(hNewValue));

  //Second Detector
  if(pUIcommand == m_pSecondDetectorPositionCmd)
    m_pPurdueDetector->SecondDetectorCoord(m_pSecondDetectorPositionCmd->GetNew3VectorValue(hNewValue));

  //First Detector
  if(pUIcommand == m_pFirstDetectorPositionCmd)
    m_pPurdueDetector->FirstDetectorCoord(m_pFirstDetectorPositionCmd->GetNew3VectorValue(hNewValue));

  //Measurement Type
  if(pUIcommand == m_pMeasurementCmd)
    m_pPurdueDetector->SetMeasurement(hNewValue);
	   
}
