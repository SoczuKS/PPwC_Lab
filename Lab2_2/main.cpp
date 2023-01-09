#include "Matrix.hpp"

#include <iostream>

int main() {
    const Matrix<float> matrix1{{ {2,2,2}, {3,3,3}, {4,4,4} }};
    const Matrix<float> matrix2{ {{3,3},{4,4},{5,5}} };

    try {
        const auto resultMatrix = matrix1 * matrix1 * matrix1 * matrix1;

        std::cout << resultMatrix;
    } catch (std::runtime_error& ex) {
        std::cout << ex.what();
    }

    std::cout << std::endl;
}
