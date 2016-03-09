import os
import sys
## Ratio is added Data/MC 
## Template macro is fed to a python variable
## 1.) Dir is created on DateBase 
## 2.) Starting Extension of your Dir..Like 
## in a day you want 2 directories jsut
## change the DirPreName
## Monika Mittal Khuarana
## Raman Khurana


if len(sys.argv) < 2 : 
    print "insufficiency inputs provided, please provide the directory with input files"

if len(sys.argv) ==2 : 
    print "plotting from directory ",sys.argv[1]
    inputdirname = sys.argv[1]

macro='''{
#include <ctime>
#include <cstdlib>
#include "TStyle.h" 
 time_t now = time(0);
 tm *ltm = localtime(&now);
 TString dirpathname;

 TString DirPreName = "'''+inputdirname+'''";
 dirpathname.Form("%d%1.2d%d",ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year);
 system("mkdir -p  " + DirPreName+dirpathname +"/MonoHROOT");
 system("mkdir -p  " + DirPreName+dirpathname +"/MonoHPdf");
 system("mkdir -p  " + DirPreName+dirpathname +"/MonoHPng");
 
 ofstream mout;
 mout.open(DirPreName+dirpathname +"/HISTPATH"+dirpathname +"Integral.txt",std::ios::app);
 ofstream rout;
 rout.open(DirPreName+dirpathname +"/HISTPATH"+dirpathname +"Integral.html",std::ios::app);
 ofstream tableout;
 tableout.open(DirPreName+dirpathname +"/HISTPATH"+dirpathname +"IntegralWithError.txt",std::ios::app);                                                                                          


gROOT->ProcessLine(".L /afs/hep.wisc.edu/cms/khurana/Monika/CMSSW_7_4_5/src/RKGlobalAnalyzer/tdrstyle.C");                                     setTDRStyle();
gStyle->SetOptStat(0);
gStyle->SetOptTitle(0);
gStyle->SetFrameLineWidth(3);
//gStyle->SetErrorX(0);
gStyle->SetLineWidth(1);

//Provide luminosity of total data
float lumi = 2263.5; // It will print on your plots too

std::vector<TString> filenameString;
//Change here Directories of the file

TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Script/CMSSW_7_4_1/src/DarkMatterBkg/'''+inputdirname+'''/"); 
// DYJets 1
filenameString.push_back(filenamepath + "Merged_WW_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");
//WJets  1
filenameString.push_back(filenamepath + "Merged_WW_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");

// Diboson WW WZ ZZ 2 3 4
filenameString.push_back(filenamepath + "Merged_WW_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WZ_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ZZ_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");
// TTJets 5
filenameString.push_back(filenamepath + "Merged_TT_TuneCUETP8M1_13TeV-powheg-pythia8-runallAnalysis.root");

//Raman ZH background 6                                                                                                                       
filenameString.push_back(filenamepath + "Merged_ZH_HToBB_ZToNuNu_M120_13TeV_amcatnloFXFX_madspin_pythia8-runallAnalysis.root"); 
//filenameString.push_back(filenamepath + "Merged_ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8-runallAnalysis.root");
//Raman Signal Sample 7-14
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-600GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-800GeV_MA0-300GeV-runallAnalysis.root");  
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-1000GeV_MA0-300GeV-runallAnalysis.root");  
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-1200GeV_MA0-300GeV-runallAnalysis.root");  
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-1400GeV_MA0-300GeV-runallAnalysis.root");  
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-1700GeV_MA0-300GeV-runallAnalysis.root");  
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-2000GeV_MA0-300GeV-runallAnalysis.root");  
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-2500GeV_MA0-300GeV-runallAnalysis.root");  


//DYJets High pt DYSample 15,16,17,18
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-100To200_13TeV-madgraph-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-200To400_13TeV-madgraph-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-400To600_13TeV-madgraph-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-600ToInf_13TeV-madgraph-runallAnalysis.root");


//filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-50_HT-600toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");


// WJets in Bins  19,20,21,22,23,24,25
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");

// Single Top 26,27,28,29,30
filenameString.push_back(filenamepath + "Merged_ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root");

                                                                   
//Data File
//filenameString.push_back(filenamepath + "Merged_MET-Run2015B-PromptReco-v1TotalV3-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_MET.root");
//histoname

//const int n_integral = (int)filenameString.size();

TString histnameString("HISTPATH/HISTNAME");

TFile *fIn;
const int nfiles = (int) filenameString.size();

float Integral[nfiles] , Integral_Error[nfiles];

//check it once
float Xsec[nfiles];
Xsec[0] = 6104;
Xsec[1] = 61500;
Xsec[2] = 118.7; 
Xsec[3] = 66.1;
Xsec[4] = 15.4;

//float Stt = 0.894141 ;
float Stt = 1.0;//7.0633e-01 ;

Xsec[5] = Stt * 831.76; // ttbar

Xsec[6] = (0.8696) * 0.577 * 0.2 ; //ZH checked from Michele
float scalexs=1.; 
Xsec[7]  = scalexs * 0.026;//600
Xsec[8]  = scalexs * 0.0288;//800
Xsec[9] = scalexs * 0.02337; //1000
Xsec[10] = scalexs * 0.01832; //1200
Xsec[11] = scalexs * 0.01359; //1400
Xsec[12] = scalexs * 0.00871; //1700
Xsec[13] = scalexs * 0.00561; //2000
Xsec[14] = scalexs * 0.00280; //2500


float Sznunu = 1.0;//7.0000e-01;
Xsec[15] = Sznunu *  1.626*280.47; // Znunu HT
Xsec[16] = Sznunu *  1.617*78.36; // Znunu HT
Xsec[17] = Sznunu *  1.459*10.94; // Znunu HT
Xsec[18] = Sznunu *  1.391*4.203;  // Znunu HT

//Xsec[15] = 1.23*280.47; // Znunu HT
//Xsec[16] = 1.23*78.36; // Znunu HT
//Xsec[17] = 1.23*10.94; // Znunu HT
//Xsec[18] = 1.23*4.203;  // Znunu HT


float Sw = 1.0;//7.8034e-01 ;

Xsec[19] = Sw  *  1.459*1347;  // WJets HT 100-200
Xsec[20] = Sw  *  1.434*360;   // WJets HT 200-400
Xsec[21] = Sw  *  1.532*48.9;  // WJets HT 400-600
Xsec[22] = Sw  *  1.004*12.8;  // WJets HT 600-800
Xsec[23] = Sw  *  1.004*5.26;  // WJets HT 800-1200
Xsec[24] = Sw  *  1.004*1.33;  // WJets HT 1200-2500
Xsec[25] = Sw  *  1.004*0.03089;  // WJets HT 2500-Inf

//Xsec[19] = Sw  *  1.21*1347;  // WJets HT 100-200
//Xsec[20] = Sw  *  1.21*360;   // WJets HT 200-400
//Xsec[21] = Sw  *  1.21*48.9;  // WJets HT 400-600
//Xsec[22] = Sw  *  1.21*12.8;  // WJets HT 600-800
//Xsec[23] = Sw  *  1.21*5.26;  // WJets HT 800-1200
//Xsec[24] = Sw  *  1.21*1.33;  // WJets HT 1200-2500
//Xsec[25] = Sw  *  1.21*0.03089;  // WJets HT 2500-Inf

Xsec[26] = Stt  *  44.51; // single top
Xsec[27] = Stt  *  26.49; // single top
Xsec[28] = Stt  *  3.38; // single top
Xsec[29] = Stt  *  35.85; // single top
Xsec[30] = Stt  *  35.85; // single top

//Xsec[15] = 1.23*139.4; // DY HT
//Xsec[16] = 1.23*42.75; // DY HT
//Xsec[17] = 1.23*5.497; // DY HT
//Xsec[18] = 1.23*2.21;  // DY HT
//

TH1F* h_mc[nfiles] ;
float normalization[nfiles];
TH1F *h_data;

for(int i =0; i<(int)filenameString.size()-1; i++){
 fIn = new TFile(filenameString[i],"READ");
 h_mc[i] = (TH1F*) fIn->Get(histnameString);
 h_mc[i]->Rebin(REBIN); 
 h_mc[i]->Sumw2();

// h_total      = (TH1F*) fIn->Get("nEvents_weight");
 h_total      = (TH1F*) fIn->Get("h_total");
 
//std::cout<<" normalization for = "<<i<<"  "<<filenameString[i]<<"   "
//<<h_mc[i]->Integral()
//<<std::endl;

 if(h_total->Integral()>0) normalization[i]     = (lumi* Xsec[i])/(h_total->Integral());
else normalization[i]      = 0;
 //cout<<"normalization :" << normalization[i] << std::endl;

 Integral[i] = h_mc[i]->Integral();
 if(Integral[i]<0) Integral_Error[i] = 0.0;
if(Integral[i]>0) Integral_Error[i] = TMath::Sqrt(Integral[i]) * normalization[i];
 h_mc[i]->Scale(normalization[i]);  
// mout << filenameString[i] <<  "  &  " << Xsec[i] <<"  &  " << std::endl; 
//// cout << "Integral : " << h_total->Integral() << "  Entries :  " << h_total->GetEntries() << std::endl;                                         

 }

fIn = new TFile(filenameString[nfiles-1],"READ");
h_data = (TH1F*) fIn->Get(histnameString);
h_data->Rebin(REBIN);
//h_data->Sumw2();



 //Legend
 TLegend *legend;
 
 if(NORATIOPLOT){
 //legend = new TLegend(0.73, 0.62, 0.95,0.92,NULL,"brNDC");
legend = new TLegend(0.56, 0.65, 0.9,0.92,NULL,"brNDC");
 legend->SetTextSize(0.045);
 }else{

legend = new TLegend(0.62, 0.65, 0.94,0.92,NULL,"brNDC"); 
//legend = new TLegend(0.13, 0.85, 0.95,0.92,NULL,"brNDC");
// legend = new TLegend(0.7, 0.68, 0.95,0.92,NULL,"brNDC");
 legend->SetTextSize(0.05); }
 legend->SetBorderSize(0);
 legend->SetLineColor(1);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetFillColor(0);
 legend->SetFillStyle(0);
 legend->SetTextFont(42);
 legend->SetNColumns(2);
 legend->AddEntry(h_data,"Data","p");                                                                                                          
 legend->AddEntry(h_mc[9],"M1000", "l");
 legend->AddEntry(h_mc[11],"M1400", "l");
 legend->AddEntry(h_mc[13],"M2000", "l");
 legend->AddEntry(h_mc[15],"Z#nu#nu+Jets","f");
 legend->AddEntry(h_mc[2],"Diboson","f");                                                                                                      
 legend->AddEntry(h_mc[5],"t#bar{t}","f");
 legend->AddEntry(h_mc[26],"Single Top","f");
 legend->AddEntry(h_mc[19],"WJets","f");
 legend->AddEntry(h_mc[6],"ZH","f");
 //legend->AddEntry(h_mc[6],"QCD","f");
 

 
//===========================Latex=================//
TString latexCMSname= "CMS";
TString latexPreCMSname= "Preliminary";
 
TString latexnamemiddle;
latexnamemiddle.Form("%1.2f",lumi); 
TString latexnamepost = " pb^{-1} (13 TeV)";
//TString latexname = latexnamepre+latexnamemiddle+latexnamepost;  
TString latexname = latexnamemiddle+latexnamepost;

TLatex *t2b;
TLatex *t2c;

if(NORATIOPLOT){
 t2a = new TLatex(0.7,0.97,latexname);
 t2a->SetTextSize(0.04);

 t2b = new TLatex(0.190,0.92,latexCMSname);
 t2b->SetTextSize(0.05);

 t2c = new TLatex(0.22,0.87,latexPreCMSname);
 t2c->SetTextSize(0.047);

 }else{
 t2a = new TLatex(0.8,0.975,latexname);
 t2a->SetTextSize(0.047); 

 t2b = new TLatex(0.190,0.92,latexCMSname);
 t2b->SetTextSize(0.05);

 t2c = new TLatex(0.22,0.87,latexPreCMSname);
 t2c->SetTextSize(0.047);


 }

 t2a->SetTextAlign(22);
 t2a->SetNDC(kTRUE);
 t2a->SetTextFont(42);

 t2b->SetTextAlign(22);
 t2b->SetNDC(kTRUE);
 t2b->SetTextFont(61);


 t2c->SetTextAlign(22);
 t2c->SetNDC(kTRUE);
 t2c->SetTextFont(52);

 


//============== CANVAS DECLARATION ===================
TCanvas *c12 = new TCanvas("Hist", "Hist", 0,0,500,500);
 
//==================Stack==========================                                                                  
THStack *hs = new THStack("hs"," ");

// For N-1 Plots only
bool nminus = 0;
TLatex *tt;
if(("HISTPATH" == "ElectronNMinus1E") || ("HISTPATH" == "ElectronNMinus1B") ){
nminus =1;
tt  = new TLatex(0.5,0.87,"N-1");
tt->SetTextSize(0.05);
tt->SetTextAlign(22);
tt->SetNDC(kTRUE);
tt->SetTextFont(22);
}                                                                                
                                                                                       
//Colors for Histos
//h_mc[0]->SetFillColor(kOrange-1);
//h_mc[0]->SetLineColor(kOrange-1);

h_mc[15]->SetFillColor(kOrange-1);
h_mc[15]->SetLineColor(kOrange-1);

h_mc[16]->SetFillColor(kOrange-1);
h_mc[16]->SetLineColor(kOrange-1);

h_mc[17]->SetFillColor(kOrange-1);
h_mc[17]->SetLineColor(kOrange-1);

h_mc[18]->SetFillColor(kOrange-1);
h_mc[18]->SetLineColor(kOrange-1);



h_mc[6]->SetFillColor(kTeal-8);
h_mc[6]->SetLineColor(kTeal-8);

for(int diboson =2; diboson <5; diboson++){
h_mc[diboson]->SetFillColor(kRed-10);
h_mc[diboson]->SetLineColor(kRed-10);
}

h_mc[5]->SetFillColor(kBlue-5);
h_mc[5]->SetLineColor(kBlue-5);

//Old W+Jets
//h_mc[1]->SetFillColor(kOrange+4);                                                                                                            


// WJets HT Bins
h_mc[19]->SetFillColor(kOrange+4);                                                                                                            
h_mc[19]->SetLineColor(kOrange+4);


h_mc[20]->SetFillColor(kOrange+4);                                                                                                            
h_mc[20]->SetLineColor(kOrange+4);

h_mc[21]->SetFillColor(kOrange+4);                                                                                                            
h_mc[21]->SetLineColor(kOrange+4);

h_mc[22]->SetFillColor(kOrange+4);                                                                                                            
h_mc[22]->SetLineColor(kOrange+4);

h_mc[23]->SetFillColor(kOrange+4);                                                                                                            
h_mc[23]->SetLineColor(kOrange+4);

h_mc[24]->SetFillColor(kOrange+4);                                                                                                            
h_mc[24]->SetLineColor(kOrange+4);

h_mc[25]->SetFillColor(kOrange+4);                                                                                                            
h_mc[25]->SetLineColor(kOrange+4);

// Single Top 
h_mc[26]->SetFillColor(kBlue-7);                                                                                                            
h_mc[26]->SetLineColor(kBlue-7);

h_mc[27]->SetFillColor(kBlue-7);                                                                                                            
h_mc[27]->SetLineColor(kBlue-7);

h_mc[28]->SetFillColor(kBlue-7);                                                                                                            
h_mc[28]->SetLineColor(kBlue-7);

h_mc[29]->SetFillColor(kBlue-7);                                                                                                            
h_mc[29]->SetLineColor(kBlue-7);

h_mc[30]->SetFillColor(kBlue-7);                                                                                                            
h_mc[30]->SetLineColor(kBlue-7);



//h_mc[6]->SetFillColor(kGreen);
//h_mc[6]->SetLineColor(kGreen);

/*
for(int qcd = 6; qcd < 7 ; qcd++){ 
h_mc[qcd]->SetFillColor(kOrange+4);                                                                                                            
h_mc[qcd]->SetLineColor(kOrange+4);
}*/

h_mc[9]->SetLineColor(kBlue);
h_mc[9]->SetLineWidth(3);
h_mc[11]->SetLineColor(kGreen);
h_mc[11]->SetLineWidth(3);
h_mc[13]->SetLineColor(kRed);
h_mc[13]->SetLineWidth(3);



//hadd all the histos acc to their contributions

//for QCD Contribution
//hs->Add(h_mc[6]);

for(int diboson = 2; diboson < 5; diboson++){
 hs->Add(h_mc[diboson],"hist");
}                                                                                                          
//hs->Add(h_mc[0],"hist");                                                                        
hs->Add(h_mc[15],"hist");
hs->Add(h_mc[16],"hist");
hs->Add(h_mc[17],"hist");
hs->Add(h_mc[18],"hist");
hs->Add(h_mc[6],"hist"); 
//hs->Add(h_mc[1],"hist");
hs->Add(h_mc[19],"hist");
hs->Add(h_mc[20],"hist");
hs->Add(h_mc[21],"hist");
hs->Add(h_mc[22],"hist");
hs->Add(h_mc[23],"hist");
hs->Add(h_mc[24],"hist");
hs->Add(h_mc[25],"hist");
hs->Add(h_mc[26],"hist");
hs->Add(h_mc[27],"hist");
hs->Add(h_mc[28],"hist");
hs->Add(h_mc[29],"hist");
hs->Add(h_mc[30],"hist");

hs->Add(h_mc[5],"hist");

h_data->SetMarkerColor(kBlack);
h_data->SetMarkerStyle(20);
float maxi = h_data->GetMaximum();

TH1F *Stackhist = (TH1F*)hs->GetStack()->Last(); 
 TH1F* h_err;
 h_err = (TH1F*) h_data->Clone("h_err");
 h_err->Sumw2();
 h_err->Reset();
 for(int diboson = 2; diboson < 5; diboson++){
   h_err->Add(h_mc[diboson]);
 }
 //h_err->Add(h_mc[0],"hist");                                                                                                                                                       
 h_err->Add(h_mc[15]);
 h_err->Add(h_mc[16]);
 h_err->Add(h_mc[17]);
 h_err->Add(h_mc[18]);
 h_err->Add(h_mc[6]);
 //h_err->Add(h_mc[1],"hist");                                                                                                                                                       
 h_err->Add(h_mc[19]);
 h_err->Add(h_mc[20]);
 h_err->Add(h_mc[21]);
 h_err->Add(h_mc[22]);
 h_err->Add(h_mc[23]);
 h_err->Add(h_mc[24]);
 h_err->Add(h_mc[25]);
 h_err->Add(h_mc[26]);
 h_err->Add(h_mc[27]);
 h_err->Add(h_mc[28]);
 h_err->Add(h_mc[29]);
 h_err->Add(h_mc[30]);
 h_err->Add(h_mc[5]);
// for (int ibin=0; ibin<h_err->GetNbinsX();ibin++){
  // std::cout<<" stack err = "<<h_err->GetBinError(ibin)<<std::endl;
// }


//Setting canvas without log axis
c12->SetLogy(0);
  
  
  
  // Upper canvas declaration
 
  if(NORATIOPLOT){
  TPad *c1_2 = new TPad("c1_2","newpad",0,0.05,1,0.993);
  }else{
  TPad *c1_2 = new TPad("c1_2","newpad",0,0.29,1,0.974);
  c1_2->SetBottomMargin(0.03);
  }
 //c1_2->SetBottomMargin(-0.5);
  c1_2->SetLogy(ISLOG);
  c1_2->Draw();
  c1_2->cd();

hs->Draw();

  TH1F *Stackhist1 = (TH1F*)hs->GetStack()->Last(); 
//  Stackhist1->SetFillColor(kRed);
//  Stackhist1->DrawCopy("histsame");
//  Stackhist1->SetFillStyle(3018);
  //Stackhist1->SetLineColor(kRed);
  //Stackhist1->SetLineWidth(4);
  //Stackhist1->Draw(" same e2");  



  //hs->Draw("same");

  h_err->Draw("E2 SAME");
  //h_err->SetLineColor(kYellow);                                                                                                                                                    
  h_err->SetMarkerStyle(1);
  h_err->SetMarkerSize(0.000001);

  h_err->SetFillColor(2);
  h_err->SetFillStyle(3002);


    h_data->SetLineColor(1);
  h_data->Draw("same p e1");
  
  if(ISLOG)    hs->SetMinimum(0.1);
  if(!ISLOG)   hs->SetMinimum(1);
  if(!ISLOG)   hs->SetMaximum(maxi *1.45);
  if(ISLOG)    hs->SetMaximum(maxi *100);
  //if(!ISLOG) hs->SetMaximum(0.4);
 

  if(NORATIOPLOT){
  hs->GetXaxis()->SetTitleSize(0.05);
  hs->GetXaxis()->SetTitleOffset(0.97);
  hs->GetXaxis()->SetTitleFont(22);
  hs->GetXaxis()->SetLabelFont(22);
  hs->GetXaxis()->SetLabelSize(.05);
  hs->GetYaxis()->SetTitle("Events");
  hs->GetYaxis()->SetTitleSize(0.05);
  hs->GetYaxis()->SetTitleOffset(1.);
  hs->GetYaxis()->SetTitleFont(22);
  hs->GetYaxis()->SetLabelFont(22);
  hs->GetYaxis()->SetLabelSize(.05);
  hs->GetXaxis()->SetTitle("XAXISLABEL");
  }else{
  hs->GetXaxis()->SetLabelOffset(999);
  hs->GetXaxis()->SetLabelSize(0);  

  }  


  hs->GetYaxis()->SetTitle("Events");                                   
  hs->GetYaxis()->SetTitleSize(0.07); 
  hs->GetYaxis()->SetTitleOffset(0.9);
  hs->GetYaxis()->SetTitleFont(22);
  hs->GetYaxis()->SetLabelFont(22);
  hs->GetYaxis()->SetLabelSize(.07);
  hs->GetXaxis()->SetRangeUser(XMIN,XMAX);  
  hs->GetXaxis()->SetNdivisions(508); 

  legend->AddEntry(h_err,"Stats. Unc.","f");


  legend->Draw("same"); 
  t2a->Draw("same");
  t2b->Draw("same");
  t2c->Draw("same");
  
  
  if(nminus = =1){tt->Draw("same");}
  
// Commenting out the signal for control region
  h_mc[9]->Draw("same");
  h_mc[11]->Draw("same");
  h_mc[13]->Draw("same");


  
 // Lower Tpad Decalaration
 
  if(! NORATIOPLOT){
  c12->cd();
  
  TH1F *DataMC = (TH1F*) h_data->Clone();
/* DataMC->Divide(DataMC);

  double NMC=0;
  double NData=0;
  double RatioNMCNData =1.;
  int nbins = h_data->GetNbinsX();
  for( int j=0; j < nbins-1; j++){
   NData = h_data->GetBinContent(j+1);
   NMC   = Stackhist->GetBinContent(j+1); 
   if(NData > 0){
   RatioNMCNData = NData/NMC;
  // RatioNMCNData = (NData-NMC)/(sqrt(NData));
   }
   DataMC->SetBinContent(j+1, RatioNMCNData);
   }   

  DataMC->SetNameTitle("DataMC", "DataMC");*/
  
  DataMC->Divide(Stackhist);
  DataMC->GetYaxis()->SetTitle("Data/MC");
  DataMC->GetYaxis()->SetTitleSize(0.155);
  DataMC->GetYaxis()->SetTitleOffset(0.3);
  DataMC->GetYaxis()->SetTitleFont(22);
  DataMC->GetYaxis()->SetLabelSize(0.15);
  DataMC->GetYaxis()->CenterTitle();
  DataMC->GetXaxis()->SetTitle("XAXISLABEL");
//DataMC->GetXaxis()->SetIndiceSize(0.1);
  DataMC->GetXaxis()->SetLabelSize(0.157);
  DataMC->GetXaxis()->SetTitleSize(0.162);
  DataMC->GetXaxis()->SetTitleOffset(1.02);
  DataMC->GetXaxis()->SetTitleFont(22);
  DataMC->GetXaxis()->SetTickLength(0.07);
  DataMC->GetXaxis()->SetLabelFont(22);
  DataMC->GetYaxis()->SetLabelFont(22);     
  
 TPad *c1_1 = new TPad("c1_1", "newpad",0,0.00,1,0.29);
 c1_1->Draw();
 c1_1->cd();
 c1_1->Range(-7.862408,-629.6193,53.07125,486.5489);
 c1_1->SetFillColor(0);
 c1_1->SetTicky(1);
 c1_1->SetLeftMargin(0.1290323);
 c1_1->SetRightMargin(0.05040323);
 c1_1->SetTopMargin(0.00);//0.0
 c1_1->SetBottomMargin(0.366666678814);
 c1_1->SetFrameFillStyle(0);
 c1_1->SetFrameBorderMode(0);
 c1_1->SetFrameFillStyle(0);
 c1_1->SetFrameBorderMode(0);
 c1_1->SetLogy(0);
 DataMC->GetXaxis()->SetRangeUser(XMIN,XMAX);
 DataMC->Draw("PE1");
 DataMC->SetMarkerStyle(20);
 DataMC->SetMarkerColor(1);
 DataMC->SetMinimum(0.);
 DataMC->SetMaximum(2.2);
 DataMC->GetXaxis()->SetNdivisions(508);
 DataMC->GetYaxis()->SetNdivisions(503);
 c1_1->SetGridy();


 TF1 *line0 = new TF1("line0","[0]*x",XMIN,XMAX);
 line0->FixParameter(0,0);
// line0->FixParameter(1,0);
 
 //DataMC->Fit("line0");
 //line0->SetLineColor(kRed);
 //line0->Draw("same");
 //
 //Double_t chi2 = line0->GetChisquare();
 //cout <<"chi2:" << chi2 <<std::endl;

 }
  


if(TEXTINFILE){ 
   
//=======================================================================
  //Calculating the contribution of each background in particular range
 // As Data DY(ee) diboson TTjets WWJets
 TAxis *xaxis = h_mc[0]->GetXaxis();
 Int_t binxmin = xaxis->FindBin(XMIN);
 Int_t binxmax = xaxis->FindBin(XMAX);

  float qcdEntries =0.0, dibosonentries =0.0 , wjetentries=0.0;
//  for(int qcd = 6; qcd < 22 ; qcd++){                                                                                   
//    qcdEntries+ = h_mc[qcd]->GetBinContent(5);}

  for(int diboson = 2; diboson < 5; diboson++){  
    dibosonentries+ = h_mc[diboson]->GetBinContent(5);
    }    

wjetentries= h_mc[19]->Integral() +h_mc[20]->Integral()+h_mc[21]->Integral()+h_mc[22]->Integral()+h_mc[23]->Integral()+h_mc[24]->Integral()+h_mc[25]->Integral();            
      
float dyjets = h_mc[15]->Integral()+h_mc[16]->Integral()+h_mc[17]->Integral()+h_mc[18]->Integral(); 
float dyjets_error = Integral_Error[15] + Integral_Error[16] + Integral_Error[17] + Integral_Error[18] ;

float diboson_ = h_mc[2]->Integral() + h_mc[3]->Integral() + h_mc[4]->Integral();
float diboson_error = Integral_Error[2] + Integral_Error[3] + Integral_Error[4];

float tt_ = h_mc[5]->Integral() + h_mc[26]->Integral()+h_mc[27]->Integral()+h_mc[28]->Integral()+h_mc[29]->Integral()+ h_mc[30]->Integral() ;
float tt_error = Integral_Error[5] + Integral_Error[26] + Integral_Error[27] +Integral_Error[28] +Integral_Error[29] +Integral_Error[30] ;

//float st = h_mc[26]->Integral()+h_mc[27]->Integral()+h_mc[28]->Integral()+h_mc[29]->Integral()+ h_mc[30]->Integral() ;
//float st_error = Integral_Error[26] + Integral_Error[27] +Integral_Error[28] +Integral_Error[29] +Integral_Error[30] ;

float wjets = h_mc[19]->Integral() +h_mc[20]->Integral()+h_mc[21]->Integral()+h_mc[22]->Integral()+h_mc[23]->Integral()+h_mc[24]->Integral()+h_mc[25]->Integral() ;
float wjets_error = Integral_Error[19] + Integral_Error[20] +Integral_Error[21] +Integral_Error[22] +Integral_Error[23] +Integral_Error[24] +Integral_Error[25] ;

float zh = h_mc[6]->Integral();
float zh_error = Integral_Error[6];


  mout << "HISTPATH_HISTNAME"            <<  " a b"<<std::endl; 
  mout << " DATA "    << h_data->Integral()  <<" 0"<< std::endl; 
//  mout << " DATA 0"    <<  std::endl; 
//  mout << " DYJETS "  << h_mc[0]->Integral() << std::endl; 
  mout << " DIBOSON " << diboson_                  <<" "<<diboson_error << std::endl;
  mout << " TT "      << h_mc[5]->Integral() + h_mc[26]->Integral()+h_mc[27]->Integral()+h_mc[28]->Integral()+h_mc[29]->Integral()+ h_mc[30]->Integral() <<" "<<tt_error <<  std::endl; 
  mout << " WJETS "   << h_mc[19]->Integral() +h_mc[20]->Integral()+h_mc[21]->Integral()+h_mc[22]->Integral()+h_mc[23]->Integral()+h_mc[24]->Integral()+h_mc[25]->Integral()<< " "<<wjets_error<<std::endl;
  mout << " ZH "      << h_mc[6]->Integral() <<" "<<zh_error<< std::endl;
  mout << " DYJETS "<<h_mc[15]->Integral()+h_mc[16]->Integral()+h_mc[17]->Integral()+h_mc[18]->Integral() <<" "<<dyjets_error <<std::endl;  
//  mout << " Single Top "<<h_mc[26]->Integral()+h_mc[27]->Integral()+h_mc[28]->Integral()+h_mc[29]->Integral()+ h_mc[30]->Integral() << std::endl;  
  mout << " M600 "    << h_mc[7]->Integral() <<" "<<Integral_Error[7]<< std::endl;
  mout << " M800 "    << h_mc[8]->Integral() <<" "<<Integral_Error[8]<< std::endl;
  mout << " M1000 "    << h_mc[9]->Integral() <<" "<<Integral_Error[9]<< std::endl;
  mout << " M1200 "    << h_mc[10]->Integral() <<" "<<Integral_Error[10]<< std::endl;
  mout << " M1400 "   << h_mc[11]->Integral() <<" "<<Integral_Error[11]<< std::endl;
  mout << " M1700 "   << h_mc[12]->Integral() <<" "<<Integral_Error[12]<< std::endl;
  mout << " M2000 "   << h_mc[13]->Integral() <<" "<<Integral_Error[13]<< std::endl;
  mout << " M2500 "   << h_mc[14]->Integral() <<" "<<Integral_Error[14]<< std::endl;
//  mout << "Total Bkg " << dibosonentries+h_mc[5]->Integral()+wjetentries+h_mc[6]->Integral()+h_mc[15]->Integral()+h_mc[16]->Integral()+h_mc[17]->Integral()+h_mc[18]->Integral()+h_mc[26]->Integral()+h_mc[27]->Integral()+h_mc[28]->Integral()+h_mc[29]->Integral()+ h_mc[30]->Integral() <<std::endl;
  mout << "========= ======================== =====================" <<std::endl;
//=========================================================================




// --------------------- table output --------------------
  tableout.precision(3);
  tableout << " Z \\\\rightarrow \\\\nu \\\\nu+Jets & "<< dyjets <<" \\\\pm "<<dyjets_error <<"\\\\\\\\"<<std::endl;  
  tableout << " t \\\\bar{t} & "<< tt_ <<" \\\\pm "<<tt_error <<"\\\\\\\\"<< std::endl; 
  tableout << " W+Jets & "  <<wjets <<" \\\\pm "<<wjets_error <<"\\\\\\\\"<< std::endl;
  tableout << " WW/WZ/ZZ & " << diboson_ <<" \\\\pm "<<diboson_error  <<"\\\\\\\\"<< std::endl;
  tableout << " ZH & "      << h_mc[6]->Integral() <<" \\\\pm "<<Integral_Error[6]<<"\\\\\\\\"<< std::endl;
  tableout << " M600  & "    << h_mc[7]->Integral() <<" \\\\pm "<<Integral_Error[7]<<"\\\\\\\\"<< std::endl;
  tableout << " M800  & "    << h_mc[8]->Integral() <<" \\\\pm "<<Integral_Error[8]<<"\\\\\\\\"<< std::endl;
  tableout << " M1000 &  "    << h_mc[9]->Integral() <<" \\\\pm "<<Integral_Error[9]<<"\\\\\\\\"<< std::endl;
  tableout << " M1200 &  "    << h_mc[10]->Integral() <<" \\\\pm "<<Integral_Error[10]<<"\\\\\\\\"<< std::endl;
  tableout << " M1400 &  "   << h_mc[11]->Integral() <<" \\\\pm "<<Integral_Error[11]<<"\\\\\\\\"<< std::endl;
  tableout << " M1700 &  "   << h_mc[12]->Integral() <<" \\\\pm "<<Integral_Error[12]<<"\\\\\\\\"<< std::endl;
  tableout << " M2000 &  "   << h_mc[13]->Integral() <<" \\\\pm "<<Integral_Error[13]<<"\\\\\\\\"<< std::endl;
  tableout << " M2500 &  "   << h_mc[14]->Integral() <<" \\\\pm "<<Integral_Error[14]<<"\\\\\\\\"<< std::endl;
  tableout << " DATA  & "    << h_data->Integral()  << std::endl; 


float a = h_mc[19]->Integral() +h_mc[20]->Integral()+h_mc[21]->Integral()+h_mc[22]->Integral()+h_mc[23]->Integral()+h_mc[24]->Integral()+h_mc[25]->Integral();
float b = h_mc[5]->Integral() + h_mc[26]->Integral()+h_mc[27]->Integral()+h_mc[28]->Integral()+h_mc[29]->Integral()+ h_mc[30]->Integral();
float c = h_data->Integral() - (dibosonentries + h_mc[6]->Integral() + h_mc[15]->Integral()+h_mc[16]->Integral()+h_mc[17]->Integral()+h_mc[18]->Integral());

tableout << "a "<<a<<" "<<" b "<<b<<" "<<" c "<<c<<std::endl;
tableout<<" total_bkg "<<a + b + dibosonentries + h_mc[6]->Integral() + h_mc[15]->Integral()+h_mc[16]->Integral()+h_mc[17]->Integral()+h_mc[18]->Integral()<<std::endl;
tableout<< " "<<std::endl;
}
 
 c12->Draw();
if(!ISLOG){
 c12->SaveAs(DirPreName+dirpathname +"/MonoHPdf/HISTPATH_HISTNAME.pdf");
 c12->SaveAs(DirPreName+dirpathname +"/MonoHPng/HISTPATH_HISTNAME.png");
 c12->SaveAs(DirPreName+dirpathname +"/MonoHROOT/HISTPATH_HISTNAME.root");                                                                         
 rout<<"<hr/>"<<std::endl;
 rout<<"<table class=\\"\\"> <tr><td><img src=\\""<<"DYPng/HISTPATH_HISTNAME.png\\" height=\\"400\\" width=\\"400\\"></td>   </tr> </table>"<<std::endl;

}
 
if(ISLOG){
 c12->SaveAs(DirPreName+dirpathname +"/MonoHPdf/HISTPATH_HISTNAME_log.pdf");
 c12->SaveAs(DirPreName+dirpathname +"/MonoHPng/HISTPATH_HISTNAME_log.png");
 c12->SaveAs(DirPreName+dirpathname +"/MonoHROOT/HISTPATH_HISTNAME_log.root");                                                                        
}
 }
'''
## template macro ends here

