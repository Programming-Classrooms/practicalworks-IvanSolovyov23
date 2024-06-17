#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "../Person/Person.h"


class Student: public Person {
private:
	int course;
	int group;
public:
	// Конструкторы и деструктор
	Student();
	Student(char*, int, int);
	Student(const Student&);
	~Student();

	// Геттеры
	int getCourse() const;
	int getGroup() const;

	// Сеттеры
	void setCourse(const int);
	void setGroup(const int);
};

#endif // STUDENT_H
