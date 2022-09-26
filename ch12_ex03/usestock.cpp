#include <iostream>
#include "stock.h"
#include <string>

const int STKS = 4;

int main() {
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("BurakPOL", 200, 2.0),
		Stock("GruzPOL", 130, 3.25),
		Stock("FutroPOL", 60, 6.5)
	};
	Stock tmp(std::string("NanoSmart"), 12, 20.0);

	std::cout << "Portfel inwestycyjny:\n";
	int st;
	for (st = 0; st < STKS; st++)
		std::cout << stocks[st];

	const Stock * top = &stocks[0];
	for (st = 0; st < STKS; st++)
		top = &top->topval(stocks[st]);

	std::cout << "\nNajbardziej wartościowy pakiet:\n";
	std::cout << *top;

	return 0;
}
