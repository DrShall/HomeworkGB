/* ======================================================================
1. Установить фреймворк Google Test.
2. Добавить unit-тесты в проект домашнего задания из седьмого или первого урока.
======================================================================*/

#include <iostream>
#include "myclasses.h"

using namespace std;

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
