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
#include "TakeFunction.h"

const char* const file[3]={
                            "gz028.root",
                            "gz05.root",
                            "gz08.root"
                          };

// bool TriggerStatus(string*  trigName, vector<bool> &hlt_trigResult, Int_t nsize, string TRIGNAME){
//     bool triggerstate=false;
//     for(size_t i=0; i<nsize;i++){
//         std::string thisTrig= trigName[i];
//         size_t found = thisTrig.find(TRIGNAME);
//         if(found==string::npos)continue;
//         triggerstate= hlt_trigResult[i];
//     }
//     return triggerstate;
// }

void gzStudy(){
  for(int i=0; i<3; i++){
  string inputFile = file[i];
  cout<<"inputFile:"<<inputFile<<endl;
  TString outputFile;
  std::vector<string> infiles;
  outputFile = Form("output_%d.root",i);
  cout << "Output file = " << outputFile.Data() << endl;
  infiles.push_back(Form("%s",inputFile.data()));

TreeReader data(infiles);
setNCUStyle();
int countEvent=0;
TakeFunction fun;

TH1F* h_MET = new TH1F("h_MET","h_MET",50,0,1000);
TH1F* h_PRCorrMass = new TH1F("h_PRCorrMass","h_PRCorrMass",50,50,200);

for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
       if (jEntry % 50000 == 0)
       fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());
    data.GetEntry(jEntry);

/********* Filter & Trigger **********/
    Bool_t hlt_hbhet          = data.GetBool("hlt_hbhet");
    Int_t nVtx          = data.GetInt("nVtx");
    // vector<bool> &trigResult = *((vector<bool>*) data.GetPtr("hlt_trigResult"));
    // std::string*  trigName = data.GetPtrString("hlt_trigName");
    const Int_t nsize = data.GetPtrStringSize();

    // if(!TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET170_NoiseCleaned_") && 
       // !TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET120_PFMHT120_IDLoose_")) continue;
    if(hlt_hbhet != 1)continue;
    if(nVtx <= 0)continue;

/********* FatJet Selection **********/
    TClonesArray* FatJetP4 = (TClonesArray*) data.GetPtrTObject("FATjetP4");
    Float_t *FATjetPRmass  = data.GetPtrFloat("FATjetPRmass");
    Float_t *FATjetPRmassL2L3Corr  = data.GetPtrFloat("FATjetPRmassL2L3Corr");
    if(fun.getFatJetIndex(data) == -1)continue;
    TLorentzVector* maxFJet = (TLorentzVector*)FatJetP4->At(fun.getFatJetIndex(data));

/********** MET cuts ***************/
    Float_t pfMetCorrPt     = data.GetFloat("pfMetCorrPt");
    Float_t pfMetCorrPhi    = data.GetFloat("pfMetCorrPhi");
    if(pfMetCorrPt < 200) continue;
    if(!fun.isPassPhiMETFJet(data,maxFJet))continue; //dPhi(FJet,MET)>2.5
    if(fabs(DeltaPhi(fun.getQCDJetTLorentz(data,maxFJet).Phi(),pfMetCorrPhi))<0.5)continue;

/****** ThinJet Veto **********/
if(fun.numThinJet(data,maxFJet)!=0)continue;

/****** Lep Veto *************/
if((fun.numEle(data,maxFJet) + fun.numMuon(data,maxFJet) + fun.numTau(data,maxFJet))!=0)continue;
// h_dPRMass->Fill((FATjetPRmassL2L3Corr[fun.getFatJetIndex(data)]-FATjetPRmass[fun.getFatJetIndex(data)])/FATjetPRmass[fun.getFatJetIndex(data)]);
h_MET->Fill(pfMetCorrPt);
h_PRCorrMass->Fill(FATjetPRmassL2L3Corr[fun.getFatJetIndex(data)]);
countEvent++;
}//ENTRIES

// cout<<"Mean:"<<h_dPRMass->GetMean()<<" Error:"<<h_dPRMass->GetMeanError()<<endl;
TFile* outFile = new TFile(outputFile.Data(),"recreate");
h_MET->Write();
h_PRCorrMass->Write();
outFile->Close();

}//files
}//.cc