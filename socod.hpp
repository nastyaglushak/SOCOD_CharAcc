#ifndef SOCOD_HPP
#define SOCOD_HPP

#include <iostream>
#include<vector>
#include<string>
#include <fstream>
using namespace std;

class SOCOD{
    private:
        vector<int> acquiredDataVec;
        vector<int> processDataVec;
        vector<int>* processData;//output vector data
        vector<int>* acquiredData;//vector to save in accumulator
        int channelNum=4;
        int frameNum=5;
    public:
        SOCOD();
        ~SOCOD();
        void GetData(vector<int>& acquiredDataVec);
        vector<int> ProcessData(const vector<int>& acquiredDataVec);
        vector<int>* GetAccData();
        vector<int>* GetProcessData();
};
#endif