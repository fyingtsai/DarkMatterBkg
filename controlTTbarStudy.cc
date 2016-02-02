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
#include "TakeFunctionTTbar.h"

const char* const file[1]={
    "/data7/khurana/NCUGlobalTuples/ForFang-Ying/"
// "/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151025_235712/0000/",
// "/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151025_235758/0000/",
// "/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151025_235853/0000/",
// "/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151025_235938/0000/",
// "/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151026_000033/0000/",
// "/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151026_000152/0000/",
// "/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151026_000238/0000/"
};

bool TriggerTTbarStatus(string*  trigName, vector<bool> &hlt_trigResult, Int_t nsize, string TRIGNAME){
    bool triggerstate=false;
    for(size_t i=0; i<nsize;i++){
        std::string thisTrig= trigName[i];
        size_t found = thisTrig.find(TRIGNAME);
        if(found==string::npos)continue;
        triggerstate= hlt_trigResult[i];
    }
    return triggerstate;
}

void controlTTbarStudy(){
  for(int i=0; i<1; i++){
  string inputFile = file[i];
  TString outputFile;
  std::vector<string> infiles;

  if(inputFile.find(".root")!= std::string::npos)
    {
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("output_TTbar%d.root",i);
      cout << "Output file_ = " << outputFile << endl;
    }
  else{
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("output_TTbar%d.root",i);
      cout << "Output file = " << outputFile.Data() << endl;
    
    
  TSystemDirectory *base = new TSystemDirectory("root","root");
  base->SetDirectory(inputFile.data());
  TList *listOfFiles = base->GetListOfFiles();
  TIter fileIt(listOfFiles);
  TFile *fileH = new TFile();
  Long64_t nfiles=0;
      while(fileH = (TFile*)fileIt()) {
      std::string fileN = fileH->GetName();
      // std::string baseString = "NCUGlobalTuples";
      std::string baseString = "Merged_MonoHTobb";  
        if(fileN.find("fail") != std::string::npos)continue;
        if(fileH->IsFolder()){
      std::string newDir=inputFile+fileN;
      base->SetDirectory(newDir.data());
      TList *listOfFiles2 = base->GetListOfFiles();
      TIter fileIt2(listOfFiles2);
      TFile *fileH2 = new TFile();  
          while(fileH2 = (TFile*)fileIt2()) {
        std::string fileN2 = fileH2->GetName();
            if(fileH2->IsFolder())continue;
            if(fileN2.find("fail") != std::string::npos)continue;
            if(fileN2.find(baseString) == std::string::npos)continue;
            infiles.push_back(Form("%s/%s",newDir.data(),fileN2.data()));
            nfiles++;
          }
        } 
      }
     cout << "Opened " << nfiles << " files" << endl; 
  }

TreeReader data(infiles);
setNCUStyle();
int countEvent=0;
TakeFunctionTTbar fun;

TH1F* h_MET = new TH1F("h_MET","MET",20,0,2000);


for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
       if (jEntry % 50000 == 0)
       fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());
    data.GetEntry(jEntry);

/********* Filter & Trigger **********/
    Bool_t hlt_hbhet          = data.GetBool("hlt_hbhet");
    Int_t nVtx          = data.GetInt("nVtx");
    vector<bool> &trigResult = *((vector<bool>*) data.GetPtr("hlt_trigResult"));
    std::string*  trigName = data.GetPtrString("hlt_trigName");
    const Int_t nsize = data.GetPtrStringSize();

    // if(!TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET170_NoiseCleaned_") && 
       // !TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET120_PFMHT120_IDLoose_")) continue;
    if(hlt_hbhet != 1)continue;
    if(nVtx <= 0)continue;

/********* FatJet Selection **********/
    TClonesArray* FatJetP4 = (TClonesArray*) data.GetPtrTObject("FATjetP4");
    if(fun.getFatJetIndex(data) == -1)continue;
    TLorentzVector* maxFJet = (TLorentzVector*)FatJetP4->At(fun.getFatJetIndex(data));

/********** MET cuts ***************/
    Float_t pfMetCorrPt     = data.GetFloat("pfMetCorrPt");
    Float_t pfMetCorrPhi    = data.GetFloat("pfMetCorrPhi");
    if(pfMetCorrPt < 200) continue;
    if(!fun.isPassPhiMETFJet(data,maxFJet))continue; //dPhi(FJet,MET)>2.5
    if(fabs(DeltaPhi(fun.getQCDJetTLorentz(data,maxFJet).Phi(),pfMetCorrPhi))<0.5)continue;

/****** ThinJet Veto **********/
if(fun.numThinJet(data,maxFJet) < 2)continue;

/****** Lep Veto *************/
if((fun.numEle(data,maxFJet) + fun.numMuon(data,maxFJet) + fun.numTau(data,maxFJet))!= 1)continue;

h_MET->Fill(pfMetCorrPt);
countEvent++;
}//ENTRIES

cout<<"Event:"<<countEvent<<endl;
TFile* outFile = new TFile(outputFile.Data(),"recreate");
h_MET->Write();
outFile->Close();

}//files
}//.cc