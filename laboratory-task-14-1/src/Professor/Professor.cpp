#define _CRT_SECURE_NO_WARNINGS
#include "Professor.h"


/*==========================================================================*/
/*=========================== Конструкторы =================================*/
/*==========================================================================*/

Professor::Professor() : Person() {
	this->department = new char[1];
	this->department[0] = '\0';
}

Professor::Professor(char* initFullName, char* initdepartment) : Person(initFullName) {
    if (initdepartment == nullptr || !strlen(initdepartment))
	{
		throw std::invalid_argument("Empty department.");
	}
	
	department = new char[strlen(initdepartment) + 1];
    strcpy(department, initdepartment);
}

Professor::Professor(const Professor& rhs) : Person(rhs), department(rhs.department) {}

Professor::~Professor() { delete[] this->department; }




/*==========================================================================*/
/*============================== Геттер ====================================*/
/*==========================================================================*/

char* Professor::getDepartment(char* buffer) const {
	if (buffer != nullptr)
	{
		delete[] buffer;
	}

	buffer = new char[strlen(department) + 1];
	strcpy(buffer, department);
	return buffer;
}




/*==========================================================================*/
/*============================== Cеттер ====================================*/
/*==========================================================================*/

void Professor::setDepartment(char* initdepartment) {
	if (initdepartment == nullptr || !strlen(initdepartment))
	{
		throw std::invalid_argument("Empty department.");
	}

	if (department != nullptr)
	{
		delete[] department;
	}

	department = new char[strlen(initdepartment) + 1];
	strcpy(department, initdepartment);
}
