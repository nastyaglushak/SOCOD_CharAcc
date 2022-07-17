#include"countchmass.hpp"
#include <fstream>

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
    for (int i=0; i<CntNum; i++){
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

void CountCharMass::DataVectorOut(){
    cout<<"Data Vector Out"<<endl;
    for (int i:inValData){
        cout<<inValData[i-1]<<" ";//Why does this vector shift by -1? Don't want to use the shift to "-1"
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

int main(){
    CountCharMass ChArray(5, 10);
    cout<<"First iter: "<<ChArray.GetChNum()<<" "<<ChArray.GetCntNum()<<"\n"<<endl;

    vector<int> dataVec;
    ChArray.DataGen(dataVec);

    cout<<"DataVec Out"<<endl;
    for (int s: dataVec){
        cout<<s<<" ";
    }
    cout<<endl;

    vector<int> dataVec2={1,2,3,4,5};
    cout<<"Data Analyse Check "<<ChArray.DataAnalyse(dataVec2)<<endl;

    ChArray.DataVectorOut();

    //Reading values from file
    /*ifstream ifile ("test.txt", ios::in);
    string line;
    vector<int> inData;
    if (ifile.is_open()){
		while (ifile>>line){
			inData.push_back(stof(line));
		}	
    }

    for (int s: inData){
        cout<<s<<"\n";
    }
	ifile.close();*/
    return 0;
}

