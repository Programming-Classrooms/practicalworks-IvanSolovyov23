// ������������ ������ 1. �������� ����
//e^x= 1+(x/1!)+ (x^2/2!) + ...
#include <iostream> 
#define USE_MATH_DEFINES
#include <cmath>


using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	double x, epsilon;
	int k;
	cout << "������� �������� �:" << endl;
	cin >> x;
	do {
		cout << "������� �������� k (k>1):" << endl;
		cin >> k;
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
	cout << "������������ ��������:" << result << endl;
	cout << "�������� � �������������� exp(x):" << standard_result << endl;
	return 0;
}
