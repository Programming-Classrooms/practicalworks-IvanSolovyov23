#include "../funcs/Matrix.h"


int main() {
    try {
        // �������� ������� 3x3 � ���������� ���������� ����������
        Matrix matrix1(3, 3);
        matrix1.fillRandom(1, 10);

        std::cout << "Matrix 1:" << std::endl;
        matrix1.print();
        std::cout << std::endl;

        // �������� ������� 3x3 � ���������� ���������� ����������
        Matrix matrix2(3, 3);
        matrix2.fillRandom(1, 10);

        std::cout << "Matrix 2:" << std::endl;
        matrix2.print();
        std::cout << std::endl;

        // �������� ���� ������
        Matrix sum = matrix1 + matrix2;
        std::cout << "Sum of matrices:" << std::endl;
        sum.print();
        std::cout << std::endl;

        // ������� ���� �����
        Matrix sumWithElements = matrix1 + 2;
        std::cout << "Matrix plus scalar" << std::endl;
        sumWithElements.print();
        std::cout << std::endl;

        // ��������� ���� ������
        Matrix product = matrix1 * matrix2;
        std::cout << "Multiplication of matrices:" << std::endl;
        product.print();
        std::cout << std::endl;

        // ������� �������� �� �����
        Matrix productWithElements = matrix1 * 2;
        std::cout << "Matrix multiply scalar" << std::endl;
        productWithElements.print();
        std::cout << std::endl;

        // ��������� �������� �� �������
        Matrix scaled1 = 2 * matrix1;
        std::cout << "2 multiply by the Matrix" << std::endl;
        scaled1.print();
        std::cout << std::endl;

        // ��������� �� ����� ������� ������ 
        Matrix difference = matrix1 - matrix2;
        std::cout << "The difference between two matrice: " << std::endl;
        difference.print();
        std::cout << std::endl;

        // ��������� �� ������� ������� 
        Matrix differenceWithElements = matrix1 - 2;
        std::cout << "Matrix subtraction scalar" << std::endl;
        differenceWithElements.print();
        std::cout << std::endl;

        // ������� ������� �� ������ 
        Matrix divisionWithElements = matrix1 / 2;
        std::cout << "Matrix division scalar" << std::endl;
        divisionWithElements.print();
        std::cout << std::endl;

        //������������ ������������
        double det = matrix1.determinantBySarrusMethod();
        std::cout << "Determinant: " << det << std::endl;

        // ���������������� �������� ������������
        Matrix mat_copy = matrix1;

        // ����� ������������� ������� �� �����
        std::cout << "Copied matrix:" << std::endl;
        std::cout << mat_copy << std::endl;

        // �������� �������� � �������� 
        std::cout << "Element at (1, 1): " << mat_copy.getElement(1, 1) << std::endl;
        mat_copy.setElements(1, 1, 10);
        std::cout << "Modified element at (1, 1): " << mat_copy.getElement(1, 1) << std::endl;

        // �������� ���������
        std::cout << "Is Matrix 1 equal to Matrix 2? " << std::boolalpha << (matrix1 == matrix2) << std::endl;
        std::cout << "Is Fraction 1 not equal to Fraction 2? " << std::boolalpha << (matrix1 != matrix2) << std::endl;
    }
    catch (const std::logic_error& re) {
        std::cerr << "Logic error exception caught: " << re.what() << '\n';
    }
    catch (const std::invalid_argument& re) {
        std::cerr << "Invalid argument exception caught: " << re.what() << '\n';
    }
    catch (const std::out_of_range& re) {
        std::cerr << "Out of range error exception caught: " << re.what() << '\n';
    }
    return 0;
}
