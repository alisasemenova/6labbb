#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>

/*@brief �����, ������������ �������
*/
class Matrix {
protected:
    int n;
    int m;
    int** arr;
public:
    /*@brief ����������� ������
        */
        Matrix(int n, int m);
    /*@brief ����������� ������ �� ���������
        */
        Matrix();
    /*@brief ���������� ������
        */
        ~Matrix();
    Matrix(const Matrix& arr2);
    /*@brief ������ ���������� ����� �������
        */
        int GetterN() const;
    /*@brief ������ ���������� �������� �������
        */
        int GetterM() const;
    /*@brief ����� ���������� ��������� � ����� �������, ��� ������� �� ����������� ������ x � ������� y �������� ����� ������� ����� ���������� ������� n �� m
        */
        int MaxVal(int x, int y, int n, int m);
    /*@brief ����� ���������� ��������� �� ���������(�� ���� �������)
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
    /*@brief ���������� ���������[] ��� ������ �������� �� ����������� ������
        */
        const int* operator[](size_t index) const;
    /*@brief ���������� ���������[] ��� ������ �������� �� ������������� ������
        */
        int* operator[](size_t index);
};

/*@brief �����, ������������ ������ ������
*/
class ConvolutionMatrix : public Matrix {
public:
    ConvolutionMatrix(int n, int m);
    /*@brief ����� ������
        *
        *@return ���������� ������� - ��������� ������
        */
        Matrix Convolution(const Matrix & arr2);
};

/*@brief �����, ������������ ���������������� ������
*/
class MaxPoolingMatrix : public Matrix {
public:
    MaxPoolingMatrix(int n, int m);
    /**
    * @brief ����� ����������������
    *
    * @return ���������� ��������������������� �������
    */
    Matrix MaxPool();
};