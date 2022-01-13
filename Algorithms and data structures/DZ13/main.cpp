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

void nodeCount(int*);

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

	int* nodes = new int[size];
	for(int i = 0; i < size; ++i)
		nodes[i] = 0;

	nodeCount(nodes);
	cout << endl;
	for(int i = 0; i < size; ++i)
	{
		cout.width(3);
		cout << nodes[i];
	}
	cout << endl;

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

void nodeCount(int* n)
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			if(graph[j][i] == 1 && i != j)
				n[i]++;
		}
	}
}
