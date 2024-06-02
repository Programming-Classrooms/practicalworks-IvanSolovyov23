#include "Book.hpp"


/*==================================================================*/
/*========================== ISBN ==================================*/
/*==================================================================*/

std::string Book::unique_string = "AAAAAAAAAAAA@";


std::string& Book::incr_ISBN()
{
	if (unique_string[0] == 'Z')
	{
		throw std::out_of_range("Too many books.");
	}

	
	for (int32_t i = 12; i > -1; --i)
	{
		if (unique_string[i] == 'Z')
		{
			if (unique_string[i-1] == 'Z')
			{
				continue;
			}
			unique_string[i] = 'A';
			++unique_string[i - 1];
			return unique_string;
		}

		++unique_string[i];
		return unique_string;
	}
	
}




/*==================================================================*/
/*====================== Конструкторы ==============================*/
/*==================================================================*/


Book::Book() : ISBN("AAAAAAAAAAAA"), title("Applied Cryptography"), author("Bruce Schneier"), price(232), copies(10000)
{}
Book::Book(const std::string& inittitle, const std::string& initauthor, const size_t initprice, const size_t initcopies, const std::vector<std::string>& initvectorofauthors) :
	ISBN(incr_ISBN()), 
	title(inittitle), 
	author(initauthor), 
	price(initprice),
	copies(initcopies), 
	vector_of_authors(initvectorofauthors)
{}
Book::Book(const Book& rhs) : 
	ISBN(incr_ISBN()),
	title(rhs.title),
	author(rhs.author),
	price(rhs.price),
	copies(rhs.copies)
{}
Book::~Book() {}




/*==================================================================*/
/*=========================== Геттеры ==============================*/
/*==================================================================*/

std::string Book::get_ISBN() const {
	return this->ISBN;
}

std::string Book::get_author() const {
	return this->author;
}

std::string Book::get_title() const {
	return this->title;
}

size_t Book::get_price() const {
	return this->price;
}

size_t Book::get_copies() const {
	return this->copies;
}




/*==================================================================*/
/*=========================== Сеттеры ==============================*/
/*==================================================================*/

void Book::set_author(const std::string initauthor) {
	this->author = initauthor;
}

void Book::set_copies(const size_t initcopies) {
	this->copies = initcopies;
}

void Book::set_price(const size_t initprice) {
	this->price = initprice;
}

void Book::set_title(const std::string inittitle) {
	this->title = inittitle;
}




/*==================================================================*/
/*==================== Оператор сравнения ==========================*/
/*==================================================================*/

bool Book::operator==(const Book& rhs) {
	return (this->title == rhs.title ? true : false);
}




/*==================================================================*/
/*==================== Оператор присваивания =======================*/
/*==================================================================*/

Book& Book::operator=(const Book& rhs) {
	if (&rhs != this) {
		ISBN = rhs.ISBN;
		title = rhs.title;
		author = rhs.author;
		price = rhs.price;
		copies = rhs.copies;
	}
	return *this;
}




/*==================================================================*/
/*================== Операторы ввода/вывода ========================*/
/*==================================================================*/

std::ostream& operator<<(std::ostream& os, const Book& rhs) {
	os << "\nISBN:\t" << rhs.ISBN << "\nTitle:\t" << rhs.title << "\nAuthor:\t" << rhs.author << "\nPrice:\t" << rhs.price << "\nCopies:\t" << rhs.copies;
	return os;
}

std::istream& operator>>(std::istream& is, Book& rhs) {
	is >> rhs.ISBN >> rhs.title >> rhs.author >> rhs.price >> rhs.copies;
	return is;
}




/*==================================================================*/
/*=================== Методы для "авторов" =========================*/
/*==================================================================*/

// Добавить автора
void Book::add_authors(const std::string& author) {
	vector_of_authors.push_back(author);
}

// Удалить автора
void Book::remove_author(const std::string& author) {
	auto it = std::remove(vector_of_authors.begin(), vector_of_authors.end(), author);
	if (it != vector_of_authors.end()) {
		vector_of_authors.erase(it, vector_of_authors.end());
	}
}

// Вывод информации о книге
void Book::print() const {
	std::cout << "\nBook (ISBN: " << ISBN << ", Title: " << title << ", Authors: " << author;
	for (const auto& n : vector_of_authors) {
		std::cout << "," << n << " ";
	}
	std::cout << ", Price: " << price << ", Copies: " << copies << ")\n";
}
