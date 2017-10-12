// Root script
// Ntuple to histogram

#include "TFile.h"
#include "TH1F.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TLegend.h"
#include <iostream>
#include "TChain.h"
#include <string>
#include <sstream>

using namespace std;

void PlotAll(string filename) 
{
  TChain chain("newT");
  string path = "~/JP_Purdue/Energy";
  string file_end = "_processed.root";
  for(int j=0; j<1000; ++j)
    {
      string string_index;
      //ostringstream convert;
      //convert<<j;
      //string_index =convert.str();
      char buffer[8];
      sprintf(buffer, "%05d", j);
      string_index = buffer;
      string file = path+filename+"_"+string_index+file_end;
      char file_read[100];
      strcpy(file_read, file.c_str());
      chain.Add(file_read);
    }
  
  // Get the Ntuples
  //float energy_obs;
  //float energy_act;
  double energy_diff;

  TCanvas *c1 = new TCanvas("c1","c1");

  //Deactivate all branches
  chain.SetBranchStatus("*",0); 

  //Reactivate the branches of interest
  //tree1->SetBranchStatus("EnergyAct",1);
  //tree1->SetBranchStatus("EnergyObs",1);
  chain.SetBranchStatus("EnergyDiff",1);
  
  //tree1->SetBranchAddress("EnergyAct", &energy_act); 
  //tree1->SetBranchAddress("EnergyObs", &energy_obs);
  chain.SetBranchAddress("EnergyDiff", &energy_diff);
  cout <<"There are "<< chain.GetEntries() <<" entries in the chain" <<endl;

  // Define a histogram 
  int nbins(250);
  double energydifflow(-0.5);
  double energydiffhigh(0.5);
  TH1F *energy = new TH1F("Energy", "Energy", nbins, energydifflow, energydiffhigh);
  
  for (int i = 0; i < chain.GetEntries(); ++i) 
    {
      chain.GetEvent(i);
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
