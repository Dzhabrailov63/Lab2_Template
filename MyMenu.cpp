#include "CMyVector.h"
#include "MyMenu.h"
#include "MyFunction.h"

template class CMyVector<int>;
template class CMyVector<float>;
template class CMyVector<double>;

template class CMyVector<std::complex<float>>;
template class CMyVector<std::complex<double>>;

int input_x()
{
	int x; cout << "input x - ";
	while (!(bool)(cin >> x))
	{
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return x;
}


template              int menu_text(CMyVector<int>& v1);
template              int menu_text(CMyVector<float>& v1);
template              int menu_text(CMyVector<double>& v1);
template              int menu_text(CMyVector<complex<float>>&  v1);
template              int menu_text(CMyVector<complex<double>>& v1);

template <typename T> int menu_text(CMyVector<T    >& v1)
{
	system("cls");

	cout << OPERATION::OPERATION_SUM << ". OPERATION_SUM " << endl;
	cout << OPERATION::OPERATION_SUB << ". OPERATION_SUB " << endl;
	cout << OPERATION::OPERATION_MUL << ". OPERATION_MUL " << endl;
	cout << OPERATION::OPERATION_DIV << ". OPERATION_DIV " << endl;
	cout << OPERATION::OPERATION_MUL_SCALAR << ". OPERATION_MUL_SCALAR " << endl;
	cout << OPERATION::OPERATION_EXIT << ". OPERATION_EXIT " << endl << endl;
	
	cout << "v1: "; cout << v1;
	cout << endl << endl;

	cout << "enter operation number: ";

	
	

	int n;  cin >> n;

	// .....

	return n;
}


template              void main_loop(CMyVector<int>    v1, int N);
template              void main_loop(CMyVector<float>  v1, int N);
template              void main_loop(CMyVector<double> v1, int N);
template              void main_loop(CMyVector<complex<float>> v1, int N);
template              void main_loop(CMyVector<complex<double>> v1, int N);

template <typename T> void main_loop(CMyVector<T>              v1, int N)
{	
	try
	{
		bool flag = true;

		while (flag)
		{
			switch (menu_text(v1))
			{
				case OPERATION::OPERATION_SUM:
				{
					CMyVector<T> v2(N);
					filling_vector("filling CMyVector 2 please", v2);

					CMyVector<T> rez_v = v1 + v2;
					cout << rez_v;

					system("pause");
				}break;

				case OPERATION::OPERATION_SUB:
				{
					CMyVector<T> v2(N);
					filling_vector("filling CMyVector 2 please", v2);
					CMyVector<T> rez_v = v1 - v2;
					cout << rez_v;
					system("pause");
				}break;

				case OPERATION::OPERATION_MUL:
				{
					CMyVector<T> v2(N);
					filling_vector("filling CMyVector 2 please", v2);
					cout << "MUL" << endl;
					T rez_v = v1 * v2;
					cout << rez_v;

					system("pause");
				}break;

				case OPERATION::OPERATION_DIV:
				{
					int x = input_x();

					CMyVector<T> rez_v = v1 / x;
					cout << rez_v;
					system("pause");
				}break;

				case OPERATION::OPERATION_MUL_SCALAR:
				{
					int x = input_x();

					CMyVector<T> rez_v = v1 * x;
					cout << rez_v;
					system("pause");
				}break;

				case OPERATION::OPERATION_EXIT:
				{
					flag = false;
				}break;
			}
		}
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}
}