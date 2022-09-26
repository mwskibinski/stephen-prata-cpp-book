#include <iostream>
#include "cow.h"

int main() {
	using std::cout;
	using std::endl;

	cout << "\tDeklaracja kilku obiektów.\n";
	Cow arthur("Artur", "Muczenie", 250.5);
	Cow def;
	Cow thomas("Tomasz", "Fizyka kwantowa", 345.34);
	Cow cowboy("Kowboj", "Ornitologia", 911.666);
	cout << endl;

	cout << "\tPrezentacja danych początkowych.\n";
	arthur.showCow();
	def.showCow();
	thomas.showCow();
	cowboy.showCow();
	cout << endl;

	cout << "\tUżycie konstruktora kopiującego.\n";
	Cow tom(thomas);
	tom.showCow();
	cout << endl;

	cout << "\tUżycie operator przypisania.\n";
	def = arthur;
	def.showCow();
	cout << endl;

	cout << "\tUżycie wskaźników.\n";
	Cow * theodoreRoosevelt = new Cow("Theodore Roosevelt", "Historia Stanów Zjednoczonych", 999.88);
	theodoreRoosevelt->showCow();
	cout << endl;

	cout << "\tKonstruktor kopiujący.\n";
	Cow * roosevelt = new Cow(*theodoreRoosevelt);
	roosevelt->showCow();
	cout << endl;

	delete theodoreRoosevelt;
	delete roosevelt;

	return 0;
}
