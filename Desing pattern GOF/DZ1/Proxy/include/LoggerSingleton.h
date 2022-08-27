#pragma once

#include <string>
#include <cstring>

class LoggerSingleton
{
private:
	int number;
	LoggerSingleton() { number = 1; }
	~LoggerSingleton() {}
	LoggerSingleton(const LoggerSingleton& root) = delete;
	LoggerSingleton& operator=(const LoggerSingleton&) = delete;
	std::string GetCurDateTime();

public:
	static LoggerSingleton& getInstance()
	{
		static LoggerSingleton instance;
		return instance;
	}

	void  OpenLogFile(const std::string& FN);
	void CloseLogFile();
	void  WriteToLog(const std::string& str);
	void  WriteToLog(const std::string& str, int n);
	void  WriteToLog(const std::string& str, double d);
};

