#include <iostream>
#include "plorg.h"

int main() {
	using namespace std;

	cout << "\tKonstruktory:\n";
	Plorg ziemowit("Ziemowit");
	Plorg def;
	Plorg plorgiusPlorgson("Plorgius Plorgson");
	// Plorg plorgiusPlorgson("Plorgius Plorgson-Plorgberg");

	cout << "\tMetoda print:\n";
	ziemowit.print();
	def.print();
	plorgiusPlorgson.print();

	cout << "\tMetoda changeSatiety:\n";
	ziemowit.changeSatiety(5);
	def.changeSatiety(999);
	plorgiusPlorgson.changeSatiety(-1);

	cout << "\tMetoda print:\n";
	ziemowit.print();
	def.print();
	plorgiusPlorgson.print();

	return 0;
}
