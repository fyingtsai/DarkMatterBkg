#include "iostream"
#include "TFile.h"
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

void plot()
{
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetFrameLineWidth(3);
    gStyle->SetLineWidth(3);
    setNCUStyle();
    TCanvas *c1 = new TCanvas("Hist", "Hist", 0,0,500,500); 
    TLegend* leg = new TLegend(0.43,0.6593,0.9,0.8761);
    double h1[7]={1916.11};
    double h2[7] ={1768.9};
    double h3[7] ={1916.11};
    double h4[7] ={1916.11};
    double h5[7] ={2069.01};
    double mass[7] ={600,800,1000,1200,1700,2000,2500};
    double eff_1[7],eff_2[7],eff_3[7],eff_4[7];
    double err_h1[7] = {62.7522};
    double err_h2[7] = {57.934};
    double err_h3[7] = {62.7522};
    double err_h4[7] = {62.7522};
    double err_h5[7] = {67.7618};
    double error_y1[7],error_y2[7],error_y3[7],error_y4[7];
    double error_x [7]= {0,0,0,0,0,0,0};
    for (int i=0;i<7;i++){
        eff_1[i]= h2[i]/h1[i];
        eff_2[i]= h3[i]/h1[i];
        eff_3[i]= h4[i]/h1[i];
        eff_4[i]= h5[i]/h1[i];
    }
    for (int i=0;i<7;i++){
        error_y1[i]= eff_1[i]*((err_h1[i]/h1[i])+(err_h2[i]/h2[i]));
        error_y2[i]= eff_2[i]*((err_h1[i]/h1[i])+(err_h3[i]/h3[i]));
        error_y3[i]= eff_3[i]*((err_h1[i]/h1[i])+(err_h4[i]/h4[i]));
        error_y4[i]= eff_4[i]*((err_h1[i]/h1[i])+(err_h5[i]/h5[i]));
        cout<<"error_y1:"<<error_y1[i]<<"error_y2:"<<error_y2[i]<<"error_y3:"<<error_y3[i]<<"error_y4:"<<error_y4[i]<<endl;
    }

    TGraphErrors* gr1 = new TGraphErrors(7,mass,eff_1,error_x,error_y1);
    gr1->SetTitle("BTagUp/JetAndLeptonVeto");
    gr1->SetMarkerColor(2);
    gr1->SetMarkerStyle(20);
    TGraphErrors* gr2 = new TGraphErrors(7,mass,eff_2,error_x,error_y2);
    gr2->SetTitle("BTagDown/JetAndLeptonVeto");
    gr2->SetMarkerColor(3);
    gr2->SetMarkerStyle(21);
    TGraphErrors* gr3 = new TGraphErrors(7,mass,eff_3,error_x,error_y3);
    gr3->SetTitle("METUp/JetAndLeptonVeto");
    gr3->SetMarkerColor(4);
    gr3->SetMarkerStyle(22);
    TGraphErrors* gr4 = new TGraphErrors(7,mass,eff_4,error_x,error_y4);
    gr4->SetTitle("METDown/JetAndLeptonVeto");
    gr4->SetMarkerColor(5);
    gr4->SetMarkerStyle(33);


    TMultiGraph *mg = new TMultiGraph("mg","mg");
    mg->Add(gr1);
    mg->Add(gr2);
    mg->Add(gr3);
    mg->Add(gr4);
    mg->Draw("ap");
    mg->GetXaxis()->SetTitle("m_{Zp}(GeV)");
    mg->GetYaxis()->SetTitle("Efficiency");
    mg->GetXaxis()->SetRangeUser(400,2600);
    mg->SetMinimum(0.5);
    mg->SetMaximum(1.5);

    // Latex
    TString latexCMSname= "CMS Simulation at  #sqrt{s} = 13TeV";
    TLatex Tl; Tl.SetTextFont(72); Tl.SetTextSize(0.05); 
    Tl.SetNDC(kTRUE); 
    Tl.SetTextAlign(22);
    Tl.DrawLatex(0.4,0.95,latexCMSname);
    c1->BuildLegend();
    c1->Modified();
    c1->Update();
    c1->cd();
    c1->Print("graph1.png");
}