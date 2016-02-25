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

const char* const file[34]={
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-600GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-800GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-1000GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-1200GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-1400GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-1700GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-2000GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MonoHToBBarMZp-2500GeV_MA0-300GeV-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_TT_TuneCUETP8M1_13TeV-powheg-pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_WW_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_WZ_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_ZH_HToBB_ZToNuNu_M120_13TeV_amcatnloFXFX_madspin_pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_ZJetsToNuNu_HT-100To200_13TeV-madgraph-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_ZJetsToNuNu_HT-200To400_13TeV-madgraph-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_ZJetsToNuNu_HT-400To600_13TeV-madgraph-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_ZJetsToNuNu_HT-600ToInf_13TeV-madgraph-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_ZZ_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_crab_MET-Run2015C_25ns-05Oct2015V120160203_FullDataSet_2p2FB_SkipEventsOldFile29Oct-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_crab_MET-Run2015D-05Oct2015V120160203_FullDataSet_2p2FB_SkipEventsOldFile29Oct-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_crab_MET-Run2015D-PromptReco-V420160203_FullDataSet_2p2FB_SkipEventsOldFile29Oct-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8-runallAnalysis.root",
     "/afs/cern.ch/user/k/khurana/public/ForBTagUnc/AnalysisTuples_V2/Merged_MET.root"
};

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); 
  string tok;
  
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
  
  return internal;
}

