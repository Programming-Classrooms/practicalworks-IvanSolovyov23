#include "functions.hpp"


//  Вывод нашего множества
void printSet(const std::string& header, const std::set<std::string>& s, std::ostream& os) {
    os << header << ": ";
    for (const auto& item : s) {
        os << item << " ";
    }
    os << "\n";
}

// Проверка файла
void checkFile(std::ofstream& fin)
{
	if (!fin.good()) {
		throw std::runtime_error("File isn't exist"); //Файл не найден
	}
	if (!fin) {
		throw std::runtime_error("Input file error"); //Ошибка открытия файла
	}
}