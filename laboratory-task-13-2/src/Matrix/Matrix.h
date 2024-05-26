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

	// Сеттеры
	void setElement(size_t, size_t, int32_t);

	// Оператор присваивания
	Matrix& operator=(const Matrix& rhs);

	// Оператор сравнения
	bool operator==(const Matrix&) const;
	bool operator!=(const Matrix&) const;

	// Методы для работы с матрицей
	void fillRandom(int32_t, int32_t);
	void print() const;
	void clear();
	void clone(const Matrix&);

	// Перегрузка бинарных алгебраических операторов (Матрица (?) скаляр)
	Matrix operator+(const Matrix&);
	Matrix operator+(const int32_t&) const;
	Matrix operator-(const Matrix&);
	Matrix operator-(const int32_t&) const;
	Matrix operator*(const Matrix&);
	Matrix operator*(const int32_t&) const;
	Matrix operator/(const int32_t&) const;

	// Дружественный оператор умножения (скаляр (?) матрица)
    friend Matrix operator*(int32_t, const Matrix&);

	// Перегрузка составных оператров присваивания
	Matrix& operator+=(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);

	// Операторы вывода и ввода
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	friend std::istream& operator>>(std::istream&, Matrix&);


};
#endif // MATRIX_H
