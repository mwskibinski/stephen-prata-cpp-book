#include <iostream>
#include "winec.h"

int main() {
	using std::cout;
	using std::endl;
	using std::cin;

	cout << "Podaj nazwę wina: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Podaj liczbę roczników: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.getBottles();
	holding.show();

	const int YRS = 3;
	int y[YRS] = {1993, 1995, 1998};
	int b[YRS] = {48, 60, 72};

	Wine more("Gushing Grape Red", YRS, y, b);
	more.show();

	cout << "Łączna liczba butelek wina " << more.label()
		<< ": " << more.sum() << endl;

	cout << "Koniec\n";

	return 0;
}
