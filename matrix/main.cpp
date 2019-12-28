

#include <iostream>
#include <vector>
using std::vector;

class Matrix{
private:

public:
    vector<vector<int> > arr;

Matrix(); //конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов

};

int main(int argc, const char * argv[]) {
    

    
    return 0;
}


Matrix::Matrix(){ //конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов
    vector<vector<int> > arr(0, vector<int>(0));  // vector<vector<int> > a(n, vector<int>(m));
}

