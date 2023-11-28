#include <iostream>

int main() {
    int number;
    std::cout << "Enter a natural number: ";
    std::cin >> number;

    int maxDigit = 0;
    int maxCount = 0;
    int tempNumber = number;

    while (tempNumber > 0) {
        int digit = tempNumber % 10;
        int count = 0;
        int tempNumber2 = number;

        while (tempNumber2 > 0) {
            if (tempNumber2 % 10 == digit) {
                count++;
            }
            tempNumber2 /= 10;
        }

        if (count > maxCount || (count == maxCount && digit > maxDigit)) {
            maxCount = count;
            maxDigit = digit;
        }

        tempNumber /= 10;
    }

    std::cout << "Result: ";
    for (int i = 0; i < maxCount; i++) {
        std::cout << maxDigit;
    }
    std::cout << number;
    for (int i = 0; i < maxCount; i++) {
        std::cout << maxDigit;
    }
    std::cout << std::endl;

    return 0;
}