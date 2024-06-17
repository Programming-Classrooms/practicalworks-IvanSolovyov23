/*
    Написать программу, которая для заданного натурального числа N находит дружественное, не превышающие это число:
*/


#include <iostream>


int32_t inputNumber() 
{
    int32_t num;    
    std::cout << "Input in:";
	std::cin >> num;
    if (num <= 0) 
    {
    	throw std::exception("Number isn't natural.");    
    }
    return num;    
}

int main()
{
	try
	{
		int32_t num = 0;
		size_t temp1 = 0;
    	size_t temp2 = 0;

    	num = inputNumber();

		for (size_t i = 2; i <= num; ++i) 
    	{
			temp1 = i;
			size_t sum1 = 1;
			size_t sum2 = 1;

			for (size_t j = 2; j < temp1; ++j) 
        	{
				if (!(temp1 % j)) 
            	{
					sum1 += j;
				}
			}
			temp2 = sum1;

			for (size_t k = 2; k < temp2; ++k) 
        	{
				if (!(temp2 % k)) 
            	{
			    	sum2 += k;
		    	}
	    	}

    		if (sum2 == temp1 && temp1 < temp2) 
        	{
    			std::cout << temp1 << " " << "and" << " " << temp2 << std::endl;
    		}
    	}
	}
	catch (std::exception e)
	{
		std::cerr << "Oops! Exception: " << e.what() << std::endl;
	}
return 0;
}
