#ifndef LIBRARY_HPP
#define LIBRARY_HPP


#include "../Book/Book.hpp" 


class Library
{
protected:
    std::set<Book> Books;
public:
    // Конструкторы
    Library() = default;                    // По умолчанию
    Library(std::set<Book>&);               // С параметрами

    // Деструктор
    ~Library() = default;                  

    // Геттер
    std::set<Book> getBook() const;

    // Метод добавления книги
    void addBook(const Book& rhs);

    // Метод удаления книги
    void deleteBook(const Book& rhs);

    // Метод нахождения книги по названию    
    void searchTitle(const std::string& rhs);

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Library& rhs);

};

#endif // LIBRARY_HPP