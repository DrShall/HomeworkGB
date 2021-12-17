 
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
#include <math.h>

using namespace std;

void bubbleSort(int**,int);
void TPK();
void printArr(int**, int);
void initArr(int**, int);

int main()
{
	int size = 3;

	int** array = new int* [size];
	for(int i = 0; i < size; ++i)
		array[i] = new int[size];

	//   Task 1
	initArr(array, size);
	printArr(array, size);
	cout << endl;
	bubbleSort(array,size);
	printArr(array,size);
	cout << endl;

	for(int i = 0; i < size; ++i)
		delete [] array[i];
	delete [] array;

	//Task 3
	TPK();
	return 0;
}

void bubbleSort(int** arr,int s)
{
	for(int i = 0; i < s*s; ++i)
		//for(int j =0; j < s; ++j)
		{
			for(int j = 0; j < s*s - 1; ++j)
			{
				int row = j /s, col = j % s, rowPlus = (j+1) /s, colPlus = (j+1) % s;
				if(arr[row][col] > arr[rowPlus][colPlus])
					swap( arr[row][col], arr[rowPlus][colPlus] );
			}
		}
}

void printArr(int** Arr, int s)
{

	for(int i = 0; i < s; ++i)
	{
		for(int j = 0; j < s; ++j)
		{
			cout.width(2);
			cout << Arr[i][j];
		}
		cout << endl;
	}
}

void initArr(int** Arr, int s)
{
	srand(time(0));

	for(int i = 0; i < s; ++i)
		for(int j = 0; j < s; ++j)
		{
			Arr[i][j] = rand() % 9 + 1;
		}
}

void TPK()
{
	const int s = 11;
	double arr[s];

	for(int i = 0; i < s; ++i)
	{
		cout << "Insert number (" << i+1 << "):";
		cin >> arr[i];
	}

	for(int i = 0; i < s/2; ++i)
		swap(arr[i], arr[s-i-1]);

	for(int i = 0; i < s; ++i)
	{
		if( (sqrt(fabs(arr[i])) + 5 *pow(arr[i], 3)) > 400)
			cout << arr[i] << " in sqrt(fabs(X)) + 5 *pow(X, 3) more than 400" << endl;
	}
}
