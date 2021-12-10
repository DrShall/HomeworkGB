 
#include <iostream>
#include <string>

using namespace std;

//==============================================================================
// Запрограммировать игру крестики нолики на поле 3х3. Прислать архив всего
//проекта или ссылку на гит репозиторий.
//Для джуниоров: не обязательно делать крутой искусственный интеллект в игре.
//Но у вас должны корректно работать все основные моменты в игре, как например
//и главный цикл игры в main.
//Челендж для опытных и продвинутых: сделать решение на поле 4х4 или 5х5 или
//на динамическом поле, размер которого ввел пользователь. Также можно запросить
//у пользователя количество фигур необходимое для выигрыша, 3-5.
//==============================================================================

enum Status
	{
	HUMAN_WON,
	COMPUTER_WON,
	DRAW,
	GAME_IS_ON
	};

enum Cell
	{
	CROSS = 'X',
	ZERO = '0',
	EMPTY = ' '
	};

void HumanMove(Cell *pG, Cell h);
void ComputerMove(Cell *pG, Cell hum, Cell comp);
void InitField(Cell* pG);
void DrawField(const Cell* pG, Cell h);
bool IsBusy(Cell *pG, int var);
Status StatusGame(Cell *pG, Cell hum, Cell comp);
void clearScr();
void GameOver(Status win);

//============================main=============================================
int main()
{
	srand(time(NULL));
	Cell human, comp;
	size_t step;
	if(rand()%2)
	{
		human = CROSS;
		comp = ZERO;
		step = 1;
	}
	else
	{
		human = ZERO;
		comp = CROSS;
		step = 0;
	}

	Cell *pGame = new (nothrow) Cell[9];

	InitField(pGame);
	DrawField(pGame, human);

	while(true)
	{
		if(step%2)
			HumanMove(pGame, human);
		else
			ComputerMove(pGame, human, comp);
		Status st = StatusGame(pGame, human, comp);
		if(st != GAME_IS_ON)
		{
			GameOver(st);
			return 0;
		}

		DrawField(pGame, human);
		step++;
	}
	delete[] pGame;
}
//=============================================================================

void clearScr()
{
	system("clear");
}

//=============================================================================
void HumanMove(Cell *pG, Cell h)
{
	while(true)
	{
		cout << "Ваш ход: ";
		int val;
		cin >> val;
		if (cin.fail() || val > 9) // если предыдущее извлечение оказалось неудачным,
		{
			cout << "Некорректный ход." << endl;
			cin.clear();
			// то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		}
		else if(!IsBusy(pG, val-1))
		{
			pG[val-1] = h;
			return;
		}
		else
			cout << "Поле уже занято, сделайте другой выбор." << endl;
	}
}
//=============================================================================
void InitField(Cell* pG)
{
	for(int i = 0; i < 9; i++)
		pG[i] = EMPTY;
}
//=============================================================================
void DrawField(const Cell* pG, Cell h)
{
	clearScr();
	cout << "-------------" << endl;
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			cout << "| " << (char)pG[j+i*3] << " ";
		}
		cout <<"|" << endl << "-------------" << endl;
	}
	cout << endl << "Выберите номер клетки для входа от 1 до 9, где:" << endl;
	cout << "-------------" << endl;
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			cout << "| " << j+i*3+1 << " ";
		}
		cout <<"|" << endl << "-------------" << endl;
	}
	cout << "Вы играете \"" << (char)h <<"\"" << endl;
}
//=============================================================================
bool IsBusy(Cell *pG, int var)
{
	if(pG[var] == EMPTY)
		return false;
	else
		return true;
}
//=============================================================================
void GameOver(Status win)
{
	clearScr();
	switch (win)
	{
	case HUMAN_WON:
		cout << "Поздравляем, вы выиграли!!!" << endl;
		break;
	case COMPUTER_WON:
		cout << "Вы проиграли, компьютер вас обыграл." << endl;
		break;
	case DRAW:
		cout << "Ходов больше нет, игра завершилась ничьей." << endl;
		break;
	}
}
//=============================================================================
Status StatusGame(Cell *pG, Cell hum, Cell comp)
{
	if(pG[0] == hum && pG[1] == hum && pG[2] == hum ||
	   pG[3] == hum && pG[4] == hum && pG[5] == hum ||
	   pG[6] == hum && pG[7] == hum && pG[8] == hum ||
	   pG[0] == hum && pG[3] == hum && pG[6] == hum ||
	   pG[1] == hum && pG[4] == hum && pG[7] == hum ||
	   pG[2] == hum && pG[5] == hum && pG[8] == hum ||
	   pG[0] == hum && pG[4] == hum && pG[8] == hum ||
	   pG[2] == hum && pG[4] == hum && pG[6] == hum)
	{
		return HUMAN_WON;
	}
	else if (pG[0] == comp && pG[1] == comp && pG[2] == comp ||
			 pG[3] == comp && pG[4] == comp && pG[5] == comp ||
			 pG[6] == comp && pG[7] == comp && pG[8] == comp ||
			 pG[0] == comp && pG[3] == comp && pG[6] == comp ||
			 pG[1] == comp && pG[4] == comp && pG[7] == comp ||
			 pG[2] == comp && pG[5] == comp && pG[8] == comp ||
			 pG[0] == comp && pG[4] == comp && pG[8] == comp ||
			 pG[2] == comp && pG[4] == comp && pG[6] == comp)
	{
		return COMPUTER_WON;
	}
	else
	{
		for(int i =0; i < 9; ++i)
		{
			if(pG[i] == EMPTY)
				return GAME_IS_ON;
		}
		return DRAW;
	}
}

void ComputerMove(Cell *pG, Cell hum, Cell comp)
{
	for(int i =0; i < 9; ++i) //перебираем пустые поля
	{
		if(pG[i] == EMPTY)
		{
			pG[i] = comp;
			if(StatusGame(pG, hum, comp) == COMPUTER_WON) //если след ход выигрыш - делаем его
				return;
			else
			{
				pG[i] = hum;
			if(StatusGame(pG, hum, comp) == HUMAN_WON) //если след ход проигрыш - мешаем
			{
				pG[i] = comp;
				return;
			}
			else
				pG[i] = EMPTY;
			}
		}
	}
	//перебираем приоритетные ходы, если свободно - ходим
	if(pG[4] == EMPTY)
		pG[4] = comp;
	else if(pG[0] == EMPTY)
		pG[0] = comp;
	else if(pG[2] == EMPTY)
		pG[2] = comp;
	else if(pG[6] == EMPTY)
		pG[6] = comp;
	else if(pG[8] == EMPTY)
		pG[8] = comp;
	else if(pG[1] == EMPTY)
		pG[1] = comp;
	else if(pG[3] == EMPTY)
		pG[3] = comp;
	else if(pG[5] == EMPTY)
		pG[5] = comp;
	else if(pG[7] == EMPTY)
		pG[7] = comp;
	return;
}
