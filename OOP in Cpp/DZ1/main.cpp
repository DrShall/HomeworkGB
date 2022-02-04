/* ======================================================================
1. Создать класс Power, который содержит два вещественных числа.
Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел.
 Еще создать два метода: один с именем set, который позволит присваивать значения
 объявленным в классе переменным, второй — calculate, который будет выводить результат
возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.
2. Написать класс с именем RGBA, который содержит 4 переменные-члена типа
 std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу).
 Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
 Создать конструктор со списком инициализации членов, который позволит пользователю передавать
 значения для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов.
3. Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
• private-массив целых чисел длиной 10;

• private целочисленное значение для отслеживания длины стека;

• public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;

• public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false,
 если массив уже заполнен, и true в противном случае;

• public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений,
то должно выводиться предупреждение;

• public-метод с именем print(), который будет выводить все значения стека.

Код main():

int main()
{
Stack stack;
stack.reset();
stack.print();

stack.push(3);
stack.push(7);
stack.push(5);
stack.print();

stack.pop();
stack.print();

stack.pop();
stack.pop();
stack.print();

return 0;
}

Этот код должен выводить:
( )
( 3 7 5 )
( 3 7 )
( )
======================================================================*/

#include <iostream>
#include <math.h>

using namespace std;

class Power
{
	double x;
	double y;
	public:
		Power():x( 1.0 ), y( 0.0 ){}
		void setVar(double x, double y)
		{
			this->x = x;
			this->y = y;
		}
		double calculate()
		{
			return pow( x, y);
		}
};

class RGBA
{
		uint8_t m_red;
		uint8_t m_green;
		uint8_t m_blue;
		uint8_t m_alpha;
	public:
		RGBA(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 255):
			m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
		{		}
		void print()
		{
			cout << "red = " << static_cast<int>( m_red ) << endl;
			cout << "green = " << static_cast<int>( m_green ) << endl;
			cout << "blue = " << static_cast<int>( m_blue ) << endl;
			cout << "alpha = " << static_cast<int>( m_alpha ) << endl;
		}
};

class Stack
{
		int st[10];
		int lenth;
	public:
		Stack(): lenth(0)
		{
			for(int x: st)
				x = 0;
		}
		void reset()
		{
			for(int x: st)
				x = 0;
			lenth = 0;
		}
		void print()
		{
			cout << "( ";
			for(int i = 0; i < lenth; ++i)
				cout << st[i] << " ";
			cout << ")" << endl;
		}
		bool push(int val)
		{
			if(lenth < 10)
			{
				st[lenth++] = val;
				return true;
			}
			else
				return false;
		}
		void pop()
		{
			if(lenth)
				--lenth;
			else
				cout << "Stack is empty!" << endl;
		}
};

int main()
{
	// Task 1
	cout << " Task 1" << endl;
	Power power;
	power.setVar(2.3, 4.2);
	cout << power.calculate() << endl;

	// Task 2
	cout << endl << " Task 2" << endl;
	RGBA rgb1;
	cout << "Object RGBA (default):" << endl;
	rgb1.print();
	RGBA rgb2(13, 24, 35, 113);
	cout << "Object RGBA (initializing list):" << endl;
	rgb2.print();

	// Task 3
	cout << endl << " Task 3" << endl;
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	// проверки
	stack.pop();
	stack.reset();

	for(int i = 0; i < 12; ++i)
		stack.push(i+1);
	stack.print();
}
