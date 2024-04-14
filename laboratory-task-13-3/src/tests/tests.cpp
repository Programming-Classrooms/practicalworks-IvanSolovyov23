#include <gtest/gtest.h>
#include "../funcs/List.h"

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(LinkedListTest, DefaultConstructor) {
    LinkedList<int> list;
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEmpty());
}

TEST(LinkedListTest, Prepend) {
    LinkedList<int> list;
    list.prepend(1);
    list.prepend(2);
    list.prepend(3);
    EXPECT_EQ(list.getSize(), 3);
    std::vector<int> expected = { 3, 2, 1 };
    std::vector<int> result;
    list.forEach([&result](const int& data) {
        result.push_back(data);
        });
    EXPECT_EQ(result, expected);
}


TEST(LinkedListTest, Append) {
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    EXPECT_EQ(list.getSize(), 3);
    std::vector<int> expected = { 1, 2, 3 };
    std::vector<int> result;
    list.forEach([&result](const int& data) {
        result.push_back(data);
        });
    EXPECT_EQ(result, expected);
}

TEST(LinkedListTest, Remove) {
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.remove(2);
    EXPECT_EQ(list.getSize(), 2);
    std::vector<int> expected = { 1, 3 };
    std::vector<int> result;
    list.forEach([&result](const int& data) {
        result.push_back(data);
        });
    EXPECT_EQ(result, expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
