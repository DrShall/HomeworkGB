/* ======================================================================
1. Создать класс Person (человек) с полями: имя, возраст, пол и вес.
 Определить методы переназначения имени, изменения возраста и веса.
 Создать производный класс Student (студент), имеющий поле года обучения.
 Определить методы переназначения и увеличения этого значения. Создать счетчик количества
 созданных студентов. В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.
2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
 У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить новый класс GrannySmith, который наследует класс Apple.
int main()
{
Apple a("red");
Banana b;
GrannySmith c;

std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

return 0;
}

Код, приведенный выше, должен давать следующий результат:

My apple is red.
My banana is yellow.
My Granny Smith apple is green.

3. Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++,
 используя объектно-ориентированное программирование. Сколько будет классов в программе?
 Какие классы будут базовыми, а какие производными? Продумать реализацию игры с помощью классов
 и записать результаты в виде комментария в основном файле сдаваемой работы.
======================================================================*/

#include <iostream>
#include <math.h>

using namespace std;

class Person
{
	protected:
		string name;
		int age;
		bool gender;   // 1 - male, 0 - female
		double weight;
	public:
		Person(string name="-", bool gender = 1, int age = 0, double weight = 0)
		{
			this->name = name;
			this->gender = gender;
			this->age = age;
			this->weight = weight;
		}
		void setName(string name)	{ this->name = name;	}
		void setGender(bool gender)	{ this->gender = gender;	}
		void setAge(int age)	{ this->age = age;	}
		void setWeight(double weight)	{ this->weight = weight;	}
};

class Student: public Person
{
	protected:
		int yearOfStudy;
		static int counOfStudent;
	public:
		Student(string name="-", bool gender = 1, int age = 0, double weight = 0, int yearOfStudy = 1111)
		{
			this->name = name;
			this->gender = gender;
			this->age = age;
			this->weight = weight;
			this->yearOfStudy = yearOfStudy;
			counOfStudent++;
		}
		void setYearOfStudy(int year) { yearOfStudy = year; }
		void print()
		{
			cout << "Student name: " << name << endl << "Student gender: " << ( gender ? "male" : "female")
				 << endl << "Student age: " << age << endl << "Student weight: " << weight << endl
				 << "Student year of study: " << yearOfStudy << endl;
		}
		void printCount()
		{ cout << "Number of students: " << counOfStudent; }
};
int Student::counOfStudent = 0;

class Fruit
{
	protected:
		string name;
		string color;
	public:
		Fruit() { }
		string getName() { return name; }
		string getColor() { return color; }
};

class Apple : public Fruit
{
	public:
		Apple(string color)
		{
			name = "apple";
			this->color = color;
		}
};

class Banana : public Fruit
{
	public:
		Banana()
		{
			name = "banana";
			color = "yellow";
		}
};

class GrannySmith : public Apple
{
	public:
		GrannySmith(): Apple("green")
		{
			name = "Granny Smith apple";
		}
};

int main()
{
	// Task 1
	{
	cout << " Task 1" << endl;
	Student Ivan("Ivan", 1, 18, 62.5, 2020);
	Ivan.printCount();
	cout << endl;
	Student Dasha("Dasha", 0, 19, 56.4, 2019);
	Ivan.printCount();
	cout << endl;
	Student Petya("Petya", 1, 21, 72, 2017);
	Ivan.printCount();
	cout << endl << endl;
	Ivan.print();
	cout << endl;
	Dasha.print();
	cout << endl;
	Petya.print();
	}


	// Task 2
	{
	cout << endl << " Task 2" << endl;
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << endl;
	std::cout << "My " << b.getName() << " is " << b.getColor() << endl;
	std::cout << "My " << c.getName() << " is " << c.getColor() << endl;
	}

	// Task 3
	cout << endl << " Task 3" << endl;
    /*
     * class Cards{}; - массив карт, содержит очки, номинал, масть
     * class Deck{}; - наследуется от Cards, добавлена возможность тасования, может выдавать карты
     * class Hand{}; - наследуется от Cards, содержит дополнения для запроса карты, статус (перебор или нет)
     * class Player{}; - наследуется от Hand, класс игрока-человека
     * class Dealer{}; - наследуется от Hand, класс игрока-раздающего/крупье
     * class Blackjack{}; - класс игры, содержит главный цикл игры
     * */

}
