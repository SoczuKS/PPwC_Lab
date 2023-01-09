#pragma once

#include "ImaginaryPart.hpp"

#include <cmath>
#include <ostream>

template<typename T>
class ComplexNumber;

template<typename T>
class ComplexNumber {
public:
	ComplexNumber() = default;
	ComplexNumber(T re, ImaginaryPart<T> im) : re(re), im(im) {}

	[[nodiscard]] double modulus() const {
		return sqrt(re * re + im.value * im.value);
	}

	[[nodiscard]] ComplexNumber conjugation() const {
		return { re, -im };
	}

	ComplexNumber operator *(const ComplexNumber& other) const {
		ComplexNumber result{};
		result = result + re * other.re + other.im * re + im * other.re + im * other.im;
		return result;
	}

	ComplexNumber operator +(const ComplexNumber& other) const {
		return { re + other.re, im + other.im };
	}

	ComplexNumber operator -(const ComplexNumber& other) const {
		return { re - other.re, im - other.im };
	}

	ComplexNumber operator +(const T& r) const {
		return { re + r, im };
	}

	ComplexNumber operator -(const T& r) const {
		return { re - r, im };
	}

	ComplexNumber operator +(const ImaginaryPart<T>& i) const {
		return { re , im + i };
	}

	ComplexNumber operator -(const ImaginaryPart<T>& i) const {
		return { re, im - i };
	}

    friend std::ostream& operator <<(std::ostream& os, const ComplexNumber& number) {
		os << number.re << " + " << number.im;
		return os;
	}

	T re{ 0 };
	ImaginaryPart<T> im{};
};
