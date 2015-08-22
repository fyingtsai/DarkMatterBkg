class CountDecayMode
{
public:
    int hadDecay=0, lepDecay=0, helfDecay=0;
    int isHadronicW(vector<int> *momid,vector<int> *pid,int genNum);
    int isBjet(vector<int> *momid,vector<int> *pid,int genNum);
    int isLeptonicW(vector<int> *momid, vector<int> *pid, int genNum);
    int isEleW(vector<int> *momid, vector<int> *pid, int genNum);
    int isMuonW(vector<int> *momid, vector<int> *pid, int genNum);
    int isTauW(vector<int> *momid, vector<int> *pid, int genNum);
    int isNutrino(vector<int> *momid, vector<int> *pid, int genNum);
    int getNumHad(vector<int> *momid, vector<int> *pid, int genNum);
    int getNumlep(vector<int> *momid, vector<int> *pid, int genNum);
    int getNumhalf(vector<int> *momid, vector<int> *pid, int genNum);
    int getInteger(vector<int> *momid, vector<int> *pid, int genNum);
};

int CountDecayMode::isHadronicW(vector<int> *momid,vector<int> *pid,int genNum)
{
    int num_had=0;
    for (int i=0;i < genNum; i++){
        if(abs((*momid)[i]) == 24){
            if(abs((*pid)[i]) < 6){
                num_had++;
            }
        }
    }
    // cout<<" njet(from W):"<<num_had<<endl;
    return num_had;
}

int CountDecayMode::isBjet(vector<int> *momid,vector<int> *pid,int genNum)
{
    int num_bjet=0;
    for (int i=0;i < genNum; i++){
        if(abs((*momid)[i]) == 6){
            if(abs((*pid)[i]) == 5){
                num_bjet++;
            }
        }
    }
    // cout<<"nbjet(from Top):"<<num_bjet;
    return num_bjet;
}

int CountDecayMode::isEleW(vector<int> *momid, vector<int> *pid, int genNum)
{
    int num_lep=0;
    for (int i=0;i < genNum; i++){
        if(abs((*momid)[i]) == 24){
            if(abs((*pid)[i]) == 11){
                num_lep++;
            }
        }
    }
   // cout<<" nele(from W):"<<num_lep;
    return num_lep;
}

int CountDecayMode::isMuonW(vector<int> *momid, vector<int> *pid, int genNum)
{
    int num_lep=0;
    for (int i=0;i < genNum; i++){
        if(abs((*momid)[i]) == 24){
            if(abs((*pid)[i]) == 13){
                num_lep++;
            }
        }
    }
    // cout<<" nMuon(from W):"<<num_lep;
    return num_lep;
}

int CountDecayMode::isTauW(vector<int> *momid, vector<int> *pid, int genNum)
{
    int num_lep=0;
    for (int i=0;i < genNum; i++){
        if(abs((*momid)[i]) == 24){
            if(abs((*pid)[i]) == 15){
                num_lep++;
            }
        }
    }
    // cout<<" nTau(from W):"<<num_lep;
    return num_lep;
}

int CountDecayMode::isLeptonicW(vector<int> *momid, vector<int> *pid, int genNum)
{
    int num_lep=0;
    for (int i=0;i < genNum; i++){
        if(abs((*momid)[i]) == 24){
            if(abs((*pid)[i]) == 11 || abs((*pid)[i]) == 13 || abs((*pid)[i]) ==15){
                num_lep++;
            }
        }
    }    
    return num_lep;
}

int CountDecayMode::isNutrino(vector<int> *momid, vector<int> *pid, int genNum)
{
    int num_neu=0;
    for (int i=0;i < genNum; i++){
        if(abs((*momid)[i]) == 24){
            if(abs((*pid)[i]) == 12 || abs((*pid)[i]) == 14 || abs((*pid)[i]) ==16){
                num_neu++;
            }
        }
    }
    return num_neu;
}

int CountDecayMode::getNumHad(vector<int> *momid, vector<int> *pid, int genNum)
{
    if(isHadronicW(momid,pid,genNum)==4){
        hadDecay++; 
    }
    return hadDecay;
}

int CountDecayMode::getNumlep(vector<int> *momid, vector<int> *pid, int genNum)
{   
    if(isLeptonicW(momid,pid,genNum)==2 && isNutrino(momid,pid,genNum)==2)lepDecay++;  
    return lepDecay;
}

int CountDecayMode::getNumhalf(vector<int> *momid, vector<int> *pid, int genNum)
{
    if(isHadronicW(momid,pid,genNum)==2 && isLeptonicW(momid,pid,genNum)==1 && isNutrino(momid,pid,genNum)==1)helfDecay++;  
    return helfDecay;
}

int CountDecayMode::getInteger(vector<int> *momid, vector<int> *pid, int genNum)
{
    if(isBjet(momid,pid,genNum)==2 && isEleW(momid,pid,genNum)==2 && isMuonW(momid,pid,genNum)==0 && isTauW(momid,pid,genNum)==0 && isHadronicW(momid,pid,genNum)==0 ){
        return 1;
    }else if (isBjet(momid,pid,genNum)==2 && isEleW(momid,pid,genNum)==0 && isMuonW(momid,pid,genNum)==2 && isTauW(momid,pid,genNum)==0 && isHadronicW(momid,pid,genNum)==0 ){
        return 2;
    }else if (isBjet(momid,pid,genNum)==2 && isEleW(momid,pid,genNum)==0 && isMuonW(momid,pid,genNum)==0 && isTauW(momid,pid,genNum)==2 && isHadronicW(momid,pid,genNum)==0 ){
        return 3;
    }else if (isBjet(momid,pid,genNum)==2 && isEleW(momid,pid,genNum)==1 && isMuonW(momid,pid,genNum)==1 && isTauW(momid,pid,genNum)==0 && isHadronicW(momid,pid,genNum)==0 ){
        return 4;
    }else if (isBjet(momid,pid,genNum)==2 && isEleW(momid,pid,genNum)==1 && isMuonW(momid,pid,genNum)==0 && isTauW(momid,pid,genNum)==1 && isHadronicW(momid,pid,genNum)==0 ){
        return 5;
    }else if (isBjet(momid,pid,genNum)==2 && isEleW(momid,pid,genNum)==0 && isMuonW(momid,pid,genNum)==1 && isTauW(momid,pid,genNum)==1 && isHadronicW(momid,pid,genNum)==0 ){
        return 6;
    }else if (isBjet(momid,pid,genNum)==2 && isEleW(momid,pid,genNum)==1 && isMuonW(momid,pid,genNum)==0 && isTauW(momid,pid,genNum)==0 && isHadronicW(momid,pid,genNum)==2 ){
        return 7;
    }else if (isBjet(momid,pid,genNum)==2 && isEleW(momid,pid,genNum)==0 && isMuonW(momid,pid,genNum)==1 && isTauW(momid,pid,genNum)==0 && isHadronicW(momid,pid,genNum)==2 ){
        return 8;
    }else if (isBjet(momid,pid,genNum)==2 && isEleW(momid,pid,genNum)==0 && isMuonW(momid,pid,genNum)==0 && isTauW(momid,pid,genNum)==1 && isHadronicW(momid,pid,genNum)==2 ){
        return 9;
    }else if (isBjet(momid,pid,genNum)==2 && isEleW(momid,pid,genNum)==0 && isMuonW(momid,pid,genNum)==0 && isTauW(momid,pid,genNum)==0 && isHadronicW(momid,pid,genNum)==4 ){
        return 10;
    }else 
        return 11;
}