TemplateOverlapMacro = open('TemplateOverlapMacro.C','w')
TemplateOverlapMacro.write(macro)
TemplateOverlapMacro.close()

def makeplot(inputs):
    print inputs
    TemplateOverlapMacro = open('TemplateOverlapMacro.C','r')
    NewPlot       = open('Plot.C','w')
    for line in TemplateOverlapMacro:
        line = line.replace("HISTPATH",inputs[0])
        line = line.replace("HISTNAME",inputs[1])
        line = line.replace("XAXISLABEL",inputs[2])
        line = line.replace("XMIN",inputs[3])
        line = line.replace("XMAX",inputs[4])
        line = line.replace("REBIN",inputs[5]) 
        line = line.replace("ISLOG",inputs[6])
        if len(inputs) > 7 : 
            line = line.replace("TEXTINFILE", inputs[7])
        else : 
            line = line.replace("TEXTINFILE", "0")     
        if len(inputs) > 8 :
            line = line.replace(".pdf",str(inputs[8]+".pdf"))
            line = line.replace(".png",str(inputs[8]+".png"))
        if len(inputs) > 9 :
            line = line.replace("NORATIOPLOT", inputs[9])
        else :
            line = line.replace("NORATIOPLOT", "0")
        #print line
        NewPlot.write(line)
    NewPlot.close()
    os.system('root -l -b -q  Plot.C')

