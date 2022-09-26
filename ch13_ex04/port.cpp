#include "port.h"
#include <iostream>
#include <cstring>

Port::Port(const char * br, const char * st, int b) {
	brand = new char[std::strlen(br) + 1];
	std::strcpy(brand, br);
	std::strncpy(style, st, STYLE_LEN - 1);
	style[STYLE_LEN - 1] = '\0';
	if (b < 0) {
		std::cout << "Liczba butelek nie moze byc ujemna. Ustawiam ja na 0" << '\n';
		bottles = 0;
	} else
		bottles = b;
}
Port::Port(const Port & p) {
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
}

Port & Port::operator=(const Port & p) {
	if (this != &p) {
		delete [] brand;
		brand = new char[std::strlen(p.brand) + 1];
		std::strcpy(brand, p.brand);
		std::strcpy(style, p.style);
		bottles = p.bottles;
	}
	return *this;
}
Port & Port::operator+=(int b) {
	bottles += b;
	return *this;
}
Port & Port::operator-=(int b) {
	if (b > bottles)
		std::cout << "Liczba butelek nie może być ujemna. Nie wykonuję odejmowania." << '\n';
	else
		bottles -= b;
	return *this;
}

void Port::show() const {
	std::cout << "Marka: " << brand << '\n';
	std::cout << "Rodzaj: " << style << '\n';
	std::cout << "Butelek: " << bottles << '\n';
}

std::ostream & operator<<(std::ostream & os, const Port & p) {
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}
