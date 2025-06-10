#include <gtest/gtest.h>
#include "/home/artush/main/c++ project/homework/Matrix/src/matrix.h"

TEST(Matrix,Test1)
{
    matrix_memory a(2,3);
    a(0,0) = 5;
    EXPECT_EQ(a(0,0),5);

}