#include "Student.h"


/*==========================================================================*/
/*=========================== Конструкторы =================================*/
/*==========================================================================*/

Student::Student() : Person(), course(1), group(1) {}

Student::Student(char* initFullname, int initGroup, int initCourse) : Person(initFullname)
{
	if (initCourse <= 0)
	{
		throw std::invalid_argument("Invalid course.");
	}
	if (initGroup <= 0)
	{
		throw std::invalid_argument("Invalid group.");
	}
	
	course = initCourse;
	
	group = initGroup;
}

Student::Student(const Student& rhs) :
	Person(rhs),
	course(rhs.course), 
	group(rhs.group)
{}

Student::~Student() {}




/*==========================================================================*/
/*=============================== Геттеры ==================================*/
/*==========================================================================*/

int Student::getCourse() const {
	return this->course;
}

int Student::getGroup() const {
	return this->group;
}




/*==========================================================================*/
/*=============================== Cеттеры ==================================*/
/*==========================================================================*/

void Student::setCourse(const int initCourse) {
	if (initCourse <= 0)
	{
		throw std::invalid_argument("Invalid course.");
	}
	
	this->course = initCourse;
}

void Student::setGroup(const int initGroup) {
	if (initGroup <= 0)
	{
		throw std::invalid_argument("Invalid group.");
	}

	this->group = initGroup;
}
