// 1. Реализовать пузырьковую сортировку двумерного массива
//например, массив
//1,9,2
//5,7,6
//4,3,8
//должен на выходе стать
//1,2,3
//4,5,6
//7,8,9

//2. Описать подробную блок-схему алгоритма Трабба-Прадо-Кнута:
//1 - запросить у пользователя 11 чисел и записать их в последовательность П
//2 - инвертировать последовательность П
//3 - для каждого элемента последовательности П произвести вычисление по формуле
//sqrt(fabs(Х)) + 5 * pow(Х, 3) и если результат вычислений превышает 400 - проинформировать пользователя.

//3. Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С(алгоритм расписан в предыдущем задании)

//Результатом выполнения задания должны стать два файла: с кодом на языке С,
//содержащим функцию main и две функции, соответствующие сортировке и алгоритму
//Трабба-Прадо-Кнута, и с изображением в любом популярном формате (jpg, png, gif)

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
