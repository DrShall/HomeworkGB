 
#include <iostream>
using namespace std;
int main()
{
	// 1. Создать и инициализировать переменные пройденных типов данных
	//  (short int, int, long long, char, bool, float, double).
	//
	short int nA = 50;
	int nB = 13;
	long long C = 1234567890;
	char D = 'f';
	bool flag = true;
	float fE = 5.6f;
	double dD = 2.17;

	// 2. Создать перечисление (enum) с возможными вариантами символов для игры в крестики-нолики.

	enum TTT{ X, O, _ };

	// 3. Создать массив, способный содержать значения такого перечисления и инициализировать его.

	TTT field[3][3]{{X,O,X},{O, X, _ },{ _, X, O}};

	// 4. * Создать структуру (struct) данных «Поле для игры в крестики-нолики» и снабдить его всеми
	// необходимыми свойствами (подумайте что может понадобиться).

	struct FieldTTT
	{
			char gameField[3][3]{' '};
			bool gameOver : 1;
			bool winX : 1;
			bool winO : 1;
			bool draw : 1;
			bool whoseMove : 1; //0 - нолики, 1 - крестики
			char Player1[25];
			char Player2[25];
	};

	// 5. ** Создать структуру (struct MyVariant) объединяющую: union MyData (int, float, char)
	// и 3-и битовых поля (флага) указывающими какого типа значение в данный момент содержится
	// в объединении (isInt, isFloat, isChar).
	// Продемонстрировать пример использования в коде этой структуры.

	struct MyVariant
	{
			union MyData
			{
					int nData;
					float fData;
					char cData;
			}MD;
			bool isInt;
			bool isFloat;
			bool isChar;
	};

	MyVariant MV{false, false, false};

	if(MV.isFloat||MV.isInt)
	{
		MV.isFloat = false;
		MV.isInt = false;
	}
	MV.MD.cData = 'y';
	MV.isChar = true;

	if(MV.isChar || MV.isInt)
	{
		MV.isChar = false;
		MV.isInt = false;
	}
	MV.MD.fData = 5.6f;
	MV.isFloat = true;

	if(MV.isChar || MV.isFloat)
	{
		MV.isChar = false;
		MV.isFloat = false;
	}
	MV.MD.nData = 60;
	MV.isInt = true;


	return 0;
}
