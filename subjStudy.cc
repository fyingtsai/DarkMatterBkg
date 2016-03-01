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
#include <sstream>
#include <Sample.h>


vector<string> split(TString str, char delimiter) {
  vector<string> internal;
  string str_ = string(str);
  stringstream ss(str_); 
  string tok;
  
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
  
  return internal;
}

void subjStudy(unsigned int id){
  TString dirName;
  if(id==1)dirName = "MonoHFatJetSelection_JetAndLeptonVeto";
  if(id==6)dirName = "histfacFatJet_TTBar";
  if(id==23)dirName = "histfacFatJet_ZLight";
  if(id==24)dirName = "histfacFatJet_WLight";
  gSystem->mkdir(dirName); 

const int nobjectmet=1;
  TH1F*    h_nMuons[nobjectmet];
  TH1F*    h_nTaus[nobjectmet];
  TH1F*    h_nElectrons[nobjectmet];
  TH1F*    h_nJets[nobjectmet];
  TH1F*    h_nFJets[nobjectmet];
  TH1F*    h_NThinJets[nobjectmet];
  TH1F*    h_dPhiThinJetMET[nobjectmet];
  TH1F*    h_DRSJ[nobjectmet];
  TH1F*    h_Q1Q2[nobjectmet];
  TH1F*    h_MET[nobjectmet];
  TH1F*    h_MHT[nobjectmet];
  TH1F*    h_Mjj[nobjectmet];
  TH1F*    h_pTjj[nobjectmet];
  TH1F*    h_etajj[nobjectmet];
  TH1F*    h_phijj[nobjectmet];
  TH1F*    h_Tau21jj[nobjectmet];
  TH1F*    h_CSVMax[nobjectmet];
  TH1F*    h_CSVMin[nobjectmet];
  TH1F*    h_CSV1[nobjectmet];
  TH1F*    h_CSV2[nobjectmet];
  TH1F*    h_CSVSum[nobjectmet];
  TH1F*    h_dPhi_MET_J[nobjectmet];
  TH1F*    h_MT_bb_MET[nobjectmet];
  TH1F*    h_dPhi_bb_MET[nobjectmet];

  TH1F*    h_MET_Over_SumET[nobjectmet];
  TH1F*    h_MET_Over_pTFatJet[nobjectmet];
  TH1F*    h_CEmEF[nobjectmet];
  TH1F*    h_CHadEF[nobjectmet];
  TH1F*    h_PhoEF[nobjectmet];
  TH1F*    h_NEmEF[nobjectmet];
  TH1F*    h_NHadEF[nobjectmet];
  TH1F*    h_MuEF[nobjectmet];
 
  TH1F*    h_CMulti[nobjectmet];
  TH1F*    h_event[nobjectmet];
  
  TString postfix;
  int pf=0;
  postfix.Form("%d",pf);
    h_nMuons[nobjectmet]     = new TH1F("h_nMuons"+postfix,"h_nMuons",10,0,10);
    h_nTaus[nobjectmet]      = new TH1F("h_nTaus"+postfix,"h_nTaus",10,0,10);
    h_nElectrons[nobjectmet] = new TH1F("h_nElectrons"+postfix,"h_nElectrons",10,0,10);
    h_nJets[nobjectmet]      = new TH1F("h_nJetss"+postfix,"h_nJetss",10,0,10);
    h_nFJets[nobjectmet]     = new TH1F("h_nFJets"+postfix,"h_nFJets",10,0,10);
    h_DRSJ[nobjectmet]       = new TH1F("h_DRSJ"+postfix,"h_DRSJ",100,0,5);
    h_NThinJets[nobjectmet]  = new TH1F("h_NThinJets"+postfix,"h_NThinJets",10,0,10);

    h_dPhiThinJetMET[nobjectmet] = new TH1F("h_dPhiThinJetMET"+postfix,"h_dPhiThinJetMET",70,-3.5,3.5);

    h_Q1Q2[nobjectmet]       = new TH1F("h_Q1Q2"+postfix,"h_Q1Q2",21,-10,10);
    h_MET[nobjectmet]        = new TH1F("h_MET"+postfix,"h_MET",300,0,3000);
    h_MHT[nobjectmet]        = new TH1F("h_MHT"+postfix,"h_MHT",300,0,3000);
    h_Mjj[nobjectmet]        = new TH1F("h_Mjj"+postfix,"",300,0,3000);
    h_pTjj[nobjectmet]       = new TH1F("h_pTjj"+postfix,"",300,0,3000);
    h_etajj[nobjectmet]      = new TH1F("h_etajj"+postfix,"",50,-2.5,2.5);
    h_phijj[nobjectmet]      = new TH1F("h_phijj"+postfix,"",70,-3.5,3.5);
    h_Tau21jj[nobjectmet]    = new TH1F("h_h_Tau21jj"+postfix,"",20,0.,1.);

    h_CSVMax[nobjectmet]     = new TH1F("h_CSVMax"+postfix,"",20,0,1);
    h_CSVMin[nobjectmet]     = new TH1F("h_CSVMin"+postfix,"",20,0,1);
    h_CSV1[nobjectmet]       = new TH1F("h_CSV1"+postfix,"",20,0,1);
    h_CSV2[nobjectmet]       = new TH1F("h_CSV2"+postfix,"",20,0,1);
    h_CSVSum[nobjectmet]     = new TH1F("h_CSVSum"+postfix,"",40,0,2);
    h_dPhi_MET_J[nobjectmet] = new TH1F("h_dPhi_MET_J"+postfix,"",70,0.,3.5);
    h_MT_bb_MET[nobjectmet]  = new TH1F("h_MT_bb_MET"+postfix,"",1000,0,5000.);
    h_dPhi_bb_MET[nobjectmet]= new TH1F("h_dPhi_bb_MET"+postfix,"",100,0,3.5);

    h_MET_Over_SumET[nobjectmet]    = new TH1F("h_MET_Over_SumET"+postfix,"",20,0,1.);
    h_MET_Over_pTFatJet[nobjectmet] = new TH1F("h_MET_Over_pTFatJet"+postfix,"",100,0,5);
    h_CEmEF[nobjectmet]             = new TH1F("h_CEmEF"+postfix,"",20,0,1);
    h_CHadEF[nobjectmet]            = new TH1F("h_CHadEF"+postfix,"",20,0,1);
    h_PhoEF[nobjectmet]             = new TH1F("h_PhoEF"+postfix,"",20,0,1);
    h_NEmEF[nobjectmet]             = new TH1F("h_NEmEF"+postfix,"",20,0,1);
    h_NHadEF[nobjectmet]            = new TH1F("h_NHadEF"+postfix,"",20,0,1);
    h_MuEF[nobjectmet]              = new TH1F("h_MuEF"+postfix,"",20,0,1);
    h_CMulti[nobjectmet]            = new TH1F("h_CMulti"+postfix,"",20,0,1);
    h_event[nobjectmet]             = new TH1F("h_event"+postfix,"",100,0,100);

  for(int i=0; i<Sample::fileNameFullSample().size(); i++)
    {
        TFile *inputFile;
        inputFile = new TFile(Sample::fileNameFullSample()[i],"READ");
        // inputFile = new TFile(file[i],"READ");
        TH1F *h = (TH1F *) gDirectory->Get("nEvents_weight");
        TH1F *h_total=(TH1F*)h->Clone();
        h_total->SetName("h_total");
        TTree *tree = (TTree*)inputFile->Get("skimTreeMonoHFatJetsPreselection_2subj");
        TString outputFile;
        TString searchFile = Sample::fileNameFullSample()[i];
        // string searchFile = file[i];
        vector<string> fileName = split(searchFile, '/');
        outputFile = fileName[8];
        cout << "Output file = " << outputFile.Data() << endl;
TreeReader data(tree);
setNCUStyle();

int countEvent=0;

for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
       if (jEntry % 50000 == 0)
       fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());
    data.GetEntry(jEntry);

    Float_t         dphiMin_    = data.GetFloat("dphiMin_");
    Int_t           NAddMu_     = data.GetInt("NAddMu_");
    Int_t           NAddEle_    = data.GetInt("NAddEle_");
    Int_t           NAddTau_    = data.GetInt("NAddTau_");
    Int_t           NAddBJet    = data.GetInt("NAddBJet");
    Float_t         MinCSV_     = data.GetFloat("MinCSV_");
    Float_t         MaxCSV_     = data.GetFloat("MaxCSV_");
    Float_t         CSV1_     = data.GetFloat("CSV1_");
    Float_t         CSV2_     = data.GetFloat("CSV2_");
    Float_t         DRSJ_       = data.GetFloat("DRSJ_");
    Float_t         Mass_       = data.GetFloat("Mass_");
    Float_t         JetPhi_     = data.GetFloat("JetPhi_");
    Float_t         JetEta_     = data.GetFloat("JetEta_");
    Float_t         JetCSVSum_  = data.GetFloat("JetCSVSum_");
    Float_t         JetMetDPhi_ = data.GetFloat("JetMetDPhi_");
    Float_t         Tau21_      = data.GetFloat("Tau21_");
    Float_t         JetPt_      = data.GetFloat("JetPt_");
    Float_t         SumET_      = data.GetFloat("SumET_");
    Float_t         MET_        = data.GetFloat("MET_");
    Float_t         jetCEmEF_   = data.GetFloat("jetCEmEF_");
    Float_t         jetCHadEF_  = data.GetFloat("jetCHadEF_"); 
    Float_t         jetPhoEF_   = data.GetFloat("jetPhoEF_");
    Float_t         jetNEmEF_   = data.GetFloat("jetNEmEF_");
    Float_t         jetNHadEF_  = data.GetFloat("jetNHadEF_");
    Float_t         jetMuEF_    = data.GetFloat("jetMuEF_");
    Float_t         jetCMulti_  = data.GetFloat("jetCMulti_");
      bool eventControl = false;
      if(id == 1)//signal region
      {
      if(CSV1_ < 0.605)continue;
      if(Mass_<100 || 150<Mass_)continue;
      if(JetMetDPhi_<2.5)continue;
      if(dphiMin_<0.5)continue;
      if(NAddBJet!=0)continue;
      if(NAddMu_ + NAddEle_ + NAddTau_ !=0)continue;
      eventControl = true;
      }
      if(id == 24)//w+jet
      {
      if(CSV2_ < 0.605)continue;
      if(Mass_<30 || 250<Mass_)continue;
      if(JetMetDPhi_<2.5)continue;
      if(dphiMin_<0.5)continue;
      if(NAddBJet!=0)continue;
      if(NAddMu_ + NAddEle_ + NAddTau_ !=1)continue;
      eventControl = true;
      }
      if(id == 6)//ttbar
      {
      if(CSV2_ < 0.605)continue;
      if(Mass_<30 || 250<Mass_)continue;
      if(JetMetDPhi_<2.5)continue;
      if(dphiMin_<0.5)continue;
      if(NAddBJet<2)continue;
      if(NAddMu_ + NAddEle_ + NAddTau_ !=1)continue;
      eventControl = true;
      }
      if(id == 23)//z to nunu + jet
      {
      if(Mass_<100 && 30<Mass_){
        if(CSV2_ < 0.605)continue;
        if(JetMetDPhi_<2.5)continue;
        if(dphiMin_<0.5)continue;
        if(NAddBJet!=0)continue;
        if(NAddMu_ + NAddEle_ + NAddTau_ !=0)continue;
      eventControl = true;
      }else if (Mass_<250 && 150<Mass_){
        if(CSV2_ < 0.605)continue;
        if(JetMetDPhi_<2.5)continue;
        if(dphiMin_<0.5)continue;
        if(NAddBJet!=0)continue;
        if(NAddMu_ + NAddEle_ + NAddTau_ !=0)continue;
        eventControl = true;
      }
      }
      if(!eventControl)continue;
      countEvent++;
      h_nMuons[nobjectmet] ->Fill(NAddMu_);
      h_nTaus[nobjectmet] ->Fill(NAddTau_);
      h_nElectrons[nobjectmet]->Fill(NAddEle_);
      h_DRSJ[nobjectmet] ->Fill(DRSJ_);
      h_NThinJets[nobjectmet] ->Fill(NAddBJet);
      h_MET[nobjectmet] ->Fill(MET_);
      h_Mjj[nobjectmet] ->Fill(Mass_);
      h_pTjj[nobjectmet] ->Fill(JetPt_);
      h_etajj[nobjectmet] ->Fill(JetEta_);
      h_phijj[nobjectmet] ->Fill(JetPhi_);
      h_Tau21jj[nobjectmet] ->Fill(Tau21_);
      h_CSVMax[nobjectmet] ->Fill(MaxCSV_);
      h_CSVMin[nobjectmet] ->Fill(MinCSV_);
      h_CSVSum[nobjectmet] ->Fill(JetCSVSum_);
      h_dPhi_MET_J[nobjectmet] ->Fill(dphiMin_);
      h_MET_Over_SumET[nobjectmet] ->Fill(MET_/SumET_);
      h_MET_Over_pTFatJet[nobjectmet] ->Fill(MET_/JetPt_);
      h_CEmEF[nobjectmet] ->Fill(jetCEmEF_);
      h_CHadEF[nobjectmet] ->Fill(jetCHadEF_);
      h_PhoEF[nobjectmet] ->Fill(jetPhoEF_);
      h_NEmEF[nobjectmet] ->Fill(jetNEmEF_);
      h_NHadEF[nobjectmet] ->Fill(jetNHadEF_);
      h_MuEF[nobjectmet] ->Fill(jetMuEF_);
      h_CMulti[nobjectmet] ->Fill(jetCMulti_);
}//ENTRIES
h_event[nobjectmet]->Fill(countEvent);
cout<<"Event:"<<countEvent<<endl;
gSystem->cd(dirName);

