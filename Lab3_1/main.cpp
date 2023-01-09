#include "ComplexNumber.hpp"
#include "Matrix.hpp"

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>

#include <iostream>

int main() {
    ComplexNumber<double> complex1(4, 4);
    ComplexNumber<double> complex2(3, 3);
    auto complex3 = complex1 * complex2;
    std::cout << complex1 << '\n';
    std::cout << complex2 << '\n';
    std::cout << complex3 << '\n';
    std::cout << "Conjugation of complex3 = " << complex3.conjugation() << '\n';
    std::cout << "Modulus of complex3 = " << complex3.modulus() << '\n';

    ImaginaryPart<double> im1{ 5 };
    std::cout << -im1 << '\n';

    Matrix<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1000>>> matrix{ {{1,2},{3,4}} };
    std::cout << "Matrix matrix to pow 7:\n" << matrix.pow(7);
    std::cout << "e^matrix:\n" << std::setprecision(std::numeric_limits<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<100>>>::digits10) << matrix.exponential();

    std::cout << std::endl;
}