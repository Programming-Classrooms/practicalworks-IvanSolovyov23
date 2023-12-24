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
void bubbleSort(int arr[], int size)
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
void fillRandomArray(int size, int* arr, int x, int y)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = x + rand() % (y - x + 1);
	}
}
void findNegativeElements(int size, int arr[])
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			std::cout << arr[i] << '\t';
		}
		
	}
}

int findFirstZero(int* arr, int size)
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

int findLastZero(int* arr, int size)
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

void checkZeroes(int last_zero, int first_zero)
{
	if (last_zero == -1)
	{
		throw std::exception("Not found 0");
	}
	if (last_zero == first_zero)
	{
		throw std::exception("Not enough 0");
	}
}

int sumBetweenZeroes(int* arr, int first_zero, int last_zero)
{
	int sum = 0;
	for (size_t i = first_zero; i <= last_zero; ++i)
	{
		
		sum += arr[i];
	}
	return sum;
}

void findPositiveElements(int size, int arr[])
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > 0);
		{
			std::cout << arr[i] << '\t';
		}
	}
}
void printArray(int size, int* arr)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << "|" << arr[i] << "|" << '\t';
	}
}
int compositionElements( int size, int* arr)
{
	int pr = 1;
	for (int i = 0; i < size; i += 2)
	{
		pr *= arr[i];
	}
	return pr;
}
void fillArray(int size, int* arr)
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
		int min = 0;
		int max = 0;
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
			std::cout << "X- bottom limit; Y - upper limit" << '\n';
			std::cout << "X =" << " ";
			std::cin >> min;
			std::cout << "Y =" << " ";
			std::cin >> max;
			if (min > max)
			{
				std::cout << "Read carefully";
				exit(0);
			}
			fillRandomArray(size, arr, min, max);
			last_zero = findLastZero(arr, size);
			first_zero = findFirstZero(arr, size);
			checkZeroes(last_zero, first_zero);
			sum = sumBetweenZeroes(arr, first_zero, last_zero);
			findNegativeElements(size, arr);
			std::cout << '\t';
			findPositiveElements(size, arr);
			bubbleSort(arr, size);
			printArray(size, arr);
			std::cout << " ";
			std::cout << "Composition = " << compositionElements(size, arr);
			std::cout << '\n';
			std::cout << "Summa =" << " " << sum;
			break;
		case '1':
			fillArray(size, arr);
			last_zero = findLastZero(arr, size);
			first_zero = findFirstZero(arr, size);
			checkZeroes(last_zero, first_zero);
			sum = sumBetweenZeroes(arr, first_zero, last_zero);
			findNegativeElements(size, arr);
			std::cout << '\t';
			findPositiveElements(size, arr);
			printArray(size, arr);
			std::cout << " ";
			std::cout << "Composition = " << compositionElements(size, arr);
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
