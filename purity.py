import ROOT
import math
from ROOT import TGraph, TFile, TCanvas, TGraphAsymmErrors
from array import array

def main():
    c1 = TCanvas("comp","",1100,1100)
    pad = c1.cd()  
    pad.SetGridx(1)
    pad.SetGridy(1)

    f1 = TFile("GJ_out.root")
    f2 = TFile("QCD_out.root")
    h_GJ = f1.Get("h_PtPho4")
    h_QCD = f2.Get("h_PtPho4")
    h_QCD.Add(h_GJ)

    g = TGraphAsymmErrors(h_GJ,h_QCD,"d")
    g.GetXaxis().SetTitle("Photon Pt (GeV)")
    g.GetYaxis().SetTitle("Purity (S/S+B)")
    g.SetTitle("Photon Purity")
    g.SetMarkerStyle(20)
    g.Draw('AP')
    c1.Modified()
    c1.Update()
    c1.cd()
    c1.Print("TGraphAsymmErrors.pdf") 

if __name__ == "__main__":
   main()