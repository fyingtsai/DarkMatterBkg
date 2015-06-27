//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Jun 27 11:57:28 2015 by ROOT version 5.34/30
// from TTree treeMaker/tree
// found on file: NCUGlobalTuples_52.root
//////////////////////////////////////////////////////////

#ifndef bkg2_TreeMaker_h
#define bkg2_TreeMaker_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <vector>
#include <TClonesArray.h>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxmuInnerdxy = 1;
   const Int_t kMaxmuInnerdz = 1;
   const Int_t kMaxmuTrkQuality = 1;
   const Int_t kMaxMuInnervalidFraction = 1;
   const Int_t kMaxpfmvaMetPt = 1;
   const Int_t kMaxpfmvaMetPhi = 1;
   const Int_t kMaxpfmvaMetSumEt = 1;
   const Int_t kMaxpfmvaMetSig = 1;

class bkg2_TreeMaker {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
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
   vector<float>   *muCharge;
   vector<int>     *isGlobalMuon;
   vector<int>     *isTrackerMuon;
   vector<int>     *isPFMuon;
   vector<float>   *muTrkPt;
   vector<float>   *muTrkPtErr;
   vector<float>   *mudxy;
   vector<float>   *mudz;
   vector<float>   *musegmentCompatibility;
   vector<float>   *muchi2LocalPosition;
   vector<float>   *mutrkKink;
   vector<float>   *muInnerdxy_;
   vector<float>   *muInnerdz_;
   vector<int>     *muTrkLayers;
   vector<int>     *muPixelLayers;
   vector<int>     *muPixelHits;
   vector<float>   *muTrkQuality_;
   vector<int>     *muHits;
   vector<float>   *muChi2NDF;
   vector<float>   *MuInnervalidFraction_;
   vector<int>     *muMatches;
   vector<int>     *muITrkID;
   vector<int>     *muSegID;
   vector<int>     *muNSegs;
   vector<int>     *muGood;
   vector<int>     *patMuonIsGood;
   vector<float>   *muTrkIso;
   vector<float>   *muHcalIso;
   vector<float>   *muEcalIso;
   vector<float>   *muChHadIso;
   vector<float>   *muNeHadIso;
   vector<float>   *muGamIso;
   vector<float>   *muPUPt;
   Int_t           nEle;
   vector<bool>    *isPassVeto;
   vector<bool>    *isPassLoose;
   vector<bool>    *isPassMedium;
   vector<bool>    *isPassTight;
   vector<bool>    *isPassHEEP;
   TClonesArray    *patElecP4;
   Float_t         eleRho;
   vector<float>   *eleEffArea;
   vector<float>   *eleCharge;
   vector<float>   *eleChargeConsistent;
   vector<float>   *eleR9;
   vector<float>   *eleHoverE;
   vector<float>   *eleD0;
   vector<float>   *eleDz;
   vector<float>   *eleScEn;
   vector<float>   *eleScPreEn;
   vector<float>   *eleScEta;
   vector<float>   *eleScPhi;
   vector<float>   *eleScRawEn;
   vector<float>   *eleScEtaWidth;
   vector<float>   *eleScPhiWidth;
   vector<float>   *eleEoverP;
   vector<float>   *eleBrem;
   vector<float>   *eledEtaAtVtx;
   vector<float>   *eledPhiAtVtx;
   vector<float>   *eleSigmaIEtaIEta;
   vector<float>   *eleSigmaIEtaIPhi;
   vector<float>   *eleSigmaIPhiIPhi;
   vector<float>   *eleConvVeto;
   vector<float>   *eleMissHits;
   vector<float>   *eleEoverPInv;
   vector<float>   *eleEtaseedAtVtx;
   vector<float>   *eleE1x5;
   vector<float>   *eleE2x5;
   vector<float>   *eleE5x5;
   vector<float>   *eleChHadIso;
   vector<float>   *eleNeHadIso;
   vector<float>   *eleGamIso;
   vector<float>   *elePUPt;
   vector<float>   *elecaloEnergy;
   vector<float>   *eleSigmaIEtaIEtaFull5x5;
   vector<float>   *eleE1x5Full5x5;
   vector<float>   *eleE2x5Full5x5;
   vector<float>   *eleE5x5Full5x5;
   vector<float>   *eleR9Full5x5;
   vector<float>   *eleEcalDrivenSeed;
   vector<float>   *eleDr03EcalRecHitSumEt;
   vector<float>   *eleDr03HcalDepth1TowerSumEt;
   vector<float>   *eleDr03HcalDepth2TowerSumEt;
   vector<float>   *eleDr03HcalTowerSumEt;
   vector<float>   *eleDr03TkSumPt;
   vector<float>   *eleTrkdztrackref;
   vector<float>   *eleTrkdxytrackref;
   vector<float>   *eleInBarrel;
   vector<float>   *eleInEndcap;
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
   Int_t           FATnJet;
   vector<float>   *FATjetPt;
   vector<float>   *FATjetEta;
   vector<float>   *FATjetPhi;
   vector<float>   *FATjetMass;
   vector<float>   *FATjetEn;
   vector<float>   *FATgenjetPx;
   vector<float>   *FATgenjetPy;
   vector<float>   *FATgenjetPz;
   vector<float>   *FATgenjetEn;
   vector<float>   *FATgenjetEM;
   vector<float>   *FATgenjetHAD;
   vector<float>   *FATgenjetINV;
   vector<float>   *FATgenjetAUX;
   vector<float>   *FATmatchedDR;
   vector<float>   *FATjetCorrUncUp;
   vector<float>   *FATjetCorrUncDown;
   vector<int>     *FATjetCharge;
   vector<int>     *FATjetPartonFlavor;
   vector<int>     *FATjetPassID;
   vector<int>     *FATjet_nSV;
   vector<vector<float> > *FATjet_SVMass;
   vector<vector<float> > *FATjet_SVEnergyRatio;
   vector<float>   *FATjetSSV;
   vector<float>   *FATjetSSVHE;
   vector<float>   *FATjetCSV;
   vector<float>   *FATjetCISVV2;
   vector<float>   *FATjetTCHP;
   vector<float>   *FATjetTCHE;
   vector<float>   *FATjetJP;
   vector<float>   *FATjetJBP;
   vector<float>   *FATjetTau1;
   vector<float>   *FATjetTau2;
   vector<float>   *FATjetTau3;
   vector<float>   *FATjetTau4;
   vector<float>   *FATjetMuEF;
   vector<float>   *FATjetPhoEF;
   vector<float>   *FATjetCEmEF;
   vector<float>   *FATjetCHadEF;
   vector<float>   *FATjetNEmEF;
   vector<float>   *FATjetNHadEF;
   vector<float>   *FATjetCMulti;
   vector<float>   *FATjetPrunedPt;
   vector<float>   *FATjetPrunedEta;
   vector<float>   *FATjetPrunedPhi;
   vector<float>   *FATjetPrunedMass;
   vector<float>   *FATjetPrunedEn;
   vector<float>   *FATjetPrunedCorrUncUp;
   vector<float>   *FATjetPrunedCorrUncDown;
   vector<int>     *FATjetPrunedCharge;
   vector<int>     *FATjetPrunedPartonFlavor;
   vector<float>   *FATjetPrunedSSV;
   vector<float>   *FATjetPrunedCSV;
   vector<float>   *FATjetPrunedTCHP;
   vector<float>   *FATjetPrunedTCHE;
   vector<float>   *FATjetPrunedJP;
   vector<float>   *FATjetPrunedJBP;
   vector<float>   *FATjetSDmass;
   vector<float>   *FATjetTRmass;
   vector<float>   *FATjetPRmass;
   vector<float>   *FATjetFimass;
   vector<float>   *FATjet_DoubleSV;
   vector<int>     *FATnSubSDJet;
   vector<vector<float> > *FATsubjetSDPt;
   vector<vector<float> > *FATsubjetSDEta;
   vector<vector<float> > *FATsubjetSDPhi;
   vector<vector<float> > *FATsubjetSDMass;
   vector<vector<float> > *FATsubjetSDCSV;
   Int_t           THINnJet;
   vector<float>   *THINjetPt;
   vector<float>   *THINjetEta;
   vector<float>   *THINjetPhi;
   vector<float>   *THINjetMass;
   vector<float>   *THINjetEn;
   vector<float>   *THINgenjetPx;
   vector<float>   *THINgenjetPy;
   vector<float>   *THINgenjetPz;
   vector<float>   *THINgenjetEn;
   vector<float>   *THINgenjetEM;
   vector<float>   *THINgenjetHAD;
   vector<float>   *THINgenjetINV;
   vector<float>   *THINgenjetAUX;
   vector<float>   *THINmatchedDR;
   vector<float>   *THINjetCorrUncUp;
   vector<float>   *THINjetCorrUncDown;
   vector<int>     *THINjetCharge;
   vector<int>     *THINjetPartonFlavor;
   vector<int>     *THINjetPassID;
   vector<int>     *THINjet_nSV;
   vector<vector<float> > *THINjet_SVMass;
   vector<vector<float> > *THINjet_SVEnergyRatio;
   vector<float>   *THINjetSSV;
   vector<float>   *THINjetSSVHE;
   vector<float>   *THINjetCSV;
   vector<float>   *THINjetCISVV2;
   vector<float>   *THINjetTCHP;
   vector<float>   *THINjetTCHE;
   vector<float>   *THINjetJP;
   vector<float>   *THINjetJBP;
   vector<float>   *THINjetTau1;
   vector<float>   *THINjetTau2;
   vector<float>   *THINjetTau3;
   vector<float>   *THINjetTau4;
   vector<float>   *THINjetMuEF;
   vector<float>   *THINjetPhoEF;
   vector<float>   *THINjetCEmEF;
   vector<float>   *THINjetCHadEF;
   vector<float>   *THINjetNEmEF;
   vector<float>   *THINjetNHadEF;
   vector<float>   *THINjetCMulti;
   Int_t           ADDnJet;
   vector<float>   *ADDjetPt;
   vector<float>   *ADDjetEta;
   vector<float>   *ADDjetPhi;
   vector<float>   *ADDjetMass;
   vector<float>   *ADDjetEn;
   vector<float>   *ADDgenjetPx;
   vector<float>   *ADDgenjetPy;
   vector<float>   *ADDgenjetPz;
   vector<float>   *ADDgenjetEn;
   vector<float>   *ADDgenjetEM;
   vector<float>   *ADDgenjetHAD;
   vector<float>   *ADDgenjetINV;
   vector<float>   *ADDgenjetAUX;
   vector<float>   *ADDmatchedDR;
   vector<float>   *ADDjetCorrUncUp;
   vector<float>   *ADDjetCorrUncDown;
   vector<int>     *ADDjetCharge;
   vector<int>     *ADDjetPartonFlavor;
   vector<int>     *ADDjetPassID;
   vector<int>     *ADDjet_nSV;
   vector<vector<float> > *ADDjet_SVMass;
   vector<vector<float> > *ADDjet_SVEnergyRatio;
   vector<float>   *ADDjetSSV;
   vector<float>   *ADDjetSSVHE;
   vector<float>   *ADDjetCSV;
   vector<float>   *ADDjetCISVV2;
   vector<float>   *ADDjetTCHP;
   vector<float>   *ADDjetTCHE;
   vector<float>   *ADDjetJP;
   vector<float>   *ADDjetJBP;
   vector<float>   *ADDjetTau1;
   vector<float>   *ADDjetTau2;
   vector<float>   *ADDjetTau3;
   vector<float>   *ADDjetTau4;
   vector<float>   *ADDjetMuEF;
   vector<float>   *ADDjetPhoEF;
   vector<float>   *ADDjetCEmEF;
   vector<float>   *ADDjetCHadEF;
   vector<float>   *ADDjetNEmEF;
   vector<float>   *ADDjetNHadEF;
   vector<float>   *ADDjetCMulti;
   vector<float>   *ADDjetPrunedPt;
   vector<float>   *ADDjetPrunedEta;
   vector<float>   *ADDjetPrunedPhi;
   vector<float>   *ADDjetPrunedMass;
   vector<float>   *ADDjetPrunedEn;
   vector<float>   *ADDjetPrunedCorrUncUp;
   vector<float>   *ADDjetPrunedCorrUncDown;
   vector<int>     *ADDjetPrunedCharge;
   vector<int>     *ADDjetPrunedPartonFlavor;
   vector<float>   *ADDjetPrunedSSV;
   vector<float>   *ADDjetPrunedCSV;
   vector<float>   *ADDjetPrunedTCHP;
   vector<float>   *ADDjetPrunedTCHE;
   vector<float>   *ADDjetPrunedJP;
   vector<float>   *ADDjetPrunedJBP;
   vector<float>   *ADDjetSDmass;
   vector<float>   *ADDjetTRmass;
   vector<float>   *ADDjetPRmass;
   vector<float>   *ADDjetFimass;
   vector<float>   *ADDjet_DoubleSV;
   vector<int>     *ADDnSubSDJet;
   vector<vector<float> > *ADDsubjetSDPt;
   vector<vector<float> > *ADDsubjetSDEta;
   vector<vector<float> > *ADDsubjetSDPhi;
   vector<vector<float> > *ADDsubjetSDMass;
   vector<vector<float> > *ADDsubjetSDCSV;
   Int_t           hlt_nTrigs;
   vector<int>     *hlt_trigResult;
   vector<string>  *trigName;

