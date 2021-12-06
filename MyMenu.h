#pragma once

enum OPERATION
{
	OPERATION_SUM = 1,
	OPERATION_SUB,
	OPERATION_MUL,
	OPERATION_DIV,
	OPERATION_MUL_SCALAR,
	OPERATION_EXIT

};

int  input_x();

//template <typename T> int  menu_text(T           );
template <typename T> int  menu_text(CMyVector<T>& v1);

//template <typename T> void main_loop(T& v1, int N);
template <typename T> void main_loop(CMyVector<T>& v1, int N);