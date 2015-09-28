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

    TH2F* h_2D_dR1 = new TH2F("h_dR1","dR(lep,b) comes from the same top VS Top Pt",100,0,5,100,0,1000);
    TH2F* h_2D_dR2 = new TH2F("h_dR2","dR(lep,b) comes from the other top VS Top Pt",100,0,5,100,0,1000);

    for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
       if (jEntry % 50000 == 0)
       fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());

    data.GetEntry(jEntry);
    TClonesArray* FatJetP4 = (TClonesArray*) data.GetPtrTObject("FATjetP4");
    Int_t nJet             = data.GetInt("FATnJet");
    Float_t pfMetRawPt     = data.GetFloat("pfMetRawPt");
    Float_t pfMetRawPhi    = data.GetFloat("pfMetRawPhi");
    Float_t *FATjetCISVV2  = data.GetPtrFloat("FATjetCISVV2");
    // Int_t *hlt_trigResult  = data.GetPtrInt("hlt_trigResult");
    vector<bool> &trigResult = *((vector<bool>*) data.GetPtr("hlt_trigResult"));
    std::string*  trigName = data.GetPtrString("hlt_trigName");
    const Int_t nsize = data.GetPtrStringSize();

    float NmaxPt = -9999.0, NsecondPt = -9999.0;
    int maxJetIndex = -1;
    TLorentzVector maxPt, secondPt;

    /********* BJet Selction *************/
    for(int ij=0; ij< nJet; ij++){
      TLorentzVector* thisJet = (TLorentzVector*)FatJetP4->At(ij);
      if(thisJet->Pt() < 200)continue;
      if(fabs(thisJet->Eta()) > 2.5)continue;
      if(FATjetCISVV2[ij] < 0.605)continue;

            if(thisJet->Pt() > NmaxPt){
                NmaxPt = thisJet->Pt();
                maxPt = *thisJet;
                maxJetIndex = ij;
            }//leading Jet
            if(thisJet->Pt() > NsecondPt){
                if(ij == maxJetIndex) continue;
                NsecondPt = thisJet->Pt();
                secondPt = *thisJet;
            }//second Jet      
    }//AK8PFJets loop

    /******* PreSelection **********/
    if((maxPt + secondPt).M()>150 || (maxPt + secondPt).M()< 100)continue;
    if(pfMetRawPt < 200) continue;
    if(fabs(maxPt.Phi()- pfMetRawPhi)<2.5)continue;
    if(fabs(secondPt.Phi()- pfMetRawPhi )<2.5)continue;
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

    for(int ig=0; ig < nGenPar; ig++){
      /******* ele Loop *********/
      if(abs(genMomParId[ig])==6 && abs(genParId[ig])==24){
        if(genParId[genDa1[ig]]==-11 || genParId[genDa1[ig]]==-13 || genParId[genDa1[ig]]==-15){
          goodLep.push_back(genDa1[ig]);
        }else if (genParId[genDa2[ig]]==-11 || genParId[genDa2[ig]]==-13 || genParId[genDa2[ig]]==-15){
          goodLep.push_back(genDa2[ig]);
        }
        if(genParId[genDa1[ig]]==11 || genParId[genDa1[ig]]==13 || genParId[genDa1[ig]]==15){
          goodantiLep.push_back(genDa1[ig]);
        }else if (genParId[genDa2[ig]]==11 || genParId[genDa2[ig]]==13 || genParId[genDa2[ig]]==15){
          goodantiLep.push_back(genDa2[ig]);
        }
      }// ele loop

      /******** bjet loop *********/
      if(abs(genParId[ig])==5){
        if(genMomParId[ig]==6)goodbquark.push_back(ig);
        if(genMomParId[ig]==-6)goodantib.push_back(ig);
      }//b quark

      /****** select top ***********/
      if(genParId[ig]==6)goodtop.push_back(ig);
      if(genParId[ig]==-6)goodantitop.push_back(ig);
    
    /********** Plot from Same Top **************/
      for(unsigned int i=0; i< goodLep.size(); i++){
        int il = goodLep[i];
        TLorentzVector* thisEle = (TLorentzVector*)genParP4->At(il);
        for(unsigned int j=0; j < goodbquark.size(); j++){
          int jb = goodbquark [j];
          TLorentzVector* thisb = (TLorentzVector*)genParP4->At(jb);
          for(unsigned int k=0; k < goodtop.size(); k++){
            int kt = goodtop[k];
            TLorentzVector* thistop = (TLorentzVector*)genParP4->At(kt);
            h_2D_dR1->Fill(thisEle->DeltaR(*thisb),thistop->Pt());
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
            h_2D_dR1->Fill(thisEle->DeltaR(*thisb),thistop->Pt());
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
            h_2D_dR2->Fill(thisEle->DeltaR(*thisb),thistop->Pt());
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
            h_2D_dR2->Fill(thisEle->DeltaR(*thisb),thistop->Pt());
          }
        }
      }// plot for coming from same antitop

    }//Gen Loop 

    }//Entries loop

TFile* outFile = new TFile(outputFile.Data(),"recreate");
h_2D_dR1->Write();
h_2D_dR2->Write();
outFile->Close();
}
