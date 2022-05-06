/* ======================================================================
1. Написать функцию, добавляющую в конец списка вещественных чисел элемент,
 значение которого равно среднему арифметическому всех его элементов.

2. Создать класс, представляющий матрицу. Реализовать в нем метод, вычисляющий определитель матрицы.
 Для реализации используйте контейнеры из STL.

3. Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться
 по диапазону целых чисел в цикле for-range-based.
======================================================================*/

#include <iostream>
#include <ctime>
#include <list>
#include "myclasses.h"

using namespace std;

int main()
{
	{ // Task 1
		cout << endl << "Task 1." << endl;

		srand(time(NULL));
		int num = 15;
		list<double> L(num);

		for(auto &it: L)
		{
			it = ( rand() % 10000) / 100.0;
			cout << it << " ";
		}
		pushBackAverage(L);

		for(auto &it: L)   // проверка
		{
			cout << it << " ";
		}
	}

	{ // Task 2
		cout << endl << "Task 2." << endl;

		int size = 4;
		Matrix matrix(size);
		matrix.print();
		cout << matrix.det() << endl;
//		cout << "Determinate = " << matrix.det() << endl;
	}

	{ // Task 3
		cout << endl << "Task 3." << endl;


	}
}
