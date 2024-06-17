#include <gtest/gtest.h>
#include "../string/String.h" 


TEST(StringTest, GetDataTest) {
    String str("Hello");
    char* temp = nullptr;
    EXPECT_STREQ(str.getData(temp), "Hello");
}

TEST(StringTest, GetLengthTest) {
    String str("Hello");
    EXPECT_EQ(str.getSize(), 5);
}

TEST(StringTest, SetDataTest) {
    String str("Hello");
    str.setData("World");
    char* temp = nullptr;
    EXPECT_STREQ(str.getData(temp), "World");
    EXPECT_EQ(str.getSize(), 5);

    str.setData(nullptr);
    EXPECT_EQ(str.getSize(), 0);
    EXPECT_EQ(str.getData(temp), nullptr);
}

TEST(StringTest, ClearTest) {
    String str("Test");
    str.clear();
    EXPECT_EQ(str.capacity(), 0);
    EXPECT_TRUE(str.isEmpty());
}

TEST(StringTest, AppendTest) {
    String str("Hello");
    str.append(" World");
    EXPECT_EQ(str.capacity(), 11);
    EXPECT_STREQ(str.begin(), "Hello World");
}

TEST(StringTest, IsEmptyTest) {
    String str;
    EXPECT_TRUE(str.isEmpty());

    str.append("Test");
    EXPECT_FALSE(str.isEmpty());
}

TEST(StringTest, GetlineTest) {
    String str;
    std::istringstream input("Hello World");
    std::cin.rdbuf(input.rdbuf());
    str.getline();
    EXPECT_STREQ(str.begin(), "Hello World");
}

TEST(StringTest, CapacityTest) {
    String str("Test");
    EXPECT_EQ(str.capacity(), 4);
}

TEST(StringTest, BeginTest) {
    String str("Test");
    EXPECT_EQ(*str.begin(), 'T');
}

TEST(StringTest, EndTest) {
    String str("Test");
    EXPECT_EQ(*(str.end() - 1), 't');
}

TEST(StringTest, FrontTest) {
    String str("Test");
    EXPECT_EQ(str.front(), 'T');
}

TEST(StringTest, BackTest) {
    String str("Test");
    EXPECT_EQ(str.back(), 't');
}

TEST(StringTest, AssignmentOperatorTest) {
    String str1("Hello");
    String str2("World");
    str1 = str2;
    EXPECT_EQ(str1, str2);
}

TEST(StringTest, AdditionOperatorTest) {
    String str1("Hello");
    String str2(" World");
    String result = str1 + str2;
    EXPECT_EQ(result, "Hello World");
}

TEST(StringTest, SubtractionOperatorTest) {
    String str1("Hello World");
    String str2(" World");
    String result = str1 - str2;
    EXPECT_EQ(result, "Hello");
}

TEST(StringTest, AdditionAssignmentOperatorTest) {
    String str1("Hello");
    String str2(" World");
    str1 += str2;
    EXPECT_EQ(str1, "Hello World");
}

TEST(StringTest, SubtractionAssignmentOperatorTest) {
    String str1("Hello World");
    String str2(" World");
    str1 -= str2;
    EXPECT_EQ(str1, "Hello");
}

TEST(StringTest, ComparisonOperatorsTest) {
    String str1("abc");
    String str2("abc");
    String str3("def");

    EXPECT_EQ(str1, str2);
    EXPECT_NE(str1, str3);
    EXPECT_LT(str1, str3);
    EXPECT_GT(str3, str1);
    EXPECT_LE(str1, str2);
    EXPECT_GE(str3, str1);
}

TEST(StringTest, ConversionOperatorsTest) {
    String str("123");
    std::string stdStr = static_cast<std::string>(str);
    EXPECT_EQ(stdStr, "123");

    int32_t intValue = static_cast<int32_t>(str);
    EXPECT_EQ(intValue, 123);

    double doubleValue = static_cast<double>(str);
    EXPECT_DOUBLE_EQ(doubleValue, 123.0);
}

TEST(StringTest, OutputStreamOperatorTest) {
    String str("Hello World");
    std::stringstream ss;
    ss << str;
    EXPECT_EQ(ss.str(), "Hello World");
}

TEST(StringTest, InputStreamOperatorTest) {
    String str;
    std::stringstream ss("Hello World");
    ss >> str;
    EXPECT_EQ(str, "Hello");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}