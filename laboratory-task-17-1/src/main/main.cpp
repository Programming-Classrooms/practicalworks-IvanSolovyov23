#include "../Library/Library.hpp"

int main()
{
    try
    {
        Library library;

        Author author1("Osiptsov ", "Aleksandr ", "Genadievich");
        Author author2("Ignatenko ", "Kirill ", "Aleksandrovich");

        AuthorList authorList1;
        authorList1.addAuthor(author1);
        authorList1.addAuthor(author2);

        Book book1(7121, "How to teach freshmen C++", 2024, authorList1);
        library.addBook(book1);

        std::cout << library << "\n";


        std::cout << "Enter name your book:\t";
        std::string nameBook;
        std::cin >> nameBook;
        library.searchTitle(nameBook);

        library.deleteBook(book1);

        std::cout << "\nLibrary after delete book" << library << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

}