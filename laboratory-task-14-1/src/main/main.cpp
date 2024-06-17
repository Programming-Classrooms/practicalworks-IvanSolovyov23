#include "../Person/Person.h"
#include "../Professor/Professor.h"
#include "../Student/Student.h"
#include <iostream>


int main()
{
    char* temp = nullptr;
    try {
        const int MAX_SIZE = 100;
        Person* persons[MAX_SIZE];
        size_t count = 0;

        uint16_t choice;
        do {
            std::cout << "Menu:\n"
                "1. Add a student\n"
                "2. Add a professor\n"
                "3. Show list of students\n"
                "4. Show list of professors\n"
                "5. Exit\n"
                "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1: {
                char name[100];
                int group, course;
                std::cout << "Enter student's full name: ";
                std::cin.ignore();
                std::cin.getline(name, 100);
                std::cout << "Enter student's group: ";
                std::cin >> group;
                std::cout << "Enter student's course: ";
                std::cin >> course;
                persons[count++] = new Student(name, group, course);
                break;
            }
            case 2: {
                char name[100];
                char department[100];
                std::cout << "Enter professor's full name: ";
                std::cin.ignore();
                std::cin.getline(name, 100);
                std::cout << "Enter professor's department: ";
                std::cin.getline(department, 100);
                persons[count++] = new Professor(name, department);
                break;
            }
            case 3:
                std::cout << "List of students:\n";
                for (size_t i = 0; i < count; ++i) {
                    Student* student = dynamic_cast<Student*>(persons[i]);
                    if (student != nullptr) {
                        std::cout << "Name: " << student->getFullName(temp) << ", Group: " << student->getGroup() << ", Course: " << student->getCourse() << std::endl;
                    }
                }
                break;
            case 4:
                std::cout << "List of professors:\n";
                for (size_t i = 0; i < count; ++i) {
                    Professor* professor = dynamic_cast<Professor*>(persons[i]);
                    if (professor != nullptr) {
                        std::cout << "Name: " << professor->getFullName(temp) << ", Department: " << professor->getDepartment(temp) << std::endl;
                    }
                }
                break;
            case 5:
                std::cout << "Exiting...\n";
                delete[] temp;
                break;
            default:
                throw std::logic_error("Invalid choice. Please try again.");
            }
        } while (choice != 5);

        for (size_t i = 0; i < count; ++i) {
            delete persons[i];
        }
    }
    catch (const std::logic_error& re) {
        delete[] temp;
        std::cerr << "Logic error exception caught: " << re.what() << '\n';
    }
    return 0;
}
