#include "hasdma.h"
#include <iostream>
#include <cstring>

HasDMA::HasDMA(const char * label_init, int r, const char * style_init)
	: AbsDMA(label_init, r)
{
	style = new char[std::strlen(style_init) + 1];
	std::strcpy(style, style_init);
}
HasDMA::HasDMA(const AbsDMA & a, const char * style_init)
	: AbsDMA(a)
{
	style = new char[std::strlen(style_init) + 1];
	std::strcpy(style, style_init);
}
HasDMA::HasDMA(const HasDMA & h)
	: AbsDMA(h)
{
	style = new char[std::strlen(h.style) + 1];
	std::strcpy(style, h.style);
}
HasDMA::~HasDMA() {
	delete [] style;
}

void HasDMA::view() const {
	AbsDMA::view();
	std::cout << "style = " << style << '\n';
}

HasDMA & HasDMA::operator=(const HasDMA & h) {
	if (this != &h) {
		AbsDMA::operator=(h);
		delete [] style;
		style = new char[std::strlen(h.style) + 1];
		std::strcpy(style, h.style);
	}
	return *this;
}
