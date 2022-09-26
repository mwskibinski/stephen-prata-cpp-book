#include <iostream>
#include <fstream>
#include "emp.h"
#include <cstring>

int main() {
	using namespace std;

	const int MAX = 10;
	AbstrEmp * pc[MAX] {};
	int pc_n = 0;

	const char * filename = "data_file.txt";
	fstream file(filename, ios_base::in | ios_base::out);

	int classtype;
	char ch;
	while ((file >> classtype).get(ch)) {
		switch (classkind(classtype)) {
		case classkind::Employee:
			pc[pc_n] = new Employee;
			break;
		case classkind::Manager:
			pc[pc_n] = new Manager;
			break;
		case classkind::Fink:
			pc[pc_n] = new Fink;
			break;
		case classkind::HighFink:
			pc[pc_n] = new HighFink;
			break;
		default:
			break;
		}
		pc[pc_n++]->getAll(file);
	}

	if (pc_n > 0) {
		cout << "--- Aktualna zawartość pliku:\n";
		for (int i = 0; i < pc_n; i++) {
			pc[i]->showAll();
			cout << endl;
		}
	}

	file.clear();

	cout << "--- Wprowadzanie danych:\n";
	char choice;
	int n = 0;
	while (n < 10) {
		cout << "\te: Employee, m: Manager, f: Fink, h: Highfink;   x - wyjście\n> ";
		cin >> choice;
		while (!strchr("emfhxEMFHX", choice)) {
			while (cin.get() != '\n')
				continue;
			cout << "Niepoprawna opcja. Wprowadź ponownie.\n> ";
			cin >> choice;
		}

		if (choice == 'x' || choice == 'X')
			break;

		cin.get();
		switch (choice) {
			case 'e': case 'E':
				pc[n] = new Employee;
				break;
			case 'm': case 'M':
				pc[n] = new Manager;
				break;
			case 'f': case 'F':
				pc[n] = new Fink;
				break;
			case 'h': case 'H':
				pc[n] = new HighFink;
				break;
			default:
				break;
		}
		pc[n++]->setAll();
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		pc[i]->writeAll(file);
		delete pc[i];
	}

	file.close();

	return 0;
}
