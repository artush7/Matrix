#include <gtest/gtest.h>
#include "matrix.h"
#include <iostream>
#include <stdexcept>

TEST(matrix,Test)
{
    matrix<int> a(2,3);
    a(0,0) = 5;
    EXPECT_EQ(a(0,0),5);

}
TEST(matrix, Test2x2)
{
    matrix<int> a(2, 2);
    a(0, 0) = 7;
    a(0, 1) = 3;
    a(1, 0) = 1;
    a(1, 1) = 9;

    EXPECT_EQ(a(0, 0), 7);
    EXPECT_EQ(a(0, 1), 3);
    EXPECT_EQ(a(1, 0), 1);
    EXPECT_EQ(a(1, 1), 9);
}

TEST(matrix, add_1x1)
{
    matrix<int> a(1, 1);
    matrix<int> b(1, 1);
    a(0, 0) = 3;
    b(0, 0) = 4;
    EXPECT_EQ((a + b)(0, 0), 7);
}

TEST(matrix, add_2x2_double)
{
    matrix<double> a(2, 2);
    matrix<double> b(2, 2);

    a(0.0, 0.0) = 1.0; a(0.0, 1.0) = 2.0;
    a(1.0, 0.0) = 3.0; a(1.0, 1.0) = 4.0;

    b(0.0, 0.0) = 5.0; b(0.0, 1.0) = 6.0;
    b(1.0, 0.0) = 7.0; b(1.0, 1.0) = 8.0;

    EXPECT_EQ((a + b)(0.0, 0.0), 6.0);  
    EXPECT_EQ((a + b)(0.0, 1.0), 8.0);  
    EXPECT_EQ((a + b)(1.0, 0.0), 10.0); 
    EXPECT_EQ((a + b)(1.0, 1.0), 12.0); 
}


TEST(matrix, add_3x3)
{
    matrix<int> a(3, 3);
    matrix<int> b(3, 3);

    a(0, 0) = 1; a(0, 1) = 2; a(0, 2) = 3;
    a(1, 0) = 4; a(1, 1) = 5; a(1, 2) = 6;
    a(2, 0) = 7; a(2, 1) = 8; a(2, 2) = 9;

    b(0, 0) = 10; b(0, 1) = 11; b(0, 2) = 12;
    b(1, 0) = 13; b(1, 1) = 14; b(1, 2) = 15;
    b(2, 0) = 16; b(2, 1) = 17; b(2, 2) = 18;

    EXPECT_EQ((a + b)(0, 0), 11); 
    EXPECT_EQ((a + b)(0, 1), 13); 
    EXPECT_EQ((a + b)(0, 2), 15); 
    EXPECT_EQ((a + b)(1, 0), 17); 
    EXPECT_EQ((a + b)(1, 1), 19); 
    EXPECT_EQ((a + b)(1, 2), 21); 
    EXPECT_EQ((a + b)(2, 0), 23); 
    EXPECT_EQ((a + b)(2, 1), 25); 
    EXPECT_EQ((a + b)(2, 2), 27); 
}

TEST(matrix,sub_1x1)
{
    matrix<int> a(1, 1);
    matrix<int> b(1, 1);
    a(0, 0) = 5;
    b(0, 0) = 4;
    EXPECT_EQ((a - b)(0, 0), 1);
}

TEST(matrix, sub_2x2_)
{
    matrix<double> a(2, 2);
    matrix<double> b(2, 2);

    a(0.0, 0.0) = 10.0; a(0.0, 1.0) = 9.0;
    a(1.0, 0.0) = 8.0;  a(1.0, 1.0) = 7.0;

    b(0.0, 0.0) = 1.0;  b(0.0, 1.0) = 2.0;
    b(1.0, 0.0) = 3.0;  b(1.0, 1.0) = 4.0;
    EXPECT_EQ((a - b)(0.0, 0.0), 9.0);  
    EXPECT_EQ((a - b)(0.0, 1.0), 7.0); 
    EXPECT_EQ((a - b)(1.0, 0.0), 5.0); 
    EXPECT_EQ((a - b)(1.0, 1.0), 3.0); 
}

