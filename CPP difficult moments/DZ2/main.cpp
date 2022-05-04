/* ======================================================================
1. Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает местами значения,
 на которые указывают эти указатели (нужно обменивать именно сами указатели,
 переменные должны оставаться в тех же адресах памяти).

2. Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей и сортирует
 указатели по значениям, на которые они указывают.

3. Подсчитайте количество гласных букв в книге “Война и мир”. Для подсчета используйте 4 способа:
○ count_if и find
○ count_if и цикл for
○ цикл for и find
○ 2 цикла for
Замерьте время каждого способа подсчета и сделайте выводы.
======================================================================*/

#include <iostream>
#include <fstream>
#include "myclasses.h"

using namespace std;

int main()
{
	{ // Task 1
		cout << endl << "Task 1." << endl;

		int d1 = 11111, d2 = 22222;
		int* ptr1 = &d1, *ptr2 = &d2;
		cout << "*ptr1 = " << *ptr1 << " ptr1 = " << ptr1 << "\t";
		cout << "*ptr2 = " << *ptr2 << " ptr2 = " << ptr2 << endl;
		swapPtr(&ptr1, &ptr2);
		cout << "*ptr1 = " << *ptr1 << " ptr1 = " << ptr1 << "\t";
		cout << "*ptr2 = " << *ptr2 << " ptr2 = " << ptr2 << endl;
	}

	{ // Task 2
		cout << endl << "Task 2." << endl;

		int length = 10;
		vector<int*> vec;

		for (int i = 0; i < length; ++i)
		{
			int *tmp = new int;
			*tmp = rand() % (length * 2);
			vec.push_back(tmp);
		}

		for (int i = 0; i < length; ++i)
		{
			cout << *vec[i] << ' ';
		}

		cout << endl;

		sortPointers(vec);

		for (int i = 0; i < length; ++i)
		{
			cout << *vec[i] << ' ';
		}

		cout << endl;
	}

	{ // Task 3
		cout << endl << "Task 3." << endl;

		ifstream file("WarAndPeace.txt");
		if(!file)
		{
			cout << "Не удалось открыть файл!" << endl;
			exit(-1);
		}
		file.seekg(0, ios::end);
		size_t size = file.tellg();
		file.seekg(0);
		string str(size, ' ');
		file.read(&str[0], size);

		const string vowels{"АУОЫИЭЯЁЕауоыиэяюёе"};

		Timer t("way1");
		way1(str, vowels);
		t.print();
		cout << endl;
		t.start("way2");
		way2(str, vowels);
		t.print();
		cout << endl;
		t.start("way3");
		way3(str, vowels);
		t.print();
		cout << endl;
		t.start("way4");
		way4(str, vowels);
		t.print();
		cout << endl;
	}
}
