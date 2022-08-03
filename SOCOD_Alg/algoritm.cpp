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
	ShowOneXData(*allCntChar, "Input data");
}

double logbase(double a, double base){return log(a) / log(base);};

//Set algoritm parameters
void Algorithm::SetAlPar(){
	LoadDataFile();
	
	alPar.ArrSize=allCntChar->size();
	alPar.THRStep=round(GlTHR/alPar.ArrSize);
	alPar.IterNum=static_cast<int>(round(logbase(alPar.THRStep, 2)));
	cout<<"Array Parameters "<<endl;
	cout<<"size "<<alPar.ArrSize<<" thrStep "<<alPar.THRStep<<" iterNum "<<alPar.IterNum<<endl;
}

//Set an array of thresholds
void Algorithm::SetTHRArr(){
	SetAlPar();

	thrArr=new vector<int>(alPar.ArrSize);

	for (int i=0; i<alPar.ArrSize; i++){
		thrArr->push_back(alPar.THRStep*i);
	}
	ShowOneXData(*thrArr, "THR Array");
}

//Print one-dimensional array
void Algorithm::ShowOneXData(vector<int>& data, string mes){
    cout<<mes<<endl;
    copy(data.begin(), data.end(),ostream_iterator<int>(cout, " "));
    cout<<endl;
}

void Algorithm::SetCntNum(int cntNum){
	this->cntNum=cntNum;
	cout<<"CntNum "<<cntNum<<endl;
}

//Perform one-dimensional data array to two-dimentional array
void Algorithm::PerformInData(){
	vector<int>dataCh{1,2,3};
	for (int i=0; i<5;++i){
		inData->push_back(vector<int>(dataCh));
	}
	ShowTwoXData(*inData,"Perform Data Out");
}

//Print two-dimensional array
void Algorithm::ShowTwoXData(vector<vector<int>>& data, string mes){
    cout<<mes<<endl;
	for(int i=0; i<data.size();++i){
		for(int j=0; j<data[i].size();++j){
			cout<<data[i][j]<<" ";
		}
	}
	cout<<endl;
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

//Slide Window Method
void Algorithm::SlideWindow(int wSize){
	vector<int> l,r;
}

