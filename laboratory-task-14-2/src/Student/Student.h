#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <array>
#include <ctime>
#include <random>

class Student {
private:
    const size_t ID;
    std::string studentName;
    int32_t course;
    std::string group;
    static size_t studentID;
    Student();
public:
    // Constructors and desttructor
    Student(std::string, int32_t, std::string);
    Student(const Student&);
    virtual ~Student();

    // Getters
    size_t getId() const;
    std::string getName() const;
    int32_t getCourse() const;
    std::string getGroup() const;
    size_t getStudentId() const;

    // Setters
    void setID(const size_t);
    void setName(const std::string);
    void setCourse(const int32_t);
    void setGroup(const std::string);
    void setStudentID(const size_t);

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};
#endif // STUDENT_H
