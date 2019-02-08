#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "windows.h"
#include "cmath"
#include "Menu.h"
#include "MyCrt.h"
#include "Table.h"


using namespace std;

void FreeMem(int **Matr, int n);
void FreeMem(double **Matr, int n);

void PrintMtx(int **matr, int n);
void PrintMtx(double **matr, int n);

void SetMtx(int **matr, int);
void SetMtx(double **matr, int n);

void TransponMtx(int **Matr, int **tMatr, int n);
void TransponMtx(double **Matr, double **tMatr, int n);

void Get_matr(double **Matr, int n, double **temp_matr, int indRow, int indCol);
double Det(double **Matr, int n);


void main()
{
	do
	{
		setlocale(0, "");
		short n;
		double det;
		do
		{
			cout << " Введите колличество строк/столбцов матрицы 10>=n>1: ";
			cin >> n;
			if (cin.fail())
				cout << "Неверно! Попробуйте еще раз" << endl;
			cin.clear();
			cin.sync();
		} while ((n <= 1) || (n>10));
		double **Matr = new double*[n];
		double **obr_matr = new double *[n];
		double **tobr_matr = new double *[n];
		for (int i = 0; i < n; i++)
		{
			obr_matr[i] = new double[n];
			tobr_matr[i] = new double[n];
		}
		Table Mass, Mass1;
		TInf El = 0;
		 int CCount = n, CWidth = 5, RCount = n, RHeigth = 2;
		const short NormColors = 0xF1, SelectColors = 0x2F, X = 1, Y = 3, M = (RHeigth + 4)*n, N=2*M;
		


		
		Matr[0] = new double[RCount * CCount];
		for (int i = 1; i < RCount; i++)
			Matr[i] = Matr[0] + i * CCount;
		
		for (int i = 0; i < RCount; i++)
			for (int j = 0; j < RCount; j++)
				Matr[i][j] = 0;
		
		int S = 2;

		if (n <= 7)
		{
			CWidth = 10;
		    S = 5;
		}

		InitTable(Mass, X, Y, CCount, CWidth, RCount, RHeigth, 2, NormColors, SelectColors, Matr, CCount, RCount, S, 0, 1, 0);
		Mass.Visible = true;
		DrawEmptyTable(Mass);


		FillTable(Mass);

		GoToXY(0, 0);
		char Ch = ' ';

		do
		{
			CellChoice(Mass);
			EditValue(Mass, Ch);
		} while (_getch() != 27);


		det = Det(Matr, n);

		GoToXY(0, 2);

		cout << "Определитель матрицы = " << det << endl;

		if (det)
		{
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					int m = n - 1;
					double **temp_matr = new double *[m];
					for (int k = 0; k < m; k++)
						temp_matr[k] = new double[m];
					Get_matr(Matr, n, temp_matr, i, j);
					obr_matr[i][j] = pow(-1.0, i + j + 2) * Det(temp_matr, m) / det;
					if (obr_matr[i][j] == -0)
						obr_matr[i][j] = 0;
					FreeMem(temp_matr, m);
				}
			}
			TransponMtx(obr_matr, tobr_matr, n);

			Matr = tobr_matr;


			InitTable(Mass1, X, M, CCount, CWidth, RCount, RHeigth, 2, NormColors, SelectColors, Matr, CCount, RCount, S, 0, 1, 0);

			
			Mass1.Visible = true;
			DrawEmptyTable(Mass1);


			FillTable(Mass1);

			do
			{
				cout << endl;
				cout << "для окончания просмотра нажмите любую клавишу";
				CellChoice(Mass1);
			} while (!_getch);
		

		}




		else
		{
			GoToXY(0, M);
			cout << "Т.к. определитель матрицы = 0,\n то матрица вырожденная и обратной не имеет!!!" << endl;
			system("pause");
	
			FreeMem(tobr_matr, n);
			FreeMem(obr_matr, n);

		}
		
		system("cls");
		cout << "для окончания работы нажмите ESC, для продолжения любая клавиша" << endl;
	} while (_getch() != 27);
	
}
//Функция транспонирования матрицы
void TransponMtx(double **Matr, double **tMatr, int n){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tMatr[j][i] = Matr[i][j];
}

void TransponMtx(int **Matr, int **tMatr, int n){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tMatr[j][i] = Matr[i][j];
}


//Функция освобождения памяти
void FreeMem(int **Matr, int n)
{
	for (int i = 0; i < n; i++)
		delete[] Matr[i];
	delete[] Matr;
}

void FreeMem(double **Matr, int n)
{
	for (int i = 0; i < n; i++)
		delete[] Matr[i];
	    delete[] Matr;
}


//функция вычеркивания строки и столбца
void Get_matr(double **Matr, int n, double **temp_matr, int indRow, int indCol)
{
	int ki = 0;
	for (int i = 0; i < n; i++){
		if (i != indRow){
			for (int j = 0, kj = 0; j < n; j++){
				if (j != indCol){
					temp_matr[ki][kj] = Matr[i][j];
					kj++;
				}
			}
			ki++;
		}
	}
}

//функция вычисления определителя матрицы
double Det(double **Matr, int n)
{
	double temp = 0;
	int k = 1;
	if (n < 1){
		cout << "Неверный размер матрицы!!!" << endl;
		return 0;
	}
	else if (n == 1)
		temp = Matr[0][0];
	else if (n == 2)
		temp = Matr[0][0] * Matr[1][1] - Matr[1][0] * Matr[0][1];
	else{
		for (int i = 0; i < n; i++){
			int m = n - 1;
			double **temp_matr = new double *[m];
			for (int j = 0; j < m; j++)
				temp_matr[j] = new double[m];
			Get_matr(Matr, n, temp_matr, 0, i);
			temp = temp + k * Matr[0][i] * Det(temp_matr, m);
			k = -k;
			FreeMem(temp_matr, m);
		}
	}
	return temp;
}
