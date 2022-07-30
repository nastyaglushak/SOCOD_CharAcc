#include"countchmass.hpp"
#include"socod.hpp"

CountCharMass::CountCharMass(int ChNum, int CntNum){
    cout<<"Class Constructor"<<endl;
    this->socod=new SOCOD();
    this->ChNum=ChNum;
    this->CntNum=CntNum;
    inData=new vector<int>(CntNum);
}

CountCharMass::~CountCharMass(){
    delete inData;
    cout<<"Class Destructor"<<endl;
}

void CountCharMass::DataSocodShow(){
    cout<<"SOCOD Data"<<endl;
    socod->GetRandomData();
    socod->ProcessData();
    socod->DataVectorOut();
    cout<<endl;
}
vector<int> CountCharMass::DataAccum(const vector<int>& dataVec1) {
    for(size_t i=0; i<dataVec1.size(); ++i){
        cout<<dataVec1[i]<<" "<<inValData[i]<<" "<<i<<endl;
        inValData[i]+=dataVec1[i];
    }
    return inValData;
}

void CountCharMass::DataVectorOut(){
    cout<<"Data Vector Out"<<endl;
    copy(inValData.begin(), inValData.end(),ostream_iterator<int>(cout, " "));
    cout<<endl;

    cout<<"Data Vector Out (Show Adress)"<<endl;
    copy(inData->begin(), inData->end(),ostream_iterator<int>(cout, " "));
    cout<<endl;
}

void CountCharMass::DataAnalyse(vector<int>& dataVec){
    for (const int& s: dataVec){
        inData->push_back(s);
        inValData.push_back(s);
    }
}

vector<int>* CountCharMass::GetData(){
    return inData;
}

