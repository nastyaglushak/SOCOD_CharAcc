#include"countchmass.hpp"

CountCharMass::CountCharMass(int ChNum, int CntNum){
    cout<<"Class Constructor"<<endl;
    this->ChNum=ChNum;
    this->CntNum=CntNum;
    inData=new vector<int>(CntNum);
}

CountCharMass::~CountCharMass(){
    delete inData;
    cout<<"Class Destructor"<<endl;
}

int CountCharMass::GetChNum(){
    return ChNum;
}

int CountCharMass::GetCntNum(){
    return CntNum;
}

void CountCharMass::DataGen(vector<int>& dataVec){
    for (int i=0; i<CntNum; ++i){
        dataVec.push_back(i);
    }
}

int CountCharMass::DataAnalyse(vector<int>& dataVec){
    int cnt=0;
    for (const int& s: dataVec){
        inData->push_back(s);
        inValData.push_back(s);
        cnt++;
    }
    return cnt;
}

vector<int>* CountCharMass::GetData(){
    return inData;
}

vector<int> CountCharMass::DataAccum(const vector<int>& dataVec1) {
    for(size_t i=0; i<dataVec1.size(); ++i){
        cout<<dataVec1[i]<<" "<<inValData[i]<<" "<<i<<endl;
        inValData[i]+=dataVec1[i];
    }
    return inValData;
}

//Problems with output
void CountCharMass::DataVectorOut(){
    cout<<"Data Vector Out"<<endl;
    for (int i:inValData){
        cout<<inValData[i]<<" ";
    }
    cout<<endl;

    cout<<"Data Vector Out (Show Adress)"<<endl;
    vector<int>::iterator cnt;
    cnt=inData->begin();
    for (; cnt != inData->end(); cnt++){
        cout<<" "<< inData;// How to show what is written in this vector?
    }
    cout<<endl;
}


