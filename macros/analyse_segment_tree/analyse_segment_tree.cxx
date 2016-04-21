// analysis macro for segment tree data taken in period M //
// This script determines the slope resolution of RPC and TGC chambers
// based on an extrapolation from MDT chamber measurements
// which are smeared by a random number generator.
// In addition it determines an informed guess for the width of
// the EO region of interest
// All position measurements and lengths are given in mm.

#include <vector>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TRandom3.h"
#include "TH1.h"
#include "TF1.h"

// You need to include "SegmentTreeReader.h" by entering ".L SegmentTreeReader.C+" before executing macro!


void analyse_segment_tree(std::string output_filename, std::string input_filename, unsigned int nevents = 0){
	
	// Obtain access to tree holding data //
	TFile* inputfile = TFile::Open(input_filename.c_str());
	TTree* tree = (TTree*) inputfile->Get("FRO_analysis_tree");

	SegmentTreeReader* tr = new SegmentTreeReader(tree);

	// Set Output file //
	TFile* outputfile = new TFile(output_filename.c_str(), "RECREATE");

	// Definition of geometrical parameters
	double EOL_posz = 21404.5;
	double EOL_posr [6] = { 2770., 4485., 6200., 7675., 9150., 10625. };
	double EOS_posz = 21820.5;
	double EOS_posr [6] = { 2770., 4485., 6200., 7915., 9390., 10865. };
	double EML_posz = 14294.5;
	double EML_posr [5] = { 1770., 3485., 5440., 7395., 9350. };
	double EMS_posz = 13878.5;
	double EMS_posr [5] = { 1770., 3725., 5680., 7635., 9590. };
	double EEL_posz = 11322.5;
	double EEL_posr [2] = { 6513., 7749.7. };
	double EES_posz = 10276.5;
	double EES_posr [2] = { 5893., 7370. };

	double BOL_posr [6] = { 2770., 4485., 6200., 7675., 9150., 10625. };

	// Event loop //
	if (nevents == 0){
		nevents = tree->GetEntriesFast();
	}
	
	for (int i = 0; i < nevents; ++i){
		
		tr->GetEntry(i);

		
	}


	// Write histograms to file
	outputfile->Write();
	outputfile->Close();

	return;
}