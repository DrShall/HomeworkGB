// 1. Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом
// 2. Реализовать шифрование и расшифровку перестановками с передаваемым в функцию
// сообщением и количеством столбцов
//
//Результатом работы должен стать один файл с кодом на языке С,
//содержащий функцию main и все необходимые функции.

#include <iostream>
#include <time.h>

using namespace std;

void cesarEncryption(char*,int,int);
void cesarDecryption(char*,int,int);
void reshuffleEncryption(char*,int,int);
void reshuffleDecryption(char*,int,int);

int main()
{
	srand(time(NULL));
	// Task 1
	const int number = 256;   //длина строки
	char* str = new char[number]{' '};
	cout << "Enter string: ";
	cin.getline(str, number);
	cout << endl << "Enter Cesar encryption key: ";
	int key;
	cin >> key;
	int len = 0;
	for(int i = 0; i < number; ++i)
	{
		if(str[i] != '\0')
			len++;
		else
			break;
	}

	cesarEncryption(str, len, key);
	cout << endl << "Encryption string: " << str << endl;
	cesarDecryption(str, len, key);
	cout << endl << "Decryption string: " << str << endl;

	// Task 2
	reshuffleEncryption(str, len, key);
	cout << endl << "Encryption string: " << str << endl;
	reshuffleDecryption(str, len, key);
	cout << endl << "Decryption string: " << str << endl;

	delete[] str;

	return 0;
}

void cesarEncryption(char* str, int num, int key)
{
	int t;
	for(int i = 0; i < num; ++i)
	{
		if(str[i] == '\0')
			return;
		t = str[i];
		if(t > 64 && t < 91)   //если большие латинские буквы
		{
			t = 65 + ( t + key - 65 ) % 26;
		}
		if(t > 96 && t < 123)   //если маленькие латинские буквы
		{
			t = 97 + ( t + key - 97 ) % 26;
		}
		str[i] = t;
	}
}

void cesarDecryption(char* str, int num, int key)
{
	int t;
	for(int i = 0; i < num; ++i)
	{
		if(str[i] == '\0')
			return;
		t = str[i];
		if(t > 64 && t < 91)   //если большие латинские буквы
		{
			t = 90 - ( 90 + key - t ) % 26;
		}
		if(t > 96 && t < 123)   //если маленькие латинские буквы
		{
			t = 122 - ( 122 + key - t ) % 26;
		}
		str[i] = t;
	}
}

void reshuffleEncryption(char* str, int num, int col)
{
	int row = num / col;
	if(num % col != 0)
		row++;
	char* tmp = new char[row*col];

	int t = 0;
	for(int i = 0; i < col; ++i)
	{
		for(int j = i; j < row*col; j += col)
		{
			if(j < num)
				tmp[t++] = str[j];
			else
				tmp[t++] = 97 + rand()%26;
		}
	}
	t=0;
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
		{
			str[t++] = tmp[i*col+j];
		}

	delete[] tmp;
}

void reshuffleDecryption(char* str, int num, int col)
{
	int row = num / col;
	if(num % col != 0)
		row++;
	char* tmp = new char[row*col];

	int t = 0;
	for(int i = 0; i < col; ++i)
	{
		for(int j = i; j < row*col; j += col)
		{
				tmp[j] = str[t++];
		}
	}
	t=0;
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
		{
			if(i*col+j < num)
				str[t++] = tmp[i*col+j];
			else
				str[t++] = '\0';
		}
}
