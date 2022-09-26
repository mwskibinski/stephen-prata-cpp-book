#include <iostream>
#include "bank_account.h"

int main() {
	BankAccount ba1("Tomasz Szamot", "0123 4567 0000 4444 0420", 1000.00);
	BankAccount ba2("Michał Łachim", "1111 2222 3333 4444 5555");
	BankAccount ba3("Robert Trebor");
	BankAccount ba4;

	ba1.show();
	ba2.show();
	ba3.show();
	ba4.show();

	std::cout << std::endl;

	ba1.acquire(0.0);
	ba1.show();
	ba1.acquire(123.00);
	ba1.show();
	ba1.acquire(765.50);
	ba1.show();
	ba1.acquire(-45);
	ba1.show();

	std::cout << std::endl;

	ba1.spend(20.0);
	ba1.show();
	ba1.spend(40.00);
	ba1.show();
	ba1.spend(-65.43);
	ba1.show();
	ba1.spend(100);
	ba1.show();

	return 0;
}
