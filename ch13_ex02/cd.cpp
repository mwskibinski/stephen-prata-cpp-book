#include "cd.h"
#include <cstring>
#include <iostream>

Cd::Cd(const char * s1, const char * s2, int n, double x) {
	performers = new char[std::strlen(s1) + 1];
	std::strcpy(performers, s1);
	label = new char[std::strlen(s2) + 1];
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd & d) {
	performers = new char[std::strlen(d.performers) + 1];
	std::strcpy(performers, d.performers);
	label = new char[std::strlen(d.label) + 1];
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
Cd::Cd() {
	const char * init_text = "- empty -";
	performers = new char[std::strlen(init_text) + 1];
	std::strcpy(performers, init_text);
	label = new char[std::strlen(init_text) + 1];
	std::strcpy(label, init_text);
	selections = 0;
	playtime = 0.0;
}
Cd::~Cd() {
	delete [] performers;
	delete [] label;
}

void Cd::report() const {
	std::cout << "--- Dane płyty:" << '\n';
	std::cout << "Artyści: " << performers << '\n';
	std::cout << "Wydawnictwo: " << label << '\n';
	std::cout << "Liczba utworów: " << selections << '\n';
	std::cout << "Długość płyty: " << playtime << " min" << '\n';
}
Cd & Cd::operator=(const Cd & d) {
	if (this != &d) {
		delete [] performers;
		delete [] label;
		performers = new char[std::strlen(d.performers) + 1];
		std::strcpy(performers, d.performers);
		label = new char[std::strlen(d.label) + 1];
		std::strcpy(label, d.label);
		selections = d.selections;
		playtime = d.playtime;
	}
	return *this;
}
