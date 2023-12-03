// Написать программу, которая для заданного натурального числа выполняет разложение числа на простые множители
#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	while (n < 1)
	{
		cout << "Input natural n:";
		cin >> n;
	}
	cout << n << " = ";
	while (n > 1)
	{
		for (int i = 2; i <= n;)
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
					cout << i << " * ";
				}
				else
				{
					cout << i;
				}
			}
		}
	}

	return 0;
}