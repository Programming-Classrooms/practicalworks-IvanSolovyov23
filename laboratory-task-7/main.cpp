/*
    //������� ������� ������������ ������    
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>


void input(char* inputString, const char* message = "Input your string:")
{
    std::cout << message << '\n';
    std::cin.getline(inputString, 256); //������� ������
}

// ������� ��� �������� ���������� ����� � ������
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
    const char* delimiter = " "; // ������-�����������
    char* inputString = new char[256];
    
    input(inputString);

    char* inputStringCopy = new char[strlen(inputString) + 1]; // �������� ����� ������, ������� strtok �������� ���������� �� ������, ������� ������ ������������ ��������� ������� � �������� ���������. ������ ����� ����� ������� ����� ������ � �������� ��������� �� ��� ������� strtok.

    strcpy(inputStringCopy, inputString);

    char* word = strtok(inputStringCopy, delimiter); // ��������� ������ �� �����

    size_t maxZeros = 0; // ������������ ���������� �����
    char* maxZerosWord = nullptr; // ����� � ������������ ����������� �����

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
