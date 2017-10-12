#ifndef __XENON10PNEUTRONGENERATOR_H__
#define __XENON10PNEUTRONGENERATOR_H__

#include <globals.hh>
#include <vector>
#include <map>
#include <G4VUserDetectorConstruction.hh>
#include <G4LogicalVolume.hh>
#include <G4VPhysicalVolume.hh>

using std::map;

//NEUTRON GENERATOR CONSTRUCTION
//JACQUES, ANDREW
//THIS CLASS CONSTRUCTS A NEUTRON GENERATOR WITH REFERENCE TO A PARENT VOLUME

class Xenon1tNeutronGenerator : public G4VUserDetectorConstruction
{
  private:
  // The volume that the generator will be placed in
  G4LogicalVolume *m_pMotherLogicalVolume;
  // The position of the generator with respect to the mother volume
  G4double xPos, yPos, zPos;
  // The array of internal dimensions of the neutron generator
  static map<G4String, G4double> m_hGeometryParameters;
  
  //Container
  G4LogicalVolume   *m_pContainerLogicalVolume;
  G4VPhysicalVolume *m_pContainerPhysicalVolume;  
  G4LogicalVolume   *m_pWaterGlycolLogicalVolume;
  G4VPhysicalVolume *m_pWaterGlycolPhysicalVolume;

  //Bulkheads
  G4LogicalVolume   *m_pTopBulkheadLogicalVolume;
  G4VPhysicalVolume *m_pTopBulkheadPhysicalVolume;
  G4LogicalVolume   *m_pMiddleBulkheadLogicalVolume;
  G4VPhysicalVolume *m_pMiddleBulkheadPhysicalVolume;
  G4LogicalVolume   *m_pBottomBulkheadLogicalVolume;
  G4VPhysicalVolume *m_pBottomBulkheadPhysicalVolume;
  G4LogicalVolume   *m_pTempInnerLogicalVolume;
  G4VPhysicalVolume *m_pTempInnerPhysicalVolume;
  G4LogicalVolume   *m_pTempInnerRingLogicalVolume;
  G4VPhysicalVolume *m_pTempInnerRingPhysicalVolume;

  //Tubes 
  G4LogicalVolume* m_pTubeLogicalVolume;
  std::vector<G4VPhysicalVolume*> m_pTubePhysicalVolumes;

  //Cathode
  G4LogicalVolume   *m_pCathodeLogicalVolume;
  G4VPhysicalVolume *m_pCathodePhysicalVolume;

  //Getter
  G4LogicalVolume   *m_pGetterMainCylinderLogicalVolume;
  G4VPhysicalVolume *m_pGetterMainCylinderPhysicalVolume;
  G4LogicalVolume   *m_pGetterMainConeLogicalVolume;
  G4VPhysicalVolume *m_pGetterMainConePhysicalVolume;
  G4LogicalVolume   *m_pGetterMediumPipeLogicalVolume;
  G4VPhysicalVolume *m_pGetterMediumPipePhysicalVolume;
  G4LogicalVolume   *m_pGetterSmallPipeLogicalVolume;
  G4VPhysicalVolume *m_pGetterSmallPipePhysicalVolume;
  G4LogicalVolume   *m_pGetterTopPortLogicalVolume;
  G4VPhysicalVolume *m_pGetterTopPortPhysicalVolume;
  G4LogicalVolume   *m_pGetterMainCylinderGasLogicalVolume;
  G4VPhysicalVolume *m_pGetterMainCylinderGasPhysicalVolume;
  G4LogicalVolume   *m_pGetterMainConeGasLogicalVolume;
  G4VPhysicalVolume *m_pGetterMainConeGasPhysicalVolume;
  G4LogicalVolume   *m_pGetterMediumPipeGasLogicalVolume;
  G4VPhysicalVolume *m_pGetterMediumPipeGasPhysicalVolume;
  G4LogicalVolume   *m_pGetterSmallPipeGasLogicalVolume;
  G4VPhysicalVolume *m_pGetterSmallPipeGasPhysicalVolume;
  G4LogicalVolume   *m_pGetterTopPortGasLogicalVolume;
  G4VPhysicalVolume *m_pGetterTopPortGasPhysicalVolume;
  
