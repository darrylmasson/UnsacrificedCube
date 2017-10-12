#include <globals.hh>
#include <G4RunManagerKernel.hh>
#include <G4Event.hh>
#include <Randomize.hh>

#include <G4GeneralParticleSource.hh>
#include <G4Material.hh>
#include <G4ThreeVector.hh>
#include <G4TransportationManager.hh>
#include <G4Navigator.hh>
#include <G4VPhysicalVolume.hh>
#include <G4LogicalVolume.hh>
#include <G4PrimaryVertex.hh>
#include <G4ParticleDefinition.hh>
// testing
#include <G4Point3D.hh>
#include <G4Vector3D.hh>
#include <G4SingleParticleSource.hh>

#include "PurdueParticleSource.hh"
#include "PurduePrimaryGeneratorAction.hh"
//#include "PurduePrimaryGeneratorMessenger.hh"

PurduePrimaryGeneratorAction::PurduePrimaryGeneratorAction(G4String fName)
{
  //m_pMessenger       = new PurduePrimaryGeneratorMessenger(this);

  G4cout <<"PurduePrimaryGeneratorAction::PurduePrimaryGeneratorAction() Use PurdueParticleSource "<<G4endl;
  m_pParticleSource = new PurdueParticleSource();
  
  particleTable = G4ParticleTable::GetParticleTable();
  
  m_hParticleTypeOfPrimary = "";
  m_dEnergyOfPrimary = 0.;
  m_hPositionOfPrimary = G4ThreeVector(0., 0., 0.);
  
  m_lSeeds[0] = -1;
  m_lSeeds[1] = -1;
  
  //G4cout <<"PurduePrimaryGeneratorAction:: MC with variance reduction = "<<VarianceReduction<<G4endl;
  //G4cout <<"PurduePrimaryGeneratorAction::               survival cut = "<<p_survive_cut<<G4endl;
  // for use with ForcedTransport of gammas
  particleGun  = new G4ParticleGun();
  
  theNavigator = G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();
  // forced transport target volume cylinder
  ft_cyl_R      = 0*cm; // set through messenger
  ft_cyl_L      = 0*cm; // set through messenger
  ft_cyl_center = G4ThreeVector(0,0,0); // set through messenger
  // maximum number of rejected primaries er event
  ntry_max = 1000;
  // number of rejected primaries
  numberOfRejectedPrimaries = 0.;
  // number of rejected primaries (double vaiables, since it counts the event weights)
  numberOfAcceptedPrimaries = 0.;
  // total run weight
  runWeight = 0;
  
  generatorRootFile = fName;
  // histograms.....
  _f_prim = new TFile(generatorRootFile,"RECREATE");
  
  _generator = _f_prim->mkdir("generator");
  
  _generator->cd();
  _log_primary_w = new TH1F("_log_primary_w","_log_primary_w",100,-20,0);
  _cost_all      = new TH1F("_cost_all","_cost_all",100,-1,1);
  _energy_all    = new TH1F("_energy_all","_energy_all",1000,0,5);
  
  _cost_accept   = new TH1F("_cost_accept","_cost_accept",100,-1,1);
  _energy_accept = new TH1F("_energy_accept","_energy_accept",1000,0,5);
  
}

PurduePrimaryGeneratorAction::~PurduePrimaryGeneratorAction()
{
  
  _f_prim->cd();
  _generator->cd();
  
  //  write the source settings to file
  G4ParticleDefinition * def = m_pParticleSource->GetParticleDefinition();
  TNamed *TypePar(0);
  if (def) TypePar = new TNamed("SourceType", m_pParticleSource->GetParticleDefinition()->GetParticleName());
  else TypePar = new TNamed("SourceType", "");
  TypePar->Write();
  TParameter<G4double> *IntensityPar = new TParameter<G4double>("SourceIntensity", -999.999);
  IntensityPar->Write();  
  
  nRejectParameter = new TParameter<double>("nreject",GetNumberOfRejectedPrimaries());
  nRejectParameter->Write();
  
  nAcceptParameter = new TParameter<double>("naccept",GetNumberOfAcceptedPrimaries());
  nAcceptParameter->Write();
  
  _f_prim->cd();
  
  _f_prim->Write();
  _f_prim->Close();
  
  delete particleGun;
 
  delete m_pParticleSource;
}

void 
PurduePrimaryGeneratorAction::GeneratePrimaries(G4Event *pEvent)
{
  // generate a single particle 
  m_lSeeds[0] = *(CLHEP::HepRandom::getTheSeeds());
  m_lSeeds[1] = *(CLHEP::HepRandom::getTheSeeds()+1);
  
  // PB 06/05/2012 - Start
  G4StackManager *pStackManager = (G4RunManagerKernel::GetRunManagerKernel())->GetStackManager(); // pb added

  if(!pStackManager->GetNPostponedTrack())
    {
      m_pParticleSource->GeneratePrimaryVertex(pEvent);
      // particle name of primary
      m_hParticleTypeOfPrimary = m_pParticleSource->GetParticleDefinition()->GetParticleName();
    }
  else
    {
      pStackManager->TransferStackedTracks(fPostpone, fUrgent);
      G4VTrajectory* pTrajectory;
      G4Track *pTrack = pStackManager->PopNextTrack(&pTrajectory);
      
      m_pParticleSource->GeneratePrimaryVertexFromTrack(pTrack, pEvent);
      // particle name of primary
      m_hParticleTypeOfPrimary = pTrack->GetParticleDefinition()->GetParticleName();
  
      delete pTrack;
    }
  // PB 06/05/2012 - End

  //G4cout << " PPP now Start Tracking " <<  m_hParticleTypeOfPrimary  << G4endl;  //MS121106

  // kinetic energy of primary
   m_dEnergyOfPrimary       = m_pParticleSource->GetParticleEnergy();
  // position of primary
   m_hPositionOfPrimary     = m_pParticleSource->GetParticlePosition();
  // direction of primary
   m_hDirectionOfPrimary    = m_pParticleSource->GetParticleMomentumDirection();
  
   FillHistograms();
  
   numberOfAcceptedPrimaries += 1.0;
}


void 
PurduePrimaryGeneratorAction::FillHistograms(){
  
  _energy_accept->Fill(m_dEnergyOfPrimary);
  _cost_accept->Fill(m_hDirectionOfPrimary.z());
  
}
 

