 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//==============================================================================
//    Задание 1
// Выделить в памяти динамический одномерный массив типа int. Размер массива
//запросить у пользователя. Инициализировать его числами степенями двойки:
//1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран. Не забыть освободить
//память. =) Разбить программу на функции.
//==============================================================================
void PrintArray(size_t *arr, int s)
{
	for(int i = 0; i < s; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void InitArray(size_t *arr, int s)
{
	size_t n = 1;
	for(int i = 0; i < s; ++i)
	{
		arr[i] = n;
		n*=2;
	}
}

void Task1()
{
	int size;
	cout << " Введите размер одномерного массива: ";
	cin >> size;

	size_t *pArr = new size_t[size];

	InitArray(pArr, size);
	PrintArray(pArr, size);

	delete [] pArr;
	pArr = nullptr;
}

//==============================================================================
//    Задание 2
// Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными
//числами через функцию rand. Вывести на экран. Разбейте вашу программу на функции
//которые вызываются из main.
//==============================================================================
void InitArray2(int **ppArr, int s)
{
	for(int row = 0; row < s; ++row)
		for(int col = 0; col < s; ++col)
			ppArr[row][col] = rand()%20;
}

void PrintArray2(int **ppArr, int s)
{
	for(int row = 0; row < s; ++row)
	{
		for(int col = 0; col < s; ++col)
			cout << ppArr[row][col] << "\t";
		cout << endl;
	}
}

void Task2()
{
	int size = 4;

	int **ppArr = new int* [size];
	for(int i = 0; i < size; ++i)
		ppArr[i] = new int [size];

	InitArray2(ppArr, size);
	PrintArray2(ppArr, size);

	for(int i = 0; i < size; ++i)
		delete [] ppArr[i];
	delete [] ppArr;
	ppArr = nullptr;
}

//==============================================================================
//    Задание 3
// Написать программу, которая создаст два текстовых файла (*.txt), примерно
//по 50-100 символов в каждом (особого значения не имеет с каким именно содержимым).
//Имена файлов запросить у пользователя.
//==============================================================================
void PrintToFile(string str)
{
	ofstream fout(str);
	fout << "Сюда записана информация для файла " << str << " для домашнего задания №3" <<
			endl << "Здесь написан тестовый текст";
	fout.close();
}

void SumFiles(string file1, string file2, string result)
{
	string buffer;
//	bool exit = false;
	ifstream fin1, fin2;
	ofstream fout;
	fin1.open(file1);
	fin2.open(file2);
	fout.open(result);
	if(fin1.is_open())
	{
		while(!fin1.eof())
		{
			getline(fin1, buffer);
			fout << buffer << "\n";
		}
		fin1.close();
	}
	if(fin2.is_open())
	{
		while(!fin2.eof())
		{
			getline(fin2, buffer);
			fout << buffer << "\n";
		}
		fin2.close();
	}
	fout.close();
}

void Task3()
{
	string nameOfFile1, nameOfFile2, nameOfResult;
	cout << "Введите имя для первого файла: ";
	cin >> nameOfFile1;
	nameOfFile1 += ".txt";
	cout << "Введите имя для второго файла: ";
	cin >> nameOfFile2;
	nameOfFile2 += ".txt";
	cout << "Введите имя для объединяющего файла: ";
	cin >> nameOfResult;
	nameOfResult += ".txt";

	PrintToFile(nameOfFile1);
	PrintToFile(nameOfFile2);
	SumFiles(nameOfFile1, nameOfFile2, nameOfResult);

}

//==============================================================================
//    Задание 4
// Написать функцию, «склеивающую» эти файлы в третий текстовый файл
//(имя файлов спросить у пользователя).
//==============================================================================


void Task4()
{
	cout << "Выполнено в рамках задания №3" << endl;
}

//==============================================================================
//    Задание 5
// Написать программу, которая проверяет присутствует ли указанное пользователем
//при запуске программы слово в указанном пользователем файле (для простоты работаем
//только с латиницей). Используем функцию find которая есть в строках std::string.
//==============================================================================

void Task5()
{
	bool notFind = true;
	string str, fileName, buffer;
	cout << "Какое вхождение будет искать?" << endl;
	cin >> str;
	cout << endl << "В каком файле будем искать вхождение?" << endl;
	cin >> fileName;
	fileName += ".txt";

	ifstream fin(fileName);
	if(fin.is_open())
	{
		int line = 1;
		while(!fin.eof())
		{
			getline(fin, buffer);
			if(buffer.find(str) != string::npos)
			{
				cout << "Вхождение \"" << str << "\" найдено в файле \"" << fileName << "\" в " << line << " строке" << endl;
				notFind = false;
				break;
			}
			++line;
		}
		fin.close();
	}

	if(notFind)
		cout << "Вхождение \"" << str << "\" не найдено в файле \"" << fileName << "\"" <<endl;
}

int main()
{
	srand(time(NULL));

	cout << endl << "Task1" << endl;
	Task1();
	cout << endl << "Task2" << endl;
	Task2();
	cout << endl << "Task3" << endl;
	Task3();
	cout << endl << "Task4" << endl;
	Task4();
	cout << endl << "Task5" << endl;
	Task5();
	return 0;
}
