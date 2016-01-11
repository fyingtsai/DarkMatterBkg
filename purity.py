import ROOT
import math
from ROOT import TGraph, TFile, TCanvas, TGraphErrors
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

    number_GJ = []
    number_QCD = []
    error_GJ = []
    error_QCD = []
    ptValue = []
    purity = []
    error = []
    error_x = []

    for i in range(h_GJ.GetNbinsX()):
        number_GJ.append(h_GJ.GetBinContent(i+1))
        number_QCD.append(h_QCD.GetBinContent(i+1))
        error_GJ.append(h_GJ.GetBinError(i+1))
        error_QCD.append(h_QCD.GetBinError(i+1))
        ptValue.append((500/h_GJ.GetNbinsX())*i)

    for j in range(len(number_GJ)):
        if (number_GJ[j]+number_QCD[j]) == 0:
            purity.append(0)
        else:
            purity.append(number_GJ[j]/(number_GJ[j]+number_QCD[j]))

    for k in range(len(purity)):
        if (number_GJ[k] and number_QCD[k]) == 0:
            error.append(0)
            error_x.append(0)
        else:
            error.append(purity[k]*math.sqrt(pow(error_GJ[k]/number_GJ[k],2)+pow(error_QCD[k]/number_QCD[k],2)))
            error_x.append(0)

    x = array("d", ptValue)
    y = array("d", purity)
    ey = array("d",error)
    ex = array("d",error_x)


    # fout = TFile("purity.root","recreate")
    g = TGraphErrors(len(x),x,y,ex,ey)
    g.GetXaxis().SetTitle("Photon Pt (GeV)")
    g.GetYaxis().SetTitle("Purity (S/S+B)")
    g.SetTitle("Photon Purity")
    # g.SetMarkerColor(4)
    g.SetMarkerStyle(20)
    g.Draw('AP')
    # fout.Write()
    # fout.Close()
    c1.Modified()
    c1.Update()
    c1.cd()
    c1.Print("graph1.png") 

if __name__ == "__main__":
   main()