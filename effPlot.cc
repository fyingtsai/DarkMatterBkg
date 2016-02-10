#include "iostream"
#include "TFile.h"
#include "untuplizer.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "TH1.h"
#include "TROOT.h"
#include "TObject.h"
#include <TStyle.h>
#include "TLegend.h"
#include <TLatex.h>
#include "TLine.h"
#include <TMath.h>
#include "setNCUStyle.C"

const char* const file[8]={
"/afs/cern.ch/user/k/khurana/public/ForBTagUnc/MonoHFatJetAnalysis_ForAn_AllMETTriggers_WithBTagScaleFactors_WithPU_OldTTBar_TightMuonID_LooseBTAG_NJets_XPOG_2/Merged_MonoHToBBarMZp-600GeV_MA0-300GeV-runallAnalysis.root",
"/afs/cern.ch/user/k/khurana/public/ForBTagUnc/MonoHFatJetAnalysis_ForAn_AllMETTriggers_WithBTagScaleFactors_WithPU_OldTTBar_TightMuonID_LooseBTAG_NJets_XPOG_2/Merged_MonoHToBBarMZp-800GeV_MA0-300GeV-runallAnalysis.root",
"/afs/cern.ch/user/k/khurana/public/ForBTagUnc/MonoHFatJetAnalysis_ForAn_AllMETTriggers_WithBTagScaleFactors_WithPU_OldTTBar_TightMuonID_LooseBTAG_NJets_XPOG_2/Merged_MonoHToBBarMZp-1000GeV_MA0-300GeV-runallAnalysis.root",
"/afs/cern.ch/user/k/khurana/public/ForBTagUnc/MonoHFatJetAnalysis_ForAn_AllMETTriggers_WithBTagScaleFactors_WithPU_OldTTBar_TightMuonID_LooseBTAG_NJets_XPOG_2/Merged_MonoHToBBarMZp-1200GeV_MA0-300GeV-runallAnalysis.root",
"/afs/cern.ch/user/k/khurana/public/ForBTagUnc/MonoHFatJetAnalysis_ForAn_AllMETTriggers_WithBTagScaleFactors_WithPU_OldTTBar_TightMuonID_LooseBTAG_NJets_XPOG_2/Merged_MonoHToBBarMZp-1400GeV_MA0-300GeV-runallAnalysis.root",
"/afs/cern.ch/user/k/khurana/public/ForBTagUnc/MonoHFatJetAnalysis_ForAn_AllMETTriggers_WithBTagScaleFactors_WithPU_OldTTBar_TightMuonID_LooseBTAG_NJets_XPOG_2/Merged_MonoHToBBarMZp-1700GeV_MA0-300GeV-runallAnalysis.root",
"/afs/cern.ch/user/k/khurana/public/ForBTagUnc/MonoHFatJetAnalysis_ForAn_AllMETTriggers_WithBTagScaleFactors_WithPU_OldTTBar_TightMuonID_LooseBTAG_NJets_XPOG_2/Merged_MonoHToBBarMZp-2000GeV_MA0-300GeV-runallAnalysis.root",
"/afs/cern.ch/user/k/khurana/public/ForBTagUnc/MonoHFatJetAnalysis_ForAn_AllMETTriggers_WithBTagScaleFactors_WithPU_OldTTBar_TightMuonID_LooseBTAG_NJets_XPOG_2/Merged_MonoHToBBarMZp-2500GeV_MA0-300GeV-runallAnalysis.root"
};