TEST(matrix, sub_3x3)
{
    matrix<int> a(3, 3);
    matrix<int> b(3, 3);

    a(0, 0) = 20; a(0, 1) = 19; a(0, 2) = 18;
    a(1, 0) = 17; a(1, 1) = 16; a(1, 2) = 15;
    a(2, 0) = 14; a(2, 1) = 13; a(2, 2) = 12;

    b(0, 0) = 1;  b(0, 1) = 2;  b(0, 2) = 3;
    b(1, 0) = 4;  b(1, 1) = 5;  b(1, 2) = 6;
    b(2, 0) = 7;  b(2, 1) = 8;  b(2, 2) = 9;

    EXPECT_EQ((a - b)(0, 0), 19); 
    EXPECT_EQ((a - b)(0, 1), 17); 
    EXPECT_EQ((a - b)(0, 2), 15); 
    EXPECT_EQ((a - b)(1, 0), 13); 
    EXPECT_EQ((a - b)(1, 1), 11); 
    EXPECT_EQ((a - b)(1, 2), 9);  
    EXPECT_EQ((a - b)(2, 0), 7);  
    EXPECT_EQ((a - b)(2, 1), 5);  
    EXPECT_EQ((a - b)(2, 2), 3);  
}

TEST(matrix,mul_1x1)
{
    
    matrix<int> a(1, 1);
    matrix<int> b(1, 1);
    a(0, 0) = 5;
    b(0, 0) = 4;
    EXPECT_EQ((a * b)(0, 0), 20);

}

TEST(matrix, mul_2x2)
{
    matrix<double> a(2, 2);
    matrix<double> b(2, 2);

    a(0.0, 0.0) = 1.0; a(0.0, 1.0) = 2.0;
    a(1.0, 0.0) = 3.0; a(1.0, 1.0) = 4.0;

    b(0.0, 0.0) = 5.0; b(0.0, 1.0) = 6.0;
    b(1.0, 0.0) = 7.0; b(1.0, 1.0) = 8.0;

    EXPECT_EQ((a * b)(0.0, 0.0), 19.0); 
    EXPECT_EQ((a * b)(0.0, 1.0), 22.0); 
    EXPECT_EQ((a * b)(1.0, 0.0), 43.0); 
    EXPECT_EQ((a * b)(1.0, 1.0), 50.0); 
}

TEST(matrix, mul_2x3_3x2)
{
    matrix<double> a(2, 3); 
    matrix<double> b(3, 2); 
    
    a(0, 0) = 1.0; a(0, 1) = 2.0; a(0, 2) = 3.0;
    a(1, 0) = 4.0; a(1, 1) = 5.0; a(1, 2) = 6.0;
    
    b(0, 0) = 7.0; b(0, 1) = 8.0;
    b(1, 0) = 9.0; b(1, 1) = 10.0;
    b(2, 0) = 11.0; b(2, 1) = 12.0;
    
    EXPECT_EQ((a * b)(0, 0), 58.0); 
    EXPECT_EQ((a * b)(0, 1), 64.0);  
    EXPECT_EQ((a * b)(1, 0), 139.0); 
    EXPECT_EQ((a * b)(1, 1), 154.0); 
}

