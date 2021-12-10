 
#include <iostream>

namespace MySpace
{
	void InitArray(double *pArray, size_t size)
	{
		double x = 1000.0;
		for(size_t i = 0; i < size; ++i)
		{
			pArray[i] = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(2*x))) - x;   //генерируем от -1000 до 1000
		}
	}

	void PrintArray(double *pArray, size_t size)
	{
		for(size_t i = 0; i < size; ++i)
		{
			std::cout << pArray[i] << ' ';
		}
		std::cout << std::endl;
	}

	void AnalysisArray(double *pArray, size_t size)
	{
		int nCountPositive = 0, nCountNegative = 0;
		for(size_t i = 0; i < size; ++i)
		{
			if(pArray[i] < 0)
				nCountNegative++;
			else if( pArray[i] > 0)
				nCountPositive++;
		}
		std::cout << "Количество отрицательных элементов в массиве - " << nCountNegative << std::endl
					<< "Количество положительных элементов в массиве - " << nCountPositive << std::endl;
	}

	void PrintArray(int *pArray, int size)
	{
		for(size_t i = 0; i < size; ++i)
		{
			std::cout << pArray[i] << ' ';
		}
		std::cout << std::endl;
	}
}
