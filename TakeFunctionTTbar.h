class TakeFunctionTTbar
{
public:
    int numEle(TreeReader &data,TLorentzVector* maxFJet);
    int numMuon(TreeReader &data,TLorentzVector* maxFJet);
    int numTau(TreeReader &data,TLorentzVector* maxFJet);
    int numThinJet(TreeReader &data,TLorentzVector* maxFJet);
    int getFatJetIndex(TreeReader &data);
    TLorentzVector getQCDJetTLorentz(TreeReader &data,TLorentzVector* maxFJet);
    TLorentzVector getSecondFatJetLorentz(TreeReader &data,TLorentzVector* maxFJet);
    bool isPassPhiMETFJet(TreeReader &data,TLorentzVector* maxFJet);
};

#define m_pi         3.1415
static Float_t DeltaPhi(Float_t phi1, Float_t phi2){
    double result = phi1 - phi2;
    if(result>m_pi) result -= 2*m_pi;
    else if (result <= -m_pi) result += 2*m_pi ;
    else result = result;
    return result;
  }

int TakeFunctionTTbar::getFatJetIndex(TreeReader &data)
{
    const TClonesArray* FatJetP4 = (TClonesArray*) data.GetPtrTObject("FATjetP4");
    const Int_t nJet             = data.GetInt("FATnJet");
    const vector<bool> &FATjetPassIDLoose = *((vector<bool>*) data.GetPtr("FATjetPassIDLoose"));
    const vector<float> *FATsubjetSDCSV  = data.GetPtrVectorFloat("FATsubjetSDCSV");
    const Float_t *FATjetPRmassL2L3Corr  = data.GetPtrFloat("FATjetPRmassL2L3Corr");
    float maxFJPt = -9999.0;
    int maxFJetIndex = -1;
    for(int ij=0; ij< nJet; ij++){
        TLorentzVector* thisJet = (TLorentzVector*)FatJetP4->At(ij);
        if(thisJet->Pt() < 200)continue;
        if(fabs(thisJet->Eta()) > 2.4)continue;
        if(!FATjetPassIDLoose[ij])continue;
        // if(FATsubjetSDCSV->size()<2)continue;
        // if(FATsubjetSDCSV[ij][0] < 0.605)continue;
        // if(FATsubjetSDCSV[ij][1] < 0.605)continue;
        if(FATjetPRmassL2L3Corr[ij]<30 || FATjetPRmassL2L3Corr[ij]>250)continue;
        if(thisJet->Pt() > maxFJPt){
            maxFJPt = thisJet->Pt();
            maxFJetIndex = ij;
          }
    }//FatJet
    return maxFJetIndex;
}

TLorentzVector TakeFunctionTTbar::getSecondFatJetLorentz(TreeReader &data,TLorentzVector* maxFJet)
{
    const TClonesArray* FatJetP4 = (TClonesArray*) data.GetPtrTObject("FATjetP4");
    const Int_t nJet             = data.GetInt("FATnJet");
    const vector<bool> &FATjetPassIDLoose = *((vector<bool>*) data.GetPtr("FATjetPassIDLoose"));
    const vector<float> *FATsubjetSDCSV  = data.GetPtrVectorFloat("FATsubjetSDCSV");
    const Float_t *FATjetPRmassL2L3Corr  = data.GetPtrFloat("FATjetPRmassL2L3Corr");
    float secondFJPt = -9999.0;
    TLorentzVector secondFJet;
    TakeFunctionTTbar func;
    for(int ij=0; ij< nJet; ij++){
        TLorentzVector* thisJet = (TLorentzVector*)FatJetP4->At(ij);
        if(thisJet->Pt() < 200)continue;
        if(fabs(thisJet->Eta()) > 2.4)continue;
        if(!FATjetPassIDLoose[ij])continue;
        // if(FATsubjetSDCSV->size()<2)continue;
        // if(FATsubjetSDCSV[ij][0] < 0.605)continue;
        // if(FATsubjetSDCSV[ij][1] < 0.605)continue;
        if(FATjetPRmassL2L3Corr[ij]<30 || FATjetPRmassL2L3Corr[ij]>250)continue;
        if(thisJet->Pt() > secondFJPt){
            if(ij==func.getFatJetIndex(data))continue;
            secondFJPt = thisJet->Pt();
            secondFJet = *thisJet;
          }
    }//FatJet
    return secondFJet;
}

