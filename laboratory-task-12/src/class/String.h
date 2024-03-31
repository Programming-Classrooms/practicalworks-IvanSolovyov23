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
	// ����������� 
	String();
	String(const char*);
	String(const String&);
	String(String&&) noexcept;
	
	// �����������
	~String();

	// �������
	const char* getData() const;
	size_t getLength() const;

	// C�����
	void setData(const char* str);

	// �������� ������ ��� ������ �� ��������
	void clear();
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

	// �������� ���������
	String& operator=(const String&);
	String operator+(const String&) const;
	String operator-(const String&) const;
	String& operator+=(const String&);
	String& operator-=(const String&);

	// ��������� ���������
	bool operator==(const String&) const;
	bool operator!=(const String&) const;
	bool operator>(const String&) const;
	bool operator>=(const String&) const;
	bool operator<(const String&) const;
	bool operator<=(const String&) const;

	// ��������� �������������� �����
	operator std::string() const;
	operator int32_t() const;
	operator double() const;

	// �������� �������


	// ��������� ����� � ������ 
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);
};


#endif // !STRING_H
