#include"countchmass.hpp"

int main(){
    CountCharMass ChArray(5, 10);
    cout<<"First iter: "<<ChArray.GetChNum()<<" "<<ChArray.GetCntNum()<<"\n"<<endl;

    vector<int> dataVec;
    ChArray.DataGen(dataVec);

    cout<<"DataVec Out"<<endl;
    for (int s: dataVec){
        cout<<s<<" ";
    }
    cout<<endl;

    vector<int> dataVec2={1,2,3,4,5};
    cout<<"Data Analyse Check "<<ChArray.DataAnalyse(dataVec2)<<endl;

    ChArray.DataVectorOut();

    vector<int> dataVec3={1,2,3,4,5};

    ChArray.DataAccum(dataVec3);
    ChArray.DataVectorOut();

    ChArray.DataAccum(dataVec2);
    ChArray.DataVectorOut();

    return 0;
}
