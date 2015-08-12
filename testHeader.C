#define testHeader_cxx
#include "testHeader.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <CountDecayMode.h>

void testHeader::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   int a=0, b=0, c=0;
   CountDecayMode count;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

        a = count.getNumHad(genMomParId,genParId, nGenPar); 
        b = count.getNumlep(genMomParId,genParId, nGenPar);
        c = count.getNumhalf(genMomParId,genParId, nGenPar);
      // count.printNumMode(genMomParId,genParId, nGenPar);
   }
   cout<<"num_had: "<<a<<" num_lep: "<<b<<" num_half: "<<c<<endl;
}
