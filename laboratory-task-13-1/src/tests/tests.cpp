
#include <stdexcept>
#include <gtest/gtest.h>
#include "../funcs/Fraction.hpp"


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

// Òåñò äëÿ îïåðàòîðà ïðèñâàèâàíèÿ
TEST(FractionTest, AssignmentOperatorTest) {
    Fraction frac1(3, 4);
    Fraction frac2;
    frac2 = frac1;
    EXPECT_EQ(frac1, frac2);
}

// Òåñò äëÿ îïåðàòîðà ñëîæåíèÿ
TEST(FractionTest, AdditionOperatorTest) {
    Fraction frac1(1, 2);
    Fraction frac2(1, 3);
    Fraction result = frac1 + frac2;
    EXPECT_EQ(result, Fraction(5, 6));
}

// Òåñò äëÿ îïåðàòîðà âû÷èòàíèÿ
TEST(FractionTest, SubtractionOperatorTest) {
    Fraction frac1(3, 4);
    Fraction frac2(1, 2);
    Fraction result = frac1 - frac2;
    EXPECT_EQ(result, Fraction(1, 4));
}

// Òåñò äëÿ îïåðàòîðà óìíîæåíèÿ
TEST(FractionTest, MultiplicationOperatorTest) {
    Fraction frac1(3, 4);
    Fraction frac2(1, 2);
    Fraction result = frac1 * frac2;
    EXPECT_EQ(result, Fraction(3, 8));
}

// Òåñò äëÿ îïåðàòîðà äåëåíèÿ
TEST(FractionTest, DivisionOperatorTest) {
    Fraction frac1(3, 4);
    Fraction frac2(1, 2);
    Fraction result = frac1 / frac2;
    EXPECT_EQ(result, Fraction(3, 2));
}

// Òåñò äëÿ êîíñòðóêòîðà ñ ïàðàìåòðàìè
TEST(FractionTest, ConstructorTest) {
    Fraction frac(3, 4);
    EXPECT_EQ(frac.getNumerator(), 3);
    EXPECT_EQ(frac.getDenominator(), 4);
}

// Òåñò äëÿ ìåòîäîâ getNumerator è getDenominator
TEST(FractionTest, GetNumeratorAndDenominatorTest) {
    Fraction frac(3, 4);
    EXPECT_EQ(frac.getNumerator(), 3);
    EXPECT_EQ(frac.getDenominator(), 4);
}

// Òåñò äëÿ ìåòîäà setNumerator
TEST(FractionTest, SetNumeratorTest) {
    Fraction frac;
    frac.setNumerator(5);
    EXPECT_EQ(frac.getNumerator(), 5);
}

// Òåñò äëÿ îïåðàòîðà ñëîæåíèÿ ñ äðóãîé äðîáüþ
TEST(FractionTest, AdditionOperatorWithFractionTest) {
    Fraction frac1(1, 2);
    Fraction frac2(1, 3);
    Fraction result = frac1 + frac2;
    EXPECT_EQ(result, Fraction(5, 6));
}

// Òåñò äëÿ îïåðàòîðà âû÷èòàíèÿ ñ äðóãîé äðîáüþ
TEST(FractionTest, SubtractionOperatorWithFractionTest) {
    Fraction frac1(3, 4);
    Fraction frac2(1, 2);
    Fraction result = frac1 - frac2;
    EXPECT_EQ(result, Fraction(1, 4));
}

// Òåñò äëÿ îïåðàòîðà óìíîæåíèÿ ñ äðóãîé äðîáüþ
TEST(FractionTest, MultiplicationOperatorWithFractionTest) {
    Fraction frac1(3, 4);
    Fraction frac2(1, 2);
    Fraction result = frac1 * frac2;
    EXPECT_EQ(result, Fraction(3, 8));
}

// Òåñò äëÿ îïåðàòîðà äåëåíèÿ ñ äðóãîé äðîáüþ
TEST(FractionTest, DivisionOperatorWithFractionTest) {
    Fraction frac1(3, 4);
    Fraction frac2(1, 2);
    Fraction result = frac1 / frac2;
    EXPECT_EQ(result, Fraction(3, 2));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
