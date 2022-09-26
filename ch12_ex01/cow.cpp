#include "cow.h"
#include <iostream>
#include <cstring>

Cow::Cow() {
	name[0] = '\0';
	hobby = new char [1];
	hobby[0] = '\0';
	weight = 0.0;
}
Cow::Cow(const char * nm, const char * ho, double wt) {
	strncpy(name, nm, NAME_LEN-1);
	name[NAME_LEN - 1] = '\0';
	hobby = new char [strlen(ho) + 1];
	strcpy(hobby, ho);
	weight = wt;
}
Cow::Cow(const Cow & c) {
	strcpy(name, c.name);
	hobby = new char [strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}
Cow::~Cow() {
	delete [] hobby;
}
Cow & Cow::operator=(const Cow & c) {
	if (this != &c) {
		delete [] hobby;
		strcpy(name, c.name);
		hobby = new char [strlen(c.hobby) + 1];
		strcpy(hobby, c.hobby);
		weight = c.weight;
	}
	return *this;
}
void Cow::showCow() const {
	std::cout << "--- Dane krowy:\n";
	std::cout << "Imię: " << name << '\n';
	std::cout << "Hobby: " << hobby << '\n';
	std::cout << "Waga: " << weight << '\n';
}