  //Coaxial Cable
  G4LogicalVolume   *m_pCoaxialInnerConductorLogicalVolume;
  G4VPhysicalVolume *m_pCoaxialInnerConductorPhysicalVolume;
  G4LogicalVolume   *m_pCoaxialDielectricLogicalVolume;
  G4VPhysicalVolume *m_pCoaxialDielectricPhysicalVolume;
  G4LogicalVolume   *m_pCoaxialOuterConductorLogicalVolume;
  G4VPhysicalVolume *m_pCoaxialOuterConductorPhysicalVolume;
  G4LogicalVolume   *m_pCoaxialSheathLogicalVolume;
  G4VPhysicalVolume *m_pCoaxialSheathPhysicalVolume;
  G4LogicalVolume   *m_pPlexiglassTubeLogicalVolume;
  G4VPhysicalVolume *m_pPlexiglassTubePhysicalVolume;

  //Ceramic Structure
  G4LogicalVolume   *m_pCeramicPortLogicalVolume;
  G4VPhysicalVolume *m_pCeramicPortPhysicalVolume;
  G4LogicalVolume   *m_pCeramicNeckLogicalVolume;
  G4VPhysicalVolume *m_pCeramicNeckPhysicalVolume;
  G4LogicalVolume   *m_pCeramicBodyLogicalVolume;
  G4VPhysicalVolume *m_pCeramicBodyPhysicalVolume;
  G4LogicalVolume   *m_pCeramicRimLogicalVolume;
  G4VPhysicalVolume *m_pCeramicRimPhysicalVolume;
  G4LogicalVolume   *m_pCeramicBigRingLogicalVolume;
  G4VPhysicalVolume *m_pCeramicBigRingPhysicalVolume;
  G4LogicalVolume   *m_pCeramicSmallRingLogicalVolume;
  G4VPhysicalVolume *m_pCeramicSmallRingPhysicalVolume;
  G4LogicalVolume   *m_pCeramicRingNeckLogicalVolume;
  G4VPhysicalVolume *m_pCeramicRingNeckPhysicalVolume;
  G4LogicalVolume   *m_pTransformerOilLogicalVolume;
  G4VPhysicalVolume *m_pTransformerOilPhysicalVolume;
  G4LogicalVolume   *m_pCeramicNeckOilLogicalVolume;
  G4VPhysicalVolume *m_pCeramicNeckOilPhysicalVolume;
  
  //Steel Housing
  G4LogicalVolume   *m_pSteelPortLogicalVolume;
  G4VPhysicalVolume *m_pSteelPortPhysicalVolume;
  G4LogicalVolume   *m_pSteelNeckLogicalVolume;
  G4VPhysicalVolume *m_pSteelNeckPhysicalVolume;
  G4LogicalVolume   *m_pSteelBodyLogicalVolume;
  G4VPhysicalVolume *m_pSteelBodyPhysicalVolume;  
  G4LogicalVolume   *m_pDelrinPortLogicalVolume;
  G4VPhysicalVolume *m_pDelrinPortPhysicalVolume;
  G4LogicalVolume   *m_pDelrinBodyLogicalVolume;
  G4VPhysicalVolume *m_pDelrinBodyPhysicalVolume;
  
  //ReactionChamber
  G4LogicalVolume   *m_pChamberBodyLogicalVolume;
  G4VPhysicalVolume *m_pChamberBodyPhysicalVolume;
  G4LogicalVolume   *m_pFinLogicalVolume;
  std::vector<G4VPhysicalVolume*> m_pFinPhysicalVolumes; 
  G4LogicalVolume   *m_pDeuteriumLogicalVolume;
  G4VPhysicalVolume *m_pDeuteriumPhysicalVolume;
  
  public:

  Xenon1tNeutronGenerator(G4LogicalVolume *MotherLogicalVolume, 
			  double x, double y, double z);
  ~Xenon1tNeutronGenerator();
  void DefineMaterials();
  void DefineGeometryParameters();
  G4VPhysicalVolume* Construct();
  void ConstructContainer();
  void ConstructCathode();
  void ConstructBulkheads();
  void ConstructGetter();
  void ConstructCoaxialCable();
  void ConstructCeramic();
  void ConstructSteelHousing();
  void ConstructTubes();
  void ConstructReactionChamber();
  G4double GetGeometryParameter(const char *szParameter);
};

#endif //__XENON10PNEUTRONGENERATOR_H__
