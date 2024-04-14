
#include "Fraction.hpp"


/* =========================================================================== */
/* ============================ Ïðèâàòíûé ìåòîä ============================== */
/* =========================================================================== */

void Fraction::reduce() {
	int32_t number = this->numerator;
	if (this->numerator < 0) {
		number *= -1;
	}
	int32_t divisor = std::gcd(number, this->denominator);
	this->numerator /= divisor;
	this->denominator /= divisor;
}




/*=============================================================================*/
/*============================== Êîíñòðóêòîðû =================================*/
/*=============================================================================*/

// Êîíñòðóêòîð ïî óìîë÷àíèþ 
Fraction::Fraction() : numerator(0), denominator(0) {}

// Êîíñòðóêòîð ñ ïàðàìåòðàìè 
Fraction::Fraction(int32_t initnumerator, int32_t initdenominator) :
	numerator(initnumerator),
	denominator(initdenominator)
{
	if (denominator == 0) {
		throw std::invalid_argument("Denominator can't be zero");
	}
	this->reduce();
}

// Êîíñòðóêòîð êîïèðîâàíèÿ 
Fraction::Fraction(const Fraction& rhs) :
	numerator(rhs.numerator),
	denominator(rhs.denominator)
{}

// Êîíñòðóêòîð ïåðåìåùåíèÿ 
Fraction::Fraction(Fraction&& rhs) noexcept {
	numerator = rhs.numerator;
	denominator = rhs.denominator;

	rhs.numerator = 0;
	rhs.denominator = 0;
}

// Äåñòðóêòîð 
Fraction::~Fraction() {}




/* =========================================================================== */
/* ============================ Ãåòòåðû ====================================== */
/* =========================================================================== */

int32_t Fraction::getNumerator() const {
	return this->numerator;
}

int32_t Fraction::getDenominator() const {
	return this->denominator;
}


/* =========================================================================== */
/* ============================ Cåòòåðû ====================================== */
/* =========================================================================== */

void Fraction::setNumerator(const int32_t origin) {
    if (this->denominator == 0) {
        this->denominator = 1;
        this->numerator = origin;
    }
	this->numerator = origin;
	this->reduce();
}

void Fraction::setDenominator(const int32_t origin) {
	if (origin == 0) {
		throw std::invalid_argument("Denominator can't be zero");
	}
	this->denominator = origin;
	this->reduce();
}




/* =========================================================================== */
/* =================== Ïåðåãðóçêè îïåðàòîðîâ ïðåîáðàçîâàíèÿ ================== */
/* =========================================================================== */

Fraction::operator double() const {
	return (static_cast<double>(this->numerator) / this->denominator);
}

Fraction::operator int32_t() const {
	return static_cast<int32_t>(this->numerator / this->denominator);
}




/* =========================================================================== */
/* ==================== Ïåðåãðóçêè îïåðàòîðîâ ïðèñâàèâàíèÿ =================== */
/* =========================================================================== */

Fraction& Fraction::operator=(const Fraction& rhs) {
	if (&rhs == this) {
		throw std::logic_error("You can't do that!");
	}

	this->numerator = rhs.numerator;
	this->denominator = rhs.denominator;
	return *this;
}

Fraction& Fraction::operator=(Fraction&& rhs) noexcept {
	numerator = rhs.numerator;
	denominator = rhs.denominator;

	rhs.numerator = 0;
	rhs.denominator = 0;

	return *this;
}

Fraction& Fraction::operator=(int32_t origin) {
	this->numerator = origin;
	this->denominator = 1;
	return *this;
}



/* =========================================================================== */
/* ===================== Ïåðåãðóçêè îïåðàòîðîâ ñðàâíåíèÿ ===================== */
/* =========================================================================== */

bool Fraction::operator==(const Fraction& rhs) const
{
	return this->numerator == rhs.numerator && this->denominator == rhs.denominator;
}

bool Fraction::operator!=(const Fraction& rhs) const
{
	return !(*this == rhs);
}

