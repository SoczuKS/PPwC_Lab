#include <cmath>
#include <numbers>
#include <numeric>
#include <iostream>

int main() {
	for (double x{ 0.0 }; x <= 2.0 * std::numbers::pi / 5.0; x = std::nextafter(x, std::numeric_limits<double>::infinity())) {
		if (std::sin(x * 5.0) - 0.1 * std::pow(std::sin(x * 5.0), 3) + 0.3 == 0.0) {
			std::cout << "The answer is: " << x << " + 2kπ\n";
		}
	}
	std::cout << std::endl;
	return 0;
}