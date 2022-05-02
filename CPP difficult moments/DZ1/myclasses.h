#ifndef MYCLASSES_H
#define MYCLASSES_H
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <optional>
#include <fstream>
#include <sstream>
#include <algorithm>

class Person
{
		std::string surname_;
		std::string name_;
		std::optional<std::string> patronymic_;
		friend class PhoneBook;
	public:
		Person() {}
		Person(std::string surname, std::string name, std::optional<std::string> patronymic = std::nullopt) : surname_(surname), name_(name), patronymic_(patronymic) { }
		bool operator< (const Person& p);
		bool operator== (const Person& p);
		friend std::ostream& operator<<(std::ostream& os, const Person& p);
};


class PhoneNumber
{
		int country_code_;
		int city_code_;
		std::optional<int> extension_number_;
		std::string number_;
		friend class PhoneBook;
	public:
		PhoneNumber(int country_code, int city_code, std::string number, std::optional<int> extension_number = std::nullopt) :
			country_code_(country_code), city_code_(city_code), number_(number), extension_number_(extension_number) { }
		friend std::ostream& operator<<(std::ostream& os, const PhoneNumber& p);
		bool operator< (const PhoneNumber& p);
		bool operator== (const PhoneNumber& p);
};

class PhoneBook
{
		std::vector<std::pair<Person, PhoneNumber>> data_;
	public:
		PhoneBook(std::ifstream& in_stream);
		void sortByName();
		void sortByPhone();
		friend std::ostream& operator<<(std::ostream& os, PhoneBook& other);
		std::pair<std::string, PhoneNumber> getPhoneNumber(std::string surname);
		bool changePhoneNumber(const Person& p, const PhoneNumber& n);
};

#endif
