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

void usage();

int main(int argc, char **argv)
{
  cout<<"Starting"<<endl;

  // Switches
  int c = 0;
  
  stringstream hStream;
	
  double angle(0.);
  double detector2(100.);
  double detector1(100.);
  double detector3(100.);
  string filename;

  //Parse switches
  while((c = getopt(argc,argv,"p:1:2:3:")) != -1)
    {
      switch(c)	
	{       
	case 'p':
	  filename = optarg;
	  break;

	case '1':
	  hStream.str(optarg);
	  hStream.clear();
	  hStream >> detector1;
	  break;
	  
	case '2':
	  hStream.str(optarg);
	  hStream.clear();
	  hStream >> detector2;
	  break;

	case '3':
	  hStream.str(optarg);
	  hStream.clear();
	  hStream >> detector3;
	  break;

	default:
	  return 0;	  	  
	}
    }

  if(filename.empty()) filename = "Test";  
  
  
  //=============================Initialisation=================================
  
  //-------------------------------File Management------------------------------
  //The location of the simulation root file, and some variables for the output
  
  //Filepath where simulation data is stored to, and process data sent
  string inputpath = "/scratch/lustreC/j/jpienaa/Flux/"; 
  string outputpath = "/home/jpienaa/JP_Purdue/Flux/prodata/";

  TChain chain("events/events");
  string file_end = ".root";
  for(int j=0; j<100; ++j)
    {
      string string_index;
      //ostringstream convert;
      //convert<<j;
      //string_index =convert.str();
      char buffer[8];
      sprintf(buffer, "%05d", j);
      string_index = buffer;
      string file = inputpath+filename+string_index+file_end;
      char file_read[100];
      strcpy(file_read, file.c_str());
      //cout<<"Adding file "<<file_read<<endl;
      chain.Add(file_read);
    }
  
  // Get the Ntuples
  TCanvas *c1 = new TCanvas("c1","c1");

  //-------------------------------Variables------------------------------------
  
  //Deactivate all branches
  chain.SetBranchStatus("*",0); 

  //Reactivate the branches of interest
  chain.SetBranchStatus("xp",1);
  chain.SetBranchStatus("yp",1);
  chain.SetBranchStatus("zp",1);
  chain.SetBranchStatus("time",1);
  chain.SetBranchStatus("edproc", 1); 
  chain.SetBranchStatus("PreStepEnergy", 1);
  chain.SetBranchStatus("PostStepEnergy", 1);
  chain.SetBranchStatus("type", 1);
  chain.SetBranchStatus("e_pri", 1);

  //Aassign variables into which the values are to be read
  vector<float>* xposition = new vector <float>;
  vector<float>* yposition = new vector <float>;
  vector<float>* zposition = new vector <float>;
  vector<float>* epredep = new vector <float>;
  vector<float>* epostdep = new vector <float>;
  vector<float>* vertex_time = new vector <float>;
  vector<float>* energy_primary = new vector <float>;
  vector<string>* process = new vector<string>;
  vector<string>* particle_type = new vector<string>;
  chain.SetBranchAddress("xp", &xposition);
  chain.SetBranchAddress("yp", &yposition);
  chain.SetBranchAddress("zp", &zposition);
  chain.SetBranchAddress("time", &vertex_time);
  chain.SetBranchAddress("edproc", &process);
  chain.SetBranchAddress("PreStepEnergy", &epredep);
  chain.SetBranchAddress("PostStepEnergy", &epostdep);
  chain.SetBranchAddress("type", &particle_type);
  chain.SetBranchAddress("e_pri", &energy_primary);


  cout <<"Branches set"<<endl;
  cout <<"There are "<< chain.GetEntries() <<" entries in the chain" <<endl;

  //Set the ranges in which to look for events  
  double y1min, y1max, x2min, x2max, x3max, x3min=0;
  y1min = detector1 - 40.;
  y1max = detector1 + 40.;
  x2min = detector2 - 40.;
  x2max = detector2 + 40.;
  x3min = detector3 - 40.;
  x3max = detector3 + 40.;

  //Name of input and output files
  string outputfile = outputpath + filename + ".root";
  char fileout[100];
  strcpy(fileout, outputfile.c_str());
  
  //Create output root file and tree
  TFile OutputTfile(fileout,"RECREATE");  
  TTree *tree=new TTree("newT","Source data");
  double xpos, ypos, zpos, energy, energy_pri = 0.;
  int detector=0;
  tree->Branch("Xpos", &xpos);
  tree->Branch("Ypos", &ypos);
  tree->Branch("Zpos", &zpos);
  tree->Branch("Detector", &detector);
  tree->Branch("Energy", &energy);
  tree->Branch("Primary_Energy", &energy_pri);

//==============================Data Processing===============================

 //----------------------------------Loop over Entries-------------------------
  int vectorsize = 0; 
  int eventsofinterest = 0;
  int endpoint = chain.GetEntries();
  for (int i=0; i < endpoint; ++i)
    { 
      xpos, ypos, zpos, detector, energy, energy_pri = 0;
      bool hit = false;
      chain.GetEvent(i);
      vectorsize = yposition->size();
      //energy_pri = energy_primary->at(i);

      for (int m=0; m<vectorsize; m++)
	{
	  //Get the energy of the proton recoil
	  if (yposition->at(m)>y1min && yposition->at(m)<y1max  && process->at(m)!="Transportation" && particle_type->at(m) == "proton")
	    {
	      //cout<<epredep->at(m)<<endl;
	      energy = energy + epredep->at(m) - epostdep->at(m);
	   }

	  //Check for an event in the 1st detector
	  if(!hit && process->at(m)!="Transportation" && particle_type->at(m) == "neutron")
	    {
	      //Check for an event in the 1st detector
	      if (yposition->at(m)>y1min && yposition->at(m)<y1max)
		{
		  hit=true;
		  detector = 1;
		  xpos=xposition->at(m);
		  ypos=yposition->at(m);
		  zpos=zposition->at(m);
		}
	    
	      //Check for an event in the 2nd detector
	      if (xposition->at(m)>x2min && xposition->at(m)<x2max)
		{
		  hit=true;
		  detector = 2;
		  xpos=xposition->at(m);
		  ypos=yposition->at(m);
		  zpos=zposition->at(m);
		}
	      
	      //Check for an event in the 3rd detector
	      if (xposition->at(m)>x3min && xposition->at(m)<x3max)
		{
		  hit=true;
		  detector = 3;
		  xpos=xposition->at(m);
		  ypos=yposition->at(m);
		  zpos=zposition->at(m);
		}
	    }
	}
      if (hit) 
	{
	  eventsofinterest += 1;
	  //el.Enter(i);
	 } 
   tree->Fill();
      	
    }

  cout<<"There are "<<eventsofinterest<<" scattering events in the detectors."<<endl;
  /*
  // Draw variable from ntuple
  energy->GetXaxis()->SetTitle("Realative Error");
  energy->GetYaxis()->SetTitle("Number of events [Counts]");
  energy->SetTitle("Energy Resolution");
  energy->Draw(); 
  c1->Modified();
  c1->Update();  
  */
  //el.Write();  
  //InputTfile->Close();
  
  OutputTfile.Write();
  OutputTfile.Close();  
}
