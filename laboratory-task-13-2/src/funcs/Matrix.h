#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>


class Matrix {
private:

	int32_t** data;
	size_t rows;
	size_t columns;

public:
	// ������������
	Matrix();
	Matrix(size_t, size_t);
	Matrix(const Matrix&);

	// ����������
	~Matrix();

	// �������
	size_t getRows() const;
	size_t getColumns() const;
	const int32_t& getElement(size_t, size_t) const;

	//�������
	void setElements(size_t, size_t, int32_t);

	// ��������� ������������
	Matrix& operator=(const Matrix& rhs);

	// �������� ���������
	bool operator==(const Matrix&) const;
	bool operator!=(const Matrix&) const;

	// �������� ������
	void fillRandom(int32_t, int32_t);
	void print() const;
	int32_t determinantBySarrusMethod() const;

	// �������� �������������� ��������� (������� ? ���-��)
	Matrix operator+(const Matrix&);
	Matrix operator+(const int32_t&) const;
	Matrix operator-(const Matrix&);
	Matrix operator-(const int32_t&) const;
	Matrix operator*(const Matrix&);
	Matrix operator*(const int32_t&) const;
	Matrix operator/(const int32_t&) const;

	// �������� �������������� ��������� (���-�� ? �������)
    friend Matrix operator*(int32_t, const Matrix&);

	// ���������� ��������� ���������� ������������ 
	Matrix& operator+=(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);

	// �������� ����� � ������
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	friend std::istream& operator>>(std::istream&, Matrix&);


};
#endif // !MATRIX_H
