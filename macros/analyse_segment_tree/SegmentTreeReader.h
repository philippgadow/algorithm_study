//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Apr 21 16:52:55 2016 by ROOT version 6.04/06
// from TTree segment_tree/SEGMENT TREE
// found on file: segment_tree_25_ns_phase1_trigger.root
//////////////////////////////////////////////////////////

#ifndef SegmentTreeReader_h
#define SegmentTreeReader_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "string"

class SegmentTreeReader {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           lbn;
   Int_t           event;
   Int_t           muons_per_event;
   Int_t           roi_per_event;
   vector<double>  *pt;
   vector<double>  *eta;
   vector<double>  *phi;
   vector<int>     *charge;
   vector<double>  *fitChi2;
   vector<int>     *fitNumberDoF;
   vector<double>  *sa_pt;
   vector<double>  *sa_eta;
   vector<double>  *sa_phi;
   vector<double>  *sa_fitChi2;
   vector<int>     *sa_fitNumberDoF;
   Int_t           nb_inner_segments;
   Int_t           nb_middle_segments;
   Int_t           nb_outer_segments;
   Int_t           nb_extended_segments;
   vector<int>     *nb_hits_inner;
   vector<int>     *nb_hits_middle;
   vector<int>     *nb_hits_outer;
   vector<int>     *nb_hits_extended;
   vector<int>     *seg_phi_index_inner;
   vector<int>     *seg_phi_index_middle;
   vector<int>     *seg_phi_index_outer;
   vector<int>     *seg_phi_index_extended;
   vector<int>     *saddle_inner;
   vector<int>     *saddle_middle;
   vector<int>     *saddle_outer;
   vector<int>     *saddle_extended;
   vector<char>    *saddle_type_inner;
   vector<char>    *saddle_type_middle;
   vector<char>    *saddle_type_outer;
   vector<char>    *saddle_type_extended;
   vector<int>     *small_chamber_inner;
   vector<int>     *small_chamber_middle;
   vector<int>     *small_chamber_outer;
   vector<int>     *small_chamber_extended;
   vector<double>  *seg_pos_inner_x;
   vector<double>  *seg_pos_inner_y;
   vector<double>  *seg_pos_inner_z;
   vector<double>  *seg_pos_middle_x;
   vector<double>  *seg_pos_middle_y;
   vector<double>  *seg_pos_middle_z;
   vector<double>  *seg_pos_outer_x;
   vector<double>  *seg_pos_outer_y;
   vector<double>  *seg_pos_outer_z;
   vector<double>  *seg_pos_extended_x;
   vector<double>  *seg_pos_extended_y;
   vector<double>  *seg_pos_extended_z;
   vector<double>  *seg_dir_inner_x;
   vector<double>  *seg_dir_inner_y;
   vector<double>  *seg_dir_inner_z;
   vector<double>  *seg_dir_middle_x;
   vector<double>  *seg_dir_middle_y;
   vector<double>  *seg_dir_middle_z;
   vector<double>  *seg_dir_outer_x;
   vector<double>  *seg_dir_outer_y;
   vector<double>  *seg_dir_outer_z;
   vector<double>  *seg_dir_extended_x;
   vector<double>  *seg_dir_extended_y;
   vector<double>  *seg_dir_extended_z;
   string          *trig_l1_name;
   Int_t           trig_l1_passed;
   Int_t           trig_l1_tbp;
   Int_t           trig_l1_tap;
   Int_t           trig_l1_tav;
   UInt_t          trig_l1_bits;
   Int_t           trig_l1_prescale;
   Double_t        trig_l1_roi_eta;
   Double_t        trig_l1_roi_phi;
   Double_t        trig_l1_roi_deta;
   Double_t        trig_l1_roi_dphi;
   Int_t           trig_l1_roi_word;
   Int_t           trig_l1_roi_sector;
   Int_t           trig_l1_roi_source;
   Int_t           trig_l1_roi_number;
   Int_t           trig_l1_roi_thrlvl;
   Int_t           trig_l1_masked;
   vector<int>     *trig_l1_roi_match;
   string          *trig_l2_name;
   Int_t           trig_l2_passed;
   Int_t           trig_l2_raw;
   Int_t           trig_l2_through;
   Int_t           trig_l2_pre;
   Int_t           trig_l2_res;
   UInt_t          trig_l2_bits;
   Int_t           trig_l2_prescale;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lbn;   //!
   TBranch        *b_event;   //!
   TBranch        *b_muons_per_event;   //!
   TBranch        *b_roi_per_event;   //!
   TBranch        *b_pt;   //!
   TBranch        *b_eta;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_charge;   //!
   TBranch        *b_fitChi2;   //!
   TBranch        *b_fitNumberDoF;   //!
   TBranch        *b_sa_pt;   //!
   TBranch        *b_sa_eta;   //!
   TBranch        *b_sa_phi;   //!
   TBranch        *b_sa_fitChi2;   //!
   TBranch        *b_sa_fitNumberDoF;   //!
   TBranch        *b_nb_inner_segments;   //!
   TBranch        *b_nb_middle_segments;   //!
   TBranch        *b_nb_outer_segments;   //!
   TBranch        *b_nb_extended_segments;   //!
   TBranch        *b_nb_hits_inner;   //!
   TBranch        *b_nb_hits_middle;   //!
   TBranch        *b_nb_hits_outer;   //!
   TBranch        *b_nb_hits_extended;   //!
   TBranch        *b_seg_phi_index_inner;   //!
   TBranch        *b_seg_phi_index_middle;   //!
   TBranch        *b_seg_phi_index_outer;   //!
   TBranch        *b_seg_phi_index_extended;   //!
   TBranch        *b_saddle_inner;   //!
   TBranch        *b_saddle_middle;   //!
   TBranch        *b_saddle_outer;   //!
   TBranch        *b_saddle_extended;   //!
   TBranch        *b_saddle_type_inner;   //!
   TBranch        *b_saddle_type_middle;   //!
   TBranch        *b_saddle_type_outer;   //!
   TBranch        *b_saddle_type_extended;   //!
   TBranch        *b_small_chamber_inner;   //!
   TBranch        *b_small_chamber_middle;   //!
   TBranch        *b_small_chamber_outer;   //!
   TBranch        *b_small_chamber_extended;   //!
   TBranch        *b_seg_pos_inner_x;   //!
   TBranch        *b_seg_pos_inner_y;   //!
   TBranch        *b_seg_pos_inner_z;   //!
   TBranch        *b_seg_pos_middle_x;   //!
   TBranch        *b_seg_pos_middle_y;   //!
   TBranch        *b_seg_pos_middle_z;   //!
   TBranch        *b_seg_pos_outer_x;   //!
   TBranch        *b_seg_pos_outer_y;   //!
   TBranch        *b_seg_pos_outer_z;   //!
   TBranch        *b_seg_pos_extended_x;   //!
   TBranch        *b_seg_pos_extended_y;   //!
   TBranch        *b_seg_pos_extended_z;   //!
   TBranch        *b_seg_dir_inner_x;   //!
   TBranch        *b_seg_dir_inner_y;   //!
   TBranch        *b_seg_dir_inner_z;   //!
   TBranch        *b_seg_dir_middle_x;   //!
   TBranch        *b_seg_dir_middle_y;   //!
   TBranch        *b_seg_dir_middle_z;   //!
   TBranch        *b_seg_dir_outer_x;   //!
   TBranch        *b_seg_dir_outer_y;   //!
   TBranch        *b_seg_dir_outer_z;   //!
   TBranch        *b_seg_dir_extended_x;   //!
   TBranch        *b_seg_dir_extended_y;   //!
   TBranch        *b_seg_dir_extended_z;   //!
   TBranch        *b_trig_l1_name;   //!
   TBranch        *b_trig_l1_passed;   //!
   TBranch        *b_trig_l1_tbp;   //!
   TBranch        *b_trig_l1_tap;   //!
   TBranch        *b_trig_l1_tav;   //!
   TBranch        *b_trig_l1_bits;   //!
   TBranch        *b_trig_l1_prescale;   //!
   TBranch        *b_trig_l1_roi_eta;   //!
   TBranch        *b_trig_l1_roi_phi;   //!
   TBranch        *b_trig_l1_roi_deta;   //!
   TBranch        *b_trig_l1_roi_dphi;   //!
   TBranch        *b_trig_l1_roi_word;   //!
   TBranch        *b_trig_l1_roi_sector;   //!
   TBranch        *b_trig_l1_roi_source;   //!
   TBranch        *b_trig_l1_roi_number;   //!
   TBranch        *b_trig_l1_roi_thrlvl;   //!
   TBranch        *b_trig_l1_masked;   //!
   TBranch        *b_trig_l1_roi_match;   //!
   TBranch        *b_trig_l2_name;   //!
   TBranch        *b_trig_l2_passed;   //!
   TBranch        *b_trig_l2_raw;   //!
   TBranch        *b_trig_l2_through;   //!
   TBranch        *b_trig_l2_pre;   //!
   TBranch        *b_trig_l2_res;   //!
   TBranch        *b_trig_l2_bits;   //!
   TBranch        *b_trig_l2_prescale;   //!

