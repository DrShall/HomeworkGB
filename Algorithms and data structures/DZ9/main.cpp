// 1. Описать очередь с приоритетным исключением
// 2. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
//
//Результатом работы должен стать один файл с кодом на языке С,
//содержащий функцию main, а также функции, необходимые для работы приоритетной
//очереди и перевода систем счисления

#include <iostream>
#include <time.h>

using namespace std;

struct element{
		int data;
		int priority;
};
int top = 0, finish = 0, items = 0;
const int size = 10;
element Queue[size];

int Stack[size] = {0};
int stack_pointer = -1;

bool push_Queue(int, int);
bool pop_Queue();
int pop_Stack();
int push_Stack(int);

int main()
{

	srand(time(NULL));

	// Task 1
	//Записываем и забираем значение со стека
	for(int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 7; ++j)
		{
			if( !push_Queue(rand() % 100, rand() % 5) )
					cout << "Queue is already full." << endl;
		}
		for(int j = 0; j < 7; ++j)
		{
			if( !pop_Queue() )
			{
				cout << " Queue is empty." << endl;
			}
		}
		if( !pop_Queue() )   //проверка удаление элемента из пустого массива
		{
			cout << " Queue is empty." << endl;
		}
	}

	// Task 2
	int val;
	cout << endl << "Input number: ";
	cin >> val;

	cout << endl;
	cout << "Number " << val << " in binary is ";

	while(val)
	{
		if( !push_Stack(val%2) )
		{
			cout << " Stack overflow" << endl;
			return 1;
		}
		val /=2;
	}

	while(true)
	{
		int x = pop_Stack();
		if(x == -1)
			break;
		else
			cout << x;
	}
	cout << endl;

	return 0;
}

bool push_Queue(int d, int pr)
{
	if(items == size)   //если очередь заполнена возвращаем false
		return false;
	else   //иначе сдигаем индекс конца, увиличиваем кол-во и записываем элемент в очередь
	{
		Queue[finish].data = d;
		Queue[finish].priority = pr;
		cout.width(4);
		cout << "Element { " << d << ", " << pr << " } is pushed." << endl;
		finish = (finish + 1) % size;
		items++;
	}
	return true;
}

bool pop_Queue()
{
	if (items == 0)   //если очередь пуста выходим из функции
		return false;

	int ind = top;   //индекс наибольшего приоритета (меньшее значение)

	// проходим по очереди в поисках первого элемента с наименьшим значением приоритета
	if(items > 1)
	{
		int i = top+1;
		do
		{
			if(Queue[i].priority < Queue[ind].priority)
				ind = i;
			i = (i+1)%size;
		}
		while(i != finish);
		cout.width(4);
		cout << "Element { " << Queue[ind].data << ", " << Queue[ind].priority << " } is poped." << endl;
	}

	if(ind == top)
	{
		items--;
		top = (top+1) % size;
	}
	else {
		for(int i = ind; i != finish; i = (i+1)%size)
		{
			Queue[i].data = Queue[(i+1)%size].data;
			Queue[i].priority = Queue[(i+1)%size].priority;
		}
		items--;
		if(finish == 0)
			finish = size-1;
		else
			finish--;
	}

	return true;
}

int pop_Stack()
{
	if( stack_pointer != -1)
	{
		return Stack[stack_pointer--];
	}
	else
		return -1;
}

int push_Stack(int d)
{
	if(stack_pointer < size)
	{
		Stack[++stack_pointer] = d;
		return 1;
	}
	else
		return 0;

}

