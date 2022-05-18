/* ======================================================================
1. Имеется отсортированный массив целых чисел. Необходимо разработать функцию insert_sorted,
 которая принимает вектор и новое число и вставляет новое число в определенную позицию в векторе,
 чтобы упорядоченность контейнера сохранялась. Реализуйте шаблонную функцию insert_sorted,
 которая сможет аналогично работать с любым контейнером, содержащим любой тип значения.

2. Сгенерируйте вектор a, состоящий из 100 вещественный чисел, представляющий собой
 значения аналогового сигнала. На основе этого массива чисел создайте другой вектор
 целых чисел b, представляющий цифровой сигнал, в котором будут откинуты дробные части чисел.
 Выведите получившиеся массивы чисел. Посчитайте ошибку, которой обладает цифровой сигнал
 по сравнению с аналоговым по формуле:
где:
N - количество элементов в векторе,
a - элемент вектора с дробными числами, b - элемент вектора с целыми числами
Постарайтесь воспользоваться алгоритмическими функциями, не используя циклы.
======================================================================*/

#include <iostream>
#include <ctime>
#include <math.h>
#include "myclasses.h"

using namespace std;

int main()
{
	srand(time(NULL));

	{ // Task 1
		cout << endl << "Task 1." << endl;

		int size = 10;
		vector<int> vec;
		vec.reserve(size);

		for(int i = 0; i < size; ++i)
		{
			vec.push_back(rand()%(size * 2));
		}
		cout << "Unsorted vector:" << endl;
		for( auto it : vec)
			cout << it << " ";
		cout << endl << "Sorted vector:" << endl;
		sort(vec.begin(), vec.end());
		for( auto it : vec)
			cout << it << " ";
		cout << endl;

		int el = rand()%(size * 2);
		insert_sorted( vec, el );
		cout << "Insert " << el << endl;
		cout << "Inserted vector:" << endl;
		for( auto it : vec)
			cout << it << " ";
		cout << endl;
	}

	{ // Task 2
		cout << endl << "Task 2." << endl;

		int size = 100;
		vector<double> a(size);
		cout << "Vector a:" << endl;
		for_each(a.begin(), a.end(), [size](double &it){ it = ( rand() % (size*size) ) / static_cast<double>(size) - size/2; });
		for_each(a.begin(), a.end(), [size](double &it){ cout << it << " ";});
		cout << endl;

		vector<int> b(size);
		cout << "Vector b:" << endl;
		auto it_a = a.begin();
		for_each(b.begin(), b.end(), [size, it_a](int &it) mutable { it = static_cast<int>(*(it_a++)); });
		for_each(b.begin(), b.end(), [size](int &it){ cout << it << " "; } );

		double sum = 0.0;
		for_each(a.begin(), a.end(), [&sum](const double &it){ sum += pow( it - static_cast<int>(it), 2); });
		cout << endl << "Mistake = " << sum << endl;
	}
}