TEST(matrix, mul_3x3_int)
{
    matrix<int> a(3, 3); 
    matrix<int> b(3, 3); 
    
    a(0, 0) = 1; a(0, 1) = 2; a(0, 2) = 3;
    a(1, 0) = 4; a(1, 1) = 5; a(1, 2) = 6;
    a(2, 0) = 7; a(2, 1) = 8; a(2, 2) = 9;

    b(0, 0) = 10; b(0, 1) = 11; b(0, 2) = 12;
    b(1, 0) = 13; b(1, 1) = 14; b(1, 2) = 15;
    b(2, 0) = 16; b(2, 1) = 17; b(2, 2) = 18;
    
    EXPECT_EQ((a * b)(0, 0), 84);  
    EXPECT_EQ((a * b)(0, 1), 90);  
    EXPECT_EQ((a * b)(0, 2), 96);  
    EXPECT_EQ((a * b)(1, 0), 201); 
    EXPECT_EQ((a * b)(1, 1), 216);
    EXPECT_EQ((a * b)(1, 2), 231); 
    EXPECT_EQ((a * b)(2, 0), 318); 
    EXPECT_EQ((a * b)(2, 1), 342);
    EXPECT_EQ((a * b)(2, 2), 366);
}

TEST(matrix,transpose_1x1)
{
     matrix<int> a(1,1);
     a(0,0) = 5;
     EXPECT_EQ(a.transpose()(0,0),5);
}

TEST(matrix, transpose_2x3)
{
    matrix<int> a(2, 3);

    a(0, 0) = 1; a(0, 1) = 2; a(0, 2) = 3;
    a(1, 0) = 4; a(1, 1) = 5; a(1, 2) = 6;

    matrix b = a.transpose(); 
    EXPECT_EQ(b(0, 0), 1); 
    EXPECT_EQ(b(0, 1), 4); 
    EXPECT_EQ(b(1, 0), 2); 
    EXPECT_EQ(b(1, 1), 5); 
    EXPECT_EQ(b(2, 0), 3); 
    EXPECT_EQ(b(2, 1), 6); 
}

TEST(matrix, transpose_2x2)
{
    matrix<double> a(2, 2);

    a(0, 0) = 1.5; a(0, 1) = 2.7;
    a(1, 0) = 3.2; a(1, 1) = 4.9;
    
    EXPECT_EQ(a.transpose()(0, 0), 1.5); 
    EXPECT_EQ(a.transpose()(0, 1), 3.2); 
    EXPECT_EQ(a.transpose()(1, 0), 2.7); 
    EXPECT_EQ(a.transpose()(1, 1), 4.9); 
}

TEST(matrix,Test_bool)
{
    matrix<bool> a(2,3);
    a(0,0) = true;
    EXPECT_EQ(a(0,0),true);

}


TEST(matrix, add_exception)
{
    matrix<int> m1(2, 2); 
    matrix<int> m2(2, 3); 

    m1(0, 0) = 1; m1(0, 1) = 2;
    m1(1, 0) = 3; m1(1, 1) = 4;

    m2(0, 0) = 1; m2(0, 1) = 2; m2(0, 2) = 3;
    m2(1, 0) = 4; m2(1, 1) = 5; m2(1, 2) = 6;

    

    EXPECT_THROW({m1 + m2;},std::invalid_argument);
}


TEST(matrix, sub_exception)
{
    matrix<int> m1(2, 2); 
    matrix<int> m2(2, 3); 

    m1(0, 0) = 1; m1(0, 1) = 2;
    m1(1, 0) = 3; m1(1, 1) = 4;

    m2(0, 0) = 1; m2(0, 1) = 2; m2(0, 2) = 3;
    m2(1, 0) = 4; m2(1, 1) = 5; m2(1, 2) = 6;

    

    EXPECT_THROW({m1 - m2;},std::invalid_argument);
}

TEST(matrix, mul_exception)
{
    matrix<int> m1(2, 1); 
    matrix<int> m2(2, 3); 

    m1(0, 0) = 1;
    m1(1, 0) = 3;

    m2(0, 0) = 1; m2(0, 1) = 2; m2(0, 2) = 3;
    m2(1, 0) = 4; m2(1, 1) = 5; m2(1, 2) = 6;

    

    EXPECT_THROW({m1 * m2;},std::invalid_argument);
}


