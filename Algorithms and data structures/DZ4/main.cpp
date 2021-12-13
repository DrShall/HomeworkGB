// 1. Реализовать функцию возведения числа [a] в степень [b] рекурсивно,
//используя свойство четности степени

// 2. Реализовать функцию возведения числа [a] в степень [b]:
//               Рекурсивно.
//               Рекурсивно, используя свойство чётности степени
// (то есть, если степень, в которую нужно возвести число, чётная, основание
// возводится в квадрат, а показатель делится на два, а если степень
// нечётная - результат умножается на основание, а показатель уменьшается на единицу)

// 3. Реализовать нахождение количества маршрутов шахматного короля
// с препятствиями (где единица - это наличие препятствия,
// а ноль - свободная для хода клетка)
//
// Результатом работы должен стать один файл с кодом на языке С, содержащий
//функцию main и четыре функции, соответствующие каждому из заданий.

#include <iostream>
#include <time.h>

using namespace std;

void toBin(int);
int Pow(int, int);
int Pow2(int, int);
int routes(int, int, int *, int);
void printArr(int*, int);
void initArr(int*, int);

int main()
{
	int num, deg;

	cout << "Enter number: ";
	cin >> num;
	cout << "Enter degree: ";
	cin >> deg;

	if(num == 0 || deg < 0)   //работаем только с положительными степенями и числами
	{
		cout << "Incorrect input" << endl;
		return 0;
	}

	// Task1
	cout << num << " in binary is ";
	toBin(num);
	cout << endl;

	// Task2-1
	cout <<"Number " << num << " in power " << deg << " is " << Pow(num, deg) <<
		   " (funstion Pow() )" <<endl;

	// Task2-2
	cout <<"Number " << num << " in power " << deg << " is " << Pow2(num, deg) <<
		   " (funstion Pow2() )" << endl;

	// Task3
	// Сделанные ограничения - по нулевым строке и столбцу не может быть препятствий
	int sizeField = 8;
	int array[sizeField*sizeField];   //  поле препятствий
	initArr(array, sizeField);
	cout << "Obstacle field:" << endl;
	printArr(array, sizeField);
	cout << endl;

	cout << "Field of routes:" << endl;
	for(int i = 0; i < sizeField; ++i)
	{
		for(int j = 0; j < sizeField; ++j)
			cout << routes( i, j, array, sizeField) << "\t";
		cout << endl;
	}

	return 0;
}

void toBin(int n)
{
	if( n == 0)
		return;

	int d = n % 2;

	toBin( n / 2);

	cout << d;
}

int Pow(int x, int d)
{
	if( d == 0)
		return 1;
	return x*Pow( x, d-1);   //x^d=x*x^(d-1)
}

int Pow2(int x, int d)
{
	if( d == 0)
		return 1;
	if( d % 2 == 0)
		return Pow2( x * x, d / 2);   //если степень четная то x^d=(x*x)^(d/2)
	else
		return x*Pow2( x, d-1);   //если степень нечетная то x^d=x*x^(d-1)
}

int routes(int row, int col, int* arr, int s)
{
	if(row == 0 && col == 0 || arr[row*s+col] == 1)   //если мы в начальной точке или на препятствии
		return 0;
	else if (row == 0 || col == 0)
		return 1;
	else   // суммируем ходы которыми мы можем прийти сверху, слева и по диагонали
		return routes(row, col - 1, arr, s) + routes( row - 1, col, arr, s) + routes(row - 1, col -1, arr, s);
}

void printArr(int* Arr, int s)
{
	for(int i = 0; i < s; ++i)
	{
		for(int j = 0; j < s; ++j)
			cout << Arr[i*s+j] << "\t";
		cout << endl;
	}
}

void initArr(int* Arr, int s)
{
	srand(time(0));

	for(int i = 0; i < s; ++i)
		for(int j = 0; j < s; ++j)
		{
			if( i == 0 || j == 0)   // Сделанные ограничения - по нулевым строке и столбцу не может быть препятствий
				Arr[i*s+j] = 0;
			else
				Arr[i*s+j] = (rand() % 5 == 1) ? 1 : 0;
		}
}
