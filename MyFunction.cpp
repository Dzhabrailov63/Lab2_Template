#include "CMyVector.h"
#include "MyFunction.h"

template class CMyVector<int>;
template class CMyVector<float>;
template class CMyVector<double>;

template class CMyVector<complex<float>>;
template class CMyVector<complex<double>>;

template              ostream& operator<< (ostream& out, const CMyVector<int>& v1);
template              ostream& operator<< (ostream& out, const CMyVector<float>& v1);
template              ostream& operator<< (ostream& out, const CMyVector<double>& v1);
template              ostream& operator<< (ostream& out, const CMyVector<complex<float>>&  v1);
template              ostream& operator<< (ostream& out, const CMyVector<complex<double>>& v1);
template <typename T> ostream& operator<< (ostream& out, const CMyVector<T>&                    v1)
{
	for (int i = 0; i < v1.size(); i++)
		out << v1[i] << " ";
	out << endl;

	return out;
}




void fun_2(int* m, int a)
{
	*m = *m * a;
}
void fun_2(float* m, int a)
{
	*m = *m * a;
}
void fun_2(double* m, int a)
{
	*m = *m * a;
}
void fun_2(complex<float>* m, int a)
{
	m->_Val[0] = m->_Val[0] * a;
	m->_Val[1] = m->_Val[1] * a;
}
void fun_2(complex<double>* m, int a)
{
	m->_Val[0] = m->_Val[0] * a;
	m->_Val[1] = m->_Val[1] * a;
}


template  CMyVector<complex<float>>  operator*(float a, CMyVector<complex<float>> obj);
template  CMyVector<complex<double>> operator*(float a, CMyVector<complex<double>> obj);
template  CMyVector<int>             operator*(float a, CMyVector<int> obj);
template  CMyVector<float>           operator*(float a, CMyVector<float> obj);
template  CMyVector<double>          operator*(float a, CMyVector<double> obj);

template <typename T> T            operator*(float a, T obj)
{
	T rez(obj);

	for (int i = 0; i < rez.size(); i++)
		fun_2(&rez.m[i], a);

	return rez;
}


template  void                     filling_vector(const char*    , CMyVector<int>&    v);
template  void                     filling_vector(const char*    , CMyVector<float>&  v);
template  void                     filling_vector(const char*    , CMyVector<double>& v);
template <typename T> void         filling_vector(const char* str, CMyVector<T>&      v)
{
	cout << str << "  size "<< v.size() << endl;
	
	for (int i = 0; i < v.size(); i++)
	{
		cout << "!!!" << endl;
		cin >> v[i];

	}
		
	
	while (cin.peek() == ' ') cin.get();
	if (cin.peek() != '\n')
	{
		throw "error operator+ ( )  different size";
	}	
}


template              void         filling_vector(const char*    , CMyVector<complex<double>>& v);
template              void         filling_vector(const char*    , CMyVector<complex<float>>&  v);
template <typename T> void         filling_vector(const char* str, CMyVector<complex<T>>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		T a;
		T b;

		cin >> a;
		cin >> b;

		v[i] = complex<T>(a, b);
	}


	while (cin.peek() == ' ') cin.get();
	if (cin.peek() != '\n')
	{
		throw "error operator+ ( )  different size";
	}
}






