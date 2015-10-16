#include <vector>
class IndexFunction
{
public:
    std::vector<int> indexGenEleMomisTop(Int_t* genMomParId,Int_t* genParId,Int_t nGenPar,Int_t* genParSt);
};

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