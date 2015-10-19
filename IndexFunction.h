#include <vector>
class IndexFunction
{
public:
    std::vector<TLorentzVector> getGenbMomtopLorentz(Int_t* genParId,Int_t nGenPar,TClonesArray* genParP4,Int_t* genMomParId);
    std::vector<TLorentzVector> getGenBMomBLorentz(Int_t* genParId,Int_t nGenPar,TClonesArray* genParP4,Int_t* genMomParId);
    std::vector<int> indexGenEleMomisTop(Int_t* genMomParId,Int_t* genParId,Int_t nGenPar,Int_t* genParSt);
    std::vector<int> indexRecoEle(Int_t nEle, vector<bool> &eleIsPassLooseNoIso);
    std::vector<int> indexRecoBMomisTopOrB(Int_t nJet,TClonesArray* FatJetP4,Int_t* genParId,Int_t nGenPar,TClonesArray* genParP4,Int_t* genMomParId);
    std::vector<int> indexFatJet(Int_t nJet, Float_t *FATjetCISVV2,TClonesArray* FatJetP4, Float_t pfMetRawPhi,Float_t *FATjetSDmass);
};

std::vector<TLorentzVector> IndexFunction::getGenbMomtopLorentz(Int_t* genParId,Int_t nGenPar,TClonesArray* genParP4,Int_t* genMomParId)
{
    std::vector<TLorentzVector> tlorentz;
    for (int i=0;i < nGenPar; i++){
        if(abs(genParId[i]) == 5){
            if(abs(genMomParId[i])!=6)continue;
            TLorentzVector* thist = (TLorentzVector*)genParP4->At(i);
            tlorentz.push_back(*thist);
        }
    }
    return tlorentz;
}

std::vector<TLorentzVector> IndexFunction::getGenBMomBLorentz(Int_t* genParId,Int_t nGenPar,TClonesArray* genParP4,Int_t* genMomParId)
{
    std::vector<TLorentzVector> blorentz;
    for (int i=0;i < nGenPar; i++){
        if(abs(genParId[i]) == 5){
            if(abs(genMomParId[i])!=5)continue;
            TLorentzVector* thist = (TLorentzVector*)genParP4->At(i);
            blorentz.push_back(*thist);
        }
    }
    return blorentz;
}

std::vector<int> IndexFunction::indexGenEleMomisTop(Int_t* genMomParId,Int_t* genParId,Int_t nGenPar,Int_t* genParSt)
{
    std::vector<int> index;
    for (int i=0;i < nGenPar; i++){
        if(genParSt[i]!=1)continue;
        if(abs(genParId[i]) !=11)continue;
        if(abs(genMomParId[i]) == 6){
            index.push_back(i);
        }
    }
    return index;
}

std::vector<int> IndexFunction::indexRecoEle(Int_t nEle, vector<bool> &eleIsPassLooseNoIso)
{
    std::vector<int> index;
    for (int i=0;i < nEle; i++){
        if(!eleIsPassLooseNoIso[i])continue;
            index.push_back(i);
    }
    return index;
}

std::vector<int> IndexFunction::indexRecoBMomisTopOrB(Int_t nJet,TClonesArray* FatJetP4,Int_t* genParId,Int_t nGenPar,TClonesArray* genParP4,Int_t* genMomParId)
{
    std::vector<int> index;
    IndexFunction gen;
    TLorentzVector maxJet;
    bool match_top = false, match_b = false;
    float NmaxPt = -9999.0;
    for (int ij=0;ij < nJet; ij++){
        TLorentzVector* thisJet = (TLorentzVector*)FatJetP4->At(ij);     
        for(int i=0; i < gen.getGenbMomtopLorentz(genParId,nGenPar,genParP4,genMomParId).size();i++){
            float dR = thisJet->DeltaR(gen.getGenbMomtopLorentz(genParId,nGenPar,genParP4,genMomParId)[i]);
            if(dR <= 0.2) match_top = true;
        }
        for(int i=0; i < gen.getGenBMomBLorentz(genParId,nGenPar,genParP4,genMomParId).size();i++){
            float dR = thisJet->DeltaR(gen.getGenBMomBLorentz(genParId,nGenPar,genParP4,genMomParId)[i]);
            if(dR <= 0.2) match_b = true;
        }
    if(match_top)index.push_back(ij);
    if(match_b)index.push_back(ij);
    }  
    return index;
}

std::vector<int> IndexFunction::indexFatJet(Int_t nJet, Float_t *FATjetCISVV2,TClonesArray* FatJetP4, Float_t pfMetRawPhi,Float_t *FATjetSDmass)
{
    std::vector<int> index;
    for (int ij=0;ij < nJet; ij++){
        TLorentzVector* thisJet = (TLorentzVector*)FatJetP4->At(ij);
        if(thisJet->Pt() < 200)continue;
        if(fabs(thisJet->Eta()) > 2.5)continue;
        if(FATjetCISVV2[ij] < 0.605)continue;
        if(FATjetSDmass[ij]<100 || FATjetSDmass[ij]>150)continue;
        if(fabs(thisJet->Phi() - pfMetRawPhi) < 2.5) continue;
        index.push_back(ij);
    }

    return index;
}