void effPlot()
{
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetFrameLineWidth(3);
    gStyle->SetLineWidth(3);
    setNCUStyle();
    TCanvas *c1 = new TCanvas("Hist", "Hist", 0,0,500,500); 
    TLegend* leg = new TLegend(0.43,0.6593,0.9,0.8761);

    double h_1[8],h_2[8],h_3[8],h_4[8],h_5[8];
    double err_h1[8],err_h2[8],err_h3[8],err_h4[8],err_h5[8];
    double scale_1[8],scale_2[8],scale_3[8],scale_4[8];
    double error_y1[8],error_y2[8],error_y3[8],error_y4[8];
    double error_x [8]= {0,0,0,0,0,0,0,0};
    double mass[8] ={600,800,1000,1200,1400,1700,2000,2500};

    for(int i=0; i<8; i++){
        TFile *inputFile;
        inputFile = new TFile(file[i],"READ");
        inputFile->cd("MonoHFatJetSelection_JetAndLeptonVeto");
        TH1F* h1 = (TH1F*) gDirectory -> Get("h_nMuons0");
        h_1[i] = h1->Integral();
        err_h1[i] = h1->GetBinError(1);
        inputFile->cd("MonoHFatJetSelection_JetAndLeptonVetoBTagUp");
        TH1F* h2 = (TH1F*) gDirectory -> Get("h_nMuons0");
        h_2[i] = h2->Integral();
        err_h2[i] = h2->GetBinError(1);
        inputFile->cd("MonoHFatJetSelection_JetAndLeptonVetoBTagDown");
        TH1F* h3 = (TH1F*) gDirectory -> Get("h_nMuons0");
        h_3[i] = h3->Integral();
        err_h3[i] = h3->GetBinError(1);
        inputFile->cd("MonoHFatJetSelection_JetAndLeptonVetoMETUp");
        TH1F* h4 = (TH1F*) gDirectory -> Get("h_nMuons0");
        h_4[i] = h4->Integral();
        err_h4[i] = h4->GetBinError(1);
        inputFile->cd("MonoHFatJetSelection_JetAndLeptonVetoMETDown");
        TH1F* h5 = (TH1F*) gDirectory -> Get("h_nMuons0");
        h_5[i] = h5->Integral();
        err_h5[i] = h5->GetBinError(1);

    }

    for (int i=0;i<8;i++){
        scale_1[i]= h_2[i]/h_1[i];
        scale_2[i]= h_3[i]/h_1[i];
        scale_3[i]= h_4[i]/h_1[i];
        scale_4[i]= h_5[i]/h_1[i];
    }
    for (int i=0;i<8;i++){
        error_y1[i]= scale_1[i]*((err_h1[i]/h_1[i])+(err_h2[i]/h_2[i]));
        error_y2[i]= scale_2[i]*((err_h1[i]/h_1[i])+(err_h3[i]/h_3[i]));
        error_y3[i]= scale_3[i]*((err_h1[i]/h_1[i])+(err_h4[i]/h_4[i]));
        error_y4[i]= scale_4[i]*((err_h1[i]/h_1[i])+(err_h5[i]/h_5[i]));
        cout<<"error_y1:"<<error_y1[i]<<"error_y2:"<<error_y2[i]<<"error_y3:"<<error_y3[i]<<"error_y4:"<<error_y4[i]<<endl;
    }

    TGraphErrors* gr1 = new TGraphErrors(8,mass,scale_1,error_x,error_y1);
    gr1->SetTitle("BTagUp");
    gr1->SetMarkerColor(2);
    gr1->SetMarkerStyle(20);
    TGraphErrors* gr2 = new TGraphErrors(8,mass,scale_2,error_x,error_y2);
    gr2->SetTitle("BTagDown");
    gr2->SetMarkerColor(3);
    gr2->SetMarkerStyle(21);
    TGraphErrors* gr3 = new TGraphErrors(8,mass,scale_3,error_x,error_y3);
    gr3->SetTitle("METUp");
    gr3->SetMarkerColor(4);
    gr3->SetMarkerStyle(22);
    TGraphErrors* gr4 = new TGraphErrors(8,mass,scale_4,error_x,error_y4);
    gr4->SetTitle("METDown");
    gr4->SetMarkerColor(5);
    gr4->SetMarkerStyle(33);

    cout<<"test1"<<endl;
    TMultiGraph *mg = new TMultiGraph("mg","mg");
    cout<<"test11"<<endl;
    mg->Add(gr1);
    mg->Add(gr2);
    mg->Add(gr3);
    mg->Add(gr4);
    mg->Draw("ap");
    // mg->GetXaxis()->SetTitle("m_{Zp}(GeV)");
    // mg->GetYaxis()->SetTitle("Scale");
    // mg->GetXaxis()->SetRangeUser(400,2600);
    mg->SetMinimum(0.5);
    mg->SetMaximum(1.5);
    c1->BuildLegend();
    c1->Modified();
    c1->Update();
    c1->cd();
    // c1->Print("graph1.png");
    c1->SaveAs("graph1.png");
    // Latex
    TString latexCMSname= "CMS Simulation at  #sqrt{s} = 13TeV";
    TLatex Tl; Tl.SetTextFont(72); Tl.SetTextSize(0.05); 
    Tl.SetNDC(kTRUE); 
    Tl.SetTextAlign(22);
    Tl.DrawLatex(0.4,0.95,latexCMSname);

    TFile* outFile = new TFile("output.root","recreate");
    mg->Write();
    outFile->Close();
}