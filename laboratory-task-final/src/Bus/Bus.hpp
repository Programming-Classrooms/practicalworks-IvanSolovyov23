#ifndef BUS_HPP
#define BUS_HPP


#include <iostream>

class Bus {
private:
    size_t numberTravel;    // Номер маршрута 
    std::string driver;     // Имя водителя
    size_t numberBus;       // Номер автобуса
    std::string markOfBus;  // Марка автобуса
public:
    // Конструкторы
    Bus();                                          // По умолчанию
    Bus(size_t initNumberTravel, 
        std::string initDriver,
        size_t initNumberBus,
        std::string initMarkOfBus);                 // С параметрами
    Bus(const Bus& rhs);                            // Копирования
    ~Bus() = default;                               // Деструктор

    // Геттеры
    size_t getNumberTravel() const;     // Получаем номер маршрута 
    std::string getDriver() const;      // Получаем имя водителя 
    size_t getNumberBus() const;        // Получаем номер автобуса
    std::string getMarkOfBus() const;   // Получаем марку автобуса

    // Сеттеры
    void setNumberTravel(const size_t initNumberTravel);    // Задаём номер маршрута
    void setDriver(const std::string initDriver);           // Задаём имя водителя
    void setNumberBus(const size_t initNumberBus);          // Задаём номер автобуса
    void setMarkOfBus(const std::string initMarkOfBus);     // Задаём марку автобуса

    // Оператор присваивания
    Bus& operator=(const Bus& rhs);

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Bus& rhs);

    // Оператор ввода
    friend std::istream& operator>>(std::istream& is, Bus& rhs);
    

};

#endif // BUS_HPP
