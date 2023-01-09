#pragma once

#include <ostream>

template<typename T>
class ComplexNumber;

template<typename T>
class ImaginaryPart {
public:
	ImaginaryPart() = default;
	ImaginaryPart(T value) : value(value) {}

	T operator *(const ImaginaryPart& other) const {
		return -1 * value * other.value;
	}

	ImaginaryPart operator *(T scalar) const {
		return { value * scalar };
	}

	ImaginaryPart operator +(const ImaginaryPart& other) const {
		return { value + other.value };
	}

	ComplexNumber<T> operator +(T re) const {
		return { re, value };
	}

	ImaginaryPart operator -(const ImaginaryPart& other) const {
		return { value - other.value };
	}

	ComplexNumber<T> operator -(T re) const {
		return { -re, value };
	}

	ImaginaryPart operator -() const {
		return { -value };
	}

    friend std::ostream& operator <<(std::ostream& os, const ImaginaryPart& imaginaryPart) {
		os << imaginaryPart.value << "i";
		return os;
	}

	[[nodiscard]] bool isStillImaginary() const { return powerOfImaginaryUnit % 2 != 0; }

	T value{ 0 };

private:
	unsigned int powerOfImaginaryUnit{ 1 };
};
