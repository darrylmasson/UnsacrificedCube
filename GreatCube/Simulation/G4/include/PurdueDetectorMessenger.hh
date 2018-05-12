#ifndef PurdueDetectorMessenger_h
#define PurdueDetectorMessenger_h 1

#include <G4UImessenger.hh>
#include <globals.hh>

class PurdueDetectorConstruction;

class G4UIcommand;
class G4UIdirectory;
class G4UIcmdWithoutParameter;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWith3Vector;
class G4UIcmdWith3VectorAndUnit;
class G4UIcmdWithAnInteger;
class G4UIcmdWithADouble;
class G4UIcmdWithABool;
class G4UIcmdWithoutParameter;

class PurdueDetectorMessenger: public G4UImessenger
{
public:
	PurdueDetectorMessenger(PurdueDetectorConstruction *pPurdueDetector);
	~PurdueDetectorMessenger();

	void		 SetNewValue(G4UIcommand *pUIcommand, G4String hString);

private:
	PurdueDetectorConstruction* m_pPurdueDetector;

	G4UIdirectory *m_pDetectorDir;

	G4UIcmdWithADoubleAndUnit *m_pDetectorSeperationCmd;
				G4UIcmdWithADoubleAndUnit *m_pFirstDetectorCmd;
				G4UIcmdWithADouble *m_pDetectorAngleCmd;
				G4UIcmdWithABool *m_pLeadSleevesCmd;
				G4UIcmdWith3VectorAndUnit *m_pThirdDetectorPositionCmd;
				G4UIcmdWith3VectorAndUnit *m_pSecondDetectorPositionCmd;	 
				G4UIcmdWith3VectorAndUnit *m_pFirstDetectorPositionCmd;
				G4UIcmdWithAString *m_pMeasurementCmd;
 

};

#endif

