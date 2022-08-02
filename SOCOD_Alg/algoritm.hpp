#ifndef ALGORITM_HPP
#define ALGORITM_HPP
/*Algorithm stages:
0. Loading of counting characteristics data (x=96, y=numbers of counts); (LoadDataArray)
1. Seaching 50% of counts; (SeachFifthCounts)
2. Sliding window method; (SlideWindow)
3. Counting corrections codes (CountCorCode)
////////////////////////////////////////
There are two types of algorithm: using global THR and using individual THR
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <stack>

using namespace std;

const int GlTHR=256;
const int InTHR=64;

class Algorithm{
    private:
        const int chNum=96;
        int cntNum;
        int thrArrSize;
        vector<vector<int>> *inData; //two-dimensional array of input data
        vector<int> *allCntChar;//one-dimensional array of input data
        vector<int> *thrArr;
    public:
        Algorithm();
        ~Algorithm();
        void LoadDataFile ();
        int LoadDataArray();
        void SetTHRArr(int size, int step);
        void SetCntNum(int cntNum);
        
        int SeachFifthCounts(int refValue, vector<int> dataIn);
        void SlideWindow(int wSize);
        void CountForCode();
};

double logbase(double a, double base){return log(a) / log(base);};

#endif