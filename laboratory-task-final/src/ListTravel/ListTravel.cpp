#include "../ListTravel/ListTravel.hpp"


/*===============================================*/
/*================ Конструктор ==================*/
/*===============================================*/

// С параметрами
ListTravel::ListTravel(std::list<Bus> initAllTravel) :
    allTravel(initAllTravel)
{}




/*===============================================*/
/*=============  Оператор вывода ================*/
/*===============================================*/

std::ostream& operator<<(std::ostream& os, const ListTravel& rhs) {
    os << "\nAll travel: " << rhs.allTravel;
    return os;
}





/*===============================================*/
/*======= Методы для спсика всех поездок ========*/
/*===============================================*/

// Метод для нахождения количесва уникальных поездок
/*std::optional<size_t> ListTravel::CountUniqueTravel(std::list<Bus>& initAllTravel) {
    size_t counter;
    while (!initAllTravel.empty()) {
    if (initAllTravel.unique()) {
        ++counter;
    }
    }
    if (counter == 0) {
        return std::nullopt;
    }
    return counter;
}
*/
// Метод для нахождения водителей на маршруте
/*void ListTravel::FindDriver(std::list<Bus>& initAllTravel) {
    size_t yourTravel;
    for (auto& n : initAllTravel) {
        if (n.getNumberTravel() == yourTravel) {
            std::cout << n.getDriver();
        }
    }
}
*/
