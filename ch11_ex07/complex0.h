#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

class Complex {
private:
	double real;
	double imag;
public:
	Complex();
	Complex(double r, double i);
	~Complex();

	double getReal() const { return real; }
	double getImag() const { return imag; }

	Complex operator+(const Complex & rhs) const;
	Complex operator-(const Complex & rhs) const;
	Complex operator*(const Complex & rhs) const;
	Complex operator*(double rhs) const;
	Complex operator~() const;

	friend std::ostream & operator<<(std::ostream & os, const Complex & c);
	friend std::istream & operator>>(std::istream & is, Complex & c);
	friend Complex operator*(double n, const Complex & c) {
		return c * n;
	}
};

#endif // COMPLEX0_H_
