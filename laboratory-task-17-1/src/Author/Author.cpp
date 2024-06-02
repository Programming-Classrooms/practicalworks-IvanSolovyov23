#include "Author.hpp"


/*=============================================================*/
/*====================== Конструкторы =========================*/
/*=============================================================*/

// Конструктор по умолчанию
Author::Author() : name("Ivan"),
surname("Ivanov"),
patronymic("Ivanovich")
{}

// Конструктор с параметрами
Author::Author(const std::string initName,
    const std::string initSurname,
    const std::string initPatronymic) :
    name(initName),
    surname(initSurname),
    patronymic(initPatronymic)
{}

// Конструктор копирования
Author::Author(const Author& rhs) :
    name(rhs.name),
    surname(rhs.surname),
    patronymic(rhs.patronymic)
{}




/*=============================================================*/
/*========================== Геттеры ==========================*/
/*=============================================================*/

// Получаем имя автора
std::string Author::getName() const {
    return this->name;
}

// Получаем фамилию автора
std::string Author::getSurname() const {
    return this->surname;
}

// Получаем отчество автора
std::string Author::getPatronomic() const {
    return this->patronymic;
}




/*=============================================================*/
/*========================== Cеттеры ==========================*/
/*=============================================================*/

// Ввели автору имя
void Author::setName(const std::string initName) {
    this->name = initName;
}

// Ввели фамилию автору
void Author::setSurname(const std::string initSurname) {
    this->surname = initSurname;
}

// Ввели отчество автору
void Author::setPatronymic(const std::string initPatronymic) {
    this->patronymic = initPatronymic;
}




/*=============================================================*/
/*================== Оператор присваивания ====================*/
/*=============================================================*/

Author& Author::operator=(const Author& rhs) {
    if (&rhs != this) {
        name = rhs.name;
        surname = rhs.surname;
        patronymic = rhs.patronymic;
    }
    return *this;
}




/*=============================================================*/
/*==================== Оператор меньше ========================*/
/*=============================================================*/

bool Author::operator<(const Author& rhs) const {
    return (surname < rhs.surname);
}




/*=============================================================*/
/*==================== Оператор вывода ========================*/
/*=============================================================*/

//Оператор вывода
std::ostream& operator<<(std::ostream& os, const Author& rhs) {
    os << "Athor: " << rhs.getName() << rhs.getSurname() << rhs.getPatronomic();
    return os;
}