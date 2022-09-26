#include <iostream>

const int Max = 5;

double * const fill_array(double ar[], int limit);
void show_array(const double * begin, const double * const);
void revalue(double r, double * begin, double * const);

int main() {
	using namespace std;
	double properties[Max];

	double * const arr_end = fill_array(properties, Max);
	show_array(properties, arr_end);
	if (arr_end > properties) {
		cout << "Podaj czynnik zmiany wartości: ";
		double factor;
		while (!(cin >> factor)) {
			cin.clear();
			while (cin.get() != '\n')
				;
			cout << "Niepoprawna wartość; podaj liczbę: ";
		}
		revalue(factor, properties, arr_end);
		show_array(properties, arr_end);
	}
	cout << "Gotowe.\n";

	return 0;
}

double * const fill_array(double ar[], int limit) {
	using namespace std;

	double temp;
	int i;
	for (i = 0; i < limit; i++) {
		cout << "Podaj wartość nr " << (i+1) << ": ";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Błędne dane, wprowadzanie danych przerwane.\n";
			break;
		} else if (temp < 0)
			break;
		ar[i] = temp;
	}

	return ar+i;
}
void show_array(const double * begin, const double * const end) {
	using namespace std;
	for (int i = 0; begin < end; begin++, i++) {
		cout << "Nieruchomość nr " << i+1 << ": ";
		cout << *begin << endl;
	}
}
void revalue(double r, double * begin, double * const end) {
	for ( ; begin < end; begin++)
		*begin *= r;
}
