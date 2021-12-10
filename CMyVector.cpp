#include "CMyVector.h"

template class CMyVector<int>;
template class CMyVector<float>;
template class CMyVector<double>;

template class CMyVector<complex<float> >;
template class CMyVector<complex<double>>;


template <typename T> CMyVector<T>::CMyVector( ) : sz(0), m(0)  
{ 
}
template <typename T> CMyVector<T>::CMyVector(int n) : sz(n) , m(new T[n]) 
{ 
}

template <typename T> CMyVector<T>::CMyVector(const CMyVector& obj) : CMyVector(obj.sz)
{
	memcpy(m, obj.m, sizeof(T) * sz);
}
template <typename T> CMyVector<T>::~CMyVector( )
{
	if (m != 0) delete[] m;
}

template <typename T> void         CMyVector<T>::push_back(T v)
{
	if (m == nullptr)
	{
		m = new T[1]{ v };
		sz = 1;
	}
	else
	{
		T* t = new T[++sz];

		memcpy(t, m, sizeof(T) * (sz - 1));
		t[sz - 1] = v;

		delete[] m;
		m = t;
	}
}
template <typename T> int          CMyVector<T>::size() const
{
	return sz;
}

template <typename T> CMyVector<T> CMyVector<T>::operator+(CMyVector<T>& obj)
{
	if (this->sz != obj.sz) throw "error operator+ ( )  different size";

	CMyVector temp(this->sz);

	for (int i = 0; i < this->sz; i++)
		temp.m[i] = this->m[i] + obj.m[i];

	return temp;
}
template <typename T> CMyVector<T> CMyVector<T>::operator-(CMyVector<T>& obj)
{
	if (this->sz != obj.sz) throw "error operator- ( )  different size";

	CMyVector temp(this->sz);

	for (int i = 0; i < this->sz; i++)
		temp.m[i] = this->m[i] - obj.m[i];

	return temp;
}

template <typename T> T            CMyVector<T>::operator*(CMyVector<T>     obj)
{
	if (this->sz != obj.sz) throw "error operator*( )  different size";

	
	T rez = 0;

	cout << typeid(obj).name() << endl;

	if (typeid(obj).name()[16] == 'c')
	{
		for (int i = 0; i < this->sz; i++)
		{
			if (typeid(obj.m[0]).name()[19] == 'd')
			{
				complex<double>* c = (complex<double>*)(&obj.m[i]);
				c->_Val[1] = c->_Val[1] * (-1);
				rez = rez + this->m[i] * obj.m[i];
			}
			else
			{
				complex<float>* c = (complex<float>*)(&obj.m[i]);
				c->_Val[1] = c->_Val[1] * (-1);
				rez = rez + this->m[i] * obj.m[i];
			}		
		}

		/*
		2
		1 1
		2 0
		2 1
		0 1
		*/	
	}
	else
	{	
		for (int i = 0; i < this->sz; i++)
			rez += this->m[i] * obj.m[i];
	}

	return rez;
}


void fun_1(int*    m, int a)
{
	*m = *m * a;
}
void fun_1(float*  m, int a)
{
	*m = *m * a;
}
void fun_1(double* m, int a)
{
	*m = *m * a;
}
void fun_1(complex<float>* m, int a)
{
	m->_Val[0] = m->_Val[0] * a;
	m->_Val[1] = m->_Val[1] * a;
}
void fun_1(complex<double>* m, int a)
{
	m->_Val[0] = m->_Val[0] * a;
	m->_Val[1] = m->_Val[1] * a;
}

template <typename T> CMyVector<T> CMyVector<T>::operator*(float a)
{	
	CMyVector<T> rez(*this);
	
	for (int i = 0; i < this->sz; i++)
		fun_1(&rez.m[i], a);
				
	return rez;
}


template <typename T> CMyVector<T> CMyVector<T>::operator/(float a)
{
	if (a == 0) throw "error operator/()  division by zero";

	CMyVector temp(this->sz);

	/*
		for (int i = 0; i < this->sz; i++)
		temp.m[i] = this->m[i] / a;
	*/


	return temp;
}
template <typename T> void         CMyVector<T>::operator=(const CMyVector& obj)
{
	if (this->sz != obj.sz)
	{
		if (m != nullptr) delete[] this->m;

		this->sz = obj.sz;
		this->m = new T[obj.sz];
	}

	for (int i = 0; i < obj.size(); i++)
		this->m[i] = obj.m[i];
}
template <typename T> T&           CMyVector<T>::operator[](int i) const
{
	if (i >= this->sz || i < 0) throw "error operator[] going beyond";
	return m[i];
}