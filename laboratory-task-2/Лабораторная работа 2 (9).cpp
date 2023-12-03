// Написать программу, которая для заданного натурального числа N находит дружественное, не превышающие это число:
#include <iostream>
using namespace std;
	int main ()
	{
		int n = 0;
		while (n < 1)
		{
			cout << "Input in:";
			cin >> n;
		}
		int temp1, temp2;
		for (int i = 2; i <= n; ++i)
		{
			temp1 = i;
			int sum1 = 1;
			int sum2 = 1;
			for (int j = 2; j < temp1; ++j)
			{
				if (!(temp1 % j))
				{
					sum1 += j;
				}
			}
			temp2 = sum1;
			for (int k = 2; k < temp2; ++k)
			{
				if (!(temp2 % k))
				{
					sum2 += k;
				}
			}
			if (sum2 == temp1 && temp1 < temp2)
			{
				cout << temp1 << " " << "and" << " " << temp2 << endl;
			}
		}

		return 0;
    }

	