   SegmentTreeReader(TTree *tree=0);
   virtual ~SegmentTreeReader();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SegmentTreeReader_cxx
SegmentTreeReader::SegmentTreeReader(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("segment_tree_25_ns_phase1_trigger.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("segment_tree_25_ns_phase1_trigger.root");
      }
      f->GetObject("segment_tree",tree);

   }
   Init(tree);
}

SegmentTreeReader::~SegmentTreeReader()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SegmentTreeReader::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t SegmentTreeReader::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void SegmentTreeReader::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   pt = 0;
   eta = 0;
   phi = 0;
   charge = 0;
   fitChi2 = 0;
   fitNumberDoF = 0;
   sa_pt = 0;
   sa_eta = 0;
   sa_phi = 0;
   sa_fitChi2 = 0;
   sa_fitNumberDoF = 0;
   nb_hits_inner = 0;
   nb_hits_middle = 0;
   nb_hits_outer = 0;
   nb_hits_extended = 0;
   seg_phi_index_inner = 0;
   seg_phi_index_middle = 0;
   seg_phi_index_outer = 0;
   seg_phi_index_extended = 0;
   saddle_inner = 0;
   saddle_middle = 0;
   saddle_outer = 0;
   saddle_extended = 0;
   saddle_type_inner = 0;
   saddle_type_middle = 0;
   saddle_type_outer = 0;
   saddle_type_extended = 0;
   small_chamber_inner = 0;
   small_chamber_middle = 0;
   small_chamber_outer = 0;
   small_chamber_extended = 0;
   seg_pos_inner_x = 0;
   seg_pos_inner_y = 0;
   seg_pos_inner_z = 0;
   seg_pos_middle_x = 0;
   seg_pos_middle_y = 0;
   seg_pos_middle_z = 0;
   seg_pos_outer_x = 0;
   seg_pos_outer_y = 0;
   seg_pos_outer_z = 0;
   seg_pos_extended_x = 0;
   seg_pos_extended_y = 0;
   seg_pos_extended_z = 0;
   seg_dir_inner_x = 0;
   seg_dir_inner_y = 0;
   seg_dir_inner_z = 0;
   seg_dir_middle_x = 0;
   seg_dir_middle_y = 0;
   seg_dir_middle_z = 0;
   seg_dir_outer_x = 0;
   seg_dir_outer_y = 0;
   seg_dir_outer_z = 0;
   seg_dir_extended_x = 0;
   seg_dir_extended_y = 0;
   seg_dir_extended_z = 0;
   trig_l1_name = 0;
   trig_l1_roi_match = 0;
   trig_l2_name = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lbn", &lbn, &b_lbn);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("muons_per_event", &muons_per_event, &b_muons_per_event);
   fChain->SetBranchAddress("roi_per_event", &roi_per_event, &b_roi_per_event);
   fChain->SetBranchAddress("pt", &pt, &b_pt);
   fChain->SetBranchAddress("eta", &eta, &b_eta);
   fChain->SetBranchAddress("phi", &phi, &b_phi);
   fChain->SetBranchAddress("charge", &charge, &b_charge);
   fChain->SetBranchAddress("fitChi2", &fitChi2, &b_fitChi2);
   fChain->SetBranchAddress("fitNumberDoF", &fitNumberDoF, &b_fitNumberDoF);
   fChain->SetBranchAddress("sa_pt", &sa_pt, &b_sa_pt);
   fChain->SetBranchAddress("sa_eta", &sa_eta, &b_sa_eta);
   fChain->SetBranchAddress("sa_phi", &sa_phi, &b_sa_phi);
   fChain->SetBranchAddress("sa_fitChi2", &sa_fitChi2, &b_sa_fitChi2);
   fChain->SetBranchAddress("sa_fitNumberDoF", &sa_fitNumberDoF, &b_sa_fitNumberDoF);
   fChain->SetBranchAddress("nb_inner_segments", &nb_inner_segments, &b_nb_inner_segments);
   fChain->SetBranchAddress("nb_middle_segments", &nb_middle_segments, &b_nb_middle_segments);
   fChain->SetBranchAddress("nb_outer_segments", &nb_outer_segments, &b_nb_outer_segments);
   fChain->SetBranchAddress("nb_extended_segments", &nb_extended_segments, &b_nb_extended_segments);
   fChain->SetBranchAddress("nb_hits_inner", &nb_hits_inner, &b_nb_hits_inner);
   fChain->SetBranchAddress("nb_hits_middle", &nb_hits_middle, &b_nb_hits_middle);
   fChain->SetBranchAddress("nb_hits_outer", &nb_hits_outer, &b_nb_hits_outer);
   fChain->SetBranchAddress("nb_hits_extended", &nb_hits_extended, &b_nb_hits_extended);
   fChain->SetBranchAddress("seg_phi_index_inner", &seg_phi_index_inner, &b_seg_phi_index_inner);
   fChain->SetBranchAddress("seg_phi_index_middle", &seg_phi_index_middle, &b_seg_phi_index_middle);
   fChain->SetBranchAddress("seg_phi_index_outer", &seg_phi_index_outer, &b_seg_phi_index_outer);
   fChain->SetBranchAddress("seg_phi_index_extended", &seg_phi_index_extended, &b_seg_phi_index_extended);
   fChain->SetBranchAddress("saddle_inner", &saddle_inner, &b_saddle_inner);
   fChain->SetBranchAddress("saddle_middle", &saddle_middle, &b_saddle_middle);
   fChain->SetBranchAddress("saddle_outer", &saddle_outer, &b_saddle_outer);
   fChain->SetBranchAddress("saddle_extended", &saddle_extended, &b_saddle_extended);
   fChain->SetBranchAddress("saddle_type_inner", &saddle_type_inner, &b_saddle_type_inner);
   fChain->SetBranchAddress("saddle_type_middle", &saddle_type_middle, &b_saddle_type_middle);
   fChain->SetBranchAddress("saddle_type_outer", &saddle_type_outer, &b_saddle_type_outer);
   fChain->SetBranchAddress("saddle_type_extended", &saddle_type_extended, &b_saddle_type_extended);
   fChain->SetBranchAddress("small_chamber_inner", &small_chamber_inner, &b_small_chamber_inner);
   fChain->SetBranchAddress("small_chamber_middle", &small_chamber_middle, &b_small_chamber_middle);
   fChain->SetBranchAddress("small_chamber_outer", &small_chamber_outer, &b_small_chamber_outer);
   fChain->SetBranchAddress("small_chamber_extended", &small_chamber_extended, &b_small_chamber_extended);
   fChain->SetBranchAddress("seg_pos_inner_x", &seg_pos_inner_x, &b_seg_pos_inner_x);
   fChain->SetBranchAddress("seg_pos_inner_y", &seg_pos_inner_y, &b_seg_pos_inner_y);
   fChain->SetBranchAddress("seg_pos_inner_z", &seg_pos_inner_z, &b_seg_pos_inner_z);
   fChain->SetBranchAddress("seg_pos_middle_x", &seg_pos_middle_x, &b_seg_pos_middle_x);
   fChain->SetBranchAddress("seg_pos_middle_y", &seg_pos_middle_y, &b_seg_pos_middle_y);
   fChain->SetBranchAddress("seg_pos_middle_z", &seg_pos_middle_z, &b_seg_pos_middle_z);
   fChain->SetBranchAddress("seg_pos_outer_x", &seg_pos_outer_x, &b_seg_pos_outer_x);
   fChain->SetBranchAddress("seg_pos_outer_y", &seg_pos_outer_y, &b_seg_pos_outer_y);
   fChain->SetBranchAddress("seg_pos_outer_z", &seg_pos_outer_z, &b_seg_pos_outer_z);
   fChain->SetBranchAddress("seg_pos_extended_x", &seg_pos_extended_x, &b_seg_pos_extended_x);
   fChain->SetBranchAddress("seg_pos_extended_y", &seg_pos_extended_y, &b_seg_pos_extended_y);
   fChain->SetBranchAddress("seg_pos_extended_z", &seg_pos_extended_z, &b_seg_pos_extended_z);
   fChain->SetBranchAddress("seg_dir_inner_x", &seg_dir_inner_x, &b_seg_dir_inner_x);
   fChain->SetBranchAddress("seg_dir_inner_y", &seg_dir_inner_y, &b_seg_dir_inner_y);
   fChain->SetBranchAddress("seg_dir_inner_z", &seg_dir_inner_z, &b_seg_dir_inner_z);
   fChain->SetBranchAddress("seg_dir_middle_x", &seg_dir_middle_x, &b_seg_dir_middle_x);
   fChain->SetBranchAddress("seg_dir_middle_y", &seg_dir_middle_y, &b_seg_dir_middle_y);
   fChain->SetBranchAddress("seg_dir_middle_z", &seg_dir_middle_z, &b_seg_dir_middle_z);
   fChain->SetBranchAddress("seg_dir_outer_x", &seg_dir_outer_x, &b_seg_dir_outer_x);
   fChain->SetBranchAddress("seg_dir_outer_y", &seg_dir_outer_y, &b_seg_dir_outer_y);
   fChain->SetBranchAddress("seg_dir_outer_z", &seg_dir_outer_z, &b_seg_dir_outer_z);
   fChain->SetBranchAddress("seg_dir_extended_x", &seg_dir_extended_x, &b_seg_dir_extended_x);
   fChain->SetBranchAddress("seg_dir_extended_y", &seg_dir_extended_y, &b_seg_dir_extended_y);
   fChain->SetBranchAddress("seg_dir_extended_z", &seg_dir_extended_z, &b_seg_dir_extended_z);
   fChain->SetBranchAddress("trig_l1_name", &trig_l1_name, &b_trig_l1_name);
   fChain->SetBranchAddress("trig_l1_passed", &trig_l1_passed, &b_trig_l1_passed);
   fChain->SetBranchAddress("trig_l1_tbp", &trig_l1_tbp, &b_trig_l1_tbp);
   fChain->SetBranchAddress("trig_l1_tap", &trig_l1_tap, &b_trig_l1_tap);
   fChain->SetBranchAddress("trig_l1_tav", &trig_l1_tav, &b_trig_l1_tav);
   fChain->SetBranchAddress("trig_l1_bits", &trig_l1_bits, &b_trig_l1_bits);
   fChain->SetBranchAddress("trig_l1_prescale", &trig_l1_prescale, &b_trig_l1_prescale);
   fChain->SetBranchAddress("trig_l1_roi_eta", &trig_l1_roi_eta, &b_trig_l1_roi_eta);
   fChain->SetBranchAddress("trig_l1_roi_phi", &trig_l1_roi_phi, &b_trig_l1_roi_phi);
   fChain->SetBranchAddress("trig_l1_roi_deta", &trig_l1_roi_deta, &b_trig_l1_roi_deta);
   fChain->SetBranchAddress("trig_l1_roi_dphi", &trig_l1_roi_dphi, &b_trig_l1_roi_dphi);
   fChain->SetBranchAddress("trig_l1_roi_word", &trig_l1_roi_word, &b_trig_l1_roi_word);
   fChain->SetBranchAddress("trig_l1_roi_sector", &trig_l1_roi_sector, &b_trig_l1_roi_sector);
   fChain->SetBranchAddress("trig_l1_roi_source", &trig_l1_roi_source, &b_trig_l1_roi_source);
   fChain->SetBranchAddress("trig_l1_roi_number", &trig_l1_roi_number, &b_trig_l1_roi_number);
   fChain->SetBranchAddress("trig_l1_roi_thrlvl", &trig_l1_roi_thrlvl, &b_trig_l1_roi_thrlvl);
   fChain->SetBranchAddress("trig_l1_masked", &trig_l1_masked, &b_trig_l1_masked);
   fChain->SetBranchAddress("trig_l1_roi_match", &trig_l1_roi_match, &b_trig_l1_roi_match);
   fChain->SetBranchAddress("trig_l2_name", &trig_l2_name, &b_trig_l2_name);
   fChain->SetBranchAddress("trig_l2_passed", &trig_l2_passed, &b_trig_l2_passed);
   fChain->SetBranchAddress("trig_l2_raw", &trig_l2_raw, &b_trig_l2_raw);
   fChain->SetBranchAddress("trig_l2_through", &trig_l2_through, &b_trig_l2_through);
   fChain->SetBranchAddress("trig_l2_pre", &trig_l2_pre, &b_trig_l2_pre);
   fChain->SetBranchAddress("trig_l2_res", &trig_l2_res, &b_trig_l2_res);
   fChain->SetBranchAddress("trig_l2_bits", &trig_l2_bits, &b_trig_l2_bits);
   fChain->SetBranchAddress("trig_l2_prescale", &trig_l2_prescale, &b_trig_l2_prescale);
   Notify();
}

Bool_t SegmentTreeReader::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void SegmentTreeReader::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t SegmentTreeReader::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef SegmentTreeReader_cxx
