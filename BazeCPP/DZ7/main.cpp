 
#include <iostream>
#include <fstream>
#include <string>

#include "mylib.h"

using namespace std;

//==============================================================================
//    Задание 1
// Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h)
//во втором модуле mylib объявить 3 функции: для инициализации массива (типа float),
//печати его на экран и подсчета количества отрицательных и положительных элементов.
//Вызывайте эти 3-и функции из main для работы с массивом.
//==============================================================================


void Task1()
{
	double *pArray = nullptr;
	size_t size;
	cout << "Введите размер массива: ";
	cin >> size;

	pArray = new double[size];

	MySpace::InitArray(pArray, size);
	MySpace::PrintArray(pArray, size);
	MySpace::AnalysisArray(pArray, size);

	delete [] pArray;
}

//==============================================================================
//    Задание 2
// Описать макрокоманду (через директиву define), проверяющую, входит ли переданное
//ей число (введенное с клавиатуры) в диапазон от нуля (включительно) до переданного
//ей второго аргумента (исключительно) и возвращает true или false, вывести
//на экран «true» или «false».
//==============================================================================

#define IN_LIMIT(x, y) (((x) >= 0 && (x) < (y)) ? true : false)
void Task2()
{
	size_t val, limit;
	cout << "Введите вернюю границу диапазона: ";
	cin >> limit;
	cout << "Введите проверяемое значение:";
	cin >> val;

	cout << boolalpha << IN_LIMIT(val, limit) << endl;
}

//==============================================================================
//    Задание 3
// Задайте массив типа int. Пусть его размер задается через директиву препроцессора
//#define. Инициализируйте его через ввод с клавиатуры. Напишите для него свою
//функцию сортировки (например Пузырьком). Реализуйте перестановку элементов
//как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
//==============================================================================

#define SIZE 5
#define SwapInt(a, b);  int temp = (a); (a) = (b); (b) = temp;

void SortArray(int *arr, int size)
{
	for(int i = 0; i < size-1; ++i)
	{
		for(int j = 0; j < size - 1 - i; ++j)
		{
			if(arr[j] > arr[j+1])
			{
				SwapInt(arr[j], arr[j+1]);
			}
		}
	}
}

void Task3()
{
	int array[SIZE];
	for(int i = 0; i < SIZE; ++i)
	{
		cout << "Введите элемент массива array[" << i << "] = ";
		cin >> array[i];
	}

	MySpace::PrintArray(array, SIZE);
	SortArray(array, SIZE);
	MySpace::PrintArray(array, SIZE);
}

//==============================================================================
//    Задание 4
// Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое
//выравнивание с помощью директивы pragma pack. Выделите динамически переменную
//этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof.
//Сохраните эту структуру в текстовый или двоичный файл.
//==============================================================================

void Task4()
{
#pragma pack(push, 1)
	struct Employee
	{
			string surname;
			string name;
			size_t ID;
			string position;
			int salary;
	};
#pragma pack(pop)

	Employee *Vasya = new Employee;
	Vasya->name = "Vasya";
	Vasya->surname = "Petrov";
	Vasya->ID = 1356;
	Vasya->position = "Менеджер";
	Vasya->salary = 45000;

	cout << "Структура содержит следующую информацию:" << endl << "Фамилия - " << Vasya->surname << endl
		 << "Имя - " << Vasya->name << endl << "Табельный номер - " << Vasya->ID << endl
		 << "Должность - " << Vasya->position << endl << "Оклад - " << Vasya->salary << endl
		 << " Структура занимает " << sizeof (*Vasya) << " байт" << endl;

	ofstream fout("Employee_Vasya.bin", ios_base::binary);
	if(fout.is_open())
	{
		fout.write((char*)Vasya, sizeof (*Vasya));
		fout.close();
	}


	delete Vasya;
}

//==============================================================================
//    Задание 5
// Сделайте задание 1 добавив свой неймспейс во втором модуле
//(первое задание тогда можно не делать).
//==============================================================================

void Task5()
{
	cout << "Выполнено в рамках задания №1" << endl;
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
