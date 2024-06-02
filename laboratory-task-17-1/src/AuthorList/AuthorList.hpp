#ifndef AUTHOR_LIST_HPP
#define AUTHOR_LIST_HPP


#include "../Author/Author.hpp"   // class Auhor


#include <set>          // std::set
#include <optional>     // std::optional


class AuthorList {
private:
	std::set<Author> authors;	                // множество которое хранит авторов
public:
	// Конструкторы
	AuthorList() = default;						// Конструктор по умолчанию
	AuthorList(std::set<Author>& initAuthors);	// Конструктор с параметрами

	// Деструктор
	~AuthorList() = default;

	// Геттеры
	std::optional<size_t> getCountAuthorInList() const;		// Получаем количество авторов
	std::set<Author> getAuthors() const;                    // Геттер авторов

	// Методы для списка авторов
	void addAuthor(const Author& rhs);      // Добавление автора
	void deleteAuthor(const Author& rhs);   // Удаление автора

	// Оператор вывода
	friend std::ostream& operator<<(std::ostream& os, const AuthorList& rhs);
};

#endif // AUTHOR_LIST_HPP

