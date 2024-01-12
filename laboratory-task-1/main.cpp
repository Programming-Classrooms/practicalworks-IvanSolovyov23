/*
	Посчитать сумму ряда e^x = ...
*/

#include <iostream>
#include <cmath>
#include <string>


double calculateExponentialRow(double x, double epsilon)
{
    double term = 1.0;
    double sum = 1.0;
    size_t index = 1;

    while (std::abs(term) > epsilon) {
        term = term * x / index;
        sum += term;
        ++index;
    }
    return sum;
}

int main() 
{
    try {
        double x = 0.0;
        std::cout << "Enter the degree e: " << '\n';
        std::cin >> x;
        if (std::cin.fail()) {
            std::cout << "The entered value is not a valid number" << '\n';
            return 0;
        }

        double epsilon = 1e-6;
        double result = calculateExponentialRow(x, epsilon);

        std::cout << "e^" << x << " = " << result << '\n';
        std::cout << "Check result: " <<  exp(x);

        return 0;
    }
    catch (std::exception e)
    {
        std::cerr << "exception: " << e.what();
    }
}
