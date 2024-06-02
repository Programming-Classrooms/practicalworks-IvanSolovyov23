#ifndef BOOK_H
#define BOOK_H


#include "../AuthorList/AuthorList.hpp"


class Book {
private:
	size_t UDK;		        // УДК
	std::string title;		// Название книги
	size_t year;			// Год выпуска
	AuthorList author;		// Авторы
public:
	// Конструкторы
	Book() = default;			    // По умолчанию
	Book(size_t initUDK,
		std::string initTitle,
		size_t initYear,
		AuthorList initAuthor);		// С параметрами
	Book(const Book& rhs);		    // Копирования

	// Деструктор
	~Book() = default;

	// Геттеры
	size_t getUDK() const;			// Получаем УДК
	std::string getTitle() const;   // Получаем название
	size_t getYear() const;         // Получаем год выпуска
	AuthorList getAuthors() const;  // Получаем авторов

	// Сеттеры
	void setUDK(const size_t initUDK);				// Задаћм УДК
	void setTitle(const std::string initTitle);     // Задаћм название
	void setYear(const size_t initYear);            // Задаћм год выпуска

	// Оператор сравнения
	bool operator==(const Book& rhs);

	// Методы дляя авторов
	void addAuthor(const Author& rhs);      // Метод добавления автора
	void removeAuthor(const Author& rhs);   // Метод удаления автора

	bool operator<(const Book& rhs) const;    // Перегрузка оператора < для корректной работы std::set

	// Оператор вывода
	friend std::ostream& operator<<(std::ostream& os, const Book& rhs);
};

#endif // BOOK_H