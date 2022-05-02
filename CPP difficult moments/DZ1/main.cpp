/* ======================================================================
Имеется база сотрудников и номеров их телефонов. Требуется написать соответствующие
 структуры для хранения данных, и заполнить контейнер записями из базы. Затем необходимо
 реализовать методы обработки данных, а также вывести на экран всю необходимую информацию.

Важно! Имена переменным, классам и функциям давайте осознанные, состоящие из слов на английском языке.

1. Создайте структуру Person с 3 полями: фамилия, имя, отчество. Поле отчество должно
 быть опционального типа, т.к. не у всех людей есть отчество. Перегрузите оператор
 вывода данных для этой структуры. Также перегрузите операторы < и == (используйте tie).
2. Создайте структуру PhoneNumber с 4 полями:
· код страны (целое число)
· код города (целое число)
· номер (строка)
· добавочный номер (целое число, опциональный тип)
Для этой структуры перегрузите оператор вывода. Необходимо, чтобы номер телефона
 выводился в формате: +7(911)1234567 12, где 7 – это номер страны, 911 – номер города,
 1234567 – номер, 12 – добавочный номер. Если добавочного номера нет, то его выводить не надо.
 Также перегрузите операторы < и == (используйте tie)

3. Создайте класс PhoneBook, который будет в контейнере хранить пары: Человек – Номер телефона.
 Конструктор этого класса должен принимать параметр типа ifstream – поток данных,
 полученных из файла. В теле конструктора происходит считывание данных из файла и заполнение контейнера.
 Класс PhoneBook должен содержать перегруженный оператор вывода, для вывода всех данных из контейнера в консоль.
В классе PhoneBook реализуйте метод SortByName, который должен сортировать элементы контейнера
 по фамилии людей в алфавитном порядке. Если фамилии будут одинаковыми, то сортировка
 должна выполняться по именам, если имена будут одинаковы, то сортировка производится по отчествам.
 Используйте алгоритмическую функцию sort.
Реализуйте метод SortByPhone, который должен сортировать элементы контейнера по номерам телефонов.
Используйте алгоритмическую функцию sort.
Реализуйте метод GetPhoneNumber, который принимает фамилию человека, а возвращает кортеж из строки и PhoneNumber.
 Строка должна быть пустой, если найден ровно один человек с заданном фамилией в списке.
 Если не найден ни один человек с заданной фамилией, то в строке должна быть запись «not found»,
 если было найдено больше одного человека, то в строке должно быть «found more than 1».
Реализуйте метод ChangePhoneNumber, который принимает человека и новый номер телефона и,
 если находит заданного человека в контейнере, то меняет его номер телефона на новый,
 иначе ничего не делает.

Функция main будет выглядеть так:
int main() {
этого
ifstream file("ХХХ"); // путь к файлу PhoneBook.txt PhoneBook book(file);
cout << book;
cout << "------SortByPhone-------" << endl;
book.SortByPhone();
cout << book;
cout << "------SortByName--------" << endl;
book.SortByName();
cout << book;
cout << "-----GetPhoneNumber-----" << endl;
// лямбда функция, которая принимает фамилию и выводит номер телефона
человека, либо строку с ошибкой
auto print_phone_number = [&book](const string& surname) {
cout << surname << "\t";
auto answer = book.GetPhoneNumber(surname);
if (get<0>(answer).empty())
cout << get<1>(answer);
else
cout << get<0>(answer);
cout << endl;
};
// вызовы лямбды
print_phone_number("Ivanov");
print_phone_number("Petrov");
cout << "----ChangePhoneNumber----" << endl;
book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
PhoneNumber{7, 123, "15344458", nullopt});
book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
PhoneNumber{ 16, 465, "9155448", 13 });
cout << book;
}
======================================================================*/

#include <iostream>
#include "myclasses.h"

using namespace std;

int main()
{
	{ // Task 1
		cout << endl << "Task 1." << endl;

		Person per1{"Иванов", "Иван"};
		Person per2{"Петров","Петр","Петрович"};
		Person per3{"Петров","Петр"};

		cout << boolalpha << per1 << " < " << per3 << " is " << (per1 < per3) << endl;

		cout << per1 << " == " << per3 << " is " << (per1 == per3) << endl;

		cout << boolalpha << per2 << " < " << per3 << " is " << (per2 < per3) << endl;
	}

	{ // Task 2
		cout << endl << "Task 2." << endl;

		PhoneNumber n1{7, 900, "1234567", 12};
		cout << n1 << endl;
		PhoneNumber n2{13, 250, "7654321"};
		cout << n2 << endl;

		cout << boolalpha << n1 << " < " << n2 << " is " << (n1 < n2) << endl;
		cout << boolalpha << n1 << " == " << n2 << " is " << (n1 == n2) << endl;
	}

	{ // Task 3
		cout << endl << "Task 3." << endl;

		ifstream file("PhoneBook.txt");
		PhoneBook book(file);
		cout << book;

		cout << endl << "------SortByPhone-------" << endl;
		book.sortByPhone();
		cout << book;

		cout << endl << "------SortByName--------" << endl;
		book.sortByName();
		cout << book;

		cout << endl << "-----GetPhoneNumber-----" << endl;
		// лямбда функция, которая принимает фамилию и выводит номер телефона человека, либо строку с ошибкой
		auto print_phone_number = [&book](const string& surname) {
		cout << surname << "\t";
		auto answer = book.getPhoneNumber(surname);
		if (get<0>(answer).empty())
		cout << get<1>(answer);
		else
		cout << get<0>(answer);
		cout << endl;
		};

		// вызовы лямбды
		print_phone_number("Шойгу");
		print_phone_number("Асадов");
		cout << endl << "----ChangePhoneNumber----" << endl;
		book.changePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{7, 123, "15344458", nullopt});
		book.changePhoneNumber(Person{ "Королев", "Сергей", "Павлович" }, PhoneNumber{ 11, 465, "11111111", 13 });
		cout << book;
	}
}
