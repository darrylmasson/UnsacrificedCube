#ifndef __PURUEPHYSICSLIST_H__
#define __PURDUEPHYSICSLIST_H__

#include <G4VUserPhysicsList.hh>
#include <globals.hh>

// Leave this if you want to be able to run the
// old lowE physics list. Needs to be undefined 
// when the old implementation is really removed!
// (probably from geant4.5.x onwards)
//
// A.P. Colijn 26-07-2011

// add line below for backward compatibility. GEANT_VERSION < 9.5.x
//#define __KEEP_OLD_LOWE_EM__

//#include "PurduePhysicsListMessenger.hh"
#include "G4DecayPhysics.hh"

class G4VPhysicsConstructor;

class PurduePhysicsList: public G4VUserPhysicsList
{
public:
	PurduePhysicsList(G4String fName);
	~PurduePhysicsList();

public:
	void SetCuts();
	
	// functions for the messenger interface
	void SetEMlowEnergyModel(G4String theModel) { m_hEMlowEnergyModel = theModel; }
	void SetHadronicModel(G4String theModel)		{ m_hHadronicModel = theModel; }
	void SetCerenkov(G4bool useCerenkov) { m_bCerenkov = useCerenkov; }
	void SetHistograms(G4bool makeHistos) { makePhysicsHistograms = makeHistos; }

	void MakePhysicsPlots();
	void WriteParameter(G4String parName);
	
protected:
	void ConstructParticle();
	void ConstructProcess();

	void ConstructGeneral();
	void ConstructEM();
	void ConstructHad();
	void ConstructOp();

	void AddTransportation();

	void SetBuilderList1(G4bool flagHP);
	
private:
	G4double cutForGamma;
	G4double cutForElectron;
	G4double cutForPositron;
	G4double cutForProton;
	G4double cutForAlpha;
	G4double cutForGenericIon;

	void ConstructMyBosons();
	void ConstructMyLeptons();
	void ConstructMyHadrons();
	void ConstructMyShortLiveds();

private:
	G4int VerboseLevel;
	G4int OpVerbLevel;
	
	G4VPhysicsConstructor*							 emPhysicsList;
	G4VPhysicsConstructor*							 opPhysicsList;
	std::vector<G4VPhysicsConstructor*>	hadronPhys;

	//	G4String								 emName;
	
	// PurduePhysicsListMessenger *m_pMessenger;
	G4String								 m_hEMlowEnergyModel;
	G4String								 m_hHadronicModel;
	G4bool									 m_bCerenkov;
	G4DecayPhysics					*particleList;
	G4bool									 makePhysicsHistograms;
	
	G4String physRootFile;
};

#endif // 

