﻿#include "SBomber.h"
#include "MyTools.h"
#include "ScreenSingleton.h"
//#include "LoggerSingleton.h"

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>

int _kbhit() {
	static const int STDIN = 0;
	static bool initialized = false;

	if (!initialized) {
		// Use termios to turn off line buffering
		termios term;
		tcgetattr(STDIN, &term);
		term.c_lflag &= ~ICANON;
		tcsetattr(STDIN, TCSANOW, &term);
		setbuf(stdin, NULL);
		initialized = true;
	}

	int bytesWaiting;
	ioctl(STDIN, FIONREAD, &bytesWaiting);
	return bytesWaiting;
}

int main(void) {
  LoggerSingleton::getInstance().OpenLogFile("log.txt");

  SBomber game;

  do {
	game.TimeStart();

	if (_kbhit()) {
	  game.ProcessKBHit();
	}

	ScreenSingleton::getInstance().ClrScr();

	game.DrawFrame();
	game.MoveObjects();
	game.CheckObjects();

	game.TimeFinish();

  } while (!game.GetExitFlag());

  LoggerSingleton::getInstance().CloseLogFile();

  return 0;
}
