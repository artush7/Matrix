
class matrix_creation
{
private:
   
protected:
    int rows_;
    int columns_;
    int** memory_;
public:
    matrix_creation(int rows,int columns);
    ~matrix_creation();
    int& operator()(int row, int column);


};
