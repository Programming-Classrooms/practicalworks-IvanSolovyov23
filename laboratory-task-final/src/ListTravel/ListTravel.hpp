#ifndef LIST_TRAVEL_HPP
#define LIST_TRAVEL_HPP


#include "../Bus/Bus.hpp"

#include <list>         // std::list
#include <optional>     // std::optional


class ListTravel {
private:
    std::list<Bus> allTravel;
public:
    // Конструкторы
    ListTravel() = default;                     // По умолчанию
    ListTravel(std::list<Bus> initAllTravel);   // C параметрами
    ~ListTravel() = default;                    // Деструктор 

    // Оператор ввода
    friend std::ostream& operator<<(std::ostream& os, const ListTravel& rhs);

    // Методы для работы со списком всех поездок
    //std::optional<size_t> CountUniqueTravel(std::list<Bus>& initAllTravel);
    //void FindDriver(std::list<Bus>& initAllTravel);
};

#endif //LIST_TRAVEL_HPP
