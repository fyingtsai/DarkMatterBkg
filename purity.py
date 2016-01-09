import ROOT
from ROOT import TGraph, TFile, TCanvas
from ROOT import gROOT
from array import array

def main():
    c1 = TCanvas( 'c1', 'A Simple Graph', 200, 10, 700, 500 )
    c1.SetGrid()
    f1 = TFile("GJ_out.root")
    f2 = TFile("QCD_out.root")
    h_GJ = f1.Get("h_PtPho3")
    h_QCD = f2.Get("h_PtPho3")

    GJ_number = []
    QCD_number = []
    ptValue = []
    purity = []
    for i in range(h_GJ.GetNbinsX()):
        GJ_number.append(h_GJ.GetBinContent(i+1))
        QCD_number.append(h_QCD.GetBinContent(i+1))
        ptValue.append((500/h_GJ.GetNbinsX())*i)

    for j in range(len(GJ_number)):
        if (GJ_number[j]+QCD_number[j]) == 0:
            purity.append(0)
        else:
            purity.append(GJ_number[j]/(GJ_number[j]+QCD_number[j]))

    x = array("d", ptValue)
    y = array("d", purity)

    fout = TFile("purity.root","recreate")
    g = TGraph(len(x),x,y)
    g.GetXaxis().SetTitle("Photon Pt (GeV)")
    g.GetYaxis().SetTitle("Purity")
    g.SetTitle("Photon Purity")
    g.SetMarkerColor(4)
    g.SetMarkerStyle(21)
    g.Write('AP')
    fout.Write()
    fout.Close()
    c1.Update()

if __name__ == "__main__":
   main()