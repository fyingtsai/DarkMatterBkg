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

void WJetStudy(string inputFile){

  TString outputFile;
  std::vector<string> infiles;

  if(inputFile.find(".root")!= std::string::npos)
    {
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("WJet%s.root",endfix.Data());
      cout << "Output file_ = " << outputFile << endl;
    }
  else{
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("WJet%s.root",endfix.Data());
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

    TH1F* h_dRWJet = new TH1F("h_dRWJet","dR(fatJet, genW)",10,0,5);
    TH1F* h_dREleJet = new TH1F("h_dREleJet","dR(fatJet, genEle)",10,0,5);
    TH1F* h_dRMuJet = new TH1F("h_dRMuJet","dR(fatJet, genMu)",10,0,5);
    TH1F* h_dRTauJet = new TH1F("h_dRTauJet","dR(fatJet, genTau)",10,0,5);
    TH1F* h_PtEle = new TH1F("h_PtEle","Pt of genEle",50,0,200);
    TH1F* h_PtMu = new TH1F("h_PtMu","Pt of genMu",50,0,200);
    TH1F* h_PtTau = new TH1F("h_PtTau","Pt of genTau",50,0,200);
    TH1F* h_EtaEle = new TH1F("h_EtaEle","Eta of genEle",10,0,5);
    TH1F* h_EtaMu = new TH1F("h_EtaMu","Eta of genMu",10,0,5);
    TH1F* h_EtaTau = new TH1F("h_EtaTau","Eta of genTau",10,0,5);
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
    Float_t *FATjetCISVV2  = data.GetPtrFloat("FATjetCISVV2");
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
      if(FATjetCISVV2[ij] < 0.605)continue;
      if(FATjetSDmass[ij]<100 || FATjetSDmass[ij]>150)continue;
      if(fabs(thisJet->Phi()- pfMetRawPhi)<2.5)continue;
          if(thisJet->Pt() > NmaxPt){
                   NmaxPt = thisJet->Pt();
                   maxJet = *thisJet;
                   maxJetIndex = ij;
          }
    }
    if(maxJetIndex == -1)continue;

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
      if(fabs(thisTau->Eta()) > 2.5)continue;
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


    /****** Gen Loop ********/
    TClonesArray* genParP4 = (TClonesArray*) data.GetPtrTObject("genParP4");
    Int_t nGenPar          = data.GetInt("nGenPar");
    Int_t* genParId        = data.GetPtrInt("genParId");
    Int_t* genMomParId        = data.GetPtrInt("genMomParId");
    Int_t* genParSt        = data.GetPtrInt("genParSt");
    TLorentzVector genW;
    for (int i=0;i < nGenPar; i++){
        if(abs(genParId[i]) == 24){
          // cout<<"status:"<<genParSt[i]<<endl;
            TLorentzVector* thisW = (TLorentzVector*)genParP4->At(i);
            h_dRWJet->Fill(thisW->DeltaR(maxJet));
        }
        if(abs(genParId[i]) == 11){
          if(genParSt[i]!=1)continue;
          if(genMomParId[i]!=24 && genMomParId[i]!=11)continue;
            TLorentzVector* thisEle = (TLorentzVector*)genParP4->At(i);
            h_dREleJet->Fill(thisEle->DeltaR(maxJet));
            h_PtEle->Fill(thisEle->Pt());
            h_EtaEle->Fill(thisEle->Eta());
        }
        if(abs(genParId[i]) == 13){
          if(genParSt[i]!=1)continue;
          if(genMomParId[i]!=24 && genMomParId[i]!=13)continue;
            TLorentzVector* thisMu = (TLorentzVector*)genParP4->At(i);
            h_dRMuJet->Fill(thisMu->DeltaR(maxJet));
            h_PtMu->Fill(thisMu->Pt());
            h_EtaMu->Fill(thisMu->Eta());
        }
        if(abs(genParId[i]) == 15){
          if(genParSt[i]!=1)continue;
          if(genMomParId[i]!=24 && genMomParId[i]!=15)continue;
            TLorentzVector* thisTau = (TLorentzVector*)genParP4->At(i);
            h_dRTauJet->Fill(thisTau->DeltaR(maxJet));
            h_PtTau->Fill(thisTau->Pt());
            h_EtaTau->Fill(thisTau->Eta());
        }
    }

    }//Entries loop

TFile* outFile = new TFile(outputFile.Data(),"recreate");
h_dRWJet->Write();
h_dREleJet->Write();
h_dRMuJet->Write();
h_dRTauJet->Write();
h_PtEle->Write();
h_EtaEle->Write();
h_PtMu->Write();
h_EtaMu->Write();
h_PtTau->Write();
h_EtaTau->Write();
h_puCorMass->Write();
outFile->Close();
}
