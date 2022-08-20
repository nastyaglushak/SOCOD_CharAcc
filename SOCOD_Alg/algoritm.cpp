#include"algoritm.hpp"

Algorithm::Algorithm(){
	cout<<"Algorithm Constructor"<<endl;
	inData=new vector<vector<int> >();
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
	vector<int> dataCh;
	for(int i=0; i<chNum; i++){ //(0..4)
		for (int k=0; k<cntNum; ++k){ //(0..5)
			//cout<<"Data Ind "<<(k*chNum+i)<<endl;
			dataCh.push_back(allCntChar->at(k*chNum+i));
			if (k==cntNum-1){
				inData->push_back(vector<int>(dataCh));
				dataCh.clear();}
		}
	}
	ShowTwoXData(*inData,"Perform Data Out");
}

//Print two-dimensional array
void Algorithm::ShowTwoXData(vector<vector<int> >& data, string mes){
    cout<<mes<<endl;
	for(int i=0; i<data.size();++i){
		for(int j=0; j<data[i].size();++j){
			cout<<data[i][j]<<" ";
		}
	}
	cout<<endl;

	cout<<"One string out"<<endl;
	copy(data[1].begin(), data[1].end(),ostream_iterator<int>(cout, " "));
	cout<<endl;
}

int findFifthCounts(vector<int> &chChar, float refValue, float midValue){
	float fifnum, fifmax=0;
	float fifmin=refValue;

	for (int i=0; i<chChar.size(); ++i){
		if (fifmin<chChar[i] && fifmin<midValue){
			fifmin=chChar[i];
			cout<<"MIN "<<fifmin<<endl;
		}else if (chChar[i]>midValue){
			fifmax=chChar[i];
			cout<<"MAX "<<fifmax<<endl;
			break;
		}
	}
	fifnum=fifmin+(fifmax-fifmin)/2;
	cout<<"Finish "<<fifmax <<" "<<fifmin<<" "<<fifnum<<endl;
	return fifmin;
}

int indFind(vector<int> &dataIn, int value ){
	int i;
	for(i=0;i<dataIn.size();i++){
		if(dataIn[i]==value)
  		{break;}
	}
	return i;
}


int Algorithm::SeachFifthCounts(float refValue){

	vector<int> chChar;
	float midValue;
	int fifmin, fifminInd;
	vector<int> fifData,fifInd;
	vector<int> FifTHRArr;
	
	for (int i=0; i<chNum; ++i){
		chChar=inData->at(i);
		midValue = 0.5*(*max_element(chChar.begin(), chChar.end()));
		cout<<"Ref value: "<<midValue<<endl;
		//Find 50% of count
		fifmin=findFifthCounts(chChar, refValue, midValue);
		fifData.push_back(fifmin);
		//fifminInd=*find(chChar.begin(),chChar.end(),fifmin);//not work in my programm
		fifminInd=indFind(chChar, fifmin);
		cout<<"FifInd "<<fifminInd<<" "<<endl;
		fifInd.push_back(fifminInd);
	}

	//Then collerate with threshold
	vector<int> THRIn={2,4,6,8,10};//I haven't figured out the array of thresholds yet

	for(int i=0; i<fifInd.size();++i){
		FifTHRArr.push_back(THRIn.at(fifInd[i]));
	}

	ShowOneXData(fifData, "Fifnum out");
	ShowOneXData(fifInd, "FifInd out");
	ShowOneXData(FifTHRArr, "FifTHR out");

	return 0;
}

void Algorithm::SortTHR(int THRstep){
	vector<int> exVec;
	for (size_t i=0; i != 20; ++i){
        exVec.push_back(1+rand()/((RAND_MAX + 1u)/10));
    }
	ShowOneXData(exVec, "ExVec THR out ");

}

//Slide Window Method
void Algorithm::SlideWindow(int wSize){
	vector<int> exVec={1,2,3,4,5,6,8,9,10,11,12};//11-3=8//sorted vector
	vector<int> outVec, workVec;

	//outVec.pop_back();//delete last member
	//outVec.push_back();//add element to the end

	while (exVec.size()>wSize){
		for (int i=0; i<wSize; ++i){
			workVec.push_back(exVec.at(i));
		}
		ShowOneXData(workVec, "Work vec ");
		
		outVec.push_back(accumulate(workVec.begin(), workVec.end(),0));
		ShowOneXData(outVec, "Out vec ");

		exVec.erase(exVec.begin());//delete first member
		ShowOneXData(exVec, "Ex vec ");
		workVec.clear();
	}
	int max_sum=*max_element(outVec.begin(), outVec.end());
	int left_num=distance(outVec.begin(),max_element(outVec.begin(), outVec.end()))+1;//number of iter+1
	int right_num=left_num+wSize;
	cout<<"Max sum "<<max_sum<<" "<<left_num<<" "<<right_num<<endl;
}

//Count coorection code
void Algorithm::CountCorCode(){

}