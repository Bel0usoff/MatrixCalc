#include<iostream>
#include<Windows.h>
#include"Source.h"
#include<ctime>
//#include<vld.h>
using namespace std;

int main()
{
	system("color 0F");
	setlocale(LC_ALL, ".1251");
	srand(time(NULL));

	int x;
	do
	{
		cout << "------------------------------------------------------------" << endl;
		cout << "1.сложение матриц (только для матриц одного размера)\n2.вычитание матриц (только для матриц одного размера)\n";
		cout << "3.умножение матрицы на число\n4.умножение числа на матрицу \n5.умножение матриц(только для согласованных матрицы)\n0.выход" << endl;
		cout << "------------------------------------------------------------" << endl;

		cin >> x;

		switch (x)
		{
		case 1:
		{
			int rows_A, cols_A;
			cout << "Введите размер первой матрицы" << endl;

			cin >> rows_A >> cols_A;
			Matrix A(rows_A, cols_A);

			cout << "---------------------------------" << endl;
			cout << "1.ввод матрицы вручуню\n2.автоматическая генерация" << endl;
			cout << "---------------------------------" << endl;

			int g;
			cin >> g;

			switch (g)
			{
			case 1:
				cin >> A;
				break;
			case 2:
				A.generate_matrix();
				break;
			}

			cout << "Введите размер второй матрицы" << endl;
			int rows_B, cols_B;
			cin >> rows_B >> cols_B;

			if ((rows_B != rows_A) || (cols_B != cols_A))
			{
				cout << "Ошибка: матрицы разного размера " << endl;
				break;
			}

			Matrix B(rows_B, cols_B);
			cout << "1.ввод матрицы вручуню\n2.автоматическая генерация" << endl;

			int k;
			cin >> k;
			switch (k)
			{
			case 1:
				cin >> B;
				break;
			case 2:
				B.generate_matrix();
				break;
			}

			Matrix C(rows_B, cols_B);
			C = A + B;
			cout << A << endl << "+ \n" << endl << B << endl << "= \n" << endl;
			cout << C;
			break;
		}


		case 2:
		{

			int rows_A, cols_A;
			cout << "Введите размер первой матрицы" << endl;

			cin >> rows_A >> cols_A;
			Matrix A(rows_A, cols_A);

			cout << "---------------------------------" << endl;
			cout << "1.ввод матрицы вручуню\n2.автоматическая генерация" << endl;
			cout << "---------------------------------" << endl;

			int g;
			cin >> g;

			switch (g)
			{
			case 1:
				cin >> A;
				break;
			case 2:
				A.generate_matrix();
				break;
			}

			cout << "Введите размер второй матрицы" << endl;
			int rows_B, cols_B;
			cin >> rows_B >> cols_B;

			if ((rows_B != rows_A) || (cols_B != cols_A))
			{
				cout << "Ошибка: матрицы разного размера " << endl;
				break;
			}

			Matrix B(rows_B, cols_B);
			cout << "1.ввод матрицы вручуню\n2.автоматическая генерация" << endl;
			int k;
			cin >> k;

			switch (k)
			{
			case 1:
				cin >> B;
				break;
			case 2:
				B.generate_matrix();
				break;
			}

			Matrix C(rows_B, cols_B);
			C = A - B;
			cout << A << endl << " - \n" << endl << B << endl << "=\n" << endl << C;
			break;
		}
		case 3:
		{

			int rows_A, cols_A;
			cout << "Введите размер первой матрицы" << endl;

			cin >> rows_A >> cols_A;
			Matrix A(rows_A, cols_A);

			cout << "---------------------------------" << endl;
			cout << "1.ввод матрицы вручуню\n2.автоматическая генерация" << endl;
			cout << "---------------------------------" << endl;

			int g;
			cin >> g;

			switch (g)
			{
			case 1:
				cin >> A;
				break;
			case 2:
				A.generate_matrix();
				break;
			}

			cout << "введите число " << endl;
			int a;
			cin >> a;

			Matrix C(rows_A, cols_A);
			C = A * a;
			cout << A << endl << "* " << a << endl << "= \n" << endl;
			cout << C;
			break;
		}

		case 4:
		{

			int rows_A, cols_A;
			cout << "Введите размер первой матрицы" << endl;

			cin >> rows_A >> cols_A;
			Matrix A(rows_A, cols_A);

			cout << "---------------------------------" << endl;
			cout << "1.ввод матрицы вручуню\n2.автоматическая генерация" << endl;
			cout << "---------------------------------" << endl;

			int g;
			cin >> g;

			switch (g)
			{
			case 1:
				cin >> A;
				break;
			case 2:
				A.generate_matrix();
				break;
			}

			int a;
			cout << "введите число " << endl;
			cin >> a;
			Matrix C(rows_A, cols_A);
			C = a * A;
			cout << a << " *\n" << endl << A << endl << "= \n" << endl;
			cout << C;
		}
		break;
		case 5:
		{
			int rows_A, cols_A;
			cout << "Введите размер первой матрицы" << endl;

			cin >> rows_A >> cols_A;
			Matrix A(rows_A, cols_A);

			cout << "---------------------------------" << endl;
			cout << "1.ввод матрицы вручуню\n2.автоматическая генерация" << endl;
			cout << "---------------------------------" << endl;

			int g;
			cin >> g;

			switch (g)
			{
			case 1:
				cin >> A;
				break;
			case 2:
				A.generate_matrix();
				break;
			}

			int rows_B, cols_B;
			cout << "Введите размер второй матрицы" << endl;
			cin >> rows_B >> cols_B;
			if (cols_A != rows_B)
			{
				cout << "Ошибка: введены несогласованные матрицы" << endl;
				break;
			}
			Matrix B(rows_B, cols_B);
			cout << "1.ввод матрицы вручуню\n2.автоматическая генерация" << endl;
			int k;
			cin >> k;
			switch (k)
			{
			case 1:
				cin >> B;
				break;
			case 2:
				B.generate_matrix();
				break;
			}
			
			Matrix C(rows_A, cols_B);
			C = A * B;
			cout << A << endl << "* \n" << endl << B << endl << "=\n" << endl << C;
			break;
		}

		case 0:
			return 0;
		}
	}while (x != 0);
	return 0;
}
