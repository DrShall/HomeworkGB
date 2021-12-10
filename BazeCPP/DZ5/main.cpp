 
#include <iostream>
#include <iomanip>
using namespace std;

//==============================================================================
//    Задание 1
// Написать функцию которая выводит массив double чисел на экран.
//Параметры функции это сам массив и его размер. Вызвать эту функцию из main.
//==============================================================================
void printArray(const double A[], const int s)
{
	for(int i = 0; i < s; ++i)
		cout << A[i] << ' ';
	cout << endl;
}

void Task1()
{
	const int sizeArr = 10;
	double arr[sizeArr]{3.14, 2.71, 9.8, 5.6, 2.1, 5.55, 7.7, 8.8, 9.9};

	printArray(arr, sizeArr);
}

//==============================================================================
//    Задание 2
// Задать целочисленный массив, состоящий из элементов 0 и 1.
//Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую
//в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.
//==============================================================================
void printArray(const int A[], const int s)
{
	for(int i = 0; i < s; ++i)
		cout << A[i] << ' ';
	cout << endl;
}

void changeArr(int A[], const int S)
{
	for(int i = 0; i < S; ++i)
	{
		if(A[i] == 1)
			A[i] = 0;
		else
			A[i] = 1;
	}
}

void Task2()
{
	const size_t sizeArr = 8;
	int arrOfBool[sizeArr]{};

	for(int i = 0; i < sizeArr; ++i)
		arrOfBool[i] = rand()%2;

	printArray(arrOfBool, sizeArr);
	changeArr(arrOfBool, sizeArr);
	printArray(arrOfBool, sizeArr);
}

//==============================================================================
//    Задание 3
// Задать пустой целочисленный массив размером 8. Написать функцию, которая
//с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.
//==============================================================================

void initArr(int Arr[], int size)
{
	int k = 1;
	for(int i = 0; i < size; ++i)
	{
		Arr[i] = k;
		k+=3;
	}
}

void Task3()
{
	const int size = 8;
	int arr[size]{};
	initArr(arr, size);
	printArray(arr, size);
}

//==============================================================================
//    Задание 4
// Написать функцию, которой на вход подаётся одномерный массив и число n
//(может быть положительным, или отрицательным), при этом метод должен циклически
//сместить все элементы массива на n позиций.
//==============================================================================

void changeArr(int Arr[], int s, int n)
{
	int temp;
	if(n == 0)
		return;
	else if(n > 0)
	{
		for(int k = 0; k < n; k++)
		{
			temp = Arr[s-1];
			for(int i = s - 2; i >= 0; --i)
			{
				Arr[i+1] = Arr[i];
			}
			Arr[0] = temp;
		}
	}
	else
	{
		for(int k = 0; k > n; --k)
		{
			temp = Arr[0];
			for(int i = 0; i < s; ++i)
			{
				Arr[i] = Arr[i+1];
			}
			Arr[s-1] = temp;
		}
	}
}

void Task4()
{
	const int size = 7;
	int array[size]{}, n = 0;

	for(int i = 0; i < size; ++i)
		array[i] = rand()%10;

	cout << "Введите сдвиг: ";
	cin >> n;

	printArray(array, size);
	changeArr(array, size, n);
	printArray(array, size);
}

//==============================================================================
//    Задание 5
// Написать функцию, которой передается не пустой одномерный целочисленный массив,
//она должна вернуть истину если в массиве есть место, в котором сумма левой и правой
//части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true,
//	checkBalance ([2, 1, 1, 2, 1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → true.
//  Абстрактная граница показана символами ||, эти символы в массив не входят.
//==============================================================================
bool checkBalance(int arr[], const int size)
{
	int sumLeft = 0, sumRight = 0;
	if(arr == nullptr || size == 0)
		return false;
	for(int i = 0; i < size; ++i)
	{
		sumLeft = 0;
		sumRight = 0;
		for( int j = 0; j <= i; ++j)
			sumLeft+=arr[j];
		for(int k = i+1; k < size; ++k)
			sumRight += arr[k];
		if(sumLeft == sumRight)
			return true;
	}
	return false;
}

void Task5()
{
	int arr1[]{ 1, 1, 1, 2, 1},
		arr2[]{2, 1, 1, 2, 1},
		arr3[]{10, 1, 2, 3, 4};

	cout << boolalpha;
	printArray(arr1, sizeof (arr1)/sizeof(arr1[0]));
	cout << checkBalance(arr1, sizeof (arr1)/sizeof(arr1[0])) << endl;
	printArray(arr2, sizeof (arr2)/sizeof(arr2[0]));
	cout << checkBalance(arr2, sizeof (arr2)/sizeof(arr2[0])) << endl;
	printArray(arr3, sizeof (arr3)/sizeof(arr3[0]));
	cout << checkBalance(arr3, sizeof (arr3)/sizeof(arr3[0])) << endl;
}

int main()
{
	srand(time(NULL));

	cout << endl << "Task1" << endl;
	Task1();
	cout << endl << "Task2" << endl;
	Task2();
	cout << endl << "Task3" << endl;
	Task3();
	cout << endl << "Task4" << endl;
	Task4();
	cout << endl << "Task5" << endl;
	Task5();
	return 0;
}
