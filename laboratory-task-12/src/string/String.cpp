#include "String.h"
#include <string>


/* =========================================================================== */
/* ============================== Конструкторы =============================== */
/* =========================================================================== */

String::String() : data(nullptr), size(0) {}

String::String(const char* str) : data(nullptr), size(1) {
    if (str != nullptr) {
        size = std::strlen(str);
        data = new char[size + 1];
        std::strcpy(data, str);
    }
}

String::String(const String& rhs) : data(rhs.data), size(rhs.size) {
    if (rhs.data != nullptr) {
        data = new char[size + 1];
        std::strcpy(data, rhs.data);
    }
}

String::String(String&& rhs) noexcept: size(1)  {
    {
        data = rhs.data;
        rhs.size = 1;
        rhs.data = nullptr;
    }
}

String::~String() {
    clear();
}




/* =========================================================================== */
/* ============================ Геттеры ====================================== */
/* =========================================================================== */

const char* String::getData() const {
    const char* temp = data;
    return temp;
}

size_t String::getSize() const {
    return this->size;
}




/* =========================================================================== */
/* ============================= Сеттеры ====================================== */
/* =========================================================================== */

void String::setData(const char* str) {
    delete[] data;
    if (str != nullptr) {
        size = std::strlen(str);
        data = new char[size + 1];
        std::strcpy(data, str);
    }
    else {
        data = nullptr;
        size = 0;
    }
}




/* =========================================================================== */
/* ================= Основные методы для работы со строкой =================== */
/* =========================================================================== */

void String::clear() {
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }
    size = 0;
}

void String::append(const char* str) {
    size_t newLength = size + strlen(str);
    char* newData = new char[newLength + 1];
    if (data) {
        strcpy(newData, data);
        delete[] data;
    }
    strcpy(newData + size, str);
    data = newData;
    size = newLength;
}

bool String::isEmpty() const {
    return size == 0;
}

void String::getline() {
    char buffer[1000]; 
    std::cin.getline(buffer, 1000);
    clear();
    append(buffer);
}

size_t String::capacity() const {
    return size;
}

size_t String::compare(const char* str) const {
    return strcmp(data, str);
}

size_t String::find(const char* substr) const {
    char* ptr = strstr(data, substr);
    if (ptr) {
        return ptr - data; 
    }
    throw std::logic_error("String is empty");
}

const char* String::begin() const {
    return data;
}

const char* String::end() const {
    return data + size;
}

char String::front() const {
    return data[0];
}

char String::back() const {
    return data[size - 1];
}




/* =========================================================================== */
/* ======================== Алгебраические операторы ========================= */
/* =========================================================================== */

String& String::operator=(const String& rhs) {
    if (this != &rhs) {
        delete[] data;

        size = rhs.size;
        if (rhs.data != nullptr) {
            data = new char[size + 1];
            strcpy(data, rhs.data);
        }
        else {
            data = nullptr;
        }
    }
    return *this;
}

String String::operator+(const String& rhs) const {
    String result;
    result.size = size + rhs.size;
    result.data = new char[result.size + 1];
    std::strcpy(result.data, data);
    std::strcat(result.data, rhs.data);
    return result;
}

String String::operator-(const String& rhs) const {
    String result;
    result.size = size - rhs.size;
    if (result.size < 0) result.size = 0;
    result.data = new char[result.size + 1];
    std::strncpy(result.data, data, size - rhs.size);
    result.data[result.size] = '\0';
    return result;
}

String& String::operator+=(const String& rhs) {
    *this = *this + rhs;
    return *this;
}

String& String::operator-=(const String& rhs) {
    *this = *this - rhs;
    return *this;
}




/* =========================================================================== */
/* ======================== Операторы сравнения ============================== */
/* =========================================================================== */

bool String::operator==(const String& rhs) const
{
    return !(*this != rhs);
}

bool String::operator!=(const String& rhs) const
{
    return strcmp(data, rhs.data);
}

bool String::operator>(const String& rhs) const
{
    return (*this != rhs) && !(*this < rhs);
}

bool String::operator>=(const String& rhs) const
{
    return !(*this < rhs);
}

bool String::operator<(const String& rhs) const
{
    return (strcmp(data, rhs.data) < 0);
}

bool String::operator<=(const String& rhs) const
{
    return !(*this > rhs);
}



/* =========================================================================== */
/* =================== Операторы преобразования строки ======================= */
/* =========================================================================== */

String::operator std::string() const {
    std::string temp(data);
    return temp;
}

String::operator int32_t() const {
    return std::stoi(static_cast<std::string>(*this));
}

String::operator double() const {
    return std::stod(static_cast<std::string>(*this));
}




/* =========================================================================== */
/* =================== Оператор вывода и ввода =============================== */
/* =========================================================================== */

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.data;
    return os;
}

std::istream& operator>>(std::istream& is, String& str) {
    char buffer[1000];
    is >> buffer;
    str.setData(buffer);
    return is;
}
