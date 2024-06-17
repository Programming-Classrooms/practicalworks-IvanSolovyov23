/*
    9. Словом в строке считается последовательность букв латинского
    алфавита, остальные символы являются разделителями между словами. За
    один просмотр символов строки найти все слова с максимальной долей
    гласных букв (т.е. прописных и строчных символов ’a’, ’e’, ’i’, ’o’,
    ’u’, ’y’) и занести их в новую строку. Слова в новой строке должны
    разделяться ровно одним пробелом.
*/


#include <iostream>
#include <string>
#include <cctype>


bool isVowel(char symbol) 
{
    symbol = tolower(symbol);
    return (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u' || symbol == 'y');
}

std::string findMaxVowelWords(const std::string& inputString) 
{
    std::string result;
    size_t maxVowelCount = 0;
    size_t currentVowelCount = 0;
    size_t quanitySymbols = inputString.length();
    std::string currentWord;

    for (size_t i = 0; i < quanitySymbols; ++i) {
        if ((static_cast<int>(inputString[i]) >= 192)&&(static_cast<int>(inputString[i]) <= 255))
        {
            throw std::exception("Wrong letter!");
        }
        else
        {
        if (isalpha(inputString[i])) {
            currentWord += inputString[i];
            if (isVowel(inputString[i])) {
                ++currentVowelCount;
            }
        }
        if (currentVowelCount == 0) {
            std::cout << "Does not exist" << '\n';
            return 0;
        }
        else {
            if (!currentWord.empty() && currentVowelCount >= maxVowelCount) {
                if (currentVowelCount > maxVowelCount) {
                    result = currentWord;
                    maxVowelCount = currentVowelCount;
                }
                else {
                    result += " " + currentWord;
                }
            }
            currentWord.clear();
            currentVowelCount = 0;
        }
    }

    if (!currentWord.empty() && currentVowelCount >= maxVowelCount) {
        if (currentVowelCount > maxVowelCount) {
            result = currentWord;
        }
        else {
            result += " " + currentWord;
        }
    }

    return result;
     }
 }

int main() 
{
    try
    {
    std::string inputSring;
    
    std::cout << "Input your string: ";
    std::getline(std::cin, inputSring);

    std::string maxVowelWords = findMaxVowelWords(inputSring);
    std::cout << "Word with maximum amount of vowels: " << maxVowelWords << '\n';
    return 0;
    }
    catch(std::exception e)
    {
        std::cerr << e.what() << '\n';
    }
}
