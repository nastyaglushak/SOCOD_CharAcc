#include"countchmass.hpp"
#include"socod.hpp"

void PrintData(vector<int> dataIn, string mes);

int main(){
    CountCharMass TestClass(4,5);
    TestClass.DataAccum();
    return 0;
}

void PrintData(vector<int> dataIn, string mes){
    cout<<mes<<endl;
    for (int s: dataIn){
        cout<<s<<" ";
    } 
    cout<<endl;
}
