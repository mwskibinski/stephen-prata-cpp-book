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

	unsigned * greatDonorsIdx = new unsigned [donor_n];
	unsigned * notGreatDonorsIdx = new unsigned [donor_n];
	unsigned greatDonors_n = 0, notGreatDonors_n = 0;

	for (int i = 0; i < donor_n; i++) {
		cout << "- Donator nr " << i+1 << ":\n";
		cout << "Nazwisko: ";
		getline(cin, donors[i].name);
		cout << "Kwota: ";
		(cin >> donors[i].amount).get();

		if (donors[i].amount >= 10000)
			greatDonorsIdx[greatDonors_n++] = i;
		else
			notGreatDonorsIdx[notGreatDonors_n++] = i;
	}

	cout << "\nNasi Wspaniali Sponsorzy:\n";
	if (greatDonors_n == 0)
		cout << "brak\n";
	else
		for (int i = 0; i < greatDonors_n; i++) {
			cout << " -- Donator:\n";
			cout << "Nazwisko: " << donors[greatDonorsIdx[i]].name << endl;
			cout << "Kwota: " << donors[greatDonorsIdx[i]].amount << endl;
		}

	cout << "\nNasi Sponsorzy:\n";
	if (notGreatDonors_n == 0)
		cout << "brak\n";
	else
		for (int i = 0; i < notGreatDonors_n; i++) {
			cout << " -- Donator:\n";
			cout << "Nazwisko: " << donors[notGreatDonorsIdx[i]].name << endl;
			cout << "Kwota: " << donors[notGreatDonorsIdx[i]].amount << endl;
		}

	delete [] donors;
	delete [] greatDonorsIdx;
	delete [] notGreatDonorsIdx;

	return 0;
}
