#include "socod.hpp"

SOCOD::SOCOD(){
    acquiredData=new vector<int>(THRNum*chNum);
    processData=new vector<int>(chNum);
    cout<<"SOCOD Constructor"<<endl;
}
SOCOD::~SOCOD(){
    delete acquiredData;
    delete processData;
    cout<<"SOCOD Destructor"<<endl;
}
void SOCOD::GetRandomData(){
    acquiredData->clear();
    for (int i=0; i != THRNum*chNum; ++i){
        acquiredData->push_back(1+rand()/((RAND_MAX + 1u)/10));
    }
}

void SOCOD::GetDataFromFile(){
    std::string line;
    acquiredData->clear();
	std::ifstream ifile("test.txt", std::ios::in);
	if (ifile.is_open()){
		while (ifile>>line){
			acquiredData->push_back(stof(line));
		}		
	}
	ifile.close();
}
void SOCOD::ProcessData(){
    processData->clear();
    for (int i=0; i<acquiredData->size(); i=i+4){
        //cout<<"i "<<i<<" "<<acquiredData->at(i)<<endl;
        processData->push_back(acquiredData->at(i));
    }
}
vector<int>* SOCOD::GetAccData(){
    return acquiredData;
}
vector<int>* SOCOD::GetProcessData(){
    return processData;
}
void SOCOD::DataVectorOut(){
    cout<<"Data Vector Out "<<endl;
    std::copy(acquiredData->begin(), acquiredData->end(),ostream_iterator<int>(cout, " "));
    cout<<endl;

    cout<<"Data Vector Out after Process"<<endl;
    std::copy(processData->begin(), processData->end(),ostream_iterator<int>(cout, " "));
    cout<<endl;
}