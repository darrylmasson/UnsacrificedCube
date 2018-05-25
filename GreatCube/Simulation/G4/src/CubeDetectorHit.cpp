#include <G4UnitsTable.hh>
#include <G4VVisManager.hh>
#include <G4Circle.hh>
#include <G4Colour.hh>
#include <G4VisAttributes.hh>

#include "CubeDetectorHit.hpp"

G4Allocator<CubeDetectorHit> CubeDetectorHitAllocator;

CubeDetectorHit::CubeDetectorHit(){}

CubeDetectorHit::~CubeDetectorHit() {
	if(m_pParticleType) delete m_pParticleType;
	if(m_pParentType) delete m_pParentType;
	if(m_pCreatorProcess) delete m_pCreatorProcess;
	if(m_pDepositingProcess) delete m_pDepositingProcess;
}

CubeDetectorHit::CubeDetectorHit(const CubeDetectorHit &hCubeDetectorHit):G4VHit() {
	m_iTrackId = hCubeDetectorHit.m_iTrackId;
	m_iParentId = hCubeDetectorHit.m_iParentId;
	m_pParticleType = hCubeDetectorHit.m_pParticleType;
	m_pParentType = hCubeDetectorHit.m_pParentType ;
	m_pCreatorProcess = hCubeDetectorHit.m_pCreatorProcess ;
	m_pDepositingProcess = hCubeDetectorHit.m_pDepositingProcess ;
	m_hPosition = hCubeDetectorHit.m_hPosition;
	m_dEnergyDeposited = hCubeDetectorHit.m_dEnergyDeposited;
	m_dKineticEnergy = hCubeDetectorHit.m_dKineticEnergy;
	m_dPreStepEnergy = hCubeDetectorHit.m_dPreStepEnergy;
	m_dPostStepEnergy = hCubeDetectorHit.m_dPostStepEnergy;
	m_dTime = hCubeDetectorHit.m_dTime;
}

const CubeDetectorHit &
CubeDetectorHit::operator=(const CubeDetectorHit &hCubeDetectorHit) {
	m_iTrackId = hCubeDetectorHit.m_iTrackId;
	m_iParentId = hCubeDetectorHit.m_iParentId;
	m_pParticleType = hCubeDetectorHit.m_pParticleType;
	m_pParentType = hCubeDetectorHit.m_pParentType;
	m_pCreatorProcess = hCubeDetectorHit.m_pCreatorProcess;
	m_pDepositingProcess = hCubeDetectorHit.m_pDepositingProcess;
	m_hPosition = hCubeDetectorHit.m_hPosition;
	m_dEnergyDeposited = hCubeDetectorHit.m_dEnergyDeposited;
	m_dKineticEnergy = hCubeDetectorHit.m_dKineticEnergy;
	m_dPreStepEnergy = hCubeDetectorHit.m_dPreStepEnergy;
	m_dPostStepEnergy = hCubeDetectorHit.m_dPostStepEnergy;
	m_dTime = hCubeDetectorHit.m_dTime;
	
	return *this;
}

G4int
CubeDetectorHit::operator==(const CubeDetectorHit &hCubeDetectorHit) const {
	return ((this == &hCubeDetectorHit) ? (1) : (0));
}

void CubeDetectorHit::Draw() {
	G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
	
	if(pVVisManager)
	{
		G4Circle hCircle(m_hPosition);
		G4Colour hColour(1.000, 0.973, 0.184);
		G4VisAttributes hVisAttributes(hColour);
		
		hCircle.SetScreenSize(0.1);
		hCircle.SetFillStyle(G4Circle::filled);
		hCircle.SetVisAttributes(hVisAttributes);
		pVVisManager->Draw(hCircle);
	}
}

void CubeDetectorHit::Print() {
	G4cout << "-------------------- PanelHit --------------------" 
		<< "Id: " << m_iTrackId
		<< " Particle: " << *m_pParticleType
		<< " ParentId: " << m_iParentId
		<< " ParentType: " << *m_pParentType << G4endl
		<< "CreatorProcess: " << *m_pCreatorProcess
		<< " DepositingProcess: " << *m_pDepositingProcess << G4endl
		<< "Position: " << m_hPosition.x()/mm
		<< " " << m_hPosition.y()/mm
		<< " " << m_hPosition.z()/mm
		<< " mm" << G4endl
		<< " EnergyDeposited: " << m_dEnergyDeposited/keV << " keV"
		<< " KineticEnergyLeft: " << m_dKineticEnergy/keV << " keV"
	  	<< " PreStepEnergy:" << m_dPreStepEnergy/keV << " keV"
		<< " PostStepEnergy: " << m_dPostStepEnergy/keV << " keV"
		<< " Time: " << m_dTime/s << " s" << G4endl;
}

