#ifndef __PURDUEEVENTDATA_H__
#define __PURDUEEVENTDATA_H__

#include <string>
#include <vector>

using std::string;
using std::vector;

class PurdueEventData
{
public:
	 PurdueEventData();
	~PurdueEventData();

public:
	void Clear();

public:
	int m_iEventId;				// the event ID
	int m_iNbEljenDetectorHits;		// number of pmt hits
	vector<int> *m_pEljenHits;		// number of photon hits per pmt
				float m_fTotalEnergyDeposited;				// total energy deposited in the ScintSD
	int m_iNbSteps;				// number of energy depositing steps
	vector<int> *m_pTrackId;		// id of the particle
	vector<int> *m_pParentId;		// id of the parent particle
	vector<string> *m_pParticleType;	// type of particle
	vector<string> *m_pParentType;		// type of particle
	vector<string> *m_pCreatorProcess;	// interaction
	vector<string> *m_pDepositingProcess;	// energy depositing process
	vector<float> *m_pX;			// position of the step
	vector<float> *m_pY;
	vector<float> *m_pZ;
	vector<float> *m_pEnergyDeposited; 	// energy deposited in the step
	vector<float> *m_pKineticEnergy;	// track kinetic energy	
		vector<float> *m_pPreStepEnergy;	// pre-step particle energy	
				vector<float> *m_pPostStepEnergy;	// post-step particle energy
	vector<float> *m_pTime;			// time of the step
	vector<string> *m_pPrimaryParticleType;	// type of particle
	float m_fPrimaryX;			// position of the primary particle
	float m_fPrimaryY;
	float m_fPrimaryZ;	
	float m_fForcedPrimaryX;		// position of the primary particle
	float m_fForcedPrimaryY;
	float m_fForcedPrimaryZ;	
	float m_fPrimaryE;	
	float m_fPrimaryW;	
};

#endif 

