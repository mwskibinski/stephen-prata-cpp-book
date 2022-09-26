#include <iostream>
#include <cstring>
#include "bank_account.h"

BankAccount::BankAccount(const char * name_init, const char * bank_num_init, double balance_init) {
	strncpy(name, name_init, NAME_LEN-1);
	name[NAME_LEN-1] = '\0';
	strncpy(bank_num, bank_num_init, BANK_NUM_LEN-1);
	bank_num[BANK_NUM_LEN-1] = '\0';
	balance = balance_init;
}
BankAccount::~BankAccount() {

}
void BankAccount::show() const {
	std::cout << "--- show():\n";
	std::cout <<
		"Nazwisko: " << name << "\n" <<
		"Numer konta: " << bank_num << "\n" <<
		"Saldo: " << balance << "\n";
}
void BankAccount::acquire(double money) {
	if (money < 0)
		std::cout << "Błąd: pieniądze nie mogą przyjmować wartości ujemnych\n";
	else
		balance += money;
}
void BankAccount::spend(double money) {
	if (money < 0.0)
		std::cout << "Błąd: pieniądze nie mogą przyjmować wartości ujemnych\n";
	else if (money > balance)
		std::cout << "Nie masz tyle pieniędzy!\n";
	else
		balance -= money;
}
