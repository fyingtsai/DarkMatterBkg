//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jun 23 03:40:18 2015 by ROOT version 6.02/05
// from TTree tree/tree
// found on file: bkg_TTbar.root
//////////////////////////////////////////////////////////

#ifndef TTbarBkg_h
#define TTbarBkg_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "TClonesArray.h"
#include "vector"
#include "vector"

class TTbarBkg {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxpfmvaMetPt = 1;
   const Int_t kMaxpfmvaMetPhi = 1;
   const Int_t kMaxpfmvaMetSumEt = 1;
   const Int_t kMaxpfmvaMetSig = 1;

   // Declaration of leaf types
   Float_t         pu_nTrueInt;
   Int_t           pu_nPUVert;
   Int_t           info_isData;
   Int_t           info_eventId;
   Int_t           info_runId;
   Int_t           info_lumiSection;
   Int_t           info_bunchXing;
   Int_t           info_nVtx;
   vector<float>   *info_vx;
   vector<float>   *info_vy;
   vector<float>   *info_vz;
   Float_t         ptHat;
   Float_t         mcWeight;
   Int_t           nGenPar;
   vector<float>   *genParE;
   vector<float>   *genParPt;
   vector<float>   *genParEta;
   vector<float>   *genParPhi;
   vector<float>   *genParM;
   vector<int>     *genParQ;
   vector<int>     *genParId;
   vector<int>     *genParSt;
   vector<int>     *genMomParId;
   vector<int>     *genParIndex;
   vector<int>     *genNMo;
   vector<int>     *genNDa;
   vector<int>     *genMo1;
   vector<int>     *genMo2;
   vector<int>     *genDa1;
   vector<int>     *genDa2;
   Int_t           nGenJet;
   vector<float>   *genJetE;
   vector<float>   *genJetPt;
   vector<float>   *genJetEta;
   vector<float>   *genJetPhi;
   vector<float>   *genJetEM;
   vector<float>   *genJetHAD;
   Int_t           nMu;
   vector<int>     *muType;
   vector<float>   *muPt;
   vector<float>   *muEta;
   vector<float>   *muPhi;
   vector<float>   *muM;
   vector<float>   *muTrkIso;
   vector<float>   *muCorrTrkIso;
   vector<float>   *muHcalIso;
   vector<float>   *muEcalIso;
   vector<float>   *muCharge;
   vector<float>   *muChHadIso;
   vector<float>   *muNeHadIso;
   vector<float>   *muGamIso;
   vector<float>   *muPUPt;
   vector<float>   *muCorrPfIso;
   vector<int>     *isGlobalMuon;
   vector<int>     *isTrackerMuon;
   vector<float>   *muPtErrx;
   vector<float>   *mudxy;
   vector<float>   *mudz;
   vector<int>     *muTrkLayers;
   vector<int>     *muPixelHits;
   vector<int>     *muHits;
   vector<int>     *muMatches;
   vector<int>     *muITrkID;
   vector<int>     *muSegID;
   vector<int>     *muNSegs;
   vector<int>     *muGood;
   Int_t           nEle;
   Float_t         eleRho;
   vector<float>   *eleEt;
   vector<float>   *eleEnergy;
   vector<float>   *elePt;
   vector<float>   *eleEta;
   vector<float>   *elePhi;
   vector<float>   *eleM;
   vector<float>   *eleCharge;
   vector<float>   *eleScEta;
   vector<float>   *eleSigIhIh;
   vector<float>   *eleDelEtaIn;
   vector<float>   *eleDelPhiIn;
   vector<float>   *eleHoE;
   vector<float>   *eleTrkIso;
   vector<float>   *eleHcalIso;
   vector<float>   *eleEcalIso;
   vector<float>   *eleEoverP;
   vector<float>   *eleDxy;
   vector<float>   *eleDz;
   vector<float>   *eleChHadIso;
   vector<float>   *eleNeHadIso;
   vector<float>   *eleGamIso;
   vector<float>   *elePUPt;
   vector<float>   *eleCorrPfIso;
   vector<float>   *eleInBarrel;
   vector<float>   *eleInEndcap;
   vector<int>     *elePassConv;
   Float_t         pfMetCorrPt;
   Float_t         pfMetCorrPhi;
   Float_t         pfMetCorrSumEt;
   Float_t         pfMetCorrSig;
   Float_t         pfMetRawPt;
   Float_t         pfMetRawPhi;
   Float_t         pfMetRawSumEt;
   Float_t         pfMetRawCov00;
   Float_t         pfMetRawCov01;
   Float_t         pfMetRawCov10;
   Float_t         pfMetRawCov11;
   Float_t         pfmvaMetPt_;
   Float_t         pfmvaMetPhi_;
   Float_t         pfmvaMetSumEt_;
   Float_t         pfmvaMetSig_;
   Int_t           CA8nJet;
   vector<float>   *CA8jetPt;
   vector<float>   *CA8jetEta;
   vector<float>   *CA8jetPhi;
   vector<float>   *CA8jetMass;
   vector<float>   *CA8jetEn;
   vector<float>   *CA8genjetPx;
   vector<float>   *CA8genjetPy;
   vector<float>   *CA8genjetPz;
   vector<float>   *CA8genjetEn;
   vector<float>   *CA8genjetEM;
   vector<float>   *CA8genjetHAD;
   vector<float>   *CA8genjetINV;
   vector<float>   *CA8genjetAUX;
   vector<float>   *CA8matchedDR;
   vector<float>   *CA8jetCorrUncUp;
   vector<float>   *CA8jetCorrUncDown;
   vector<int>     *CA8jetCharge;
   vector<int>     *CA8jetPartonFlavor;
   vector<int>     *CA8jetPassID;
   vector<float>   *CA8jetSSV;
   vector<float>   *CA8jetSSVHE;
   vector<float>   *CA8jetCSV;
   vector<float>   *CA8jetCISVV2;
   vector<float>   *CA8jetTCHP;
   vector<float>   *CA8jetTCHE;
   vector<float>   *CA8jetJP;
   vector<float>   *CA8jetJBP;
   vector<float>   *CA8jetTau1;
   vector<float>   *CA8jetTau2;
   vector<float>   *CA8jetTau3;
   vector<float>   *CA8jetTau4;
   vector<float>   *CA8jetMuEF;
   vector<float>   *CA8jetPhoEF;
   vector<float>   *CA8jetCEmEF;
   vector<float>   *CA8jetCHadEF;
   vector<float>   *CA8jetNEmEF;
   vector<float>   *CA8jetNHadEF;
   vector<float>   *CA8jetCMulti;
   vector<float>   *CA8jetPrunedPt;
   vector<float>   *CA8jetPrunedEta;
   vector<float>   *CA8jetPrunedPhi;
   vector<float>   *CA8jetPrunedMass;
   vector<float>   *CA8jetPrunedEn;
   vector<float>   *CA8jetPrunedCorrUncUp;
   vector<float>   *CA8jetPrunedCorrUncDown;
   vector<int>     *CA8jetPrunedCharge;
   vector<int>     *CA8jetPrunedPartonFlavor;
   vector<float>   *CA8jetPrunedSSV;
   vector<float>   *CA8jetPrunedCSV;
   vector<float>   *CA8jetPrunedTCHP;
   vector<float>   *CA8jetPrunedTCHE;
   vector<float>   *CA8jetPrunedJP;
   vector<float>   *CA8jetPrunedJBP;
   vector<float>   *CA8jetSDmass;
   vector<float>   *CA8jetTRmass;
   vector<float>   *CA8jetPRmass;
   vector<float>   *CA8jetFimass;
   vector<int>     *CA8nSubSDJet;
   vector<vector<float> > *subjetSDPt;
   vector<vector<float> > *subjetSDEta;
   vector<vector<float> > *subjetSDPhi;
   vector<vector<float> > *subjetSDMass;
   vector<vector<float> > *subjetSDCSV;
   Int_t           AK5nJet;
   vector<float>   *AK5jetPt;
   vector<float>   *AK5jetEta;
   vector<float>   *AK5jetPhi;
   vector<float>   *AK5jetMass;
   vector<float>   *AK5jetEn;
   vector<float>   *AK5genjetPx;
   vector<float>   *AK5genjetPy;
   vector<float>   *AK5genjetPz;
   vector<float>   *AK5genjetEn;
   vector<float>   *AK5genjetEM;
   vector<float>   *AK5genjetHAD;
   vector<float>   *AK5genjetINV;
   vector<float>   *AK5genjetAUX;
   vector<float>   *AK5matchedDR;
   vector<float>   *AK5jetCorrUncUp;
   vector<float>   *AK5jetCorrUncDown;
   vector<int>     *AK5jetCharge;
   vector<int>     *AK5jetPartonFlavor;
   vector<int>     *AK5jetPassID;
   vector<float>   *AK5jetSSV;
   vector<float>   *AK5jetSSVHE;
   vector<float>   *AK5jetCSV;
   vector<float>   *AK5jetCISVV2;
   vector<float>   *AK5jetTCHP;
   vector<float>   *AK5jetTCHE;
   vector<float>   *AK5jetJP;
   vector<float>   *AK5jetJBP;
   vector<float>   *AK5jetTau1;
   vector<float>   *AK5jetTau2;
   vector<float>   *AK5jetTau3;
   vector<float>   *AK5jetTau4;
   vector<float>   *AK5jetMuEF;
   vector<float>   *AK5jetPhoEF;
   vector<float>   *AK5jetCEmEF;
   vector<float>   *AK5jetCHadEF;
   vector<float>   *AK5jetNEmEF;
   vector<float>   *AK5jetNHadEF;
   vector<float>   *AK5jetCMulti;
   Int_t           genjetngenMuons;
   Int_t           genjetgenjet_n;
   TClonesArray    *GenJets_4Momentum;
   Int_t           hlt_nTrigs;
   vector<int>     *hlt_trigResult;
   vector<string>  *trigName;
   Int_t           HPSTau_n;
   vector<float>   *taupt;
   TClonesArray    *HPSTau_4Momentum;
   TClonesArray    *HPSTau_Vposition;
   vector<bool>    *HPSTau_leadPFChargedHadrCand;
   vector<bool>    *HPSTau_leadPFChargedHadrCand_trackRef;
   vector<bool>    *disc_againstElectronLoose;
   vector<bool>    *disc_againstElectronMedium;
   vector<bool>    *disc_againstElectronTight;
   vector<bool>    *disc_againstElectronLooseMVA5;
   vector<bool>    *disc_againstElectronMediumMVA5;
   vector<bool>    *disc_againstElectronTightMVA5;
   vector<bool>    *disc_againstElectronVLooseMVA5;
   vector<bool>    *disc_againstElectronVTightMVA5;
   vector<bool>    *disc_againstMuonLoose;
   vector<bool>    *disc_againstMuonMedium;
   vector<bool>    *disc_againstMuonTight;
   vector<bool>    *disc_againstMuonLoose2;
   vector<bool>    *disc_againstMuonMedium2;
   vector<bool>    *disc_againstMuonTight2;
   vector<bool>    *disc_againstMuonLooseMVA;
   vector<bool>    *disc_againstMuonMediumMVA;
   vector<bool>    *disc_againstMuonTightMVA;
   vector<bool>    *disc_againstMuonLoose3;
   vector<bool>    *disc_againstMuonTight3;
   vector<bool>    *disc_byVLooseCombinedIsolationDeltaBetaCorr;
   vector<bool>    *disc_byLooseCombinedIsolationDeltaBetaCorr;
   vector<bool>    *disc_byMediumCombinedIsolationDeltaBetaCorr;
   vector<bool>    *disc_byTightCombinedIsolationDeltaBetaCorr;
   vector<bool>    *disc_byLooseIsolation;
   vector<bool>    *disc_byVLooseIsolationMVA3newDMwLT;
   vector<bool>    *disc_byLooseIsolationMVA3newDMwLT;
   vector<bool>    *disc_byMediumIsolationMVA3newDMwLT;
   vector<bool>    *disc_byTightIsolationMVA3newDMwLT;
   vector<bool>    *disc_byVTightIsolationMVA3newDMwLT;
   vector<bool>    *disc_byVVTightIsolationMVA3newDMwLT;
   vector<bool>    *disc_byVLooseIsolationMVA3newDMwoLT;
   vector<bool>    *disc_byLooseIsolationMVA3newDMwoLT;
   vector<bool>    *disc_byMediumIsolationMVA3newDMwoLT;
   vector<bool>    *disc_byTightIsolationMVA3newDMwoLT;
   vector<bool>    *disc_byVTightIsolationMVA3newDMwoLT;
   vector<bool>    *disc_byVVTightIsolationMVA3newDMwoLT;
   vector<bool>    *disc_byVLooseIsolationMVA3oldDMwLT;
   vector<bool>    *disc_byLooseIsolationMVA3oldDMwLT;
   vector<bool>    *disc_byMediumIsolationMVA3oldDMwLT;
   vector<bool>    *disc_byTightIsolationMVA3oldDMwLT;
   vector<bool>    *disc_byVTightIsolationMVA3oldDMwLT;
   vector<bool>    *disc_byVVTightIsolationMVA3oldDMwLT;
   vector<bool>    *disc_byVLooseIsolationMVA3oldDMwoLT;
   vector<bool>    *disc_byLooseIsolationMVA3oldDMwoLT;
   vector<bool>    *disc_byMediumIsolationMVA3oldDMwoLT;
   vector<bool>    *disc_byTightIsolationMVA3oldDMwoLT;
   vector<bool>    *disc_byVTightIsolationMVA3oldDMwoLT;
   vector<bool>    *disc_byVVTightIsolationMVA3oldDMwoLT;
   vector<bool>    *disc_byLooseCombinedIsolationDeltaBetaCorr3Hits;
   vector<bool>    *disc_byMediumCombinedIsolationDeltaBetaCorr3Hits;
   vector<bool>    *disc_byTightCombinedIsolationDeltaBetaCorr3Hits;
   vector<bool>    *disc_decayModeFinding;
   vector<bool>    *disc_decayModeFindingNewDMs;
   vector<float>   *disc_chargedIsoPtSum;
   vector<float>   *disc_neutralIsoPtSum;
   vector<float>   *disc_puCorrPtSum;
   vector<float>   *HPSTau_NewVz;
   vector<int>     *HPSTau_charge;

