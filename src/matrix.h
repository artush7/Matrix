#include <stdexcept>


template <typename T>
class matrix_implementation
{
protected:
    int rows_;
    int columns_;
    T** memory_;
public:
    matrix_implementation(int rows,int columns);
    T& operator()(int row, int column);
    const T& operator()(int row, int column) const;

    matrix_implementation(const matrix_implementation<T>& other);
    matrix_implementation<T>& operator=(const matrix_implementation<T>& other);
    matrix_implementation(matrix_implementation<T>&& other);
    matrix_implementation<T>& operator=(matrix_implementation<T>&& other);


};

template <typename T>
class matrix : public matrix_implementation<T>
{
public:
    matrix(int rows,int columns);

    matrix operator+(const matrix& other);
    matrix operator-(const matrix& other);
    matrix operator*(const matrix& other);
    matrix transpose() const;

};



template <typename T>
matrix_implementation<T>::matrix_implementation(int rows,int columns) 
{
    this->rows_ = rows;
    this->columns_ = columns;
    this->memory_ = new T*[rows_];
    for(int i = 0;i < rows_;++i)
    {
        memory_[i] = new T[columns_];
    }
    
};

template <typename T>
T& matrix_implementation<T>::operator()(int row, int column)
{
    return memory_[row][column];
}

template <typename T>
const T& matrix_implementation<T>::operator()(int row, int column) const
{
    return memory_[row][column];
}

template <typename T>
matrix<T>::matrix(int rows,int columns) : matrix_implementation<T>(rows,columns) {}

template <typename T>
matrix<T> matrix<T>::operator+(const matrix<T>& other) 
{

    if(this->rows_ != other.rows_ || this->columns_ != other.columns_)
    {
        throw std::invalid_argument("Matrix dimensions do not match for addition");
    }

    else
    {
        matrix new_matrix(this->rows_,this->columns_);

        for(int i = 0;i < this->rows_;++i)
        {
            for(int j = 0;j < this->columns_;++j)
            {
                new_matrix(i,j) = (*this)(i,j) + other(i,j);
            }
        }
        return new_matrix;
    }
}

template <typename T>
matrix<T> matrix<T>::operator-(const matrix& other)
{
    if (this->rows_ != other.rows_ || this->columns_ != other.columns_)
    {
        throw std::invalid_argument("Matrix dimensions do not match for substraction");
    }

    else
    {
        matrix new_matrix(this->rows_,this->columns_);

        for(int i = 0;i < this->rows_;++i)
        {
            for(int j = 0;j < this->columns_;++j)
            {
                new_matrix(i,j) = (*this)(i,j) - other(i,j);
            }
        }
        return new_matrix;
    }
}

template <typename T>
matrix<T> matrix<T>::operator*(const matrix& other) 
{
    if (this->columns_ != other.rows_) 
    {
        throw std::invalid_argument("Matrix dimensions do not match for multiplying");
    }

    matrix new_matrix(this->rows_, other.columns_);
    for (int i = 0; i < this->rows_;++i) 
    {
        for (int j = 0; j < other.columns_;++j) 
        {
            T sum = 0;
            for (int k = 0; k < this->columns_;++k) 
            {
                sum += (*this)(i, k) * other(k, j);
            }
            new_matrix(i, j) = sum;
        }
    }
    return new_matrix;
}

template <typename T>
matrix<T> matrix<T>::transpose() const
{
    matrix new_matrix(this->columns_, this->rows_); 
    for (int i = 0; i < this->columns_;++i) 
    {
        for (int j = 0; j < this->rows_;++j) 
        {
            new_matrix(i, j) = (*this)(j, i); 
        }
    }
    return new_matrix;
}


template<typename T>
matrix_implementation<T>::matrix_implementation(const matrix_implementation<T>& other)
{
    this->rows_ = other.rows_;
    this->columns_ = other.columns_;
    this->memory_ = new T*[rows_];
    for(int i = 0;i < this->rows_;++i)
    {
        memory_[i] = new T[this->columns_];
        for(int j = 0; j < this->columns_; ++j)
        {
            this->memory_[i][j] = other.memory_[i][j];
        }
    }
}

template<typename T>
matrix_implementation<T>& matrix_implementation<T>::operator=(const matrix_implementation<T>& other)
{
    if (this == &other)     
    {
        return *this;
    }

    for(int i = 0;i < this->rows_; ++i)
    {
        delete[] this->memory_[i];
    }
    delete[] this->memory_;

    this->rows_ = other.rows_;
    this->columns_ = other.columns_;
    this->memory_ = new T*[this->rows_];
    for(int i = 0;i < this->rows_; ++i)
    {
        this->memory_[i] = new T[this->columns_];
        for(int j = 0;j < this->columns_;++j)
        {
            this->memory_[i][j] = other.memory_[i][j];
        }
    }

    return *this;

}

template<typename T>
matrix_implementation<T>::matrix_implementation(matrix_implementation<T>&& other)
{
    this->rows_ = other.rows_;
    this->columns_ = other.columns_;
    this->memory_ = other.memory_;

    other.memory_ = nullptr;
}

template<typename T>
matrix_implementation<T>& matrix_implementation<T>::operator=(matrix_implementation<T>&& other)
{
    std::swap(this->rows_, other.rows_);
    std::swap(this->columns_, other.columns_);
    std::swap(this->memory_, other.memory_);
    return *this;
}
