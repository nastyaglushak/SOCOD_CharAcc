#include"countchmass.hpp"
#include"socod.hpp"

CountCharMass::CountCharMass(int FrNum, int CntNum){
    cout<<"Class Constructor"<<endl;
    this->socod=new SOCOD();
    this->FrNum=FrNum;
    this->CntNum=CntNum;
    inData=new vector<int>(socod->GetChNum());
    //accumData=new vector<int>(CntNum*(socod->GetChNum()));
    accumData=new vector<int>();
    oneAccumData=new vector<int>(socod->GetChNum()); 
}

CountCharMass::~CountCharMass(){
    delete inData;
    delete accumData;
    delete oneAccumData;
    cout<<"Class Destructor"<<endl;
}

void CountCharMass::GetDataSocod(){
    inData->clear();
    //cout<<"SOCOD Data"<<endl;
    socod->GetRandomData();
    socod->ProcessData();
    //socod->DataVectorOut();
    inData=socod->GetProcessData();

}
void CountCharMass::CreateZeroVector(){
    oneAccumData->clear();
    for(size_t i=0; i<socod->GetChNum();++i){
        oneAccumData->push_back(0);
    }
}
void CountCharMass::OneDataAccum(){
    CreateZeroVector();
    for (size_t k=0; k<FrNum;++k){
        GetDataSocod();
        //cout<<"Data From Socod"<<endl;
        for(size_t i=0; i<inData->size();++i){
            oneAccumData->at(i)+=inData->at(i); 
            //cout<<oneAccumData->at(i)<<" "<<inData->at(i)<<" "<<i<<endl; 
        }
        //cout<<"Number of Iter "<<k<<endl;
        //ShowData();
    }
}

void CountCharMass::DataAccum(){
    for (size_t i=0; i<CntNum; ++i){
        OneDataAccum();
        for (size_t k=0; k<socod->GetChNum(); ++k){
           accumData->push_back(oneAccumData->at(k)); 
        }
        cout<<"Number of Iter "<<i<<endl;
        ShowData();
    }
}

void CountCharMass::ShowData(){
    cout<<"Input Data"<<endl;
    copy(inData->begin(), inData->end(),ostream_iterator<int>(cout, " "));
    cout<<endl;

    cout<<"One String Accum Data"<<endl;
    copy(oneAccumData->begin(), oneAccumData->end(),ostream_iterator<int>(cout, " "));
    cout<<endl;

    cout<<"Final Accum Data"<<endl;
    copy(accumData->begin(), accumData->end(),ostream_iterator<int>(cout, " "));
    cout<<endl;
}

vector<int>* CountCharMass::GetAccumData(){
    return accumData;
}

