#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int);

int main()
{
	int num;
	bool flag;

	cout << "Enter number (more then 1): ";
	cin >> num;

	if(num < 2)   //если число меньше двух не можем говорить о простоте числа
	{
		cout << "Incorrect input" << endl;
		return 0;
	}

	flag = isPrime(num);

	if(flag)
		cout << num << " is prime number" << endl;
	else
		cout << num << " is NOT prime number" << endl;

	return 0;
}

bool isPrime(int n)
{
	if( n < 4)   //2 и 3 простые числа
		return true;

	if( n % 2 == 0)   //четные числа не являются простыми
	{
		return false;
	}

	double s = sqrt(n);
	for( int i = 3; i < s; i+=2)   //перебираем нечетные делители до корень из n
	{
		if( n % i == 0)
		{
			return false;
		}
	}

	return true;
}
