#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>


class Matrix {
private:

	int32_t** data;
	size_t rows;
	size_t columns;

public:
	// Конструкторы
	Matrix();
	Matrix(size_t, size_t);
	Matrix(const Matrix&);

	// Деструктор
	~Matrix();

	// Геттеры
	size_t getRows() const;
	size_t getColumns() const;
	const int32_t& getElement(size_t, size_t) const;

	//Сеттеры
	void setElements(size_t, size_t, int32_t);

	// Операторы присваивания
	Matrix& operator=(const Matrix& rhs);

	// Оператор сравнения
	bool operator==(const Matrix&) const;
	bool operator!=(const Matrix&) const;

	// Некторые методы
	void fillRandom(int32_t, int32_t);
	void print() const;
	int32_t determinantBySarrusMethod() const;

	// Бинарные алгебраические операторы (матрица ? что-то)
	Matrix operator+(const Matrix&);
	Matrix operator+(const int32_t&) const;
	Matrix operator-(const Matrix&);
	Matrix operator-(const int32_t&) const;
	Matrix operator*(const Matrix&);
	Matrix operator*(const int32_t&) const;
	Matrix operator/(const int32_t&) const;

	// Бинарные алгеьраические операторы (что-то ? матрица)
    friend Matrix operator*(int32_t, const Matrix&);

	// Перегрузка составных операторов присваивания 
	Matrix& operator+=(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);

	// Оператор ввода и вывода
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	friend std::istream& operator>>(std::istream&, Matrix&);


};
#endif // !MATRIX_H
