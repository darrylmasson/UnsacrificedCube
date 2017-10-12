#include <Randomize.hh>

#include <sys/time.h>

#include "PurdueAnalysisManager.hh"

#include "PurdueRunAction.hh"

PurdueRunAction::PurdueRunAction(PurdueAnalysisManager *pAnalysisManager)
{
  m_hRanSeed         = 0; //12345; // default value
  //m_pMessenger       = new PurdueRunActionMessenger(this);
  
  m_pAnalysisManager = pAnalysisManager;
  
}

PurdueRunAction::~PurdueRunAction()
{
  //delete m_pMessenger;
}

void
PurdueRunAction::BeginOfRunAction(const G4Run *pRun)
{
  if(m_pAnalysisManager) {
    m_pAnalysisManager->BeginOfRun(pRun);
  }
  
  // random seeding of the MC
  if(m_hRanSeed > 0){
    CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
    G4cout << "PurdueRunAction::BeginOfRunAction Initialize random numbers with seed = "<<m_hRanSeed<<G4endl;
    CLHEP::HepRandom::setTheSeed(m_hRanSeed);
  } else {
    // initialize with time.....
    struct timeval hTimeValue;
    gettimeofday(&hTimeValue, NULL);
    G4cout << "PurdueRunAction::BeginOfRunAction Initialize random numbers with seed = "<<hTimeValue.tv_usec<<G4endl;
    CLHEP::HepRandom::setTheSeed(hTimeValue.tv_usec);
  }
}

void
PurdueRunAction::EndOfRunAction(const G4Run *pRun)
{
  if(m_pAnalysisManager)
    m_pAnalysisManager->EndOfRun(pRun);
}

