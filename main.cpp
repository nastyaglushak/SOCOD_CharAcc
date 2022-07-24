#include"countchmass.hpp"
#include"socod.hpp"
#include<cstdlib>

void PrintData(vector<int> dataIn, string mes);
void RandVecGen(vector<int> &vecIn, int len);

int main(){
    CountCharMass ChArray(5, 10);
    SOCOD TestSOCOD;

    vector<int> testvec, testvec2;
    TestSOCOD.GetData(testvec);
    testvec2=TestSOCOD.ProcessData(testvec);

    PrintData(testvec, "TestOutVec");
    PrintData(testvec2,"TestOutVec Before Process");

    vector<int> testgenvec;
    RandVecGen(testgenvec, 5);
    PrintData(testgenvec,"Gen Test Vec");

    cout<<"-------------"<<endl;

    vector<int> dataVec;
    ChArray.DataGen(dataVec);

    PrintData(dataVec, "DataVec Out");

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

void PrintData(vector<int> dataIn, string mes){
    cout<<mes<<endl;
    for (int s: dataIn){
        cout<<s<<" ";
    } 
    cout<<endl;
}

void RandVecGen(vector<int> &vecIn, int len){
    for (int i=0; i != len; ++i){
        vecIn.push_back(1+rand()/((RAND_MAX + 1u)/10));
    }
}