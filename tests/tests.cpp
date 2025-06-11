#include <gtest/gtest.h>
#include "/home/artush/main/c++ project/homework/Matrix/src/matrix.h"

TEST(matrix,Test1)
{
    matrix a(2,3);
    a(0,0) = 5;
    EXPECT_EQ(a(0,0),5);

}
TEST(matrix, add)
{
    matrix a (2,2);
    matrix b (2,2);
    a(0,0) = 5; a(0,1) = 4; a(1,0) = 3; a(1,1) = 2;
    b(0,0) = 10; b(0,1) = 9; b(1,0) = 8; b(1,1) = 7;
    EXPECT_EQ((a+b)(0,0), 10);
    EXPECT_EQ((a+b)(0,1), 13);
    EXPECT_EQ((a+b)(1,0), 11);
    EXPECT_EQ((a+b)(1,1), 10);
}