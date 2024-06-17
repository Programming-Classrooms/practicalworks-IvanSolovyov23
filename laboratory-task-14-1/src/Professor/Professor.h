#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "../Person/Person.h"


class Professor : public Person {
private:
	char* department;
public:
	// Конструкторы и деструктор
	Professor();
	Professor(char*, char*);
	Professor(const Professor&);
	~Professor();

	// Геттер
	char* getDepartment(char* buffer) const;

	// Сеттер
	void setDepartment(char*);
};

#endif // PROFESSOR_H
