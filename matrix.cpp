#include <iostream>
#include <algorithm>
#include <iomanip>
#include "matrix.h"

Matrix::Matrix(int n, int m) {
    this->n = n;
    this->m = m;
    arr = new int* [n];
    for (int i = 0; i < n; ++i) arr[i] = new int[m];
};
Matrix::Matrix() : Matrix(2, 2) {};
Matrix::~Matrix() {
    for (int i = 0; i < n; ++i) delete[] arr[i];
    delete[] arr;
};
Matrix::Matrix(const Matrix& arr2) : Matrix(arr2.n, arr2.m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->arr[i][j] = arr2.arr[i][j];
        }
    }
};
int Matrix::GetterN() const {
    return this->n;
}
int Matrix::GetterM() const {
    return this->m;
}
int Matrix::MaxVal(int x, int y, int n, int m) {
    int ans = this->arr[x][y];
    for (int i = x; i < n + x; ++i) {
        for (int j = y; j < m + y; ++j) {
            if (this->arr[i][j] > ans) ans = this->arr[i][j];
        }
    }
    return ans;
};
int Matrix::MaxVal() {
    return MaxVal(0, 0, this->n, this->m);
};
Matrix Matrix::operator+(const Matrix& arr2) {
    int n1 = this->n;
    int m1 = this->m;
    int n2 = arr2.n;
    int m2 = arr2.m;
    if (n1 != n2 && m1 != m2) {
        throw "Different sizes.";
    }
    Matrix arr3 = Matrix(n1, m1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr3.arr[i][j] = this->arr[i][j] + arr2.arr[i][j];
        }
    }
    return arr3;
}
Matrix Matrix::operator-(const Matrix& arr2) {
    int n1 = this->n;
    int m1 = this->m;
    int n2 = arr2.n;
    int m2 = arr2.m;
    if (n1 != n2 && m1 != m2) {
        throw "Different sizes.";
    }
    Matrix arr3 = Matrix(n1, m1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr3.arr[i][j] = this->arr[i][j] - arr2.arr[i][j];
        }
    }
    return arr3;
}
Matrix Matrix::operator*(const int& x) {
    int n1 = this->n;
    int m1 = this->m;
    Matrix arr3 = Matrix(n1, m1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr3.arr[i][j] = this->arr[i][j] * x;
        }
    }
    return arr3;
}
Matrix Matrix::operator*(const Matrix& arr2) {
    int n1 = this->n;
    int m1 = this->m;
    int n2 = arr2.n;
    int m2 = arr2.m;
    if (n2 != m1) {
        throw "The number of columns of matrix 1 and rows of matrix 2 are not equal.";
    }
    Matrix arr3 = Matrix(n1, m2);
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m2; ++j) {
            arr3.arr[i][j] = 0;
        }
    }
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m2; ++j) {
            for (int k = 0; k < m1; ++k) {
                arr3.arr[i][j] += this->arr[i][k] * arr2.arr[k][j];
            }
        }
    }
    return arr3;
}
Matrix Matrix::operator=(const Matrix& arr2) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->arr[i][j] = arr2.arr[i][j];
        }
    }
    return *this;
}
bool Matrix::operator==(const Matrix& arr2) {
    int n1 = this->n;
    int m1 = this->m;
    int n2 = arr2.n;
    int m2 = arr2.m;
    if (n1 != n2 || m1 != m2) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (this->arr[i][j] != arr2.arr[i][j]) {
                return false;
            };
        }
    }
    return true;
}
std::ostream& operator<<(std::ostream& os, const Matrix& arr2) {
    os << "Matrix output: \n";
    for (int i = 0; i < arr2.n; ++i) {
        for (int j = 0; j < arr2.m; ++j) {
            os << arr2.arr[i][j] << std::setw(5);
        }
        os << '\n';
    }
    return os;
}
std::istream& operator>>(std::istream& is, const Matrix& arr2) {
    for (int i = 0; i < arr2.n; ++i) {
        for (int j = 0; j < arr2.m; ++j) {
            is >> arr2.arr[i][j];
        }
    }
    return is;
}
const int* Matrix::operator[](size_t index) const {
    return this->arr[index];
}
int* Matrix::operator[](size_t index) {
    return this->arr[index];
}


ConvolutionMatrix::ConvolutionMatrix(int n, int m) {
    this->n = n;
    this->m = m;
    arr = new int* [n];
    for (int i = 0; i < n; ++i) arr[i] = new int[m];
};
Matrix ConvolutionMatrix::Convolution(const Matrix& arr2) {
    int n1 = this->n;
    int m1 = this->m;
    int n2 = arr2.GetterN();
    int m2 = arr2.GetterM();
    int n3 = n2 - n1 + 1;
    int m3 = m2 - m1 + 1;
    Matrix resarr = Matrix(n3, m3);
    for (int k = 0; k < n3; ++k) {
        for (int l = 0; l < m3; ++l) {
            int summa = 0;
            for (int i = 0; i < n1; ++i) {
                for (int j = 0; j < m1; ++j) {
                    const int* ar = arr2[i + k];
                    summa += ar[j + l] * this->arr[i][j];
                }
            }
            int* ar2 = resarr[k];
            ar2[l] = summa;
        }
    }
    return resarr;
};


MaxPoolingMatrix::MaxPoolingMatrix(int n, int m) {
    this->n = n;
    this->m = m;
    arr = new int* [n];
    for (int i = 0; i < n; ++i) arr[i] = new int[m];
};
Matrix MaxPoolingMatrix::MaxPool() {
    int n1 = this->n;
    int m1 = this->m;
    Matrix resarr = Matrix(n - 1, m - 1);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            resarr[i][j] = MaxVal(i, j, 2, 2);
        }
    }
    return resarr;
};