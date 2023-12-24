// Calculate the sum of a series: e^x= 1+(x/1!)+ (x^2/2!) + ...
#include <iostream> 
#define USE_MATH_DEFINES
#include <cmath>
int main()
{
	setlocale(LC_ALL, "RU");
	double x, epsilon;
	int k;
	std::cout << "Enter value x:" << std:: endl;
	std::cin >> x;
	do {
		std:: cout << "Enter the number of series terms to calculate k (k>1):" << std:: endl;
		std:: cin >> k;
	} while (k <= 1);
	epsilon = pow(10, -k);
	double result = 1.0;
	double term = 1.0;
	int n = 1;
	while (fabs(term) >= epsilon)
	{
		term *= x / n;
		result += term;
		n++;
	}
	double standard_result = exp(x);
	std:: cout << "Approximate sum of series:" << result << std:: endl;
	std:: cout << "Meaning exp(x):" << standard_result << std:: endl;
	return 0;
}
