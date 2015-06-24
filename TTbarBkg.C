#define TTbarBkg_cxx
#include "TTbarBkg.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

int momTop(int pid){
	return abs(pid);
}

bool is2Jets(int index, int d1, int d2){
	bool flag = false;
	if(abs(d1) <=6 && abs(d1)!=0) flag = true;
	if(flag){
		if(abs(d2) <=6 && abs(d2)!=0) return true;
	}
	return false;
}

bool is1lep1nu(int index, int d1, int d2){
	bool flag = false;
	if(abs(d1) == 11 || abs(d1) == 13 || abs(d1) ==15) flag = true;
	if(flag){
		if(abs(d2) == 12 || abs(d2) == 14 || abs(d2) ==16) return true;
	}
	return false;
}

bool is1Nu1Lep(int index, int d1, int d2){
	bool flag = false;
	if(abs(d2) == 11 || abs(d2) == 13 || abs(d2) ==15) flag = true;
	if(flag){
		if(abs(d1) == 12 || abs(d1) == 14 || abs(d1) ==16) return true;
	}
	return false;
}

void TTbarBkg::Loop()
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
        int nW_lep=0, nW_had=0;

        /**** GenInfo Loop ****/
    	for (int i=0; i< nGenPar; i++){
            /**** W Info Loop ****/
    	  	if(abs((*genParId)[i]) == 24){
                /**** select w's mother ****/
    	  		if(momTop((*genParId)[(*genMo1)[i]]) == 6 || momTop((*genParId)[(*genMo2)[i]]) == 6){
                    /**** select w's daughter ****/
    	  			int da1 = (*genParId)[(*genDa1)[i]];
    	  			int da2 = (*genParId)[(*genDa2)[i]];
    	  			if(is2Jets(i,da1,da2)) nW_had++;
    	  			if(is1lep1nu(i,da1,da2) || is1Nu1Lep(i,da1,da2)) nW_lep++;
    	  		}//momTop
    	  	}//W info
    	}//GenLoop

        /**** counting event info which contains at leatst 2 W bosons ****/
    	if (nW_lep >= 2) nEve_2Lep++;
    	if (nW_had >= 2) nEve_2Had++;
    	if (nW_had >= 1 && nW_lep >= 1) nEve_1Lep1Had++;
    }//event loop

    cout<<"nEve_1Lep1Had:"<<nEve_1Lep1Had<<" nEve_2Lep:"<<nEve_2Lep<<" nEve_2Had:"<<nEve_2Had<<endl;
}//TTbarBkg loop
