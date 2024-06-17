#ifndef AUTHOR_HPP
#define AUTHOR_HPP


#include <iostream>
#include <string>


class Author {
private:
	std::string surname;		// Фамилия автора
	std::string name;           // Имя автора 
	std::string patronymic;     // Отчество автора
public:
	// Конструкторы
	Author();	                         // Конструктор по умолчанию
	Author(const Author& rhs);           // Конструтор копирования
	Author(std::string initsurname,
		std::string initname,
		std::string initpatronymic);     // Конструктор с параметрами


	// Деструктор
	~Author() = default;


	// Геттеры
	std::string getName() const;
	std::string getSurname() const;
	std::string getPatronomic() const;


	// Сеттеры
	void setName(const std::string initName);
	void setSurname(const std::string initSurname);
	void setPatronymic(const std::string initPatronymic);


	// Оператор присваивания 
	Author& operator=(const Author& rhs);

	// Оператор меньше(для std::set)
	bool operator<(const Author& rhs) const;


	// Оператор вывода и ввода
	friend std::ostream& operator<< (std::ostream& os, const Author& rhs);	// Вывода


};
#endif // AUTHOR_APP
