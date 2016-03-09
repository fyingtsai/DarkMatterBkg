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
//#include "setNCUStyle.C"
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


  for(int i=0; i<(int) Sample::fileNameFullSample().size(); i++)
    {
     const int nobjectmet=2;
     TH1F*    h_cutFlow;
     TH1F*    h_nMuons;
     TH1F*    h_nTaus;
     TH1F*    h_nElectrons;
     TH1F*    h_nJets;
     TH1F*    h_nFJets;
     TH1F*    h_NThinJets;
     TH1F*    h_dPhiThinJetMET;
     TH1F*    h_DRSJ;
     TH1F*    h_Q1Q2;
     TH1F*    h_MET;
     TH1F*    h_MHT;
     TH1F*    h_Mjj;
     TH1F*    h_pTjj;
     TH1F*    h_etajj;
     TH1F*    h_phijj;
     TH1F*    h_Tau21jj;
     TH1F*    h_CSVMax;
     TH1F*    h_CSVMin;
     TH1F*    h_CSV1;
     TH1F*    h_CSV2;
     TH1F*    h_CSVSum;
     TH1F*    h_dPhi_MET_J;
     TH1F*    h_MT_bb_MET;
     TH1F*    h_dPhi_bb_MET;
     
     TH1F*    h_MET_Over_SumET;
     TH1F*    h_MET_Over_pTFatJet;
     TH1F*    h_CEmEF;
     TH1F*    h_CHadEF;
     TH1F*    h_PhoEF;
     TH1F*    h_NEmEF;
     TH1F*    h_NHadEF;
     TH1F*    h_MuEF;
     
     TH1F*    h_CMulti;
     TH1F*    h_event;
     
     TString postfix;
     int pf=0;
     postfix.Form("%d",pf);
     h_cutFlow    = new TH1F("h_cutFlow"+postfix,"h_cutFlow",10,0,10);
     h_nMuons     = new TH1F("h_nMuons"+postfix,"h_nMuons",10,0,10);
     h_nTaus      = new TH1F("h_nTaus"+postfix,"h_nTaus",10,0,10);
     h_nElectrons = new TH1F("h_nElectrons"+postfix,"h_nElectrons",10,0,10);
     h_nJets      = new TH1F("h_nJetss"+postfix,"h_nJetss",10,0,10);
     h_nFJets     = new TH1F("h_nFJets"+postfix,"h_nFJets",10,0,10);
     h_DRSJ       = new TH1F("h_DRSJ"+postfix,"h_DRSJ",100,0,5);
     h_NThinJets  = new TH1F("h_NThinJets"+postfix,"h_NThinJets",10,0,10);
     
     h_dPhiThinJetMET = new TH1F("h_dPhiThinJetMET"+postfix,"h_dPhiThinJetMET",70,-3.5,3.5);
     
     h_Q1Q2       = new TH1F("h_Q1Q2"+postfix,"h_Q1Q2",21,-10,10);
     h_MET        = new TH1F("h_MET"+postfix,"h_MET",300,0,3000);
     h_MHT        = new TH1F("h_MHT"+postfix,"h_MHT",300,0,3000);
     h_Mjj        = new TH1F("h_Mjj"+postfix,"",300,0,3000);
     h_pTjj       = new TH1F("h_pTjj"+postfix,"",300,0,3000);
     h_etajj      = new TH1F("h_etajj"+postfix,"",50,-2.5,2.5);
     h_phijj      = new TH1F("h_phijj"+postfix,"",70,-3.5,3.5);
     h_Tau21jj    = new TH1F("h_h_Tau21jj"+postfix,"",20,0.,1.);
     
     h_CSVMax     = new TH1F("h_CSVMax"+postfix,"",20,0,1);
     h_CSVMin     = new TH1F("h_CSVMin"+postfix,"",20,0,1);
     h_CSV1       = new TH1F("h_CSV1"+postfix,"",20,0,1);
     h_CSV2       = new TH1F("h_CSV2"+postfix,"",20,0,1);
     h_CSVSum     = new TH1F("h_CSVSum"+postfix,"",40,0,2);
     h_dPhi_MET_J = new TH1F("h_dPhi_MET_J"+postfix,"",70,0.,3.5);
     h_MT_bb_MET  = new TH1F("h_MT_bb_MET"+postfix,"",1000,0,5000.);
     h_dPhi_bb_MET= new TH1F("h_dPhi_bb_MET"+postfix,"",100,0,3.5);
     
     h_MET_Over_SumET    = new TH1F("h_MET_Over_SumET"+postfix,"",20,0,1.);
     h_MET_Over_pTFatJet = new TH1F("h_MET_Over_pTFatJet"+postfix,"",100,0,5);
     h_CEmEF             = new TH1F("h_CEmEF"+postfix,"",20,0,1);
     h_CHadEF            = new TH1F("h_CHadEF"+postfix,"",20,0,1);
     h_PhoEF             = new TH1F("h_PhoEF"+postfix,"",20,0,1);
     h_NEmEF             = new TH1F("h_NEmEF"+postfix,"",20,0,1);
     h_NHadEF            = new TH1F("h_NHadEF"+postfix,"",20,0,1);
     h_MuEF              = new TH1F("h_MuEF"+postfix,"",20,0,1);
     h_CMulti            = new TH1F("h_CMulti"+postfix,"",20,0,1);
     h_event             = new TH1F("h_event"+postfix,"",100,0,100);
     
        TFile *inputFile;
        inputFile = new TFile(Sample::fileNameFullSample()[i],"READ");
        TH1F *h = (TH1F *) gDirectory->Get("nEvents_weight");
        TH1F *h_total=(TH1F*)h->Clone();
        h_total->SetName("h_total");
        TTree *tree = (TTree*)inputFile->Get("skimTreeMonoHFatJetsPreselection");
        TString outputFile;
        TString searchFile = Sample::fileNameFullSample()[i];
        vector<string> fileName = split(searchFile, '/');
        outputFile = fileName[8];
        cout << "Output file = " << outputFile.Data() << endl;

TreeReader data(tree);
//setNCUStyle();

int countEvent=0;

for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
       if (jEntry % 50000 == 0)
       fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());
    data.GetEntry(jEntry);
    Int_t           run_        = data.GetInt("Run_");
    Int_t           lumi_       = data.GetInt("Lumi_");
    Int_t           event_      = data.GetInt("Event_");
    
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
    Float_t         MCweight_   = data.GetFloat("MCweight_");
    Float_t         EWKweight_   = data.GetFloat("EWKweight_");
    Float_t         PUweight_   = data.GetFloat("PUweight_");
    Float_t         BTAGSF_     = data.GetFloat("BTAGSF_");
      bool eventControl = false;
      if(id == 1)//signal region
      {
      if(CSV1_ < 0.605)continue;
      if(Mass_<100 || 150<Mass_)continue;
      if(JetMetDPhi_<2.5)continue;
      if(TMath::Abs(dphiMin_)<0.5)continue;
      if(NAddBJet!=0)continue;
      if((NAddMu_ + NAddEle_ + NAddTau_ )!=0)continue;
      eventControl = true;
      }
      if(id == 24)//w+jet
      {
      if(CSV2_ < 0.605)continue;
      if(Mass_<30 || 250<Mass_)continue;
      if(JetMetDPhi_<2.5)continue;
      if(TMath::Abs(dphiMin_)<0.4)continue;
      if(NAddBJet!=0)continue;
      if((NAddMu_ + NAddEle_ + NAddTau_) !=1)continue;
      eventControl = true;
      }
      if(id == 6)//ttbar
      {
      if(CSV2_ < 0.605)continue;
      if(CSV1_ < 0.605)continue;
      if(Mass_<30 || 250<Mass_)continue;
      if(JetMetDPhi_<2.5)continue;
      if(TMath::Abs(dphiMin_)<0.5)continue;
      if(NAddBJet<2)continue;
      if((NAddMu_ + NAddEle_ + NAddTau_ )!=1)continue;
      eventControl = true;
      }
      if(id == 23)//z to nunu + jet
      {
      h_cutFlow ->Fill(0);
      if((Mass_>30 && Mass_<100) || (Mass_>150 && Mass_<250)){
        h_cutFlow ->Fill(1); //1
        if(CSV2_ < 0.605)continue;
        h_cutFlow ->Fill(2); //2
        if(CSV1_ < 0.605)continue;
        h_cutFlow ->Fill(3); //3
        if(JetMetDPhi_<2.5)continue;
        h_cutFlow ->Fill(4); //4
        if(TMath::Abs(dphiMin_)<0.4)continue;
        h_cutFlow ->Fill(5); //5
        if(NAddBJet!=0)continue;
        h_cutFlow ->Fill(6); //6
        if((NAddMu_ + NAddEle_ + NAddTau_ )!=0)continue;
        h_cutFlow ->Fill(7); //7
      eventControl = true;
        }
      }
      if(!eventControl)continue;
      countEvent++;
      float weight = 0.0;
      weight = MCweight_ * EWKweight_ * PUweight_ * BTAGSF_;
      const char *str = fileName[8].c_str();
      if(strstr(str,"Merged_MET")){
	std::cout<<run_<<":"<<lumi_ <<":"<<event_<<std::endl;
      h_nMuons ->Fill(NAddMu_);
      h_nTaus ->Fill(NAddTau_);
      h_nElectrons->Fill(NAddEle_);
      h_DRSJ ->Fill(DRSJ_);
      h_NThinJets ->Fill(NAddBJet);
      h_MET ->Fill(MET_);
      h_Mjj ->Fill(Mass_);
      h_pTjj ->Fill(JetPt_);
      h_etajj ->Fill(JetEta_);
      h_phijj ->Fill(JetPhi_);
      h_Tau21jj ->Fill(Tau21_);
      h_CSVMax ->Fill(MaxCSV_);
      h_CSVMin ->Fill(MinCSV_);
      h_CSVSum ->Fill(JetCSVSum_);
      h_dPhi_MET_J ->Fill(dphiMin_);
      h_MET_Over_SumET ->Fill(MET_/SumET_);
      h_MET_Over_pTFatJet ->Fill(MET_/JetPt_);
      h_CEmEF ->Fill(jetCEmEF_);
      h_CHadEF ->Fill(jetCHadEF_);
      h_PhoEF ->Fill(jetPhoEF_);
      h_NEmEF ->Fill(jetNEmEF_);
      h_NHadEF ->Fill(jetNHadEF_);
      h_MuEF ->Fill(jetMuEF_);
      h_CMulti ->Fill(jetCMulti_);
      }else {
	//if(strstr(str,"Merged_TT")){
	//std::cout<<run_<<"  "<<lumi_ <<"  "<<event_<<std::endl;
	//}
      h_nMuons ->Fill(NAddMu_,weight);
      h_nTaus ->Fill(NAddTau_,weight);
      h_nElectrons->Fill(NAddEle_,weight);
      h_DRSJ ->Fill(DRSJ_,weight);
      h_NThinJets ->Fill(NAddBJet,weight);
      h_MET ->Fill(MET_,weight);
      h_Mjj ->Fill(Mass_,weight);
      h_pTjj ->Fill(JetPt_,weight);
      h_etajj ->Fill(JetEta_,weight);
      h_phijj ->Fill(JetPhi_,weight);
      h_Tau21jj ->Fill(Tau21_,weight);
      h_CSVMax ->Fill(MaxCSV_,weight);
      h_CSVMin ->Fill(MinCSV_,weight);
      h_CSVSum ->Fill(JetCSVSum_,weight);
      h_dPhi_MET_J ->Fill(dphiMin_,weight);
      h_MET_Over_SumET ->Fill(MET_/SumET_,weight);
      h_MET_Over_pTFatJet ->Fill(MET_/JetPt_,weight);
      h_CEmEF ->Fill(jetCEmEF_,weight);
      h_CHadEF ->Fill(jetCHadEF_,weight);
      h_PhoEF ->Fill(jetPhoEF_,weight);
      h_NEmEF ->Fill(jetNEmEF_,weight);
      h_NHadEF ->Fill(jetNHadEF_,weight);
      h_MuEF ->Fill(jetMuEF_,weight);
      h_CMulti ->Fill(jetCMulti_,weight);
      
      }
          
}//ENTRIES
h_event->Fill(countEvent);
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
      h_cutFlow ->Write();
      h_nMuons ->Write();
      h_nTaus ->Write();
      h_nElectrons->Write();
      h_DRSJ ->Write();
      h_NThinJets ->Write();
      h_MET ->Write();
      h_Mjj ->Write();
      h_pTjj ->Write();
      h_etajj ->Write();
      h_phijj ->Write();
      h_Tau21jj ->Write();
      h_CSVMax ->Write();
      h_CSVMin ->Write();
      h_CSVSum ->Write();
      h_dPhi_MET_J ->Write();
      h_MET_Over_SumET ->Write();
      h_MET_Over_pTFatJet ->Write();
      h_CEmEF ->Write();
      h_CHadEF ->Write();
      h_PhoEF ->Write();
      h_NEmEF ->Write();
      h_NHadEF ->Write();
      h_MuEF ->Write();
      h_CMulti ->Write();
      h_event->Write();

outFile->Close();

}//files
 }//.cc
