/* ======================================================================
1. Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов,
 и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза, то вывести его надо один раз).
 Продемонстрировать работу функции, передав итераторы различных типов.

2. Используя ассоциативный контейнер, напишите программу, которая будет считывать
 данные введенные пользователем из стандартного потока ввода и разбивать их на предложения.
 Далее программа должна вывести пользователю все предложения, а также количество слов в них,
 отсортировав предложения по количеству слов.
======================================================================*/

#include <iostream>
#include <ctime>
#include <math.h>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include "myclasses.h"

using namespace std;

int main()
{
	srand(time(NULL));

	{ // Task 1
		cout << endl << "Task 1." << endl;

		vector<string> vec{"одно", "слово", "два", "слово", "гвоздика", "весна", "одно", "пример"};
		cout << "Вектор:" << endl;
		printWords(vec.begin(), vec.end());
		cout << endl;

		list<string> l(vec.begin(), vec.end());
		cout << "Список:" << endl;
		printWords(l.begin(), l.end());
		cout << endl;

		deque<string> deq(vec.begin(), vec.end());
		cout << "Очередь:" << endl;
		printWords(deq.begin(), deq.end());
		cout << endl;
	}

	{ // Task 2
		cout << endl << "Task 2." << endl;

		string input_str;
		cout << "Введите текст:" << endl;
		getline(cin, input_str);
		countSentence( input_str );
		cout << endl;

		cout << input_str << endl;
	}
}
