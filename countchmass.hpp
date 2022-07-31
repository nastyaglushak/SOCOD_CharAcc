#ifndef COUNTCHMASS_HPP
#define COUNTCHMASS_HPP

#include <iostream>
#include<vector>
#include<string>
#include<iterator>
#include"socod.hpp"
using namespace std;

/*One Frame Format (Number of Frames (set by the user))
->chNum (0..96)->
|CntNum (max 255)
////////////////////////////////
Data Repository Structure (accumData=oneAccumData*CntNum)
->oneAccumData (CntNum=0)->
->oneAccumData (CntNum=1)->
..............
*/

class CountCharMass {
public:
    CountCharMass(int FrNum, int CntNum);
    ~CountCharMass();
    void GetDataSocod();
    void OneDataAccum();
    void DataAccum();
    void CreateZeroVector();
    void ShowData();
    vector<int>* GetAccumData();
private:
    SOCOD *socod;
    int FrNum; //number of characteristics
    int CntNum;//number of counts
    vector<int>* inData;//input data array
    vector<int>* oneAccumData;
    vector<int>* accumData;//data array accumulator
};
#endif 