bool Fraction::operator<(const Fraction& source) const
{
	return (this->numerator * source.denominator) < (this->denominator * source.numerator);
}

bool Fraction::operator<=(const Fraction& rhs) const
{
	return (*this < rhs || *this == rhs);
}

bool Fraction::operator>(const Fraction& rhs) const
{
	return !(*this <= rhs);
}

bool Fraction::operator>=(const Fraction& rhs) const
{
	return !(*this < rhs);
}




/* =========================================================================== */
/* ============== Ïåðåãðóçêè áèíàðíûõ àðèôìåòè÷åñêèõ îïåðàòîðîâ ============== */
/* =========================================================================== */

Fraction Fraction::operator+(const Fraction& rhs) const {
	Fraction result;
	result.numerator = this->numerator * rhs.denominator + rhs.numerator * this->denominator;
	result.denominator = this->denominator * rhs.denominator;
	result.reduce();
	return result;
}

Fraction Fraction::operator-(const Fraction& rhs) const {
	Fraction result;
	result.numerator = this->numerator * rhs.denominator - rhs.numerator * this->denominator;
	result.denominator = this->denominator * rhs.denominator;
	result.reduce();
	return result;
}

Fraction Fraction::operator*(const Fraction& rhs) const {
	Fraction result;
	result.numerator = this->numerator * rhs.numerator;
	result.denominator = this->denominator * rhs.denominator;
	result.reduce();
	return result;
}

Fraction Fraction::operator/(const Fraction& rhs) const {
	if (!rhs.numerator) {
		throw std::logic_error("You can't divide by zero!");
	}
	Fraction result;
	result.numerator = this->numerator * rhs.denominator;
	result.denominator = this->denominator * rhs.numerator;
	result.reduce();
	return result;
}

Fraction Fraction::operator+(const int32_t& rhs) const {
	return Fraction(this->numerator + rhs * this->denominator, this->denominator);
}

Fraction Fraction::operator-(const int32_t& rhs) const {
	return Fraction(this->numerator - rhs * this->denominator, this->denominator);
}

Fraction Fraction::operator*(const int32_t& rhs) const {
	return Fraction(this->numerator * rhs, this->denominator);
}

Fraction Fraction::operator/(const int32_t& rhs) const {
	if (rhs == 0) {
		throw std::invalid_argument("You can't divide by zero!");
	}
	return Fraction(this->numerator / rhs, this->denominator);
}

Fraction Fraction::operator+(const double& rhs) const {
	return Fraction(this->numerator + rhs * this->denominator, this->denominator);
}

Fraction Fraction::operator-(const double& rhs) const {
	return Fraction(this->numerator - rhs * this->denominator, this->denominator);
}

Fraction Fraction::operator*(const double& rhs) const {
	return Fraction(this->numerator * rhs, this->denominator);
}

Fraction Fraction::operator/(const double& rhs) const {
	if (rhs == 0.0) {
		throw std::invalid_argument("You can't divide by zero!");
	}
	return Fraction(this->numerator / rhs, this->denominator);
}

Fraction operator+(const int32_t& number, const Fraction& rhs) {
	int32_t newNumerator = number * rhs.denominator + rhs.numerator;
	return Fraction(newNumerator, rhs.denominator);
}

Fraction operator-(const int32_t& number, const Fraction& rhs) {
	int32_t newNumerator = number * rhs.denominator - rhs.numerator;
	return Fraction(newNumerator, rhs.denominator);
}

Fraction operator*(const int32_t& number, const Fraction& rhs) {
	int32_t newNumerator = number * rhs.numerator;
	return Fraction(newNumerator, rhs.denominator);
}

Fraction operator/(const int32_t& number, const Fraction& rhs) {
	int32_t newNumerator = number * rhs.denominator;
	int32_t newDenominator = rhs.numerator;
	return Fraction(newNumerator, newDenominator);
}

