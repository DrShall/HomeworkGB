// 1. Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом
// 2. Реализовать шифрование и расшифровку перестановками с передаваемым в функцию
// сообщением и количеством столбцов
//
//Результатом работы должен стать один файл с кодом на языке С,
//содержащий функцию main и все необходимые функции.

#include <iostream>

using namespace std;

void cesarEncryption(char*,int,int);
void cesarDecryption(char*,int,int);

int main()
{
	// Task 1
	const int number = 256;   //длина строки
	char* str = new char[number]{' '};
	cout << "Enter string: ";
	cin.getline(str, number);
	cout << endl << "Enter Cesar encryption key: ";
	int key;
	cin >> key;

	cesarEncryption(str, number, key);
	cout << endl << "Encryption string: " << str << endl;
	cesarDecryption(str, number, key);
	cout << endl << "Decryption string: " << str << endl;

	// Task 2


	delete[] str;

	return 0;
}

void cesarEncryption(char* str, int num, int key)
{
	int t;
	for(int i = 0; i < num; ++i)
	{
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


