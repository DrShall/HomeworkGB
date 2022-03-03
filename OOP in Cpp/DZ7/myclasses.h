#ifndef MYCLASSES_H
#define MYCLASSES_H
#include <ostream>

class Date
{
		int day_;
		int month_;
		int year_;
		friend std::ostream& operator<<(std::ostream& os, Date& date);
	public:
		Date(int day = 1, int month = 1, int year = 2001) : day_(day), month_(month), year_(year) { }
		bool setDay(int day);
		bool setMonth(int month);
		bool setYear(int year);
		int getDay();
		int getMonth();
		int getYear();
};

#endif
