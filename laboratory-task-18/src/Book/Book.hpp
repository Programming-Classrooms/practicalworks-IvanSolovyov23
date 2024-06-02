#ifndef BOOK_HPP
#define BOOK_HPP


#include <iostream>
#include <vector>			// std::vector


class Book {
private:
	std::string ISBN;								// Уникальный идентификатор
	std::string title;								// Название книги
	std::string author;								// Автор книги
	size_t price;									// Цена книги
	size_t copies;									// Количество экземпляров
	std::vector<std::string> vector_of_authors;		// Вектор авторов
	static std::string unique_string;				// Статическая строка для идентификатора
	std::string& incr_ISBN();						// Приватный метод для идентификатора
public:
	// Конструкторы 
	Book();		// По умолчанию
	Book(const std::string&, const std::string&, const size_t, const size_t, const std::vector<std::string>&); // С параметрами
	Book(const Book&);	// Копирования

	// Деструктор
	~Book();

	// Геттеры
	std::string get_ISBN() const;
	std::string get_title() const;
	std::string get_author() const;
	size_t get_price() const;
	size_t get_copies() const;

	// Сеттеры
	void set_title(const std::string);
	void set_author(const std::string);
	void set_price(const size_t);
	void set_copies(const size_t);

	// Оператор сравнения
	bool operator==(const Book&);

	// Оператор присваивания
	Book& operator=(const Book&);

	// Дружественные операторы ввода и вывода
	friend std::ostream& operator<<(std::ostream&, const Book&);
	friend std::istream& operator>>(std::istream&, Book&);

	// Добавить автора
	void add_authors(const std::string&);

	// Удалить автора
	void remove_author(const std::string&);

	// Метод для вывода
	void print() const;

};
#endif // BOOK_H
