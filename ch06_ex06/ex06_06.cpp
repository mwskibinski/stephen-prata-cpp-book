#include <iostream>
#include <string>

using namespace std;

int main() {
	struct Donors {
		string name;
		double amount;
	};

	cout << "*** Towarzystwo na Rzecz Zachowania Dobrych Wpływów ***\n";
	cout << "Podaj liczbę wpłacających: ";
	int donor_n;
	(cin >> donor_n).get();

	Donors * donors = new Donors [donor_n];

	for (int i = 0; i < donor_n; i++) {
		cout << "- Donator nr " << i+1 << ":\n";
		cout << "Nazwisko: ";
		getline(cin, donors[i].name);
		cout << "Kwota: ";
		(cin >> donors[i].amount).get();
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
