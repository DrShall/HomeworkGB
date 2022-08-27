#pragma once

#include <string>
#include <cstring>

class FileLoggerSingleton
{
private:

	FileLoggerSingleton() {}
	~FileLoggerSingleton() {}
	FileLoggerSingleton(const FileLoggerSingleton& root) = delete;
	FileLoggerSingleton& operator=(const FileLoggerSingleton&) = delete;
	std::string GetCurDateTime();

public:
	static FileLoggerSingleton& getInstance()
	{
		static FileLoggerSingleton instance;
		return instance;
	}

	void  OpenLogFile(const std::string& FN);
	void CloseLogFile();
	void  WriteToLog(const std::string& str);
	void  WriteToLog(const std::string& str, int n);
	void  WriteToLog(const std::string& str, double d);
};
