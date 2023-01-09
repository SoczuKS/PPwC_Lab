#pragma once

#include <cmath>

template <typename T> T myPow(T a, const int x) {
	T result{ 1 };
	for (int i{ 0 }; i < abs(x); ++i) {
		result *= a;
	}

	return x > 0 ? result : T(1) / result;
}

inline unsigned long long myFactorial(const unsigned long long x) {
	if (x == 0 or x == 1) return 1;

	unsigned long long result{ 1ULL };
	for (auto i{ 2ULL }; i <= x; ++i) {
		result *= i;
	}

	return result;
}

inline long double myExp(const unsigned long long x) {
	long double result{ 1.0L };
	long double previousResult{ 0.0L };
	constexpr long double errorRange(0.01L / 100.0L);

	for (int i{ 1 }; i < 170 && !(previousResult / result >= 1.0L - errorRange && previousResult / result <= 1.0L + errorRange); ++i) {
		const auto powResult = myPow(x, i);
		const auto factorialResult = myFactorial(i);

		previousResult = result;
		result += static_cast<long double>(powResult) / static_cast<long double>(factorialResult);
	}

	return result;
}

template<typename T> T multipow(T a, int x, const unsigned int n) {
	T result = { 1 };
	for (auto i{ 0U }; i < n; ++i) {
		result = myPow(a, x);
		a = result;
	}

	return result;
}