##########Start Adding your plots here


#dirnames=['histfacFatJet_WHeavy','MonoHFatJetSelection_JetAndLeptonVeto','histfacFatJet_ZLight']
#'histfacFatJet_WLight','histfacFatJet_TTBar','histfacFatJet_ZLight','histfacFatJet_TTBar_Merged','histfacFatJet_WHeavy','MonoHFatJetSelection_JetAndLeptonVeto']
#dirnames=['histfacFatJet_QCD']
#dirnames=['histfacFatJet_ZLight']
dirnames=['MonoHFatJetSelection_JetAndLeptonVeto']
#dirnames=['MonoHFatJetsPreselection_2subj']
#dirnames=['MonoHFatJetSelection_Jetveto','MonoHFatJetSelection_LeptonVeto','MonoHFatJetSelection_JetAndLeptonVeto']
#dirnames=['histfacFatJet_WLight','histfacFatJet_TTBar','histfacFatJet_ZLight']
#dirnames=['histfacFatJet_ZLight']
#dirnames=['histfacFatJet_ZLight']

#dirnames=['MonoHFatJetSelection_JetAndLeptonVeto']
#dirnames=['MonoHFatJetsPreselection_1subj','MonoHFatJetsPreselection_2subj','histfacFatJet_TTBar','histfacFatJet_ZLight','histfacFatJet_ZHeavy','histfacFatJet_WLight','histfacFatJet_WHeavy']
#dirnames=['MonoHFatJetsPreselection_2subj','MonoHFatJetSelection_Jetveto','MonoHFatJetSelection_LeptonVeto','MonoHFatJetSelection_JetAndLeptonVeto']
## Plots After Pre-selection
#makeplot(['CutFlowAndEachCutFatJet', 'h_cutflow_0_f', 'Cut Flow', '0','5', '1', '1','1'])
for dirname in dirnames:
    makeLinearplots=True;
    if makeLinearplots :
        #makeplot([dirname,'h_dPhi_MT_0','N_{AK04 Jets}','0','10','1','0','1'])
        makeplot([dirname,'h_nMuons0','N_{add. #mu}','0','5','1','0','1','','1'])
        #makeplot([dirname,'h_MET0','MET','200','700','2','0'])
        #makeplot([dirname,'h_NThinJets0','N_{AK04 Jets}','0','10','1','0','1'])
        #makeplot([dirname,'h_pTjj0','p_{T}^{AK8Jet}','100','1000','4','0'])
        #makeplot([dirname,'h_CSV10', 'CSV_{1}', '0','1', '1','0'])
        #makeplot([dirname,'h_CSV20', 'CSV_{2}', '0','1', '1','0'])
        #makeplot([dirname,'h_Mjj0','M_{SD}','20','250','1','0']) 
        #makeplot([dirname,'h_nElectrons0','N_{add. e}','0','5','1','0'])
        #makeplot([dirname,'h_nJetss0','N_{add. Jets}','0','5','1','0']) 
        #makeplot([dirname,'h_dPhiThinJetMET0','Min #Delta#phi_{J-MET}','0.','3.5','2','0'])
        #makeplot([dirname,'h_MHT0','MHT','0.','600','2','0'])
        #makeplot([dirname,'h_CSVSum0','CSV','0','1','1','0'])
        #makeplot([dirname,'h_phijj0','#phi_{AK8Jet}','-3.5','3.5','4','0'])
        #makeplot([dirname,'h_etajj0','#eta_{AK8Jet}','-2.5','2.5','4','0'])
        #makeplot([dirname,'h_nTaus0','N_{#tau}','0','5','1','0'])
        #makeplot([dirname,'h_dPhi_bb_MET0','#Delta#phi_{AK8Jet-MET}','0.','3.5','2','0'])
        #makeplot([dirname,'h_MT_bb_MET0', 'M_{T}', '0','1500', '4','0'])
        #makeplot([dirname,'h_MET_Over_SumET0', 'MET/SumET', '0','5', '1','0'])
        #makeplot([dirname,'h_MET_Over_pTFatJet0', 'MET/p_{T}^{AK8-Jet}', '0','2.', '1','0'])
        #makeplot([dirname,'h_DRSJ0', '#DeltaR_{sub-jets}', '0','1', '1','0'])
        #makeplot([dirname,'h_CSVMax0', 'CSV_{Max}', '0','1', '1','0'])
        #makeplot([dirname,'h_CSVMin0', 'CSV_{Min}', '0','1', '1','0'])
        #makeplot([dirname,'h_h_Tau21jj0','#tau_{21}','0','1','1','0'])
        #makeplot([dirname,'h_CEmEF0', 'CEmEF', '0','1.', '1','0'])
        #makeplot([dirname,'h_CHadEF0', 'CHadEF', '0','1.', '1','0'])
        #makeplot([dirname,'h_PhoEF0', 'PhoEF', '0','1.', '1','0'])
        #makeplot([dirname,'h_NHadEF0', 'NHadEF', '0','1.', '1','0'])
        #makeplot([dirname,'h_MuEF0', 'MuEF', '0','1.', '1','0'])
    
    makelogplots=False
    
    if makelogplots : 
        makeplot([dirname,'h_MET0','MET','200','500','2','1'])
        makeplot([dirname,'h_NThinJets0','N_{AK04 Jets}','0','10','1','1'])
        makeplot([dirname,'h_pTjj0','p_{T}^{AK8Jet}','100','1000','4','1'])
        makeplot([dirname,'h_CSV10', 'CSV_{1}', '0','1', '1','1'])
        makeplot([dirname,'h_CSV20', 'CSV_{1}', '0','1', '1','1'])
        makeplot([dirname,'h_Mjj0','M_{SD}','20','200','1','1']) 
        makeplot([dirname,'h_nMuons0','N_{add. #mu}','0','5','1','1','1'])
        makeplot([dirname,'h_dPhiThinJetMET0','#Delta#phi_{J-MET}','0.','3.5','2','1'])
        makeplot([dirname,'h_nElectrons0','N_{add. e}','0','5','1','1'])
        makeplot([dirname,'h_nJetss0','N_{add. Jets}','0','5','1','1']) 
        #makeplot([dirname,'h_MET0','MET','200','1000','4','1','1'])
        #makeplot([dirname,'h_pTjj0','p_{T}^{AK8Jet}','100','1600','4','1'])
        makeplot([dirname,'h_h_Tau21jj0','#tau_{21}','0','1','1','1'])
        makeplot([dirname,'h_CSVSum0','CSV','0','1','1','1'])
        makeplot([dirname,'h_phijj0','#phi_{AK8Jet}','-3.5','3.5','5','1'])
        makeplot([dirname,'h_etajj0','#eta_{AK8Jet}','-2.5','2.5','5','1'])
        makeplot([dirname,'h_nTaus0','N_{#tau}','0','5','1','1'])
        makeplot([dirname,'h_dPhi_bb_MET0','#Delta#phi_{AK8Jet-MET}','0.','3.5','2','1'])
        makeplot([dirname,'h_MT_bb_MET0', 'M_{T}', '500','1500', '4','1'])
        makeplot([dirname,'h_DRSJ0', '#DeltaR_{sub-jets}', '0','1', '1','1'])
        makeplot([dirname,'h_CSVMax0', 'CSV_{Max}', '0','1', '1','1'])
        makeplot([dirname,'h_CSVMin0', 'CSV_{Min}', '0','1', '1','1'])
        makeplot([dirname,'h_MET_Over_SumET0', 'MET/SumET', '0','5', '2','1'])
        makeplot([dirname,'h_MET_Over_pTFatJet0', 'MET/p_{T}^{AK8-Jet}', '0','1.', '1','1'])
        makeplot([dirname,'h_CEmEF0', 'CEmEF', '0','1.', '1','1'])
        makeplot([dirname,'h_CHadEF0', 'CHadEF', '0','1.', '1','1'])
        makeplot([dirname,'h_PhoEF0', 'PhoEF', '0','1.', '1','1'])
        makeplot([dirname,'h_NHadEF0', 'NHadEF', '0','1.', '1','1'])
        makeplot([dirname,'h_MuEF0', 'MuEF', '0','1.', '1','1'])


