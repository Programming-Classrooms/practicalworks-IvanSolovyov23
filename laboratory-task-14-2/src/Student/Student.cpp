#include "Student.h"

size_t Student::studentID = 1;


/*===========================================================================*/
/*========================== Constructors ===================================*/
/*===========================================================================*/

Student::Student(std::string initStudentName, int32_t initcourse, std::string initgroup)
    : ID(studentID++), studentName(initStudentName), course(initcourse), group(initgroup) {}

Student::Student(const Student& rhs)
    : ID(studentID++), studentName(rhs.studentName), course(rhs.course), group(rhs.group) {}

Student::~Student() {}




/*===========================================================================*/
/*=============================== Getters ===================================*/
/*===========================================================================*/

size_t Student::getId() const {
    return this->ID;
}

std::string Student::getName() const {
    return this->studentName;
}

int32_t Student::getCourse() const {
    return this->course;
}

std::string Student::getGroup() const {
    return this->group;
}




/*===========================================================================*/
/*=============================== Setters ===================================*/
/*===========================================================================*/

void Student::setName(const std::string initName) {
    this->studentName = initName;
}

void Student::setCourse(const int32_t initCourse) {
    this->course = initCourse;
}

void Student::setGroup(const std::string initGroup) {
    this->group = initGroup;
}




/*===========================================================================*/
/*========================== Output operator ================================*/
/*===========================================================================*/

std::ostream& operator<<(std::ostream& out, const Student& rhs) {
    out << "ID: " << rhs.ID << "\nName: " << rhs.studentName << "\nCourse: " << rhs.course
        << "\nGroup: " << rhs.group << "\nStudent ID: " << rhs.studentID;
    return out;
}
