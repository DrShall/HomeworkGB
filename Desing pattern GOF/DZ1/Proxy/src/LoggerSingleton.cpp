#include <fstream>
#include <iostream>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <chrono>
#include <iostream>

#include "LoggerSingleton.h"
#include "FileLoggerSingleton.h"

void LoggerSingleton::OpenLogFile(const std::string& FN)
{
	FileLoggerSingleton::getInstance().OpenLogFile(FN);
}

void LoggerSingleton::CloseLogFile()
{
	FileLoggerSingleton::getInstance().CloseLogFile();
}

void LoggerSingleton::WriteToLog(const std::string& str)
{
	if (logOut.is_open())
	{
		logOut << "№" << std::to_string(number++) << "  ";
	}
	FileLoggerSingleton::getInstance().WriteToLog(str);
}

void LoggerSingleton::WriteToLog(const std::string& str, int n)
{
	FileLoggerSingleton::getInstance().WriteToLog(str, n);
}

void LoggerSingleton::WriteToLog(const std::string& str, double d)
{
	FileLoggerSingleton::getInstance().WriteToLog(str, d);
}

