#ifndef SECOND_SESSION_STUDENT_H
#define SECOND_SESSION_STUDENT_H
#include "../FirstSessionStudent/FirstSessionStudent.h"


class SecondSessionStudent : public FirstSessionStudent {
private:
    std::array<size_t, 5> secondSessionGrades;
    SecondSessionStudent();
public:
    // Constructors and destructor
    SecondSessionStudent(std::string, int32_t, std::string, std::array<size_t, 4>, std::array<size_t, 5>);
    SecondSessionStudent(const SecondSessionStudent&);
    ~SecondSessionStudent();

    // Getter
    size_t getSecondMarks(size_t) const;

    // Setter
    void setSecondMarks(size_t, size_t);

    // The method for calculating the average score
    double calculateOverallAverage() const;

    //The output operator
    friend std::ostream& operator<<(std::ostream&, const SecondSessionStudent&);
};

#endif // SECOND_SESSION_STUDENT_H
