#include"algoritm.hpp"

Algorithm::Algorithm(){
	cout<<"Algorithm Constructor"<<endl;
}

Algorithm::~Algorithm(){
	cout<<"Algorithm Destructor"<<endl;
}

void Algorithm::SlideWindow(int wSize){
	vector<int> l,r;
	

}

pair<int,float> FifthCounts(float mass[], int size, float ref){
	float fifnum, fifmax=0;
	float fifmin=ref;
	int i=0;
	for (i=0; i<size; i++){
		if (fifmin<mass[i] && fifmin<50.0){
			fifmin=mass[i];
			//cout<<"MIN"<<fifmin<<endl;
		}else if (mass[i+1]>50.0){
			fifmax=mass[i+1];
			//cout<<"MAX"<<fifmax<<endl;
			break;
		}
	}
	fifnum=fifmin+(fifmax-fifmin)/2;
	//cout<<"Finish "<<fifmax <<" "<<fifmin<<endl;
	return pair<int,float>(i,fifnum); 
}

float** DataArray(float datamas[]){

	float **arr=new float* [row];
	for (int i=0; i<row; i++){
		arr[i]=new float [column];
	}

	for (int j=0; j<row; j++){
		for(int k=0; k<column; k++){
			arr[j][k]=datamas[k+column*j];
		}
	}
	return arr;
}
double logbase(double a, double base)
{
   return log(a) / log(base);
}

float* THRarr(int size, int thrStep){
	float *thr=new float [size];

	for (int i=0; i<size; i++){
		thr[i]=thrStep*i;
	}
	return thr;
}

float* DataInput (){

	float *CountChar=new float [10];
	string line;
	int i=0;
	float data;

	ifstream ifile("test.txt", ios::in);
	if (ifile.is_open()){
		while (ifile>>line){
			data=stof(line);
			CountChar[i]=data;
			i++;
		}		
	}
	ifile.close();

	return CountChar;
}