#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf() {
	using namespace std;

	char fullname_tmp[Len];
	cout << "Podaj nazwisko: ";
	cin.getline(fullname_tmp, Len);

	int handicap_tmp;
	cout << "Podaj handicap: ";
	while (!(cin >> handicap_tmp)) {
		cin.clear();
		while (cin.get() != '\n')
			;
		cout << "Nieprawidłowa wartość. Jeszcze raz, podaj handicap: ";
	}
	cin.get();

	*this = Golf(fullname_tmp, handicap_tmp);
}
Golf::Golf(const char * name, int hc) {
	strncpy(fullname, name, Len-1);
	fullname[Len-1] = '\0';
	handicap = hc;
}
Golf::~Golf() {

}
void Golf::setHandicap(int hc) {
	handicap = hc;
}
void Golf::show() const {
	using std::cout;
	using std::endl;
	// cout << "--- Struktura golf:\n";
	cout << "Nazwisko: " << fullname << endl;
	cout << "Handicap: " << handicap << endl;
}

