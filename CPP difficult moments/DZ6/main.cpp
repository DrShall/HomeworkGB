/* ======================================================================
1. Создайте потокобезопасную оболочку для объекта cout. Назовите ее pcout.
 Необходимо, чтобы несколько потоков могли обращаться к pcout и информация выводилась
 в консоль. Продемонстрируйте работу pcout.

2. Реализовать функцию, возвращающую i-ое простое число (например, миллионное простое
 число равно 15485863). Вычисления реализовать во вторичном потоке. В консоли отображать
 прогресс вычисления (в основном потоке).

3. Промоделировать следующую ситуацию. Есть два человека (2 потока): хозяин и вор.
 Хозяин приносит домой вещи (функция добавляющая случайное число в вектор
 с периодичностью 1 раз в секунду). При этом у каждой вещи есть своя ценность.
 Вор забирает вещи (функция, которая находит наибольшее число и удаляет из вектора
 с периодичностью 1 раз в 0.5 секунд), каждый раз забирает вещь с наибольшей ценностью.
======================================================================*/

#include <iostream>
#include <vector>
#include "myclasses.h"

using namespace std;


int main()
{
	srand(time(NULL));

	{ // Task 1
		cout << endl << "Task 1." << endl;

		thread t1(test_thread, 1);
		thread t2(test_thread, 2);
		thread t3(test_thread, 3);
		t1.join();
		t2.join();
		t3.join();
	}

	{ // Task 2
		cout << endl << "Task 2." << endl;

		size_t n;
		cout << "Enter number of prime number: ";
		cin >> n;
		size_t result = 0;
		thread primeNum( [&]{ result = sieve(n); } );

		for(size_t i =1; i <= n; ++i)   //прогресс нахождения простого числа
		{
			unique_lock<mutex> lk(sm);
			prime_plus.wait(lk, []{ return !data_i.empty();});
			size_t t = data_i.front();
			data_i.pop();
			cout << ( i * 100 / static_cast<double>(t)) << "%";
			lk.unlock();
		}

		primeNum.join();
		cout << endl << "This prime number is " << result << endl;
	}

	{ // Task 3
		cout << endl << "Task 3." << endl;


	}
}
