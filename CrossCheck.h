//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar  9 12:42:21 2016 by ROOT version 5.34/18
// from TTree skimTreehistfacFatJet_ZLight/Tree with relevant info only
// found on file: Merged_MET.root
//////////////////////////////////////////////////////////

#ifndef CrossCheck_h
#define CrossCheck_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxRun = 1;
const Int_t kMaxLumi = 1;
const Int_t kMaxEvent = 1;
const Int_t kMaxdphiMin = 1;
const Int_t kMaxnthinjets = 1;
const Int_t kMaxMT = 1;
const Int_t kMaxCSV1 = 1;
const Int_t kMaxCSV2 = 1;
const Int_t kMaxMHT = 1;
const Int_t kMaxNAddMu = 1;
const Int_t kMaxNAddEle = 1;
const Int_t kMaxNAddTau = 1;
const Int_t kMaxMinCSV = 1;
const Int_t kMaxMaxCSV = 1;
const Int_t kMaxDRSJ = 1;
const Int_t kMaxMass = 1;
const Int_t kMaxJetPhi = 1;
const Int_t kMaxJetEta = 1;
const Int_t kMaxJetCSVSum = 1;
const Int_t kMaxJetMetDPhi = 1;
const Int_t kMaxTau21 = 1;
const Int_t kMaxJetPt = 1;
const Int_t kMaxSumET = 1;
const Int_t kMaxMET = 1;
const Int_t kMaxjetCEmEF = 1;
const Int_t kMaxjetCHadEF = 1;
const Int_t kMaxjetPhoEF = 1;
const Int_t kMaxjetNEmEF = 1;
const Int_t kMaxjetNHadEF = 1;
const Int_t kMaxjetMuEF = 1;
const Int_t kMaxjetCMulti = 1;
const Int_t kMaxPUweight = 1;
const Int_t kMaxEWKweight = 1;
const Int_t kMaxMCweight = 1;
const Int_t kMaxBTAGSF = 1;

class CrossCheck {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           run_;
   Int_t           lumi_;
   Int_t           event_;
   Float_t         dphiMin_;
   Int_t           nthinjets_;
   Float_t         MT_;
   Float_t         CSV1_;
   Float_t         CSV2_;
   Float_t         MHT_;
   Int_t           NAddMu_;
   Int_t           NAddEle_;
   Int_t           NAddTau_;
   Int_t           NAddBJet;
   Float_t         MinCSV_;
   Float_t         MaxCSV_;
   Float_t         DRSJ_;
   Float_t         Mass_;
   Float_t         JetPhi_;
   Float_t         JetEta_;
   Float_t         JetCSVSum_;
   Float_t         JetMetDPhi_;
   Float_t         Tau21_;
   Float_t         JetPt_;
   Float_t         SumET_;
   Float_t         MET_;
   Float_t         jetCEmEF_;
   Float_t         jetCHadEF_;
   Float_t         jetPhoEF_;
   Float_t         jetNEmEF_;
   Float_t         jetNHadEF_;
   Float_t         jetMuEF_;
   Float_t         jetCMulti_;
   Float_t         PUweight_;
   Float_t         EWKweight_;
   Float_t         MCweight_;
   Float_t         BTAGSF_;

   // List of branches
   TBranch        *b_Run_;   //!
   TBranch        *b_Lumi_;   //!
   TBranch        *b_Event_;   //!
   TBranch        *b_dphiMin_;   //!
   TBranch        *b_nthinjets_;   //!
   TBranch        *b_MT_;   //!
   TBranch        *b_CSV1_;   //!
   TBranch        *b_CSV2_;   //!
   TBranch        *b_MHT_;   //!
   TBranch        *b_NAddMu_;   //!
   TBranch        *b_NAddEle_;   //!
   TBranch        *b_NAddTau_;   //!
   TBranch        *b_NAddBJet;   //!
   TBranch        *b_MinCSV_;   //!
   TBranch        *b_MaxCSV_;   //!
   TBranch        *b_DRSJ_;   //!
   TBranch        *b_Mass_;   //!
   TBranch        *b_JetPhi_;   //!
   TBranch        *b_JetEta_;   //!
   TBranch        *b_JetCSVSum_;   //!
   TBranch        *b_JetMetDPhi_;   //!
   TBranch        *b_Tau21_;   //!
   TBranch        *b_JetPt_;   //!
   TBranch        *b_SumET_;   //!
   TBranch        *b_MET_;   //!
   TBranch        *b_jetCEmEF_;   //!
   TBranch        *b_jetCHadEF_;   //!
   TBranch        *b_jetPhoEF_;   //!
   TBranch        *b_jetNEmEF_;   //!
   TBranch        *b_jetNHadEF_;   //!
   TBranch        *b_jetMuEF_;   //!
   TBranch        *b_jetCMulti_;   //!
   TBranch        *b_PUweight_;   //!
   TBranch        *b_EWKweight_;   //!
   TBranch        *b_MCweight_;   //!
   TBranch        *b_BTAGSF_;   //!

