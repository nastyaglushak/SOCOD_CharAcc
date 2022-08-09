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
#include<iterator>
#include <algorithm>
#include <numeric>

using namespace std;

const int GlTHR=256;
const int InTHR=64;

class Algorithm{
    private:
        struct AlgoritmParameters{
            int ArrSize;//full number of input array 
            int THRStep;//full range divide to cntNum
            int IterNum;//how many iterration you should for seaching 50% of counts
        } alPar;

        const int chNum=4;//number of channnels
        int cntNum;//number of counts in one characteristics

        vector<vector<int>> *inData; //two-dimensional array of input data
        vector<int> *allCntChar;//one-dimensional array of input data
        vector<int> *thrArr;
    public:
        Algorithm();
        ~Algorithm();
        void LoadDataFile();
        void SetAlPar();
        void SetTHRArr();
        void PerformInData();
        void SetCntNum(int cntNum);//return numbers of one characteristic (find from input array)
        void ShowOneXData(vector<int>& data, string mes);
        void ShowTwoXData(vector<vector<int>>& data, string mes);
        int SeachFifthCounts(float refValue);//refValue-value, which the seaching starts
        
        void SlideWindow(int wSize);
        void CountCorCode();    
};

#endif