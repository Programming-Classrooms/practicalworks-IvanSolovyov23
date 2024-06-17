#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string.h>


class Person {
protected:
	char* fullName;
public:
	// Конструкторы и деструктор
	Person();
	Person(char*);
	Person(const Person&);
	virtual ~Person();

	// Геттер
	char* getFullName(char*) const;

	// Cеттер
	void setFullName(char*);

};

#endif // PERSON_H
