#pragma once

#include <iostream>
#include <initializer_list> 
#include <complex>

using namespace std;


template<typename T>
class CMyVector
{
private:
	int  sz;
	T*   m;

public:
	CMyVector();
	CMyVector(int);
	CMyVector(const CMyVector<T>& obj);

	int  size() const;
	void push_back(T v);

	CMyVector<T> operator+(CMyVector<T>& obj);
	CMyVector<T> operator-(CMyVector<T>& obj);

	T operator*(CMyVector<T> obj);

	CMyVector<T> operator*(float a);
	CMyVector<T> operator/(float a);
	
	void     operator=(const CMyVector<T>& obj);
	T&       operator [ ](int i) const;


	template <typename T> friend  T            operator*(float a, T obj);

	~CMyVector();	
};


