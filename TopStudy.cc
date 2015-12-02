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
#include "IndexFunction.h"

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

bool is2Jets(int index, int d1, int d2){
  bool flag = false;
  if(abs(d1) <=6 && abs(d1)!=0) flag = true;
  if(flag){
    if(abs(d2) <=6 && abs(d2)!=0) return true;
  }
  return false;
}
bool is1lep1nu(int index, int d1, int d2){
  bool flag = false;
  if(abs(d1) == 11 || abs(d1) == 13 || abs(d1) ==15) flag = true;
  if(flag){
    if(abs(d2) == 12 || abs(d2) == 14 || abs(d2) ==16) return true;
  }
  return false;
}

bool is1Nu1Lep(int index, int d1, int d2){
  bool flag = false;
  if(abs(d2) == 11 || abs(d2) == 13 || abs(d2) ==15) flag = true;
  if(flag){
    if(abs(d1) == 12 || abs(d1) == 14 || abs(d1) ==16) return true;
  }
  return false;
}

void TopStudy(string inputFile){

  TString outputFile;
  std::vector<string> infiles;

  if(inputFile.find(".root")!= std::string::npos)
    {
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("ttbar_1%s.root",endfix.Data());
      cout << "Output file_ = " << outputFile << endl;
    }
  else{
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("ttbar_1%s.root",endfix.Data());
      cout << "Output file = " << outputFile.Data() << endl;
    
    
  TSystemDirectory *base = new TSystemDirectory("root","root");
  base->SetDirectory(inputFile.data());
  TList *listOfFiles = base->GetListOfFiles();
  TIter fileIt(listOfFiles);
  TFile *fileH = new TFile();
  Long64_t nfiles=0;
      while(fileH = (TFile*)fileIt()) {
      std::string fileN = fileH->GetName();
      std::string baseString = "NCUGlobal"; 
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

    TH1F* h_genElePt = new TH1F("h_genElePt","genEle Pt",100,0,1000);
    TH1F* h_genEleEta = new TH1F("h_genEleEta","genEle Eta",100,-5,5);
    TH1F* h_recoElePt = new TH1F("h_recoElePt","recoEle Pt",100,0,1000);
    TH1F* h_recoEleEta = new TH1F("h_recoEleEta","recoEle Eta",100,-5,5);
    TH1F* h_recoElePt_match = new TH1F("h_recoElePt_match","recoEle_match Pt",100,0,1000);
    TH1F* h_recoEleEta_match = new TH1F("h_recoEleEta_match","recoEle_match Eta",100,-5,5);
    TH1F* h_fatjetPt = new TH1F("h_fatjetPt","fatJet Pt",100,0,1000);
    TH1F* h_fatjetEta = new TH1F("h_fatjetEta","fatJet Eta",100,-5,5);
    TH1F* h_recoBPt = new TH1F("h_recoBPt","recoJet Pt",100,0,1000);
    TH1F* h_recoBEta = new TH1F("h_recoBEta","recoJet Eta",100,-5,5);
    TH1F* h_dR_recoM = new TH1F("h_dR_recoM","dR(ele,b) at reco with gen-matching",20,0,4);
    TH1F* h_dR1_reco = new TH1F("h_dR1_reco","dR(ele,b) at reco for same top",20,0,4);
    TH1F* h_dR2_reco = new TH1F("h_dR2_reco","dR(ele,b) at reco for diff top",20,0,4);
    TH1F* h_dR1_recoM = new TH1F("h_dR1_recoM","dR(ele,b) at reco with gen-matching for same top",20,0,4);
    TH1F* h_dR2_recoM = new TH1F("h_dR2_recoM","dR(ele,b) at reco with gen-matching for diff top",20,0,4);
    TH1F* h_dPhi1_recoM = new TH1F("h_dPhi1_recoM","dPhi(ele,b) at reco with gen-matching for same top",20,0,4);
    TH1F* h_dPhi2_recoM = new TH1F("h_dPhi2_recoM","dPhi(ele,b) at reco with gen-matching for diff top",20,0,4);
    TH1F* h_dR3_recoM = new TH1F("h_dR3_recoM","TEST",5,-2,2);
    TH1F* h_numThinJet = new TH1F("h_numThinJet","number of thin jet",10,0,10);
    TH1F* h_numThinJet2 = new TH1F("h_numThinJet2","number of thin jet (with csv)",10,0,10);
    TH1F* h_numThinJet_ele = new TH1F("h_numThinJet_ele","number of thin jet after dR(ele,fatJet) > 0.8",10,0,10);
    TH1F* h_numThinJet2_ele = new TH1F("h_numThinJet2_ele","number of thin jet (with csv) after dR(ele,fatJet) > 0.8",10,0,10);
    TH1F* h_numThinJet_ele2 = new TH1F("h_numThinJet_ele2","number of thin jet after dR(ele,fatJet) > 1.2",10,0,10);
    TH1F* h_numThinJet2_ele2 = new TH1F("h_numThinJet2_ele2","number of thin jet (with csv) after dR(ele,fatJet) > 1.2",10,0,10);
    TH1F* h_charge1 = new TH1F("h_charge1","charge same",5,-2,2);
    TH1F* h_charge2 = new TH1F("h_charge2","charge diff",5,-2,2);

    IndexFunction d;

    for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
       if (jEntry % 50000 == 0)
       fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());

    data.GetEntry(jEntry);

    TClonesArray* genParP4 = (TClonesArray*) data.GetPtrTObject("genParP4");
    Int_t nGenPar          = data.GetInt("nGenPar");
    Int_t* genParId        = data.GetPtrInt("genParId");
    Int_t* genParSt        = data.GetPtrInt("genParSt");
    Int_t* genMomParId     = data.GetPtrInt("genMomParId");
    Int_t* genDa1          = data.GetPtrInt("genDa1");
    Int_t* genDa2          = data.GetPtrInt("genDa2");
    Int_t* genMo1          = data.GetPtrInt("genMo1");
    Int_t* genMo2          = data.GetPtrInt("genMo2");

    TClonesArray* eleP4 = (TClonesArray*) data.GetPtrTObject("eleP4");
    Int_t nEle          = data.GetInt("nEle");
    Int_t* eleCharge    = data.GetPtrInt("eleCharge");
    vector<bool> &eleIsPassLooseNoIso = *((vector<bool>*) data.GetPtr("eleIsPassLooseNoIso"));

    TClonesArray* FatJetP4 = (TClonesArray*) data.GetPtrTObject("FATjetP4");
    Int_t nJet             = data.GetInt("FATnJet");
    Float_t pfMetRawPt     = data.GetFloat("pfMetRawPt");
    Float_t pfMetRawPhi    = data.GetFloat("pfMetRawPhi");
    Float_t *FATjetCISVV2  = data.GetPtrFloat("FATjetCISVV2");
    Float_t *FATjetSDmass  = data.GetPtrFloat("FATjetSDmass");
    Float_t *FATjetPRmass  = data.GetPtrFloat("FATjetPRmass");
    Int_t* FATjetCharge    = data.GetPtrInt("FATjetCharge");
    vector<bool> &trigResult = *((vector<bool>*) data.GetPtr("hlt_trigResult"));
    std::string*  trigName = data.GetPtrString("hlt_trigName");

    TClonesArray* THINjetP4 = (TClonesArray*) data.GetPtrTObject("THINjetP4");
    Int_t THINnJet             = data.GetInt("THINnJet");
    const Int_t nsize = data.GetPtrStringSize();



    int nW_lep=0, nW_had=0;

    /********** Gen Level Info **********/
    for(int ig=0; ig < nGenPar; ig++){
      // if(genParSt[ig]!=1)continue;
      if(abs(genParId[ig]) == 24){
        if(abs(genMomParId[ig])!=6)continue;
          int da1 = genParId[genDa1[ig]];
          int da2 = genParId[genDa2[ig]];
          if(is2Jets(ig,da1,da2)){
            nW_had++;
          }
          if(is1lep1nu(ig,da1,da2) || is1Nu1Lep(ig,da1,da2)){
            nW_lep++;
          }
      }
     }//select semi loop 
    /******* semi-leptonic selection *******/
    if(nW_had!=1 && nW_lep!=1)continue;

    float NmaxPt = -9999.0;
    int maxJetIndex = -1;
    TLorentzVector maxJet;

    /********* BJet Selction *************/
    for(int ij=0; ij< nJet; ij++){
      bool match = false,match_anti = false;
      TLorentzVector* thisJet = (TLorentzVector*)FatJetP4->At(ij);
      if(thisJet->Pt() < 200)continue;
      if(fabs(thisJet->Eta()) > 2.4)continue;
      if(FATjetCISVV2[ij] < 0.605)continue;
      if(thisJet->Pt() > NmaxPt){
                NmaxPt = thisJet->Pt();
                maxJet = *thisJet;
                maxJetIndex = ij;
            }//leading Jet     
    }//AK8PFJets loop
    
    if(maxJetIndex == -1)continue;
    /******* PreSelection **********/
    if(pfMetRawPt < 200) continue;
    if(fabs(maxJet.Phi()- pfMetRawPhi)<2.5)continue;
    if(!TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET170_NoiseCleaned_v1") || 
    !TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET120_PFMHT120_IDLoose_v1")) continue;

    vector<int> indexGenEleMomisTopWEle = d.indexGenEleMomisTopWEle(genMomParId,genParId,nGenPar,genParSt);
    vector<int> indexRecoEle = d.indexRecoEle(nEle,eleIsPassLooseNoIso);
    vector<int> indexFatJet = d.indexFatJet(nJet,FATjetCISVV2,FatJetP4,pfMetRawPhi,FATjetSDmass);
    vector<int> indexRecoBMomisTopOrB = d.indexRecoBMomisTopOrB(nJet,FatJetP4,genParId,nGenPar,genParP4,genMomParId,FATjetCISVV2,pfMetRawPhi,FATjetSDmass);
    vector<int> indexRecoAntiBMomisTopOrB = d.indexRecoAntiBMomisTopOrB(nJet,FatJetP4,genParId,nGenPar,genParP4,genMomParId,FATjetCISVV2,pfMetRawPhi,FATjetSDmass);
    vector<int> indexRecoEleMatch = d.indexRecoEleMatch(nEle, eleIsPassLooseNoIso, eleP4, genMomParId, genParId, nGenPar, genParSt, genParP4);
    vector<int> indexRecoAntiEleMatch = d.indexRecoAntiEleMatch(nEle, eleIsPassLooseNoIso, eleP4, genMomParId, genParId, nGenPar, genParSt, genParP4);
    int getNumThinJet = d.getNumThinJet(THINnJet, THINjetP4,nJet,FatJetP4,genParId,nGenPar,genParP4,genMomParId);
    int getNumThinJet2 = d.getNumThinJet2(THINnJet, THINjetP4,nJet,FatJetP4,FATjetCISVV2,genParId,nGenPar,genParP4,genMomParId);
    int getNumThinJet_eleFat = d.getNumThinJet_eleFat(THINnJet, THINjetP4,nJet,FatJetP4,nEle,eleP4, eleIsPassLooseNoIso);
    int getNumThinJet2_eleFat = d.getNumThinJet2_eleFat(THINnJet, THINjetP4,nJet,FatJetP4,FATjetCISVV2, nEle,eleP4, eleIsPassLooseNoIso);
    int getNumThinJet_eleFat2 = d.getNumThinJet_eleFat(THINnJet, THINjetP4,nJet,FatJetP4,nEle,eleP4, eleIsPassLooseNoIso);
    int getNumThinJet2_eleFat2 = d.getNumThinJet2_eleFat(THINnJet, THINjetP4,nJet,FatJetP4,FATjetCISVV2, nEle,eleP4, eleIsPassLooseNoIso);

    /********** Plot ******************/

    for(int i=0; i< indexGenEleMomisTopWEle.size();i++){
      TLorentzVector* thisEle = (TLorentzVector*)genParP4->At(indexGenEleMomisTopWEle[i]);
      h_genElePt->Fill(thisEle->Pt());
      h_genEleEta->Fill(thisEle->Eta());
    }
    for(int i=0; i< indexRecoEle.size();i++){
      TLorentzVector* thisEle = (TLorentzVector*)eleP4->At(indexRecoEle[i]);
      h_recoElePt->Fill(thisEle->Pt());
      h_recoEleEta->Fill(thisEle->Eta());
    }

    for(int i=0; i< indexFatJet.size();i++){
      TLorentzVector* fatJet = (TLorentzVector*)FatJetP4->At(indexFatJet[i]);
      h_fatjetPt->Fill(fatJet->Pt());
      h_fatjetEta->Fill(fatJet->Eta());
    }

    for(int i=0; i< indexRecoBMomisTopOrB.size();i++){
      TLorentzVector* thisb = (TLorentzVector*)FatJetP4->At(indexRecoBMomisTopOrB[i]);
      h_recoBPt->Fill(thisb->Pt());
      h_recoBEta->Fill(thisb->Eta());
    }

    //same top
      for(int i=0; i< indexRecoEleMatch.size(); i++){
      TLorentzVector* thisEle = (TLorentzVector*)eleP4->At(indexRecoEleMatch[i]);
      h_recoElePt_match->Fill(thisEle->Pt());
      h_recoEleEta_match->Fill(thisEle->Eta());
      for (int j=0; j< indexRecoBMomisTopOrB.size();j++){
        // int charge_ele = 0,charge_jet=0;
        TLorentzVector* thisb = (TLorentzVector*)FatJetP4->At(indexRecoBMomisTopOrB[j]);
        h_dR_recoM->Fill(thisEle->DeltaR(*thisb));
        h_numThinJet->Fill(getNumThinJet);
        h_numThinJet2->Fill(getNumThinJet2);
        h_numThinJet_ele->Fill(getNumThinJet_eleFat);
        h_numThinJet2_ele->Fill(getNumThinJet2_eleFat);
        h_numThinJet_ele2->Fill(getNumThinJet_eleFat2);
        h_numThinJet2_ele2->Fill(getNumThinJet2_eleFat2);
        if(FATjetCharge[indexRecoBMomisTopOrB[j]]>0)h_charge1->Fill(FATjetCharge[indexRecoBMomisTopOrB[j]]);
        if(FATjetCharge[indexRecoBMomisTopOrB[j]]<0 || FATjetCharge[indexRecoBMomisTopOrB[j]]==0) h_charge2->Fill(FATjetCharge[indexRecoBMomisTopOrB[j]]);
        // int charge_ele = eleCharge[i];
        // int charge_jet = FATjetCharge[j];
        // if(charge_ele*charge_jet<0)h_dR1_recoM->Fill(thisEle->DeltaR(*thisb));
        // if(charge_ele*charge_jet>0)h_dR2_recoM->Fill(thisEle->DeltaR(*thisb));
        h_dR1_recoM->Fill(thisEle->DeltaR(*thisb));
        h_dPhi1_recoM->Fill(fabs(thisEle->Phi()-thisb->Phi()));
        // else cout<<"ele charge:"<<eleCharge[indexRecoEleMatch[i]]<<" fat charge:"<<FATjetCharge[indexRecoBMomisTopOrB[j]]<<endl;
        // else h_dR3_recoM->Fill(eleCharge[indexRecoEleMatch[i]]*FATjetCharge[indexRecoBMomisTopOrB[j]]);
      }
    }
      //same top
      for(int i=0; i< indexRecoAntiEleMatch.size(); i++){
      TLorentzVector* thisEle = (TLorentzVector*)eleP4->At(indexRecoAntiEleMatch[i]);
      h_recoElePt_match->Fill(thisEle->Pt());
      h_recoEleEta_match->Fill(thisEle->Eta());
      for (int j=0; j< indexRecoAntiBMomisTopOrB.size();j++){
        // int charge_ele = 0,charge_jet=0;
        TLorentzVector* thisb = (TLorentzVector*)FatJetP4->At(indexRecoAntiBMomisTopOrB[j]);
        h_dR_recoM->Fill(thisEle->DeltaR(*thisb));
        h_numThinJet->Fill(getNumThinJet);
        h_numThinJet2->Fill(getNumThinJet2);
        h_numThinJet_ele->Fill(getNumThinJet_eleFat);
        h_numThinJet2_ele->Fill(getNumThinJet2_eleFat);
        h_numThinJet_ele2->Fill(getNumThinJet_eleFat2);
        h_numThinJet2_ele2->Fill(getNumThinJet2_eleFat2);
        if(FATjetCharge[indexRecoAntiBMomisTopOrB[j]]<0)h_charge1->Fill(FATjetCharge[indexRecoAntiBMomisTopOrB[j]]);
        if(FATjetCharge[indexRecoAntiBMomisTopOrB[j]]>0 || FATjetCharge[indexRecoAntiBMomisTopOrB[j]]==0) h_charge2->Fill(FATjetCharge[indexRecoAntiBMomisTopOrB[j]]);
        // int charge_ele = eleCharge[i];
        // int charge_jet = FATjetCharge[j];
        // if(charge_ele*charge_jet<0)h_dR1_recoM->Fill(thisEle->DeltaR(*thisb));
        // if(charge_ele*charge_jet>0)h_dR2_recoM->Fill(thisEle->DeltaR(*thisb));
        h_dR1_recoM->Fill(thisEle->DeltaR(*thisb));
        h_dPhi1_recoM->Fill(fabs(thisEle->Phi()-thisb->Phi()));
        // else cout<<"ele charge:"<<eleCharge[indexRecoEleMatch[i]]<<" fat charge:"<<FATjetCharge[indexRecoBMomisTopOrB[j]]<<endl;
        // else h_dR3_recoM->Fill(eleCharge[indexRecoEleMatch[i]]*FATjetCharge[indexRecoBMomisTopOrB[j]]);
      }
    }
      //diff top
      for(int i=0; i< indexRecoAntiEleMatch.size(); i++){
      TLorentzVector* thisEle = (TLorentzVector*)eleP4->At(indexRecoAntiEleMatch[i]);
      h_recoElePt_match->Fill(thisEle->Pt());
      h_recoEleEta_match->Fill(thisEle->Eta());
      for (int j=0; j< indexRecoBMomisTopOrB.size();j++){
        // int charge_ele = 0,charge_jet=0;
        TLorentzVector* thisb = (TLorentzVector*)FatJetP4->At(indexRecoBMomisTopOrB[j]);
        h_dR_recoM->Fill(thisEle->DeltaR(*thisb));
        h_numThinJet->Fill(getNumThinJet);
        h_numThinJet2->Fill(getNumThinJet2);
        h_numThinJet_ele->Fill(getNumThinJet_eleFat);
        h_numThinJet2_ele->Fill(getNumThinJet2_eleFat);
        h_numThinJet_ele2->Fill(getNumThinJet_eleFat2);
        h_numThinJet2_ele2->Fill(getNumThinJet2_eleFat2);
        if(FATjetCharge[indexRecoBMomisTopOrB[j]]<0)h_charge1->Fill(FATjetCharge[indexRecoBMomisTopOrB[j]]);
        if(FATjetCharge[indexRecoBMomisTopOrB[j]]>0 || FATjetCharge[indexRecoBMomisTopOrB[j]]==0) h_charge2->Fill(FATjetCharge[indexRecoBMomisTopOrB[j]]);
        // int charge_ele = eleCharge[i];
        // int charge_jet = FATjetCharge[j];
        // if(charge_ele*charge_jet<0)h_dR1_recoM->Fill(thisEle->DeltaR(*thisb));
        // if(charge_ele*charge_jet>0)h_dR2_recoM->Fill(thisEle->DeltaR(*thisb));
        h_dR2_recoM->Fill(thisEle->DeltaR(*thisb));
        h_dPhi2_recoM->Fill(fabs(thisEle->Phi()-thisb->Phi()));
        // else cout<<"ele charge:"<<eleCharge[indexRecoEleMatch[i]]<<" fat charge:"<<FATjetCharge[indexRecoBMomisTopOrB[j]]<<endl;
        // else h_dR3_recoM->Fill(eleCharge[indexRecoEleMatch[i]]*FATjetCharge[indexRecoBMomisTopOrB[j]]);
      }
    }
    //same top
      for(int i=0; i< indexRecoEleMatch.size(); i++){
      TLorentzVector* thisEle = (TLorentzVector*)eleP4->At(indexRecoEleMatch[i]);
      h_recoElePt_match->Fill(thisEle->Pt());
      h_recoEleEta_match->Fill(thisEle->Eta());
      for (int j=0; j< indexRecoAntiBMomisTopOrB.size();j++){
        // int charge_ele = 0,charge_jet=0;
        TLorentzVector* thisb = (TLorentzVector*)FatJetP4->At(indexRecoAntiBMomisTopOrB[j]);
        h_dR_recoM->Fill(thisEle->DeltaR(*thisb));
        h_numThinJet->Fill(getNumThinJet);
        h_numThinJet2->Fill(getNumThinJet2);
        h_numThinJet_ele->Fill(getNumThinJet_eleFat);
        h_numThinJet2_ele->Fill(getNumThinJet2_eleFat);
        h_numThinJet_ele2->Fill(getNumThinJet_eleFat2);
        h_numThinJet2_ele2->Fill(getNumThinJet2_eleFat2);
        if(FATjetCharge[indexRecoAntiBMomisTopOrB[j]]<0)h_charge1->Fill(FATjetCharge[indexRecoAntiBMomisTopOrB[j]]);
        if(FATjetCharge[indexRecoAntiBMomisTopOrB[j]]>0 || FATjetCharge[indexRecoAntiBMomisTopOrB[j]]==0) h_charge2->Fill(FATjetCharge[indexRecoAntiBMomisTopOrB[j]]);
        // int charge_ele = eleCharge[i];
        // int charge_jet = FATjetCharge[j];
        // if(charge_ele*charge_jet<0)h_dR1_recoM->Fill(thisEle->DeltaR(*thisb));
        // if(charge_ele*charge_jet>0)h_dR2_recoM->Fill(thisEle->DeltaR(*thisb));
        h_dR2_recoM->Fill(thisEle->DeltaR(*thisb));
        h_dPhi2_recoM->Fill(fabs(thisEle->Phi()-thisb->Phi()));
        // else cout<<"ele charge:"<<eleCharge[indexRecoEleMatch[i]]<<" fat charge:"<<FATjetCharge[indexRecoBMomisTopOrB[j]]<<endl;
        // else h_dR3_recoM->Fill(eleCharge[indexRecoEleMatch[i]]*FATjetCharge[indexRecoBMomisTopOrB[j]]);
      }
    }

      for(int i=0; i< indexRecoEle.size(); i++){
      TLorentzVector* thisEle = (TLorentzVector*)eleP4->At(indexRecoEle[i]);
      for (int j=0; j< indexFatJet.size();j++){
        TLorentzVector* thisb = (TLorentzVector*)FatJetP4->At(indexFatJet[j]);
        // int charge_ele = eleCharge[i];
        // int charge_jet = FATjetCharge[j];
        // if(charge_ele*charge_jet<0)h_dR1_reco->Fill(thisEle->DeltaR(*thisb));
        // if(charge_ele*charge_jet>0)h_dR2_reco->Fill(thisEle->DeltaR(*thisb));
        if(eleCharge[indexRecoEle[i]]*FATjetCharge[indexFatJet[j]]<0)h_dR1_reco->Fill(thisEle->DeltaR(*thisb));
        if(eleCharge[indexRecoEle[i]]*FATjetCharge[indexFatJet[j]]>0)h_dR2_reco->Fill(thisEle->DeltaR(*thisb));
      }
    }

    }//Entries loop

TFile* outFile = new TFile(outputFile.Data(),"recreate");

h_genElePt->Write();
h_genEleEta->Write();
h_recoElePt->Write();
h_recoEleEta->Write();
h_recoElePt_match->Write();
h_recoEleEta_match->Write();
h_fatjetPt->Write();
h_fatjetEta->Write();
h_recoBPt->Write();
h_recoBEta->Write();
h_dR1_reco->Write();
h_dR2_reco->Write();
h_dR_recoM->Write();
h_dR1_recoM->Write();
h_dR2_recoM->Write();
h_dR3_recoM->Write();
h_dPhi1_recoM->Write();
h_dPhi2_recoM->Write();
h_numThinJet->Write();
h_numThinJet2->Write();
h_numThinJet_ele->Write();
h_numThinJet2_ele->Write();
h_numThinJet_ele2->Write();
h_numThinJet2_ele2->Write();
h_charge1->Write();
h_charge2->Write();
outFile->Close();
}
