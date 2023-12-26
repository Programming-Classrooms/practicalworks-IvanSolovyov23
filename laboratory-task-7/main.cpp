/*
    //добаить условие лабораторной работы    
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>


void input(char* inputString, const char* message = "Input your string:")
{
    std::cout << message << '\n';
    std::cin.getline(inputString, 256); //Входная строка
}

// Функция для подсчета количества нулей в строке
int countZeros(const char* str) {
    size_t count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '0') {
            ++count;
        }
    }
    return count;
}

int main()
{
    const char* delimiter = " "; // Символ-разделитель
    char* inputString = new char[256];
    
    input(inputString);

    char* inputStringCopy = new char[strlen(inputString) + 1]; // Создание копии строки, Функция strtok изменяет переданную ей строку, поэтому нельзя использовать строковый литерал в качестве аргумента. Вместо этого нужно создать копию строки и передать указатель на нее функции strtok.

    strcpy(inputStringCopy, inputString);

    char* word = strtok(inputStringCopy, delimiter); // Разбиение строки на слова

    size_t maxZeros = 0; // Максимальное количество нулей
    char* maxZerosWord = nullptr; // Слово с максимальным количеством нулей

    while (word != nullptr) {
        bool isDigitOnly = true;
        for (size_t i = 0; word[i] != '\0'; ++i) {
            if (!isdigit(word[i])) {
                isDigitOnly = false;
                break;
            }
        }
        if (isDigitOnly) {
            size_t zerosCount = countZeros(word);
            if (zerosCount > maxZeros) {
                maxZeros = zerosCount;
                maxZerosWord = word;
            }
        }
        word = strtok(nullptr, delimiter);
    }

    if (maxZerosWord != " ") {
        std::cout << "Word with maximum number of zeros: " << maxZerosWord << '\n';
    }
    else {
        std::cout << "There are no words in the line that consist only of numbers." << '\n';
    }

    return 0;
}
