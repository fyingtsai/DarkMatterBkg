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


void plot()
{
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetFrameLineWidth(3);
    
    TCanvas *c1 = new TCanvas("c1","hist",900,700);
    TLegend* leg = new TLegend(0.43,0.6593,0.9,0.8761);
    
    TFile *f_mzp1 = TFile::Open("Veto.root");
    TFile *f_mzp2 = TFile::Open("Veto_TTbar.root");
    TFile *f_mzp3 = TFile::Open("Veto_DY.root");

    TH1F* h_A0m1 = (TH1F*)f_mzp1->Get("h_nEle");
    TH1F* h_A0m2 = (TH1F*)f_mzp2->Get("h_nEle");
    TH1F* h_A0m3 = (TH1F*)f_mzp3->Get("h_nEle"); 

    float scale1 = 1.0/h_A0m1->Integral();
    float scale2 = 1.0/h_A0m2->Integral();
    float scale3 = 1.0/h_A0m3->Integral();

    cout<<"Zp_Nevt:"<<h_A0m1->Integral()<<endl;
    cout<<"TTbar_Nevt:"<<h_A0m2->Integral()<<endl;
    cout<<"DY_Nevt:"<<h_A0m3->Integral()<<endl;


    h_A0m1->Scale(scale1);
    h_A0m2->Scale(scale2);
    h_A0m3->Scale(scale3);

    h_A0m1->SetLineColor(1);
    h_A0m2->SetLineColor(2);
    h_A0m3->SetLineColor(3);

    h_A0m1->GetXaxis()->SetTitleFont(22);
    h_A0m1->GetYaxis()->SetTitleFont(22);
    h_A0m2->GetXaxis()->SetLabelFont(22);
    h_A0m2->GetYaxis()->SetLabelFont(22);
    h_A0m3->GetXaxis()->SetLabelFont(22);
    h_A0m3->GetYaxis()->SetLabelFont(22);
    
    h_A0m1->GetXaxis()->SetTitleSize(0.045);
    h_A0m1->GetYaxis()->SetTitleSize(0.045);  
    h_A0m2->GetXaxis()->SetLabelSize(0.045);
    h_A0m2->GetYaxis()->SetLabelSize(0.045);
    h_A0m3->GetXaxis()->SetLabelSize(0.045);
    h_A0m3->GetYaxis()->SetLabelSize(0.045);

    h_A0m1->GetYaxis()->SetTitleOffset(1.45);
    h_A0m2->GetYaxis()->SetTitleOffset(1.45);
    h_A0m3->GetYaxis()->SetTitleOffset(1.45);   

    h_A0m1->SetLineWidth(2);
    h_A0m2->SetLineWidth(2);
    h_A0m3->SetLineWidth(2);
    // h->SetLineColor(1);

    h_A0m1->GetYaxis()->SetRange(0,700);
    h_A0m2->GetYaxis()->SetRange(0,700);
    h_A0m3->GetYaxis()->SetRange(0,700);

    h_A0m1->Draw("hist");        
    h_A0m2->Draw("hitsame");
    h_A0m3->Draw("hitssame"); 

    leg->AddEntry(h_A0m1,"MZ'_1000GeV");
    leg->AddEntry(h_A0m2,"TTbar");
    leg->AddEntry(h_A0m3,"DY Jet");

    leg->Draw();

    c1->Update();

}