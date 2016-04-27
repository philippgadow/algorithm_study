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
#include "TNtuple.h"
#include "TRandom3.h"
#include "TVector3.h"
#include "TH1.h"
#include "TF1.h"

// You need to include "SegmentTreeReader.h" by entering ".L SegmentTreeReader.C+" before executing macro!


void analyse_segment_tree(std::string output_filename, std::string input_filename, unsigned int nevents = 0){
	
	// Obtain access to tree holding data //
	TFile* inputfile = TFile::Open(input_filename.c_str());
	TTree* tree = (TTree*) inputfile->Get("segment_tree");

	SegmentTreeReader* tr = new SegmentTreeReader(tree);

	// Set Output file //
	TFile* outputfile = new TFile(output_filename.c_str(), "RECREATE");

	// Define Random number generator for smearing precise MDT measurements to RPC position resolution
	TRandom3 *r = new TRandom3(0); 

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
	double EEL_posr [2] = { 6513., 7749. };
	double EES_posz = 10276.5;
	double EES_posr [2] = { 5893., 7370. };

	double BOL_posr = 9500.;
	double BOS_posr = 10569.;
	double BML_posr = 7139.;
	double BMS_posr = 8095.;
	double BIL_posr = 4949.;
	double BIS_posr = 4550.;

	TVector3 dirZ(0.,0.,1.);
	TVector3 dir[2][8];
    // small sector direction vectors
        dir[1][0] = TVector3(0.92449,0.381206,0.000000);
        dir[1][1] = TVector3(0.380925,0.924606,0.000000);
        dir[1][2] = TVector3(-0.384073,0.923303,0.000000);
        dir[1][3] = TVector3(-0.924302,0.381661,0.000000);
        dir[1][4] = TVector3(-0.92392,-0.382585,0.000000);
        dir[1][5] = TVector3(-0.382226, -0.924069, 0.0);
        dir[1][6] = TVector3(0.381849, -0.924225, 0.0);
        dir[1][7] = TVector3(0.923726,-0.383054,0.000000);

    // large sector direction vectors
        dir[0][0] = TVector3(1.0, 0.0, 0.0);
        dir[0][1] = TVector3(0.708024,0.706188,0.000000);
        dir[0][2] = TVector3(0.0, 1.0, 0.0);
        dir[0][3] = TVector3(-0.709793,0.704411,0.000000);
        dir[0][4] = TVector3(-1.0, 0.0, 0.0);
        dir[0][5] = TVector3(-0.708382, -0.705829, 0.0);
        dir[0][6] = TVector3(0.0, -1.0, 0.0);
        dir[0][7] = TVector3(0.705727,-0.708483,0.000000);
        


	double tgc_slope_resolution = 0.005;
	double rpc_position_single_resolution = 10; // [mm]
	double rpc_position_double_resolution = 5; // [mm]

	unsigned int nb_hits_threshold = 6;

	// Definition of histograms and ntuples
	TNtuple *ntuple = new TNtuple("ntuple", "ntuple", "is_small_sector:phi_sector:pt:eta:charge:nb_hits_inner:nb_hits_middle:nb_hits_outer:m_EO:m_EM:m_BI:m_BI_calc:m_BO:m_BO_calc");

	TH1D* h_seg_m_EOL_minus_seg_m_EML = new TH1D(\
		"h_seg_m_EOL_minus_seg_m_EML", ";m_{EOL} - m_{EML}", 2000, -0.1,0.1);
	TH1D* h_seg_m_EOS_minus_seg_m_EMS = new TH1D(\
		"h_seg_m_EOS_minus_seg_m_EMS", ";m_{EOS} - m_{EMS}", 2000, -0.1,0.1);

	TH1D* h_seg_m_BIL_calc_minus_seg_m_BIL = new TH1D(\
"h_seg_m_BIL_calc_minus_seg_m_BIL", ";m_{BIL} - m_{BIL, calc}", 1000, -.5,.5);
	TH1D* h_seg_m_BIS_calc_minus_seg_m_BIS = new TH1D(\
"h_seg_m_BIS_calc_minus_seg_m_BIS", ";m_{BIS} - m_{BIS, calc}", 1000, -.5,.5);

	TH1D* h_seg_m_BOL_calc_minus_seg_m_BOL = new TH1D(\
"h_seg_m_BOL_calc_minus_seg_m_BOL", ";m_{BOL} - m_{BOL, calc}", 1000, -.5,.5);
	TH1D* h_seg_m_BOS_calc_minus_seg_m_BOS = new TH1D(\
"h_seg_m_BOS_calc_minus_seg_m_BOS", ";m_{BOS} - m_{BOS, calc}", 1000, -.5,.5);


	// Event loop //
	if (nevents == 0){
		nevents = tree->GetEntriesFast();
	}
	
	for (int i = 0; i < nevents; ++i){
		
		tr->GetEntry(i);

		// high quality muon segment - cuts
		// require exactly 1 muon
		if (tr->muons_per_event != 1){
			continue;
		}
		// require 1 outer segment
		if (tr->small_chamber_outer->size() == 0 || \
			tr->seg_phi_index_outer->size() == 0 || \
			tr->pt->size() == 0 || \
			tr->eta->size() == 0){
			continue;
		}


		// read position and direction information from event
		unsigned int is_small_sector = tr->small_chamber_outer->at(0);
		unsigned int phi_sector = tr->seg_phi_index_outer->at(0);
		double eta = tr->eta->at(0);
        double pt = tr->pt->at(0);
        double charge = tr->charge->at(0);
        
        unsigned int nb_hits_inner = 0;
        unsigned int nb_hits_middle = 0;
        unsigned int nb_hits_outer = 0;

        double slope_EO = 0.;
        double slope_EM = 0.;

        double slope_inner = 0.;
        double slope_inner_calc = 0.;
        double slope_outer = 0.;
        double slope_outer_calc = 0.;

        if(tr->nb_hits_inner->size()>0){
        	nb_hits_inner = tr->nb_hits_inner->at(0);
        }

        if(tr->nb_hits_middle->size()>0){
        	nb_hits_middle = tr->nb_hits_middle->at(0);
        }

        if(tr->nb_hits_outer->size()>0){
        	nb_hits_outer = tr->nb_hits_outer->at(0);
        }

        
		// 0.) determine endcap outer resolution
		// only consider track segments with 
		// sufficient number of hits,
		// only take tracks in end-cap
		if(abs(eta) > 1.05){
			if(tr->nb_middle_segments == 1 &&
			   tr->nb_outer_segments == 1){
				
					
                TVector3 dir_sector = dir[is_small_sector][phi_sector];

                TVector3 dir_global_middle(tr->seg_dir_middle_x->at(0),
                                    	   tr->seg_dir_middle_y->at(0),
                                    	   tr->seg_dir_middle_z->at(0));

                TVector3 dir_global_outer(tr->seg_dir_outer_x->at(0),
                                    	  tr->seg_dir_outer_y->at(0),
                                    	  tr->seg_dir_outer_z->at(0));
                
                TVector3 pos_global_middle(tr->seg_pos_middle_x->at(0),
                                    	   tr->seg_pos_middle_y->at(0),
                                    	   tr->seg_pos_middle_z->at(0));

                TVector3 pos_global_outer(tr->seg_pos_outer_x->at(0),
                                    	  tr->seg_pos_outer_y->at(0),
                                    	  tr->seg_pos_outer_z->at(0));
                        

				slope_EO = (dir_global_middle*dir_sector)/\
								  (dir_global_middle.Z());
				slope_EM = (dir_global_outer*dir_sector)/\
								  (dir_global_outer.Z());
				if (nb_hits_middle >= nb_hits_threshold &&
					nb_hits_outer >= nb_hits_threshold && pt > 10){
					if (is_small_sector){
						h_seg_m_EOS_minus_seg_m_EMS->Fill(charge*(slope_EO-slope_EM));
					}
					else{
						h_seg_m_EOL_minus_seg_m_EML->Fill(charge*(slope_EO-slope_EM));
					}
				}
			}
		}

		// 1.) determine rpc resolution in barrel inner
		if(abs(eta) < 1.05){
			if(tr->nb_inner_segments == 1){
									
				TVector3 dir_sector = dir[is_small_sector][phi_sector];

                TVector3 dir_global_inner(tr->seg_dir_inner_x->at(0),
                                    	  tr->seg_dir_inner_y->at(0),
                                    	  tr->seg_dir_inner_z->at(0));
                
                TVector3 pos_global_inner(tr->seg_pos_inner_x->at(0),
                                    	  tr->seg_pos_inner_y->at(0),
                                    	  tr->seg_pos_inner_z->at(0));

                slope_inner = (dir_global_inner*dir_sector)/\
                    		  (dir_global_inner.Z());
                double ri = pos_global_inner*dir_sector;
                        
                // compute collision vertex
                double z0_inner  = pos_global_inner.Z() - 
                   					(ri / slope_inner);
				// smear position measurement of MDT
                double z_inner = r->Gaus(pos_global_inner.Z(),\
                	rpc_position_single_resolution);
                // calculate slope
                slope_inner_calc = ri/(z_inner - z0_inner);
                if (tr->nb_hits_inner->at(0) > nb_hits_threshold && pt > 10){
                if(!(phi_sector == 5 || phi_sector == 6 || phi_sector == 7)){
					if (is_small_sector){
						h_seg_m_BIL_calc_minus_seg_m_BIL->Fill(\
							charge*(slope_inner_calc-slope_inner));
					}
					else{
						h_seg_m_BIS_calc_minus_seg_m_BIS->Fill(\
							charge*(slope_inner_calc-slope_inner));
					}
				}
			}}
		}

		// 2.) determine rpc resolution in barrel outer
		if(abs(eta) < 1.05){
			if(tr->nb_middle_segments == 1 &&
			   tr->nb_outer_segments == 1){
									
				TVector3 dir_sector = dir[is_small_sector][phi_sector];

                                    
                TVector3 pos_global_middle(tr->seg_pos_middle_x->at(0),
                                    	   tr->seg_pos_middle_y->at(0),
                                    	   tr->seg_pos_middle_z->at(0));
                                    
                TVector3 pos_global_outer(tr->seg_pos_outer_x->at(0),
                                    	  tr->seg_pos_outer_y->at(0),
                                    	  tr->seg_pos_outer_z->at(0));

                TVector3 dir_global_outer(tr->seg_dir_outer_x->at(0),
                                    	  tr->seg_dir_outer_y->at(0),
                                    	  tr->seg_dir_outer_z->at(0));

                    
                                        
                slope_outer = (dir_global_outer*dir_sector)/\
                					 (dir_global_outer.Z());
                    
                double rm = pos_global_middle*dir_sector;
                double ro = pos_global_outer*dir_sector;
                        
				// smear position measurement of MDT
                double z_middle = r->Gaus(pos_global_middle.Z(),\
                	rpc_position_double_resolution);
                double z_outer = r->Gaus(pos_global_outer.Z(),\
                	rpc_position_single_resolution);
                // calculate slope
                slope_outer_calc = (ro - rm)/(z_outer - z_middle);
                if (tr->nb_hits_middle->at(0) > nb_hits_threshold &&
					tr->nb_hits_outer->at(0) > nb_hits_threshold && pt > 10){
					if (is_small_sector){
						h_seg_m_BOL_calc_minus_seg_m_BOL->Fill(\
							charge*(slope_outer_calc-slope_outer));
					}
					else{
						h_seg_m_BOS_calc_minus_seg_m_BOS->Fill(\
							charge*(slope_outer_calc-slope_outer));
					}
				}
			}
		}

		ntuple->Fill(is_small_sector, phi_sector, pt, eta, charge,
				 nb_hits_inner, nb_hits_middle, nb_hits_outer,
				 slope_EO, slope_EM, slope_inner, slope_inner_calc, 
				 slope_outer, slope_outer_calc);

	}

	


	// Write histograms to file
	outputfile->Write();
	outputfile->Close();

	return;
}