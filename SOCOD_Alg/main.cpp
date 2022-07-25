#include"algoritm.hpp"

int main(){
	float arr[]={35.8, 23.4, 42.3, 48.5, 48.5, 50.4, 60.4, 65.7};
	int size=sizeof (arr)/sizeof (arr[0]);

	int thrStep=round(GlTHR/size);
	int iterNum=static_cast<int>(round(logbase(thrStep, 2)));

	float* THR=THRarr(size,thrStep);

	float fifcount, fifiter=0.0;
	int ind=0;

	/*for (int i=0; i<iterNum; i++){
		auto[ind,fifcount]=FifthCounts(arr,size,fifiter);
		fifiter=fifcount;
	}*/

	float* data1xArr=DataInput();
	
	for (int i=0; i<10; i++){
		cout<<data1xArr[i]<<endl;
	}

	float** data2xArr=DataArray(data1xArr);

	for (int i=0; i<row; i++){
		for (int j=0; j<column; j++){
			cout<<data2xArr[i][j]<<endl;
		}
	}

	for (int c=0; c<row; c++){
		delete [] data2xArr[c];
	}

	delete [] THR;

	//float data;
	//float data2xArr[2][5];
	//string line;
	//int i=0;
	/*float* data1xArr=DataInput();
	for (int i=0; i<10; i++){
		cout<<data1xArr[i]<<endl;
	}*/

	/*ifstream ifile("test.txt", ios::in);
	if (ifile.is_open()){
		while (ifile>>line){
			data=stof(line);
			data1xArr[i]=data;
			i++;
		}		
	}
	ifile.close();

	for (int i=0; i<2; i++){
		for (int k=0; k<5; k++){
			data2xArr[i][k]=data1xArr[k+5*i];
			cout<<data2xArr[i][k]<<endl;
		}
	}*/
	

	return 0;

}