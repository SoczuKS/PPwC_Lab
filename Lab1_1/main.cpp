#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>

int main() {
    constexpr size_t arraySize = 10;
    constexpr std::streamsize streamSize = 4;

	std::array<double, arraySize> numbers{};
    std::array<double, arraySize> sinusOfNumbers{};
    std::random_device randomDevice{};
	std::mt19937 randomEngine{ randomDevice() };
    std::uniform_real_distribution distribution(-100.0, 100.0);

    std::ranges::generate(numbers, [&distribution, &randomEngine]{
        return distribution(randomEngine);
    });
    std::ranges::generate(sinusOfNumbers, [i = 0, &numbers]() mutable {
        return std::sin(numbers[i++]);
    });

    std::fstream fileStream{ "file.txt", std::ios::out };

    for (int i{0}; i < arraySize; ++i) {
        const auto& n = numbers[i];
        const auto& sn = sinusOfNumbers[i];

        std::cout << std::setw(streamSize) << std::setprecision(streamSize) << n << '\t' << sn << '\n';
        fileStream << std::setw(streamSize) << std::setprecision(streamSize) << n << '\t' << sn << '\n';
    }
    std::cout << std::endl;
    fileStream << std::endl;

    return 0;
}
