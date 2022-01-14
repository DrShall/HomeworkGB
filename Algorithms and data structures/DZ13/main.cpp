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

const int sizeGraph = 6;
int graph[sizeGraph][sizeGraph] = {
	{ 0,1,1,0,0,0 },
	{ 1,0,0,1,0,0 },
	{ 1,0,0,1,0,1 },
	{ 0,1,1,0,1,0 },
	{ 0,0,0,1,0,1 },
	{ 0,0,1,0,1,0 },
};

int visited[sizeGraph]{0};

int* Stack = new int[sizeGraph];
int stack_pointer = -1;

int* queue = new int[sizeGraph];
int top = 0, finish = 0, items = 0;

void resetVisits();
void depth(int);
int pop_Stack();
int push_Stack(int);
void pop_all();

void apexCount(int*);
void adjacentCount(int, int*);

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
	int* nodes = new int[sizeGraph];
	for(int i = 0; i < sizeGraph; ++i)
		nodes[i] = 0;

	apexCount(nodes);   // количество по
	cout << endl;
	for(int i = 0; i < sizeGraph; ++i)
	{
		cout.width(3);
		cout << nodes[i];
	}
	cout << endl;

	resetVisits();
	for(int i = 0; i < sizeGraph; ++i)
		nodes[i] = 0;
	adjacentCount(0, nodes);
	cout << endl;
	for(int i = 0; i < sizeGraph; ++i)
	{
		cout.width(3);
		cout << nodes[i];
	}
	cout << endl;

	return 0;
}

void resetVisits()
{
	for(int i = 0; i < sizeGraph; ++i)
		visited[i] = 0;
}

void depth(int s)
{
	push_Stack(s);
	visited[s] = 1;
	for( int i = 0; i < sizeGraph; ++i)
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
	if(stack_pointer < sizeGraph)
	{
		Stack[++stack_pointer] = d;
		return 1;
	}
	else
		return 0;

}

void apexCount(int* n)
{
	for(int i = 0; i < sizeGraph; ++i)
	{
		for(int j = 0; j < sizeGraph; ++j)
		{
			if(graph[j][i] == 1 && i != j)
				n[i]++;
		}
	}
}

void adjacentCount(int start, int* n)
{
	visited[start] = 1;
	for(int i = 0; i < sizeGraph; ++i)
	{
		if( graph[start][i] && start != i)
			{
				n[start]++;
				if( !visited[i])
					adjacentCount(i, n);
			}
	}
}
