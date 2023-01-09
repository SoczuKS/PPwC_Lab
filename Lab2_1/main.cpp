#include "Utils.hpp"

#include <cmath>
#include <iostream>
#include <numbers>

int main() {
	int x{}, n{};
	std::cout << "Liczymy exp(x). Podaj x: ";
	std::cin >> x;
	std::cout << "Wynik cmath: " << exp(x) << '\n';
	std::cout << "Wynik myExp: " << myExp(x) << '\n';
	std::cout << "Wynik myPow: " << myPow(std::numbers::e_v<double>, x) << '\n';

	std::cout << "Policzymy n-krotnie 1.1^x. Podaj n: ";
	std::cin >> n;
	std::cout << "Podaj x: ";
	std::cin >> x;
	std::cout << "Wynik: " << multipow(1.1L, x, n) << '\n'; 	

	std::cout << std::endl;
	return 0;
}

// +3 PUNKTY
