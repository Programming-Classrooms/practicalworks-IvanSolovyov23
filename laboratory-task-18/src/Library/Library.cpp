#include "Library.hpp"


/*=================================================================*/
/*============== Методы для работы с библиотекой ==================*/
/*=================================================================*/

// Добавить автора
void Libary::add_book_on_libary(const Book& books) {
	vector_of_books.push_back(books);
}

// Найти книгк по ISBN
Book* Libary::find_book_by_ISBN(const std::string& ISBN) {
	for (auto& n : vector_of_books) {
		if (n.get_ISBN() == ISBN) {
			return &n;
		}
	}
	return nullptr;
}

// Удалить книгу по ISBN
bool Libary::delete_book_by_ISBN(const std::string& ISBN) {
    auto it = std::remove_if(vector_of_books.begin(), vector_of_books.end(), [&ISBN](const Book& book) {
        return book.get_ISBN() == ISBN;
        });
    if (it != vector_of_books.end()) {
        vector_of_books.erase(it, vector_of_books.end());
        return true;
    }
    return false;
}

// Показ библиотеки
void Libary::print_libary(std::vector<Book>& books) {
	std::copy(books.begin(), books.end(), std::ostream_iterator<Book>(std::cout, " "));
}

// Добавить автора по ISBN
bool Libary::add_author_by_ISBN(const std::string& ISBN, const std::string& author) {
    Book* book = this->find_book_by_ISBN(ISBN);
    if (book) {
        book->add_authors(author);
        return true;
    }
    return false;
}

// Удалить автора по ISBN 
bool Libary::remove_author_by_ISBN(const std::string& ISBN, const std::string& author) {
    Book* book = this->find_book_by_ISBN(ISBN);
    if (book) {
        book->remove_author(author);
        return true;
    }
    return false;
}

// Показать инфомацию о книге
void Libary::view_books() const {
    for (const auto& n : vector_of_books) {
        n.print();
    }
    std::cout << "\n\n";
}

// Сортировка книги по ISBN 
void Libary::sort_books_by_ISBN() {
    std::sort(vector_of_books.begin(), vector_of_books.end(), [](const Book& a, const Book& b) {
        return a.get_ISBN() < b.get_ISBN();
        });
}

// Сортировка книг по названию
void Libary::sort_books_by_title() {
    std::sort(vector_of_books.begin(), vector_of_books.end(), [](const Book& a, const Book& b) {
        return a.get_title() < b.get_title();
        });
}