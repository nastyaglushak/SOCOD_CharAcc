#include "socod.hpp"

SOCOD::SOCOD(){
    acquiredData=new vector<int>(channelNum*frameNum);
    processData=new vector<int>(channelNum*frameNum/4);
    cout<<"SOCOD Constructor"<<endl;
}
SOCOD::~SOCOD(){
    delete acquiredData;
    delete processData;
    cout<<"SOCOD Destructor"<<endl;
}
void SOCOD::GetData(vector<int>& acquiredDataVec){
    string line;
    acquiredData->clear();
	ifstream ifile("test.txt", ios::in);
	if (ifile.is_open()){
		while (ifile>>line){
			acquiredData->push_back(stof(line));
            acquiredDataVec.push_back(stof(line));
		}		
	}
	ifile.close();
}
vector<int> SOCOD::ProcessData(const vector<int>& acquiredDataVec){
    for (int i=0; i<acquiredData->size(); i=i+4){
        processData->push_back(acquiredData->at(i));
    }
    for (int i=0; i<acquiredDataVec.size(); i=i+4){
        processDataVec.push_back(acquiredDataVec[i]);
    }
    return processDataVec;
}

vector<int>* SOCOD::GetAccData(){
    return acquiredData;
}
vector<int>* SOCOD::GetProcessData(){
    return processData;
}