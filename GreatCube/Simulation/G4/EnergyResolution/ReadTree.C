// Root script
// Ntuple to histogram

#include "TFile.h"
#include "TH1F.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TLegend.h"
#include <iostream>

using namespace std;

void MakePlots(string filename) 
{
  string path = "~/JP_Purdue/EnergyResolution/prodata/";
  string file = path + filename + "_processed.root";
  char file_read[100];
  strcpy(file_read, file.c_str());
  
  // Get the Ntuples
  //float energy_obs;
  //float energy_act;
  double energy_diff;

  TCanvas *c1 = new TCanvas("c1","c1");

  TFile * f1 = new TFile(file_read,"ROOT");
  TTree* tree1 = (TTree*)f1->Get("newT");

   //Deactivate all branches
  tree1->SetBranchStatus("*",0); 

  //Reactivate the branches of interest
  //tree1->SetBranchStatus("EnergyAct",1);
  //tree1->SetBranchStatus("EnergyObs",1);
  tree1->SetBranchStatus("EnergyDiff",1);
  
  //tree1->SetBranchAddress("EnergyAct", &energy_act); 
  //tree1->SetBranchAddress("EnergyObs", &energy_obs);
  tree1->SetBranchAddress("EnergyDiff", &energy_diff);
  cout <<"There are "<< tree1->GetEntries() <<" entries in the tree" <<endl;

  // Define a histogram 
  int nbins(250);
  double energydifflow(-0.5);
  double energydiffhigh(0.5);
  TH1F *energy = new TH1F("Energy", "Energy", nbins, energydifflow, energydiffhigh);
  
  for (int i = 0; i < tree1->GetEntries(); ++i) 
    {
      tree1->GetEntry(i);
      energy->Fill(energy_diff);
    }

  // Draw variable from ntuple
  energy->GetXaxis()->SetTitle("Realative Error");
  energy->GetYaxis()->SetTitle("Number of events [Counts]");
  energy->SetTitle("Energy Resolution");
  energy->Draw(); 
  c1->Modified();
  c1->Update();
}
