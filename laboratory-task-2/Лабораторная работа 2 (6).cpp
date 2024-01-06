/*
    Написать программу, которая для заданного натурального числа выполняет разложение числа на простые множители
*/ 


#include <iostream>
#include <exception>


size_t InputNumber(size_t n)
{

	std::cout << "Input natural n:";
	std::cin >> n;
	if (n <= 0)
	{
		throw std::exception("n isn't natural!");
	}
	return n;
}

int main()
{
	try
	{
		size_t n = 0;
		while (n < 1)
		{
			n = InputNumber(n);
			std::cout << n << " = ";
		while (n > 1)
		{
			for (size_t i = 2; i <= n;) 
			{
				if (n % i)
				{
					++i;
				}
				else
				{
					n /= i;
					if (n != 1)
					{
						std::cout << i << " * ";
					}
					else
					{
						std::cout << i;
					}
				}
			}
		}
	}
	return 0;
	}

	catch (std::exception e)
	{
		std::cerr << e.what() << '\n';
		return 0;
	}
}
