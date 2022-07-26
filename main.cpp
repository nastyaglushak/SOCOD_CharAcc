#include"countchmass.hpp"
#include"socod.hpp"

void PrintData(vector<int> dataIn, string mes);

int main(){
    SOCOD TestSocod;
    //Test of SOCOD class
    for(int i=0; i<5; ++i){
        std::cout<<"Iter "<<i<<endl;
        TestSocod.GetRandomData();
        TestSocod.ProcessData();
        TestSocod.DataVectorOut();
    }
    return 0;
}

void PrintData(vector<int> dataIn, string mes){
    cout<<mes<<endl;
    for (int s: dataIn){
        cout<<s<<" ";
    } 
    cout<<endl;
}
