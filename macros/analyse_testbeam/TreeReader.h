//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Apr  7 10:23:44 2016 by ROOT version 6.04/06
// from TTree FRO_analysis_tree/FRO ANALYSIS TREE
// found on file: no_BLR.root
//////////////////////////////////////////////////////////

#ifndef TreeReader_h
#define TreeReader_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

class TreeReader {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          std_nb_hits;
   std::vector<unsigned int> *std_channel;
   std::vector<double>  *std_t;
   std::vector<double>  *std_r;
   std::vector<double>  *std_res;
   std::vector<double>  *std_wy;
   std::vector<double>  *std_wz;
   Bool_t          std_has_track;
   UInt_t          std_nb_track_hits;
   Double_t        std_CL;
   Double_t        std_m;
   Double_t        std_b;
   std::vector<double>  *std_d;
   UInt_t          FRO_nb_hits;
   std::vector<unsigned int> *FRO_channel;
   std::vector<double>  *FRO_t;
   std::vector<double>  *FRO_r;
   std::vector<double>  *FRO_wy;
   std::vector<double>  *FRO_wz;
   std::vector<double>  *FRO_d;

   // List of branches
   TBranch        *b_std_nb_hits;   //!
   TBranch        *b_std_channel;   //!
   TBranch        *b_std_t;   //!
   TBranch        *b_std_r;   //!
   TBranch        *b_std_res;   //!
   TBranch        *b_std_wy;   //!
   TBranch        *b_std_wz;   //!
   TBranch        *b_std_has_track;   //!
   TBranch        *b_std_nb_track_hits;   //!
   TBranch        *b_std_CL;   //!
   TBranch        *b_std_m;   //!
   TBranch        *b_std_b;   //!
   TBranch        *b_std_d;   //!
   TBranch        *b_FRO_nb_hits;   //!
   TBranch        *b_FRO_channel;   //!
   TBranch        *b_FRO_t;   //!
   TBranch        *b_FRO_r;   //!
   TBranch        *b_FRO_wy;   //!
   TBranch        *b_FRO_wz;   //!
   TBranch        *b_FRO_d;   //!

   TreeReader(TTree *tree=0);
   virtual ~TreeReader();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef TreeReader_cxx
TreeReader::TreeReader(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("no_BLR.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("no_BLR.root");
      }
      f->GetObject("FRO_analysis_tree",tree);

   }
   Init(tree);
}

TreeReader::~TreeReader()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t TreeReader::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t TreeReader::LoadTree(Long64_t entry)
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

void TreeReader::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   std_channel = 0;
   std_t = 0;
   std_r = 0;
   std_res = 0;
   std_wy = 0;
   std_wz = 0;
   std_d = 0;
   FRO_channel = 0;
   FRO_t = 0;
   FRO_r = 0;
   FRO_wy = 0;
   FRO_wz = 0;
   FRO_d = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("std_nb_hits", &std_nb_hits, &b_std_nb_hits);
   fChain->SetBranchAddress("std_channel", &std_channel, &b_std_channel);
   fChain->SetBranchAddress("std_t", &std_t, &b_std_t);
   fChain->SetBranchAddress("std_r", &std_r, &b_std_r);
   fChain->SetBranchAddress("std_res", &std_res, &b_std_res);
   fChain->SetBranchAddress("std_wy", &std_wy, &b_std_wy);
   fChain->SetBranchAddress("std_wz", &std_wz, &b_std_wz);
   fChain->SetBranchAddress("std_has_track", &std_has_track, &b_std_has_track);
   fChain->SetBranchAddress("std_nb_track_hits", &std_nb_track_hits, &b_std_nb_track_hits);
   fChain->SetBranchAddress("std_CL", &std_CL, &b_std_CL);
   fChain->SetBranchAddress("std_m", &std_m, &b_std_m);
   fChain->SetBranchAddress("std_b", &std_b, &b_std_b);
   fChain->SetBranchAddress("std_d", &std_d, &b_std_d);
   fChain->SetBranchAddress("FRO_nb_hits", &FRO_nb_hits, &b_FRO_nb_hits);
   fChain->SetBranchAddress("FRO_channel", &FRO_channel, &b_FRO_channel);
   fChain->SetBranchAddress("FRO_t", &FRO_t, &b_FRO_t);
   fChain->SetBranchAddress("FRO_r", &FRO_r, &b_FRO_r);
   fChain->SetBranchAddress("FRO_wy", &FRO_wy, &b_FRO_wy);
   fChain->SetBranchAddress("FRO_wz", &FRO_wz, &b_FRO_wz);
   fChain->SetBranchAddress("FRO_d", &FRO_d, &b_FRO_d);
   Notify();
}

Bool_t TreeReader::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void TreeReader::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t TreeReader::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef TreeReader_cxx
