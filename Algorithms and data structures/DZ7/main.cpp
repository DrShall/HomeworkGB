 
// 1. Описать в коде улучшенный алгоритм быстрой сортировки
// 2. Сортировать в массиве целых положительных чисел только чётные числа,
//нечётные оставив на своих местах при помощи алгоритма блочной сортировки,
//то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 6 5 9 8 8 7 3]
//
//Результатом работы должен стать один файл с кодом на языке С,
//содержащий функцию main и функции, необходимые для реализации сортировок

#include <iostream>
#include <time.h>

using namespace std;

void qquickSort(int*, int, int);
void quickSort(int*, int, int);
void sortInsert(int*, int);
void blockSort(int*, int);
void printArr(int*, int);
void initArr(int*, int);

int main()
{
	int size;
	cout << "Input array size: ";
	cin >> size;
	int* arr = new int[size];

	initArr(arr, size);
	printArr(arr, size);

	//   Task 1

//	int a[]={0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};   //проверка примера из задания
//	printArr(a,12);
//	blockSort(a,12);
//	printArr(a,12);

//	sortInsert(arr, size);
//	quickSort(arr, 0, size-1);
//	qquickSort(arr, 0, size-1);
	blockSort(arr, size);
	printArr(arr, size);

	delete [] arr;
	return 0;
}

void qquickSort(int* arr, int first, int last)
{
	if(last>10)
		{
			if(arr[first]>arr[(first+last)/2])
				swap(arr[first], arr[(first+last)/2]);
			else if(arr[(first+last)/2]>arr[last])
				swap(arr[(first+last)/2], arr[last]);
			else if(arr[first]>arr[(first+last)/2])
				swap(arr[first], arr[(first+last)/2]);

			quickSort(arr, first, last);
		}
	else
		sortInsert(arr, last);
}

void quickSort(int* arr, int first, int last)
{
	int i = first, j = last;
	int x = arr[(first+last)/2];
	do
	{
		while(arr[i] < x) i++;
		while(arr[j] > x) j--;

		if(i<=j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	while(i<=j);

	if(i<last) quickSort(arr, i, last);
	if(first<j) quickSort(arr, first, j);
}

void sortInsert(int* arr, int size)
{
	int temp, pos;
	for(int i = 1; i < size; ++i)
	{
		temp = arr[i];
		pos = i -1;
		while(pos >= 0 && arr[pos] > temp)
		{
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos+1] = temp;
	}
}

void printArr(int* Arr, int s)
{
	cout << endl;
	for(int i = 0, dec = 1; i < s; ++i, ++dec)
	{
		cout.width(4);
		cout << Arr[i];
		if(dec == 10)
		{
			dec = 0;
			cout << endl;
		}
	}
	cout << endl;
}

void initArr(int* Arr, int s)
{
	srand(time(0));

	for(int i = 0; i < s; ++i)
		{
			Arr[i] = rand() % s;
		}
}

void blockSort(int* arr, int size)
{
	const int b = 10, m = size+1;
	int buckets[b][m];

	for(int i = 0; i < b; ++i)
	{
		buckets[i][size] = 0;
	}
	for(int digit = 1; digit < 1000000000; digit*=10)
	{
		int indexs[size];   //массив индексов четных чисел в изначальном массиве
		int numberOfEven = 0;   //счетчик четных чисел

		for(int i = 0; i < size; i++)
		{
			if(arr[i] % 2 == 1)   //если число нечетное, то пропускаем его
				continue;
			indexs[numberOfEven++] = i;   //если четное сохраняем индекс и увеличиваем счетчик

			int d = (arr[i]/digit)%b;
			//int counter = buckets[d][max];
			//buckets[d][counter] = arr[i];
			//counter++;
			//buckets[d][max] = counter;
			buckets[d][buckets[d][size]++] = arr[i];
		}
		int ind = 0;
		for(int i = 0; i < b; ++i)
		{
			for(int j = 0; j < buckets[i][size]; ++j)
			{
				arr[indexs[ind]] = buckets[i][j];
				ind++;
			}
			buckets[i][size] = 0;
		}
	}
}
