#include "TGraph.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH1I.h"
#include "TH2.h"
#include "TF1.h"
#include "TTree.h"
#include "TGraphErrors.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TCut.h"
#include "TApplication.h"
#include "TLegend.h"
#include <iostream>
#include <sstream>
#include "Riostream.h"
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include "TMultiGraph.h"


#include "TList.h"
#include "TKey.h"
#include "TMath.h"

void FluxMCPlots(string MCtype){
	
	const int nFiles= 25; 
	double nEvents=0;	
	
	//Define livetimes and sources
	double flux[nFiles][3], errFlux[nFiles][3];
	double xaxis[nFiles]={-700, -600, -500, -400, -300, -200, -100, -50, -40, -30, -20, -10, 0, 10, 20, 30, 40, 50, 100, 200, 300, 400, 500, 600, 700};
	double x_radians[nFiles], r_dist[nFiles];
	double errXaxis[nFiles]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double nMCFiles[nFiles]={100, 100, 100, 99, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 98, 100, 100};
	TString sDetector[3]={"Det_1", "Det_2", "Det_3"};
	TGraphErrors* gFlux[3];

	//Define arrays to be filled
	TFile* fGamma[nFiles];
	TTree* tGamma[nFiles];

	//Get the files
	fGamma[0] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDepM700mm.root", "OPEN");
	fGamma[1] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDepM600mm.root", "OPEN");
	fGamma[2] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDepM500mm.root", "OPEN");
	fGamma[3] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDepM400mm.root", "OPEN");
	fGamma[4] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDepM300mm.root", "OPEN");
	fGamma[5] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDepM200mm.root", "OPEN");
	fGamma[6] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDepM100mm.root", "OPEN");
	fGamma[7] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGSleeveZFluxM50mm.root", "OPEN");
	fGamma[8] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGSleeveZFluxM40mm.root", "OPEN");
	fGamma[9] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGSleeveZFluxM30mm.root", "OPEN");
	fGamma[10] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGSleeveZFluxM20mm.root", "OPEN");
	fGamma[11] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGSleeveZFluxM10mm.root", "OPEN");
	fGamma[12] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGSleeveFlux260mm.root", "OPEN");
	fGamma[13] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGSleeveZFlux10mm.root", "OPEN");
	fGamma[14] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGSleeveZFlux20mm.root", "OPEN");
	fGamma[15] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGSleeveZFlux30mm.root", "OPEN");
	fGamma[16] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGSleeveZFlux40mm.root", "OPEN");
	fGamma[17] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGSleeveZFlux50mm.root", "OPEN");
	fGamma[18] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDep100mm.root", "OPEN");
	fGamma[19] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDep200mm.root", "OPEN");
	fGamma[20] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDep300mm.root", "OPEN");
	fGamma[21] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDep400mm.root", "OPEN");
	fGamma[22] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDep500mm.root", "OPEN");
	fGamma[23] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDep600mm.root", "OPEN");
	fGamma[24] = new TFile("/home/jpienaa/JP_Purdue/Flux/prodata/NGZDep700mm.root", "OPEN");
	


	//Get the trees
	for (int j=0; j<nFiles; j++) tGamma[j]=(TTree*)fGamma[j]->Get("newT");
				

	//Draw the energy histograms
	for (int j=0; j<nFiles; j++){
		x_radians[j] = TMath::ATan(-xaxis[j]/260);
		r_dist[j] = TMath::Sqrt(TMath::Power(xaxis[j],2)+TMath::Power(260,2));
		cout<<"File "<<j<<": "<<x_radians[j]<<" "<<r_dist[j]<<endl;
		for (int i=0; i<3; i++){
			nEvents = 0;
			char cDetector[100];
			sprintf(cDetector, "Detector==%d",i+1);
			nEvents=tGamma[j]->GetEntries(cDetector);
			flux[j][i]=nEvents;//*TMath::Power(r_dist[j]/260, 1.3);
			nEvents=TMath::Sqrt(nEvents);
			errFlux[j][i]=nEvents;
		}
	}

	double det0[nFiles], errDet0[nFiles];
	double det1[nFiles], errDet1[nFiles];
	double det2[nFiles], errDet2[nFiles];
	double det_tot[nFiles], err_tot[nFiles];
	for (int j=0; j<nFiles; j++){
		det0[j]=flux[j][0]/nMCFiles[j]/100000;
		det1[j]=flux[j][1]/nMCFiles[j]/100000;	
		det2[j]=flux[j][2]/nMCFiles[j]/100000;
		det_tot[j]=(det0[j]+det1[j]+det2[j])/3;
		errDet0[j]=errFlux[j][0]/nMCFiles[j]/100000;
		errDet1[j]=errFlux[j][1]/nMCFiles[j]/100000;	
		errDet2[j]=errFlux[j][2]/nMCFiles[j]/100000;
		err_tot[j]=TMath::Sqrt(TMath::Power(errDet0[j],2)+TMath::Power(errDet1[j],2)+TMath::Power(errDet2[j],2));
	}

	double rel=det_tot[12];
	
	for (int j=0; j<nFiles; j++){
		det_tot[j]=det_tot[j]/rel;
		err_tot[j]=err_tot[j]/rel;
	}


	gFlux[0] =  new TGraphErrors(nFiles, x_radians, det0, errXaxis, errDet0);
	gFlux[1] =  new TGraphErrors(nFiles, x_radians, det1, errXaxis, errDet1);
	gFlux[2] =  new TGraphErrors(nFiles, x_radians, det2, errXaxis, errDet2);
	TGraphErrors* gFlux_Tot = new TGraphErrors(nFiles, x_radians, det_tot, errXaxis, err_tot);

	TLegend* leg = new TLegend(0.75, 0.7, 0.9, 0.9);
	TMultiGraph *mgFlux = new TMultiGraph();
	
	for (int i=0; i<3; i++){
		gFlux[i]->SetMarkerColor(i+1);
		gFlux[i]->SetMarkerStyle(20+i);
		leg->AddEntry(gFlux[i], sDetector[i], "p");
		//mgFlux->Add(gFlux[i]);
	}
	gFlux_Tot->SetMarkerColor(4);
	gFlux_Tot->SetMarkerStyle(23);
	mgFlux->Add(gFlux_Tot);	

	TCanvas* can = new TCanvas("c1", "c1", 40,40,820,470);
	mgFlux->Draw("AP");
	leg->Draw();

	TFile* fSave = new TFile("/home/jpienaa/JP_Purdue/Flux/MCplots.root", "UPDATE");
	gFlux_Tot->Write("Radian_Z_Tot", TObject::kOverwrite);
	/*	
	for (int i =0; i<3; i++){
		TString sWrite = sDetector[i];
		sWrite+=MCtype;
		gFlux[i]->Write(sWrite, TObject::kOverwrite);
	}
	*/

	fSave->Close();
	return;

}
