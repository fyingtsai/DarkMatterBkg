#include <vector>
#include <iostream>
#include <TString.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TSystemDirectory.h>
#include <TClonesArray.h>
#include <TLorentzVector.h>
#include <TList.h>
#include "untuplizer.h"
#include <fstream>
#include <map>
#include <TFile.h>
#include "setNCUStyle.C"
#include <math.h>

const char* const file[8]={
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-600GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-800GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-1000GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-1200GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-1400GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-1700GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-2000GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-2500GeV_MA0-300GeV-runallAnalysis.root"
};


// bool TriggerStatus(string*  trigName, vector<bool> &hlt_trigResult, Int_t nsize, string TRIGNAME){
//     bool triggerstate=false;
//     for(size_t i=0; i<nsize;i++){
//         std::string thisTrig= trigName[i];
//         size_t found = thisTrig.find(TRIGNAME);
//         if(found==string::npos)continue;
//         triggerstate= hlt_trigResult[i];
//     }
//     return triggerstate;
// }

void subjStudy(){
  for(int i=0; i<1; i++)
    {
        TFile *inputFile;
        inputFile = new TFile(file[i],"READ");
        TTree *tree = (TTree*)inputFile->Get("skimTreeMonoHFatJetsPreselection_2subj");
        TString outputFile;
        outputFile = Form("output_%d.root",i);
        cout << "Output file = " << outputFile.Data() << endl;

TreeReader data(tree);
setNCUStyle();
int countEvent=0;

TH1* h_MET[1];
TString postfix;
postfix.Form("%d",i);
h_MET[i]        = new TH1F("h_MET"+postfix,"h_MET",300,0,3000);

for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
       if (jEntry % 50000 == 0)
       fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());
    data.GetEntry(jEntry);

    Float_t MinCSV_          = data.GetFloat("MinCSV_");
    Float_t Mass_          = data.GetFloat("Mass_");
    Float_t MET_          = data.GetFloat("MET_");
    Float_t JetMetDPhi_          = data.GetFloat("JetMetDPhi_");
    Float_t dphiMin_          = data.GetFloat("dphiMin_");
    Int_t NAddEle_          = data.GetInt("NAddEle_");
    Int_t NAddMu_          = data.GetInt("NAddMu_");
    Int_t NAddTau_          = data.GetInt("NAddTau_");

      if(MinCSV_<0.605)continue;
      if(Mass_<100 || 150<Mass_)continue;
      if(MET_<200)continue;
      if(JetMetDPhi_<2.5)continue;
      if(dphiMin_<0.5)continue;
      if(NAddEle_+NAddMu_+NAddTau_ != 0)continue;
      h_MET[i] ->Fill(MET_);

}//ENTRIES

TFile* outFile = new TFile(outputFile.Data(),"recreate");
h_MET[i]->Write();
outFile->Close();

}//files
}//.cc