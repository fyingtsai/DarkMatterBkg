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

const char* const file[5]={
"/data7/syu/NCUGlobalTuples/Spring15_ReMiniAODSim/9b33d00/GJets_HT-40To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/151207_150150/0000/",
"/data7/syu/NCUGlobalTuples/Spring15_ReMiniAODSim/9b33d00/GJets_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/151207_150319/0000/",
"/data7/syu/NCUGlobalTuples/Spring15_ReMiniAODSim/9b33d00/GJets_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/151207_150446/0000/",
"/data7/syu/NCUGlobalTuples/Spring15_ReMiniAODSim/9b33d00/GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/151207_150611/0000/",
"/data7/syu/NCUGlobalTuples/Spring15_ReMiniAODSim/9b33d00/GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/151207_150715/0000/"
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

void PhoJetStudy(){
  for(int i=0; i<5; i++){
  string inputFile = file[i];
  TString outputFile;
  std::vector<string> infiles;

  if(inputFile.find(".root")!= std::string::npos)
    {
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("GJ_HT_%d.root",i);
      cout << "Output file_ = " << outputFile << endl;
    }
  else{
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("GJ_HT_%d.root",i);
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

int count_Pho=0;
    TH1F* h_PtPho = new TH1F("h_PtPho","Pt of photon",50,0,500);
    TH1F* h_PtPho2 = new TH1F("h_PtPho2","Pt of photon",50,0,500);
    TH1F* h_PtPho3 = new TH1F("h_PtPho3","Pt of photon",50,0,500);
    TH1F* h_PtGenPho = new TH1F("h_PtGenPho","Pt of gen-photon",50,0,500);
    TH1F* h_PtLeadingPho = new TH1F("h_PtLeadingPho","Pt of leading photon",50,0,500);

    for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
       if (jEntry % 50000 == 0)
       fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());

    data.GetEntry(jEntry);

    /********** Photon ************/
    vector<bool> &phoIsPassTight = *((vector<bool>*) data.GetPtr("phoIsPassTight"));
    Int_t nPho             = data.GetInt("nPho");
    TClonesArray* phoP4 = (TClonesArray*) data.GetPtrTObject("phoP4");
    
    float met        = data.GetFloat("pfMetRawPt");
    float metphi     = data.GetFloat("pfMetRawPhi");    
    float metx = met*TMath::Cos(metphi);
    float mety = met*TMath::Sin(metphi);

    float NmaxPhoPt = -9999.0;
    TLorentzVector maxPho;
    for(int p=0; p< nPho; p++){
      TLorentzVector* thisPho = (TLorentzVector*)phoP4->At(p);
      if(thisPho->Pt() > NmaxPhoPt){
            NmaxPhoPt = thisPho->Pt();
            maxPho = *thisPho;
          }
    }
    h_PtLeadingPho->Fill(NmaxPhoPt);
    float gammapx = maxPho.Px();
    float gammapy = maxPho.Py();
    float llmet = sqrt( pow(metx+gammapx,2) + 
                        pow(mety+gammapy,2));

    // MET & Trigger
    vector<bool> &trigResult = *((vector<bool>*) data.GetPtr("hlt_trigResult"));
    std::string*  trigName = data.GetPtrString("hlt_trigName");
    const Int_t nsize = data.GetPtrStringSize();
    if(!TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET170_NoiseCleaned_v1")) continue;
    if(llmet < 120) continue;
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

    float NmaxPt = -9999.0;
    int maxJetIndex = -1;
    TLorentzVector maxJet;
    for(int ij=0; ij< nJet; ij++){
      bool match = false;
      TLorentzVector* thisJet = (TLorentzVector*)FatJetP4->At(ij);
      if(thisJet->Pt() < 200)continue;
      if(fabs(thisJet->Eta()) > 2.4)continue;
      if(FATjetSDmass[ij]<100 || FATjetSDmass[ij]>150)continue;
      if(fabs(thisJet->Phi()- pfMetRawPhi)<2.5)continue;
      if(FATsubjetSDCSV->size()<2)continue;
      // if(FATsubjetSDCSV[ij][0] < 0.605)continue;
      // if(FATsubjetSDCSV[ij][1] < 0.605)continue;
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

    /******* Pho Loop *********/
    for(int ig=0; ig<nPho; ig++){
        TLorentzVector* thisPho = (TLorentzVector*)phoP4->At(ig);
        if(!phoIsPassTight[ig])continue;
        h_PtPho->Fill(thisPho->Pt());
        count_Pho++;

    }


    if((num_thin + num_Mu + num_tau + num_Ele)!=0)continue;

    /****** Gen Loop ********/
    TClonesArray* genParP4 = (TClonesArray*) data.GetPtrTObject("genParP4");
    Int_t nGenPar          = data.GetInt("nGenPar");
    Int_t* genParId        = data.GetPtrInt("genParId");
    Int_t* genMomParId        = data.GetPtrInt("genMomParId");
    Int_t* genParSt        = data.GetPtrInt("genParSt");
    Int_t* genStFlag=data.GetPtrInt("genStFlag");

    for (int i=0;i < nGenPar; i++){
        TLorentzVector* thispho = (TLorentzVector*)genParP4->At(i);
        if( genParSt[i] == 1 && ((genStFlag[i] >> 9 ) & 1) && fabs(genParId[i]) ==22){
            h_PtGenPho->Fill(thispho->Pt());
        }
    }

    /******* Pho Loop *********/
    for(int ig=0; ig<nPho; ig++){
        TLorentzVector* thisPho = (TLorentzVector*)phoP4->At(ig);
        h_PtPho2->Fill(thisPho->Pt());
        if(!phoIsPassTight[ig])continue;
        h_PtPho3->Fill(thisPho->Pt());
        count_Pho++;

    }

    }//entries

cout<<"GJ_Pho:"<<count_Pho<<endl;
TFile* outFile = new TFile(outputFile.Data(),"recreate");
h_PtPho->Write();
h_PtPho2->Write();
h_PtPho3->Write();
h_PtLeadingPho->Write();
h_PtGenPho->Write();
outFile->Close();
}//files
}//.cc
