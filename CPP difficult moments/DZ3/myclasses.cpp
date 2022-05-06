#include "myclasses.h"

Matrix::Matrix(int size)
{
	size_ = size;
	M.reserve(size_);
	for(int i = 0; i < size_; ++i)
		M[i].reserve(size_);
	for(int i = 0; i < size_; ++i)
		for(int j = 0; j < size_; ++j)
			M[i][j] = rand() % 10 - 5;
}
void Matrix::print()
{
	for(int i = 0; i < size_; ++i)
	{
		for(int j = 0; j < size_; ++j)
			std::cout << std::setw(4) << M[i][j] << " ";
		std::cout << std::endl;
	}
}

int Matrix::det()
{
	int deter = 0;

	if(size_ == 1)
		return M[0][0];

	if(size_ == 2)
	{
		deter = M[0][0]*M[1][1] - M[0][1]*M[1][0];   //
		std::cout << std::endl << deter << std::endl;   //
		return deter;
	}


	int sig = 1;
	Matrix modM(size_ -1);

	for(int i = 0; i < size_; ++i)
	{
		modMatrix(modM, i);
		std::cout << std::endl;   //
		modM.print();   //
		deter += sig * M[0][i] * modM.det();
		sig *= (- 1);
	}
	std::cout << std::endl << deter << std::endl;   //
	return deter;
}

void Matrix::modMatrix( Matrix& modM, int C )
{
	for(int row = 0; row < size_ - 1; ++row)
	{
		for(int oldCol = 0, col = 0; oldCol < size_; ++oldCol)
		{
			if(oldCol == C)
				continue;
			else
			{
				modM.M[row][col++] = M[row+1][oldCol];
			}
		}
	}
}
