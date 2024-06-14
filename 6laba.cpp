#include <iostream>
#include <algorithm>
#include <iomanip>
#include "matrix.h"

int main() {
    Matrix arr1 = Matrix(3, 3);
    std::cin >> arr1;
    Matrix arr2 = Matrix(3, 3);
    std::cin >> arr2;
    std::cout << arr1;
    std::cout << arr2;
    try {
        std::cout << "Sum: " << arr1 + arr2 << '\n';
        std::cout << "Diff: " << arr1 - arr2 << '\n';
        std::cout << "Mult by constant 2: " << arr1 * 2 << '\n';
        std::cout << "Mult: " << arr1 * arr2 << '\n';
        std::cout << "Equal: " << (arr1 == arr2) << '\n';
        std::cout << "Maximum: " << arr2.MaxVal() << '\n';
        std::cout << "arr1: " << arr1 << '\n';
        arr1 = arr2;
        std::cout << "arr2 (copied to arr1): " << arr1 << '\n';
    }
    catch (const char* message) {
        std::cerr << message << '\n';
        std::cerr << "Returning 1." << '\n';
        return 1;
    }
    ConvolutionMatrix filter = ConvolutionMatrix(2, 2);
    std::cin >> filter;
    Matrix resarr = filter.Convolution(arr1);
    std::cout << "Convolution: " << resarr;

    MaxPoolingMatrix mpmatrix = MaxPoolingMatrix(4, 4);
    std::cin >> mpmatrix;
    Matrix resarr2 = mpmatrix.MaxPool();
    std::cout << "Max Pooling: " << resarr2;
}
