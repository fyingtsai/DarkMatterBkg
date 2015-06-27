#define bkg2_TreeMaker_cxx
#include "bkg2_TreeMaker.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

bool isHadronicW(int id){
	if(abs(id)<6)return true;
        else return false;
}

bool isLeptonicW(int id){
	if(abs(id) == 11 || abs(id) == 13 || abs(id) ==15) return true;
        else return false;
}

bool isNutrino(int id){
    if(abs(id) == 12 || abs(id) == 14 || abs(id) ==16) return true;
        else return false;
}

void bkg2_TreeMaker::Loop()
{
    if (fChain == 0) return;
 
    Long64_t nentries = fChain->GetEntriesFast();
 
    Long64_t nbytes = 0, nb = 0;
    int nEve_1Lep1Had=0, nEve_2Lep=0, nEve_2Had=0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        // if (Cut(ientry) < 0) continue;
        int nW_lep=0, nW_had=0, nw_nu=0;
        vector<int>     pid,status,mom;
        /**** GenInfo Loop ****/
    	for (int i=0; i< nGenPar; i++){
            pid.push_back((*genParId)[i]);
            status.push_back((*genParSt)[i]);
            mom.push_back((*genMomParId)[i]);
            if((*genParSt)[i]>=20 && (*genParSt)[i] <=30){
            	if(abs((*genMomParId)[i]) == 24){
            		if(isHadronicW((*genParId)[i]))nW_had++;
            		if(isLeptonicW((*genParId)[i]))nW_lep++;
                    if(isNutrino((*genParId)[i]))nw_nu++;
            	}//W mom
            }//HardScattering
    	}//GenLoop

        /*******For Checking*******/
        // if (jentry<=10) {
        //     cout<<"nentry:"<<jentry<<endl;
        //     for(int i=0; i< pid.size(); i++){
        //     	cout<<"pid: "<<pid[i]<<" status: "<<status[i]<<" Mom: "<<mom[i]<<endl;
        //     }
        // }
        
        /**** counting event info which contains at leatst 2 W bosons ****/
    	if (nW_lep == 2 && nw_nu ==2) nEve_2Lep++;
    	if (nW_had == 4) nEve_2Had++;
    	if (nW_had == 2 && nW_lep == 1 && nw_nu ==1) nEve_1Lep1Had++;
    }//event loop

    cout<<"event:"<<nentries<<" nEve_1Lep1Had:"<<nEve_1Lep1Had<<" nEve_2Lep:"<<nEve_2Lep<<" nEve_2Had:"<<nEve_2Had<<endl;
}
