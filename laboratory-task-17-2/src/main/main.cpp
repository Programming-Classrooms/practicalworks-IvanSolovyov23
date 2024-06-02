#include "../Functions/Functions.hpp"




int main()
{
    std::string filename = "src/main/information.txt";
    std::unordered_map<std::string, int> wordCount;
    std::set<std::string> uniqueWords;

    try {
        processFile(filename, wordCount, uniqueWords);

        // Вывод списка всех слов
        std::cout << "List of all words in the file:\n";
        for (const auto& word : uniqueWords) {
            std::cout << word << "\n";
        }

        // Вывод количества вхождений каждого слова
        std::cout << "\nWord counts:\n";
        for (const auto& entry : wordCount) {
            std::cout << entry.first << ": " << entry.second << "\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}