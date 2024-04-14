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

	// Êîíñòðóêòîðû 
	Fraction();                   
	Fraction(const Fraction&);     
	Fraction(int32_t, int32_t);  
	Fraction(Fraction&&) noexcept;         

	// Äåñòðóêòîð 
	~Fraction();

	// Ãåòòåðû 
	int32_t getNumerator() const;
	int32_t getDenominator() const;

	// Cåòòåðû
	void setNumerator(const int32_t);
	void setDenominator(const int32_t);

	// Ïåðåãðóçêè îïåðàòîðîâ ïðåîáðàçîâàíèÿ òèïîâ
	explicit operator int32_t() const;
	explicit operator double() const;

	// Ïåðåãðóçêè îïåðàòîðîâ ñðàâíåíèÿ 
	bool operator==(const Fraction&) const;
	bool operator!=(const Fraction&) const;
	bool operator<(const Fraction&) const;
	bool operator>(const Fraction&) const;
	bool operator<=(const Fraction&) const;
	bool operator>=(const Fraction&) const;

	// Ïåðåãðóçêà áèíàðíûõ àëãåáðàè÷åñêèõ îïåðàòîðîâ (äðîáü + ÷òî-òî)
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

	// Ïåðåãðóçêà áèíàðíûõ àëãåáðàè÷åñêèõ îïåðàòîðîâ (÷òî-òî + äðîáü)
	friend Fraction operator+(const int32_t&, const Fraction&);
	friend Fraction operator-(const int32_t&, const Fraction&);
	friend Fraction operator*(const int32_t&, const Fraction&);
	friend Fraction operator/(const int32_t&, const Fraction&);
	friend Fraction operator+(const double&, const Fraction&);
	friend Fraction operator-(const double&, const Fraction&);
	friend Fraction operator*(const double&, const Fraction&);
	friend Fraction operator/(const double&, const Fraction&);

	// Ïåðåãðóçêà îïåðàòîðîâ ïðèñâàèâàíèÿ 
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

	// Ïåðåãðóçêà óíàðíûõ îïåðàòîðîâ
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	Fraction operator-();
	Fraction operator~();

	// Ïåðåãðóçêè îïåðàòîðîâ ââîäà/âûâîäà
	friend std::istream& operator>>(std::istream&, Fraction&);
	friend std::ostream& operator<<(std::ostream&, const Fraction&);

	// Ìåòîä äëÿ âûâîäà äðîáè
	void print() const;
};

#endif // !FRACTION_H