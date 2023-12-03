#include <iostream>
#include <ctime>
#include <exception>


int sumElements(int size, int* arr, int sum)
{
	for (int i = 0; i < size; ++i)
	{
			sum += arr[i];
	}
	return sum;
}
void bublle(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int t = 0; t < size - 1; ++t)
		{
			if (arr[t + 1] < arr[t])
			{
				std::swap(arr[t + 1], arr[t]);
			}
		}
	}
}
void random(int size, int* arr, int x, int y)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = x + rand() % (y - x + 1);
	}
}
void otric(int size, int arr[])
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			std::cout << arr[i] << '\t';
		}
		
	}
}

int find_first_zero(int* arr, int size)
{
	int first_zero = -1;
	for (size_t i = 0; i < size; ++i)
	{
		if (arr[i] == 0)
		{
			first_zero = i;
			break;
		}
		
	}
	return first_zero;
}

int find_last_zero(int* arr, int size)
{
	int last_zero = -1;
	for (size_t i = size - 1; i >= 0; --i)
	{
		if (arr[i] == 0)
		{
			last_zero = i;
			break;
		}

	}
	return last_zero;
}

void check_zeroes(int last_zero, int first_zero)
{
	if (last_zero == -1)
	{
		throw std::exception("Not found 0");
	}
	if (last_zero == first_zero)
	{
		throw std::exception("not enough 0");
	}
}

int sum_between_zeroes(int* arr, int first_zero, int last_zero)
{
	int sum = 0;
	for (size_t i = first_zero; i <= last_zero; ++i)
	{
		
		sum += arr[i];
	}
	return sum;
}

void polog(int size, int arr[])
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > 0);
		{
			std::cout << arr[i] << '\t';
		}
	}
}
void vivod(int size, int* arr)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << "|" << arr[i] << "|" << '\t';
	}
}
int composition( int size, int* arr)
{
	int pr = 1;
	for (int i = 0; i < size; i += 2)
	{
		pr *= arr[i];
	}
	return pr;
}
void zapol(int size, int* arr)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << "Enter element" << i << "=" << " ";
		std::cin >> arr[i];
	}
}
int main()
{
	try 
	{
		srand(time(NULL));
		int x = 0;
		int y = 0;
		int sum = 0;
		int first_zero = -1;
		int last_zero = -1;
		char a = '0';
		std::cout << "Random - 0; Personal choose - 1" << '\n';
		std::cin >> a;
		if (a != '0' && a != '1')
		{
			throw std::exception("Error");
		}
		int size = 0;
		std::cout << "Enter number of integer elements of the array:" << '\n';
		std::cin >> size;
		if (size <= 0)
		{
			throw std::exception("The quantity must be greater than 0");
		}
		int* arr = new int[size];
		switch (a)
		{
		case '0':
			std::cout << "X - minimal element; Y - maximum element" << '\n';
			std::cout << "X =" << " ";
			std::cin >> x;
			std::cout << "Y =" << " ";
			std::cin >> y;
			if (x > y)
			{
				std::cout << "Read carefully";
				exit(0);
			}
			random(size, arr, x, y);
			last_zero = find_last_zero(arr, size);
			first_zero = find_first_zero(arr, size);
			check_zeroes(last_zero, first_zero);
			sum = sum_between_zeroes(arr, first_zero, last_zero);
			otric(size, arr);
			std::cout << '\t';
			polog(size, arr);
			bublle(arr, size);
			vivod(size, arr);
			std::cout << " ";
			std::cout << "Composition = " << composition(size, arr);
			std::cout << '\n';
			std::cout << "Summa =" << " " << sum;
			break;
		case '1':
			zapol(size, arr);
			last_zero = find_last_zero(arr, size);
			first_zero = find_first_zero(arr, size);
			check_zeroes(last_zero, first_zero);
			sum = sum_between_zeroes(arr, first_zero, last_zero);
			otric(size, arr);
			std::cout << '\t';
			polog(size, arr);
			vivod(size, arr);
			std::cout << " ";
			std::cout << "Composition = " << composition(size, arr);
			std::cout << '\n';
			std::cout << "Summa =" << " " << sum;
			break;
		default:
			std::cout << "Error. I dont Know this number" << '\n';
			break;
		}
		delete[] arr;
	}
	catch (std::exception e)
	{
		std::cerr << "exception: " << e.what();
		exit(0);
	}
	return 0;
}
