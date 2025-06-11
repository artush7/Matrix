
class matrix_implementation
{
protected:
    int rows_;
    int columns_;
    int** memory_;
public:
    matrix_implementation(int rows,int columns);
    ~matrix_implementation();
    int& operator()(int row, int column);
    const int& operator()(int row, int column) const;

};

class matrix : public matrix_implementation
{
public:
    matrix(int rows,int columns);
    matrix operator+(const matrix& other);
};