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

const char* const file[7]={
 "/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151025_235712/0000/",
"/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151025_235758/0000/",
"/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151025_235853/0000/",
"/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151025_235938/0000/",
"/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151026_000033/0000/",
"/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151026_000152/0000/",
"/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151026_000238/0000/"};

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
// const char* const file[1]={
// "/data7/khurana/NCUGlobalTuples/SPRING15_ReMiniAODSIM/WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/151026_000238/0000/"};


void WJetStudy2(){
  for(int i=0; i<7; i++){
  string inputFile = file[i];
  TString outputFile;
  std::vector<string> infiles;

  if(inputFile.find(".root")!= std::string::npos)
    {
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("TEST_%i.root",i);
      cout << "Output file_ = " << outputFile << endl;
    }
  else{
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("TEST_%i.root",i);
      cout << "Output file = " << outputFile.Data() << endl;
    
    
  TSystemDirectory *base = new TSystemDirectory("root","root");
  base->SetDirectory(inputFile.data());
  TList *listOfFiles = base->GetListOfFiles();
  TIter fileIt(listOfFiles);
  TFile *fileH = new TFile();
  Long64_t nfiles=0;
      while(fileH = (TFile*)fileIt()) {
      std::string fileN = fileH->GetName();
      std::string baseString = "NCUGlobalTuples"; 
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

    TH1F* h_Nele = new TH1F("h_Nele","number of ele",10,0,10);
    TH1F* h_Nmu = new TH1F("h_Nmu","number of muon",10,0,10);
    TH1F* h_Ntau = new TH1F("h_Ntau","number of tau",10,0,10);
    TH1F* h_puCorMass = new TH1F("h_puCorMass","PRCorMass",100,0,200);

    for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
       if (jEntry % 50000 == 0)
       fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());

    data.GetEntry(jEntry);
        /********* FatJet Loop *************/
    TClonesArray* FatJetP4 = (TClonesArray*) data.GetPtrTObject("FATjetP4");
    Int_t nJet             = data.GetInt("FATnJet");
    Float_t pfMetRawPt     = data.GetFloat("pfMetRawPt");
    Float_t pfMetRawPhi    = data.GetFloat("pfMetRawPhi");
    vector<float> *FATsubjetSDCSV  = data.GetPtrVectorFloat("FATsubjetSDCSV");
    Float_t *FATjetSDmass  = data.GetPtrFloat("FATjetSDmass");
    Float_t *FATjetPRmass  = data.GetPtrFloat("FATjetPRmass");
    Float_t *FATjetPRmassL2L3Corr  = data.GetPtrFloat("FATjetPRmassL2L3Corr");
    Int_t* FATjetCharge    = data.GetPtrInt("FATjetCharge");
    vector<bool> &trigResult = *((vector<bool>*) data.GetPtr("hlt_trigResult"));
    std::string*  trigName = data.GetPtrString("hlt_trigName");
    const Int_t nsize = data.GetPtrStringSize();

    if(!TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET170_NoiseCleaned_v1")) continue;
    if(pfMetRawPt < 200) continue;
    float NmaxPt = -9999.0;
    int maxJetIndex = -1;
    TLorentzVector maxJet;
    for(int ij=0; ij< nJet; ij++){
      bool match = false;
      TLorentzVector* thisJet = (TLorentzVector*)FatJetP4->At(ij);
      if(thisJet->Pt() < 200)continue;
      if(fabs(thisJet->Eta()) > 2.4)continue;
      // if(FATsubjetSDCSV[ij] < 0.605)continue;
      if(FATjetSDmass[ij]<100 || FATjetSDmass[ij]>150)continue;
      if(fabs(thisJet->Phi()- pfMetRawPhi)<2.5)continue;
      if(FATsubjetSDCSV->size()<2)continue;
      if(FATsubjetSDCSV[ij][0] < 0.605)continue;
      if(FATsubjetSDCSV[ij][1] < 0.605)continue;
          if(thisJet->Pt() > NmaxPt){
            NmaxPt = thisJet->Pt();
            maxJet = *thisJet;
            maxJetIndex = ij;
          }
    }
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
      if(maxJet.DeltaR(*thisEle) < 0.8)continue;
      num_Ele++;
    }//Ele loop

    /******** Muon Loop ************/
    TClonesArray* muP4 = (TClonesArray*) data.GetPtrTObject("muP4");
    Int_t nMu             = data.GetInt("nMu");
    vector<bool> &isTightMuon = *((vector<bool>*) data.GetPtr("isTightMuon"));
    Float_t *muChHadIso  = data.GetPtrFloat("muChHadIso");
    Float_t *muNeHadIso  = data.GetPtrFloat("muNeHadIso");
    Float_t *muGamIso  = data.GetPtrFloat("muGamIso");
    int num_Mu=0;
    for(int im=0;im<nMu;im++){
      TLorentzVector* thisMu = (TLorentzVector*)muP4->At(im);
      bool iso = (muChHadIso[im]+muNeHadIso[im]+muGamIso[im])/thisMu->Pt();
      if(thisMu->Pt() < 10)continue;
      if(fabs(thisMu->Eta()) > 2.4)continue;
      if(!isTightMuon[im])continue;
      if(iso > 0.4)continue;
      if(maxJet.DeltaR(*thisMu) < 0.8)continue;
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
      if(fabs(thisTau->Eta()) > 2.4)continue;
      if(!disc_decayModeFinding[it])continue;
      if(!disc_byLooseIsolationMVA3newDMwLT[it])continue;
      if(maxJet.DeltaR(*thisTau) < 0.8)continue;
      num_tau++;
    }//Tau loop

    /********* ThinJet Loop *************/
    TClonesArray* THINgenjetP4 = (TClonesArray*) data.GetPtrTObject("THINgenjetP4");
    Int_t THINnJet             = data.GetInt("THINnJet");
    Float_t *THINjetCISVV2  = data.GetPtrFloat("THINjetCISVV2");
    int num_thin=0;
    for(int tj=0; tj< THINnJet; tj++){
      TLorentzVector* thisThinJet = (TLorentzVector*)THINgenjetP4->At(tj);
      if(thisThinJet->Pt() < 10)continue;
      if(fabs(thisThinJet->Eta()) > 2.5)continue;
      if(THINjetCISVV2[tj] < 0.605)continue;
      float dR = maxJet.DeltaR(*thisThinJet);
      if(dR<0.8)continue;
      num_thin++;
    }
    if(maxJetIndex == -1)continue;

    if((num_thin + num_Mu + num_tau + num_Ele)!=0)continue;
    h_puCorMass->Fill(FATjetPRmassL2L3Corr[maxJetIndex]);

    bool flag_ele=false, flag_mu=false, flag_tau=false;
    Int_t* genStFlag=data.GetPtrInt("genStFlag");
    Int_t* genParSt=data.GetPtrInt("genParSt");
    Int_t nGenPar          = data.GetInt("nGenPar");
    Int_t* genParId        = data.GetPtrInt("genParId");
    Int_t* genMomParId        = data.GetPtrInt("genMomParId");

    for (int i=0;i < nGenPar; i++){
      if((genParSt[i]==1 && abs(genParId[i]) == 11 && abs(genMomParId[i])==24) || 
         (genParSt[i]==1 && abs(genParId[i]) == 11 && abs(genMomParId[i])==11)){
        flag_ele = true;
        break;
      }
      if((genParSt[i]==1 && abs(genParId[i]) == 13 && abs(genMomParId[i])==24) || 
         (genParSt[i]==1 && abs(genParId[i]) == 13 && abs(genMomParId[i])==13)){
        flag_mu = true;
        break;
      }
      if((abs(genParId[i]) == 15 && abs(genMomParId[i])==24) || 
         (abs(genParId[i]) == 15 && abs(genMomParId[i])==15)){
        flag_tau = true;
        break;
      }
    }

// cout<<"=================="<<endl;
int nele=0,nmu=0,ntau=0;
for (int i=0;i < nGenPar; i++){
  // if(fabs(genParId[i]) ==11){
  //   if(abs(genMomParId[i])==24)cout<<"WMom_flag:"<<((genStFlag[i] >> 9 ) & 1)<<endl;
  //   if(abs(genMomParId[i])==11)cout<<"EleMom_flag:"<<((genStFlag[i] >> 9 ) & 1)<<endl;
  //   if(abs(genMomParId[i])==24 || abs(genMomParId[i])==11) cout<<"flag_mom24:"<<((genStFlag[i] >> 9 ) & 1)<<endl;
  // }
      if(flag_ele){
        if( genParSt[i] == 1 && ((genStFlag[i] >> 9 ) & 1) && fabs(genParId[i]) ==11){

      nele++;
	    }
        }
      if(flag_mu){
	      if( genParSt[i] == 1 && ((genStFlag[i] >> 9 ) & 1) && fabs(genParId[i]) ==13){

      nmu++;
      }
        }	

      if(flag_tau){
        if( genParSt[i] == 1 && ((genStFlag[i] >> 9 ) & 1) && fabs(genParId[i]) ==15){

      ntau++;
      }
        }
}

if(flag_ele)h_Nele->Fill(nele);
if(flag_mu)h_Nmu->Fill(nmu);
if(flag_tau)h_Ntau->Fill(ntau);
    }//Entries loop




TFile* outFile = new TFile(outputFile.Data(),"recreate");
h_Nele->Write();
h_Nmu->Write();
h_Ntau->Write();
h_puCorMass->Write();
outFile->Close();
}//WJetStudy
}
