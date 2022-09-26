#include <iostream>
#include <string>
#include <cstring>
#include "person.h"

Person::Person(const string & ln, const char * fn) {
	lname = ln;
	strncpy(fname, fn, LIMIT-1);
	fname[LIMIT - 1] = '\0';
}
void Person::Show() const {
	std::cout << "--- metoda Show():\n";
	std::cout << fname << " " << lname << std::endl;
}
void Person::FormalShow() const {
	std::cout << "--- metoda FormalShow():\n";
	std::cout << lname << ", " << fname << std::endl;
}
