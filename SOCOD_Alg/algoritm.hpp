#ifndef ALGOTITM_HPP
#define ALGOTITM_HPP
/*Algorithm stages:
0. Loading of counting characteristics data (x=96, y=numbers of counts); (LoadDataArray)
1. Seaching 50% of counts; (SeachFifthCounts)
2. Sliding window method; (SlideWindow)
3. Counting corrections codes (CountCorCode)
////////////////////////////////////////
There are two types of algorithm: using global THR and using individual THR
*/
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <stack>

using namespace std;

const int GlTHR=256;
const int InTHR=64;

const int row = 2;
const int column = 5;

pair<int,float> FifthCounts(float mass[], int size, float ref);
float** DataArray(float datamas[]);
float* THRarr(int size, int thrStep);
double logbase(double a, double base);
float* DataInput ();

#endif