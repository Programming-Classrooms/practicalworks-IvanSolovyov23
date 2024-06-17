#include <gtest/gtest.h>
#include "../Person/Person.h"
#include "../Student/Student.h"
#include "../Professor/Professor.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(StudentTest, GetterTest) {
    Student obj;
    obj.setCourse(1); 

    EXPECT_EQ(obj.getCourse(), 1); 
}


TEST(StudentTest, SetterTest) {
    Student obj;
    obj.setCourse(5); 

    EXPECT_EQ(obj.getCourse(), 5); 
}

TEST(StudentTest, GetterTest1) {
    Student obj;
    obj.setGroup(7121); 

    EXPECT_EQ(obj.getGroup(), 7121); 
}

TEST(StudentTest, SetterTest1) {
    Student obj;
    obj.setGroup(5); 

    EXPECT_EQ(obj.getGroup(), 5); 
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
