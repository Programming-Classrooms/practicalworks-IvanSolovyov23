#include "SecondSessionStudent.h"


/*===========================================================================*/
/*========================== Constructors ===================================*/
/*===========================================================================*/

SecondSessionStudent::SecondSessionStudent(std::string initStudentName, int32_t initCourse, std::string initgroup,
    std::array<size_t, 4> initStudentMarks, std::array<size_t, 5> initsecondMarks)
    : FirstSessionStudent(initStudentName, initCourse, initgroup, initStudentMarks), secondSessionGrades(initsecondMarks) {}

SecondSessionStudent::SecondSessionStudent(const SecondSessionStudent& rhs)
    : FirstSessionStudent(rhs), secondSessionGrades(rhs.secondSessionGrades) {}

SecondSessionStudent::~SecondSessionStudent() {}




/*===========================================================================*/
/*============================= Getters =====================================*/
/*===========================================================================*/

size_t SecondSessionStudent::getSecondMarks(size_t index) const {
    return this->secondSessionGrades.at(index);
}




/*===========================================================================*/
/*============================== Setters ====================================*/
/*===========================================================================*/

void SecondSessionStudent::setSecondMarks(size_t index, size_t value) {
    this->secondSessionGrades.at(index) = value;
}

double SecondSessionStudent::calculateOverallAverage() const {
    double sum = calculateAverage();
    for (size_t mark : secondSessionGrades) {
        sum += mark;
    }
    return sum / (secondSessionGrades.size() + 1);
}

std::ostream& operator<<(std::ostream& out, const SecondSessionStudent& rhs) {
    out << static_cast<const FirstSessionStudent&>(rhs) << "\nSecond session grades: ";
    for (size_t mark : rhs.secondSessionGrades) {
        out << mark << " ";
    }
    return out;
}
