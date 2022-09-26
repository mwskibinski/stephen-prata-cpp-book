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
	string filename;
	// filename = "donorsFile_err.txt";
	cout << "Podaj nazwę pliku do odczytu: ";
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

	int i;
	for (i = 0; i < donor_n; i++) {
		getline(file, donors[i].name);
		if (!file.good()) {
			i--;
			break;
		}
		(file >> donors[i].amount).get();
		if (!file.good()) {
			i--;
			break;
		}
	}
	donor_n = i;

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
