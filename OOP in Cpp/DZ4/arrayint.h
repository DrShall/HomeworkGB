#ifndef FRACTION_H
#define FRACTION_H

class ArrayInt
{
		int length_;
		int* data_;
		void quickSort(int* arr, int first, int last);
		void sortInsert(int* arr, int size);
	public:
		ArrayInt();
		ArrayInt(int length);
		~ArrayInt();
		void erase();
		int& operator[](int index);
		void resize(int newSize);
		void print();
		void at(int index, int data);
		void push_back(int data);
		int pop_back();
		int pop_front();
		void sort();
};

#endif
