#include "stock.h"
#include <iostream>
#include <cstring>
#include <string>

Stock::Stock() {
	const char * init_name = "bez nazwy";
	company = new char [strlen(init_name) + 1];
	strcpy(company, init_name);
	share_val = total_val = 0.0;
}
Stock::Stock(const std::string & co, long n, double pr) {
	company = new char [co.length() + 1];
	for (int i = 0; company[i] = co[i]; i++)
		;

	if (n < 0) {
		std::cout << "Liczba udziałów nie może być ujemna; "
			<< "ustalam liczbę udziałów w " << company << " na 0.\n";
		shares = 0;
	} else
		shares = n;
	share_val = pr;
	set_tot();
}
Stock::Stock(const char * co, long n, double pr) {
	company = new char [strlen(co) + 1];
	strcpy(company, co);

	if (n < 0) {
		std::cout << "Liczba udziałów nie może być ujemna; "
			<< "ustalam liczbę udziałów w " << company << " na 0.\n";
		shares = 0;
	} else
		shares = n;
	share_val = pr;
	set_tot();
}
Stock::~Stock() {
	delete [] company;
}

void Stock::buy(long num, double price) {
	if (num < 0) {
		std::cout << "Liczba nabywanych udziałów nie może być ujemna. "
			<< "Transakcja przerwana.\n";
	} else {
		shares += num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(long num, double price) {
	if (num > 0) {
		std::cout << "Liczba sprzedawanych udziałów nie może być ujemna. "
			<< "Transakcja przerwana.\n";
	} else if (num > shares) {
		std::cout << "Nie możesz sprzedać więcej udziałów, niż posiadasz! "
			<< "Transakcja przerwana.\n";
	} else {
		shares -= num;
		share_val = price;
		set_tot();
	}
}
void Stock::update(double price) {
	share_val = price;
	set_tot();
}
const Stock & Stock::topval(const Stock & s) const {
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

std::ostream & operator<<(std::ostream & os, const Stock & s) {
	using std::ios_base;

	ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = os.precision(3);

	os << "Spółka: " << s.company
		<< "  Liczba udziałów: " << s.shares << '\n'
		<< "  Cena udziału: " << s.share_val << " zł";

	os.precision(2);
	os << " Łączna wartość udziałów: " << s.total_val << " zł" << '\n';

	os.setf(orig, ios_base::floatfield);
	os.precision(prec);

	return os;
}
