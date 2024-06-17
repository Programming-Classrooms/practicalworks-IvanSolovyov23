#include "src/Library/Library.hpp"
#include "src/Book/Book.hpp"

int main() 
{
    Libary library;

    // Добавляем книги
    Book book1("Harry Potter", "J.Rowling", 20, 10000000, {""});
    Book book2("Lord of rings", "J.Tolkinen", 31, 2000000, {""});
    Book book3("Master and Margarita", "M.Bulgakov", 17, 10000, {""});


    library.add_book_on_libary(book1);
    library.add_book_on_libary(book2);
    library.add_book_on_libary(book3);


    // Демонстация "библиотеки"
    std::cout << "All books:\n";
    library.view_books();


    // Поиск книги по ISBN
    std::cout << "Search book:\n";
    std::cout << "Enter ISBN:\t";
    std::string temp_ISBN;
    std::cin >> temp_ISBN;
    Book* foundBook = library.find_book_by_ISBN(temp_ISBN);
    if (foundBook) {
        foundBook->print();
    }
    else {
        std::cout << "In library there are not this book.\n";
    }


    // Удаление книги по ISBN
    std::cout << "Enter ISBN for delete this book:\t";
    std::cin >> temp_ISBN;
    library.delete_book_by_ISBN(temp_ISBN);
    std::cout << "Libary after delete:\n";
    library.view_books();


    // Добавить автора по ISBN
    std::cout << "Enter ISBN and add author:\t";
    std::cout << "ISBN: ";
    std::cin >> temp_ISBN;
    std::string temp_author;
    std::cout << "Author: ";
    std::cin >> temp_author;
    library.add_author_by_ISBN(temp_ISBN, temp_author);
    std::cout << "Libary after add author:\n";
    library.view_books();

    
    // Удалить автора по ISBN
    std::cout << "Enter ISBN and delte author:\n";
    std::cout << "ISBN: ";
    std::cin >> temp_ISBN;
    std::cout << "Author: ";
    std::cin >> temp_author;
    library.remove_author_by_ISBN(temp_ISBN, temp_author);
    std::cout << "Libary after add author:\n";
    library.view_books();

    
    // Сортировка "Библиотеки" по ISBN
    library.sort_books_by_ISBN();
    std::cout << "Labary after sort by ISBN:\n";
    library.view_books();

   
    // Сортировка "Библиотеки" по названию
    library.sort_books_by_title();
    std::cout << "Libary after sort by title:\n";
    library.view_books();


	return 0;
}
