#include "Riostream.h"
#include "TGraph.h"
#include "TFile.h"
#include <iostream>
#include "TNtuple.h"
#include <vector>
#include <sstream>
#include "TF1.h"
#include "TTree.h"
#include "TCanvas.h"
#include "stdlib.h"
#include "TH1D.h"
#include "TLegend.h"
#include "TMath.h"
#include "TEventList.h"

#define PI 3.14159265

//*****************************************************************************
//* This program takes a simulated root file, specified in the string input,  *
//* produced by the EnergyResolution GEANT4 MC simulation, and searches it for*
//* events which recorded a neutron scatter in both the first and second EJ301*
//* detectors.                                                                *
//*                                                                           *
//* The position of the first detector (in the y-direction), the seperation of*
//* the detectors, and the angle from the positive y axis, are given as double*
//* arguments in the input.                                                   *
//*****************************************************************************

using namespace std;

void usage();

int main(int argc, char **argv)
{
  cout<<"Starting"<<endl;

  // Switches
  int c = 0;
  
  stringstream hStream;
	
  double angle(0.);
  double seperation(20.);
  double detector1(80.);
  string filename;
  
  //Parse switches
  while((c = getopt(argc,argv,"p:d:s:a:")) != -1)
    {
      switch(c)	
	{       
	case 'p':
	  filename = optarg;
	  cout<<"Found the file: "<<filename<<endl;
	  break;

	case 'd':
	  hStream.str(optarg);
	  hStream.clear();
	  hStream >> detector1;
	  break;
	  
	case 's':
	  hStream.str(optarg);
	  hStream.clear();
	  hStream >> seperation;
	  break;

	case 'a':
	  hStream.str(optarg);
	  hStream.clear();
	  hStream >> angle;
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
  string inputpath = "/scratch/lustreC/j/jpienaa/Energy/"; 
  string outputpath = "~/JP_Purdue/Energy/";

  //Name of input and output files
  string inputfile = inputpath + filename + ".root";
  string outputfile = outputpath + filename + "_processed.root";
  char filein[100];
  char fileout[100];
  strcpy(filein, inputfile.c_str());
  strcpy(fileout, outputfile.c_str());
 
  //-------------------------------Variables------------------------------------
  
  //Declare (and initialise) variables to be used 
  int entries = 0;                        //Number of Entries in the tree
  int eventsofinterest = 0;               //Events that double scattered
  double distance = 0;                    //Distance traveled between scatters
  double time = 0;                        //Time travelled between scatters
  double energy_obs =0;                   //Observed Energy
  double velocity_obs=0;                  //Observed Velocity
  double energy_act =0;                   //Actual Energy
  double velocity_act=0;                  //Actual Velocity
  int firstscatter=0;                     //Number of scatters in 1st detector
  double energy_diff=0;                   //Relative Error in energy
  int detector=0;                         //Detector where event occured

  //-----------------------------------Plots------------------------------------
  //Declare the histograms to be generated.
  TH1F *Seperation = new TH1F("Distance travelled between detectors", "", 
			      250, 0.00, 1500 ); 
  TH1F *Traveltime = new TH1F("Time between detector hits","", 250, 0, 1000e-9);
  TH1F *Energy = new TH1F("Observed energy of neutrons","", 250, -0.5, 0.5);

  //---------------------------Data Processing----------------------------------
  //Event List where the selected events will be stored
  TEventList el("el","el");
  
  //Open the root file, and read in the tree
  TFile *InputTfile = new TFile(filein, "READ");
  TDirectoryFile df;
  df.Read("events");
  df.cd();
  TTree * events = new TTree();
  events->Read("events");
  entries = events->GetEntries();

  //Deactivate all branches
  events->SetBranchStatus("*",0); 

  //Reactivate the branches of interest
  events->SetBranchStatus("xp",1);
  events->SetBranchStatus("yp",1);
  events->SetBranchStatus("zp",1);
  events->SetBranchStatus("time",1);
  events->SetBranchStatus("edproc", 1);

  //Aassign variables into which the values are to be read
  vector<float>* xposition = new vector <float>;
  vector<float>* yposition = new vector <float>;
  vector<float>* zposition = new vector <float>;
  vector<float>* time_doublescatter = new vector <float>;
  vector<string>* process = new vector <string>;
  events->SetBranchAddress("xp", &xposition);
  events->SetBranchAddress("yp", &yposition);
  events->SetBranchAddress("zp", &zposition);
  events->SetBranchAddress("time", &time_doublescatter);
  events->SetBranchAddress("edproc", &process);

  //Set the ranges in which to look for events  
  double y1min, y1max, y2min, y2max =0;
  y1min = detector1 - 40.;
  y1max = detector1 + 40.;
  y2min = y1min + seperation*cos(angle*PI/180);
  y2max = y1max + seperation*cos(angle*PI/180);


  //Create output root file and tree
  TFile OutputTfile(fileout,"RECREATE");  
  TTree *tree=new TTree("newT","Source data");
  tree->Branch("EnergyAct", &energy_act);
  tree->Branch("VelocityAct", &velocity_act);
  tree->Branch("Distance" , &distance);
  tree->Branch("EnergyObs", &energy_obs);
  tree->Branch("VelocityAct", &velocity_act);
  tree->Branch("Time", &time);
  tree->Branch("EnergyDiff", &energy_diff);
  tree->Branch("DetectorNumber", &detector);
  /*  tree->Branch("Xpos", &xposition);
  tree->Branch("Ypos", &yposition);
  tree->Branch("Zpos", &zposition);*/
  
  cout<<"There are "<<entries<<" entries in the tree "<<endl;

  //==============================Data Processing===============================

  //----------------------------------Loop over Entries-------------------------
  double xpos1, ypos1, zpos1, xpos2, ypos2, zpos2 =0;
  double time1, time2=0;
  int vectorsize = 0; 
  for (int i=0; i < entries; ++i)
    {       
      bool secondhit = false;
      bool firsthit = false;      
      events->GetEntry(i);
      vectorsize = yposition->size();
     
      for (int k=0; k<vectorsize; k++)
	{
	  //Check for an event in the 2nd detector
	  if (yposition->at(k)>y2min && yposition->at(k)<y2max && xposition->at(k)>0 && process->at(k)!="Transportation")
	    {
	      //cout<<"I registered a hit in the 2nd detector"<<endl;
	      secondhit=true;
	      detector = 2;
	      xpos2=xposition->at(k);
	      ypos2=yposition->at(k);
	      zpos2=zposition->at(k);
	      time2=time_doublescatter->at(k);

	      for (int m=0; m<vectorsize; m++)
		{
		  //Check for an event in the 1st detector
		  if (yposition->at(m)>y1min && yposition->at(m)<y1max && process->at(k)!="Transportation")
		    {
		      //cout<<"I found a hit in the 1st detector as well"<<endl;
		      firsthit=true;
		      firstscatter += 1;
		      xpos1=xposition->at(m);
		      ypos1=yposition->at(m);
		      zpos1=zposition->at(m);
		      time1=time_doublescatter->at(m);
		    }
		  if (firsthit)
		    break; 
		}

	    }

	  //Check for an event in the 3rd detector
	  if (yposition->at(k)>y2min && yposition->at(k)<y2max && xposition->at(k)<0 && process->at(k)!="Transportation")
	    {
	      //cout<<"I registered a hit in the 3rd detector"<<endl;
	      secondhit=true;
	      detector = 3;
	      xpos2=xposition->at(k);
	      ypos2=yposition->at(k);
	      zpos2=zposition->at(k);
	      time2=time_doublescatter->at(k);

	      for (int m=0; m<vectorsize; m++)
		{
		  //Check for an event in the 1st detector
		  if (yposition->at(m)>y1min && yposition->at(m)<y1max && process->at(k)!="Transportation")
		    {
		      //cout<<"I found a hit in the 1st detector as well"<<endl;
		      firsthit=true;
		      firstscatter += 1;
		      xpos1=xposition->at(m);
		      ypos1=yposition->at(m);
		      zpos1=zposition->at(m);
		      time1=time_doublescatter->at(m);
		    }
		  if (firsthit)
		    break; 
		}

	    }

	  if(secondhit)
	    break;
	}
      
      if (secondhit && firsthit) 
	{
	  time = time2 - time1;
	  double xdiff = xpos2 - xpos1;
	  double ydiff = ypos2 - ypos1;
	  double zdiff = zpos2 - zpos1;
	  distance = sqrt(xdiff*xdiff + ydiff*ydiff + zdiff*zdiff);
	  velocity_act = ((distance/1000.)/time)/(299792458);
	  velocity_obs = ((seperation/1000.)/time)/(299792458);
	  energy_act = 0.5*(939.5653782)*velocity_act*velocity_act;
	  energy_obs = 0.5*(939.5653782)*velocity_obs*velocity_obs;
	  energy_diff = (energy_obs-energy_act)/energy_act;
	  Seperation->Fill(distance);
	  Traveltime->Fill(time);
	  Energy->Fill(energy_diff);
	  eventsofinterest += 1;
	  el.Enter(i);
	  
	  tree->Fill();
	  
	}
    }

  /*
  //Now do some analysis with the list
  //events->SetEventList(&el);
  for (int i=0; i<el.GetN(); ++i) 
    {
    events->GetEntry(el.GetEntry(i));
    XPosition->Fill(xposition); 
    }
  */

  //=================================Histograms=================================
  TCanvas *c1 = new TCanvas("c1", "c1");
  Seperation->SetTitle("Distance traveled by neutrons");
  Seperation->GetXaxis()->SetTitle("Distance");
  Seperation->GetYaxis()->SetTitle("Counts");
  Seperation->Draw();
  c1->Modified();
  c1->Update();

  TCanvas *c2 = new TCanvas("c2", "c2");
  Traveltime->SetTitle("Travel time of neutrons");
  Traveltime->GetXaxis()->SetTitle("Time");
  Traveltime->GetYaxis()->SetTitle("Counts");
  Traveltime->Draw();
  c2->Modified();
  c2->Update();

  TCanvas *c3= new TCanvas("c3", "c3");
  Energy->SetTitle("Energy of Observed Events");
  Energy->GetXaxis()->SetTitle("Energy");
  Energy->GetYaxis()->SetTitle("Counts");
  Energy->Draw();
  c3->Modified();
  c3->Update();

  //================================Finishing Up===============================
 
  el.Write();  
  InputTfile->Close();

  OutputTfile.Write();
  OutputTfile.Close();  
		    
}
      


  

  

