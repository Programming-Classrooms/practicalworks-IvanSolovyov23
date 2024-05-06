#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <numeric>
#include <math.h>
#include <utility>
#include <stdexcept>


class Fraction {
private:

	int32_t numerator;     
	int32_t denominator;   
	void reduce();          

public:

	// Конструкторы
	Fraction();                   
	Fraction(const Fraction&);     
	Fraction(int32_t, int32_t);  
	Fraction(Fraction&&) noexcept;         

	// Деструктор
	~Fraction();

	// Геттеры 
	int32_t getNumerator() const;
	int32_t getDenominator() const;

	// Сеттеры
	void setNumerator(const int32_t);
	void setDenominator(const int32_t);

	// Перегрузки операторов преобразования типов
	explicit operator int32_t() const;
	explicit operator double() const;

	// Перегрузки операторов сравнения 
	bool operator==(const Fraction&) const;
	bool operator!=(const Fraction&) const;
	bool operator<(const Fraction&) const;
	bool operator>(const Fraction&) const;
	bool operator<=(const Fraction&) const;
	bool operator>=(const Fraction&) const;

	// Перегрузка бинарных алгебраических операторов (дробь + что-то)
	Fraction operator+(const Fraction&) const;
	Fraction operator-(const Fraction&) const;
	Fraction operator*(const Fraction&) const;
	Fraction operator/(const Fraction&) const;

	Fraction operator+(const int32_t&) const;
	Fraction operator-(const int32_t&) const;
	Fraction operator*(const int32_t&) const;
	Fraction operator/(const int32_t&) const;

	Fraction operator+(const double&) const;
	Fraction operator-(const double&) const;
	Fraction operator*(const double&) const;
	Fraction operator/(const double&) const;

	// Перегрузка бинарных алгебраических операторов (что-то + дробь)
	friend Fraction operator+(const int32_t&, const Fraction&);
	friend Fraction operator-(const int32_t&, const Fraction&);
	friend Fraction operator*(const int32_t&, const Fraction&);
	friend Fraction operator/(const int32_t&, const Fraction&);
	friend Fraction operator+(const double&, const Fraction&);
	friend Fraction operator-(const double&, const Fraction&);
	friend Fraction operator*(const double&, const Fraction&);
	friend Fraction operator/(const double&, const Fraction&);

	// Перегрузка операторов присваивания 
	Fraction& operator=(const Fraction& rhs);   
	Fraction& operator=(Fraction&&) noexcept;   
	Fraction& operator=(const int32_t);         

	Fraction& operator+=(const Fraction&);      
	Fraction& operator-=(const Fraction&);
	Fraction& operator*=(const Fraction&);
	Fraction& operator/=(const Fraction&);
	Fraction& operator+=(const int32_t);
	Fraction& operator-=(const int32_t);
	Fraction& operator*=(const int32_t);
	Fraction& operator/=(const int32_t);

	// Перегрузка унарных операторов
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	Fraction operator-();
	Fraction operator~();

	// Перегрузки операторов ввода/вывода
	friend std::istream& operator>>(std::istream&, Fraction&);
	friend std::ostream& operator<<(std::ostream&, const Fraction&);

	// Метод для вывода дроби
	void print() const;
};

#endif // FRACTION_H
