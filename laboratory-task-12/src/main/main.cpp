#include "../class/String.h"


int main() 
{
	try {
		// Проверка конструктора
		String str1("Kriptographia");
		std::cout << "Main string: " << str1 << std::endl;

		String str2 = str1;
		std::cout << "Copy main string: " << str2 << std::endl;

		// Проверка Геттеров и Сеттеров
		std::cout << "Length of main string: " << str2.getSize() << std::endl; 
		std::cout << "Data of main string: " << str2.getData() << std::endl; 

		str1.setData("KrEptographia"); 
		std::cout << "Main string after setting data: " << str1 << std::endl;

        // Проверка алгебраических операторов
		String str3(" MatImatica");
		String str4 = str1 + str3; 
		std::cout << "String after concatenation: " << str4 << std::endl; 

		String str5 = str1 - str3;
		std::cout << "String after substraction: " << str5 << std::endl;

		str3 += " and Coding on C++"; 
		std::cout << "String after addition: " << str3 << std::endl; 
        
		// Проверка операторов сравнения
		String str6("VF");
		String str7("ANB");
		std::cout << "Is ANB equal to VF? " << std::boolalpha << (str6 == str7) << std::endl;
		std::cout << "Is ANB not equal to VF? " << std::boolalpha << (str6 != str7) << std::endl;
		std::cout << "Is ANB less than VF? " << std::boolalpha << (str6 < str7) << std::endl;
		std::cout << "Is ANB less than or equal to VF? " << std::boolalpha << (str6 <= str7) << std::endl;
		std::cout << "Is ANB greater than VF? " << std::boolalpha << (str6 > str7) << std::endl;
		std::cout << "Is ANB greater than or equal to VF? " << std::boolalpha << (str6 >= str7) << std::endl;

	}
	catch (const std::logic_error& re) {
		std::cerr << "Logic error exception caught: " << re.what() << '\n';
	}
	return 0;
}
