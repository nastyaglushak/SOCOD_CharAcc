#ifndef COUNTCHMASS_HPP
#define COUNTCHMASS_HPP

#include <iostream>
#include<vector>
#include<string>
#include<iterator>
#include"socod.hpp"
using namespace std;

class CountCharMass {
public:
    CountCharMass(int ChNum, int CntNum);
    ~CountCharMass();
    vector<int> DataAccum(const vector<int>& dataVec1);
    void DataVectorOut();
    void DataSocodShow();
    void DataAnalyse(vector<int>& dataVec);
    vector<int>* GetData();
private:
    SOCOD *socod;
    CountCharMass *countarr;
    int ChNum; //number of characteristics
    int CntNum;//number of counts
    vector<int>* inData;//address of input data array
    vector<int> inValData;//input data array
};
#endif 