   CrossCheck(TTree *tree=0);
   virtual ~CrossCheck();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CrossCheck_cxx
CrossCheck::CrossCheck(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Merged_MET.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("Merged_MET.root");
      }
      f->GetObject("skimTreehistfacFatJet_ZLight",tree);

   }
   Init(tree);
}

CrossCheck::~CrossCheck()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CrossCheck::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CrossCheck::LoadTree(Long64_t entry)
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

void CrossCheck::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run_", &run_, &b_Run_);
   fChain->SetBranchAddress("lumi_", &lumi_, &b_Lumi_);
   fChain->SetBranchAddress("event_", &event_, &b_Event_);
   fChain->SetBranchAddress("dphiMin_", &dphiMin_, &b_dphiMin_);
   fChain->SetBranchAddress("nthinjets_", &nthinjets_, &b_nthinjets_);
   fChain->SetBranchAddress("MT_", &MT_, &b_MT_);
   fChain->SetBranchAddress("CSV1_", &CSV1_, &b_CSV1_);
   fChain->SetBranchAddress("CSV2_", &CSV2_, &b_CSV2_);
   fChain->SetBranchAddress("MHT_", &MHT_, &b_MHT_);
   fChain->SetBranchAddress("NAddMu_", &NAddMu_, &b_NAddMu_);
   fChain->SetBranchAddress("NAddEle_", &NAddEle_, &b_NAddEle_);
   fChain->SetBranchAddress("NAddTau_", &NAddTau_, &b_NAddTau_);
   fChain->SetBranchAddress("NAddBJet", &NAddBJet, &b_NAddBJet);
   fChain->SetBranchAddress("MinCSV_", &MinCSV_, &b_MinCSV_);
   fChain->SetBranchAddress("MaxCSV_", &MaxCSV_, &b_MaxCSV_);
   fChain->SetBranchAddress("DRSJ_", &DRSJ_, &b_DRSJ_);
   fChain->SetBranchAddress("Mass_", &Mass_, &b_Mass_);
   fChain->SetBranchAddress("JetPhi_", &JetPhi_, &b_JetPhi_);
   fChain->SetBranchAddress("JetEta_", &JetEta_, &b_JetEta_);
   fChain->SetBranchAddress("JetCSVSum_", &JetCSVSum_, &b_JetCSVSum_);
   fChain->SetBranchAddress("JetMetDPhi_", &JetMetDPhi_, &b_JetMetDPhi_);
   fChain->SetBranchAddress("Tau21_", &Tau21_, &b_Tau21_);
   fChain->SetBranchAddress("JetPt_", &JetPt_, &b_JetPt_);
   fChain->SetBranchAddress("SumET_", &SumET_, &b_SumET_);
   fChain->SetBranchAddress("MET_", &MET_, &b_MET_);
   fChain->SetBranchAddress("jetCEmEF_", &jetCEmEF_, &b_jetCEmEF_);
   fChain->SetBranchAddress("jetCHadEF_", &jetCHadEF_, &b_jetCHadEF_);
   fChain->SetBranchAddress("jetPhoEF_", &jetPhoEF_, &b_jetPhoEF_);
   fChain->SetBranchAddress("jetNEmEF_", &jetNEmEF_, &b_jetNEmEF_);
   fChain->SetBranchAddress("jetNHadEF_", &jetNHadEF_, &b_jetNHadEF_);
   fChain->SetBranchAddress("jetMuEF_", &jetMuEF_, &b_jetMuEF_);
   fChain->SetBranchAddress("jetCMulti_", &jetCMulti_, &b_jetCMulti_);
   fChain->SetBranchAddress("PUweight_", &PUweight_, &b_PUweight_);
   fChain->SetBranchAddress("EWKweight_", &EWKweight_, &b_EWKweight_);
   fChain->SetBranchAddress("MCweight_", &MCweight_, &b_MCweight_);
   fChain->SetBranchAddress("BTAGSF_", &BTAGSF_, &b_BTAGSF_);
   Notify();
}

Bool_t CrossCheck::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CrossCheck::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CrossCheck::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CrossCheck_cxx
