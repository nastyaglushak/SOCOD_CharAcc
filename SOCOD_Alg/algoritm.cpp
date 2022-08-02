#include"algoritm.hpp"

Algorithm::Algorithm(){
	cout<<"Algorithm Constructor"<<endl;
	inData=new vector<vector<int>>();
	allCntChar=new vector<int>() ;
}

Algorithm::~Algorithm(){
	cout<<"Algorithm Destructor"<<endl;
	delete inData;
	delete allCntChar;
	delete thrArr;
}

void Algorithm::LoadDataFile (){

	string line;
	int data;

	ifstream ifile("test.txt", ios::in);
	if (ifile.is_open()){
		while (ifile>>line){
			data=stof(line);
			allCntChar->push_back(data);
		}		
	}
	ifile.close();

}

//Setting an array of thresholds
void Algorithm::SetTHRArr(int size, int step){
	thrArr=new vector<int>(size);

	for (int i=0; i<size; i++){
		thrArr->push_back(step*i);
	}
}

int Algorithm::LoadDataArray(){
	//Set algoritm parameters
	int size=sizeof (allCntChar)/sizeof (allCntChar[0]);

	int thrStep=round(GlTHR/size);
	int iterNum=static_cast<int>(round(logbase(thrStep, 2)));

	vector<int>dataCh;
	inData->push_back(vector<int>(dataCh));
}

void Algorithm::SetCntNum(int cntNum){
	this->cntNum=cntNum;
	cout<<"CntNum "<<cntNum<<endl;
}


void Algorithm::SlideWindow(int wSize){
	vector<int> l,r;
	

}

//While integer
int Algorithm::SeachFifthCounts(int refValue, vector<int> dataIn){
	int fifnum, fifmax=0;
	int fifmin=refValue;
	int i=0;
	for (i=0; i<dataIn.size(); ++i){
		if (fifmin<dataIn[i] && fifmin<50){
			fifmin=dataIn[i];
			//cout<<"MIN"<<fifmin<<endl;
		}else if (dataIn[i+1]>50.0){
			fifmax=dataIn[i+1];
			//cout<<"MAX"<<fifmax<<endl;
			break;
		}
	}
	fifnum=fifmin+(fifmax-fifmin)/2;
	//cout<<"Finish "<<fifmax <<" "<<fifmin<<endl;
	return fifnum; 
}


