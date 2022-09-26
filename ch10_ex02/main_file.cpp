#include <iostream>
#include <string>
#include "person.h"

int main() {
	Person one;
	Person two("Staszek");
	// Person three("Jacek", "Placek");
	Person three("Placek", "Jacek"); // Jeśli konstruktor najpierw bierze nazwisko, to trzeba użyć go tak.

	cout << "*** one:\n";
	one.Show();
	cout << endl;
	one.FormalShow();
	cout << endl;

	cout << "*** two:\n";
	two.Show();
	cout << endl;
	two.FormalShow();
	cout << endl;

	cout << "*** three:\n";
	three.Show();
	cout << endl;
	three.FormalShow();
	cout << endl;

	return 0;
}
