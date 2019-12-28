
#include "Matrix_class.hpp"

#include <iostream>


Matrix::Matrix() :arr(0, vector<int>(0))
{ //конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов
}

///Если количество строк или количество столбцов, переданное в конструктор класса Matrix, оказалось отрицательным, то должно быть выброшено стандартное исключение out_of_range.
Matrix::Matrix(int rows, int cols) :arr(rows, vector<int>(cols))
{
    if(rows<0 || cols<0){
        throw std::out_of_range ("Out of range");
    }
    this->_rows=rows;
    this->_cols=cols;
}

///метод Reset, принимающий два целочисленных параметра, которые задают новое количество строк и столбцов матрицы соответственно; метод Reset меняет размеры матрицы на заданные и обнуляет все её элементы
///Если количество строк или количество столбцов, переданное в метод Reset, оказалось отрицательным, то должно быть выброшено стандартное исключение out_of_range.

void Matrix::Reset(int new_rows, int new_cols){
    if(new_rows<0 || new_cols<0){
        throw std::out_of_range ("Out of range");
    }
    
    _rows = new_rows;
    _cols = new_cols;
    arr.clear();// обнуляем
    
    for(int i = 0;i<_rows;i++){
        arr.push_back(vector<int>(_cols)); // в каждую строку кладем вектор
        for(int j = 0;j<_cols;j++)
        {
            arr[i].push_back(0);
        }
    }
}

///константный метод At, который принимает номер строки и номер столбца (именно в этом порядке; нумерация строк и столбцов начинается с нуля) и возвращает значение в соответствущей ячейке матрицы
int Matrix::At(int atRow, int atCol) const{
    return arr.at(atRow).at(atCol); // at и так бросает исключение
}
///неконстантный метод At с такими же параметрами, но возвращающий ссылку на значение в соответствущей ячейке матрицы
int &Matrix::At(int atRow, int atCol){
    return arr.at(atRow).at(atCol); // at и так бросает исключение
}

///константный метод GetNumRows
int Matrix:: GetNumRows() const{
    return _rows;
}
///константный метод GetNumCols
int Matrix:: GetNumCols() const{
    return _cols;
}

///оператор ввода из потока istream; формат ввода простой — сначала задаётся количество строк и столбцов (именно в этом порядке), а затем все элементы матрицы: сначала элемент первой строки и первого столбца, затем элемент первой строки и второго столбца и так далее
std::istream& operator>> (std::istream &in,  Matrix &matrix)
{
    
    int temp_rows,temp_cols;
    
    in >> temp_rows >>temp_cols;
    
    matrix.Reset(temp_rows, temp_cols); // if out of range-> throws exception
    
    matrix._rows = temp_rows;
    matrix._cols = temp_cols;
    
    for (int i = 0;i<matrix._rows;i++){
        for(int j = 0;j<matrix._cols;j++){
           in>>matrix.arr[i][j];
        }
    }
 
    return in;
}


std::ostream& operator<< (std::ostream &out,const  Matrix &matrix)
{
    
    out << matrix._rows << matrix._cols<<std::endl ;
    for (int i = 0;i<matrix._rows;i++){
        for(int j = 0;j<matrix._cols;j++){
           out<<matrix.arr[i][j]<<" ";
        }
        out<<std::endl;
    }
 
    return out;
}

///оператор проверки на равенство (==): он должен возвращать true, если сравниваемые матрицы имеют одинаковый размер и все их соответствующие элементы равны между собой, в противном случае он должен возвращать false.
bool operator== (const Matrix &m1, const Matrix &m2)
{
    if(m1.GetNumRows()==m2.GetNumRows() && m1.GetNumCols()==m2.GetNumCols())
    {
        for(int i = 0; i<m1.GetNumRows();i++)
        {
            for(int j = 0; j<m1.GetNumCols();j++)
            {
                if(m1.At(i, j) != m2.At(i,j))
                {
                    return false;
                }
            }
        }
        return true;
    }
    else{
        return false;
    }
}

///оператор сложения: он должен принимать две матрицы и возвращать новую матрицу, которая является их суммой; если переданные матрицы имеют разные размеры этот оператор должен выбрасывать стандартное исключение invalid_argument.
const Matrix operator+(const Matrix& left, const Matrix& right) {
    Matrix newMatrix=left;
    if(left.GetNumRows()==right.GetNumRows() && left.GetNumCols()==right.GetNumCols())
    {
        for(int i = 0; i<newMatrix.GetNumRows();i++)
        {
            for(int j = 0; j<newMatrix.GetNumCols();j++)
            {
                newMatrix.At(i, j) = left.At(i, j) + right.At(i, j);
            }
        }
    }
    else{
        throw std::invalid_argument("different size");
    }
    
    
    
    return newMatrix;
}

Matrix Matrix::operator=(Matrix other)
{
    _rows = other._rows;
    _cols = other._cols;
    arr = other.arr;
    return *this;
}
