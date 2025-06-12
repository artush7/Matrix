
class matrix_implementation
{
protected:
    int rows_;
    int columns_;
    double** memory_;
public:
    matrix_implementation(int rows,int columns);
    ~matrix_implementation();
    double& operator()(int row, int column) ;
    const double& operator()(int row, int column) const;

};

class matrix : public matrix_implementation
{
public:
    matrix(int rows,int columns);
    matrix operator+(const matrix& other);
    matrix operator-(const matrix& other);
    matrix operator*(const matrix& other);
    matrix transpose() const;
};