#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg(const char * name_init) {
	strncpy(name, name_init, MAX_LEN-1);
	name[MAX_LEN-1] = '\0';
	satietyFactor = 50;
}
Plorg::~Plorg() {

}
void Plorg::changeSatiety(int sf) {
	satietyFactor = sf;
}
void Plorg::print() const {
	std::cout << "--- Informacje o plorgu:\n";
	std::cout << "Imię: " << name << "\n";
	std::cout << "Współczynnik sytości: " << satietyFactor << "\n";
}
