#include <gtest/gtest.h>
#include "../TreeContainer/TreeContainer.h"
#include "../ForestTree/ForestTree.h"
#include "../FruitTree/FruitTree.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}