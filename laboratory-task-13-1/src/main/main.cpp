#include "../Fraction/Fraction.hpp"


int main() {
	try {
        Fraction fraction1(3, 4);
	Fraction fraction2(1, 2);

        std::cout << "Fraction 1: ";
        fraction1.print();
        std::cout << std::endl;

        std::cout << "Fraction 2: ";
        fraction2.print();
        std::cout << std::endl;

        std::cout << "Fraction 1 + Fraction 2: ";
        (fraction1 + fraction2).print();
        std::cout << std::endl;

        std::cout << "Fraction 1 - Fraction 2: ";
        (fraction1 - fraction2).print();
        std::cout << std::endl;

        std::cout << "Fraction 1 * Fraction 2: ";
        (fraction1 * fraction2).print();
        std::cout << std::endl;

        std::cout << "Fraction 1 / Fraction 2: ";
        (fraction1 / fraction2).print();
        std::cout << std::endl;

        
        std::cout << "Numerator of Fraction 1: " << fraction1.getNumerator() << std::endl;
        std::cout << "Denominator of Fraction 1: " << fraction1.getDenominator() << std::endl;

        
        fraction1.setNumerator(5);
        fraction1.setDenominator(3);
        std::cout << "Modified Fraction 1: ";
        fraction1.print();
        std::cout << std::endl;

        int32_t number = 3;

        Fraction result_addition_number_fraction = number + fraction1;
        std::cout << "Number + Fraction: ";
        result_addition_number_fraction.print();
        std::cout << std::endl;

        
        Fraction result_subtraction_number_fraction = number - fraction1;
        std::cout << "Number - Fraction: ";
        result_subtraction_number_fraction.print();
        std::cout << std::endl;

        
        Fraction result_multiplication_number_fraction = number * fraction1;
        std::cout << "Number * Fraction: ";
        result_multiplication_number_fraction.print();
        std::cout << std::endl;

        
        Fraction result_division_number_fraction = number / fraction1;
        std::cout << "Number / Fraction: ";
        result_division_number_fraction.print();
        std::cout << std::endl;

        
        Fraction result_addition_fraction_number = fraction1 + number;
        std::cout << "Fraction + Number: ";
        result_addition_fraction_number.print();
        std::cout << std::endl;

        
        Fraction result_subtraction_fraction_number = fraction1 - number;
        std::cout << "Fraction - Number: ";
        result_subtraction_fraction_number.print();
        std::cout << std::endl;

        
        Fraction result_multiplication_fraction_number = fraction1 * number;
        std::cout << "Fraction * Number: ";
        result_multiplication_fraction_number.print();
        std::cout << std::endl;

        
        Fraction result_division_fraction_number = fraction1 / number;
        std::cout << "Fraction / Number: ";
        result_division_fraction_number.print();
        std::cout << std::endl;


        std::cout << "Is Fraction 1 equal to Fraction 2? " << std::boolalpha << (fraction1 == fraction2) << std::endl;
        std::cout << "Is Fraction 1 not equal to Fraction 2? " << std::boolalpha << (fraction1 != fraction2) << std::endl;
        std::cout << "Is Fraction 1 less than Fraction 2? " << std::boolalpha << (fraction1 < fraction2) << std::endl;
        std::cout << "Is Fraction 1 less than or equal to Fraction 2? " << std::boolalpha << (fraction1 <= fraction2) << std::endl;
        std::cout << "Is Fraction 1 greater than Fraction 2? " << std::boolalpha << (fraction1 > fraction2) << std::endl;
        std::cout << "Is Fraction 1 greater than or equal to Fraction 2? " << std::boolalpha << (fraction1 >= fraction2) << std::endl;

        
        double decimalValue = static_cast<double>(fraction1);
        std::cout << "Fraction 1 as a double: " << decimalValue << std::endl;

        
        int32_t intValue = static_cast<int32_t>(fraction1);
        std::cout << "Fraction 1 as int32_t: " << intValue << std::endl;

	}
	catch (const std::invalid_argument& re) {
		std::cerr << "Invalid argument exception caught: " << re.what() << std::endl;
	}
	catch (const std::logic_error& re) {
        std::cerr << "Logic error exception caught: " << re.what() << std::endl;
	}
	return 0;
}
