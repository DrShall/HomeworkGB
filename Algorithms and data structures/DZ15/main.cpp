// 1. Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
// 2. Имеются монеты номиналом 50, 10, 5, 2, 1 коп. Напишите функцию которая минимальным
// количеством монет наберет сумму 98 коп. Для решения задачи используйте “жадный” алгоритм.
//
//Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.

#include <iostream>

using namespace std;

int hashOfString(char*, int);
void countCoins(int*, int*, int, int);

int main()
{
	// Task 1
	const int length = 256;
	char str[length]{'0'};
	cout << "Enter string: ";
	cin.getline(str, length);

	cout <<endl << hashOfString(str, length) << endl;

	// Task 2
	int denominations[]{50, 10, 5, 2, 1};   // номиналы монет
	int number = sizeof (denominations)/sizeof(denominations[0]);
	int* countOfCoins = new int[number];

	cout << endl<< "Enter amount of money: ";
	int sum;
	cin >> sum;

	countCoins(denominations, countOfCoins, number, sum);

	cout << endl << "For the sum " << sum << " it is necessary:" << endl;
	for(int i = 0; i < number; ++i)
	{
		cout << denominations[i] << " - " << countOfCoins[i] << endl;
	}

	delete[] countOfCoins;

	return 0;
}

int hashOfString(char* str, int len)
{
	int hashSum = 0;
	for(int i = 0; i < len; ++i)
	{
		if(str[i] == '\0')
			break;
		hashSum += str[i];
	}
	return hashSum;
}

void countCoins(int* den, int* count, int num, int sum)
{
	for(int i = 0; i < num; ++i)
	{
		count[i] = sum/den[i];
		sum -= den[i] * count[i];
	}
}