   // List of branches
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
   TBranch        *b_muCharge;   //!
   TBranch        *b_isGlobalMuon;   //!
   TBranch        *b_isTrackerMuon;   //!
   TBranch        *b_isPFMuon;   //!
   TBranch        *b_muTrkPt;   //!
   TBranch        *b_muTrkPtErr;   //!
   TBranch        *b_mudxy;   //!
   TBranch        *b_mudz;   //!
   TBranch        *b_musegmentCompatibility;   //!
   TBranch        *b_muchi2LocalPosition;   //!
   TBranch        *b_mutrkKink;   //!
   TBranch        *b_muInnerdxy_;   //!
   TBranch        *b_muInnerdz_;   //!
   TBranch        *b_muTrkLayers;   //!
   TBranch        *b_muPixelLayers;   //!
   TBranch        *b_muPixelHits;   //!
   TBranch        *b_muTrkQuality_;   //!
   TBranch        *b_muHits;   //!
   TBranch        *b_muChi2NDF;   //!
   TBranch        *b_MuInnervalidFraction_;   //!
   TBranch        *b_muMatches;   //!
   TBranch        *b_muITrkID;   //!
   TBranch        *b_muSegID;   //!
   TBranch        *b_muNSegs;   //!
   TBranch        *b_muGood;   //!
   TBranch        *b_patMuonIsGood;   //!
   TBranch        *b_muTrkIso;   //!
   TBranch        *b_muHcalIso;   //!
   TBranch        *b_muEcalIso;   //!
   TBranch        *b_muChHadIso;   //!
   TBranch        *b_muNeHadIso;   //!
   TBranch        *b_muGamIso;   //!
   TBranch        *b_muPUPt;   //!
   TBranch        *b_nEle;   //!
   TBranch        *b_isPassVeto;   //!
   TBranch        *b_isPassLoose;   //!
   TBranch        *b_isPassMedium;   //!
   TBranch        *b_isPassTight;   //!
   TBranch        *b_isPassHEEP;   //!
   TBranch        *b_patElecP4;   //!
   TBranch        *b_eleRho;   //!
   TBranch        *b_eleEffArea;   //!
   TBranch        *b_eleCharge;   //!
   TBranch        *b_eleChargeConsistent;   //!
   TBranch        *b_eleR9;   //!
   TBranch        *b_eleHoverE;   //!
   TBranch        *b_eleD0;   //!
   TBranch        *b_eleDz;   //!
   TBranch        *b_eleScEn;   //!
   TBranch        *b_eleScPreEn;   //!
   TBranch        *b_eleScEta;   //!
   TBranch        *b_eleScPhi;   //!
   TBranch        *b_eleScRawEn;   //!
   TBranch        *b_eleScEtaWidth;   //!
   TBranch        *b_eleScPhiWidth;   //!
   TBranch        *b_eleEoverP;   //!
   TBranch        *b_eleBrem;   //!
   TBranch        *b_eledEtaAtVtx;   //!
   TBranch        *b_eledPhiAtVtx;   //!
   TBranch        *b_eleSigmaIEtaIEta;   //!
   TBranch        *b_eleSigmaIEtaIPhi;   //!
   TBranch        *b_eleSigmaIPhiIPhi;   //!
   TBranch        *b_eleConvVeto;   //!
   TBranch        *b_eleMissHits;   //!
   TBranch        *b_eleEoverPInv;   //!
   TBranch        *b_eleEtaseedAtVtx;   //!
   TBranch        *b_eleE1x5;   //!
   TBranch        *b_eleE2x5;   //!
   TBranch        *b_eleE5x5;   //!
   TBranch        *b_eleChHadIso;   //!
   TBranch        *b_eleNeHadIso;   //!
   TBranch        *b_eleGamIso;   //!
   TBranch        *b_elePUPt;   //!
   TBranch        *b_elecaloEnergy;   //!
   TBranch        *b_eleSigmaIEtaIEtaFull5x5;   //!
   TBranch        *b_eleE1x5Full5x5;   //!
   TBranch        *b_eleE2x5Full5x5;   //!
   TBranch        *b_eleE5x5Full5x5;   //!
   TBranch        *b_eleR9Full5x5;   //!
   TBranch        *b_eleEcalDrivenSeed;   //!
   TBranch        *b_eleDr03EcalRecHitSumEt;   //!
   TBranch        *b_eleDr03HcalDepth1TowerSumEt;   //!
   TBranch        *b_eleDr03HcalDepth2TowerSumEt;   //!
   TBranch        *b_eleDr03HcalTowerSumEt;   //!
   TBranch        *b_eleDr03TkSumPt;   //!
   TBranch        *b_eleTrkdztrackref;   //!
   TBranch        *b_eleTrkdxytrackref;   //!
   TBranch        *b_eleInBarrel;   //!
   TBranch        *b_eleInEndcap;   //!
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
   TBranch        *b_FATnJet;   //!
   TBranch        *b_FATjetPt;   //!
   TBranch        *b_FATjetEta;   //!
   TBranch        *b_FATjetPhi;   //!
   TBranch        *b_FATjetMass;   //!
   TBranch        *b_FATjetEn;   //!
   TBranch        *b_FATgenjetPx;   //!
   TBranch        *b_FATgenjetPy;   //!
   TBranch        *b_FATgenjetPz;   //!
   TBranch        *b_FATgenjetEn;   //!
   TBranch        *b_FATgenjetEM;   //!
   TBranch        *b_FATgenjetHAD;   //!
   TBranch        *b_FATgenjetINV;   //!
   TBranch        *b_FATgenjetAUX;   //!
   TBranch        *b_FATmatchedDR;   //!
   TBranch        *b_FATjetCorrUncUp;   //!
   TBranch        *b_FATjetCorrUncDown;   //!
   TBranch        *b_FATjetCharge;   //!
   TBranch        *b_FATjetPartonFlavor;   //!
   TBranch        *b_FATjetPassID;   //!
   TBranch        *b_FATjet_nSV;   //!
   TBranch        *b_FATjet_SVMass;   //!
   TBranch        *b_FATjet_SVEnergyRatio;   //!
   TBranch        *b_FATjetSSV;   //!
   TBranch        *b_FATjetSSVHE;   //!
   TBranch        *b_FATjetCSV;   //!
   TBranch        *b_FATjetCISVV2;   //!
   TBranch        *b_FATjetTCHP;   //!
   TBranch        *b_FATjetTCHE;   //!
   TBranch        *b_FATjetJP;   //!
   TBranch        *b_FATjetJBP;   //!
   TBranch        *b_FATjetTau1;   //!
   TBranch        *b_FATjetTau2;   //!
   TBranch        *b_FATjetTau3;   //!
   TBranch        *b_FATjetTau4;   //!
   TBranch        *b_FATjetMuEF;   //!
   TBranch        *b_FATjetPhoEF;   //!
   TBranch        *b_FATjetCEmEF;   //!
   TBranch        *b_FATjetCHadEF;   //!
   TBranch        *b_FATjetNEmEF;   //!
   TBranch        *b_FATjetNHadEF;   //!
   TBranch        *b_FATjetCMulti;   //!
   TBranch        *b_FATjetPrunedPt;   //!
   TBranch        *b_FATjetPrunedEta;   //!
   TBranch        *b_FATjetPrunedPhi;   //!
   TBranch        *b_FATjetPrunedMass;   //!
   TBranch        *b_FATjetPrunedEn;   //!
   TBranch        *b_FATjetPrunedCorrUncUp;   //!
   TBranch        *b_FATjetPrunedCorrUncDown;   //!
   TBranch        *b_FATjetPrunedCharge;   //!
   TBranch        *b_FATjetPrunedPartonFlavor;   //!
   TBranch        *b_FATjetPrunedSSV;   //!
   TBranch        *b_FATjetPrunedCSV;   //!
   TBranch        *b_FATjetPrunedTCHP;   //!
   TBranch        *b_FATjetPrunedTCHE;   //!
   TBranch        *b_FATjetPrunedJP;   //!
   TBranch        *b_FATjetPrunedJBP;   //!
   TBranch        *b_FATjetSDmass;   //!
   TBranch        *b_FATjetTRmass;   //!
   TBranch        *b_FATjetPRmass;   //!
   TBranch        *b_FATjetFimass;   //!
   TBranch        *b_FATjet_DoubleSV;   //!
   TBranch        *b_FATnSubSDJet;   //!
   TBranch        *b_FATsubjetSDPt;   //!
   TBranch        *b_FATsubjetSDEta;   //!
   TBranch        *b_FATsubjetSDPhi;   //!
   TBranch        *b_FATsubjetSDMass;   //!
   TBranch        *b_FATsubjetSDCSV;   //!
   TBranch        *b_THINnJet;   //!
   TBranch        *b_THINjetPt;   //!
   TBranch        *b_THINjetEta;   //!
   TBranch        *b_THINjetPhi;   //!
   TBranch        *b_THINjetMass;   //!
   TBranch        *b_THINjetEn;   //!
   TBranch        *b_THINgenjetPx;   //!
   TBranch        *b_THINgenjetPy;   //!
   TBranch        *b_THINgenjetPz;   //!
   TBranch        *b_THINgenjetEn;   //!
   TBranch        *b_THINgenjetEM;   //!
   TBranch        *b_THINgenjetHAD;   //!
   TBranch        *b_THINgenjetINV;   //!
   TBranch        *b_THINgenjetAUX;   //!
   TBranch        *b_THINmatchedDR;   //!
   TBranch        *b_THINjetCorrUncUp;   //!
   TBranch        *b_THINjetCorrUncDown;   //!
   TBranch        *b_THINjetCharge;   //!
   TBranch        *b_THINjetPartonFlavor;   //!
   TBranch        *b_THINjetPassID;   //!
   TBranch        *b_THINjet_nSV;   //!
   TBranch        *b_THINjet_SVMass;   //!
   TBranch        *b_THINjet_SVEnergyRatio;   //!
   TBranch        *b_THINjetSSV;   //!
   TBranch        *b_THINjetSSVHE;   //!
   TBranch        *b_THINjetCSV;   //!
   TBranch        *b_THINjetCISVV2;   //!
   TBranch        *b_THINjetTCHP;   //!
   TBranch        *b_THINjetTCHE;   //!
   TBranch        *b_THINjetJP;   //!
   TBranch        *b_THINjetJBP;   //!
   TBranch        *b_THINjetTau1;   //!
   TBranch        *b_THINjetTau2;   //!
   TBranch        *b_THINjetTau3;   //!
   TBranch        *b_THINjetTau4;   //!
   TBranch        *b_THINjetMuEF;   //!
   TBranch        *b_THINjetPhoEF;   //!
   TBranch        *b_THINjetCEmEF;   //!
   TBranch        *b_THINjetCHadEF;   //!
   TBranch        *b_THINjetNEmEF;   //!
   TBranch        *b_THINjetNHadEF;   //!
   TBranch        *b_THINjetCMulti;   //!
   TBranch        *b_ADDnJet;   //!
   TBranch        *b_ADDjetPt;   //!
   TBranch        *b_ADDjetEta;   //!
   TBranch        *b_ADDjetPhi;   //!
   TBranch        *b_ADDjetMass;   //!
   TBranch        *b_ADDjetEn;   //!
   TBranch        *b_ADDgenjetPx;   //!
   TBranch        *b_ADDgenjetPy;   //!
   TBranch        *b_ADDgenjetPz;   //!
   TBranch        *b_ADDgenjetEn;   //!
   TBranch        *b_ADDgenjetEM;   //!
   TBranch        *b_ADDgenjetHAD;   //!
   TBranch        *b_ADDgenjetINV;   //!
   TBranch        *b_ADDgenjetAUX;   //!
   TBranch        *b_ADDmatchedDR;   //!
   TBranch        *b_ADDjetCorrUncUp;   //!
   TBranch        *b_ADDjetCorrUncDown;   //!
   TBranch        *b_ADDjetCharge;   //!
   TBranch        *b_ADDjetPartonFlavor;   //!
   TBranch        *b_ADDjetPassID;   //!
   TBranch        *b_ADDjet_nSV;   //!
   TBranch        *b_ADDjet_SVMass;   //!
   TBranch        *b_ADDjet_SVEnergyRatio;   //!
   TBranch        *b_ADDjetSSV;   //!
   TBranch        *b_ADDjetSSVHE;   //!
   TBranch        *b_ADDjetCSV;   //!
   TBranch        *b_ADDjetCISVV2;   //!
   TBranch        *b_ADDjetTCHP;   //!
   TBranch        *b_ADDjetTCHE;   //!
   TBranch        *b_ADDjetJP;   //!
   TBranch        *b_ADDjetJBP;   //!
   TBranch        *b_ADDjetTau1;   //!
   TBranch        *b_ADDjetTau2;   //!
   TBranch        *b_ADDjetTau3;   //!
   TBranch        *b_ADDjetTau4;   //!
   TBranch        *b_ADDjetMuEF;   //!
   TBranch        *b_ADDjetPhoEF;   //!
   TBranch        *b_ADDjetCEmEF;   //!
   TBranch        *b_ADDjetCHadEF;   //!
   TBranch        *b_ADDjetNEmEF;   //!
   TBranch        *b_ADDjetNHadEF;   //!
   TBranch        *b_ADDjetCMulti;   //!
   TBranch        *b_ADDjetPrunedPt;   //!
   TBranch        *b_ADDjetPrunedEta;   //!
   TBranch        *b_ADDjetPrunedPhi;   //!
   TBranch        *b_ADDjetPrunedMass;   //!
   TBranch        *b_ADDjetPrunedEn;   //!
   TBranch        *b_ADDjetPrunedCorrUncUp;   //!
   TBranch        *b_ADDjetPrunedCorrUncDown;   //!
   TBranch        *b_ADDjetPrunedCharge;   //!
   TBranch        *b_ADDjetPrunedPartonFlavor;   //!
   TBranch        *b_ADDjetPrunedSSV;   //!
   TBranch        *b_ADDjetPrunedCSV;   //!
   TBranch        *b_ADDjetPrunedTCHP;   //!
   TBranch        *b_ADDjetPrunedTCHE;   //!
   TBranch        *b_ADDjetPrunedJP;   //!
   TBranch        *b_ADDjetPrunedJBP;   //!
   TBranch        *b_ADDjetSDmass;   //!
   TBranch        *b_ADDjetTRmass;   //!
   TBranch        *b_ADDjetPRmass;   //!
   TBranch        *b_ADDjetFimass;   //!
   TBranch        *b_ADDjet_DoubleSV;   //!
   TBranch        *b_ADDnSubSDJet;   //!
   TBranch        *b_ADDsubjetSDPt;   //!
   TBranch        *b_ADDsubjetSDEta;   //!
   TBranch        *b_ADDsubjetSDPhi;   //!
   TBranch        *b_ADDsubjetSDMass;   //!
   TBranch        *b_ADDsubjetSDCSV;   //!
   TBranch        *b_hlt_nTrigs;   //!
   TBranch        *b_hlt_trigResult;   //!
   TBranch        *b_trigName;   //!

