#include <Randomize.hh>

#include <sys/time.h>

#include "CubeAnalysisManager.hpp"

#include "CubeRunAction.hpp"

CubeRunAction::CubeRunAction(CubeAnalysisManager *pAnalysisManager)
{
  m_hRanSeed         = 0; //12345; // default value
  //m_pMessenger       = new CubeRunActionMessenger(this);
  
  m_pAnalysisManager = pAnalysisManager;
  
}

CubeRunAction::~CubeRunAction()
{
  //delete m_pMessenger;
}

void
CubeRunAction::BeginOfRunAction(const G4Run *pRun)
{
  if(m_pAnalysisManager) {
    m_pAnalysisManager->BeginOfRun(pRun);
  }
  
  // random seeding of the MC
  if(m_hRanSeed > 0){
    CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
    G4cout << "CubeRunAction::BeginOfRunAction Initialize random numbers with seed = "<<m_hRanSeed<<G4endl;
    CLHEP::HepRandom::setTheSeed(m_hRanSeed);
  } else {
    // initialize with time.....
    struct timeval hTimeValue;
    gettimeofday(&hTimeValue, NULL);
    G4cout << "CubeRunAction::BeginOfRunAction Initialize random numbers with seed = "<<hTimeValue.tv_usec<<G4endl;
    CLHEP::HepRandom::setTheSeed(hTimeValue.tv_usec);
  }
}

void
CubeRunAction::EndOfRunAction(const G4Run *pRun)
{
  if(m_pAnalysisManager)
    m_pAnalysisManager->EndOfRun(pRun);
}

