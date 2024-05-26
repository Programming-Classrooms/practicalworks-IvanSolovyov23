#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"


/*==========================================================================*/
/*=========================== Конструкторы =================================*/
/*==========================================================================*/

Person::Person() {
    this->fullName = new char[1];
    this->fullName[0] = '\0';
}

Person::Person(char* initFullName) {

    if (initFullName == nullptr || !strlen(initFullName))
    {
        throw std::invalid_argument("Empty name.");
    }

    fullName = new char[strlen(initFullName) + 1];
    strcpy(fullName, initFullName);
}

Person::Person(const Person& rhs) : fullName(rhs.fullName) 
{}

Person::~Person() 
{ 
    delete[] this->fullName; 
}





/*==========================================================================*/
/*=============================== Геттер ===================================*/
/*==========================================================================*/

char* Person::getFullName(char* buffer) const {
	if (buffer != nullptr)
    {
        delete[] buffer;
    }

    buffer = new char[strlen(fullName) + 1];
    strcpy(buffer, fullName);
    return buffer;
}




/*==========================================================================*/
/*=============================== Cеттер ===================================*/
/*==========================================================================*/

void Person::setFullName(char* initFullName) {
    if (initFullName == nullptr || !strlen(initFullName))
    {
        throw std::invalid_argument("Empty name.");
    }

    if (fullName != nullptr)
    {
        delete[] fullName;
    }

    fullName = new char[strlen(initFullName) + 1];
    strcpy(fullName, initFullName);
}
