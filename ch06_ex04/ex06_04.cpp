#include <iostream>

using namespace std;

void menu();

int main() {
	const int strsize = 100, DataSize = 5;
	struct zpdw {
		char imie[strsize];
		char stanowisko[strsize];
		char pseudozpdw[strsize];
		int preferencje;
	};
	enum pref { Imie, Stanowisko, Pseudozpdw };

	zpdw data[DataSize] = {
		{"Janusz Szunaj", "Kierowca TIR-a", "yanoosh666", Imie},
		{"John D. Carmack II", "Programista C++", "johnC", Stanowisko},
		{"G. W. H. Bush", "Prezydent USA", "GWHB", Pseudozpdw},
		{"Szczepan Agaton Marcepan-Baton", "Woźny w szkole podstawowej", "superPartia000", Stanowisko},
		{"Teodor Rodoet", "Saper", "AllRRRR!@2", Imie}
	};

	cout << "*** Zakon Programistów Dobrej Woli ***\n";

	char choice = 0;
	while (choice != 'q') {
		menu();

		for (choice = 0; choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'q'; ) {
			cout << "Wybierz jedną z opcji: ";
			cin.get(choice);
			while (choice != '\n' && cin.get() != '\n')
				;
		}

		switch (choice) {
		case 'a':
			cout << "\n";
			for (int i = 0; i < DataSize; i++)
				cout << data[i].imie << endl;
			cout << "\n";
			break;
		case 'b':
			cout << "\n";
			for (int i = 0; i < DataSize; i++)
				cout << data[i].stanowisko << endl;
			cout << "\n";
			break;
		case 'c':
			cout << "\n";
			for (int i = 0; i < DataSize; i++)
				cout << data[i].pseudozpdw << endl;
			cout << "\n";
			break;
		case 'd':
			cout << "\n";
			for (int i = 0; i < DataSize; i++) {
				if (data[i].preferencje == Imie)
					cout << data[i].imie << endl;
				else if (data[i].preferencje == Stanowisko)
					cout << data[i].stanowisko << endl;
				else
					cout << data[i].pseudozpdw << endl;
			}
			cout << "\n";
			break;
		default:
			break;
		}
	}

	return 0;
}

void menu() {
	cout << "a. lista wg imion\tb. lista wg stanowisk\n"
		<< "c. lista wg pseudonimów\td. lista wg preferencji\n"
		<< "q. koniec\n";
}
