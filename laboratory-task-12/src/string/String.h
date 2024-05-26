#ifndef STRING_H
#define STRING_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring>


class String {
private:
	char* data;
	size_t size;
public:
	// Конструкторы
	String();
	String(const char*);
	String(const String&);
	String(String&&) noexcept;
	
	// Деструктор
	~String();

	// Геттер
	char* getData(char* buffer) const;
	size_t getSize() const;

	// Cеттер
	void setData(const char* str);

	// Основные методы для работы со строкой
	void clear();
	void clone(const String& origin);
	void append(const char*);
	bool isEmpty() const;
	void getline();
	size_t capacity() const;
	size_t compare(const char*) const;
	size_t find(const char*) const;
	const char* begin() const;
	const char* end() const;
	char front() const;
	char back() const;

	// Операторы присваивания
	String& operator=(const String&);
	String operator+(const String&) const;
	String operator-(const String&) const;
	String& operator+=(const String&);
	String& operator-=(const String&);

	// Операторы сравнения 
	bool operator==(const String&) const;
	bool operator!=(const String&) const;
	bool operator>(const String&) const;
	bool operator>=(const String&) const;
	bool operator<(const String&) const;
	bool operator<=(const String&) const;

	// Операторы преобразования строки 
	operator std::string() const;
	operator int32_t() const;
	operator double() const;

	// Оператор ввода/вывода
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);
};


#endif // !STRING_H
