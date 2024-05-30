#include "../Bus/Bus.hpp" 


/*===============================================*/
/*=============== Конструкторы ==================*/
/*===============================================*/

// По умолчанию 
 Bus::Bus() : numberTravel(1), 
              driver("Yashkin Victor Ivanovich"),
              numberBus(7121),
              markOfBus("Range Rover")
  {}

  // С параметрами
  Bus::Bus(size_t initNumberTravel, 
           std::string initDriver,
           size_t initNumberBus,
           std::string initMarkOfBus) :
    numberTravel(initNumberTravel),
    driver(initDriver),
    numberBus(initNumberBus),
    markOfBus(initMarkOfBus)
{}

// Копирования
Bus::Bus(const Bus& rhs) :
    numberTravel(rhs.numberTravel),
    driver(rhs.driver),
    numberBus(rhs.numberBus),
    markOfBus(rhs.markOfBus)
{}




/*===============================================*/
/*=================  Геттеры ====================*/
/*===============================================*/

// Получаем номер маршрута
size_t Bus::getNumberTravel() const {
    return this->numberTravel;
}

// Получаем имя водителя
std::string Bus::getDriver() const {
    return this->driver;
}

// Получаем номер автобуса
size_t Bus::getNumberBus() const {
    return this->numberBus;
}

// Получаем марку автобуса
std::string Bus::getMarkOfBus() const {
    return this->markOfBus;
}



/*===============================================*/
/*=================  Cеттеры ====================*/
/*===============================================*/

// Задаём номер маршрута
void Bus::setNumberTravel(const size_t initNumberTravel) {
    this->numberTravel = initNumberTravel;
}

// Задаём имя водителя
void Bus::setDriver(const std::string initDriver) {
    this->driver = initDriver;
}

// Задаём номер автобуса
void Bus::setNumberBus(const size_t initNumberBus) {
    this->numberBus = initNumberBus;
}

// Задаём марку автобуса
void Bus::setMarkOfBus(const std::string initMarkOfBus) {
    this->markOfBus = initMarkOfBus;
}




/*===============================================*/
/*===========  Оператор присваивания ============*/
/*===============================================*/

Bus& Bus::operator=(const Bus& rhs) {
    if (&rhs == this) {
        numberTravel = rhs.numberTravel;
        driver = rhs.driver;
        numberBus = rhs.numberBus;
        markOfBus = rhs.markOfBus;
    }
    return *this;
}




/*===============================================*/
/*=============  Оператор вывода ================*/
/*===============================================*/

std::ostream& operator<<(std::ostream& os, const Bus& rhs) {
    os << "\nNumber Travel: " << rhs.numberTravel <<
    "\nDriver: " << rhs.driver << 
    "\nNumber Bus: " << rhs.numberBus <<
    "\nMarks of Bus: " << rhs.markOfBus;
    return os;
}




/*===============================================*/
/*==============  Оператор ввода ================*/
/*===============================================*/

std::istream& operator>>(std::istream& is, Bus& rhs) {
    is >> rhs.numberTravel >> rhs.driver >> rhs.numberBus >> rhs.markOfBus;
    return is;
}
