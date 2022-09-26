#include "winec.h"
#include <iostream>

Wine::Wine(const char * l, int y)
    : std::string(l), PairArray(ArrayInt(0, y), ArrayInt(0, y)), year_n(y)
{}

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
    : std::string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)), year_n(y)
{}

void Wine::getBottles() {
    if (year_n > 0) {
        std::cout << "Podaj dane o winie " << (const std::string &) *this
        	<< " dla " << year_n << " roczników:\n";
        for (int i = 0; i < year_n; i++) {
            std::cout << "Podaj rocznik: ";
            // std::cin >> yearAndAmount.first()[i];
            std::cin >> PairArray::first()[i];
            std::cout << "Podaj liczbę butelek: ";
            std::cin >> PairArray::second()[i];
        }
        while (std::cin.get() != '\n')
        	continue;
    } else
        std::cout << "Brak butelek do wprowadzenia\n";
}
const std::string & Wine::label() const {
	return (const std::string &) *this;
}
int Wine::sum() const {
	return PairArray::second().sum();
}
void Wine::show() const {
	std::cout << "Wino: " << (const std::string &) *this << '\n';
	if (year_n > 0) {
		std::cout << '\t';
		std::cout << "Rocznik\t";
		std::cout << "Butelki\n";
		for (int i = 0; i < year_n; i++) {
			std::cout << '\t';
			// std::cout << yearAndAmount.first()[i];
			std::cout << PairArray::first()[i];
			std::cout << '\t';
			std::cout << PairArray::second()[i];
			std::cout << '\n';
		}
	}
}