TFile* outFile = new TFile(outputFile.Data(),"recreate");
h_total->Write();

  if(id==1){outFile->mkdir("MonoHFatJetSelection_JetAndLeptonVeto");
             outFile->cd("MonoHFatJetSelection_JetAndLeptonVeto");}  
  if(id==6){outFile->mkdir("histfacFatJet_TTBar");
             outFile->cd("histfacFatJet_TTBar");}  
  if(id==23){outFile->mkdir("histfacFatJet_ZLight");
             outFile->cd("histfacFatJet_ZLight");}
  if(id==24){outFile->mkdir("histfacFatJet_WLight");
             outFile->cd("histfacFatJet_WLight");}          

      h_nMuons[nobjectmet] ->Write();
      h_nTaus[nobjectmet] ->Write();
      h_nElectrons[nobjectmet]->Write();
      h_DRSJ[nobjectmet] ->Write();
      h_NThinJets[nobjectmet] ->Write();
      h_MET[nobjectmet] ->Write();
      h_Mjj[nobjectmet] ->Write();
      h_pTjj[nobjectmet] ->Write();
      h_etajj[nobjectmet] ->Write();
      h_phijj[nobjectmet] ->Write();
      h_Tau21jj[nobjectmet] ->Write();
      h_CSVMax[nobjectmet] ->Write();
      h_CSVMin[nobjectmet] ->Write();
      h_CSVSum[nobjectmet] ->Write();
      h_dPhi_MET_J[nobjectmet] ->Write();
      h_MET_Over_SumET[nobjectmet] ->Write();
      h_MET_Over_pTFatJet[nobjectmet] ->Write();
      h_CEmEF[nobjectmet] ->Write();
      h_CHadEF[nobjectmet] ->Write();
      h_PhoEF[nobjectmet] ->Write();
      h_NEmEF[nobjectmet] ->Write();
      h_NHadEF[nobjectmet] ->Write();
      h_MuEF[nobjectmet] ->Write();
      h_CMulti[nobjectmet] ->Write();
      h_event[nobjectmet]->Write();

outFile->Close();

}//files
 }//.cc