#include <gtest/gtest.h>
#include "../funcs/Matrix.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
// ���� ��� ������� getRows � getColumns
TEST(MatrixTest, GetRowsAndColumnsTest) {
    Matrix mat(3, 4);
    EXPECT_EQ(mat.getRows(), 3);
    EXPECT_EQ(mat.getColumns(), 4);
}

// ���� ��� ������ getElement
TEST(MatrixTest, GetElementTest) {
    Matrix mat(2, 2);
    mat.setElements(0, 0, 1);
    mat.setElements(0, 1, 2);
    mat.setElements(1, 0, 3);
    mat.setElements(1, 1, 4);

    EXPECT_EQ(mat.getElement(0, 0), 1);
    EXPECT_EQ(mat.getElement(0, 1), 2);
    EXPECT_EQ(mat.getElement(1, 0), 3);
    EXPECT_EQ(mat.getElement(1, 1), 4);
}

// ���� ��� ������ setElements
TEST(MatrixTest, SetElementTest) {
    Matrix mat(2, 2);
    mat.setElements(0, 0, 1);
    mat.setElements(0, 1, 2);
    mat.setElements(1, 0, 3);
    mat.setElements(1, 1, 4);

    EXPECT_EQ(mat.getElement(0, 0), 1);
    EXPECT_EQ(mat.getElement(0, 1), 2);
    EXPECT_EQ(mat.getElement(1, 0), 3);
    EXPECT_EQ(mat.getElement(1, 1), 4);
}


// ���� ��� ��������� ��������
TEST(MatrixTest, AdditionOperatorTest) {
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);
    mat1.fillRandom(1, 10);
    mat2.fillRandom(1, 10);

    Matrix result = mat1 + mat2;
    for (size_t i = 0; i < result.getRows(); ++i) {
        for (size_t j = 0; j < result.getColumns(); ++j) {
            EXPECT_EQ(result.getElement(i, j), mat1.getElement(i, j) + mat2.getElement(i, j));
        }
    }
}

// ���� ��� ��������� ���������
TEST(MatrixTest, SubtractionOperatorTest) {
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);
    mat1.fillRandom(1, 10);
    mat2.fillRandom(1, 10);

    Matrix result = mat1 - mat2;
    for (size_t i = 0; i < result.getRows(); ++i) {
        for (size_t j = 0; j < result.getColumns(); ++j) {
            EXPECT_EQ(result.getElement(i, j), mat1.getElement(i, j) - mat2.getElement(i, j));
        }
    }
}

// ���� ��� ��������� ��������� �� ������
TEST(MatrixTest, MultiplicationByScalarOperatorTest) {
    Matrix mat(2, 2);
    mat.fillRandom(1, 10);
    int32_t scalar = 2;

    Matrix result = mat * scalar;
    for (size_t i = 0; i < result.getRows(); ++i) {
        for (size_t j = 0; j < result.getColumns(); ++j) {
            EXPECT_EQ(result.getElement(i, j), mat.getElement(i, j) * scalar);
        }
    }
}

// ���� ��� ��������� ������� �� ������
TEST(MatrixTest, DivisionByScalarOperatorTest) {
    Matrix mat(2, 2);
    mat.fillRandom(2, 10);
    int32_t scalar = 2;

    Matrix result = mat / scalar;
    for (size_t i = 0; i < result.getRows(); ++i) {
        for (size_t j = 0; j < result.getColumns(); ++j) {
            EXPECT_EQ(result.getElement(i, j), mat.getElement(i, j) / scalar);
        }
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}