   // List of branches
   TBranch        *b_pu_nTrueInt;   //!
   TBranch        *b_pu_nPUVert;   //!
   TBranch        *b_info_isData;   //!
   TBranch        *b_info_eventId;   //!
   TBranch        *b_info_runId;   //!
   TBranch        *b_info_lumiSection;   //!
   TBranch        *b_info_bunchXing;   //!
   TBranch        *b_info_nVtx;   //!
   TBranch        *b_info_vx;   //!
   TBranch        *b_info_vy;   //!
   TBranch        *b_info_vz;   //!
   TBranch        *b_ptHat;   //!
   TBranch        *b_mcWeight;   //!
   TBranch        *b_nGenPar;   //!
   TBranch        *b_genParE;   //!
   TBranch        *b_genParPt;   //!
   TBranch        *b_genParEta;   //!
   TBranch        *b_genParPhi;   //!
   TBranch        *b_genParM;   //!
   TBranch        *b_genParQ;   //!
   TBranch        *b_genParId;   //!
   TBranch        *b_genParSt;   //!
   TBranch        *b_genMomParId;   //!
   TBranch        *b_genParIndex;   //!
   TBranch        *b_genNMo;   //!
   TBranch        *b_genNDa;   //!
   TBranch        *b_genMo1;   //!
   TBranch        *b_genMo2;   //!
   TBranch        *b_genDa1;   //!
   TBranch        *b_genDa2;   //!
   TBranch        *b_nGenJet;   //!
   TBranch        *b_genJetE;   //!
   TBranch        *b_genJetPt;   //!
   TBranch        *b_genJetEta;   //!
   TBranch        *b_genJetPhi;   //!
   TBranch        *b_genJetEM;   //!
   TBranch        *b_genJetHAD;   //!
   TBranch        *b_nMu;   //!
   TBranch        *b_muType;   //!
   TBranch        *b_muPt;   //!
   TBranch        *b_muEta;   //!
   TBranch        *b_muPhi;   //!
   TBranch        *b_muM;   //!
   TBranch        *b_muTrkIso;   //!
   TBranch        *b_muCorrTrkIso;   //!
   TBranch        *b_muHcalIso;   //!
   TBranch        *b_muEcalIso;   //!
   TBranch        *b_muCharge;   //!
   TBranch        *b_muChHadIso;   //!
   TBranch        *b_muNeHadIso;   //!
   TBranch        *b_muGamIso;   //!
   TBranch        *b_muPUPt;   //!
   TBranch        *b_muCorrPfIso;   //!
   TBranch        *b_isGlobalMuon;   //!
   TBranch        *b_isTrackerMuon;   //!
   TBranch        *b_muPtErrx;   //!
   TBranch        *b_mudxy;   //!
   TBranch        *b_mudz;   //!
   TBranch        *b_muTrkLayers;   //!
   TBranch        *b_muPixelHits;   //!
   TBranch        *b_muHits;   //!
   TBranch        *b_muMatches;   //!
   TBranch        *b_muITrkID;   //!
   TBranch        *b_muSegID;   //!
   TBranch        *b_muNSegs;   //!
   TBranch        *b_muGood;   //!
   TBranch        *b_nEle;   //!
   TBranch        *b_eleRho;   //!
   TBranch        *b_eleEt;   //!
   TBranch        *b_eleEnergy;   //!
   TBranch        *b_elePt;   //!
   TBranch        *b_eleEta;   //!
   TBranch        *b_elePhi;   //!
   TBranch        *b_eleM;   //!
   TBranch        *b_eleCharge;   //!
   TBranch        *b_eleScEta;   //!
   TBranch        *b_eleSigIhIh;   //!
   TBranch        *b_eleDelEtaIn;   //!
   TBranch        *b_eleDelPhiIn;   //!
   TBranch        *b_eleHoE;   //!
   TBranch        *b_eleTrkIso;   //!
   TBranch        *b_eleHcalIso;   //!
   TBranch        *b_eleEcalIso;   //!
   TBranch        *b_eleEoverP;   //!
   TBranch        *b_eleDxy;   //!
   TBranch        *b_eleDz;   //!
   TBranch        *b_eleChHadIso;   //!
   TBranch        *b_eleNeHadIso;   //!
   TBranch        *b_eleGamIso;   //!
   TBranch        *b_elePUPt;   //!
   TBranch        *b_eleCorrPfIso;   //!
   TBranch        *b_eleInBarrel;   //!
   TBranch        *b_eleInEndcap;   //!
   TBranch        *b_elePassConv;   //!
   TBranch        *b_pfMetCorrPt;   //!
   TBranch        *b_pfMetCorrPhi;   //!
   TBranch        *b_pfMetCorrSumEt;   //!
   TBranch        *b_pfMetCorrSig;   //!
   TBranch        *b_pfMetRawPt;   //!
   TBranch        *b_pfMetRawPhi;   //!
   TBranch        *b_pfMetRawSumEt;   //!
   TBranch        *b_pfMetRawCov00;   //!
   TBranch        *b_pfMetRawCov01;   //!
   TBranch        *b_pfMetRawCov10;   //!
   TBranch        *b_pfMetRawCov11;   //!
   TBranch        *b_pfmvaMetPt_;   //!
   TBranch        *b_pfmvaMetPhi_;   //!
   TBranch        *b_pfmvaMetSumEt_;   //!
   TBranch        *b_pfmvaMetSig_;   //!
   TBranch        *b_CA8nJet;   //!
   TBranch        *b_CA8jetPt;   //!
   TBranch        *b_CA8jetEta;   //!
   TBranch        *b_CA8jetPhi;   //!
   TBranch        *b_CA8jetMass;   //!
   TBranch        *b_CA8jetEn;   //!
   TBranch        *b_CA8genjetPx;   //!
   TBranch        *b_CA8genjetPy;   //!
   TBranch        *b_CA8genjetPz;   //!
   TBranch        *b_CA8genjetEn;   //!
   TBranch        *b_CA8genjetEM;   //!
   TBranch        *b_CA8genjetHAD;   //!
   TBranch        *b_CA8genjetINV;   //!
   TBranch        *b_CA8genjetAUX;   //!
   TBranch        *b_CA8matchedDR;   //!
   TBranch        *b_CA8jetCorrUncUp;   //!
   TBranch        *b_CA8jetCorrUncDown;   //!
   TBranch        *b_CA8jetCharge;   //!
   TBranch        *b_CA8jetPartonFlavor;   //!
   TBranch        *b_CA8jetPassID;   //!
   TBranch        *b_CA8jetSSV;   //!
   TBranch        *b_CA8jetSSVHE;   //!
   TBranch        *b_CA8jetCSV;   //!
   TBranch        *b_CA8jetCISVV2;   //!
   TBranch        *b_CA8jetTCHP;   //!
   TBranch        *b_CA8jetTCHE;   //!
   TBranch        *b_CA8jetJP;   //!
   TBranch        *b_CA8jetJBP;   //!
   TBranch        *b_CA8jetTau1;   //!
   TBranch        *b_CA8jetTau2;   //!
   TBranch        *b_CA8jetTau3;   //!
   TBranch        *b_CA8jetTau4;   //!
   TBranch        *b_CA8jetMuEF;   //!
   TBranch        *b_CA8jetPhoEF;   //!
   TBranch        *b_CA8jetCEmEF;   //!
   TBranch        *b_CA8jetCHadEF;   //!
   TBranch        *b_CA8jetNEmEF;   //!
   TBranch        *b_CA8jetNHadEF;   //!
   TBranch        *b_CA8jetCMulti;   //!
   TBranch        *b_CA8jetPrunedPt;   //!
   TBranch        *b_CA8jetPrunedEta;   //!
   TBranch        *b_CA8jetPrunedPhi;   //!
   TBranch        *b_CA8jetPrunedMass;   //!
   TBranch        *b_CA8jetPrunedEn;   //!
   TBranch        *b_CA8jetPrunedCorrUncUp;   //!
   TBranch        *b_CA8jetPrunedCorrUncDown;   //!
   TBranch        *b_CA8jetPrunedCharge;   //!
   TBranch        *b_CA8jetPrunedPartonFlavor;   //!
   TBranch        *b_CA8jetPrunedSSV;   //!
   TBranch        *b_CA8jetPrunedCSV;   //!
   TBranch        *b_CA8jetPrunedTCHP;   //!
   TBranch        *b_CA8jetPrunedTCHE;   //!
   TBranch        *b_CA8jetPrunedJP;   //!
   TBranch        *b_CA8jetPrunedJBP;   //!
   TBranch        *b_CA8jetSDmass;   //!
   TBranch        *b_CA8jetTRmass;   //!
   TBranch        *b_CA8jetPRmass;   //!
   TBranch        *b_CA8jetFimass;   //!
   TBranch        *b_CA8nSubSDJet;   //!
   TBranch        *b_subjetSDPt;   //!
   TBranch        *b_subjetSDEta;   //!
   TBranch        *b_subjetSDPhi;   //!
   TBranch        *b_subjetSDMass;   //!
   TBranch        *b_subjetSDCSV;   //!
   TBranch        *b_AK5nJet;   //!
   TBranch        *b_AK5jetPt;   //!
   TBranch        *b_AK5jetEta;   //!
   TBranch        *b_AK5jetPhi;   //!
   TBranch        *b_AK5jetMass;   //!
   TBranch        *b_AK5jetEn;   //!
   TBranch        *b_AK5genjetPx;   //!
   TBranch        *b_AK5genjetPy;   //!
   TBranch        *b_AK5genjetPz;   //!
   TBranch        *b_AK5genjetEn;   //!
   TBranch        *b_AK5genjetEM;   //!
   TBranch        *b_AK5genjetHAD;   //!
   TBranch        *b_AK5genjetINV;   //!
   TBranch        *b_AK5genjetAUX;   //!
   TBranch        *b_AK5matchedDR;   //!
   TBranch        *b_AK5jetCorrUncUp;   //!
   TBranch        *b_AK5jetCorrUncDown;   //!
   TBranch        *b_AK5jetCharge;   //!
   TBranch        *b_AK5jetPartonFlavor;   //!
   TBranch        *b_AK5jetPassID;   //!
   TBranch        *b_AK5jetSSV;   //!
   TBranch        *b_AK5jetSSVHE;   //!
   TBranch        *b_AK5jetCSV;   //!
   TBranch        *b_AK5jetCISVV2;   //!
   TBranch        *b_AK5jetTCHP;   //!
   TBranch        *b_AK5jetTCHE;   //!
   TBranch        *b_AK5jetJP;   //!
   TBranch        *b_AK5jetJBP;   //!
   TBranch        *b_AK5jetTau1;   //!
   TBranch        *b_AK5jetTau2;   //!
   TBranch        *b_AK5jetTau3;   //!
   TBranch        *b_AK5jetTau4;   //!
   TBranch        *b_AK5jetMuEF;   //!
   TBranch        *b_AK5jetPhoEF;   //!
   TBranch        *b_AK5jetCEmEF;   //!
   TBranch        *b_AK5jetCHadEF;   //!
   TBranch        *b_AK5jetNEmEF;   //!
   TBranch        *b_AK5jetNHadEF;   //!
   TBranch        *b_AK5jetCMulti;   //!
   TBranch        *b_genjetngenMuons;   //!
   TBranch        *b_genjetgenjet_n;   //!
   TBranch        *b_GenJets_4Momentum;   //!
   TBranch        *b_hlt_nTrigs;   //!
   TBranch        *b_hlt_trigResult;   //!
   TBranch        *b_trigName;   //!
   TBranch        *b_HPSTau_n;   //!
   TBranch        *b_taupt;   //!
   TBranch        *b_HPSTau_4Momentum;   //!
   TBranch        *b_HPSTau_Vposition;   //!
   TBranch        *b_HPSTau_leadPFChargedHadrCand;   //!
   TBranch        *b_HPSTau_leadPFChargedHadrCand_trackRef;   //!
   TBranch        *b_disc_againstElectronLoose;   //!
   TBranch        *b_disc_againstElectronMedium;   //!
   TBranch        *b_disc_againstElectronTight;   //!
   TBranch        *b_disc_againstElectronLooseMVA5;   //!
   TBranch        *b_disc_againstElectronMediumMVA5;   //!
   TBranch        *b_disc_againstElectronTightMVA5;   //!
   TBranch        *b_disc_againstElectronVLooseMVA5;   //!
   TBranch        *b_disc_againstElectronVTightMVA5;   //!
   TBranch        *b_disc_againstMuonLoose;   //!
   TBranch        *b_disc_againstMuonMedium;   //!
   TBranch        *b_disc_againstMuonTight;   //!
   TBranch        *b_disc_againstMuonLoose2;   //!
   TBranch        *b_disc_againstMuonMedium2;   //!
   TBranch        *b_disc_againstMuonTight2;   //!
   TBranch        *b_disc_againstMuonLooseMVA;   //!
   TBranch        *b_disc_againstMuonMediumMVA;   //!
   TBranch        *b_disc_againstMuonTightMVA;   //!
   TBranch        *b_disc_againstMuonLoose3;   //!
   TBranch        *b_disc_againstMuonTight3;   //!
   TBranch        *b_disc_byVLooseCombinedIsolationDeltaBetaCorr;   //!
   TBranch        *b_disc_byLooseCombinedIsolationDeltaBetaCorr;   //!
   TBranch        *b_disc_byMediumCombinedIsolationDeltaBetaCorr;   //!
   TBranch        *b_disc_byTightCombinedIsolationDeltaBetaCorr;   //!
   TBranch        *b_disc_byLooseIsolation;   //!
   TBranch        *b_disc_byVLooseIsolationMVA3newDMwLT;   //!
   TBranch        *b_disc_byLooseIsolationMVA3newDMwLT;   //!
   TBranch        *b_disc_byMediumIsolationMVA3newDMwLT;   //!
   TBranch        *b_disc_byTightIsolationMVA3newDMwLT;   //!
   TBranch        *b_disc_byVTightIsolationMVA3newDMwLT;   //!
   TBranch        *b_disc_byVVTightIsolationMVA3newDMwLT;   //!
   TBranch        *b_disc_byVLooseIsolationMVA3newDMwoLT;   //!
   TBranch        *b_disc_byLooseIsolationMVA3newDMwoLT;   //!
   TBranch        *b_disc_byMediumIsolationMVA3newDMwoLT;   //!
   TBranch        *b_disc_byTightIsolationMVA3newDMwoLT;   //!
   TBranch        *b_disc_byVTightIsolationMVA3newDMwoLT;   //!
   TBranch        *b_disc_byVVTightIsolationMVA3newDMwoLT;   //!
   TBranch        *b_disc_byVLooseIsolationMVA3oldDMwLT;   //!
   TBranch        *b_disc_byLooseIsolationMVA3oldDMwLT;   //!
   TBranch        *b_disc_byMediumIsolationMVA3oldDMwLT;   //!
   TBranch        *b_disc_byTightIsolationMVA3oldDMwLT;   //!
   TBranch        *b_disc_byVTightIsolationMVA3oldDMwLT;   //!
   TBranch        *b_disc_byVVTightIsolationMVA3oldDMwLT;   //!
   TBranch        *b_disc_byVLooseIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_disc_byLooseIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_disc_byMediumIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_disc_byTightIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_disc_byVTightIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_disc_byVVTightIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_disc_byLooseCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_disc_byMediumCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_disc_byTightCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_disc_decayModeFinding;   //!
   TBranch        *b_disc_decayModeFindingNewDMs;   //!
   TBranch        *b_disc_chargedIsoPtSum;   //!
   TBranch        *b_disc_neutralIsoPtSum;   //!
   TBranch        *b_disc_puCorrPtSum;   //!
   TBranch        *b_HPSTau_NewVz;   //!
   TBranch        *b_HPSTau_charge;   //!

