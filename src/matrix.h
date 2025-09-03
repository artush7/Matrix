#include <stdexcept>
#include <pthread.h>

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
    matrix add_parralel(const matrix& other) const;

};

template <typename T>
struct thread_data
{
    int start;
    int end;
    const matrix<T>* matrix_1;
    const matrix<T>* matrix_2;
    matrix<T>* matrix_result;

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
        return *this;

    matrix_implementation<T> tmp(other);

    std::swap(this->rows_, tmp.rows_);
    std::swap(this->columns_, tmp.columns_);
    std::swap(this->memory_, tmp.memory_);


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

template<typename T>
matrix<T> matrix<T>::add_parralel(const matrix& other) const
{
    if(this->rows_ != other.rows_ || this->columns_ != other.columns_)
    {
        throw std::invalid_argument("Matrix dimensions do not match for addition");
    }
    else
    {
        matrix<T> result(this->rows_,this->columns_);
        const int thread_count = 12;
        pthread_t threads[thread_count];
        thread_data<T>* data = new thread_data<T>[thread_count];
        int matrix_elements = this->rows_ * this->columns_;
        int elements_per_thread = matrix_elements / thread_count;
        int remainder= matrix_elements % thread_count;
        int start = 0;
        for(int k = 0;k < thread_count;++k)
        {
            int elements = elements_per_thread;
            if (k == thread_count - 1) elements = elements + remainder;
            int end = start + elements;

            data[k].start = start;
            data[k].end = end;
            data[k].matrix_1 = this;
            data[k].matrix_2 = &other;
            data[k].matrix_result = &result;

            pthread_create(&threads[k],nullptr,[](void* arg) -> void*
            {
                thread_data<T>* data = static_cast<thread_data<T>*>(arg);
                for(int i = data->start; i < data->end;++i)
                {
                    int r = i / data->matrix_1->columns_;
                    int c = i % data->matrix_1->columns_;
                    (*data->matrix_result)(r,c) = (*data->matrix_1)(r,c) + (*data->matrix_2)(r,c);
                }
                return nullptr;
            },&data[k]);

            start = end;
        }
        for(int i = 0;i < thread_count;++i)
        {
            pthread_join(threads[i],nullptr);
        }
        delete[] data;
        
        return result;
    }
    
}
