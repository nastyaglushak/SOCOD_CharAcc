#ifndef ALGOTITM_HPP
#define ALGOTITM_HPP
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