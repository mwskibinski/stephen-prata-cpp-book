#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	struct Donors {
		string name;
		double amount;
	};

	cout << "*** Towarzystwo na Rzecz Zachowania Dobrych Wpływów ***\n";
	cout << "Podaj nazwę pliku do odczytu: ";
	string filename;
	getline(cin, filename);

	ifstream file;
	file.open(filename);

	if (!file.is_open()) {
		cout << "Nie można otworzyć pliku o nazwie \"" << filename << "\".\n";
		exit(EXIT_FAILURE);
	}

	int donor_n = 0;
	(file >> donor_n).get();
	Donors * donors = new Donors [donor_n];

	for (int i = 0; i < donor_n; i++) {
		getline(file, donors[i].name);
		(file >> donors[i].amount).get();
	}

	cout << "\nNasi Wspaniali Sponsorzy:\n";
	bool noSuchDonors = true;
	for (int i = 0; i < donor_n; i++) {
		if (donors[i].amount >= 10000) {
			cout << " -- Donator:\n";
			cout << "Nazwisko: " << donors[i].name << endl;
			cout << "Kwota: " << donors[i].amount << endl;
			noSuchDonors = false;
		}
	}
	if (noSuchDonors)
		cout << "brak\n";

	cout << "\nNasi Sponsorzy:\n";
	noSuchDonors = true;
	for (int i = 0; i < donor_n; i++) {
		if (donors[i].amount < 10000) {
			cout << " -- Donator:\n";
			cout << "Nazwisko: " << donors[i].name << endl;
			cout << "Kwota: " << donors[i].amount << endl;
			noSuchDonors = false;
		}
	}
	if (noSuchDonors)
		cout << "brak\n";

	delete [] donors;

	return 0;
}
