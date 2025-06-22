#include "matrix.h"

#include <iostream>
#include <stdexcept>

bool add_exception()
{
    try
    {
        matrix<int> m1(2, 2); 
        matrix<int> m2(2, 3); 

        m1(0, 0) = 1; m1(0, 1) = 2;
        m1(1, 0) = 3; m1(1, 1) = 4;

        m2(0, 0) = 1; m2(0, 1) = 2; m2(0, 2) = 3;
        m2(1, 0) = 4; m2(1, 1) = 5; m2(1, 2) = 6;

        auto result = m1 + m2; 

    }
    catch(std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
        return true;
    }
    return false;
}

bool substract_exception()
{

   try
    {
        matrix<int> m1(2, 2); 
        matrix<int> m2(2, 3); 

        m1(0, 0) = 1; m1(0, 1) = 2;
        m1(1, 0) = 3; m1(1, 1) = 4;

        m2(0, 0) = 1; m2(0, 1) = 2; m2(0, 2) = 3;
        m2(1, 0) = 4; m2(1, 1) = 5; m2(1, 2) = 6;

        auto result = m1 - m2; 
    }
    catch(std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
        return true;
    }
    
    return false;
}

bool multiply_exception()
{
    try
    {
        matrix<float> m1(2, 2); 
        matrix<float> m2(1, 1); 

        m1(0, 0) = 1.4; m1(0, 1) = 2.5;
        m1(1, 0) = 3.7; m1(1, 1) = 4.9;

        m2(0, 0) = 1.1;

        auto result = m1 * m2;
    }
    catch(std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
        return true;
    }
    return false;
}