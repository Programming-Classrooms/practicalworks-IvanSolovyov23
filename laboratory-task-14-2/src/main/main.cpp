#include <iostream>
#include <array>
#include "../SecondSessionStudent/SecondSessionStudent.h"


int main()
{
    std::array<size_t, 4> firstGrades = { 6, 5, 8, 7 };
    FirstSessionStudent firstStudent("Starikov Rostislav Romanovich ", 1, "7121", firstGrades);

    std::cout << "First cadet info:\n" << firstStudent << "\n";
    std::cout << "First cadet average mark: " << firstStudent.calculateAverage() << std::endl;

    // Creating a student after the second session
    std::array<size_t, 5> secondGrades = { 7, 6, 7, 8, 9 };
    std::array<size_t, 4> firstGrades2 = { 7, 7, 4, 9 }; 
    SecondSessionStudent secondStudent("Soltanuk Maksim Michalovich", 1, "7121", firstGrades, secondGrades);

    std::cout << "\nSecond cadet info:\n" << secondStudent << "\n";
    std::cout << "Second cadet overall average mark: " << secondStudent.calculateOverallAverage() << std::endl;

    return 0;
}
