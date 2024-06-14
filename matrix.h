#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>

/*@brief Класс, определяющий матрицу
*/
class Matrix {
protected:
    int n;
    int m;
    int** arr;
public:
    /*@brief Конструктор класса
        */
        Matrix(int n, int m);
    /*@brief Конструктор класса по умолчанию
        */
        Matrix();
    /*@brief Деструктор класса
        */
        ~Matrix();
    Matrix(const Matrix& arr2);
    /*@brief Геттер количества строк матрицы
        */
        int GetterN() const;
    /*@brief Геттер количества столбцов матрицы
        */
        int GetterM() const;
    /*@brief Метод нахождения максимума в части матрицы, где элемент на пересечении строки x и столбца y является левым верхним углом субматрицы размера n на m
        */
        int MaxVal(int x, int y, int n, int m);
    /*@brief Метод нахождения максимума по умолчанию(во всей матрице)
        */
        int MaxVal();

    Matrix operator+(const Matrix& arr2);
    Matrix operator-(const Matrix& arr2);
    Matrix operator*(const int& x);
    Matrix operator*(const Matrix& arr2);
    Matrix operator=(const Matrix& arr2);
    bool operator==(const Matrix& arr2);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& arr2);
    friend std::istream& operator>>(std::istream& is, const Matrix& arr2);
    /*@brief Перегрузка оператора[] для взятия значений из константных матриц
        */
        const int* operator[](size_t index) const;
    /*@brief Перегрузка оператора[] для взятия значений из неконстантных матриц
        */
        int* operator[](size_t index);
};

/*@brief Класс, определяющий свёртку матриц
*/
class ConvolutionMatrix : public Matrix {
public:
    ConvolutionMatrix(int n, int m);
    /*@brief Метод свёртки
        *
        *@return Возвращает матрицу - результат свёртки
        */
        Matrix Convolution(const Matrix & arr2);
};

/*@brief Класс, определяющий субдискретизацию матриц
*/
class MaxPoolingMatrix : public Matrix {
public:
    MaxPoolingMatrix(int n, int m);
    /**
    * @brief Метод субдискретизации
    *
    * @return Возвращает субдискретизированную матрицу
    */
    Matrix MaxPool();
};