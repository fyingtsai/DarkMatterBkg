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

#define m_pi         3.1415 /* pi */

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

bool TriggerStatus(string*  trigName, vector<bool> &hlt_trigResult, Int_t nsize, string TRIGNAME){
    bool triggerstate=false;
    for(size_t i=0; i<nsize;i++){
        std::string thisTrig= trigName[i];
        size_t found = thisTrig.find(TRIGNAME);
        if(found==string::npos)continue;
        triggerstate= hlt_trigResult[i];
    }
    return triggerstate;
}

static Float_t DeltaPhi(Float_t phi1, Float_t phi2){
    double result = phi1 - phi2;
    if(result>m_pi) result -= 2*m_pi;
    else if (result <= -m_pi) result += 2*m_pi ;
    else result = result;
    return result;
  }
void controlStudy(){
  for(int i=0; i<1; i++){
  string inputFile = file[i];
  TString outputFile;
  std::vector<string> infiles;

  if(inputFile.find(".root")!= std::string::npos)
    {
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("CONTROLtry_%d.root",i);
      cout << "Output file_ = " << outputFile << endl;
    }
  else{
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("CONTROLtry_%d.root",i);
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

TH1F* h_MET = new TH1F("h_MET","MET",20,0,2000);


for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
       if (jEntry % 50000 == 0)
       fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());
        if(jEntry>100)continue;
    data.GetEntry(jEntry);

/********* Filter & Trigger **********/
    Bool_t hlt_hbhet          = data.GetBool("hlt_hbhet");
    Int_t nVtx          = data.GetInt("nVtx");
    vector<bool> &trigResult = *((vector<bool>*) data.GetPtr("hlt_trigResult"));
    std::string*  trigName = data.GetPtrString("hlt_trigName");
    const Int_t nsize = data.GetPtrStringSize();

    // if(!TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET170_NoiseCleaned_") && 
       // !TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET120_PFMHT120_IDLoose_")) continue;
cout<<"passjEntry1:"<<jEntry<<endl;
    if(hlt_hbhet != 1)continue;
    if(nVtx <= 0)continue;
cout<<"passjEntry2:"<<jEntry<<endl;
/********* FatJet **********/
    TClonesArray* FatJetP4 = (TClonesArray*) data.GetPtrTObject("FATjetP4");
    Int_t nJet             = data.GetInt("FATnJet");
    vector<bool> &FATjetPassIDLoose = *((vector<bool>*) data.GetPtr("FATjetPassIDLoose"));
    vector<float> *FATsubjetSDCSV  = data.GetPtrVectorFloat("FATsubjetSDCSV");
    Float_t *FATjetPRmassL2L3Corr  = data.GetPtrFloat("FATjetPRmassL2L3Corr");
    float maxFJPt = -9999.0;
    int maxFJetIndex = -1;
    TLorentzVector maxFJet;
    for(int ij=0; ij< nJet; ij++){
        TLorentzVector* thisJet = (TLorentzVector*)FatJetP4->At(ij);
        if(thisJet->Pt() < 200)continue;
        if(fabs(thisJet->Eta()) > 2.4)continue;
        if(!FATjetPassIDLoose[ij])continue;
        if(FATsubjetSDCSV->size()<2)continue;
        if(FATsubjetSDCSV[ij][0] < 0.605)continue;
        if(FATsubjetSDCSV[ij][1] < 0.605)continue;
        if(FATjetPRmassL2L3Corr[ij]<100 || FATjetPRmassL2L3Corr[ij]>150)continue;
        if(thisJet->Pt() > maxFJPt){
            maxFJPt = thisJet->Pt();
            maxFJet = *thisJet;
            maxFJetIndex = ij;
          }
    }//FatJet
    if(maxFJetIndex == -1)continue;
cout<<"passjEntry3:"<<jEntry<<endl;
/******** ThinJet (QCD Jet) *********/
    TClonesArray* THINjetP4 = (TClonesArray*) data.GetPtrTObject("THINjetP4");
    Int_t THINnJet             = data.GetInt("THINnJet");
    vector<bool> &THINjetPassIDLoose = *((vector<bool>*) data.GetPtr("THINjetPassIDLoose"));
    float maxQCDJPt = -9999.0;
    int maxQCDJetIndex = -1;
    TLorentzVector maxQCDJet;
    for(int i=0; i<THINnJet;i++){
        TLorentzVector* thisJet = (TLorentzVector*)THINjetP4->At(i);
        if(thisJet->Pt() < 30)continue;
        if(fabs(thisJet->Eta()) > 2.4)continue;
        if(!THINjetPassIDLoose[i])continue;
        if(maxFJet.DeltaR(*thisJet)<0.8)continue;
        if(thisJet->Pt() > maxQCDJPt){
            maxQCDJPt = thisJet->Pt();
            maxQCDJet = *thisJet;
            maxQCDJetIndex = i;
          }
    }

/********** MET ***************/
    Float_t pfMetCorrPt     = data.GetFloat("pfMetCorrPt");
    Float_t pfMetCorrPhi    = data.GetFloat("pfMetCorrPhi");
    if(pfMetCorrPt < 200) continue;
cout<<"passjEntry4:"<<jEntry<<endl;
    if(DeltaPhi(maxFJet.Phi(),pfMetCorrPhi)<0.5)continue;
cout<<"passjEntry5:"<<jEntry<<endl;
    if(DeltaPhi(maxQCDJet.Phi(),pfMetCorrPhi)<0.5)continue;
    // if(fabs(maxFJet.Phi()- pfMetCorrPhi)<2.5)continue;
    // if(fabs(maxQCDJet.Phi()- pfMetCorrPhi)<2.5)continue;
cout<<"passjEntry6:"<<jEntry<<endl;
/********** ThinJet Veto ********/
    Float_t *THINjetCISVV2  = data.GetPtrFloat("THINjetCISVV2");
    int nThinJet=0;
    for(int i=0; i<THINnJet;i++){
       TLorentzVector* thisJet = (TLorentzVector*)THINjetP4->At(i);
        if(thisJet->Pt() < 30)continue;
        if(fabs(thisJet->Eta()) > 2.4)continue; 
        if(THINjetCISVV2[i] < 0.605)continue;
        if(!THINjetPassIDLoose[i])continue;
        if(maxFJet.DeltaR(*thisJet)<0.8)continue;
        nThinJet++;
    }
    if(nThinJet!=0)continue;
cout<<"passjEntry7:"<<jEntry<<endl;
/******** Ele Loop ************/
    TClonesArray* eleP4 = (TClonesArray*) data.GetPtrTObject("eleP4");
    Int_t nEle             = data.GetInt("nEle");
    vector<bool> &eleIsPassLoose = *((vector<bool>*) data.GetPtr("eleIsPassLoose"));
    int num_Ele=0;

    for(int ie=0;ie<nEle;ie++){
      TLorentzVector* thisEle = (TLorentzVector*)eleP4->At(ie);
      if(thisEle->Pt() < 10)continue;
      if(fabs(thisEle->Eta()) > 2.5)continue;
      if(!eleIsPassLoose[ie])continue;
      if(maxFJet.DeltaR(*thisEle) < 0.8)continue;
      num_Ele++;
    }//Ele loop

/******** Muon Loop ************/
    TClonesArray* muP4 = (TClonesArray*) data.GetPtrTObject("muP4");
    Int_t nMu             = data.GetInt("nMu");
    vector<bool> &isLooseMuon = *((vector<bool>*) data.GetPtr("isLooseMuon"));
    Float_t *muChHadIso  = data.GetPtrFloat("muChHadIso");
    Float_t *muNeHadIso  = data.GetPtrFloat("muNeHadIso");
    Float_t *muGamIso  = data.GetPtrFloat("muGamIso");
    int num_Mu=0;
    for(int im=0;im<nMu;im++){
      TLorentzVector* thisMu = (TLorentzVector*)muP4->At(im);
      bool iso = (muChHadIso[im]+muNeHadIso[im]+muGamIso[im])/thisMu->Pt();
      if(thisMu->Pt() < 10)continue;
      if(fabs(thisMu->Eta()) > 2.5)continue;
      if(!isLooseMuon[im])continue;
      if(iso > 0.4)continue;
      if(maxFJet.DeltaR(*thisMu) < 0.8)continue;
      num_Mu++;
    }//Muon loop

/******** Tau Loop ************/
    TClonesArray* HPSTau_4Momentum = (TClonesArray*) data.GetPtrTObject("HPSTau_4Momentum");
    Int_t HPSTau_n             = data.GetInt("HPSTau_n");
    vector<bool> &disc_decayModeFinding = *((vector<bool>*) data.GetPtr("disc_decayModeFinding"));
    vector<bool> &disc_byLooseIsolationMVA3newDMwLT = *((vector<bool>*) data.GetPtr("disc_byLooseIsolationMVA3newDMwLT"));
    int num_tau=0;

    for(int it=0;it<HPSTau_n;it++){
      TLorentzVector* thisTau = (TLorentzVector*)HPSTau_4Momentum->At(it);
      if(thisTau->Pt() < 20)continue;
      if(fabs(thisTau->Eta()) > 2.3)continue;
      if(!disc_decayModeFinding[it])continue;
      if(!disc_byLooseIsolationMVA3newDMwLT[it])continue;
      if(maxFJet.DeltaR(*thisTau) < 0.8)continue;
      num_tau++;
    }//Tau loop
if((num_Mu + num_tau + num_Ele)!=0)continue;
cout<<"passjEntry8:"<<jEntry<<endl;
h_MET->Fill(pfMetCorrPt);
Int_t lumiSection             = data.GetInt("lumiSection");
Int_t runId             = data.GetInt("runId");
Int_t eventId             = data.GetInt("eventId");
cout<<"lumiSection:"<<lumiSection<<"  runId:"<< runId<<"   eventId:"<< eventId<<endl;
countEvent++;
}//ENTRIES

cout<<"Event:"<<countEvent<<endl;
TFile* outFile = new TFile(outputFile.Data(),"recreate");
h_MET->Write();
outFile->Close();

}//files
}//.cc