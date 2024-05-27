#include "FirstSessionStudent.h"


/*===========================================================================*/
/*========================== Constructors ===================================*/
/*===========================================================================*/

FirstSessionStudent::FirstSessionStudent(std::string initStudentName, int32_t initCourse, std::string initgroup,
    std::array<size_t, 4> initStudentMarks)
    : Student(initStudentName, initCourse, initgroup), marks(initStudentMarks) {}

FirstSessionStudent::FirstSessionStudent(const FirstSessionStudent& rhs)
    : Student(rhs), marks(rhs.marks) {}

FirstSessionStudent::~FirstSessionStudent() {}




/*===========================================================================*/
/*=============================== Getters ===================================*/
/*===========================================================================*/

size_t FirstSessionStudent::getMarks(size_t index) const {
    return marks.at(index);
}




/*===========================================================================*/
/*=============================== Setters ===================================*/
/*===========================================================================*/

void FirstSessionStudent::setMarks(const size_t index, const size_t value) {
    this->marks.at(index) = value;
}




/*===========================================================================*/
/*========================== Arithmetic mean ================================*/
/*===========================================================================*/

double FirstSessionStudent::calculateAverage() const {
    double sum = 0.0;
    for (size_t mark : marks) {
        sum += mark;
    }
    return sum / marks.size();
}

std::ostream& operator<<(std::ostream& out, const FirstSessionStudent& rhs) {
    out << static_cast<const Student&>(rhs) << "\nGrades: ";
    for (size_t mark : rhs.marks) {
        out << mark << " ";
    }
    return out;
}