Fraction operator+(const double& number, const Fraction& rhs) {
	double result = number + (static_cast<double>(rhs.numerator) / rhs.denominator);
	return Fraction(result * rhs.denominator, rhs.denominator);
}

Fraction operator-(const double& number, const Fraction& rhs) {
	double result = number - (static_cast<double>(rhs.numerator) / rhs.denominator);
	return Fraction(result * rhs.denominator, rhs.denominator);
}

Fraction operator*(const double& number, const Fraction& rhs) {
	double result = number * (static_cast<double>(rhs.numerator) / rhs.denominator);
	return Fraction(result * rhs.denominator, rhs.denominator);
}

Fraction operator/(const double& number, const Fraction& rhs) {
	double result = number / (static_cast<double>(rhs.numerator) / rhs.denominator);
	return Fraction(result * rhs.denominator, rhs.denominator);
}




/* =========================================================================== */
/* ============== Ïåðåãðóçêè îïåðàòîðîâ cîñòàâíîãî ïðèñâàèâàíèÿ ============== */
/* =========================================================================== */

Fraction& Fraction::operator+=(const Fraction& rhs) {
	int32_t newNumerator = this->numerator * rhs.denominator + rhs.numerator * this->denominator;
	int newDenominator = this->denominator * rhs.denominator;
	this->numerator = newNumerator;
	this->denominator = newDenominator;
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& rhs) {
	int32_t newNumerator = this->numerator * rhs.denominator - rhs.numerator * this->denominator;
	int newDenominator = this->denominator * rhs.denominator;
	this->numerator = newNumerator;
	this->denominator = newDenominator;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& rhs) {
	this->numerator *= rhs.numerator;
	this->denominator *= rhs.denominator;
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
	this->numerator *= other.denominator;
	this->denominator *= other.numerator;
	return *this;
}

Fraction& Fraction::operator+=(const int32_t rhs) {
	return (*this = *this + rhs);
}

Fraction& Fraction::operator-=(const int32_t rhs) {
	return (*this = *this - rhs);
}

Fraction& Fraction::operator*=(const int32_t rhs) {
	return (*this = *this * rhs);
}

Fraction& Fraction::operator/=(const int32_t rhs) {
	return (*this = *this / rhs);
}




/* =========================================================================== */
/* ============== Ïåðåãðóçêà óíàðíûõ àðèôìåòè÷åñêèõ îïåðàòîðîâ =============== */
/* =========================================================================== */

Fraction& Fraction::operator++()
{
	return *this += 1;
}

Fraction Fraction::operator++(int)
{
	Fraction temp = *this;
	*this += 1;
	return temp;
}

Fraction& Fraction::operator--()
{
	return *this -= 1;
}

Fraction Fraction::operator--(int)
{
	Fraction temp = *this;
	*this -= 1;
	return temp;
}

Fraction Fraction::operator-() {
	return Fraction(-(this->numerator), this->denominator);
}

Fraction Fraction::operator~() {
	return Fraction(this->denominator, this->numerator);
}




/* =========================================================================== */
/* ================== Ïåðåãðóçêè îïåðàòîðîâ âûâîäà/ââîäà ===================== */
/* =========================================================================== */

std::istream& operator>>(std::istream& in, Fraction& rhs) {
	int32_t temporaryNumerator = 0;
	int32_t temporaryDenominator = 0;
	in >> temporaryNumerator;
	std::string slash;
	in >> slash;
	in >> temporaryDenominator;

	if (temporaryDenominator == 0) {
		throw std::logic_error("You can't divide by zero!");
		return in;
	}

	rhs.numerator = temporaryNumerator;
	rhs.denominator = temporaryDenominator;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& rhs) {
	out << rhs.numerator << "/" << rhs.denominator;
	return out;
}




/* =========================================================================== */
/* ========================= Ìåòîä äëÿ âûâîäà äðîáè ========================== */
/* =========================================================================== */

void Fraction::print() const {
	std::cout << numerator << "/" << denominator;
}
