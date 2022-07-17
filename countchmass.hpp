#include <iostream>
#include<vector>
#include<string>
using namespace std;

class CountCharMass {
public:
    CountCharMass(int ChNum, int CntNum);
    ~CountCharMass();
    int GetChNum();
    int GetCntNum();
    void DataGen(vector<int>& dataVec);
    int DataAnalyse(vector<int>& dataVec);
    void DataVectorOut();
    vector<int>* GetData();
private:
    int ChNum; //number of characteristics
    int CntNum;//number of counts
    vector<int>* inData;//address of input data array
    vector<int> inValData;//input data array
};