/* ======================================================================
1. Добавить в контейнерный класс, который был написан в этом уроке, методы:
• для удаления последнего элемента массива (аналог функции pop_back() в векторах)
• для удаления первого элемента массива (аналог pop_front() в векторах)
• для сортировки массива
• для вывода на экран элементов.

2. Дан вектор чисел, требуется выяснить, сколько среди них различных.
Постараться использовать максимально быстрый алгоритм.

3. Реализовать класс Hand, который представляет собой коллекцию карт.
В классе будет одно поле: вектор указателей карт (удобно использовать вектор,
 т.к. это по сути динамический массив, а тип его элементов должен быть - указатель
 на объекты класса Card). Также в классе Hand должно быть 3 метода:
• метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает
 в качестве параметра указатель на новую карту
• метод Clear, который очищает руку от карт
• метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть
 возможность того, что туз может быть равен 11).
======================================================================*/

#include <iostream>
#include <vector>
#include<map>
#include<time.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////////

#include "arrayint.h"

int main()
{
	// Task 1
	{
	cout << " Task 1" << endl;
	int sizeArr = 9;
	ArrayInt arr(sizeArr);
	arr.print();
	arr.push_back(13);
	arr.print();
	for(int i = sizeArr-1; i>=0; --i)
		arr[sizeArr-i-1] = i;
	arr.print();
	arr.at(3,7);
	arr.print();
	arr.push_back(12);
	arr.print();
	arr.pop_back();
	arr.print();
	arr.pop_front();
	arr.print();
	arr.sort();
	arr.print();
	}


	// Task 2
	{
	cout << endl << " Task 2" << endl;
	srand(time(NULL));
	int sizeVector = 20;
	vector<int> vec;
	for(int i = 0; i < sizeVector; ++i)   //заполняем вектор значениями
	{
		vec.push_back(rand()%10);
	}
	for(int i = 0; i < sizeVector; ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	map<int,int> numberOfUnique;
	for(int i = 0; i < sizeVector; ++i)   // подсчет сколько раз встречается каждый элемент
	{
		if(numberOfUnique.find(vec[i]) != numberOfUnique.end())
		{
			numberOfUnique[vec[i]] ++;
		}
		else
			numberOfUnique.emplace(vec[i],1);
	}
	/*
	for(auto [key, value] : numberOfUnique)
	{
		cout << key << " - " << value << endl;
	}
	cout << endl;*/
	cout << "In the vecotor " << numberOfUnique.size() << " unique elements" << endl;

	}

	// Task 3
	{
	cout << endl << " Task 3" << endl;

	}

}
