#ifndef LIBARY_HPP
#define LIBARY_HPP

#include <iterator>

#include "../Book/Book.hpp"

class Libary : public Book {
private:
	std::vector<Book> vector_of_books;
public:
	/*Методы для работы с книгами*/

	void add_book_on_libary(const Book&);									// Добавить книгу в библиотеку
	Book* find_book_by_ISBN(const std::string&);							// Найти книгу по ISBN
	bool delete_book_by_ISBN(const std::string&);							// Удалить книгу по ISBN
	void print_libary(std::vector<Book>&);									// Показ библиотеки
	bool add_author_by_ISBN(const std::string&, const std::string&);		// Добавить автора по ISBN
	bool remove_author_by_ISBN(const std::string&, const std::string&);		// Удалить автора по ISBN 
	void view_books() const;												// Показать информацию о книге
	void sort_books_by_ISBN();												// Сортировка книг по ISBN
	void sort_books_by_title();												// Сортировка книг по названию
};

#endif // LIBARY_H