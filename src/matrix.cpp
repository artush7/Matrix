// #include "matrix.h"

// matrix_implementation::matrix_implementation(int rows,int columns) 
// {
//     this->rows_ = rows;
//     this->columns_ = columns;
//     this->memory_ = new double*[rows_];
//     for(int i = 0;i < rows_;++i)
//     {
//         memory_[i] = new double[columns_];
//     }
    
// }

// matrix_implementation::~matrix_implementation()
// {   
//     for(int i = 0; i < rows_;++i)
//     {
//         delete[] memory_[i];
//     }
//     delete[] memory_;
// }

// double& matrix_implementation::operator()(int row, int column)
// {
//     return memory_[row][column];
// }

// const double& matrix_implementation::operator()(int row, int column) const
// {
//     return memory_[row][column];
// }

// matrix::matrix(int rows,int columns) : matrix_implementation(rows,columns) {}

// matrix matrix::operator+(const matrix& other) 
// {

//     if(this->rows_ != other.rows_ || this->columns_ != other.columns_)
//     {
//         throw;
//     }

//     else
//     {
//         matrix new_matrix(rows_,columns_);

//         for(int i = 0;i < rows_;++i)
//         {
//             for(int j = 0;j < columns_;++j)
//             {
//                 new_matrix(i,j) = (*this)(i,j) + other(i,j);
//             }
//         }
//         return new_matrix;
//     }
// }

// matrix matrix::operator-(const matrix& other)
// {
//     if (this->rows_ != other.rows_ || this->columns_ != other.columns_)
//     {
//         throw;
//     }

//     else
//     {
//         matrix new_matrix(rows_,columns_);

//         for(int i = 0;i < rows_;++i)
//         {
//             for(int j = 0;j < columns_;++j)
//             {
//                 new_matrix(i,j) = (*this)(i,j) - other(i,j);
//             }
//         }
//         return new_matrix;
//     }
// }

// matrix matrix::operator*(const matrix& other) 
// {
//     if (this->columns_ != other.rows_) 
//     {
//         throw;
//     }

//     matrix new_matrix(this->rows_, other.columns_);
//     for (int i = 0; i < this->rows_;++i) 
//     {
//         for (int j = 0; j < other.columns_;++j) 
//         {
//             double sum = 0;
//             for (int k = 0; k < this->columns_;++k) 
//             {
//                 sum += (*this)(i, k) * other(k, j);
//             }
//             new_matrix(i, j) = sum;
//         }
//     }
//     return new_matrix;
// }

// matrix matrix::transpose() const
// {
//     matrix new_matrix(columns_, rows_); 
//     for (int i = 0; i < columns_;++i) 
//     {
//         for (int j = 0; j < rows_;++j) 
//         {
//             new_matrix(i, j) = (*this)(j, i); 
//         }
//     }
//     return new_matrix;
// }