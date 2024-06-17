/*
    Написать программу, которая для заданного натурального числа выполняет разложение числа на простые множители
*/ 


#include <iostream>


int main()
{
	size_t n = 0;
	while (n < 1)
	{
		std::cout << "Input natural n:";
		std::cin >> n;
	std::cout << n << " = ";
	while (n > 1) {
		for (size_t i = 2; i <= n;) {
			if (n % i) {
				++i;
			}
			else
			{
				n /= i;
				if (n != 1) {
					std::cout << i << " * ";
				}
				else
				{
					std::cout << i;
				}
			}
		}
	}
	return 0;
}

