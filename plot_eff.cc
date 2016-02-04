#include "iostream"
#include "TFile.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TGraphErrors.h"
#include "TH1.h"
#include "TROOT.h"
#include "TObject.h"
#include <TStyle.h>
#include "TLegend.h"
#include <TLatex.h>
#include "TLine.h"
#include <TMath.h>
#include "setNCUStyle.C"

void plot_eff()
{
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetFrameLineWidth(3);
    gStyle->SetLineWidth(3);
    TCanvas *c1 = new TCanvas("Hist", "Hist", 0,0,500,500); 
    double num[7]={147,6096,13834,15307,15052,13178,11664};
    double denom[7] ={48900,45200,48900,47300,48200,46000,48500};
    double eff[7] ={0.00300613,0.134867,0.282904,0.323615,0.312282,0.286478,0.240495};
    double mass[7] ={600,800,1000,1200,1700,2000,2500};
    double err_num[7] = {12.1244,78.0769,117.618,123.721,122.687,114.795,108};
    double err_denom[7] = {221.133,212.603,221.133,217.486,219.545,214.476,220.227};
    double error_y[7];
    double error_x [7]= {0,0,0,0,0,0,0};
    for (int i=0;i<7;i++){
        error_y[i]= eff[i]*((err_num[i]/num[i])+(err_denom[i]/denom[i]));
        cout<<"error_y:"<<error_y[i]<<endl;
    }

    TGraphErrors* gr = new TGraphErrors(7,mass,eff,error_x,error_y);
    gr->SetMinimum(0);
    gr->SetMaximum(1);
    gr->GetXaxis()->SetRangeUser(400,2600);
    gr->GetXaxis()->SetTitle("M_{Zp}(GeV)");
    gr->GetYaxis()->SetTitle("Efficiency");
    gr->SetTitle("Efficiency");
    // gr->SetMarkerColor(4)
    gr->SetMarkerStyle(20);
    gr->Draw("AP");

    // Latex
    TString latexCMSname= "CMS Simulation at  #sqrt{s} = 13TeV";
    TLatex Tl; Tl.SetTextFont(72); Tl.SetTextSize(0.05); 
    Tl.SetNDC(kTRUE); 
    Tl.SetTextAlign(22);

    Tl.DrawLatex(0.4,0.93,latexCMSname);
    c1->Modified();
    c1->Update();
    c1->cd();
    c1->Print("graph1.png");
}