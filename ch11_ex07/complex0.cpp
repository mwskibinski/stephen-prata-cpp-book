#include <iostream>
#include "complex0.h"

Complex::Complex() {
	real = imag = 0.0;
}
Complex::Complex(double r, double i) {
	real = r;
	imag = i;
}
Complex::~Complex() {

}

Complex Complex::operator+(const Complex & rhs) const {
	return Complex(real + rhs.real, imag + rhs.imag);
}
Complex Complex::operator-(const Complex & rhs) const {
	return Complex(real - rhs.real, imag - rhs.imag);
}
Complex Complex::operator*(const Complex & rhs) const {
	return Complex(
		real * rhs.real - imag * rhs.imag,
		real * rhs.imag + imag * rhs.real
	);
}
Complex Complex::operator*(double rhs) const {
	return Complex(real * rhs, imag * rhs);
}
Complex Complex::operator~() const {
	return Complex(real, -imag);
}

std::ostream & operator<<(std::ostream & os, const Complex & c) {
	os << "(" << c.real << "," << c.imag << "i)";
}
std::istream & operator>>(std::istream & is, Complex & c) {
	// Nie jest to szczególnie bezpieczny interfejs, ale dla tego zadania wystarcza.
	std::cout << "składowa rzeczywista: ";
	is >> c.real;
	std::cout << "składowa zespolona: ";
	is >> c.imag;
	return is;
}