TLorentzVector TakeFunctionTTbar::getQCDJetTLorentz(TreeReader &data,TLorentzVector* maxFJet)
{
    const TClonesArray* THINjetP4 = (TClonesArray*) data.GetPtrTObject("THINjetP4");
    const Int_t THINnJet             = data.GetInt("THINnJet");
    const vector<bool> &THINjetPassIDLoose = *((vector<bool>*) data.GetPtr("THINjetPassIDLoose"));
    float maxQCDJPt = -9999.0;
    TLorentzVector maxQCDJet;
    TakeFunctionTTbar func;
    for(int i=0; i<THINnJet;i++){
        TLorentzVector* thisJet = (TLorentzVector*)THINjetP4->At(i);
        if(thisJet->Pt() < 30)continue;
        if(fabs(thisJet->Eta()) > 2.4)continue;
        if(!THINjetPassIDLoose[i])continue;
        if(maxFJet->DeltaR(*thisJet) > 0.8){
        if(thisJet->Pt() > maxQCDJPt){
            maxQCDJPt = thisJet->Pt();
            maxQCDJet = *thisJet;
          }
        }else if(func.getSecondFatJetLorentz(data,maxFJet).Pt()!=0 && func.getSecondFatJetLorentz(data,maxFJet).DeltaR(*thisJet)>0.8){
          if(thisJet->Pt() > maxQCDJPt){
            maxQCDJPt = thisJet->Pt();
            maxQCDJet = *thisJet;
          }
        }
    }
    return maxQCDJet;
}

int TakeFunctionTTbar::numThinJet(TreeReader &data,TLorentzVector* maxFJet)
{
    const Float_t *THINjetCISVV2  = data.GetPtrFloat("THINjetCISVV2");
    const TClonesArray* THINjetP4 = (TClonesArray*) data.GetPtrTObject("THINjetP4");
    const Int_t THINnJet             = data.GetInt("THINnJet");
    const vector<bool> &THINjetPassIDLoose = *((vector<bool>*) data.GetPtr("THINjetPassIDLoose"));
    int nThinJet=0;
    TakeFunctionTTbar func;
    for(int i=0; i<THINnJet;i++){
       TLorentzVector* thisJet = (TLorentzVector*)THINjetP4->At(i);
        if(thisJet->Pt() < 30)continue;
        if(fabs(thisJet->Eta()) > 2.4)continue; 
        if(THINjetCISVV2[i] < 0.605)continue;
        if(!THINjetPassIDLoose[i])continue;
        if(maxFJet->DeltaR(*thisJet) > 0.8)
        nThinJet++;
          else if(func.getSecondFatJetLorentz(data,maxFJet).Pt()!=0 && func.getSecondFatJetLorentz(data,maxFJet).DeltaR(*thisJet)>0.8)
            nThinJet++;
    }
    return nThinJet;
}

int TakeFunctionTTbar::numEle(TreeReader &data,TLorentzVector* maxFJet)
{
    const TClonesArray* eleP4 = (TClonesArray*) data.GetPtrTObject("eleP4");
    const Int_t nEle             = data.GetInt("nEle");
    const vector<bool> &eleIsPassLoose = *((vector<bool>*) data.GetPtr("eleIsPassLoose"));
    int num_Ele=0;
    TakeFunctionTTbar func;
    for(int ie=0;ie<nEle;ie++){
      TLorentzVector* thisEle = (TLorentzVector*)eleP4->At(ie);
      if(thisEle->Pt() < 10)continue;
      if(fabs(thisEle->Eta()) > 2.5)continue;
      if(!eleIsPassLoose[ie])continue;
      if(maxFJet->DeltaR(*thisEle) > 0.8)
      num_Ele++;
        else if(func.getSecondFatJetLorentz(data,maxFJet).Pt()!=0 && func.getSecondFatJetLorentz(data,maxFJet).DeltaR(*thisEle)>0.8)
          num_Ele++;
    }//Ele loop
    return num_Ele;
}

