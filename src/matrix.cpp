#include "matrix.h"

matrix_creation::matrix_creation(int rows,int columns) 
{
    this->rows_ = rows;
    this->columns_ = columns;
    this->memory_ = new int*[rows_];
    for(int i = 0;i < rows_;++i)
    {
        memory_[i] = new int[columns_];
    }
    
}

matrix_creation::~matrix_creation()
{   
    for(int i = 0; i < rows_;++i)
    {
        delete[] memory_[i];
    }
    delete[] memory_;
}

int& matrix_creation::operator()(int row, int column)
{
    return memory_[row][column];
}
