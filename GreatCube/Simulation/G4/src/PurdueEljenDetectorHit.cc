#include <G4UnitsTable.hh>
#include <G4VVisManager.hh>
#include <G4Circle.hh>
#include <G4Colour.hh>
#include <G4VisAttributes.hh>

#include "PurdueEljenDetectorHit.hh"

G4Allocator<PurdueEljenDetectorHit> PurdueEljenDetectorHitAllocator;

PurdueEljenDetectorHit::PurdueEljenDetectorHit(){}

PurdueEljenDetectorHit::~PurdueEljenDetectorHit()
{
	if(m_pParticleType) delete m_pParticleType;
	if(m_pParentType) delete m_pParentType;
	if(m_pCreatorProcess) delete m_pCreatorProcess;
	if(m_pDepositingProcess) delete m_pDepositingProcess;
}

PurdueEljenDetectorHit::PurdueEljenDetectorHit(const PurdueEljenDetectorHit &hPurdueEljenDetectorHit):G4VHit()
{
	m_iTrackId = hPurdueEljenDetectorHit.m_iTrackId;
	m_iParentId = hPurdueEljenDetectorHit.m_iParentId;
	m_pParticleType = hPurdueEljenDetectorHit.m_pParticleType;
	m_pParentType = hPurdueEljenDetectorHit.m_pParentType ;
	m_pCreatorProcess = hPurdueEljenDetectorHit.m_pCreatorProcess ;
	m_pDepositingProcess = hPurdueEljenDetectorHit.m_pDepositingProcess ;
	m_hPosition = hPurdueEljenDetectorHit.m_hPosition;
	m_dEnergyDeposited = hPurdueEljenDetectorHit.m_dEnergyDeposited;
	m_dKineticEnergy = hPurdueEljenDetectorHit.m_dKineticEnergy ;
	m_dPreStepEnergy = hPurdueEljenDetectorHit.m_dPreStepEnergy ;
	m_dPostStepEnergy = hPurdueEljenDetectorHit.m_dPostStepEnergy ;
	m_dTime = hPurdueEljenDetectorHit.m_dTime;
}

const PurdueEljenDetectorHit &
PurdueEljenDetectorHit::operator=(const PurdueEljenDetectorHit &hPurdueEljenDetectorHit)
{
	m_iTrackId = hPurdueEljenDetectorHit.m_iTrackId;
	m_iParentId = hPurdueEljenDetectorHit.m_iParentId;
	m_pParticleType = hPurdueEljenDetectorHit.m_pParticleType;
	m_pParentType = hPurdueEljenDetectorHit.m_pParentType ;
	m_pCreatorProcess = hPurdueEljenDetectorHit.m_pCreatorProcess ;
	m_pDepositingProcess = hPurdueEljenDetectorHit.m_pDepositingProcess ;
	m_hPosition = hPurdueEljenDetectorHit.m_hPosition;
	m_dEnergyDeposited = hPurdueEljenDetectorHit.m_dEnergyDeposited;
	m_dKineticEnergy = hPurdueEljenDetectorHit.m_dKineticEnergy ;
	m_dPreStepEnergy = hPurdueEljenDetectorHit.m_dPreStepEnergy ;
	m_dPostStepEnergy = hPurdueEljenDetectorHit.m_dPostStepEnergy ;
	m_dTime = hPurdueEljenDetectorHit.m_dTime;
	
	return *this;
}

G4int
PurdueEljenDetectorHit::operator==(const PurdueEljenDetectorHit &hPurdueEljenDetectorHit) const
{
	return ((this == &hPurdueEljenDetectorHit) ? (1) : (0));
}

void PurdueEljenDetectorHit::Draw()
{
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

void PurdueEljenDetectorHit::Print()
{
	G4cout << "-------------------- EljenDetectorHit --------------------" 
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

