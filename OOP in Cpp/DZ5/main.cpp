/* ======================================================================
1. Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
Следующий код:

int main()
{
Pair1<int> p1(6, 9);
cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

const Pair1<double> p2(3.4, 7.8);
cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

return 0;
}

… должен производить результат:
Pair: 6 9
Pair: 3.4 7.8

2. Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
Следующий код:

int main()
{
Pair<int, double> p1(6, 7.8);
cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

const Pair<double, int> p2(3.4, 5);
cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

return 0;
}

… должен производить следующий результат:
Pair: 6 7.8
Pair: 3.4 5

Подсказка: чтобы определить шаблон с использованием двух разных типов,
просто разделите параметры типа шаблона запятой.

3. Написать шаблон класса StringValuePair, в котором первое значение всегда типа string,
 а второе — любого типа. Этот шаблон класса должен наследовать частично специализированный класс Pair,
 в котором первый параметр — string, а второй — любого типа данных.
Следующий код:

int main()
{
StringValuePair<int> svp("Amazing", 7);
std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
return 0;
}

… должен производить следующий результат:
Pair: Amazing 7

Подсказка: при вызове конструктора класса **Pair* из конструктора класса StringValuePair не забудьте указать,
 что параметры относятся к классу Pair. *

4. Согласно иерархии классов, которая представлена в методичке к уроку 3,
от класса Hand наследует класс GenericPlayer, который обобщенно представляет игрока,
 ведь у нас будет два типа игроков - человек и компьютер. Создать класс GenericPlayer,
в который добавить поле name - имя игрока. Также добавить 3 метода:
• IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
• IsBoosted() - возвращает bool значение, есть ли у игрока перебор
• Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
======================================================================*/

#include <iostream>
#include<string>

using namespace std;

///////////////////////////////////////////////////////////////////////////////

//#include "myclasses.h"

template <typename T>
class Pair1
{
		T a_;
		T b_;
	public:
		Pair1(T a, T b): a_(a), b_(b) { }
		T first() const { return a_;}
		T second() const {return b_;}
};

template  <typename T1, typename T2>
class Pair
{
	protected:
		T1 a_;
		T2 b_;
	public:
		Pair(T1 a, T2 b): a_(a), b_(b) { }
		T1 first() const { return a_;}
		T2 second() const { return b_;}
};

template <typename T>
class StringValuePair : public Pair<string, T>
{
	public:
		StringValuePair(string str, T val): Pair<string, T> (str, val) 	{ }
};

int main()
{
	// Task 1
	{
	cout << " Task 1" << endl;
	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	}


	// Task 2
	{
	cout << endl << " Task 2" << endl;
	Pair<int, double> p1(6, 7.8);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(3.4, 5);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	}

	// Task 3
	{
	cout << endl << " Task 3" << endl;
	StringValuePair<int> svp("Amazing", 7);
	cout << "Pair: " << svp.first() << ' ' << svp.second() << endl;
	}

}
