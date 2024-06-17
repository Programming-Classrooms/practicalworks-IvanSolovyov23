#include "Functions.hpp"


std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
        [](unsigned char c) {return std::tolower(c); });
    return lowerStr;
}


void processFile(const std::string& filename, std::unordered_map<std::string, int>& wordCount, std::set<std::string>& uniqueWords) {
    std::ifstream fin(filename);
    if (!fin.good()) {
        throw std::runtime_error("File isn't exist");   // Файл не найден
    }
    if (!fin) {
        throw std::runtime_error("Input file error");   // Ошибка открытия файла
    }
    if (fin.peek() == EOF) {
        throw std::runtime_error("File is empty");      // Файл пустой
    }

    std::string word;
    while (fin >> word) {
        
        word = toLower(word);   // Приведение слова к нижнему регистру

        if (!word.empty()) {
            wordCount[word]++;
            uniqueWords.insert(word);
        }
    }
    fin.close();
}