
class matrix_memory
{
private:
   
protected:
    int rows_;
    int columns_;
    int** memory_;
public:
    matrix_memory(int rows,int columns);
    ~matrix_memory();
    int& operator()(int row, int column);


};
