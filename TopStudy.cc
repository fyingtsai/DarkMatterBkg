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
      outputFile = Form("ttbar_%s.root",endfix.Data());
      cout << "Output file_ = " << outputFile << endl;
    }
  else{
      TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
      outputFile = Form("ttbar_%s.root",endfix.Data());
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

    TH2F* h_2D_dR1 = new TH2F("h_2D_dR1","dR(lep,b) comes from the same top VS Top Pt",100,0,1000,100,0,5);
    TH2F* h_2D_dR2 = new TH2F("h_2D_dR2","dR(lep,b) comes from the other top VS Top Pt",100,0,1000,100,0,5);
    TH1F* h_JetPt = new TH1F("h_jetPt","Jet Pt",100,0,1000);
    TH1F* h_JetMass = new TH1F("h_jetMass","Jet Mass",100,0,500);
    TH1F* h_JetPt_reco = new TH1F("h_jetPt_reco","Jet Pt",100,0,1000);
    TH1F* h_JetMass_reco = new TH1F("h_jetMass_reco","Jet Mass",100,0,500);
    TH1F* h_dR1 = new TH1F("h_dR1","dR(ele,top1)",20,0,4);
    TH1F* h_dR2 = new TH1F("h_dR2","dR(ele,top2)",20,0,4);
    TH1F* h_dR_Ele_genreco = new TH1F("h_dR_Ele_genreco","dR(Reco_ele,Gen_ele)",20,0,4);
    TH1F* h_eb_dR1 = new TH1F("h_eb_dR1","dR1(ele,bjet)",20,0,4);
    TH1F* h_eb_dR2 = new TH1F("h_eb_dR2","dR2(ele,bjet)",20,0,4);
    TH1F* h_eb_dR1_gen = new TH1F("h_eb_dR1_gen","dR1(ele,bjet)",20,0,4);
    TH1F* h_eb_dR2_gen = new TH1F("h_eb_dR2_gen","dR2(ele,bjet)",20,0,4);
    TH1F* h_eb_dR1_reco = new TH1F("h_eb_dR1_reco","dR1(ele,bjet)",20,0,4);
    TH1F* h_eb_dR2_reco = new TH1F("h_eb_dR2_reco","dR2(ele,bjet)",20,0,4);
    TH1F* h_eb_dR3_reco = new TH1F("h_eb_dR3_reco","dR2(ele,bjet) when dR1(ele,bjet)<0.8",20,0,4);
    TH1F* h_dPhi1 = new TH1F("h_dPhi1","dPhi(ele,top1)",10,0,5);
    TH1F* h_dPhi2 = new TH1F("h_dPhi2","dPhi(ele,top2)",10,0,5);
    TH1F* h_dEta1 = new TH1F("h_dEta1","dEta(ele,top1)",10,-5,5);
    TH1F* h_dEta2 = new TH1F("h_dEta2","dEta(ele,top2)",10,-5,5);

    for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
       if (jEntry % 50000 == 0)
       fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());

    data.GetEntry(jEntry);
    TClonesArray* FatJetP4 = (TClonesArray*) data.GetPtrTObject("FATjetP4");
    Int_t nJet             = data.GetInt("FATnJet");
    Float_t pfMetRawPt     = data.GetFloat("pfMetRawPt");
    Float_t pfMetRawPhi    = data.GetFloat("pfMetRawPhi");
    Float_t *FATjetCISVV2  = data.GetPtrFloat("FATjetCISVV2");
    Float_t *FATjetSDmass  = data.GetPtrFloat("FATjetSDmass");
    Float_t *FATjetPRmass  = data.GetPtrFloat("FATjetPRmass");
    // Int_t *hlt_trigResult  = data.GetPtrInt("hlt_trigResult");
    vector<bool> &trigResult = *((vector<bool>*) data.GetPtr("hlt_trigResult"));
    std::string*  trigName = data.GetPtrString("hlt_trigName");
    const Int_t nsize = data.GetPtrStringSize();

    float NmaxPt = -9999.0, NsecondPt = -9999.0;
    int maxJetIndex = -1;
    TLorentzVector maxJet, secondJet;

    /********* BJet Selction *************/
    for(int ij=0; ij< nJet; ij++){
      TLorentzVector* thisJet = (TLorentzVector*)FatJetP4->At(ij);
      if(thisJet->Pt() < 200)continue;
      if(fabs(thisJet->Eta()) > 2.5)continue;
      if(FATjetCISVV2[ij] < 0.605)continue;
      // if(FATjetSDmass[ij]>150 || FATjetSDmass[ij]<100)continue;

            if(thisJet->Pt() > NmaxPt){
                NmaxPt = thisJet->Pt();
                maxJet = *thisJet;
                maxJetIndex = ij;
            }//leading Jet
            if(thisJet->Pt() > NsecondPt){
                if(ij == maxJetIndex) continue;
                NsecondPt = thisJet->Pt();
                secondJet = *thisJet;
            }//second Jet      
    }//AK8PFJets loop
    if(maxJetIndex == -1)continue;
    /******* PreSelection **********/
    if(pfMetRawPt < 200) continue;
    if(fabs(maxJet.Phi()- pfMetRawPhi)<2.5)continue;
    if(!TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET170_NoiseCleaned_v1") || 
    !TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET120_PFMHT120_IDLoose_v1")) continue;

    TClonesArray* genParP4 = (TClonesArray*) data.GetPtrTObject("genParP4");
    Int_t nGenPar          = data.GetInt("nGenPar");
    Int_t* genParId        = data.GetPtrInt("genParId");
    Int_t* genParSt        = data.GetPtrInt("genParSt");
    Int_t* genMomParId     = data.GetPtrInt("genMomParId");
    Int_t* genDa1          = data.GetPtrInt("genDa1");
    Int_t* genDa2          = data.GetPtrInt("genDa2");
    Int_t* genMo1          = data.GetPtrInt("genMo1");
    Int_t* genMo2          = data.GetPtrInt("genMo2");
    int lep1Index=-1,lep2Index=-1;
    int bqaurk_index=-1,abquark_index=-1;
    int Pass=0;
    int nW_lep=0, nW_had=0;
    TLorentzVector ele, antiEle, bjet;
    std::vector<int> goodLep, goodbquark, goodtop;
    std::vector<int> goodantiLep, goodantib, goodantitop;

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

    TLorentzVector *lorentzGenEle_same[10],*lorentzGenEle_diff[10];
    int genEle_same=0,genEle_diff=0;
    for(int ig=0; ig < nGenPar; ig++){
      /******* Ele Gen Loop *********/
      if(abs(genMomParId[ig])!= 6 )continue;
      if(abs(genParId[ig])==24 || abs(genParId[ig])==11){
        // if(abs(genMomParId[ig])!= 6 )continue;
        if(genParSt[genDa1[ig]]!=1)continue;
        if(genParId[genDa1[ig]]==-11){
          goodLep.push_back(genDa1[ig]);
          TLorentzVector* thisEleP4 = (TLorentzVector*)genParP4->At(genDa1[ig]);
          lorentzGenEle_same[genEle_same]= thisEleP4;
          genEle_same++;
        }else if (genParId[genDa2[ig]]==-11){
          goodLep.push_back(genDa2[ig]);
          TLorentzVector* thisEleP4 = (TLorentzVector*)genParP4->At(genDa1[ig]);
          lorentzGenEle_same[genEle_same]= thisEleP4;
          genEle_same++;
        }
        if(genParId[genDa1[ig]]==11){
          goodantiLep.push_back(genDa1[ig]);
          TLorentzVector* thisEleP4 = (TLorentzVector*)genParP4->At(genDa1[ig]);
          lorentzGenEle_diff[genEle_diff]= thisEleP4;
          genEle_diff++;
        }else if (genParId[genDa2[ig]]==11){
          goodantiLep.push_back(genDa2[ig]);
          TLorentzVector* thisEleP4 = (TLorentzVector*)genParP4->At(genDa1[ig]);
          lorentzGenEle_diff[genEle_diff]= thisEleP4;
          genEle_diff++;
        }
      }// ele loop
      for(unsigned int i=0; i< goodLep.size(); i++){
        int il = goodLep[i];
        TLorentzVector* thisEle = (TLorentzVector*)genParP4->At(il);
        if(maxJet.DeltaR(*thisEle)<2)continue;
        h_JetPt->Fill(maxJet.Pt());
        h_JetMass->Fill(maxJet.M());

      }
      for(unsigned int i=0; i< goodantiLep.size(); i++){
        int il = goodantiLep[i];
        TLorentzVector* thisEle = (TLorentzVector*)genParP4->At(il);
        if(maxJet.DeltaR(*thisEle)<2)continue;
        h_JetPt->Fill(maxJet.Pt());
        h_JetMass->Fill(maxJet.M());
      }      

      /******** bjet loop GenLevel *********/
      if(abs(genParId[ig])==5){
        if(genMomParId[ig]==6)goodbquark.push_back(ig);
        if(genMomParId[ig]==-6)goodantib.push_back(ig);
      }//b quark

      /****** select top - GenLevel ***********/
      // for top quark
      if(genParId[ig]==6){
        goodtop.push_back(ig);
      }
      if(genParId[ig]==-6){
        goodantitop.push_back(ig);
      }
    /****** Plot for Reco Ele with FatJet ********/
    TClonesArray* eleP4 = (TClonesArray*) data.GetPtrTObject("eleP4");
    Int_t nEle          = data.GetInt("nEle");
    vector<bool> &eleIsPassLooseNoIso = *((vector<bool>*) data.GetPtr("eleIsPassLooseNoIso"));
    for(int ie=0; ie < nEle; ie++){
      bool match_same = false,match_diff = false;
      if(!eleIsPassLooseNoIso[ie])continue;
      TLorentzVector* thisEle = (TLorentzVector*)eleP4->At(ie);
      for(int ig=0; ig <genEle_same; ig++ ){
        float dR1 = thisEle->DeltaR(*lorentzGenEle_same[ig]);
        if(dR1 <= 0.1) match_same = true;
      }
      for(int ig=0; ig <genEle_diff; ig++ ){
        float dR2 = thisEle->DeltaR(*lorentzGenEle_diff[ig]);
        if(dR2 <= 0.1) match_diff = true;
      }
       if(match_same){
        h_eb_dR1_reco->Fill(thisEle->DeltaR(maxJet));
        float dR =  maxJet.DeltaR(*thisEle);
        if(dR >2){
          h_JetPt_reco->Fill(maxJet.Pt());
          h_JetMass_reco->Fill(FATjetPRmass[maxJetIndex]);
        }
       }
      if(match_diff){
        h_eb_dR2_reco->Fill(thisEle->DeltaR(maxJet));
        float dR = maxJet.DeltaR(*thisEle);
        if(dR>2){
          h_JetPt_reco->Fill(maxJet.Pt());
          h_JetMass_reco->Fill(FATjetPRmass[maxJetIndex]);
        }
       }

    }//reco ele loop

    //reco-gen ele loop
    for(int ie=0; ie < nEle; ie++){
      if(!eleIsPassLooseNoIso[ie])continue;
      TLorentzVector* thisEle = (TLorentzVector*)eleP4->At(ie);
      float dR = maxJet.DeltaR(*thisEle);
      if(dR > 0.8)continue;
      for(int ig=0; ig <genEle_same; ig++ ){
        h_dR_Ele_genreco->Fill(thisEle->DeltaR(*lorentzGenEle_same[ig]));
      }
      for(int ig=0; ig <genEle_diff; ig++ ){
        h_dR_Ele_genreco->Fill(thisEle->DeltaR(*lorentzGenEle_diff[ig]));
      }
    }
    /********** Plot from Same Top - GenLevel**************/
      for(unsigned int i=0; i< goodLep.size(); i++){
        int il = goodLep[i];
        TLorentzVector* thisEle = (TLorentzVector*)genParP4->At(il);
        for(unsigned int j=0; j < goodbquark.size(); j++){
          int jb = goodbquark [j];
          TLorentzVector* thisb = (TLorentzVector*)genParP4->At(jb);
          for(unsigned int k=0; k < goodtop.size(); k++){
            int kt = goodtop[k];
            TLorentzVector* thistop = (TLorentzVector*)genParP4->At(kt);
            h_2D_dR1->Fill(thistop->Pt(),thisEle->DeltaR(*thisb));
            h_dR1->Fill(thisEle->DeltaR(*thistop));
            h_eb_dR1->Fill(thisEle->DeltaR(maxJet));
            h_eb_dR1_gen->Fill(thisEle->DeltaR(*thisb));
            h_dPhi1->Fill(thisEle->DeltaPhi(*thistop));
            h_dEta1->Fill(thisEle->Eta()-thistop->Eta());
          }
        }
      }
      // plot for coming from Same antitop
      for(unsigned int i=0; i< goodantiLep.size(); i++){
        int il = goodantiLep[i];
        TLorentzVector* thisEle = (TLorentzVector*)genParP4->At(il);
        for(unsigned int j=0; j < goodantib.size(); j++){
          int jb = goodantib [j];
          TLorentzVector* thisb = (TLorentzVector*)genParP4->At(jb);
          for(unsigned int k=0; k < goodantitop.size(); k++){
            int kt = goodantitop[k];
            TLorentzVector* thistop = (TLorentzVector*)genParP4->At(kt);
            h_2D_dR1->Fill(thistop->Pt(),thisEle->DeltaR(*thisb));
            h_dR1->Fill(thisEle->DeltaR(*thistop));
            h_eb_dR1->Fill(thisEle->DeltaR(maxJet));
            h_eb_dR1_gen->Fill(thisEle->DeltaR(*thisb));
            h_dPhi1->Fill(thisEle->DeltaPhi(*thistop));
            h_dEta1->Fill(thisEle->Eta()-thistop->Eta());
          }
        }
      }// plot for coming from same antitop

      // plot for coming from Diff top
      for(unsigned int i=0; i< goodLep.size(); i++){
        int il = goodLep[i];
        TLorentzVector* thisEle = (TLorentzVector*)genParP4->At(il);
        for(unsigned int j=0; j < goodantib.size(); j++){
          int jb = goodantib [j];
          TLorentzVector* thisb = (TLorentzVector*)genParP4->At(jb);
          for(unsigned int k=0; k < goodtop.size(); k++){
            int kt = goodtop[k];
            TLorentzVector* thistop = (TLorentzVector*)genParP4->At(kt);
            h_2D_dR2->Fill(thistop->Pt(),thisEle->DeltaR(*thisb));
            h_dR2->Fill(thisEle->DeltaR(*thistop));
            h_eb_dR2->Fill(thisEle->DeltaR(maxJet));
            h_eb_dR2_gen->Fill(thisEle->DeltaR(*thisb));
            h_dPhi2->Fill(thisEle->DeltaPhi(*thistop));
            h_dEta2->Fill(thisEle->Eta()-thistop->Eta());
          }
        }
      }// plot for coming from same antitop
      // plot for coming from Diff antitop
      for(unsigned int i=0; i< goodantiLep.size(); i++){
        int il = goodantiLep[i];
        TLorentzVector* thisEle = (TLorentzVector*)genParP4->At(il);
        for(unsigned int j=0; j < goodbquark.size(); j++){
          int jb = goodbquark [j];
          TLorentzVector* thisb = (TLorentzVector*)genParP4->At(jb);
          for(unsigned int k=0; k < goodtop.size(); k++){
            int kt = goodtop[k];
            TLorentzVector* thistop = (TLorentzVector*)genParP4->At(kt);
            h_2D_dR2->Fill(thistop->Pt(),thisEle->DeltaR(*thisb));
            h_dR2->Fill(thisEle->DeltaR(*thistop));
            h_eb_dR2->Fill(thisEle->DeltaR(maxJet));
            h_eb_dR2_gen->Fill(thisEle->DeltaR(*thisb));
            h_dPhi2->Fill(thisEle->DeltaPhi(*thistop));
            h_dEta2->Fill(thisEle->Eta()-thistop->Eta());
          }
        }
      }// plot for coming from same antitop

    }//Gen Loop 

    }//Entries loop

TFile* outFile = new TFile(outputFile.Data(),"recreate");
h_2D_dR1->Write();
h_2D_dR2->Write();
h_dR1->Write();
h_dR2->Write();
h_eb_dR1->Write();
h_eb_dR2->Write();
h_dR_Ele_genreco->Write();
h_eb_dR1_gen->Write();
h_eb_dR2_gen->Write();
h_eb_dR1_reco->Write();
h_eb_dR2_reco->Write();
h_eb_dR3_reco->Write();
h_dPhi1->Write();
h_dPhi2->Write();
h_dEta1->Write();
h_dEta2->Write();
h_JetPt->Write();
h_JetMass->Write();
h_JetPt_reco->Write();
h_JetMass_reco->Write();
outFile->Close();
}
