#include "myclasses.h"

bool Date::setDay(int day)
{
	if( day > 0 && day <= 31)
	{
		day_ = day;
		return true;
	}
	else
		return false;
}

bool Date::setMonth(int month)
{
	if( month > 0 && month < 13)
	{
		month_ = month;
		return true;
	}
	else
		return false;
}

bool Date::setYear(int year)
{
	if( year > 0 && year < 3000)
	{
		year_ = year;
		return true;
	}
	else
		return false;
}

int Date::getDay()
{
	return day_;
}

int Date::getMonth()
{
	return month_;
}

int Date::getYear()
{
	return year_;
}

std::ostream& operator<<(std::ostream& os, Date& date)
{
	os << date.day_ << "." << date.month_ << "." << date.year_;
	return os;
}
