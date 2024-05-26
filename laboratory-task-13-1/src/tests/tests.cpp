
#include <stdexcept>
#include <gtest/gtest.h>
#include "../Fraction/Fraction.hpp"


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(FractionTest, AssignmentOperatorTest) {
    Fraction frac1(3, 4);
    Fraction frac2;
    frac2 = frac1;
    EXPECT_EQ(frac1, frac2);
}

TEST(FractionTest, AdditionOperatorTest) {
    Fraction frac1(1, 2);
    Fraction frac2(1, 3);
    Fraction result = frac1 + frac2;
    EXPECT_EQ(result, Fraction(5, 6));
}

TEST(FractionTest, SubtractionOperatorTest) {
    Fraction frac1(3, 4);
    Fraction frac2(1, 2);
    Fraction result = frac1 - frac2;
    EXPECT_EQ(result, Fraction(1, 4));
}

TEST(FractionTest, MultiplicationOperatorTest) {
    Fraction frac1(3, 4);
    Fraction frac2(1, 2);
    Fraction result = frac1 * frac2;
    EXPECT_EQ(result, Fraction(3, 8));
}

TEST(FractionTest, DivisionOperatorTest) {
    Fraction frac1(3, 4);
    Fraction frac2(1, 2);
    Fraction result = frac1 / frac2;
    EXPECT_EQ(result, Fraction(3, 2));
}

TEST(FractionTest, ConstructorTest) {
    Fraction frac(3, 4);
    EXPECT_EQ(frac.getNumerator(), 3);
    EXPECT_EQ(frac.getDenominator(), 4);
}

TEST(FractionTest, GetNumeratorAndDenominatorTest) {
    Fraction frac(3, 4);
    EXPECT_EQ(frac.getNumerator(), 3);
    EXPECT_EQ(frac.getDenominator(), 4);
}

TEST(FractionTest, SetNumeratorTest) {
    Fraction frac;
    frac.setNumerator(5);
    EXPECT_EQ(frac.getNumerator(), 5);
}

TEST(FractionTest, AdditionOperatorWithFractionTest) {
    Fraction frac1(1, 2);
    Fraction frac2(1, 3);
    Fraction result = frac1 + frac2;
    EXPECT_EQ(result, Fraction(5, 6));
}

TEST(FractionTest, SubtractionOperatorWithFractionTest) {
    Fraction frac1(3, 4);
    Fraction frac2(1, 2);
    Fraction result = frac1 - frac2;
    EXPECT_EQ(result, Fraction(1, 4));
}

TEST(FractionTest, MultiplicationOperatorWithFractionTest) {
    Fraction frac1(3, 4);
    Fraction frac2(1, 2);
    Fraction result = frac1 * frac2;
    EXPECT_EQ(result, Fraction(3, 8));
}

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
