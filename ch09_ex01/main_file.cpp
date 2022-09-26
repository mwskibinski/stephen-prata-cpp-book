#include <iostream>
#include <cstring>
#include "golf.h"

int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	const int GolfSize = 5;
	golf golf_arr[GolfSize] {};

	cout << "Wprowadź dane do maksymalnie 5 struktur 'golf'.\n";
	cout << "Pusty ciąg znaków dla nazwiska kończy wprowadzanie szybciej.\n";
	int golf_n = 0;
	while (setgolf(golf_arr[golf_n]))
		if (++golf_n >= GolfSize)
			break;

	cout << endl;
	cout << "Wprowadzone dane:\n";
	for (int i = 0; i < golf_n; i++) {
		cout << "--- Struktura nr " << i+1 << ": " << endl;
		showgolf(golf_arr[i]);
	}

	cout << endl;
	cout << "Zmiana wprowadzonych danych:\n";
	char tmp_name[Len];
	for (golf_n = 0; golf_n < GolfSize; golf_n++) {
		// setgolf(golf_arr[golf_n], "John", 0);
		strcpy(tmp_name, "John ");
		tmp_name[strlen(tmp_name)] = golf_n + '1';
		setgolf(golf_arr[golf_n], tmp_name, 0);
	}

	cout << endl;
	cout << "Wprowadzone dane:\n";
	for (int i = 0; i < golf_n; i++) {
		cout << "--- Struktura nr " << i+1 << ": " << endl;
		showgolf(golf_arr[i]);
	}

	cout << endl;
	cout << "Zmiana handicapu wprowadzonych danych:\n";
	for (golf_n = 0; golf_n < GolfSize; golf_n++)
		handicap(golf_arr[golf_n], 4*golf_n*golf_n + 8*golf_n + 2);

	cout << endl;
	cout << "Wprowadzone dane:\n";
	for (int i = 0; i < golf_n; i++) {
		cout << "--- Struktura nr " << i+1 << ": " << endl;
		showgolf(golf_arr[i]);
	}

	return 0;
}
