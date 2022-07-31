#ifndef SOCOD_HPP
#define SOCOD_HPP

#include <iostream>
#include<vector>
#include<string>
#include <fstream>
#include<iterator>

using namespace std;

class SOCOD{
    private:
        vector<int>* processData;//output vector data
        vector<int>* acquiredData;//vector to save in accumulator
        const int THRNum=4;//number of THR
        const int chNum=96;//number of channels
    public:
        SOCOD();
        ~SOCOD();
        int GetChNum();
        void GetDataFromFile();
        void GetRandomData();
        void ProcessData();
        void DataVectorOut();
        vector<int>* GetAccData();
        vector<int>* GetProcessData();
};
#endif