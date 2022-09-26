#include "cd.h"
#include <cstring>
#include <iostream>

Cd::Cd(const char * s1, const char * s2, int n, double x) {
	std::strncpy(performers, s1, PERFORMERS_LEN-1);
	performers[PERFORMERS_LEN-1] = '\0';
	std::strncpy(label, s2, LABEL_LEN-1);
	label[LABEL_LEN-1] = '\0';
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd & d) {
	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
Cd::Cd() {
	std::strcpy(performers, "- empty -");
	std::strcpy(label, "- empty -");
	selections = 0;
	playtime = 0.0;
}
Cd::~Cd() {

}

void Cd::report() const {
	std::cout << "--- Dane płyty:" << '\n';
	std::cout << "Artyści: " << performers << '\n';
	std::cout << "Wydawnictwo: " << label << '\n';
	std::cout << "Liczba utworów: " << selections << '\n';
	std::cout << "Długość płyty: " << playtime << " min" << '\n';
}
//Cd & Cd::operator=(const Cd & d) {
//	if (this != &d) {
//		std::strcpy(performers, d.performers);
//		std::strcpy(label, d.label);
//		selections = d.selections;
//		playtime = d.playtime;
//	}
//	return *this;
//}
