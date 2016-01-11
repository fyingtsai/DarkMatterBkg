import ROOT
from ROOT import TGraph, TFile, TCanvas
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
    ptValue = []
    purity = []

    for i in range(h_GJ.GetNbinsX()):
        number_GJ.append(h_GJ.GetBinContent(i+1))
        number_QCD.append(h_QCD.GetBinContent(i+1))
        ptValue.append((500/h_GJ.GetNbinsX())*i)

    for j in range(len(number_GJ)):
        if (number_GJ[j]+number_QCD[j]) == 0:
            purity.append(0)
        else:
            purity.append(number_GJ[j]/(number_GJ[j]+number_QCD[j]))

    x = array("d", ptValue)
    y = array("d", purity)

    # fout = TFile("purity.root","recreate")
    g = TGraph(len(x),x,y)
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