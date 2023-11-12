#pragma once
#include<iostream>
using namespace std;
class Matrix
{
private:
	int n;
	int m;
	int** matrix;
public:
	Matrix();
	Matrix(int row, int col);
	Matrix(const Matrix& a);
	void generate_matrix();
	void show_matrix();
	Matrix operator+(const Matrix& a) const;
	Matrix operator-(const Matrix& a) const;
	friend Matrix operator* (const Matrix& a, int c);
	Matrix operator*(const Matrix& a) const;
	friend Matrix operator*(int c, const Matrix& a);
	friend ostream& operator<<(ostream& os, const Matrix& a);
	friend istream& operator>> (istream& in, Matrix& a);
	Matrix& operator=(const Matrix& a);
	int getn() { return n; }
	int getm() { return m; }
	~Matrix();
};
