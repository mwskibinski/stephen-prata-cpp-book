#include "absdma.h"
#include <iostream>
#include <cstring>

AbsDMA::AbsDMA(const char * label_init, int r) {
	label = new char[std::strlen(label_init) + 1];
	std::strcpy(label, label_init);
	rating = r;
}
AbsDMA::AbsDMA(const AbsDMA & a) {
	label = new char[std::strlen(a.label) + 1];
	std::strcpy(label, a.label);
	rating = a.rating;
}
AbsDMA::~AbsDMA() {
	delete [] label;
}

void AbsDMA::view() const {
	std::cout << "label = " << label << '\n';
	std::cout << "rating = " << rating << '\n';
}

AbsDMA & AbsDMA::operator=(const AbsDMA & a) {
	if (this != &a) {
		delete [] label;
		label = new char[std::strlen(a.label) + 1];
		std::strcpy(label, a.label);
		rating = a.rating;
	}
	return *this;
}
