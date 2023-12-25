#include <iostream>


// Функция для создания и заполнения массива случайными числами
void generateRandomArray(int* arr, size_t size, int8_t min, int8_t max) 
{
    for (size_t i = 0; i < size; ++i) { 
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void fillArray(int* arr, size_t size, int8_t min, int8_t max)
{ 
    for (size_t i = 0; i < size; ++i) { 
        std::cout << "Element: ";
        std::cin >> arr[i];
        std::cout << '\n';
    }
}

// Функция для создания матрицы Коши на основе двух массивов
void createCauchyMatrix(int* X, int* Y, double** cauchyMatrix, uint32_t P, uint32_t Q) 
{ 
    for (size_t i = 0; i < P; ++i) {
        for (size_t j = 0; j < Q; ++j) {
            cauchyMatrix[i][j] = 1.0 / (X[i] + Y[j]);
        }
    }
}

// Функция для вычисления суммы элементов в каждом столбце матрицы              
void calculateColumnSums(double** cauchyMatrix, double* columnSums, uint32_t P, uint32_t Q, double finalSum) 
{ 
    for (int j = 0; j < Q; j++) { 
        finalSum = 0;
        for (int i = 0; i < P; i++) { 
            finalSum += cauchyMatrix[i][j];
        
        std::cout << "Column #" << j + 1 << ": " << finalSum << '\n';
        }
    }
}

void mtrxDefine(double**& matrix, size_t rows, size_t colums)
{
    matrix = new double* [rows];
    for(size_t i = 0; i < rows; ++i) {
        matrix[i] = new double [colums];
    }
}

void freeMemory(int*arr)
{
    delete[] arr;
}

void freeMemory(double* arr)
{
    delete[] arr;
}


void freeCauchyMtrx(uint32_t P, double**& cauchyMatrix)
{
    for (size_t i = 0; i < P; ++i) {
        delete[] cauchyMatrix[i];
    }
    delete[] cauchyMatrix;
}

int main() 
{ 
    // Ввод размеров массивов X(P) и Y(Q) с клавиатуры
    uint32_t P = 0;
    uint32_t Q = 0;
    std::cout << "Enter array size X(P): ";
    std::cin >> P;
    std::cout << "Enter array size Y(Q): ";
    std::cin >> Q;
    std::cout << "How do I fill an array? 0 - Random; 1- Personal choose" << '\n';
    char choose = '0';
    // Создание массивов X(P) и Y(Q) и заполнение их случайными числами
    double** cauchyMatrix  = nullptr;
    int* X = new int[P];
    int* Y = new int[Q];
    // Создание матрицы Коши на основе X(P) и Y(Q)
    mtrxDefine(cauchyMatrix, P, Q);
    double* columnSums = new double[Q];
    std::cin >> choose;
    double finalSum = 0;
    if (choose == '0') { 
        generateRandomArray(X, P, 1, 10);
        generateRandomArray(Y, Q, 1, 10);
        createCauchyMatrix(X, Y, cauchyMatrix, P, Q);
        // Вывод матрицы Коши
        std::cout << "Cauchy matrix:" << '\n';
        for (size_t i = 0; i < P; ++i) {
            for (size_t j = 0; j < Q; ++j) {
                std::cout << cauchyMatrix[i][j] << "\t";
            }
            std::cout << '\n';
        }
        calculateColumnSums(cauchyMatrix, columnSums, P, Q, finalSum);
    }
    if (choose == '1') { 
        fillArray(X, P, 1, 10);
        std::cout << "Second array" << '\n';
        fillArray(Y, Q, 1, 10);
        createCauchyMatrix(X, Y, cauchyMatrix, P, Q);
        // Вывод матрицы Коши
        std::cout << "Cauchy matrix:" << '\n';
        for (size_t i = 0; i < P; ++i) {
            for (size_t j = 0; j < Q; ++j) {
                std::cout << cauchyMatrix[i][j] << "\t";
            }
            std::cout << '\n';
        }
        calculateColumnSums(cauchyMatrix, columnSums, P, Q, finalSum);
    }
    else 
    {
        std::cout << "Read more attantive!";
        return 0;
    }
    freeMemory(X);
    freeMemory(Y);
    freeMemory(columnSums);
    freeCauchyMtrx(P, cauchyMatrix);
    return 0;
}
