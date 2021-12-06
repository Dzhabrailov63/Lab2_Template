#include "CMyVector.h"
#include "MyFunction.h"
#include "MyMenu.h"


using namespace std;

int main()
{
	int N; cout << "input N - "; cin >> N;

	//CMyVector<int>     v1(N);
	//CMyVector<float>   v1(N);
	//CMyVector<double>  v1(N);

	CMyVector<complex<float>>  v1(N);
	//CMyVector<complex<float>>  v2(N);

	//CMyVector<complex<double>> v1(N);
	
	filling_vector("filling CMyVector 1 please", v1);
	//filling_vector("filling CMyVector 1 please", v2);

	cout<< v1*3 <<endl;


	// изменение



	system("pause");

	//main_loop(v1, N);
}


