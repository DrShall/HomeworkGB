// 1. Реализовать обход в глубину с использованием стека
// 2. Моделируем робот поисковой системы. Дан готовый простой граф с циклическими связями.
// Нужно обойти этот граф двумя способами и подсчитать количество ссылок на каждый
// из узлов графа (полустепень захода).
//   - обход графа рекурсивной функцией (с подсчётом только смежных со стартовой вершин)
//   - обход графа по матрице смежности (с подсчётом всех вершин графа)
//В конце обхода вывести два получившихся списка всех узлов в порядке уменьшения количества ссылок на них.
//
//Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.

#include <iostream>

using namespace std;

const int size = 6;
int graph[size][size] = {
	{ 0,1,1,0,0,0 },
	{ 1,0,0,1,0,0 },
	{ 1,0,0,1,0,1 },
	{ 0,1,1,0,1,0 },
	{ 0,0,0,1,0,1 },
	{ 0,0,1,0,1,0 },
};

int visited[size]{0};

int* Stack = new int[size];
int stack_pointer = -1;

int* queue = new int[size];
int top = 0, finish = 0, items = 0;

void resetVisits();
void depth(int);
int pop_Stack();
int push_Stack(int);
void pop_all();
void width(int);

bool push_Queue(int);
bool pop_Queue();

int main()
{
	// Task 1
	resetVisits();
	depth(0);
	pop_all();
	cout << endl;
	resetVisits();
	depth(2);
	pop_all();
	cout << endl;
	resetVisits();
	depth(4);
	pop_all();
	cout << endl;

	// Task 2
	resetVisits();

	return 0;
}

void resetVisits()
{
	for(int i = 0; i < size; ++i)
		visited[i] = 0;
}

void depth(int s)
{
	push_Stack(s);
	visited[s] = 1;
	for( int i = 0; i < size; ++i)
		if( graph[s][i] == 1 && !visited[i])
			depth(i);
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

void pop_all()
{
	while(stack_pointer != -1)
	{
		cout << pop_Stack() << "\t";
	}
	cout << endl;
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

void width(int start)
{
	push_Queue(start);
	while(items > 0)
	{
		int ind = pop_Queue();
	}
}

bool push_Queue(int d)
{
	if(items == size)   //если очередь заполнена возвращаем false
		return false;
	else   //иначе сдигаем индекс конца, увиличиваем кол-во и записываем элемент в очередь
	{
		queue[finish] = d;
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

