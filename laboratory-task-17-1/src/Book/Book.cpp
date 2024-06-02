#include "Book.hpp"


/*=============================================================*/
/*====================== Конструкторы =========================*/
/*=============================================================*/

// Конструктор с параметрами
Book::Book(size_t initUDK,
	std::string initTitle,
	size_t initYear,
	AuthorList initAuthor) :
	UDK(initUDK),
	title(initTitle),
	year(initYear),
	author(initAuthor)
{}

// Конструктор копирования
Book::Book(const Book& rhs) :
	UDK(rhs.UDK),
	title(rhs.title),
	year(rhs.year),
	author(rhs.author)
{}




/*=============================================================*/
/*========================= Геттеры ===========================*/
/*=============================================================*/

// Получаем авторов
AuthorList Book::getAuthors() const {
	return this->author;
}

// Получаем год выпуска
size_t Book::getYear() const {
	return this->year;
}

// Получаем название книги
std::string Book::getTitle() const {
	return this->title;
}

// Получаем УДК
size_t Book::getUDK() const {
	return this->UDK;
}




/*=============================================================*/
/*========================= Cеттеры ===========================*/
/*=============================================================*/

// Задаћм УДК
void Book::setUDK(const size_t initUDK) {
	this->UDK = initUDK;
}

// Задаћм назввание книги
void Book::setTitle(const std::string initTitle) {
	this->title = initTitle;
}

// Задаћм год выпуска книги
void Book::setYear(const size_t initYear) {
	this->year = initYear;
}




/*=============================================================*/
/*=================== Оператор сравнения ======================*/
/*=============================================================*/

bool Book::operator==(const Book& rhs) {
	return (title == rhs.title ? true : false);
}




/*=============================================================*/
/*===================== Оператор меньше =======================*/
/*=============================================================*/

bool Book::operator<(const Book& rhs) const {
	return (title < rhs.title);
}




/*==============================================================*/
/*============= Методы добавления/удаления автора ==============*/
/*==============================================================*/

// Добавление автора
void Book::addAuthor(const Author& rhs) {
	author.addAuthor(rhs);
}

// Удаление автора
void Book::removeAuthor(const Author& rhs) {
	author.deleteAuthor(rhs);
}



/*=============================================================*/
/*===================== Оператор вывода =======================*/
/*=============================================================*/

//Оператор вывода
std::ostream& operator<<(std::ostream& os, const Book& rhs) {
	os << "Book\n" << "Title: " << rhs.getTitle()
		<< "Age publication: " << rhs.getYear()
		<< "Author: " << rhs.getAuthors()
		<< "UDK: " << rhs.getUDK();
	return os;
}