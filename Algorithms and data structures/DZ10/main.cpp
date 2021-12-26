// 1. Написать программу, которая определяет, является ли введенная скобочная
// последовательность правильной. Примеры правильных скобочных выражений:
// (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(])
// для скобок [,(,{. Например: (2+(2*2)) или [2/{5*(4+7)}]
//
// 2. Создать функцию, копирующую односвязный список (без удаления первого списка).
//
// 3. Реализуйте алгоритм, который определяет, отсортирован ли связный список.
//
// Результатом работы должен стать один файл с кодом на языке С,
// содержащий функцию main и функции, соответствующие заданиям.

#include <iostream>
#include <time.h>

using namespace std;

// for Task 1
const int size = 20;
char Stack[size] = {0};
int stack_pointer = -1;

char pop_Stack();
bool push_Stack(char);
bool check_string(char val[], int size);

//for Task 2
struct Node {
		int data;
		Node* next;
};
struct List {
		Node* head;
		int size;
};

void add_node(List*, int);
void copy_list(List*, List*);
void print_list(List*);

// for Task 3
bool itSorted(List*);   // возвращаем истину, если отсортирован или пуст

int main()
{

	srand(time(NULL));

	// Task 1 ===============================
	char val[250] = "";
	cout << endl << "Input string: ";
	cin.getline(val,250);

	if(check_string(val,250))
		cout << "Allright." << endl;
	else
		cout << "It's wrong" << endl;

	// Task 2 ================================
	List* first_list = new List;
	first_list->head = nullptr;
	first_list->size = 0;

	for(int i = 0; i < 10; ++i)
	{
		add_node(first_list, rand()%100);
	}
	cout << endl;
	print_list(first_list);

	List* second_list = new List;
	second_list->head = nullptr;
	second_list->size = 0;

	copy_list(first_list, second_list);
	cout << endl;
	print_list(second_list);

	// Task 3 ===============================
	cout << endl;
	if(itSorted(first_list))
		cout << "First list sorted." << endl;
	else
		cout << "First list unsortes." << endl;

	List* third_list = new List;
	third_list->head = nullptr;
	third_list->size = 0;

	List* fourth_list = new List;
	fourth_list->head = nullptr;
	fourth_list->size = 0;

	for(int i = 0; i < 5; ++i)   //делаем третий и четвертый список сортированными
	{
		add_node(third_list, (i+1)*2);
		add_node(fourth_list, 10-2*(i+1));
	}

	cout << endl << " Third list." << endl;
	print_list(third_list);
	if(itSorted(third_list))
		cout << endl << "Third list sorted." << endl;
	else
		cout << "Third list unsortes." << endl;

	cout << endl << " Fourth list." << endl;
	print_list(fourth_list);
	if(itSorted(fourth_list))
		cout << endl << "Fourth list sorted." << endl;
	else
		cout << "Fourth list unsortes." << endl;

	return 0;
}

char pop_Stack()
{
	if( stack_pointer != -1)
	{
		return Stack[stack_pointer--];
	}
	else
		return 0;
}

bool push_Stack(char d)
{
	if(stack_pointer < size)
	{
		Stack[++stack_pointer] = d;
		return 1;
	}
	else
		return 0;

}

bool check_string(char val[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		switch (val[i]) {
		case '{':
			push_Stack(val[i]);
			break;
		case '[':
			push_Stack(val[i]);
			break;
		case '(':
			push_Stack(val[i]);
			break;
		case ']':
			if(pop_Stack() != '[')
				return false;
			break;
		case '}':
			if(pop_Stack() != '{')
				return false;
			break;
		case ')':
			if(pop_Stack() != '(')
				return false;
			break;
		default:
			break;
		}
	}
	if( pop_Stack())
		return false;
	return true;
}

void add_node(List* lst, int val)
{
	Node* new_node = new Node;
	new_node->data = val;
	new_node->next = nullptr;

	if(lst->head == nullptr)
	{
		lst->head = new_node;
	}
	else
	{
		Node* tmp = lst->head;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	lst->size++;
}

void copy_list(List* first, List* second)
{
	if(first->head == nullptr)
	{
		second->head = nullptr;
		second->size = 0;
		return;
	}
	Node* tmp = new Node;
	second->head = tmp;
	Node* cur = first->head;
	while(cur->next != nullptr)
	{
		tmp->data = cur->data;
		cur = cur->next;
		tmp->next = new Node;
		tmp = tmp->next;
		second->size++;
	}
	tmp->data = cur->data;
	tmp->next = nullptr;
	second->size++;
}

void print_list(List* lst)
{
	cout << "In list " << lst->size << " elements." << endl;
	Node* tmp = lst->head;
	do
	{
		cout.width(10);
		cout << "Address node: " << tmp << "\tData: " << tmp->data << "\tNext: " << tmp->next << endl;
		tmp = tmp->next;
	}
	while(tmp != nullptr);
}

bool itSorted(List* lst)
{
	bool more;

	if(lst->head == nullptr)
		return true;

	int tmp = lst->head->data;
	Node* cur = lst->head->next;

	if(tmp <= cur->data)
		more = true;   //если второе значение больше, проверяем на увеличение
	else
		more = false;   // в противном случае проверяем уменьшение последовательности

	tmp = cur->data;
	cur = cur->next;

	while(cur != nullptr)
	{
		if(more && cur->data >= tmp)
		{
			tmp = cur->data;
			cur = cur->next;
			continue;
		}
		else if( more)
			return false;
		else if ( !more && cur->data < tmp)
		{
			tmp = cur->data;
			cur = cur->next;
			continue;
		}
		else
			return false;

	}
	return true;
}