int TakeFunctionTTbar::numMuon(TreeReader &data,TLorentzVector* maxFJet)
{
    const TClonesArray* muP4 = (TClonesArray*) data.GetPtrTObject("muP4");
    const Int_t nMu             = data.GetInt("nMu");
    const vector<bool> &isLooseMuon = *((vector<bool>*) data.GetPtr("isLooseMuon"));
    const Float_t *muChHadIso  = data.GetPtrFloat("muChHadIso");
    const Float_t *muNeHadIso  = data.GetPtrFloat("muNeHadIso");
    const Float_t *muGamIso  = data.GetPtrFloat("muGamIso");
    int num_Mu=0;
    TakeFunctionTTbar func;
    for(int im=0;im<nMu;im++){
      TLorentzVector* thisMu = (TLorentzVector*)muP4->At(im);
      bool iso = (muChHadIso[im]+muNeHadIso[im]+muGamIso[im])/thisMu->Pt();
      if(thisMu->Pt() < 10)continue;
      if(fabs(thisMu->Eta()) > 2.5)continue;
      if(!isLooseMuon[im])continue;
      if(iso > 0.4)continue;
      if(maxFJet->DeltaR(*thisMu) > 0.8)
      num_Mu++;
        else if(func.getSecondFatJetLorentz(data,maxFJet).Pt()!=0 && func.getSecondFatJetLorentz(data,maxFJet).DeltaR(*thisMu)>0.8)
          num_Mu++;
    }//Muon loop
    return num_Mu;
}

int TakeFunctionTTbar::numTau(TreeReader &data,TLorentzVector* maxFJet)
{
    const TClonesArray* HPSTau_4Momentum = (TClonesArray*) data.GetPtrTObject("HPSTau_4Momentum");
    const Int_t HPSTau_n             = data.GetInt("HPSTau_n");
    const vector<bool> &disc_decayModeFinding = *((vector<bool>*) data.GetPtr("disc_decayModeFinding"));
    const vector<bool> &disc_byLooseIsolationMVA3newDMwLT = *((vector<bool>*) data.GetPtr("disc_byLooseIsolationMVA3newDMwLT"));
    int num_tau=0;
    TakeFunctionTTbar func;
    for(int it=0;it<HPSTau_n;it++){
      TLorentzVector* thisTau = (TLorentzVector*)HPSTau_4Momentum->At(it);
      if(thisTau->Pt() < 20)continue;
      if(fabs(thisTau->Eta()) > 2.3)continue;
      if(!disc_decayModeFinding[it])continue;
      if(!disc_byLooseIsolationMVA3newDMwLT[it])continue;
      if(maxFJet->DeltaR(*thisTau) > 0.8 )
      num_tau++;
        else if(func.getSecondFatJetLorentz(data,maxFJet).Pt()!=0 && func.getSecondFatJetLorentz(data,maxFJet).DeltaR(*thisTau)>0.8)
          num_tau++;
    }//Tau loop
    return num_tau;
}

bool TakeFunctionTTbar::isPassPhiMETFJet(TreeReader &data,TLorentzVector* maxFJet)
{
    const Float_t pfMetCorrPhi    = data.GetFloat("pfMetCorrPhi");
    bool isPass = false;
    TakeFunctionTTbar func;
    if(fabs(DeltaPhi(maxFJet->Phi(),pfMetCorrPhi))>2.5)
      isPass = true;
      else if(func.getSecondFatJetLorentz(data,maxFJet).Pt()!=0 && fabs(DeltaPhi(func.getSecondFatJetLorentz(data,maxFJet).Phi(),pfMetCorrPhi))>2.5)
        isPass = true;
    return isPass;
}


