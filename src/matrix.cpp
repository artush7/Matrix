#include "matrix.h"

matrix_implementation::matrix_implementation(int rows,int columns) 
{
    this->rows_ = rows;
    this->columns_ = columns;
    this->memory_ = new int*[rows_];
    for(int i = 0;i < rows_;++i)
    {
        memory_[i] = new int[columns_];
    }
    
}

matrix_implementation::~matrix_implementation()
{   
    for(int i = 0; i < rows_;++i)
    {
        delete[] memory_[i];
    }
    delete[] memory_;
}

int& matrix_implementation::operator()(int row, int column)
{
    return memory_[row][column];
}

const int& matrix_implementation::operator()(int row, int column) const
{
    return memory_[row][column];
}

matrix::matrix(int rows,int columns) : matrix_implementation(rows,columns) {}

matrix matrix::operator+(const matrix& other) 
{

    if(this->rows_ != other.rows_ || this->columns_ != other.columns_)
    {
        throw ;
    }

    else
    {
        matrix new_matrix(rows_,columns_);

        for(int i = 0;i < rows_;++i)
        {
            for(int j = 0;j < columns_;++i)
            {
                new_matrix(i,j) = (*this)(i,j) + other(i,j);
            }
        }
        return new_matrix;
    }
}