// 1. Написать функцию проверяющую является ли переданное в неё бинарное дерево
// сбалансированным и написать программу, которая:
//   - создаст [50] деревьев по [10000] узлов и заполнит узлы случайными целочисленными значениями;
//   - рассчитает, какой процент из созданных деревьев является сбалансированными.
// 2. Написать рекурсивную функцию бинарного поиска в дереве хранящемся в узлах,
//а не в массиве.
//
//Результатом работы должен стать один файл с кодом на языке С,
//содержащий функцию main и все необходимые функции.

#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

class Node {
	public:
		int key;
		Node* left;
		Node* right;
};

Node* treeInsert(Node*, int);
void printTree(Node*);
bool deleteNode(Node*, int);
Node* getSuccessor(Node*);
void deleteTree(Node*);
int countNode(Node*);
bool isBalance(Node*);
bool itFound(Node*, int);

int main()
{
	srand(time(NULL));

	Node* tree = nullptr;

	const int numberOfTree = 500;
	const int numberOfElements = 10000;
	int numberBalance = 0;

	// Task 1
	for(int i = 0; i < numberOfTree; ++i)
	{
		for(int j = 0; j < numberOfElements; ++j)
		{
			if(tree == nullptr)
			{
				tree = 	treeInsert(tree, rand()%(numberOfElements*10));
			}
			else
			{
				treeInsert(tree, rand()%(numberOfElements*10));
			}
		}

		if(isBalance(tree))
			numberBalance++;
		deleteTree(tree);
		tree = nullptr;
	}
	cout << "Percentage of balanced trees is " << 100*numberBalance/numberOfTree << endl;

	// Task 2
	for(int i = 0; i < numberOfElements; ++i)
	{
		if(tree == nullptr)
		{
			tree = 	treeInsert(tree, rand()%(numberOfElements*10));
		}
		else
		{
			treeInsert(tree, rand()%(numberOfElements*10));
		}
	}

	cout << "What are we looking for?\nval = ";
	int val;
	cin >> val;
	if(itFound(tree,val))
		cout << val << " in the tree." << endl;
	else
		cout << val << " not in the tree." << endl;

	return 0;
}

Node* treeInsert(Node* t,int d)
{
	Node* newNode = new Node;
	newNode->key= d;
	newNode->left = nullptr;
	newNode->right = nullptr;

	Node* current = t;
	Node* parent = t;
	if( t == nullptr)
	{
		t = newNode;
		return t;
	}
	else
	{
		while( true) //current->key != d)
		{
			parent = current;
			if(current->key > d)
			{
				current = current->left;
				if(current == nullptr)
				{
					parent->left = newNode;
					return newNode;
				}
			}
			else if(current->key <= d)
			{
				current = current->right;
				if( current == nullptr)
				{
					parent->right = newNode;
					return newNode;
				}
			}
		}
	}
}

void printTree(Node* t)
{
	if(t)
	{
		cout << t->key;
		if(t->left || t->right)
		{
			cout << "(";
			if(t->left)
				printTree(t->left);
			else
				cout << "NULL";
			cout << ",";
			if(t->right)
				printTree(t->right);
			else
				cout << "NULL";
			cout << ")";
		}
	}
}

void deleteTree(Node* t)
{
	if(t == nullptr)
		return;
	deleteTree(t->left);
	deleteTree(t->right);
	delete t;
}

int countNode(Node* t)
{
	if(t == nullptr)
		return 0;
	return countNode(t->left) + countNode(t->right) + 1;
}

bool isBalance(Node* t)
{
	if(abs(countNode( t->left ) - countNode( t->right )) <= 1)
		return true;
	else
		return false;
}

bool itFound(Node* t, int v)
{
	if(t == nullptr)
		return false;
	if(t->key == v)
		return true;
	else
		return (itFound(t->left, v) || itFound(t->right, v));
}

