#include "MyTools.h"

#include <stdint.h>
#include <time.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>

std::ofstream logOut;

void FileLoggerSingleton::OpenLogFile(const std::string& FN)
{
	logOut.open(FN, std::ios_base::out);
}
void FileLoggerSingleton::CloseLogFile()
{
	if (logOut.is_open()) {
		logOut.close();
	  }
}
void FileLoggerSingleton::WriteToLog(const std::string& str)
{
	if (logOut.is_open()) {
		logOut << GetCurDateTime() << " - " << str << std::endl;
	  }
}
void FileLoggerSingleton::WriteToLog(const std::string& str, int n)
{
	if (logOut.is_open()) {
		logOut << GetCurDateTime() << " - " << str << n << std::endl;
	  }
}
void FileLoggerSingleton::WriteToLog(const std::string& str, double d)
{
	if (logOut.is_open()) {
		logOut << GetCurDateTime() << " - " << str << d << std::endl;
	  }
}
std::string FileLoggerSingleton::GetCurDateTime() {
  auto cur = std::chrono::system_clock::now();
  time_t time = std::chrono::system_clock::to_time_t(cur);
  char* buf = ctime(&time);
  return std::string(buf);
}

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
	if (logOut.is_open())
	{
		logOut << "№" << std::to_string(number++) << "  ";
	}
	FileLoggerSingleton::getInstance().WriteToLog(str, n);
}

void LoggerSingleton::WriteToLog(const std::string& str, double d)
{
	if (logOut.is_open())
	{
		logOut << "№" << std::to_string(number++) << "  ";
	}
	FileLoggerSingleton::getInstance().WriteToLog(str, d);
}

//namespace MyTools {

//std::ofstream logOut;

//void OpenLogFile(const std::string &FN) { logOut.open(FN, std::ios_base::out); }

//void CloseLogFile() {
//  if (logOut.is_open()) {
//	logOut.close();
//  }
//}

//std::string GetCurDateTime() {
//  auto cur = std::chrono::system_clock::now();
//  time_t time = std::chrono::system_clock::to_time_t(cur);
//  char* buf = ctime(&time);
//  return std::string(buf);
//}

//void WriteToLog(const std::string &str) {
//  if (logOut.is_open()) {
//	logOut << GetCurDateTime() << " - " << str << std::endl;
//  }
//}

//void WriteToLog(const std::string &str, int n) {
//  if (logOut.is_open()) {
//	logOut << GetCurDateTime() << " - " << str << n << std::endl;
//  }
//}

//void WriteToLog(const std::string &str, double d) {
//  if (logOut.is_open()) {
//	logOut << GetCurDateTime() << " - " << str << d << std::endl;
//  }
//}

//} // namespace MyTools
