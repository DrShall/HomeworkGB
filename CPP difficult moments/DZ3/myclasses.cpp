#include "myclasses.h"

Matrix::Matrix(int size)
{
	srand(time(NULL));
	size_ = size;
	std::vector<int> tmp;
	for(int i = 0; i < size_; ++i)
	{
		tmp.reserve(size);
		for(int j = 0; j < size_; ++j)
			tmp.push_back( rand() % 50 - 25 );
		M.push_back(tmp);
		tmp.erase(tmp.begin(), tmp.end());
	}
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
	if(size_ == 1)
		return M[0][0];

	if(size_ == 2)
	{
		return M[0][0]*M[1][1] - M[0][1]*M[1][0];
	}

	int deter = 0;
	int sig = 1;

	for(int i = 0; i < size_; ++i)
	{
		Matrix modM(size_ -1);
		modMatrix(modM, i);
		deter += sig * M[0][i] * modM.det();
		sig *= (- 1);
	}
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
