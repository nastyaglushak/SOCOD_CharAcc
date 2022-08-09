#include"algoritm.hpp"

int main(){
	Algorithm TestAlg;
	TestAlg.SetCntNum(5);
	//TestAlg.SetAlPar();
	/*TestAlg.SetTHRArr();
	TestAlg.PerformInData();
	TestAlg.SeachFifthCounts(0);*/
	TestAlg.SlideWindow(3);
	return 0;
}