#ifndef FIRST_SESSION_STUDENT_H
#define FIRST_SESSION_STUDENT_H
#include "../Student/Student.h"


class FirstSessionStudent : public Student {
private:
    std::array<size_t, 4> marks;
    FirstSessionStudent();
public:
    // Constructors
    FirstSessionStudent(std::string, int32_t, std::string, std::array<size_t, 4>);
    FirstSessionStudent(const FirstSessionStudent&);
    virtual ~FirstSessionStudent();

    // Getter
    size_t getMarks(size_t) const;

    // Setter
    void setMarks(const size_t, const size_t);

    // The method for calculating the average score
    double calculateAverage() const;

    // The output operator
    friend std::ostream& operator<<(std::ostream&, const FirstSessionStudent&);
};
#endif // FIRST_SESSION_STUDENT_H
