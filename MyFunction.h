#pragma once


//template <typename T> ostream& operator<< (ostream& out, const T& v1);
//ostream&     operator<< (ostream& , const CMyVector<float>&);

template <typename T> ostream& operator<< (ostream& out, const CMyVector<T>& v1);


template <typename T> T operator*(float a, T obj);



template <typename T> void         filling_vector(const char* str, CMyVector<T>& v);
template <typename T> void         filling_vector(const char* str, CMyVector<complex<T>>& v);






  