void subjStudy(){
  int nobjectmet=34;
  gSystem->mkdir("rootDirectory"); 

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

  for(int i=0; i<34; i++)
    {
        TFile *inputFile;
        inputFile = new TFile(file[i],"READ");
        TTree *tree = (TTree*)inputFile->Get("skimTreeMonoHFatJetsPreselection_2subj");
        TString outputFile;
        string searchFile = file[i];
        vector<string> fileName = split(searchFile, '/');
        outputFile = fileName[9];
        cout << "Output file = " << outputFile.Data() << endl;

TreeReader data(tree);
setNCUStyle();

TString postfix;
int countEvent=0;
postfix.Form("%d",i);

    h_nMuons[i]     = new TH1F("h_nMuons"+postfix,"h_nMuons",10,0,10);
    h_nTaus[i]      = new TH1F("h_nTaus"+postfix,"h_nTaus",10,0,10);
    h_nElectrons[i] = new TH1F("h_nElectrons"+postfix,"h_nElectrons",10,0,10);
    h_nJets[i]      = new TH1F("h_nJetss"+postfix,"h_nJetss",10,0,10);
    h_nFJets[i]     = new TH1F("h_nFJets"+postfix,"h_nFJets",10,0,10);
    h_DRSJ[i]       = new TH1F("h_DRSJ"+postfix,"h_DRSJ",100,0,5);
    h_NThinJets[i]  = new TH1F("h_NThinJets"+postfix,"h_NThinJets",10,0,10);

    h_dPhiThinJetMET[i] = new TH1F("h_dPhiThinJetMET"+postfix,"h_dPhiThinJetMET",70,-3.5,3.5);

    h_Q1Q2[i]       = new TH1F("h_Q1Q2"+postfix,"h_Q1Q2",21,-10,10);
    h_MET[i]        = new TH1F("h_MET"+postfix,"h_MET",300,0,3000);
    h_MHT[i]        = new TH1F("h_MHT"+postfix,"h_MHT",300,0,3000);
    h_Mjj[i]        = new TH1F("h_Mjj"+postfix,"",300,0,3000);
    h_pTjj[i]       = new TH1F("h_pTjj"+postfix,"",300,0,3000);
    h_etajj[i]      = new TH1F("h_etajj"+postfix,"",50,-2.5,2.5);
    h_phijj[i]      = new TH1F("h_phijj"+postfix,"",70,-3.5,3.5);
    h_Tau21jj[i]    = new TH1F("h_h_Tau21jj"+postfix,"",20,0.,1.);

    h_CSVMax[i]     = new TH1F("h_CSVMax"+postfix,"",20,0,1);
    h_CSVMin[i]     = new TH1F("h_CSVMin"+postfix,"",20,0,1);
    h_CSV1[i]       = new TH1F("h_CSV1"+postfix,"",20,0,1);
    h_CSV2[i]       = new TH1F("h_CSV2"+postfix,"",20,0,1);
    h_CSVSum[i]     = new TH1F("h_CSVSum"+postfix,"",40,0,2);
    h_dPhi_MET_J[i] = new TH1F("h_dPhi_MET_J"+postfix,"",70,0.,3.5);
    h_MT_bb_MET[i]  = new TH1F("h_MT_bb_MET"+postfix,"",1000,0,5000.);
    h_dPhi_bb_MET[i]= new TH1F("h_dPhi_bb_MET"+postfix,"",100,0,3.5);

    h_MET_Over_SumET[i]    = new TH1F("h_MET_Over_SumET"+postfix,"",20,0,1.);
    h_MET_Over_pTFatJet[i] = new TH1F("h_MET_Over_pTFatJet"+postfix,"",100,0,5);
    h_CEmEF[i]             = new TH1F("h_CEmEF"+postfix,"",20,0,1);
    h_CHadEF[i]            = new TH1F("h_CHadEF"+postfix,"",20,0,1);
    h_PhoEF[i]             = new TH1F("h_PhoEF"+postfix,"",20,0,1);
    h_NEmEF[i]             = new TH1F("h_NEmEF"+postfix,"",20,0,1);
    h_NHadEF[i]            = new TH1F("h_NHadEF"+postfix,"",20,0,1);
    h_MuEF[i]              = new TH1F("h_MuEF"+postfix,"",20,0,1);
    h_CMulti[i]            = new TH1F("h_CMulti"+postfix,"",20,0,1);
    h_event[i]             = new TH1F("h_event"+postfix,"",100,0,100);

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

      if(Mass_<100 || 150<Mass_)continue;
      if(JetMetDPhi_<2.5)continue;
      if(dphiMin_<0.5)continue;
      if(NAddBJet!=0)continue;
      if(NAddMu_ + NAddEle_ + NAddTau_ !=0)continue;
      countEvent++;

      h_nMuons[i] ->Fill(NAddMu_);
      h_nTaus[i] ->Fill(NAddTau_);
      h_nElectrons[i]->Fill(NAddEle_);
      h_DRSJ[i] ->Fill(DRSJ_);
      h_NThinJets[i] ->Fill(NAddBJet);
      h_MET[i] ->Fill(MET_);
      h_Mjj[i] ->Fill(Mass_);
      h_pTjj[i] ->Fill(JetPt_);
      h_etajj[i] ->Fill(JetEta_);
      h_phijj[i] ->Fill(JetPhi_);
      h_Tau21jj[i] ->Fill(Tau21_);
      h_CSVMax[i] ->Fill(MaxCSV_);
      h_CSVMin[i] ->Fill(MinCSV_);
      h_CSVSum[i] ->Fill(JetCSVSum_);
      h_dPhi_MET_J[i] ->Fill(dphiMin_);
      h_MET_Over_SumET[i] ->Fill(MET_/SumET_);
      h_MET_Over_pTFatJet[i] ->Fill(MET_/JetPt_);
      h_CEmEF[i] ->Fill(jetCEmEF_);
      h_CHadEF[i] ->Fill(jetCHadEF_);
      h_PhoEF[i] ->Fill(jetPhoEF_);
      h_NEmEF[i] ->Fill(jetNEmEF_);
      h_NHadEF[i] ->Fill(jetNHadEF_);
      h_MuEF[i] ->Fill(jetMuEF_);
      h_CMulti[i] ->Fill(jetCMulti_);

}//ENTRIES
h_event[i]->Fill(countEvent);
// cout<<"Event:"<<countEvent<<endl;
gSystem->cd("rootDirectory");

TFile* outFile = new TFile(outputFile.Data(),"recreate");

      h_nMuons[i] ->Write();
      h_nTaus[i] ->Write();
      h_nElectrons[i]->Write();
      h_DRSJ[i] ->Write();
      h_NThinJets[i] ->Write();
      h_MET[i] ->Write();
      h_Mjj[i] ->Write();
      h_pTjj[i] ->Write();
      h_etajj[i] ->Write();
      h_phijj[i] ->Write();
      h_Tau21jj[i] ->Write();
      h_CSVMax[i] ->Write();
      h_CSVMin[i] ->Write();
      h_CSVSum[i] ->Write();
      h_dPhi_MET_J[i] ->Write();
      h_MET_Over_SumET[i] ->Write();
      h_MET_Over_pTFatJet[i] ->Write();
      h_CEmEF[i] ->Write();
      h_CHadEF[i] ->Write();
      h_PhoEF[i] ->Write();
      h_NEmEF[i] ->Write();
      h_NHadEF[i] ->Write();
      h_MuEF[i] ->Write();
      h_CMulti[i] ->Write();
      h_event[i]->Write();

outFile->Close();

}//files
}//.cc