#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "cstdlib"
#include "iostream"
#include "TStyle.h"
#include "TLegend.h"
#include "THStack.h"
#include "TLatex.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TStyle.h"
#include "TROOT.h"
#include "setNCUStyle.C"

void plot_gz()
{
    TCanvas *c1 = new TCanvas("c1","hmzp",900,700);
    TLegend* leg = new TLegend(0.43,0.6593,0.9,0.8761);
    
    TFile *f_gz028 = TFile::Open("output_0.root");
    TFile *f_gz05 = TFile::Open("output_1.root");
    TFile *f_gz08 = TFile::Open("output_2.root");

    TH1F* h_MET0 = (TH1F*)f_gz028->Get("h_MET");
    TH1F* h_PRCorr0 = (TH1F*)f_gz028->Get("h_PRCorrMass");
    TH1F* h_MET1 = (TH1F*)f_gz05->Get("h_MET");
    TH1F* h_PRCorr1 = (TH1F*)f_gz05->Get("h_PRCorrMass");
    TH1F* h_MET2 = (TH1F*)f_gz08->Get("h_MET");
    TH1F* h_PRCorr2 = (TH1F*)f_gz08->Get("h_PRCorrMass");

    // //hmzp;hht;hpth;hmbb;hmet;hdphibb;hdphij;hnmuo;hnjet;
    // //hptzp;hjetht;hnele
    float scale1 = 1.0/h_MET1->Integral();
    float scale2 = 1.0/h_PRCorr1->Integral();
    float scale3 = 1.0/h_MET2->Integral();
    float scale4 = 1.0/h_PRCorr2->Integral();
    float scale5 = 1.0/h_MET0->Integral();
    float scale6 = 1.0/h_PRCorr0->Integral();
    // float scale5 = 1.0/h_ZJetsToNuNu->Integral();
    // float scale6 = 1.0/h_WJetsToLNu->Integral();
    // float scale7 = 1.0/h_zpM700_hA0_bbxx->Integral();

    h_MET1->Scale(scale1);
    h_PRCorr1->Scale(scale2);
    h_MET2->Scale(scale3);
    h_PRCorr2->Scale(scale4);
    h_MET0->Scale(scale5);
    h_PRCorr0->Scale(scale6);
    // h_ZJetsToNuNu->Scale(scale5);
    // h_WJetsToLNu->Scale(scale6);
    // h_zpM700_hA0_bbxx->Scale(scale7);
    h_MET0->Sumw2();
    h_PRCorr0->Sumw2();
    h_MET1->Sumw2();
    h_PRCorr1->Sumw2();
    h_MET2->Sumw2();
    h_PRCorr2->Sumw2();
    // h_ZJetsToNuNu->Sumw2();
    // h_WJetsToLNu->Sumw2();
    setNCUStyle();
    h_MET0->SetLineColor(kBlack);
    h_MET1->SetLineColor(kBlue);
    h_MET2->SetLineColor(kRed);
    h_PRCorr0->SetLineColor(kBlack);
    h_PRCorr1->SetLineColor(kBlue);
    h_PRCorr2->SetLineColor(kRed);

    h_MET0->SetLineStyle(1);
    h_MET1->SetLineStyle(1);
    h_MET2->SetLineStyle(1);
    h_PRCorr0->SetLineStyle(1);
    h_PRCorr1->SetLineStyle(1);
    h_PRCorr2->SetLineStyle(1);
    // h_zpM700_hA0_bbxx->SetFillColor(kRed-10);
    
    // h_MET2->GetXaxis()->SetTitle("MET (GeV)");
    // h_MET2->Draw("hist");
    // h_MET1->Draw("histsame"); 
    // h_MET0->Draw("histsame"); 

    h_PRCorr0->GetXaxis()->SetTitle("m_{H} (GeV)");
    h_PRCorr0->Draw("hist");        
    h_PRCorr1->Draw("histsame");
    h_PRCorr2->Draw("histsame");

    // leg->AddEntry(h_MET0,"gz=0.28");
    // leg->AddEntry(h_MET1,"gz=0.5");
    // leg->AddEntry(h_MET2,"gz=0.8");
    leg->AddEntry(h_PRCorr0,"gz=0.28");
    leg->AddEntry(h_PRCorr1,"gz=0.5");
    leg->AddEntry(h_PRCorr2,"gz=0.8");

    leg->Draw();

    TString latexCMSname= "CMS Simulation at  #sqrt{s} = 13TeV";
    TLatex Tl; Tl.SetTextFont(72); Tl.SetTextSize(0.05); 
    Tl.SetNDC(kTRUE); 
    Tl.SetTextAlign(22);

    Tl.DrawLatex(0.4,0.95,latexCMSname);
    c1->Update();

}




