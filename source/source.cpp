#include<iostream>
#include<Windows.h>
#include"Source.h"


using namespace std;

void Matrix::generate_matrix() //метод генерации матрицы
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % 21 - 10;
		}
	}
}
void Matrix::show_matrix() // метод вывода матрицы на экран
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "--------------------" << endl;
}

Matrix::Matrix() : n(0), m(0), matrix(nullptr)
{
	cout << "*выделена память под матрицу (без параметров)*" << endl;
}



Matrix::Matrix(int row, int col) : n(row), m(col), matrix(nullptr)
{
	if (n <= 0 || m <= 0)
	{
		cerr << "Ошибка: некорректный размер матрицы" << endl;
		return;
	}

	matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}

	cout << "*выделена память под матрицу (с параметрами)*" << endl;
}

Matrix::Matrix(const Matrix& copy) : n(copy.n), m(copy.m), matrix(nullptr)
{
	matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = copy.matrix[i][j];
		}
	}
	cout << "*выделена память под копию матрицы*" << endl;
}

Matrix Matrix :: operator+(const Matrix& a) const
{
	Matrix C(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			C.matrix[i][j] = matrix[i][j] + a.matrix[i][j];
		}
	}
	return C;
}
Matrix operator* (const Matrix& a, int c)
{
	Matrix C(a.n, a.m);
	for (int i = 0; i < a.n; i++)
	{

		for (int j = 0; j < a.m; j++)
		{
			C.matrix[i][j] = a.matrix[i][j] * c;
		}
	}
	return C;
}
Matrix operator*(int c, const Matrix& a)
{
	Matrix C(a.n, a.m);
	for (int i = 0; i < a.n; i++)
	{
		for (int j = 0; j < a.m; j++)
		{
			C.matrix[i][j] = c * a.matrix[i][j];
		}
	}
	return C;
}

Matrix Matrix :: operator*(const Matrix& a) const
{
	Matrix C(n, a.m);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a.m; j++)
		{
			for (int k = 0; k < m; k++)
			{
				sum += matrix[i][k] * a.matrix[k][j];
			}
			C.matrix[i][j] = sum;
			sum = 0;
		}
	}
	return C;
}

Matrix Matrix :: operator-(const Matrix& a) const
{
	Matrix C(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			C.matrix[i][j] = matrix[i][j] + (a.matrix[i][j] * (-1));
		}
	}
	return C;
}
ostream&  operator<<(ostream& os, const Matrix& a)
{
	for (int i = 0; i < a.n; i++)
	{
		for (int j = 0; j < a.m; j++)
		{
			os << a.matrix[i][j] << '\t';
		}
		os << endl;
	}
	return os;
}
istream& operator>>(istream& in,  Matrix& a)
{
	cout << "введите " << a.n * a.m << " элементов " << endl;
	for (int i = 0; i < a.n; i++)
	{
		for (int j = 0; j < a.m; j++)
		{
			in >> a.matrix[i][j];
		}
	}
	return in;
}

Matrix::~Matrix()
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = nullptr;

	cout << "*Матрица удалена*" << endl;
	cout << endl;
}
Matrix& Matrix::operator=(const Matrix& other)
{
	if (this == &other) // Проверка на самоприсваивание
	{
		return *this;
	}
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = nullptr;

	// Копирование размеров матрицы
	n = other.n;
	m = other.m;

	// Выделение новой памяти и копирование значений
	matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}

	return *this;
}
