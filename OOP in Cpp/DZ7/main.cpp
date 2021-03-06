/* ======================================================================
1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.
Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя today и date.
Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы
 доступа к полям класса Date, а также выведите на экран данные всего объекта с помощью
 перегруженного оператора вывода. Затем переместите ресурс, которым владеет
 указатель today в указатель date. Проверьте, являются ли нулевыми указатели today и date
 и выведите соответствующую информацию об этом в консоль.

2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
• Создайте функцию, которая принимает в качестве параметра два умных указателя
 типа Date и сравнивает их между собой (сравнение происходит по датам).
 Функция должна вернуть более позднюю дату.
• Создайте функцию, которая обменивает ресурсами (датами) два умных указателя,
 переданных в функцию в качестве параметров.

Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.

3. Создать класс Deck, который наследует от класса Hand и представляет собой колоду карт. Класс Deck имеет 4 метода:
• vold Populate() - Создает стандартную колоду из 52 карт, вызывается из конструктора.
• void Shuffle() - Метод, который тасует карты, можно использовать функцию из алгоритмов STL random_shuffle
• vold Deal (Hand& aHand) - метод, который раздает в руку одну карту
• void AddltionalCards (GenericPlayer& aGenerlcPlayer) - раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать

Обратите внимание на применение полиморфизма. В каких методах применяется этот принцип ООП?

4. Реализовать класс Game, который представляет собой основной процесс игры. У этого класса будет 3 поля:
• колода карт
• рука дилера
• вектор игроков.
Конструктор класса принимает в качестве параметра вектор имен игроков и создает объекты самих игроков.
 В конструкторе создается колода карт и затем перемешивается.
Также класс имеет один метод play(). В этом методе раздаются каждому игроку по две стартовые карты,
 а первая карта дилера прячется. Далее выводится на экран информация о картах каждого игра,
 в т.ч. и для дилера. Затем раздаются игрокам дополнительные карты. Потом показывается первая карта
 дилера и дилер набирает карты, если ему надо. После этого выводится сообщение, кто победил,
 а кто проиграл. В конце руки всех игроков очищаются.

5. 5. Написать функцию main() к игре Блекджек. В этой функции вводятся имена игроков.
 Создается объект класса Game и запускается игровой процесс. Предусмотреть возможность повторной игры.
======================================================================*/

#include <iostream>
#include <memory>
#include "blackjack.h"
#include "myclasses.h"

using namespace std;

shared_ptr<Date> compareDate(shared_ptr<Date> first, shared_ptr<Date> second)
{
	int d1 = first->getDay();
	int m1 = first->getMonth();
	int y1 = first->getYear();
	int d2 = second->getDay();
	int m2 = second->getMonth();
	int y2 = second->getYear();
	if(y1 > y2)
		return first;
	else if(y1 < y2)
		return second;
	else if(m1 > m2)
		return first;
	else if(m1 < m2)
		return second;
	else if(d1 > d2)
		return first;
	else if(d1 < d2)
		return second;
	else
		return first;   //если даты равны возвращаем любое
}

void swapDate(shared_ptr<Date> first, shared_ptr<Date> second)
{
	auto tmp = make_shared<Date>();
	tmp->setDay(first->getDay());
	tmp->setMonth(first->getMonth());
	tmp->setYear(first->getYear());
	first->setDay(second->getDay());
	first->setMonth(second->getMonth());
	first->setYear(second->getYear());
	second->setDay(tmp->getDay());
	second->setMonth(tmp->getMonth());
	second->setYear(tmp->getYear());
}

int main()
{
	// Task 1
	{
	cout << " Task 1" << endl;
	auto today = make_shared<Date>();
	cout << *today << endl;
	today->setDay(15);
	today->setMonth(05);
	today->setYear(2023);
	cout << *today << endl;
	auto date = today;
	cout << "today - " << today << "\tdate - " << date << endl;
	}


	// Task 2
	{
	cout << endl << " Task 2" << endl;
	auto date1 = make_shared<Date>(7,11,2017);
	auto date2 = make_shared<Date>(6,10,2015);
	cout << (*compareDate(date1, date2)) << endl;

	cout << "date1: " << *date1 << " date2: " << *date2 << endl;
	swapDate(date1, date2);
	cout << "date1: " << *date1 << " date2: " << *date2 << endl;
	}

	// Blackjack
	{
		cout << "\t\tWelcome to Blackjack!" << endl;

			int numPlayers = 0;
			while (numPlayers < 1 || numPlayers > 7)
			{
				cout << "How many players? (1 - 7): ";
				cin >> numPlayers;
			}

			vector<string> names;
			string name;
			for (int i = 0; i < numPlayers; ++i)
			{
				cout << "Enter player " << i+1 <<" name: ";
				cin >> name;
				names.push_back(name);
			}
			cout << endl;

			Blackjack aGame(names);
			char choice = 'y';
			while (choice != 'n' && choice != 'N')
			{
				aGame.play();
				cout << endl << "\nDo you want to play again? (Y/N): ";
				cin >> choice;
			}
	}
}
