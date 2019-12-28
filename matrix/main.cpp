

#include <iostream>
#include <vector>
using std::vector;

class Matrix{
private:
    
public:
    int rows,cols;
    vector<vector<int> > arr;

Matrix(); //конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов
/*
    конструктор от двух целочисленных параметров:
    num_rows и num_cols, — которые задают количество строк и столбцов матрицы соответственно
*/
Matrix(int rows, int cols);

};

int main(int argc, const char * argv[]) {
    

    
    return 0;
}


Matrix::Matrix(){ //конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов
    arr(0, vector<int>(0));  // vector<vector<int> > a(n, vector<int>(m));
}
Matrix::Matrix(int rows, int cols){
    this->rows=rows;
    this->cols=cols;
    vector<vector<int> > arr(rows, vector<int>(cols));
}


