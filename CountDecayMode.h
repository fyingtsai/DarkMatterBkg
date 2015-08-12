class CountDecayMode
{
public:
    int hadDecay=0, lepDecay=0, helfDecay=0;
    int isHadronicW(vector<int> *momid,vector<int> *pid,int genNum);
    int isLeptonicW(vector<int> *momid, vector<int> *pid, int genNum);
    int isNutrino(vector<int> *momid, vector<int> *pid, int genNum);
    int getNumHad(vector<int> *momid, vector<int> *pid, int genNum);
    int getNumlep(vector<int> *momid, vector<int> *pid, int genNum);
    int getNumhalf(vector<int> *momid, vector<int> *pid, int genNum);
    void printNumMode(vector<int> *momid, vector<int> *pid, int genNum);
};

int CountDecayMode::isHadronicW(vector<int> *momid,vector<int> *pid,int genNum){
    int num_had=0;
    for (int i=0;i < genNum; i++){
        if(abs((*momid)[i]) == 24){
            if(abs((*pid)[i]) < 6){
                num_had++;
            }
        }
    }
    return num_had;
}

int CountDecayMode::isLeptonicW(vector<int> *momid, vector<int> *pid, int genNum){
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

int CountDecayMode::isNutrino(vector<int> *momid, vector<int> *pid, int genNum){
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
    if(isHadronicW(momid,pid,genNum)==4)hadDecay++;  
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

void CountDecayMode::printNumMode(vector<int> *momid, vector<int> *pid, int genNum)
{
    cout<<"Leptonic Decay Event Number:"<<getNumlep(momid,pid, genNum)<<endl;
    cout<<"Hadronic Decay Event Number:"<<getNumHad(momid,pid, genNum)<<endl;
    cout<<"1Lep + 1Had Decay Event Number:"<<getNumhalf(momid,pid, genNum)<<endl;
}