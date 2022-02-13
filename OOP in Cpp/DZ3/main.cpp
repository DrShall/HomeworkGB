/* ======================================================================
1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы
Parallelogram (параллелограмм) и Circle (круг). Класс Parallelogram — базовый для классов
Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). Для всех классов создать конструкторы.
 Для класса Figure добавить чисто виртуальную функцию area() (площадь). Во всех остальных классах
 переопределить эту функцию, исходя из геометрических формул нахождения площади.
2. Создать класс Car (автомобиль) с полями company (компания) и model (модель).
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
От этих классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов,
 чтобы они выводили данные о классах. Создать объекты для каждого из классов и посмотреть,
 в какой последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз смерти».
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового
 класса создает самый "дочерний" класс.

3. Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
 Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
унарный оператор (-)
логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).

Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности,
 попробуйте перегрузить один через другой.

Продемонстрировать использование перегруженных операторов.

4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля:
 масть, значение карты и положение карты (вверх лицом или рубашкой).
 Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool.
 Также в этом классе должно быть два метода:
метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх,
 то он ее поворачивает лицом вверх, и наоборот.
метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
======================================================================*/

#include <iostream>
#include <math.h>

using namespace std;

class Figure
{
	public:
		virtual double area() = 0;
};

class Parrallelogram : public Figure   //параллелограмм
{
	protected:
		double length_;
		double height_;
	public:
		Parrallelogram(double length, double height)
		{
			length_ = length;
			height_ = height;
		}
		virtual double area() override
		{
			return length_ * height_;
		}
};

class Rectangle : public Parrallelogram   //прямоугольник
{
	public:
		Rectangle(double length, double height): Parrallelogram(length, height) {}
		virtual double area() override
		{
			return length_ * height_;
		}
};

class Square : public Parrallelogram   //квадрат
{
	public:
		Square(double side): Parrallelogram(side, 0.0) {}
		virtual double area() override
		{
			return length_ * length_;
		}
};

class Rhombus : public Parrallelogram   //ромб
{
	public:
		Rhombus(double length, double height): Parrallelogram(length, height){}
		virtual double area() override
		{
			return length_ * height_;
		}
};

class Circle : public Figure   //круг
{
		double radius_;
	public:
		Circle(double radius) { this->radius_ = radius;}

		virtual double area() override
		{
			return 2 * 3.1459 * radius_;
		}
};
///////////////////////////////////////////////////////////////////////////////
class Car
{
	protected:
		string company_;
		string model_;
	public:
		Car(string company, string model): company_(company), model_(model)
		{
			cout << "Car::Car" << endl;
		}
};

class PassengerCar : virtual public Car
{
	public:
		PassengerCar(string company, string model):Car(company, model)
		{
			cout << "PassengerCar::PassengerCar" << endl;
		}
};

class Bus : virtual public Car
{
	public:
		Bus(string company, string model):Car(company, model)
		{
			cout << "Bus::Bus" << endl;
		}
};

class Minivan : public Bus, public PassengerCar
{
	public:
		Minivan(string company, string model):Car(company, model),Bus(company, model),PassengerCar(company, model)
		{
			cout << "Minivan::Minivan" << endl;
		}
};
///////////////////////////////////////////////////////////////////////////////

#include "fraction.h"

int main()
{
	// Task 1
	{
	cout << " Task 1" << endl;
	Parrallelogram par(2.5, 4.0);
	cout << "Area of Parrallelogram: " << par.area() << endl;
	Rectangle rec(1.5, 6.0);
	cout << "Area of Rectangle: " << rec.area() << endl;
	Square sq(5.5);
	cout << "Area of Square: " << sq.area() << endl;
	Rhombus rhom(3.3, 10.0);
	cout << "Area of Rhombus: " << rhom.area() << endl;
	Circle cir(6.3);
	cout << "Area of Circle: " << cir.area() << endl;
	}


	// Task 2
	{
	cout << endl << " Task 2" << endl;
	cout << "Class Car" << endl;
	Car c("Ford", "T");
	cout << endl << "Class PassengerCar" << endl;
	PassengerCar pascar("Toyota", "Camry");
	cout << endl << "Class Bus" << endl;
	Bus bus("Ikarus","123");
	cout << endl << "Class Minivan" << endl;
	Minivan minivan("VW", "SuperModel");
	}

	// Task 3
	{
	cout << endl << " Task 3" << endl;
	Fraction a(2,3);
	Fraction b(3, 5);
	Fraction c = a * b;
	c.print();
	c = a/b;
	c.print();
	c = a + b;
	c.print();
	c = a - b;
	c.print();
	c = - a;
	(c).print();
	cout << "(a != b) is " << (a != b) << "  (a != a) is " << (a != a) << endl;
	cout <<"(a == b) is " << (a == b) << " (a == a) is " << (a == a) << endl;
	cout <<"(a < b) is " << (a < b) << " (a >= b) is " << (a >= b) << endl;
	cout <<"(a > b) is " << (a > b) << " (a <= b) is " << (a <= b) << endl;
	cout <<"(a > a) is " << (a > a) << " (a <= a) is " << (a <= a) << endl;
	cout <<"(a < a) is " << (a < a) << " (a >= a) is " << (a >= a) << endl;
	}

}