   TTbarBkg(TTree *tree=0);
   virtual ~TTbarBkg();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef TTbarBkg_cxx
TTbarBkg::TTbarBkg(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("bkg_ttbar.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("bkg_ttbar.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("bkg_ttbar.root:/tree");
      dir->GetObject("tree",tree);

   }
   Init(tree);
}

TTbarBkg::~TTbarBkg()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t TTbarBkg::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t TTbarBkg::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void TTbarBkg::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   info_vx = 0;
   info_vy = 0;
   info_vz = 0;
   genParE = 0;
   genParPt = 0;
   genParEta = 0;
   genParPhi = 0;
   genParM = 0;
   genParQ = 0;
   genParId = 0;
   genParSt = 0;
   genMomParId = 0;
   genParIndex = 0;
   genNMo = 0;
   genNDa = 0;
   genMo1 = 0;
   genMo2 = 0;
   genDa1 = 0;
   genDa2 = 0;
   genJetE = 0;
   genJetPt = 0;
   genJetEta = 0;
   genJetPhi = 0;
   genJetEM = 0;
   genJetHAD = 0;
   muType = 0;
   muPt = 0;
   muEta = 0;
   muPhi = 0;
   muM = 0;
   muTrkIso = 0;
   muCorrTrkIso = 0;
   muHcalIso = 0;
   muEcalIso = 0;
   muCharge = 0;
   muChHadIso = 0;
   muNeHadIso = 0;
   muGamIso = 0;
   muPUPt = 0;
   muCorrPfIso = 0;
   isGlobalMuon = 0;
   isTrackerMuon = 0;
   muPtErrx = 0;
   mudxy = 0;
   mudz = 0;
   muTrkLayers = 0;
   muPixelHits = 0;
   muHits = 0;
   muMatches = 0;
   muITrkID = 0;
   muSegID = 0;
   muNSegs = 0;
   muGood = 0;
   eleEt = 0;
   eleEnergy = 0;
   elePt = 0;
   eleEta = 0;
   elePhi = 0;
   eleM = 0;
   eleCharge = 0;
   eleScEta = 0;
   eleSigIhIh = 0;
   eleDelEtaIn = 0;
   eleDelPhiIn = 0;
   eleHoE = 0;
   eleTrkIso = 0;
   eleHcalIso = 0;
   eleEcalIso = 0;
   eleEoverP = 0;
   eleDxy = 0;
   eleDz = 0;
   eleChHadIso = 0;
   eleNeHadIso = 0;
   eleGamIso = 0;
   elePUPt = 0;
   eleCorrPfIso = 0;
   eleInBarrel = 0;
   eleInEndcap = 0;
   elePassConv = 0;
   CA8jetPt = 0;
   CA8jetEta = 0;
   CA8jetPhi = 0;
   CA8jetMass = 0;
   CA8jetEn = 0;
   CA8genjetPx = 0;
   CA8genjetPy = 0;
   CA8genjetPz = 0;
   CA8genjetEn = 0;
   CA8genjetEM = 0;
   CA8genjetHAD = 0;
   CA8genjetINV = 0;
   CA8genjetAUX = 0;
   CA8matchedDR = 0;
   CA8jetCorrUncUp = 0;
   CA8jetCorrUncDown = 0;
   CA8jetCharge = 0;
   CA8jetPartonFlavor = 0;
   CA8jetPassID = 0;
   CA8jetSSV = 0;
   CA8jetSSVHE = 0;
   CA8jetCSV = 0;
   CA8jetCISVV2 = 0;
   CA8jetTCHP = 0;
   CA8jetTCHE = 0;
   CA8jetJP = 0;
   CA8jetJBP = 0;
   CA8jetTau1 = 0;
   CA8jetTau2 = 0;
   CA8jetTau3 = 0;
   CA8jetTau4 = 0;
   CA8jetMuEF = 0;
   CA8jetPhoEF = 0;
   CA8jetCEmEF = 0;
   CA8jetCHadEF = 0;
   CA8jetNEmEF = 0;
   CA8jetNHadEF = 0;
   CA8jetCMulti = 0;
   CA8jetPrunedPt = 0;
   CA8jetPrunedEta = 0;
   CA8jetPrunedPhi = 0;
   CA8jetPrunedMass = 0;
   CA8jetPrunedEn = 0;
   CA8jetPrunedCorrUncUp = 0;
   CA8jetPrunedCorrUncDown = 0;
   CA8jetPrunedCharge = 0;
   CA8jetPrunedPartonFlavor = 0;
   CA8jetPrunedSSV = 0;
   CA8jetPrunedCSV = 0;
   CA8jetPrunedTCHP = 0;
   CA8jetPrunedTCHE = 0;
   CA8jetPrunedJP = 0;
   CA8jetPrunedJBP = 0;
   CA8jetSDmass = 0;
   CA8jetTRmass = 0;
   CA8jetPRmass = 0;
   CA8jetFimass = 0;
   CA8nSubSDJet = 0;
   subjetSDPt = 0;
   subjetSDEta = 0;
   subjetSDPhi = 0;
   subjetSDMass = 0;
   subjetSDCSV = 0;
   AK5jetPt = 0;
   AK5jetEta = 0;
   AK5jetPhi = 0;
   AK5jetMass = 0;
   AK5jetEn = 0;
   AK5genjetPx = 0;
   AK5genjetPy = 0;
   AK5genjetPz = 0;
   AK5genjetEn = 0;
   AK5genjetEM = 0;
   AK5genjetHAD = 0;
   AK5genjetINV = 0;
   AK5genjetAUX = 0;
   AK5matchedDR = 0;
   AK5jetCorrUncUp = 0;
   AK5jetCorrUncDown = 0;
   AK5jetCharge = 0;
   AK5jetPartonFlavor = 0;
   AK5jetPassID = 0;
   AK5jetSSV = 0;
   AK5jetSSVHE = 0;
   AK5jetCSV = 0;
   AK5jetCISVV2 = 0;
   AK5jetTCHP = 0;
   AK5jetTCHE = 0;
   AK5jetJP = 0;
   AK5jetJBP = 0;
   AK5jetTau1 = 0;
   AK5jetTau2 = 0;
   AK5jetTau3 = 0;
   AK5jetTau4 = 0;
   AK5jetMuEF = 0;
   AK5jetPhoEF = 0;
   AK5jetCEmEF = 0;
   AK5jetCHadEF = 0;
   AK5jetNEmEF = 0;
   AK5jetNHadEF = 0;
   AK5jetCMulti = 0;
   GenJets_4Momentum = 0;
   hlt_trigResult = 0;
   trigName = 0;
   taupt = 0;
   HPSTau_4Momentum = 0;
   HPSTau_Vposition = 0;
   HPSTau_leadPFChargedHadrCand = 0;
   HPSTau_leadPFChargedHadrCand_trackRef = 0;
   disc_againstElectronLoose = 0;
   disc_againstElectronMedium = 0;
   disc_againstElectronTight = 0;
   disc_againstElectronLooseMVA5 = 0;
   disc_againstElectronMediumMVA5 = 0;
   disc_againstElectronTightMVA5 = 0;
   disc_againstElectronVLooseMVA5 = 0;
   disc_againstElectronVTightMVA5 = 0;
   disc_againstMuonLoose = 0;
   disc_againstMuonMedium = 0;
   disc_againstMuonTight = 0;
   disc_againstMuonLoose2 = 0;
   disc_againstMuonMedium2 = 0;
   disc_againstMuonTight2 = 0;
   disc_againstMuonLooseMVA = 0;
   disc_againstMuonMediumMVA = 0;
   disc_againstMuonTightMVA = 0;
   disc_againstMuonLoose3 = 0;
   disc_againstMuonTight3 = 0;
   disc_byVLooseCombinedIsolationDeltaBetaCorr = 0;
   disc_byLooseCombinedIsolationDeltaBetaCorr = 0;
   disc_byMediumCombinedIsolationDeltaBetaCorr = 0;
   disc_byTightCombinedIsolationDeltaBetaCorr = 0;
   disc_byLooseIsolation = 0;
   disc_byVLooseIsolationMVA3newDMwLT = 0;
   disc_byLooseIsolationMVA3newDMwLT = 0;
   disc_byMediumIsolationMVA3newDMwLT = 0;
   disc_byTightIsolationMVA3newDMwLT = 0;
   disc_byVTightIsolationMVA3newDMwLT = 0;
   disc_byVVTightIsolationMVA3newDMwLT = 0;
   disc_byVLooseIsolationMVA3newDMwoLT = 0;
   disc_byLooseIsolationMVA3newDMwoLT = 0;
   disc_byMediumIsolationMVA3newDMwoLT = 0;
   disc_byTightIsolationMVA3newDMwoLT = 0;
   disc_byVTightIsolationMVA3newDMwoLT = 0;
   disc_byVVTightIsolationMVA3newDMwoLT = 0;
   disc_byVLooseIsolationMVA3oldDMwLT = 0;
   disc_byLooseIsolationMVA3oldDMwLT = 0;
   disc_byMediumIsolationMVA3oldDMwLT = 0;
   disc_byTightIsolationMVA3oldDMwLT = 0;
   disc_byVTightIsolationMVA3oldDMwLT = 0;
   disc_byVVTightIsolationMVA3oldDMwLT = 0;
   disc_byVLooseIsolationMVA3oldDMwoLT = 0;
   disc_byLooseIsolationMVA3oldDMwoLT = 0;
   disc_byMediumIsolationMVA3oldDMwoLT = 0;
   disc_byTightIsolationMVA3oldDMwoLT = 0;
   disc_byVTightIsolationMVA3oldDMwoLT = 0;
   disc_byVVTightIsolationMVA3oldDMwoLT = 0;
   disc_byLooseCombinedIsolationDeltaBetaCorr3Hits = 0;
   disc_byMediumCombinedIsolationDeltaBetaCorr3Hits = 0;
   disc_byTightCombinedIsolationDeltaBetaCorr3Hits = 0;
   disc_decayModeFinding = 0;
   disc_decayModeFindingNewDMs = 0;
   disc_chargedIsoPtSum = 0;
   disc_neutralIsoPtSum = 0;
   disc_puCorrPtSum = 0;
   HPSTau_NewVz = 0;
   HPSTau_charge = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pu_nTrueInt", &pu_nTrueInt, &b_pu_nTrueInt);
   fChain->SetBranchAddress("pu_nPUVert", &pu_nPUVert, &b_pu_nPUVert);
   fChain->SetBranchAddress("info_isData", &info_isData, &b_info_isData);
   fChain->SetBranchAddress("info_eventId", &info_eventId, &b_info_eventId);
   fChain->SetBranchAddress("info_runId", &info_runId, &b_info_runId);
   fChain->SetBranchAddress("info_lumiSection", &info_lumiSection, &b_info_lumiSection);
   fChain->SetBranchAddress("info_bunchXing", &info_bunchXing, &b_info_bunchXing);
   fChain->SetBranchAddress("info_nVtx", &info_nVtx, &b_info_nVtx);
   fChain->SetBranchAddress("info_vx", &info_vx, &b_info_vx);
   fChain->SetBranchAddress("info_vy", &info_vy, &b_info_vy);
   fChain->SetBranchAddress("info_vz", &info_vz, &b_info_vz);
   fChain->SetBranchAddress("ptHat", &ptHat, &b_ptHat);
   fChain->SetBranchAddress("mcWeight", &mcWeight, &b_mcWeight);
   fChain->SetBranchAddress("nGenPar", &nGenPar, &b_nGenPar);
   fChain->SetBranchAddress("genParE", &genParE, &b_genParE);
   fChain->SetBranchAddress("genParPt", &genParPt, &b_genParPt);
   fChain->SetBranchAddress("genParEta", &genParEta, &b_genParEta);
   fChain->SetBranchAddress("genParPhi", &genParPhi, &b_genParPhi);
   fChain->SetBranchAddress("genParM", &genParM, &b_genParM);
   fChain->SetBranchAddress("genParQ", &genParQ, &b_genParQ);
   fChain->SetBranchAddress("genParId", &genParId, &b_genParId);
   fChain->SetBranchAddress("genParSt", &genParSt, &b_genParSt);
   fChain->SetBranchAddress("genMomParId", &genMomParId, &b_genMomParId);
   fChain->SetBranchAddress("genParIndex", &genParIndex, &b_genParIndex);
   fChain->SetBranchAddress("genNMo", &genNMo, &b_genNMo);
   fChain->SetBranchAddress("genNDa", &genNDa, &b_genNDa);
   fChain->SetBranchAddress("genMo1", &genMo1, &b_genMo1);
   fChain->SetBranchAddress("genMo2", &genMo2, &b_genMo2);
   fChain->SetBranchAddress("genDa1", &genDa1, &b_genDa1);
   fChain->SetBranchAddress("genDa2", &genDa2, &b_genDa2);
   fChain->SetBranchAddress("nGenJet", &nGenJet, &b_nGenJet);
   fChain->SetBranchAddress("genJetE", &genJetE, &b_genJetE);
   fChain->SetBranchAddress("genJetPt", &genJetPt, &b_genJetPt);
   fChain->SetBranchAddress("genJetEta", &genJetEta, &b_genJetEta);
   fChain->SetBranchAddress("genJetPhi", &genJetPhi, &b_genJetPhi);
   fChain->SetBranchAddress("genJetEM", &genJetEM, &b_genJetEM);
   fChain->SetBranchAddress("genJetHAD", &genJetHAD, &b_genJetHAD);
   fChain->SetBranchAddress("nMu", &nMu, &b_nMu);
   fChain->SetBranchAddress("muType", &muType, &b_muType);
   fChain->SetBranchAddress("muPt", &muPt, &b_muPt);
   fChain->SetBranchAddress("muEta", &muEta, &b_muEta);
   fChain->SetBranchAddress("muPhi", &muPhi, &b_muPhi);
   fChain->SetBranchAddress("muM", &muM, &b_muM);
   fChain->SetBranchAddress("muTrkIso", &muTrkIso, &b_muTrkIso);
   fChain->SetBranchAddress("muCorrTrkIso", &muCorrTrkIso, &b_muCorrTrkIso);
   fChain->SetBranchAddress("muHcalIso", &muHcalIso, &b_muHcalIso);
   fChain->SetBranchAddress("muEcalIso", &muEcalIso, &b_muEcalIso);
   fChain->SetBranchAddress("muCharge", &muCharge, &b_muCharge);
   fChain->SetBranchAddress("muChHadIso", &muChHadIso, &b_muChHadIso);
   fChain->SetBranchAddress("muNeHadIso", &muNeHadIso, &b_muNeHadIso);
   fChain->SetBranchAddress("muGamIso", &muGamIso, &b_muGamIso);
   fChain->SetBranchAddress("muPUPt", &muPUPt, &b_muPUPt);
   fChain->SetBranchAddress("muCorrPfIso", &muCorrPfIso, &b_muCorrPfIso);
   fChain->SetBranchAddress("isGlobalMuon", &isGlobalMuon, &b_isGlobalMuon);
   fChain->SetBranchAddress("isTrackerMuon", &isTrackerMuon, &b_isTrackerMuon);
   fChain->SetBranchAddress("muPtErrx", &muPtErrx, &b_muPtErrx);
   fChain->SetBranchAddress("mudxy", &mudxy, &b_mudxy);
   fChain->SetBranchAddress("mudz", &mudz, &b_mudz);
   fChain->SetBranchAddress("muTrkLayers", &muTrkLayers, &b_muTrkLayers);
   fChain->SetBranchAddress("muPixelHits", &muPixelHits, &b_muPixelHits);
   fChain->SetBranchAddress("muHits", &muHits, &b_muHits);
   fChain->SetBranchAddress("muMatches", &muMatches, &b_muMatches);
   fChain->SetBranchAddress("muITrkID", &muITrkID, &b_muITrkID);
   fChain->SetBranchAddress("muSegID", &muSegID, &b_muSegID);
   fChain->SetBranchAddress("muNSegs", &muNSegs, &b_muNSegs);
   fChain->SetBranchAddress("muGood", &muGood, &b_muGood);
   fChain->SetBranchAddress("nEle", &nEle, &b_nEle);
   fChain->SetBranchAddress("eleRho", &eleRho, &b_eleRho);
   fChain->SetBranchAddress("eleEt", &eleEt, &b_eleEt);
   fChain->SetBranchAddress("eleEnergy", &eleEnergy, &b_eleEnergy);
   fChain->SetBranchAddress("elePt", &elePt, &b_elePt);
   fChain->SetBranchAddress("eleEta", &eleEta, &b_eleEta);
   fChain->SetBranchAddress("elePhi", &elePhi, &b_elePhi);
   fChain->SetBranchAddress("eleM", &eleM, &b_eleM);
   fChain->SetBranchAddress("eleCharge", &eleCharge, &b_eleCharge);
   fChain->SetBranchAddress("eleScEta", &eleScEta, &b_eleScEta);
   fChain->SetBranchAddress("eleSigIhIh", &eleSigIhIh, &b_eleSigIhIh);
   fChain->SetBranchAddress("eleDelEtaIn", &eleDelEtaIn, &b_eleDelEtaIn);
   fChain->SetBranchAddress("eleDelPhiIn", &eleDelPhiIn, &b_eleDelPhiIn);
   fChain->SetBranchAddress("eleHoE", &eleHoE, &b_eleHoE);
   fChain->SetBranchAddress("eleTrkIso", &eleTrkIso, &b_eleTrkIso);
   fChain->SetBranchAddress("eleHcalIso", &eleHcalIso, &b_eleHcalIso);
   fChain->SetBranchAddress("eleEcalIso", &eleEcalIso, &b_eleEcalIso);
   fChain->SetBranchAddress("eleEoverP", &eleEoverP, &b_eleEoverP);
   fChain->SetBranchAddress("eleDxy", &eleDxy, &b_eleDxy);
   fChain->SetBranchAddress("eleDz", &eleDz, &b_eleDz);
   fChain->SetBranchAddress("eleChHadIso", &eleChHadIso, &b_eleChHadIso);
   fChain->SetBranchAddress("eleNeHadIso", &eleNeHadIso, &b_eleNeHadIso);
   fChain->SetBranchAddress("eleGamIso", &eleGamIso, &b_eleGamIso);
   fChain->SetBranchAddress("elePUPt", &elePUPt, &b_elePUPt);
   fChain->SetBranchAddress("eleCorrPfIso", &eleCorrPfIso, &b_eleCorrPfIso);
   fChain->SetBranchAddress("eleInBarrel", &eleInBarrel, &b_eleInBarrel);
   fChain->SetBranchAddress("eleInEndcap", &eleInEndcap, &b_eleInEndcap);
   fChain->SetBranchAddress("elePassConv", &elePassConv, &b_elePassConv);
   fChain->SetBranchAddress("pfMetCorrPt", &pfMetCorrPt, &b_pfMetCorrPt);
   fChain->SetBranchAddress("pfMetCorrPhi", &pfMetCorrPhi, &b_pfMetCorrPhi);
   fChain->SetBranchAddress("pfMetCorrSumEt", &pfMetCorrSumEt, &b_pfMetCorrSumEt);
   fChain->SetBranchAddress("pfMetCorrSig", &pfMetCorrSig, &b_pfMetCorrSig);
   fChain->SetBranchAddress("pfMetRawPt", &pfMetRawPt, &b_pfMetRawPt);
   fChain->SetBranchAddress("pfMetRawPhi", &pfMetRawPhi, &b_pfMetRawPhi);
   fChain->SetBranchAddress("pfMetRawSumEt", &pfMetRawSumEt, &b_pfMetRawSumEt);
   fChain->SetBranchAddress("pfMetRawCov00", &pfMetRawCov00, &b_pfMetRawCov00);
   fChain->SetBranchAddress("pfMetRawCov01", &pfMetRawCov01, &b_pfMetRawCov01);
   fChain->SetBranchAddress("pfMetRawCov10", &pfMetRawCov10, &b_pfMetRawCov10);
   fChain->SetBranchAddress("pfMetRawCov11", &pfMetRawCov11, &b_pfMetRawCov11);
   fChain->SetBranchAddress("pfmvaMetPt_", &pfmvaMetPt_, &b_pfmvaMetPt_);
   fChain->SetBranchAddress("pfmvaMetPhi_", &pfmvaMetPhi_, &b_pfmvaMetPhi_);
   fChain->SetBranchAddress("pfmvaMetSumEt_", &pfmvaMetSumEt_, &b_pfmvaMetSumEt_);
   fChain->SetBranchAddress("pfmvaMetSig_", &pfmvaMetSig_, &b_pfmvaMetSig_);
   fChain->SetBranchAddress("CA8nJet", &CA8nJet, &b_CA8nJet);
   fChain->SetBranchAddress("CA8jetPt", &CA8jetPt, &b_CA8jetPt);
   fChain->SetBranchAddress("CA8jetEta", &CA8jetEta, &b_CA8jetEta);
   fChain->SetBranchAddress("CA8jetPhi", &CA8jetPhi, &b_CA8jetPhi);
   fChain->SetBranchAddress("CA8jetMass", &CA8jetMass, &b_CA8jetMass);
   fChain->SetBranchAddress("CA8jetEn", &CA8jetEn, &b_CA8jetEn);
   fChain->SetBranchAddress("CA8genjetPx", &CA8genjetPx, &b_CA8genjetPx);
   fChain->SetBranchAddress("CA8genjetPy", &CA8genjetPy, &b_CA8genjetPy);
   fChain->SetBranchAddress("CA8genjetPz", &CA8genjetPz, &b_CA8genjetPz);
   fChain->SetBranchAddress("CA8genjetEn", &CA8genjetEn, &b_CA8genjetEn);
   fChain->SetBranchAddress("CA8genjetEM", &CA8genjetEM, &b_CA8genjetEM);
   fChain->SetBranchAddress("CA8genjetHAD", &CA8genjetHAD, &b_CA8genjetHAD);
   fChain->SetBranchAddress("CA8genjetINV", &CA8genjetINV, &b_CA8genjetINV);
   fChain->SetBranchAddress("CA8genjetAUX", &CA8genjetAUX, &b_CA8genjetAUX);
   fChain->SetBranchAddress("CA8matchedDR", &CA8matchedDR, &b_CA8matchedDR);
   fChain->SetBranchAddress("CA8jetCorrUncUp", &CA8jetCorrUncUp, &b_CA8jetCorrUncUp);
   fChain->SetBranchAddress("CA8jetCorrUncDown", &CA8jetCorrUncDown, &b_CA8jetCorrUncDown);
   fChain->SetBranchAddress("CA8jetCharge", &CA8jetCharge, &b_CA8jetCharge);
   fChain->SetBranchAddress("CA8jetPartonFlavor", &CA8jetPartonFlavor, &b_CA8jetPartonFlavor);
   fChain->SetBranchAddress("CA8jetPassID", &CA8jetPassID, &b_CA8jetPassID);
   fChain->SetBranchAddress("CA8jetSSV", &CA8jetSSV, &b_CA8jetSSV);
   fChain->SetBranchAddress("CA8jetSSVHE", &CA8jetSSVHE, &b_CA8jetSSVHE);
   fChain->SetBranchAddress("CA8jetCSV", &CA8jetCSV, &b_CA8jetCSV);
   fChain->SetBranchAddress("CA8jetCISVV2", &CA8jetCISVV2, &b_CA8jetCISVV2);
   fChain->SetBranchAddress("CA8jetTCHP", &CA8jetTCHP, &b_CA8jetTCHP);
   fChain->SetBranchAddress("CA8jetTCHE", &CA8jetTCHE, &b_CA8jetTCHE);
   fChain->SetBranchAddress("CA8jetJP", &CA8jetJP, &b_CA8jetJP);
   fChain->SetBranchAddress("CA8jetJBP", &CA8jetJBP, &b_CA8jetJBP);
   fChain->SetBranchAddress("CA8jetTau1", &CA8jetTau1, &b_CA8jetTau1);
   fChain->SetBranchAddress("CA8jetTau2", &CA8jetTau2, &b_CA8jetTau2);
   fChain->SetBranchAddress("CA8jetTau3", &CA8jetTau3, &b_CA8jetTau3);
   fChain->SetBranchAddress("CA8jetTau4", &CA8jetTau4, &b_CA8jetTau4);
   fChain->SetBranchAddress("CA8jetMuEF", &CA8jetMuEF, &b_CA8jetMuEF);
   fChain->SetBranchAddress("CA8jetPhoEF", &CA8jetPhoEF, &b_CA8jetPhoEF);
   fChain->SetBranchAddress("CA8jetCEmEF", &CA8jetCEmEF, &b_CA8jetCEmEF);
   fChain->SetBranchAddress("CA8jetCHadEF", &CA8jetCHadEF, &b_CA8jetCHadEF);
   fChain->SetBranchAddress("CA8jetNEmEF", &CA8jetNEmEF, &b_CA8jetNEmEF);
   fChain->SetBranchAddress("CA8jetNHadEF", &CA8jetNHadEF, &b_CA8jetNHadEF);
   fChain->SetBranchAddress("CA8jetCMulti", &CA8jetCMulti, &b_CA8jetCMulti);
   fChain->SetBranchAddress("CA8jetPrunedPt", &CA8jetPrunedPt, &b_CA8jetPrunedPt);
   fChain->SetBranchAddress("CA8jetPrunedEta", &CA8jetPrunedEta, &b_CA8jetPrunedEta);
   fChain->SetBranchAddress("CA8jetPrunedPhi", &CA8jetPrunedPhi, &b_CA8jetPrunedPhi);
   fChain->SetBranchAddress("CA8jetPrunedMass", &CA8jetPrunedMass, &b_CA8jetPrunedMass);
   fChain->SetBranchAddress("CA8jetPrunedEn", &CA8jetPrunedEn, &b_CA8jetPrunedEn);
   fChain->SetBranchAddress("CA8jetPrunedCorrUncUp", &CA8jetPrunedCorrUncUp, &b_CA8jetPrunedCorrUncUp);
   fChain->SetBranchAddress("CA8jetPrunedCorrUncDown", &CA8jetPrunedCorrUncDown, &b_CA8jetPrunedCorrUncDown);
   fChain->SetBranchAddress("CA8jetPrunedCharge", &CA8jetPrunedCharge, &b_CA8jetPrunedCharge);
   fChain->SetBranchAddress("CA8jetPrunedPartonFlavor", &CA8jetPrunedPartonFlavor, &b_CA8jetPrunedPartonFlavor);
   fChain->SetBranchAddress("CA8jetPrunedSSV", &CA8jetPrunedSSV, &b_CA8jetPrunedSSV);
   fChain->SetBranchAddress("CA8jetPrunedCSV", &CA8jetPrunedCSV, &b_CA8jetPrunedCSV);
   fChain->SetBranchAddress("CA8jetPrunedTCHP", &CA8jetPrunedTCHP, &b_CA8jetPrunedTCHP);
   fChain->SetBranchAddress("CA8jetPrunedTCHE", &CA8jetPrunedTCHE, &b_CA8jetPrunedTCHE);
   fChain->SetBranchAddress("CA8jetPrunedJP", &CA8jetPrunedJP, &b_CA8jetPrunedJP);
   fChain->SetBranchAddress("CA8jetPrunedJBP", &CA8jetPrunedJBP, &b_CA8jetPrunedJBP);
   fChain->SetBranchAddress("CA8jetSDmass", &CA8jetSDmass, &b_CA8jetSDmass);
   fChain->SetBranchAddress("CA8jetTRmass", &CA8jetTRmass, &b_CA8jetTRmass);
   fChain->SetBranchAddress("CA8jetPRmass", &CA8jetPRmass, &b_CA8jetPRmass);
   fChain->SetBranchAddress("CA8jetFimass", &CA8jetFimass, &b_CA8jetFimass);
   fChain->SetBranchAddress("CA8nSubSDJet", &CA8nSubSDJet, &b_CA8nSubSDJet);
   fChain->SetBranchAddress("subjetSDPt", &subjetSDPt, &b_subjetSDPt);
   fChain->SetBranchAddress("subjetSDEta", &subjetSDEta, &b_subjetSDEta);
   fChain->SetBranchAddress("subjetSDPhi", &subjetSDPhi, &b_subjetSDPhi);
   fChain->SetBranchAddress("subjetSDMass", &subjetSDMass, &b_subjetSDMass);
   fChain->SetBranchAddress("subjetSDCSV", &subjetSDCSV, &b_subjetSDCSV);
   fChain->SetBranchAddress("AK5nJet", &AK5nJet, &b_AK5nJet);
   fChain->SetBranchAddress("AK5jetPt", &AK5jetPt, &b_AK5jetPt);
   fChain->SetBranchAddress("AK5jetEta", &AK5jetEta, &b_AK5jetEta);
   fChain->SetBranchAddress("AK5jetPhi", &AK5jetPhi, &b_AK5jetPhi);
   fChain->SetBranchAddress("AK5jetMass", &AK5jetMass, &b_AK5jetMass);
   fChain->SetBranchAddress("AK5jetEn", &AK5jetEn, &b_AK5jetEn);
   fChain->SetBranchAddress("AK5genjetPx", &AK5genjetPx, &b_AK5genjetPx);
   fChain->SetBranchAddress("AK5genjetPy", &AK5genjetPy, &b_AK5genjetPy);
   fChain->SetBranchAddress("AK5genjetPz", &AK5genjetPz, &b_AK5genjetPz);
   fChain->SetBranchAddress("AK5genjetEn", &AK5genjetEn, &b_AK5genjetEn);
   fChain->SetBranchAddress("AK5genjetEM", &AK5genjetEM, &b_AK5genjetEM);
   fChain->SetBranchAddress("AK5genjetHAD", &AK5genjetHAD, &b_AK5genjetHAD);
   fChain->SetBranchAddress("AK5genjetINV", &AK5genjetINV, &b_AK5genjetINV);
   fChain->SetBranchAddress("AK5genjetAUX", &AK5genjetAUX, &b_AK5genjetAUX);
   fChain->SetBranchAddress("AK5matchedDR", &AK5matchedDR, &b_AK5matchedDR);
   fChain->SetBranchAddress("AK5jetCorrUncUp", &AK5jetCorrUncUp, &b_AK5jetCorrUncUp);
   fChain->SetBranchAddress("AK5jetCorrUncDown", &AK5jetCorrUncDown, &b_AK5jetCorrUncDown);
   fChain->SetBranchAddress("AK5jetCharge", &AK5jetCharge, &b_AK5jetCharge);
   fChain->SetBranchAddress("AK5jetPartonFlavor", &AK5jetPartonFlavor, &b_AK5jetPartonFlavor);
   fChain->SetBranchAddress("AK5jetPassID", &AK5jetPassID, &b_AK5jetPassID);
   fChain->SetBranchAddress("AK5jetSSV", &AK5jetSSV, &b_AK5jetSSV);
   fChain->SetBranchAddress("AK5jetSSVHE", &AK5jetSSVHE, &b_AK5jetSSVHE);
   fChain->SetBranchAddress("AK5jetCSV", &AK5jetCSV, &b_AK5jetCSV);
   fChain->SetBranchAddress("AK5jetCISVV2", &AK5jetCISVV2, &b_AK5jetCISVV2);
   fChain->SetBranchAddress("AK5jetTCHP", &AK5jetTCHP, &b_AK5jetTCHP);
   fChain->SetBranchAddress("AK5jetTCHE", &AK5jetTCHE, &b_AK5jetTCHE);
   fChain->SetBranchAddress("AK5jetJP", &AK5jetJP, &b_AK5jetJP);
   fChain->SetBranchAddress("AK5jetJBP", &AK5jetJBP, &b_AK5jetJBP);
   fChain->SetBranchAddress("AK5jetTau1", &AK5jetTau1, &b_AK5jetTau1);
   fChain->SetBranchAddress("AK5jetTau2", &AK5jetTau2, &b_AK5jetTau2);
   fChain->SetBranchAddress("AK5jetTau3", &AK5jetTau3, &b_AK5jetTau3);
   fChain->SetBranchAddress("AK5jetTau4", &AK5jetTau4, &b_AK5jetTau4);
   fChain->SetBranchAddress("AK5jetMuEF", &AK5jetMuEF, &b_AK5jetMuEF);
   fChain->SetBranchAddress("AK5jetPhoEF", &AK5jetPhoEF, &b_AK5jetPhoEF);
   fChain->SetBranchAddress("AK5jetCEmEF", &AK5jetCEmEF, &b_AK5jetCEmEF);
   fChain->SetBranchAddress("AK5jetCHadEF", &AK5jetCHadEF, &b_AK5jetCHadEF);
   fChain->SetBranchAddress("AK5jetNEmEF", &AK5jetNEmEF, &b_AK5jetNEmEF);
   fChain->SetBranchAddress("AK5jetNHadEF", &AK5jetNHadEF, &b_AK5jetNHadEF);
   fChain->SetBranchAddress("AK5jetCMulti", &AK5jetCMulti, &b_AK5jetCMulti);
   fChain->SetBranchAddress("genjetngenMuons", &genjetngenMuons, &b_genjetngenMuons);
   fChain->SetBranchAddress("genjetgenjet_n", &genjetgenjet_n, &b_genjetgenjet_n);
   fChain->SetBranchAddress("GenJets_4Momentum", &GenJets_4Momentum, &b_GenJets_4Momentum);
   fChain->SetBranchAddress("hlt_nTrigs", &hlt_nTrigs, &b_hlt_nTrigs);
   fChain->SetBranchAddress("hlt_trigResult", &hlt_trigResult, &b_hlt_trigResult);
   fChain->SetBranchAddress("trigName", &trigName, &b_trigName);
   fChain->SetBranchAddress("HPSTau_n", &HPSTau_n, &b_HPSTau_n);
   fChain->SetBranchAddress("taupt", &taupt, &b_taupt);
   fChain->SetBranchAddress("HPSTau_4Momentum", &HPSTau_4Momentum, &b_HPSTau_4Momentum);
   fChain->SetBranchAddress("HPSTau_Vposition", &HPSTau_Vposition, &b_HPSTau_Vposition);
   fChain->SetBranchAddress("HPSTau_leadPFChargedHadrCand", &HPSTau_leadPFChargedHadrCand, &b_HPSTau_leadPFChargedHadrCand);
   fChain->SetBranchAddress("HPSTau_leadPFChargedHadrCand_trackRef", &HPSTau_leadPFChargedHadrCand_trackRef, &b_HPSTau_leadPFChargedHadrCand_trackRef);
   fChain->SetBranchAddress("disc_againstElectronLoose", &disc_againstElectronLoose, &b_disc_againstElectronLoose);
   fChain->SetBranchAddress("disc_againstElectronMedium", &disc_againstElectronMedium, &b_disc_againstElectronMedium);
   fChain->SetBranchAddress("disc_againstElectronTight", &disc_againstElectronTight, &b_disc_againstElectronTight);
   fChain->SetBranchAddress("disc_againstElectronLooseMVA5", &disc_againstElectronLooseMVA5, &b_disc_againstElectronLooseMVA5);
   fChain->SetBranchAddress("disc_againstElectronMediumMVA5", &disc_againstElectronMediumMVA5, &b_disc_againstElectronMediumMVA5);
   fChain->SetBranchAddress("disc_againstElectronTightMVA5", &disc_againstElectronTightMVA5, &b_disc_againstElectronTightMVA5);
   fChain->SetBranchAddress("disc_againstElectronVLooseMVA5", &disc_againstElectronVLooseMVA5, &b_disc_againstElectronVLooseMVA5);
   fChain->SetBranchAddress("disc_againstElectronVTightMVA5", &disc_againstElectronVTightMVA5, &b_disc_againstElectronVTightMVA5);
   fChain->SetBranchAddress("disc_againstMuonLoose", &disc_againstMuonLoose, &b_disc_againstMuonLoose);
   fChain->SetBranchAddress("disc_againstMuonMedium", &disc_againstMuonMedium, &b_disc_againstMuonMedium);
   fChain->SetBranchAddress("disc_againstMuonTight", &disc_againstMuonTight, &b_disc_againstMuonTight);
   fChain->SetBranchAddress("disc_againstMuonLoose2", &disc_againstMuonLoose2, &b_disc_againstMuonLoose2);
   fChain->SetBranchAddress("disc_againstMuonMedium2", &disc_againstMuonMedium2, &b_disc_againstMuonMedium2);
   fChain->SetBranchAddress("disc_againstMuonTight2", &disc_againstMuonTight2, &b_disc_againstMuonTight2);
   fChain->SetBranchAddress("disc_againstMuonLooseMVA", &disc_againstMuonLooseMVA, &b_disc_againstMuonLooseMVA);
   fChain->SetBranchAddress("disc_againstMuonMediumMVA", &disc_againstMuonMediumMVA, &b_disc_againstMuonMediumMVA);
   fChain->SetBranchAddress("disc_againstMuonTightMVA", &disc_againstMuonTightMVA, &b_disc_againstMuonTightMVA);
   fChain->SetBranchAddress("disc_againstMuonLoose3", &disc_againstMuonLoose3, &b_disc_againstMuonLoose3);
   fChain->SetBranchAddress("disc_againstMuonTight3", &disc_againstMuonTight3, &b_disc_againstMuonTight3);
   fChain->SetBranchAddress("disc_byVLooseCombinedIsolationDeltaBetaCorr", &disc_byVLooseCombinedIsolationDeltaBetaCorr, &b_disc_byVLooseCombinedIsolationDeltaBetaCorr);
   fChain->SetBranchAddress("disc_byLooseCombinedIsolationDeltaBetaCorr", &disc_byLooseCombinedIsolationDeltaBetaCorr, &b_disc_byLooseCombinedIsolationDeltaBetaCorr);
   fChain->SetBranchAddress("disc_byMediumCombinedIsolationDeltaBetaCorr", &disc_byMediumCombinedIsolationDeltaBetaCorr, &b_disc_byMediumCombinedIsolationDeltaBetaCorr);
   fChain->SetBranchAddress("disc_byTightCombinedIsolationDeltaBetaCorr", &disc_byTightCombinedIsolationDeltaBetaCorr, &b_disc_byTightCombinedIsolationDeltaBetaCorr);
   fChain->SetBranchAddress("disc_byLooseIsolation", &disc_byLooseIsolation, &b_disc_byLooseIsolation);
   fChain->SetBranchAddress("disc_byVLooseIsolationMVA3newDMwLT", &disc_byVLooseIsolationMVA3newDMwLT, &b_disc_byVLooseIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("disc_byLooseIsolationMVA3newDMwLT", &disc_byLooseIsolationMVA3newDMwLT, &b_disc_byLooseIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("disc_byMediumIsolationMVA3newDMwLT", &disc_byMediumIsolationMVA3newDMwLT, &b_disc_byMediumIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("disc_byTightIsolationMVA3newDMwLT", &disc_byTightIsolationMVA3newDMwLT, &b_disc_byTightIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("disc_byVTightIsolationMVA3newDMwLT", &disc_byVTightIsolationMVA3newDMwLT, &b_disc_byVTightIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("disc_byVVTightIsolationMVA3newDMwLT", &disc_byVVTightIsolationMVA3newDMwLT, &b_disc_byVVTightIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("disc_byVLooseIsolationMVA3newDMwoLT", &disc_byVLooseIsolationMVA3newDMwoLT, &b_disc_byVLooseIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("disc_byLooseIsolationMVA3newDMwoLT", &disc_byLooseIsolationMVA3newDMwoLT, &b_disc_byLooseIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("disc_byMediumIsolationMVA3newDMwoLT", &disc_byMediumIsolationMVA3newDMwoLT, &b_disc_byMediumIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("disc_byTightIsolationMVA3newDMwoLT", &disc_byTightIsolationMVA3newDMwoLT, &b_disc_byTightIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("disc_byVTightIsolationMVA3newDMwoLT", &disc_byVTightIsolationMVA3newDMwoLT, &b_disc_byVTightIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("disc_byVVTightIsolationMVA3newDMwoLT", &disc_byVVTightIsolationMVA3newDMwoLT, &b_disc_byVVTightIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("disc_byVLooseIsolationMVA3oldDMwLT", &disc_byVLooseIsolationMVA3oldDMwLT, &b_disc_byVLooseIsolationMVA3oldDMwLT);
   fChain->SetBranchAddress("disc_byLooseIsolationMVA3oldDMwLT", &disc_byLooseIsolationMVA3oldDMwLT, &b_disc_byLooseIsolationMVA3oldDMwLT);
   fChain->SetBranchAddress("disc_byMediumIsolationMVA3oldDMwLT", &disc_byMediumIsolationMVA3oldDMwLT, &b_disc_byMediumIsolationMVA3oldDMwLT);
   fChain->SetBranchAddress("disc_byTightIsolationMVA3oldDMwLT", &disc_byTightIsolationMVA3oldDMwLT, &b_disc_byTightIsolationMVA3oldDMwLT);
   fChain->SetBranchAddress("disc_byVTightIsolationMVA3oldDMwLT", &disc_byVTightIsolationMVA3oldDMwLT, &b_disc_byVTightIsolationMVA3oldDMwLT);
   fChain->SetBranchAddress("disc_byVVTightIsolationMVA3oldDMwLT", &disc_byVVTightIsolationMVA3oldDMwLT, &b_disc_byVVTightIsolationMVA3oldDMwLT);
   fChain->SetBranchAddress("disc_byVLooseIsolationMVA3oldDMwoLT", &disc_byVLooseIsolationMVA3oldDMwoLT, &b_disc_byVLooseIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("disc_byLooseIsolationMVA3oldDMwoLT", &disc_byLooseIsolationMVA3oldDMwoLT, &b_disc_byLooseIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("disc_byMediumIsolationMVA3oldDMwoLT", &disc_byMediumIsolationMVA3oldDMwoLT, &b_disc_byMediumIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("disc_byTightIsolationMVA3oldDMwoLT", &disc_byTightIsolationMVA3oldDMwoLT, &b_disc_byTightIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("disc_byVTightIsolationMVA3oldDMwoLT", &disc_byVTightIsolationMVA3oldDMwoLT, &b_disc_byVTightIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("disc_byVVTightIsolationMVA3oldDMwoLT", &disc_byVVTightIsolationMVA3oldDMwoLT, &b_disc_byVVTightIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("disc_byLooseCombinedIsolationDeltaBetaCorr3Hits", &disc_byLooseCombinedIsolationDeltaBetaCorr3Hits, &b_disc_byLooseCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("disc_byMediumCombinedIsolationDeltaBetaCorr3Hits", &disc_byMediumCombinedIsolationDeltaBetaCorr3Hits, &b_disc_byMediumCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("disc_byTightCombinedIsolationDeltaBetaCorr3Hits", &disc_byTightCombinedIsolationDeltaBetaCorr3Hits, &b_disc_byTightCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("disc_decayModeFinding", &disc_decayModeFinding, &b_disc_decayModeFinding);
   fChain->SetBranchAddress("disc_decayModeFindingNewDMs", &disc_decayModeFindingNewDMs, &b_disc_decayModeFindingNewDMs);
   fChain->SetBranchAddress("disc_chargedIsoPtSum", &disc_chargedIsoPtSum, &b_disc_chargedIsoPtSum);
   fChain->SetBranchAddress("disc_neutralIsoPtSum", &disc_neutralIsoPtSum, &b_disc_neutralIsoPtSum);
   fChain->SetBranchAddress("disc_puCorrPtSum", &disc_puCorrPtSum, &b_disc_puCorrPtSum);
   fChain->SetBranchAddress("HPSTau_NewVz", &HPSTau_NewVz, &b_HPSTau_NewVz);
   fChain->SetBranchAddress("HPSTau_charge", &HPSTau_charge, &b_HPSTau_charge);
   Notify();
}

Bool_t TTbarBkg::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void TTbarBkg::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t TTbarBkg::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef TTbarBkg_cxx
