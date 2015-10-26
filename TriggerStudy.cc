#define M1200TriggerStudy_cxx
#include "M1200TriggerStudy.h"
#include <TH2.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include "TLorentzVector.h"
#include "TGraphAsymmErrors.h"
#include "untuplizer.h"
#include <fstream>
#include <map>
#include <TFile.h>
#include "setNCUStyle.C"
using namespace std;


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

void TriggerStudy(string inputFile)
{

      TString outputFile;
    std::vector<string> infiles;
  
    if(inputFile.find(".root")!= std::string::npos)
      {
        TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
        outputFile = Form("trigger%s.root",endfix.Data());
        cout << "Output file_ = " << outputFile << endl;
      }
    else{
        TString endfix=gSystem->GetFromPipe(Form("file=%s; test=${file##*/}; echo \"${test%%.root*}\"",inputFile.data()));
        outputFile = Form("trigger%s.root",endfix.Data());
        cout << "Output file = " << outputFile.Data() << endl;
      
      
    TSystemDirectory *base = new TSystemDirectory("root","root");
    base->SetDirectory(inputFile.data());
    TList *listOfFiles = base->GetListOfFiles();
    TIter fileIt(listOfFiles);
    TFile *fileH = new TFile();
    Long64_t nfiles=0;
        while(fileH = (TFile*)fileIt()) {
        std::string fileN = fileH->GetName();
        std::string baseString = "treeMaker"; 
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

    int goodjetsEvt=0;
    int MET120ORMET170=0;

    float lower[] = {0,50,100,150,200,250,300,500,1000};

    TFile* myFile = new TFile("Eff_trigger.root", "RECREATE");
    TH1F* h_PFMET = new TH1F("h_PFMET","h_PFMET",8, lower);
    TH1F* h_Trigger = new TH1F("h_Trigger","PFMET170_NoiseCleaned OR PFMET120_PFMHT120_IDLoose",8,lower);

    for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
       if (jEntry % 50000 == 0)
       fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());

    data.GetEntry(jEntry);

    vector<bool> &trigResult = *((vector<bool>*) data.GetPtr("hlt_trigResult"));
    std::string*  trigName = data.GetPtrString("hlt_trigName");
    Float_t pfMetRawPt     = data.GetFloat("pfMetRawPt");
    Int_t THINnJet             = data.GetInt("THINnJet");
    TClonesArray* THINjetP4 = (TClonesArray*) data.GetPtrTObject("THINjetP4");
    Float_t *THINjetCISVV2  = data.GetPtrFloat("THINjetCISVV2");
    const Int_t nsize = data.GetPtrStringSize();
    
    // int ngoodjets=0;
    //     for(Int_t i=0;i<THINnJet;i++){
    //         TLorentzVector* thisJetP4 = (TLorentzVector*)THINjetP4->At(i);
    //         if(fabs(thisJetP4->Eta())<2.5 && THINjetCISVV2[i] > 0.432 && thisJetP4->Pt() > 20. ){
    //             ngoodjets++;
    //         }
    //     }
        //Btag Eff
    h_PFMET->Fill(pfMetRawPt);
        if(TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET170_NoiseCleaned_v1") || 
           TriggerStatus(trigName,trigResult,nsize,"HLT_PFMET120_PFMHT120_IDLoose_v1")){
            MET120ORMET170++;
            h_Trigger->Fill(pfMetRawPt);
        }

    }//End Event

TGraphAsymmErrors* Eff_PFMET170OR120_MET = new TGraphAsymmErrors(h_Trigger,h_PFMET,"b");

myFile->cd();
TCanvas *c1 = new TCanvas("c1","",200,10,700,900);
c1->SetGridx();
c1->SetGridy();
gStyle->SetOptFit(1011);
TF1 *f1 = new TF1("f1"," (1.0-exp([0]*([1]-x)))*0.972", 120, 1000);
f1->SetParameters(0.042,75.7);

TAxis *axis1_met = Eff_PFMET170OR120_MET->GetXaxis();
axis1_met->SetTitle("MET Eff.");
Eff_PFMET170OR120_MET->Fit("f1");
Eff_PFMET170OR120_MET->Write();


myFile->Close();
cout<<"Nevent:"<<data.GetEntriesFast()<<endl;
cout<<"MET120ORMET170:"<<MET120ORMET170<<endl;
cout<<" eff_120OR170: "<<((float)MET120ORMET170/data.GetEntriesFast())*100<<"%"<<endl;

}//Loop Function
