// ConsoleApplication20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//1.	Написать функцию, которая принимает два параметра: основание степени и показатель степени, и вычисляет степень числа на основе полученных данных.

int Pow(int x, int y) {
	int p = 1;
	for (int i = 0; i < y; i++)
	{
		p *= x;
	}
	return p;
}

//2.	Написать функцию, которая получает в качестве параметров 2 целых числа и возвращает сумму чисел из диапазона между ними.

int ab(int a, int b, int sum = 0) {
	for (int i = a; i <= b; i++)
	{
		sum += i;
	}
	return sum;
}
//3.	Написать функцию для округления заданного числа с заданной точностью

double funcO(double x, int z) {
	int o = 1;
	for (int i = 1; i <= z; i++)
	{
		o *= 10;
	}
	return	round(x * o) / o;
}


//4. Напишите функцию, которая принимает массив, количество элементов, тип сортировки (пузырьком, выбором и т.д. - строка) и порядок сортировки (по убыванию, по возрастанию – логическая переменная). Функция сортирует массив. Реализовать перегрузки для целых и вещественных чисел.

void arrX(int a[], int size, int metod, bool por) {

	int min_v = INT_MAX, min, j;

	switch (metod)
	{
	case 1: // пузырьковый

		for (int pass = 0; pass < size; pass++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (a[i] > a[i+1])
				{
					swap(a[i], a[i + 1]);
				}

			}
		}
		break;
	case 2: // вставки
		j = 0;
		for (int pass = 0; pass < size; pass++)
		{
			j = pass;
			while ((a[j] < a[j - 1]) && j>0)
			{
				swap(a[j], a[j - 1]);
				j--;
			}
		}
		break;
	case 3: //сортировка выбором

		for (int i = 0; i < size; i++)
		{
			for (j = i; j < size; j++)
			{

				if (a[j] < min_v) {
					min_v = a[j];
					min = j;
				}
			}

			a[min] = a[i];
			a[i] = min_v;

			min_v = INT_MAX;
		}

		break;
	}

	if (por == false) {
		for (int i = 0; i < size / 2; i++)
		{
			swap(a[i], a[size - i - 1]);
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl << endl;
}


//5. Напишите функцию, которая принимает целое число и возвращает количество цифр в числе и процент четных цифр.

void kprc(int x) {
	double res = 0, kc = 0, prc;

	for (int i = 0; x > 0; i++)
	{
		if (x % 2 == 0) res++;
		x = x / 10;
		kc++;
	}
	prc = res / kc * 100;

	cout << "procent 4etnyh = " << prc << endl;
	cout << "kol-vo cifr = " << kc << endl;

}

//6. Напишите функцию, которая принимает массив и количество элементов и возвращает среднее арифметическое всех элементов массива. Реализуйте перегрузку для целых и вещественных чисел.

double arrX(double arr[], int size) {
	int sum = 0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
		k++;
	}
	return (double)sum / k;
}



int main()
{



	//1
	cout << "1 = " << Pow(9, 2) << endl << endl;

	//2
	cout << "2 = " << ab(2, 9) << endl << endl;

	//3
	long double pi = 3.14159265359;
	cout << "3 = " << funcO(pi, 4) << endl << endl;

	//4
	int a[] = { 3,2,4,5,6,2,3,1 };
	int metod;

	cout << "Metod sortirovki (1 - puzyr'kovyi, 2 - vstavki, 3 - vybor) = ";
	cin >> metod;

	int por;

	cout << "poryadok sortirovki (0 - po ybyvaniu, 1 - po vozrostaniu) = ";
	cin >> por;

	arrX(a, 8, metod, por);

	//5	
	cout << "5: " << endl;
	kprc(123456789);
	cout << endl;

	//6
	double arr[] = { 1.0, 2, 3, 9, 5, 6, 7, 8, 9 };

	cout << "6 = " << arrX(arr, 9) << endl;

	return 0;
}

/*#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

#pragma region 1. заполнение массива

	const int x = 12;
	int a[x];

	for (int i = 0; i < x; i++)
	{
		a[i] = -5 + rand() % 15;
		cout << a[i] << " ";
	}
	cout << endl << endl;

#pragma endregion

	int min_v = INT_MAX, min, j;
	float sum = 0.0;

#pragma region 2. сумма елементов

	for (int i = 0; i < 9; i++)
	{
		sum += a[i];
	}

	cout << "Summa vseh elementov massiva = " << sum << endl;

#pragma endregion

	float sra = sum / x;

	cout << "Srednee arifmeti4eskoe = " << sra << endl;


	int n;

	if (sra > 0) n = x * 2 / 3; else n = x * 1 / 3;
	cout << endl;

#pragma region 3. сортировка

	for (int i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{

			if (a[j] < min_v) {
				min_v = a[j];
				min = j;
			}
		}

		a[min] = a[i];
		a[i] = min_v;

		cout << a[i] << " ";

		min_v = INT_MAX;
	}

#pragma endregion

	cout << "/ ";

#pragma region 4. расположение в обратном порядке

	for (int i = n; i <x - (x - n) / 2; i++)
	{
		swap(a[i], a[x + n - i - 1]);
	}

#pragma endregion

	for (int i = n; i < x; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	return 0;
}*/