   bkg2_TreeMaker(TTree *tree=0);
   virtual ~bkg2_TreeMaker();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef bkg2_TreeMaker_cxx
bkg2_TreeMaker::bkg2_TreeMaker(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("NCUGlobalTuples_52.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("NCUGlobalTuples_52.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("NCUGlobalTuples_52.root:/tree");
      dir->GetObject("treeMaker",tree);

   }
   Init(tree);
}

bkg2_TreeMaker::~bkg2_TreeMaker()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t bkg2_TreeMaker::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t bkg2_TreeMaker::LoadTree(Long64_t entry)
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

void bkg2_TreeMaker::Init(TTree *tree)
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
   muCharge = 0;
   isGlobalMuon = 0;
   isTrackerMuon = 0;
   isPFMuon = 0;
   muTrkPt = 0;
   muTrkPtErr = 0;
   mudxy = 0;
   mudz = 0;
   musegmentCompatibility = 0;
   muchi2LocalPosition = 0;
   mutrkKink = 0;
   muInnerdxy_ = 0;
   muInnerdz_ = 0;
   muTrkLayers = 0;
   muPixelLayers = 0;
   muPixelHits = 0;
   muTrkQuality_ = 0;
   muHits = 0;
   muChi2NDF = 0;
   MuInnervalidFraction_ = 0;
   muMatches = 0;
   muITrkID = 0;
   muSegID = 0;
   muNSegs = 0;
   muGood = 0;
   patMuonIsGood = 0;
   muTrkIso = 0;
   muHcalIso = 0;
   muEcalIso = 0;
   muChHadIso = 0;
   muNeHadIso = 0;
   muGamIso = 0;
   muPUPt = 0;
   isPassVeto = 0;
   isPassLoose = 0;
   isPassMedium = 0;
   isPassTight = 0;
   isPassHEEP = 0;
   patElecP4 = 0;
   eleEffArea = 0;
   eleCharge = 0;
   eleChargeConsistent = 0;
   eleR9 = 0;
   eleHoverE = 0;
   eleD0 = 0;
   eleDz = 0;
   eleScEn = 0;
   eleScPreEn = 0;
   eleScEta = 0;
   eleScPhi = 0;
   eleScRawEn = 0;
   eleScEtaWidth = 0;
   eleScPhiWidth = 0;
   eleEoverP = 0;
   eleBrem = 0;
   eledEtaAtVtx = 0;
   eledPhiAtVtx = 0;
   eleSigmaIEtaIEta = 0;
   eleSigmaIEtaIPhi = 0;
   eleSigmaIPhiIPhi = 0;
   eleConvVeto = 0;
   eleMissHits = 0;
   eleEoverPInv = 0;
   eleEtaseedAtVtx = 0;
   eleE1x5 = 0;
   eleE2x5 = 0;
   eleE5x5 = 0;
   eleChHadIso = 0;
   eleNeHadIso = 0;
   eleGamIso = 0;
   elePUPt = 0;
   elecaloEnergy = 0;
   eleSigmaIEtaIEtaFull5x5 = 0;
   eleE1x5Full5x5 = 0;
   eleE2x5Full5x5 = 0;
   eleE5x5Full5x5 = 0;
   eleR9Full5x5 = 0;
   eleEcalDrivenSeed = 0;
   eleDr03EcalRecHitSumEt = 0;
   eleDr03HcalDepth1TowerSumEt = 0;
   eleDr03HcalDepth2TowerSumEt = 0;
   eleDr03HcalTowerSumEt = 0;
   eleDr03TkSumPt = 0;
   eleTrkdztrackref = 0;
   eleTrkdxytrackref = 0;
   eleInBarrel = 0;
   eleInEndcap = 0;
   FATjetPt = 0;
   FATjetEta = 0;
   FATjetPhi = 0;
   FATjetMass = 0;
   FATjetEn = 0;
   FATgenjetPx = 0;
   FATgenjetPy = 0;
   FATgenjetPz = 0;
   FATgenjetEn = 0;
   FATgenjetEM = 0;
   FATgenjetHAD = 0;
   FATgenjetINV = 0;
   FATgenjetAUX = 0;
   FATmatchedDR = 0;
   FATjetCorrUncUp = 0;
   FATjetCorrUncDown = 0;
   FATjetCharge = 0;
   FATjetPartonFlavor = 0;
   FATjetPassID = 0;
   FATjet_nSV = 0;
   FATjet_SVMass = 0;
   FATjet_SVEnergyRatio = 0;
   FATjetSSV = 0;
   FATjetSSVHE = 0;
   FATjetCSV = 0;
   FATjetCISVV2 = 0;
   FATjetTCHP = 0;
   FATjetTCHE = 0;
   FATjetJP = 0;
   FATjetJBP = 0;
   FATjetTau1 = 0;
   FATjetTau2 = 0;
   FATjetTau3 = 0;
   FATjetTau4 = 0;
   FATjetMuEF = 0;
   FATjetPhoEF = 0;
   FATjetCEmEF = 0;
   FATjetCHadEF = 0;
   FATjetNEmEF = 0;
   FATjetNHadEF = 0;
   FATjetCMulti = 0;
   FATjetPrunedPt = 0;
   FATjetPrunedEta = 0;
   FATjetPrunedPhi = 0;
   FATjetPrunedMass = 0;
   FATjetPrunedEn = 0;
   FATjetPrunedCorrUncUp = 0;
   FATjetPrunedCorrUncDown = 0;
   FATjetPrunedCharge = 0;
   FATjetPrunedPartonFlavor = 0;
   FATjetPrunedSSV = 0;
   FATjetPrunedCSV = 0;
   FATjetPrunedTCHP = 0;
   FATjetPrunedTCHE = 0;
   FATjetPrunedJP = 0;
   FATjetPrunedJBP = 0;
   FATjetSDmass = 0;
   FATjetTRmass = 0;
   FATjetPRmass = 0;
   FATjetFimass = 0;
   FATjet_DoubleSV = 0;
   FATnSubSDJet = 0;
   FATsubjetSDPt = 0;
   FATsubjetSDEta = 0;
   FATsubjetSDPhi = 0;
   FATsubjetSDMass = 0;
   FATsubjetSDCSV = 0;
   THINjetPt = 0;
   THINjetEta = 0;
   THINjetPhi = 0;
   THINjetMass = 0;
   THINjetEn = 0;
   THINgenjetPx = 0;
   THINgenjetPy = 0;
   THINgenjetPz = 0;
   THINgenjetEn = 0;
   THINgenjetEM = 0;
   THINgenjetHAD = 0;
   THINgenjetINV = 0;
   THINgenjetAUX = 0;
   THINmatchedDR = 0;
   THINjetCorrUncUp = 0;
   THINjetCorrUncDown = 0;
   THINjetCharge = 0;
   THINjetPartonFlavor = 0;
   THINjetPassID = 0;
   THINjet_nSV = 0;
   THINjet_SVMass = 0;
   THINjet_SVEnergyRatio = 0;
   THINjetSSV = 0;
   THINjetSSVHE = 0;
   THINjetCSV = 0;
   THINjetCISVV2 = 0;
   THINjetTCHP = 0;
   THINjetTCHE = 0;
   THINjetJP = 0;
   THINjetJBP = 0;
   THINjetTau1 = 0;
   THINjetTau2 = 0;
   THINjetTau3 = 0;
   THINjetTau4 = 0;
   THINjetMuEF = 0;
   THINjetPhoEF = 0;
   THINjetCEmEF = 0;
   THINjetCHadEF = 0;
   THINjetNEmEF = 0;
   THINjetNHadEF = 0;
   THINjetCMulti = 0;
   ADDjetPt = 0;
   ADDjetEta = 0;
   ADDjetPhi = 0;
   ADDjetMass = 0;
   ADDjetEn = 0;
   ADDgenjetPx = 0;
   ADDgenjetPy = 0;
   ADDgenjetPz = 0;
   ADDgenjetEn = 0;
   ADDgenjetEM = 0;
   ADDgenjetHAD = 0;
   ADDgenjetINV = 0;
   ADDgenjetAUX = 0;
   ADDmatchedDR = 0;
   ADDjetCorrUncUp = 0;
   ADDjetCorrUncDown = 0;
   ADDjetCharge = 0;
   ADDjetPartonFlavor = 0;
   ADDjetPassID = 0;
   ADDjet_nSV = 0;
   ADDjet_SVMass = 0;
   ADDjet_SVEnergyRatio = 0;
   ADDjetSSV = 0;
   ADDjetSSVHE = 0;
   ADDjetCSV = 0;
   ADDjetCISVV2 = 0;
   ADDjetTCHP = 0;
   ADDjetTCHE = 0;
   ADDjetJP = 0;
   ADDjetJBP = 0;
   ADDjetTau1 = 0;
   ADDjetTau2 = 0;
   ADDjetTau3 = 0;
   ADDjetTau4 = 0;
   ADDjetMuEF = 0;
   ADDjetPhoEF = 0;
   ADDjetCEmEF = 0;
   ADDjetCHadEF = 0;
   ADDjetNEmEF = 0;
   ADDjetNHadEF = 0;
   ADDjetCMulti = 0;
   ADDjetPrunedPt = 0;
   ADDjetPrunedEta = 0;
   ADDjetPrunedPhi = 0;
   ADDjetPrunedMass = 0;
   ADDjetPrunedEn = 0;
   ADDjetPrunedCorrUncUp = 0;
   ADDjetPrunedCorrUncDown = 0;
   ADDjetPrunedCharge = 0;
   ADDjetPrunedPartonFlavor = 0;
   ADDjetPrunedSSV = 0;
   ADDjetPrunedCSV = 0;
   ADDjetPrunedTCHP = 0;
   ADDjetPrunedTCHE = 0;
   ADDjetPrunedJP = 0;
   ADDjetPrunedJBP = 0;
   ADDjetSDmass = 0;
   ADDjetTRmass = 0;
   ADDjetPRmass = 0;
   ADDjetFimass = 0;
   ADDjet_DoubleSV = 0;
   ADDnSubSDJet = 0;
   ADDsubjetSDPt = 0;
   ADDsubjetSDEta = 0;
   ADDsubjetSDPhi = 0;
   ADDsubjetSDMass = 0;
   ADDsubjetSDCSV = 0;
   hlt_trigResult = 0;
   trigName = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

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
   fChain->SetBranchAddress("muCharge", &muCharge, &b_muCharge);
   fChain->SetBranchAddress("isGlobalMuon", &isGlobalMuon, &b_isGlobalMuon);
   fChain->SetBranchAddress("isTrackerMuon", &isTrackerMuon, &b_isTrackerMuon);
   fChain->SetBranchAddress("isPFMuon", &isPFMuon, &b_isPFMuon);
   fChain->SetBranchAddress("muTrkPt", &muTrkPt, &b_muTrkPt);
   fChain->SetBranchAddress("muTrkPtErr", &muTrkPtErr, &b_muTrkPtErr);
   fChain->SetBranchAddress("mudxy", &mudxy, &b_mudxy);
   fChain->SetBranchAddress("mudz", &mudz, &b_mudz);
   fChain->SetBranchAddress("musegmentCompatibility", &musegmentCompatibility, &b_musegmentCompatibility);
   fChain->SetBranchAddress("muchi2LocalPosition", &muchi2LocalPosition, &b_muchi2LocalPosition);
   fChain->SetBranchAddress("mutrkKink", &mutrkKink, &b_mutrkKink);
   fChain->SetBranchAddress("muInnerdxy_", &muInnerdxy_, &b_muInnerdxy_);
   fChain->SetBranchAddress("muInnerdz_", &muInnerdz_, &b_muInnerdz_);
   fChain->SetBranchAddress("muTrkLayers", &muTrkLayers, &b_muTrkLayers);
   fChain->SetBranchAddress("muPixelLayers", &muPixelLayers, &b_muPixelLayers);
   fChain->SetBranchAddress("muPixelHits", &muPixelHits, &b_muPixelHits);
   fChain->SetBranchAddress("muTrkQuality_", &muTrkQuality_, &b_muTrkQuality_);
   fChain->SetBranchAddress("muHits", &muHits, &b_muHits);
   fChain->SetBranchAddress("muChi2NDF", &muChi2NDF, &b_muChi2NDF);
   fChain->SetBranchAddress("MuInnervalidFraction_", &MuInnervalidFraction_, &b_MuInnervalidFraction_);
   fChain->SetBranchAddress("muMatches", &muMatches, &b_muMatches);
   fChain->SetBranchAddress("muITrkID", &muITrkID, &b_muITrkID);
   fChain->SetBranchAddress("muSegID", &muSegID, &b_muSegID);
   fChain->SetBranchAddress("muNSegs", &muNSegs, &b_muNSegs);
   fChain->SetBranchAddress("muGood", &muGood, &b_muGood);
   fChain->SetBranchAddress("patMuonIsGood", &patMuonIsGood, &b_patMuonIsGood);
   fChain->SetBranchAddress("muTrkIso", &muTrkIso, &b_muTrkIso);
   fChain->SetBranchAddress("muHcalIso", &muHcalIso, &b_muHcalIso);
   fChain->SetBranchAddress("muEcalIso", &muEcalIso, &b_muEcalIso);
   fChain->SetBranchAddress("muChHadIso", &muChHadIso, &b_muChHadIso);
   fChain->SetBranchAddress("muNeHadIso", &muNeHadIso, &b_muNeHadIso);
   fChain->SetBranchAddress("muGamIso", &muGamIso, &b_muGamIso);
   fChain->SetBranchAddress("muPUPt", &muPUPt, &b_muPUPt);
   fChain->SetBranchAddress("nEle", &nEle, &b_nEle);
   fChain->SetBranchAddress("isPassVeto", &isPassVeto, &b_isPassVeto);
   fChain->SetBranchAddress("isPassLoose", &isPassLoose, &b_isPassLoose);
   fChain->SetBranchAddress("isPassMedium", &isPassMedium, &b_isPassMedium);
   fChain->SetBranchAddress("isPassTight", &isPassTight, &b_isPassTight);
   fChain->SetBranchAddress("isPassHEEP", &isPassHEEP, &b_isPassHEEP);
   fChain->SetBranchAddress("patElecP4", &patElecP4, &b_patElecP4);
   fChain->SetBranchAddress("eleRho", &eleRho, &b_eleRho);
   fChain->SetBranchAddress("eleEffArea", &eleEffArea, &b_eleEffArea);
   fChain->SetBranchAddress("eleCharge", &eleCharge, &b_eleCharge);
   fChain->SetBranchAddress("eleChargeConsistent", &eleChargeConsistent, &b_eleChargeConsistent);
   fChain->SetBranchAddress("eleR9", &eleR9, &b_eleR9);
   fChain->SetBranchAddress("eleHoverE", &eleHoverE, &b_eleHoverE);
   fChain->SetBranchAddress("eleD0", &eleD0, &b_eleD0);
   fChain->SetBranchAddress("eleDz", &eleDz, &b_eleDz);
   fChain->SetBranchAddress("eleScEn", &eleScEn, &b_eleScEn);
   fChain->SetBranchAddress("eleScPreEn", &eleScPreEn, &b_eleScPreEn);
   fChain->SetBranchAddress("eleScEta", &eleScEta, &b_eleScEta);
   fChain->SetBranchAddress("eleScPhi", &eleScPhi, &b_eleScPhi);
   fChain->SetBranchAddress("eleScRawEn", &eleScRawEn, &b_eleScRawEn);
   fChain->SetBranchAddress("eleScEtaWidth", &eleScEtaWidth, &b_eleScEtaWidth);
   fChain->SetBranchAddress("eleScPhiWidth", &eleScPhiWidth, &b_eleScPhiWidth);
   fChain->SetBranchAddress("eleEoverP", &eleEoverP, &b_eleEoverP);
   fChain->SetBranchAddress("eleBrem", &eleBrem, &b_eleBrem);
   fChain->SetBranchAddress("eledEtaAtVtx", &eledEtaAtVtx, &b_eledEtaAtVtx);
   fChain->SetBranchAddress("eledPhiAtVtx", &eledPhiAtVtx, &b_eledPhiAtVtx);
   fChain->SetBranchAddress("eleSigmaIEtaIEta", &eleSigmaIEtaIEta, &b_eleSigmaIEtaIEta);
   fChain->SetBranchAddress("eleSigmaIEtaIPhi", &eleSigmaIEtaIPhi, &b_eleSigmaIEtaIPhi);
   fChain->SetBranchAddress("eleSigmaIPhiIPhi", &eleSigmaIPhiIPhi, &b_eleSigmaIPhiIPhi);
   fChain->SetBranchAddress("eleConvVeto", &eleConvVeto, &b_eleConvVeto);
   fChain->SetBranchAddress("eleMissHits", &eleMissHits, &b_eleMissHits);
   fChain->SetBranchAddress("eleEoverPInv", &eleEoverPInv, &b_eleEoverPInv);
   fChain->SetBranchAddress("eleEtaseedAtVtx", &eleEtaseedAtVtx, &b_eleEtaseedAtVtx);
   fChain->SetBranchAddress("eleE1x5", &eleE1x5, &b_eleE1x5);
   fChain->SetBranchAddress("eleE2x5", &eleE2x5, &b_eleE2x5);
   fChain->SetBranchAddress("eleE5x5", &eleE5x5, &b_eleE5x5);
   fChain->SetBranchAddress("eleChHadIso", &eleChHadIso, &b_eleChHadIso);
   fChain->SetBranchAddress("eleNeHadIso", &eleNeHadIso, &b_eleNeHadIso);
   fChain->SetBranchAddress("eleGamIso", &eleGamIso, &b_eleGamIso);
   fChain->SetBranchAddress("elePUPt", &elePUPt, &b_elePUPt);
   fChain->SetBranchAddress("elecaloEnergy", &elecaloEnergy, &b_elecaloEnergy);
   fChain->SetBranchAddress("eleSigmaIEtaIEtaFull5x5", &eleSigmaIEtaIEtaFull5x5, &b_eleSigmaIEtaIEtaFull5x5);
   fChain->SetBranchAddress("eleE1x5Full5x5", &eleE1x5Full5x5, &b_eleE1x5Full5x5);
   fChain->SetBranchAddress("eleE2x5Full5x5", &eleE2x5Full5x5, &b_eleE2x5Full5x5);
   fChain->SetBranchAddress("eleE5x5Full5x5", &eleE5x5Full5x5, &b_eleE5x5Full5x5);
   fChain->SetBranchAddress("eleR9Full5x5", &eleR9Full5x5, &b_eleR9Full5x5);
   fChain->SetBranchAddress("eleEcalDrivenSeed", &eleEcalDrivenSeed, &b_eleEcalDrivenSeed);
   fChain->SetBranchAddress("eleDr03EcalRecHitSumEt", &eleDr03EcalRecHitSumEt, &b_eleDr03EcalRecHitSumEt);
   fChain->SetBranchAddress("eleDr03HcalDepth1TowerSumEt", &eleDr03HcalDepth1TowerSumEt, &b_eleDr03HcalDepth1TowerSumEt);
   fChain->SetBranchAddress("eleDr03HcalDepth2TowerSumEt", &eleDr03HcalDepth2TowerSumEt, &b_eleDr03HcalDepth2TowerSumEt);
   fChain->SetBranchAddress("eleDr03HcalTowerSumEt", &eleDr03HcalTowerSumEt, &b_eleDr03HcalTowerSumEt);
   fChain->SetBranchAddress("eleDr03TkSumPt", &eleDr03TkSumPt, &b_eleDr03TkSumPt);
   fChain->SetBranchAddress("eleTrkdztrackref", &eleTrkdztrackref, &b_eleTrkdztrackref);
   fChain->SetBranchAddress("eleTrkdxytrackref", &eleTrkdxytrackref, &b_eleTrkdxytrackref);
   fChain->SetBranchAddress("eleInBarrel", &eleInBarrel, &b_eleInBarrel);
   fChain->SetBranchAddress("eleInEndcap", &eleInEndcap, &b_eleInEndcap);
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
   fChain->SetBranchAddress("FATnJet", &FATnJet, &b_FATnJet);
   fChain->SetBranchAddress("FATjetPt", &FATjetPt, &b_FATjetPt);
   fChain->SetBranchAddress("FATjetEta", &FATjetEta, &b_FATjetEta);
   fChain->SetBranchAddress("FATjetPhi", &FATjetPhi, &b_FATjetPhi);
   fChain->SetBranchAddress("FATjetMass", &FATjetMass, &b_FATjetMass);
   fChain->SetBranchAddress("FATjetEn", &FATjetEn, &b_FATjetEn);
   fChain->SetBranchAddress("FATgenjetPx", &FATgenjetPx, &b_FATgenjetPx);
   fChain->SetBranchAddress("FATgenjetPy", &FATgenjetPy, &b_FATgenjetPy);
   fChain->SetBranchAddress("FATgenjetPz", &FATgenjetPz, &b_FATgenjetPz);
   fChain->SetBranchAddress("FATgenjetEn", &FATgenjetEn, &b_FATgenjetEn);
   fChain->SetBranchAddress("FATgenjetEM", &FATgenjetEM, &b_FATgenjetEM);
   fChain->SetBranchAddress("FATgenjetHAD", &FATgenjetHAD, &b_FATgenjetHAD);
   fChain->SetBranchAddress("FATgenjetINV", &FATgenjetINV, &b_FATgenjetINV);
   fChain->SetBranchAddress("FATgenjetAUX", &FATgenjetAUX, &b_FATgenjetAUX);
   fChain->SetBranchAddress("FATmatchedDR", &FATmatchedDR, &b_FATmatchedDR);
   fChain->SetBranchAddress("FATjetCorrUncUp", &FATjetCorrUncUp, &b_FATjetCorrUncUp);
   fChain->SetBranchAddress("FATjetCorrUncDown", &FATjetCorrUncDown, &b_FATjetCorrUncDown);
   fChain->SetBranchAddress("FATjetCharge", &FATjetCharge, &b_FATjetCharge);
   fChain->SetBranchAddress("FATjetPartonFlavor", &FATjetPartonFlavor, &b_FATjetPartonFlavor);
   fChain->SetBranchAddress("FATjetPassID", &FATjetPassID, &b_FATjetPassID);
   fChain->SetBranchAddress("FATjet_nSV", &FATjet_nSV, &b_FATjet_nSV);
   fChain->SetBranchAddress("FATjet_SVMass", &FATjet_SVMass, &b_FATjet_SVMass);
   fChain->SetBranchAddress("FATjet_SVEnergyRatio", &FATjet_SVEnergyRatio, &b_FATjet_SVEnergyRatio);
   fChain->SetBranchAddress("FATjetSSV", &FATjetSSV, &b_FATjetSSV);
   fChain->SetBranchAddress("FATjetSSVHE", &FATjetSSVHE, &b_FATjetSSVHE);
   fChain->SetBranchAddress("FATjetCSV", &FATjetCSV, &b_FATjetCSV);
   fChain->SetBranchAddress("FATjetCISVV2", &FATjetCISVV2, &b_FATjetCISVV2);
   fChain->SetBranchAddress("FATjetTCHP", &FATjetTCHP, &b_FATjetTCHP);
   fChain->SetBranchAddress("FATjetTCHE", &FATjetTCHE, &b_FATjetTCHE);
   fChain->SetBranchAddress("FATjetJP", &FATjetJP, &b_FATjetJP);
   fChain->SetBranchAddress("FATjetJBP", &FATjetJBP, &b_FATjetJBP);
   fChain->SetBranchAddress("FATjetTau1", &FATjetTau1, &b_FATjetTau1);
   fChain->SetBranchAddress("FATjetTau2", &FATjetTau2, &b_FATjetTau2);
   fChain->SetBranchAddress("FATjetTau3", &FATjetTau3, &b_FATjetTau3);
   fChain->SetBranchAddress("FATjetTau4", &FATjetTau4, &b_FATjetTau4);
   fChain->SetBranchAddress("FATjetMuEF", &FATjetMuEF, &b_FATjetMuEF);
   fChain->SetBranchAddress("FATjetPhoEF", &FATjetPhoEF, &b_FATjetPhoEF);
   fChain->SetBranchAddress("FATjetCEmEF", &FATjetCEmEF, &b_FATjetCEmEF);
   fChain->SetBranchAddress("FATjetCHadEF", &FATjetCHadEF, &b_FATjetCHadEF);
   fChain->SetBranchAddress("FATjetNEmEF", &FATjetNEmEF, &b_FATjetNEmEF);
   fChain->SetBranchAddress("FATjetNHadEF", &FATjetNHadEF, &b_FATjetNHadEF);
   fChain->SetBranchAddress("FATjetCMulti", &FATjetCMulti, &b_FATjetCMulti);
   fChain->SetBranchAddress("FATjetPrunedPt", &FATjetPrunedPt, &b_FATjetPrunedPt);
   fChain->SetBranchAddress("FATjetPrunedEta", &FATjetPrunedEta, &b_FATjetPrunedEta);
   fChain->SetBranchAddress("FATjetPrunedPhi", &FATjetPrunedPhi, &b_FATjetPrunedPhi);
   fChain->SetBranchAddress("FATjetPrunedMass", &FATjetPrunedMass, &b_FATjetPrunedMass);
   fChain->SetBranchAddress("FATjetPrunedEn", &FATjetPrunedEn, &b_FATjetPrunedEn);
   fChain->SetBranchAddress("FATjetPrunedCorrUncUp", &FATjetPrunedCorrUncUp, &b_FATjetPrunedCorrUncUp);
   fChain->SetBranchAddress("FATjetPrunedCorrUncDown", &FATjetPrunedCorrUncDown, &b_FATjetPrunedCorrUncDown);
   fChain->SetBranchAddress("FATjetPrunedCharge", &FATjetPrunedCharge, &b_FATjetPrunedCharge);
   fChain->SetBranchAddress("FATjetPrunedPartonFlavor", &FATjetPrunedPartonFlavor, &b_FATjetPrunedPartonFlavor);
   fChain->SetBranchAddress("FATjetPrunedSSV", &FATjetPrunedSSV, &b_FATjetPrunedSSV);
   fChain->SetBranchAddress("FATjetPrunedCSV", &FATjetPrunedCSV, &b_FATjetPrunedCSV);
   fChain->SetBranchAddress("FATjetPrunedTCHP", &FATjetPrunedTCHP, &b_FATjetPrunedTCHP);
   fChain->SetBranchAddress("FATjetPrunedTCHE", &FATjetPrunedTCHE, &b_FATjetPrunedTCHE);
   fChain->SetBranchAddress("FATjetPrunedJP", &FATjetPrunedJP, &b_FATjetPrunedJP);
   fChain->SetBranchAddress("FATjetPrunedJBP", &FATjetPrunedJBP, &b_FATjetPrunedJBP);
   fChain->SetBranchAddress("FATjetSDmass", &FATjetSDmass, &b_FATjetSDmass);
   fChain->SetBranchAddress("FATjetTRmass", &FATjetTRmass, &b_FATjetTRmass);
   fChain->SetBranchAddress("FATjetPRmass", &FATjetPRmass, &b_FATjetPRmass);
   fChain->SetBranchAddress("FATjetFimass", &FATjetFimass, &b_FATjetFimass);
   fChain->SetBranchAddress("FATjet_DoubleSV", &FATjet_DoubleSV, &b_FATjet_DoubleSV);
   fChain->SetBranchAddress("FATnSubSDJet", &FATnSubSDJet, &b_FATnSubSDJet);
   fChain->SetBranchAddress("FATsubjetSDPt", &FATsubjetSDPt, &b_FATsubjetSDPt);
   fChain->SetBranchAddress("FATsubjetSDEta", &FATsubjetSDEta, &b_FATsubjetSDEta);
   fChain->SetBranchAddress("FATsubjetSDPhi", &FATsubjetSDPhi, &b_FATsubjetSDPhi);
   fChain->SetBranchAddress("FATsubjetSDMass", &FATsubjetSDMass, &b_FATsubjetSDMass);
   fChain->SetBranchAddress("FATsubjetSDCSV", &FATsubjetSDCSV, &b_FATsubjetSDCSV);
   fChain->SetBranchAddress("THINnJet", &THINnJet, &b_THINnJet);
   fChain->SetBranchAddress("THINjetPt", &THINjetPt, &b_THINjetPt);
   fChain->SetBranchAddress("THINjetEta", &THINjetEta, &b_THINjetEta);
   fChain->SetBranchAddress("THINjetPhi", &THINjetPhi, &b_THINjetPhi);
   fChain->SetBranchAddress("THINjetMass", &THINjetMass, &b_THINjetMass);
   fChain->SetBranchAddress("THINjetEn", &THINjetEn, &b_THINjetEn);
   fChain->SetBranchAddress("THINgenjetPx", &THINgenjetPx, &b_THINgenjetPx);
   fChain->SetBranchAddress("THINgenjetPy", &THINgenjetPy, &b_THINgenjetPy);
   fChain->SetBranchAddress("THINgenjetPz", &THINgenjetPz, &b_THINgenjetPz);
   fChain->SetBranchAddress("THINgenjetEn", &THINgenjetEn, &b_THINgenjetEn);
   fChain->SetBranchAddress("THINgenjetEM", &THINgenjetEM, &b_THINgenjetEM);
   fChain->SetBranchAddress("THINgenjetHAD", &THINgenjetHAD, &b_THINgenjetHAD);
   fChain->SetBranchAddress("THINgenjetINV", &THINgenjetINV, &b_THINgenjetINV);
   fChain->SetBranchAddress("THINgenjetAUX", &THINgenjetAUX, &b_THINgenjetAUX);
   fChain->SetBranchAddress("THINmatchedDR", &THINmatchedDR, &b_THINmatchedDR);
   fChain->SetBranchAddress("THINjetCorrUncUp", &THINjetCorrUncUp, &b_THINjetCorrUncUp);
   fChain->SetBranchAddress("THINjetCorrUncDown", &THINjetCorrUncDown, &b_THINjetCorrUncDown);
   fChain->SetBranchAddress("THINjetCharge", &THINjetCharge, &b_THINjetCharge);
   fChain->SetBranchAddress("THINjetPartonFlavor", &THINjetPartonFlavor, &b_THINjetPartonFlavor);
   fChain->SetBranchAddress("THINjetPassID", &THINjetPassID, &b_THINjetPassID);
   fChain->SetBranchAddress("THINjet_nSV", &THINjet_nSV, &b_THINjet_nSV);
   fChain->SetBranchAddress("THINjet_SVMass", &THINjet_SVMass, &b_THINjet_SVMass);
   fChain->SetBranchAddress("THINjet_SVEnergyRatio", &THINjet_SVEnergyRatio, &b_THINjet_SVEnergyRatio);
   fChain->SetBranchAddress("THINjetSSV", &THINjetSSV, &b_THINjetSSV);
   fChain->SetBranchAddress("THINjetSSVHE", &THINjetSSVHE, &b_THINjetSSVHE);
   fChain->SetBranchAddress("THINjetCSV", &THINjetCSV, &b_THINjetCSV);
   fChain->SetBranchAddress("THINjetCISVV2", &THINjetCISVV2, &b_THINjetCISVV2);
   fChain->SetBranchAddress("THINjetTCHP", &THINjetTCHP, &b_THINjetTCHP);
   fChain->SetBranchAddress("THINjetTCHE", &THINjetTCHE, &b_THINjetTCHE);
   fChain->SetBranchAddress("THINjetJP", &THINjetJP, &b_THINjetJP);
   fChain->SetBranchAddress("THINjetJBP", &THINjetJBP, &b_THINjetJBP);
   fChain->SetBranchAddress("THINjetTau1", &THINjetTau1, &b_THINjetTau1);
   fChain->SetBranchAddress("THINjetTau2", &THINjetTau2, &b_THINjetTau2);
   fChain->SetBranchAddress("THINjetTau3", &THINjetTau3, &b_THINjetTau3);
   fChain->SetBranchAddress("THINjetTau4", &THINjetTau4, &b_THINjetTau4);
   fChain->SetBranchAddress("THINjetMuEF", &THINjetMuEF, &b_THINjetMuEF);
   fChain->SetBranchAddress("THINjetPhoEF", &THINjetPhoEF, &b_THINjetPhoEF);
   fChain->SetBranchAddress("THINjetCEmEF", &THINjetCEmEF, &b_THINjetCEmEF);
   fChain->SetBranchAddress("THINjetCHadEF", &THINjetCHadEF, &b_THINjetCHadEF);
   fChain->SetBranchAddress("THINjetNEmEF", &THINjetNEmEF, &b_THINjetNEmEF);
   fChain->SetBranchAddress("THINjetNHadEF", &THINjetNHadEF, &b_THINjetNHadEF);
   fChain->SetBranchAddress("THINjetCMulti", &THINjetCMulti, &b_THINjetCMulti);
   fChain->SetBranchAddress("ADDnJet", &ADDnJet, &b_ADDnJet);
   fChain->SetBranchAddress("ADDjetPt", &ADDjetPt, &b_ADDjetPt);
   fChain->SetBranchAddress("ADDjetEta", &ADDjetEta, &b_ADDjetEta);
   fChain->SetBranchAddress("ADDjetPhi", &ADDjetPhi, &b_ADDjetPhi);
   fChain->SetBranchAddress("ADDjetMass", &ADDjetMass, &b_ADDjetMass);
   fChain->SetBranchAddress("ADDjetEn", &ADDjetEn, &b_ADDjetEn);
   fChain->SetBranchAddress("ADDgenjetPx", &ADDgenjetPx, &b_ADDgenjetPx);
   fChain->SetBranchAddress("ADDgenjetPy", &ADDgenjetPy, &b_ADDgenjetPy);
   fChain->SetBranchAddress("ADDgenjetPz", &ADDgenjetPz, &b_ADDgenjetPz);
   fChain->SetBranchAddress("ADDgenjetEn", &ADDgenjetEn, &b_ADDgenjetEn);
   fChain->SetBranchAddress("ADDgenjetEM", &ADDgenjetEM, &b_ADDgenjetEM);
   fChain->SetBranchAddress("ADDgenjetHAD", &ADDgenjetHAD, &b_ADDgenjetHAD);
   fChain->SetBranchAddress("ADDgenjetINV", &ADDgenjetINV, &b_ADDgenjetINV);
   fChain->SetBranchAddress("ADDgenjetAUX", &ADDgenjetAUX, &b_ADDgenjetAUX);
   fChain->SetBranchAddress("ADDmatchedDR", &ADDmatchedDR, &b_ADDmatchedDR);
   fChain->SetBranchAddress("ADDjetCorrUncUp", &ADDjetCorrUncUp, &b_ADDjetCorrUncUp);
   fChain->SetBranchAddress("ADDjetCorrUncDown", &ADDjetCorrUncDown, &b_ADDjetCorrUncDown);
   fChain->SetBranchAddress("ADDjetCharge", &ADDjetCharge, &b_ADDjetCharge);
   fChain->SetBranchAddress("ADDjetPartonFlavor", &ADDjetPartonFlavor, &b_ADDjetPartonFlavor);
   fChain->SetBranchAddress("ADDjetPassID", &ADDjetPassID, &b_ADDjetPassID);
   fChain->SetBranchAddress("ADDjet_nSV", &ADDjet_nSV, &b_ADDjet_nSV);
   fChain->SetBranchAddress("ADDjet_SVMass", &ADDjet_SVMass, &b_ADDjet_SVMass);
   fChain->SetBranchAddress("ADDjet_SVEnergyRatio", &ADDjet_SVEnergyRatio, &b_ADDjet_SVEnergyRatio);
   fChain->SetBranchAddress("ADDjetSSV", &ADDjetSSV, &b_ADDjetSSV);
   fChain->SetBranchAddress("ADDjetSSVHE", &ADDjetSSVHE, &b_ADDjetSSVHE);
   fChain->SetBranchAddress("ADDjetCSV", &ADDjetCSV, &b_ADDjetCSV);
   fChain->SetBranchAddress("ADDjetCISVV2", &ADDjetCISVV2, &b_ADDjetCISVV2);
   fChain->SetBranchAddress("ADDjetTCHP", &ADDjetTCHP, &b_ADDjetTCHP);
   fChain->SetBranchAddress("ADDjetTCHE", &ADDjetTCHE, &b_ADDjetTCHE);
   fChain->SetBranchAddress("ADDjetJP", &ADDjetJP, &b_ADDjetJP);
   fChain->SetBranchAddress("ADDjetJBP", &ADDjetJBP, &b_ADDjetJBP);
   fChain->SetBranchAddress("ADDjetTau1", &ADDjetTau1, &b_ADDjetTau1);
   fChain->SetBranchAddress("ADDjetTau2", &ADDjetTau2, &b_ADDjetTau2);
   fChain->SetBranchAddress("ADDjetTau3", &ADDjetTau3, &b_ADDjetTau3);
   fChain->SetBranchAddress("ADDjetTau4", &ADDjetTau4, &b_ADDjetTau4);
   fChain->SetBranchAddress("ADDjetMuEF", &ADDjetMuEF, &b_ADDjetMuEF);
   fChain->SetBranchAddress("ADDjetPhoEF", &ADDjetPhoEF, &b_ADDjetPhoEF);
   fChain->SetBranchAddress("ADDjetCEmEF", &ADDjetCEmEF, &b_ADDjetCEmEF);
   fChain->SetBranchAddress("ADDjetCHadEF", &ADDjetCHadEF, &b_ADDjetCHadEF);
   fChain->SetBranchAddress("ADDjetNEmEF", &ADDjetNEmEF, &b_ADDjetNEmEF);
   fChain->SetBranchAddress("ADDjetNHadEF", &ADDjetNHadEF, &b_ADDjetNHadEF);
   fChain->SetBranchAddress("ADDjetCMulti", &ADDjetCMulti, &b_ADDjetCMulti);
   fChain->SetBranchAddress("ADDjetPrunedPt", &ADDjetPrunedPt, &b_ADDjetPrunedPt);
   fChain->SetBranchAddress("ADDjetPrunedEta", &ADDjetPrunedEta, &b_ADDjetPrunedEta);
   fChain->SetBranchAddress("ADDjetPrunedPhi", &ADDjetPrunedPhi, &b_ADDjetPrunedPhi);
   fChain->SetBranchAddress("ADDjetPrunedMass", &ADDjetPrunedMass, &b_ADDjetPrunedMass);
   fChain->SetBranchAddress("ADDjetPrunedEn", &ADDjetPrunedEn, &b_ADDjetPrunedEn);
   fChain->SetBranchAddress("ADDjetPrunedCorrUncUp", &ADDjetPrunedCorrUncUp, &b_ADDjetPrunedCorrUncUp);
   fChain->SetBranchAddress("ADDjetPrunedCorrUncDown", &ADDjetPrunedCorrUncDown, &b_ADDjetPrunedCorrUncDown);
   fChain->SetBranchAddress("ADDjetPrunedCharge", &ADDjetPrunedCharge, &b_ADDjetPrunedCharge);
   fChain->SetBranchAddress("ADDjetPrunedPartonFlavor", &ADDjetPrunedPartonFlavor, &b_ADDjetPrunedPartonFlavor);
   fChain->SetBranchAddress("ADDjetPrunedSSV", &ADDjetPrunedSSV, &b_ADDjetPrunedSSV);
   fChain->SetBranchAddress("ADDjetPrunedCSV", &ADDjetPrunedCSV, &b_ADDjetPrunedCSV);
   fChain->SetBranchAddress("ADDjetPrunedTCHP", &ADDjetPrunedTCHP, &b_ADDjetPrunedTCHP);
   fChain->SetBranchAddress("ADDjetPrunedTCHE", &ADDjetPrunedTCHE, &b_ADDjetPrunedTCHE);
   fChain->SetBranchAddress("ADDjetPrunedJP", &ADDjetPrunedJP, &b_ADDjetPrunedJP);
   fChain->SetBranchAddress("ADDjetPrunedJBP", &ADDjetPrunedJBP, &b_ADDjetPrunedJBP);
   fChain->SetBranchAddress("ADDjetSDmass", &ADDjetSDmass, &b_ADDjetSDmass);
   fChain->SetBranchAddress("ADDjetTRmass", &ADDjetTRmass, &b_ADDjetTRmass);
   fChain->SetBranchAddress("ADDjetPRmass", &ADDjetPRmass, &b_ADDjetPRmass);
   fChain->SetBranchAddress("ADDjetFimass", &ADDjetFimass, &b_ADDjetFimass);
   fChain->SetBranchAddress("ADDjet_DoubleSV", &ADDjet_DoubleSV, &b_ADDjet_DoubleSV);
   fChain->SetBranchAddress("ADDnSubSDJet", &ADDnSubSDJet, &b_ADDnSubSDJet);
   fChain->SetBranchAddress("ADDsubjetSDPt", &ADDsubjetSDPt, &b_ADDsubjetSDPt);
   fChain->SetBranchAddress("ADDsubjetSDEta", &ADDsubjetSDEta, &b_ADDsubjetSDEta);
   fChain->SetBranchAddress("ADDsubjetSDPhi", &ADDsubjetSDPhi, &b_ADDsubjetSDPhi);
   fChain->SetBranchAddress("ADDsubjetSDMass", &ADDsubjetSDMass, &b_ADDsubjetSDMass);
   fChain->SetBranchAddress("ADDsubjetSDCSV", &ADDsubjetSDCSV, &b_ADDsubjetSDCSV);
   fChain->SetBranchAddress("hlt_nTrigs", &hlt_nTrigs, &b_hlt_nTrigs);
   fChain->SetBranchAddress("hlt_trigResult", &hlt_trigResult, &b_hlt_trigResult);
   fChain->SetBranchAddress("trigName", &trigName, &b_trigName);
   Notify();
}

Bool_t bkg2_TreeMaker::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void bkg2_TreeMaker::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t bkg2_TreeMaker::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef bkg2_TreeMaker_cxx
