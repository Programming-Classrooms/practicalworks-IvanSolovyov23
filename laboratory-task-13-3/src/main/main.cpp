#include "../funcs/List.h"

int main()
{
    try {
        LinkedList<int> list;

        
        list.prepend(1);
        list.append(2);
        list.append(3);
        list.prepend(0);

        std::cout << "List size: " << list.getSize() << std::endl;
        std::cout << "List is empty? " << list.isEmpty() << std::endl;
        std::cout << "List elements: ";
        list.forEach([](const int& data) {
            std::cout << data << " ";
            });
        std::cout << std::endl;

        list.remove(2);
        std::cout << "After removing 2: ";
        list.forEach([](const int& data) {
            std::cout << data << " ";
            });
        std::cout << std::endl;
    }

    catch (const std::logic_error& re) {
        std::cerr << "Logic error exception caught: " << re.what() << '\n';
    }
    return 0;
}
