#include "Matrix.h"
#include <iomanip>
#include <ctime>


/* =========================================================================== */
/* ============================== Конструкторы =============================== */
/* =========================================================================== */

Matrix::Matrix() : rows(2), columns(2), data(nullptr) {}

Matrix::Matrix(size_t initrows, size_t initcols) : rows(initrows), columns(initcols) {
    if (this->rows == 0 || this->columns == 0) {
        throw std::invalid_argument("Size does matter");
    }
    data = new int32_t* [rows];
    for (size_t i = 0; i < rows; ++i) {
        data[i] = new int32_t[columns];
    }
}

Matrix::Matrix(const Matrix& rhs) : rows(rhs.rows), columns(rhs.columns) {
    data = new int32_t* [rows];
    for (size_t i = 0; i < rows; ++i) {
        data[i] = new int32_t[columns];
        for (size_t j = 0; j < columns; ++j) {
            data[i][j] = rhs.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (size_t i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}




/* =========================================================================== */
/* ============================== Геттеры ==================================== */
/* =========================================================================== */

size_t Matrix::getRows() const {
    return this->rows;
}

size_t Matrix::getColumns() const {
    return this->columns;
}

const int32_t& Matrix::getElement(size_t initrows, size_t initcolumns) const {
    if (initrows >= rows || initcolumns >= columns) {
        throw std::out_of_range("Index out of range!");
    }
    return data[initrows][initcolumns];
}




/* =========================================================================== */
/* ============================== Сеттеры ==================================== */
/* =========================================================================== */

void Matrix::setElement(size_t initrows, size_t initcolumns, int32_t value) {
    if (initrows >= rows || initcolumns >= columns) {
        throw std::out_of_range("Index out of range!");
    }
    data[initrows][initcolumns] = value;
}




/* =========================================================================== */
/* ==================== Перегрузка операторов присваивания =================== */
/* =========================================================================== */

Matrix& Matrix::operator=(const Matrix& rhs) {
    if (this != &rhs) {
        clone(rhs);
    }
    return *this;
}




/* =========================================================================== */
/* ========================= Методы для матрицы ============================== */
/* =========================================================================== */

void Matrix::fillRandom(int32_t min, int32_t max) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            data[i][j] = min + rand() % (max - min + 1);
        }
    }
}

void Matrix::print() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            std::cout << data[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

void Matrix::clear()
{
    for (size_t i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;    
}

void Matrix::clone(const Matrix& rhs)
{
    clear();

    rows = rhs.rows;
    columns = rhs.columns;
    data = new int32_t* [rows];
    for (size_t i = 0; i < rows; ++i) {
        data[i] = new int32_t[columns];
        for (size_t j = 0; j < columns; ++j) {
            data[i][j] = rhs.data[i][j];
        }
    }
}

/* =========================================================================== */
/* ============== Перегрузка бинарных алгебраических операторов ============== */
/* =========================================================================== */

 /*=========================(Матрица (?) скаляр)=================================*/ 

Matrix Matrix::operator+(const Matrix& rhs) {
    Matrix result(rows, columns);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            result.data[i][j] = data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator+(const int32_t& scalar) const {
    Matrix result(rows, columns);
    for (size_t i = 0; i < rows;  ++i) {
        for (size_t j = 0; j < columns; ++j) {
            result.data[i][j] = data[i][j] + scalar;
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& rhs) {
    Matrix result(rows, columns);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            result.data[i][j] = data[i][j] - rhs.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const int32_t& scalar) const {
    Matrix result(rows, columns);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            result.data[i][j] = data[i][j] - scalar;
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& rhs) {
    if (columns != rhs.rows) {
        throw std::logic_error("Size does matter");
        return Matrix(0, 0);
    }

    Matrix result(rows, rhs.columns);

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < rhs.columns; ++j) {
            double sum = 0.0;
            for (size_t k = 0; k < columns; ++k) {
                sum += data[i][k] * rhs.data[k][j];
            }
            static_cast<double>(result.data[i][j]);
            result.data[i][j] = sum;
        }
    }

    return result;
}


Matrix Matrix::operator*(const int32_t& scalar) const 
{
    Matrix result(rows, columns);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator/(const int32_t& scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero");
    }
    Matrix result(rows, columns);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            result.data[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}

/*=========================(скаляр ? матрица=================================*/

Matrix operator*(int32_t scalar, const Matrix& rhs) {
    return rhs * scalar;
}




/* =========================================================================== */
/* ===================== Перегрузка операторов сравнения ===================== */
/* =========================================================================== */

bool Matrix::operator==(const Matrix& rhs) const {
    if (rows != rhs.rows || columns != rhs.columns) {
        return false;
    }
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            if (data[i][j] != rhs.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}




/* =========================================================================== */
/* ============ Перегрузка составных операторов присваивания ================= */
/* =========================================================================== */

Matrix& Matrix::operator+=(const Matrix& other) {
    if (rows != other.rows || columns != other.columns) {
        throw std::invalid_argument("Size does matter");
    }
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs) {
    if (rows != rhs.rows || columns != rhs.columns) {
        throw std::invalid_argument("Size does matter");
    }
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            data[i][j] -= rhs.data[i][j];
        }
    }
    return *this;
}




/* =========================================================================== */
/* ================ Перегрузка операторов вывода / ввода ===================== */
/* =========================================================================== */

std::ostream& operator<<(std::ostream& out, const Matrix& rhs) {
    size_t numRows = rhs.getRows();
    size_t numCols = rhs.getColumns();

    for (size_t i = 0; i < numRows; ++i) {
        for (size_t j = 0; j < numCols; ++j) {
            out << rhs.data[i][j] << '\t';
        }
        out << std::endl;
    }

    return out;
}

std::istream& operator>>(std::istream& is, Matrix& rhs) {
    size_t numRows = rhs.getRows();
    size_t numCols = rhs.getColumns();

    for (size_t i = 0; i < numRows; ++i) {
        for (size_t j = 0; j < numCols; ++j) {
            is >> rhs.data[i][j];
        }
    }
    return is;
}
