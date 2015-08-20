#define VetoStudy_cxx
#include "VetoStudy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TLorentzVector.h"
#include <iostream>

void VetoStudy::Loop()
{
    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();
    TFile* myFile = new TFile("HT-600toInf.root", "RECREATE");
    TH1F* h_LooseCh = new TH1F("h_LooseCh","",100,0,15);
    TH1F* h_LooseNe = new TH1F("h_LooseNe","",100,0,15);
    TH1F* h_LooseGa = new TH1F("h_LooseGa","",100,0,15);
    TH1F* h_MedCh = new TH1F("h_MedCh","",100,0,15);
    TH1F* h_MedNe = new TH1F("h_MedNe","",100,0,15);
    TH1F* h_MedGa = new TH1F("h_MedGa","",100,0,15);
    TH1F* h_VetoCh = new TH1F("h_VetoCh","",100,0,15);
    TH1F* h_VetoNe = new TH1F("h_VetoNe","",100,0,15);
    TH1F* h_VetoGa = new TH1F("h_VetoGa","",100,0,15);
    TH1F* h_nEle = new TH1F("h_nEle","h_nEle",5,0,5);
    TH1F* h_PtLJ = new TH1F("h_PtLJet","h_PtLJet",100,0,1000);
    TH1F* h_PtSJ = new TH1F("h_PtSJet","h_PtSJet",100,0,1000);
    TH1F* h_PtEle = new TH1F("h_PtEle","Pt of Ele",50,0,500);
    TH1F* h_LPtEle = new TH1F("h_PtEle2","Pt of Ele with loose cut",50,0,500);
    TH1F* h_MPtEle = new TH1F("h_PtEle3","Pt of Ele with medium cut",50,0,500);
    TH1F* h_dREleLJ = new TH1F("h_dREleLJet","dR with leading bjet",50,0,5);
    TH1F* h_dREleSJ = new TH1F("h_dREleSJet","dR with sub-leading bjet",50,0,5);
    TH1F* h_dRCEleJet = new TH1F("h_dRClosetEleJet","dR with closest bjet",50,0,5);
    TH2F* h_eleL = new TH2F("h_eleL","pt ele vs pt leading bjet",100,0,500,100,0,500);
    TH2F* h_eleS = new TH2F("h_eleS","pt ele vs pt sub-leading bjet",100,0,500,100,0,300);
    TH2F* h_eleC = new TH2F("h_eleC","pt ele vs pt Closest Jet",100,0,500,100,0,500);
    TH2F* h_dR1 = new TH2F("h_dR1","dR(ele,leadingJet) vs dR(leadingJet,sub-leadingJet)",50,0,5,50,0,5);
    TH2F* h_dR2 = new TH2F("h_dR2","dR(ele,sub-leadingJet) vs dR(leadingJet,sub-leadingJet)",50,0,5,50,0,5);
    TH2F* h_dR3 = new TH2F("h_dR3","dR(ele,leadingJet) vs dR(ele,sub-leadingJet)",50,0,5,50,0,5);
    
    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        // if (Cut(ientry) < 0) continue;
        TLorentzVector *maxPt, *secondPt;
        float NmaxPt = -9999.0, NsecondPt = -9999.0;
        int maxJetIndex = -1;
        for(Int_t i=0;i<THINnJet;i++){
            TLorentzVector* thisJetP4 = (TLorentzVector*)THINjetP4->At(i);
            if((*THINjetCISVV2)[i] < 0.605)continue;
            if(thisJetP4->Pt() > NmaxPt){
                NmaxPt = thisJetP4->Pt();
                maxPt = thisJetP4;
                maxJetIndex = i;
            }//leading Jet
            if(thisJetP4->Pt() > NsecondPt){
                if(i == maxJetIndex) continue;
                NsecondPt = thisJetP4->Pt();
                secondPt = thisJetP4;
            }//second Jet
        }
        /****** To Select b jet candidates ********/
        if(NmaxPt < 80 || NsecondPt < 30) continue;
        if((*maxPt+*secondPt).M()>150 || (*maxPt+*secondPt).M()<90)continue;
        /******* MET Cut for Signal like Events *******/ 
        if(pfMetRawPt < 200) continue;

        h_PtLJ->Fill(maxPt->Pt());
        h_PtSJ->Fill(secondPt->Pt());

        for(Int_t i=0; i<nEle; i++){
            Double_t closePt = 0.0, closedR=0.0;
            TLorentzVector* thisEleP4 = (TLorentzVector*)eleP4->At(i);
            if(thisEleP4->Pt()<10 || fabs(thisEleP4->Eta())>2.5)continue;
                if(eleIsPassVeto){
                    h_nEle->Fill(nEle);
                    h_VetoCh->Fill((*eleChHadIso)[i]/thisEleP4->Pt());
                    h_VetoNe->Fill((*eleNeHadIso)[i]/thisEleP4->Pt());
                    h_VetoGa->Fill((*eleGamIso)[i]/thisEleP4->Pt());
                    h_PtEle->Fill(thisEleP4->Pt());
                    h_eleL->Fill(thisEleP4->Pt(),maxPt->Pt());
                    h_eleS->Fill(thisEleP4->Pt(),secondPt->Pt());
                    h_dREleLJ->Fill(maxPt->DeltaR(*thisEleP4));
                    h_dREleSJ->Fill(secondPt->DeltaR(*thisEleP4));
                    h_dR1->Fill(maxPt->DeltaR(*thisEleP4),maxPt->DeltaR(*secondPt));
                    h_dR2->Fill(secondPt->DeltaR(*thisEleP4),maxPt->DeltaR(*secondPt));
                    h_dR3->Fill(maxPt->DeltaR(*thisEleP4),secondPt->DeltaR(*thisEleP4));

                    if(maxPt->DeltaR(*thisEleP4)<secondPt->DeltaR(*thisEleP4)){
                        closePt = maxPt->Pt();
                        closedR = maxPt->DeltaR(*thisEleP4);
                    }else{
                        closePt = secondPt->Pt();
                        closedR = secondPt->DeltaR(*thisEleP4);
                    }
                    h_dRCEleJet->Fill(closedR);
                    h_eleC->Fill(thisEleP4->Pt(),closePt);
                }
                if(eleIsPassLoose){
                    h_LPtEle->Fill(thisEleP4->Pt());
                    h_LooseCh->Fill((*eleChHadIso)[i]/thisEleP4->Pt());
                    h_LooseNe->Fill((*eleNeHadIso)[i]/thisEleP4->Pt());
                    h_LooseGa->Fill((*eleGamIso)[i]/thisEleP4->Pt());
                }
                if(eleIsPassMedium){
                    h_MPtEle->Fill(thisEleP4->Pt());
                    h_MedCh->Fill((*eleChHadIso)[i]/thisEleP4->Pt());
                    h_MedNe->Fill((*eleNeHadIso)[i]/thisEleP4->Pt());
                    h_MedGa->Fill((*eleGamIso)[i]/thisEleP4->Pt());
                }
        }



   }//Event loop
   h_LooseCh-> SetXTitle("eleChHadIso/Pt_ele");
   h_LooseNe-> SetXTitle("eleNeHadIso/Pt_ele");
   h_LooseGa-> SetXTitle("eleGamIso/Pt_ele");
   h_MedCh-> SetXTitle("eleChHadIso/Pt_ele");
   h_MedNe-> SetXTitle("eleNeHadIso/Pt_ele");
   h_MedGa-> SetXTitle("eleGamIso/Pt_ele");
   h_VetoCh-> SetXTitle("eleChHadIso/Pt_ele");
   h_VetoNe-> SetXTitle("eleNeHadIso/Pt_ele");
   h_VetoGa-> SetXTitle("eleGamIso/Pt_ele");
   h_PtEle->Write();
   h_LPtEle->Write();
   h_MPtEle->Write();
   h_nEle->Write();
   h_PtLJ->Write();
   h_PtSJ->Write();
   h_dREleLJ->Write();
   h_dREleSJ->Write();
   h_dRCEleJet->Write();
   h_eleL->Write();
   h_eleS->Write();
   h_eleC->Write(); 
   h_LooseCh->Write();
   h_LooseNe->Write();
   h_LooseGa->Write();
   h_MedCh->Write();
   h_MedNe->Write();
   h_MedGa->Write();
   h_VetoCh->Write();
   h_VetoNe->Write();
   h_VetoGa->Write();
   h_dR1->Write();
   h_dR2->Write();
   h_dR3->Write();
}