TEST(matrix, copy_contrustor)
{
    matrix<int> original(2, 2);
    original(0, 0) = 1;
    original(0, 1) = 2;
    original(1, 0) = 3;
    original(1, 1) = 4;

    matrix<int> copy = original;

    EXPECT_EQ(copy(0, 0), 1);
    EXPECT_EQ(copy(0, 1), 2);
    EXPECT_EQ(copy(1, 0), 3);
    EXPECT_EQ(copy(1, 1), 4);

    original(0, 0) = 5;

    EXPECT_EQ(copy(0, 0), 1);
}

TEST(matrix, copy_operator)
{
    matrix<int> original(2, 2);
    original(0, 0) = 1;
    original(0, 1) = 2;
    original(1, 0) = 3;
    original(1, 1) = 4;

    matrix<int> copy(2,2);
    copy(0, 0) = 5;
    copy(0, 1) = 6;
    copy(1, 0) = 7;
    copy(1, 1) = 8;


    original = copy;

    EXPECT_EQ(original(0, 0), 5);
    EXPECT_EQ(original(0, 1), 6);
    EXPECT_EQ(original(1, 0), 7);
    EXPECT_EQ(original(1, 1), 8);

    copy(0, 0) = 999;
    EXPECT_EQ(original(0, 0), 5);


    
}

TEST(matrix, copy_operator_2)
{
    matrix<int> original(2, 2);
    original(0, 0) = 1;
    original(0, 1) = 2;
    original(1, 0) = 3;
    original(1, 1) = 4;

    original = original;

    EXPECT_EQ(original(0, 0), 1);
    EXPECT_EQ(original(0, 1), 2);
    EXPECT_EQ(original(1, 0), 3);
    EXPECT_EQ(original(1, 1), 4);

}
TEST(matrix, move_constructor)
{
    matrix<int> original(2, 2);
    original(0, 0) = 1;
    original(0, 1) = 2;
    original(1, 0) = 3;
    original(1, 1) = 4;

    matrix<int> move(std::move(original));
    EXPECT_EQ(move(0, 0), 1);
    EXPECT_EQ(move(0, 1), 2);
    EXPECT_EQ(move(1, 0), 3);
    EXPECT_EQ(move(1, 1), 4);
}

TEST(matrix, move_operator)
{
    matrix<int> original(2, 2);
    original(0, 0) = 1;
    original(0, 1) = 2;
    original(1, 0) = 3;
    original(1, 1) = 4;

    matrix<int> move(1,1);
    move(0,0) = 5;
    move = std::move(original);

    EXPECT_EQ(move(0, 0), 1);
    EXPECT_EQ(move(0, 1), 2);
    EXPECT_EQ(move(1, 0), 3);
    EXPECT_EQ(move(1, 1), 4);
}

TEST(matrix, add_3x3_parallel)
{
    matrix<int> a(3, 3);
    matrix<int> b(3, 3);

    a(0, 0) = 1; a(0, 1) = 2; a(0, 2) = 3;
    a(1, 0) = 4; a(1, 1) = 5; a(1, 2) = 6;
    a(2, 0) = 7; a(2, 1) = 8; a(2, 2) = 9;

    b(0, 0) = 10; b(0, 1) = 11; b(0, 2) = 12;
    b(1, 0) = 13; b(1, 1) = 14; b(1, 2) = 15;
    b(2, 0) = 16; b(2, 1) = 17; b(2, 2) = 18;

    matrix<int> result(3,3); 

    result(0,0) = 11; result(0,1) = 13; result(0,2) = 15;
    result(1,0) = 17; result(1,1) = 19; result(1,2) = 21;
    result(2,0) = 23; result(2,1) = 25; result(2,2) = 27;

    a = a.add_parralel(b);
    for(int i = 0;i < 3;++i)
    {
        for(int j = 0; j < 3;++j)
        {
            EXPECT_EQ(result(i,j), a(i,j)); 
        }
    }

}
