#include "CMyVector.h"
#include "MyFunction.h"
#include "MyMenu.h"

using namespace std;


int main()
{
	int N; cout << "input N - "; cin >> N;

	unsigned type;
	std::cout << "Type:" << std::endl;
	std::cout << "1) INT" << std::endl;
	std::cout << "2) FLOAT" << std::endl;
	std::cout << "3) DOUBLE" << std::endl;
	std::cout << "4) STD::COMPLEX<FLOAT>" << std::endl;
	std::cout << "5) STD::COMPLEX<DOUBLE>" << std::endl;
	std::cin >> type;

	switch (type)
	{
		case 1: 
		{
			CMyVector<int> v(N);
			filling_vector("filling CMyVector 1 please", v);
			main_loop(v, N);
		}break;

		case 2:
		{
			CMyVector<float> v(N);
			filling_vector("filling CMyVector 1 please", v);
			main_loop(v, N);
		}break;

		case 3:
		{
			CMyVector<double> v(N);
			filling_vector("filling CMyVector 1 please", v);
			main_loop(v, N);
		}break;

		case 4:
		{
			CMyVector<complex<float>> v(N);
			filling_vector("filling CMyVector 1 please", v);
			main_loop(v, N);
		}break;

		case 5:
		{
			CMyVector<complex<double>> v(N);
			filling_vector("filling CMyVector 1 please", v);
			main_loop(v, N);
		}break;
	}
	
}


