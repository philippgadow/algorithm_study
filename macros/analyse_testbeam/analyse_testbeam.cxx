// analysis macro for test beam data //
#include <vector>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TF1.h"

// You need to include "TreeReader.h" by entering ".L TreeReader.C+" before executing macro!


void analyse_testbeam(std::string output_filename, std::string input_filename){
	
	// Obtain access to tree holding data //
	TFile* inputfile = TFile::Open(input_filename.c_str());
	TTree* tree = (TTree*) inputfile->Get("FRO_analysis_tree");

	TreeReader* tr = new TreeReader(tree);

	// Set Output file //
	TFile* outputfile = new TFile(output_filename.c_str(), "RECREATE");

	// Definition of histograms //
	TH1F* h_std_m = new TH1F("h_std_m", ";slope m;Entries/0.0005", 200,-0.05,0.05);
	TH1F* h_std_b = new TH1F("h_std_b", ";intercept b;Entries", 200,280,480);

	// Definition of fit functions //
	TF1 *f_fit_h_std_m_gaus2 = new TF1("f_fit_h_std_m_gaus2","gaus(0)+gaus(3)",h_std_m->GetXaxis()->GetXmin(),
																	h_std_m->GetXaxis()->GetXmax());
		f_fit_h_std_m_gaus2->SetParameters(3000, 0, 0.002, 170, 0, 0.01);

	TF1 *f_fit_h_std_b_gaus6 = new TF1("f_fit_h_std_b_gaus6",
									   "gaus(0)+gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)",
										h_std_b->GetXaxis()->GetXmin(),
										h_std_b->GetXaxis()->GetXmax());
		f_fit_h_std_b_gaus6->SetParameter(0,200);
		f_fit_h_std_b_gaus6->SetParameter(1,356);
		f_fit_h_std_b_gaus6->SetParameter(2,9);
		f_fit_h_std_b_gaus6->SetParameter(3,460);
		f_fit_h_std_b_gaus6->SetParameter(4,375);
		f_fit_h_std_b_gaus6->SetParameter(5,8);
		f_fit_h_std_b_gaus6->SetParameter(6,650);
		f_fit_h_std_b_gaus6->SetParameter(7,392);
		f_fit_h_std_b_gaus6->SetParameter(8,11);
		f_fit_h_std_b_gaus6->SetParameter(9,478);
		f_fit_h_std_b_gaus6->SetParameter(10,415);
		f_fit_h_std_b_gaus6->SetParameter(11,7);
		f_fit_h_std_b_gaus6->SetParameter(12,300);
		f_fit_h_std_b_gaus6->SetParameter(13,430);
		f_fit_h_std_b_gaus6->SetParameter(14,8);
		f_fit_h_std_b_gaus6->SetParameter(15,25);
		f_fit_h_std_b_gaus6->SetParameter(16,394);
		f_fit_h_std_b_gaus6->SetParameter(17,25);


	// Event loop //
	unsigned int nevents = tree->GetEntries("std_has_track");
	unsigned count = 0;
	for (int i = 0; count < nevents; ++i){
		
		tr->GetEntry(i);

		if (tr->std_has_track == 0){
			continue;
		}

		++count;


		// Fill histograms //
		h_std_m->Fill(tr->std_m);
		h_std_b->Fill(tr->std_b);
	}

	// Fit histograms //
	h_std_m->Fit(f_fit_h_std_m_gaus2);
	h_std_b->Fit(f_fit_h_std_b_gaus6);

	// Write histograms to file
	outputfile->Write();
	outputfile->Close();

	return;
}