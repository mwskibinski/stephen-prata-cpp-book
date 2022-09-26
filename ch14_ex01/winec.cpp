#include "winec.h"
#include <iostream>

Wine::Wine(const char * l, int y)
    : name(l), year_n(y), yearAndAmount(ArrayInt(0, y), ArrayInt(0, y))
{}

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
    : name(l), year_n(y), yearAndAmount(ArrayInt(yr, y), ArrayInt(bot, y))
{}

void Wine::getBottles() {
    if (year_n > 0) {
        std::cout << "Podaj dane o winie " << name << " dla " << year_n << " roczników:\n";
        for (int i = 0; i < year_n; i++) {
            std::cout << "Podaj rocznik: ";
            std::cin >> yearAndAmount.first()[i];
            std::cout << "Podaj liczbę butelek: ";
            std::cin >> yearAndAmount.second()[i];
        }
        while (std::cin.get() != '\n')
        	continue;
    } else
        std::cout << "Brak butelek do wprowadzenia\n";
}
const std::string & Wine::label() const {
	return name;
}
int Wine::sum() const {
	return yearAndAmount.second().sum();
}
void Wine::show() const {
	std::cout << "Wino: " << name << '\n';
	if (year_n > 0) {
		std::cout << '\t';
		std::cout << "Rocznik\t";
		std::cout << "Butelki\n";
		for (int i = 0; i < year_n; i++) {
			std::cout << '\t';
			std::cout << yearAndAmount.first()[i];
			std::cout << '\t';
			std::cout << yearAndAmount.second()[i];
			std::cout << '\n';
		}
	}
}
