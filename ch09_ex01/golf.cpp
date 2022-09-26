#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc) {
	strncpy(g.fullname, name, Len);
	g.handicap = hc;
}
int setgolf(golf & g) {
	using namespace std;

	cout << "Podaj nazwisko: ";
	cin.getline(g.fullname, Len);
	if (!strcmp(g.fullname, ""))
		return 0;

	cout << "Podaj handicap: ";
	while (!(cin >> g.handicap)) {
		cin.clear();
		while (cin.get() != '\n')
			;
		cout << "Nieprawidłowa wartość. Jeszcze raz, podaj handicap: ";
	}
	cin.get();

	return 1;
}
void handicap(golf & g, int hc) {
	g.handicap = hc;
}
void showgolf(const golf & g) {
	using std::cout;
	using std::endl;
	// cout << "--- Struktura golf:\n";
	cout << "Nazwisko: " << g.fullname << endl;
	cout << "Handicap: " << g.handicap << endl;
}
