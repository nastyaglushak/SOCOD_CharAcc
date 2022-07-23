#include"countchmass.hpp"
#include <fstream>

class SOCOD{
    private:
        vector<int> acquiredDataVec;
        vector<int> processDataVec;
        vector<int>* processData;//output vector data
        vector<int>* acquiredData;//vector to save in accumulator
        int channelNum=4;
        int frameNum=5;
    public:
        SOCOD();
        ~SOCOD();
        void GetData(vector<int>& acquiredDataVec);
        vector<int> ProcessData(const vector<int>& acquiredDataVec);
        vector<int>* GetAccData();
        vector<int>* GetProcessData();
};

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
    //acquiredData->clear();
	ifstream ifile("test.txt", ios::in);
	if (ifile.is_open()){
		while (ifile>>line){
			//acquiredData->push_back(stof(line));
            acquiredDataVec.push_back(stof(line));
		}		
	}
	ifile.close();
}
vector<int>* SOCOD::GetAccData(){
    return acquiredData;
}
vector<int> SOCOD::ProcessData(const vector<int>& acquiredDataVec){
    /*for (int i=0; i<acquiredData.size(); i=i+4){
        processData->push_back(acquiredData[i]);
    }*/
    for (int i=0; i<acquiredDataVec.size(); i=i+4){
        processDataVec.push_back(acquiredDataVec[i]);
    }
    return processDataVec;
}

vector<int>* SOCOD::GetProcessData(){
    return processData;
}


int main(){
    CountCharMass ChArray(5, 10);
    cout<<"First iter: "<<ChArray.GetChNum()<<" "<<ChArray.GetCntNum()<<"\n"<<endl;

    SOCOD TestSOCOD;
    vector<int> testvec, testvec2;
    
    TestSOCOD.GetData(testvec);
    testvec2=TestSOCOD.ProcessData(testvec);
    cout<<"TestData Out"<<endl;
    for (int s: testvec){
        cout<<s<<" ";
    }
    cout<<endl;
    
    for (int s: testvec2){
        cout<<s<<" ";
    }
    cout<<endl;

    cout<<"------------------"<<endl;

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

    vector<int> dataVec3={1,2,3,4,5};

    ChArray.DataAccum(dataVec3);
    ChArray.DataVectorOut();

    ChArray.DataAccum(dataVec2);
    ChArray.DataVectorOut();

    return 0;
}
