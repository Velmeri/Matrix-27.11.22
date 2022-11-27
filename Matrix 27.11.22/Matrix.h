#pragma once

#pragma once
#include<iostream>
using namespace std;

template<class T>
class Matrix
{
	T** mas;
	int str;
	int stolb;
public:
	Matrix();
	Matrix(int st, int stolb);
	//----
	Matrix(const Matrix<T>& obj);
	~Matrix();
	Matrix<T>& operator=(const Matrix<T>& obj);
	//-----
	void Random();
	void Print();
	friend ostream& operator<< (ostream& out, const Matrix& obj) {	//	Вот тут
		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < stolb; j++)
			{
				out << mas[i][j] << "\t";
			}
			out << endl << endl;
		}
		return out;
	}

	Matrix<T> operator + (int value) {
		Matrix res = this;
		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < stolb; j++)
			{
				res.mas[i][j] += value;
			}
			cout << endl << endl;
		}
		return res;
	}

	bool operator >(Matrix obj) {
		cout << "Применимы ли к матрице операции \"больше\" или \"меньше\"?\n\n Разве что по размеру(шутка)";
	}
};
template<class T>
Matrix<T>::Matrix()
{
	mas = nullptr;
	str = stolb = 0;
}
template<class T>
Matrix<T>::Matrix(int st, int stol)
{
	str = st;
	stolb = stol;
	mas = new T * [str];
	for (int i = 0; i < str; i++)
	{
		mas[i] = new T[stolb];
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& obj)
{
	str = obj.str;
	stolb = obj.stolb;
	mas = new T * [str];
	for (int i = 0; i < str; i++)
	{
		mas[i] = new T[stolb];
	}
	// copy
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			mas[i][j] = obj.mas[i][j];
		}
	}
}
template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < str; i++)
	{
		delete[] mas[i];
	}
	delete[] mas;
}

template<class T>
void Matrix<T>::Random()
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			mas[i][j] = rand() % 100 * 1.6;
		}
	}
}

template<class T>
void Matrix<T>::Print()
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			cout << mas[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	if (mas != nullptr)
	{
		this->~Matrix();
	}

	//copy
	str = obj.str;
	stolb = obj.stolb;
	mas = new T * [str];
	for (int i = 0; i < str; i++)
	{
		mas[i] = new T[stolb];
	}
	// copy
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			mas[i][j] = obj.mas[i][j];
		}
	}
	return *this;
}

