/* ======================================================================
1. Установить библиотеку protobuf.

2. С помощью компилятора protobuf в отдельном пространстве имен сгенерировать классы:
a. FullName с полями имя, фамилия, отчество (отчество опционально).
b. Student с полями полное имя, массив оценок, средний балл.
c. StudentsGroup с полем массив студентов.

3. Создать класс StudentsGroup, который реализует интерфейсы:
class IRepository {
virtual void Open() = 0; // бинарная десериализация в файл
virtual void Save() = 0; // бинарная сериализация в файл
};
class IMethods {
virtual double GetAverageScore(const FullName& name) = 0;
virtual string GetAllInfo(const FullName& name) = 0;
virtual string GetAllInfo() = 0;
};
======================================================================*/

#include <iostream>
#include <numeric>
#include "myclasses.h"

int main()
{
	dz7::FullName fn;
	fn.set_name("Petr");
	fn.set_surname("Petrov");
	fn.set_patronymic("Ivanovich");

	dz7::Student st;
	*st.mutable_name() = fn;
	st.add_grades(5);
	st.add_grades(2);
	st.add_grades(4);
	st.add_grades(3);
	st.add_grades(4);
	st.add_grades(3);
	st.add_grades(4);
	st.add_grades(3);
	st.set_avg_score(std::accumulate(st.grades().begin(), st.grades().end(), 0) / st.grades().size());

	NS::StudentsGroup sg;
	sg.add_student(st);
	sg.Save();

	NS::StudentsGroup new_sg;
	new_sg.Open();
	std:: cout << new_sg.GetAllInfo(fn) << std::endl;
}
