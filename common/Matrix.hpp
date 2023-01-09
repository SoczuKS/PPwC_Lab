#pragma once

#include "Utils.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T>
class Matrix {
public:
	Matrix() = default;
	Matrix(size_t rows, size_t columns) : values{ std::vector<std::vector<T>>(rows, std::vector<T>(columns)) } {}
	Matrix(const std::vector<std::vector<T>>& val) : values(val) {}
	Matrix(const Matrix& other) = default;
	Matrix(Matrix&&) = default;

	[[nodiscard]] Matrix operator +(const Matrix& rhs) const {
		if (empty() or rhs.empty()) throw std::runtime_error("EMPTY MATRIX!");
		if (numRows() != rhs.numRows() or numColumns() != rhs.numColumns()) throw std::runtime_error("NOT MATCHING SIZES!");

		Matrix result(*this);
		for (size_t i{0}; i < numRows(); ++i) {
		    for(size_t j{0}; j < numColumns(); ++j) {
				result[i][j] += rhs[i][j];
		    }
		}
		return result;
	}

	[[nodiscard]] Matrix& operator +=(const Matrix& rhs) {
		if (empty() or rhs.empty()) throw std::runtime_error("EMPTY MATRIX!");
		if (numRows() != rhs.numRows() or numColumns() != rhs.numColumns()) throw std::runtime_error("NOT MATCHING SIZES!");

		for (size_t i{ 0 }; i < numRows(); ++i) {
			for (size_t j{ 0 }; j < numColumns(); ++j) {
				values[i][j] += rhs[i][j];
			}
		}
		return *this;
	}

	[[nodiscard]] Matrix operator *(const Matrix& other) const noexcept(false) {
		if (empty() or other.empty()) throw std::runtime_error("EMPTY MATRIX!");
		if (numColumns() != other.numRows()) throw std::runtime_error("NOT MATCHING SIZES!");

		Matrix result(numRows(), other.numColumns());

		for (size_t i{ 0 }; i < result.numRows(); ++i)
			for (size_t j{ 0 }; j < result.numColumns(); ++j)
				for (size_t k{ 0 }; k < numColumns(); ++k)
					result[i][j] += values[i][k] * other[k][j];

		return result;
	}

	[[nodiscard]] Matrix operator *(T factor) const {
		Matrix result(*this);

		for (size_t i{0}; i < numRows(); ++i) {
		    for (auto& row = result[i]; auto& el : row) {
				el *= factor;
		    }
		}

		return result;
	}

	Matrix& operator =(const Matrix& rhs) = default;

	std::vector<T>& operator [](size_t i) { return values[i]; }
	const std::vector<T>& operator [](size_t i) const { return values[i]; }

	[[nodiscard]] bool empty() const { return values.empty(); }
	[[nodiscard]] size_t numRows() const { return values.size(); }
	[[nodiscard]] size_t numColumns() const {
		return numRows() == 0 ? 0 : values[0].size();
	}

	[[nodiscard]] bool isSquare() const { return numRows() == numColumns(); }

	[[nodiscard]] Matrix pow(const unsigned int n) const {
		if (n == 0) {
			if (not isSquare()) throw std::runtime_error("NON SQUARE MATRIX!");

			Matrix result(numRows(), numColumns());
			for (size_t i{0}; i < numRows(); ++i) {
				result[i][i] = 1;
			}
			return result;
		}

		Matrix result(*this);

		for (unsigned int i = 2; i <= n; ++i) {
			result = result * *this;
		}

		return result;
	}

	[[nodiscard]] Matrix exponential(const unsigned int counter = 23) const {
		if (not isSquare()) throw std::runtime_error("NON SQUARE MATRIX!");

		Matrix result(numRows(), numColumns());

		for (unsigned int k = 0; k < counter; ++k) {
			T factor = static_cast<T>(1.0) / static_cast<T>(myFactorial(k));
			Matrix matrixPow = pow(k);
			Matrix valueToAdd = matrixPow * factor;

			result = result + valueToAdd;
		}

		return result;
	}

private:
	std::vector<std::vector<T>> values;
};

template<typename T>
std::ostream& operator <<(std::ostream& os, const Matrix<T>& matrix) {
	for (int i{0}; i < matrix.numRows(); ++i) {
		for (const auto& row = matrix[i]; const auto & el : row) {
			std::cout << el << ' ';
		}
		std::cout << '\n';
	}
	return os;
}
