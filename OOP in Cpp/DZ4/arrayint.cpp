#include "arrayint.h"
#include <iostream>

ArrayInt::ArrayInt(): length_(0), data_(nullptr) { }

ArrayInt::ArrayInt(int length): length_(length)
{
	if(length > 0)
		data_ = new int[length_]{0};
	else
		data_ = nullptr;
}

ArrayInt::~ArrayInt()
{
	delete [] data_;
}

void ArrayInt::erase()
{
	delete [] data_;
	length_ = 0;
	data_ = nullptr;
}

int& ArrayInt::operator[](int index)
{
	if(index < 0 || index >= length_)
		return data_[0];
	else
		return data_[index];
}

void ArrayInt::resize(int newSize)
{
	if(newSize == length_)
		return;
	if(newSize <= 0)
	{
		erase();
		return;
	}
	int* newData = new int[newSize]{0};
	int elem = ( (newSize < length_) ? newSize : length_ );
	for(int i = 0; i < elem; ++i)
		newData[i] = data_[i];
	delete [] data_;
	data_ = newData;
	length_ = newSize;
}

void ArrayInt::print()
{
	for(int i = 0; i < length_; ++i)
		std::cout << data_[i] << " ";
	std::cout << std::endl;
}

void ArrayInt::at(int index, int data)
{
	if(index < 0 || index >= length_)
		return;
	data_[index] = data;
}

void ArrayInt::push_back(int data)
{
	resize(length_ + 1);
	data_[length_ - 1] = data;
}

int ArrayInt::pop_back()
{
	int rez = data_[length_-1];
	resize(length_ - 1);
	return rez;
}

int ArrayInt::pop_front()
{
	int rez = data_[0];
	for(int i = 0; i < length_ - 1; ++i)
	{
		data_[i] = data_[i+1];
	}
	resize(length_ - 1);
	return rez;
}

void ArrayInt::sort()
{
	quickSort(data_, 0, length_ - 1);
}

void ArrayInt::sortInsert(int* arr, int size)
{
	int temp, pos;
	for(int i = 1; i < size; ++i)
	{
		temp = arr[i];
		pos = i -1;
		while(pos >= 0 && arr[pos] > temp)
		{
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos+1] = temp;
	}
}

void ArrayInt::quickSort(int* arr, int first, int last)
{
	if(last>10)
		{
			if(arr[first]>arr[(first+last)/2])
				std::swap(arr[first], arr[(first+last)/2]);
			if(arr[(first+last)/2]>arr[last])
				std::swap(arr[(first+last)/2], arr[last]);
			if(arr[first]>arr[(first+last)/2])
				std::swap(arr[first], arr[(first+last)/2]);

			int i = first, j = last;
			int x = arr[(first+last)/2];
			do
			{
				while(arr[i] < x) i++;
				while(arr[j] > x) j--;

				if(i<=j)
				{
					std::swap(arr[i], arr[j]);
					i++;
					j--;
				}
			}
			while(i<=j);

			if(i<last) quickSort(arr, i, last);
			if(first<j) quickSort(arr, first, j);
		}
	else
		sortInsert(arr, last);
}
