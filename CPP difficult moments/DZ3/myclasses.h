#ifndef MYCLASSES_H
#define MYCLASSES_H
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <iomanip>

template<typename T> void pushBackAverage(std::list<T> &l)
{
	T sum = 0;
	for(auto it: l)
		sum+=it;
	T tmp = sum/l.size();
	l.push_back(tmp);
	std::cout << std::endl << "Average = " << tmp << std::endl;
}

class Matrix
{
		std::vector<std::vector<int>> M;
		int size_;
	public:
		Matrix(int size);
		void print();
		int det();   // определитель матрицы
		void modMatrix( Matrix& modM, int C );   // заполнение дополнительной матрицы
};

template<typename T>
class MyIter
{
		T* ptr;
	public:
		MyIter() {};
		MyIter(T& val) { ptr = &val; }
		void operator=(T val) { *ptr = val; }
		T operator* () { return *ptr;}
		void operator++() { ptr++; }
};

#endif
