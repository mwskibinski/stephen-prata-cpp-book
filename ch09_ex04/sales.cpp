#include <iostream>
#include "sales.h"

namespace SALES {
	void setSales(Sales & s, const double ar[], int n) {
		int limit = n < QUARTERS ? n : QUARTERS;
		s.average = 0.0;
		s.min = s.max = limit > 0 ? ar[0] : 0.0;
		// Czy średnia powinna być wyznaczana dla wszystkich elementów tablicy sales czy tylko dla tych niezerowych?
		// Czy może źle rozumiem zadanie składowej average?
		for (int i = 0; i < limit; i++) {
			s.sales[i] = ar[i];
			s.average += s.sales[i] / limit;
			if (s.sales[i] > s.max)
				s.max = s.sales[i];
			else if (s.sales[i] < s.min)
				s.min = s.sales[i];
		}
		for (int i = limit; i < QUARTERS; i++)
			s.sales[i] = 0;
	}
	void setSales(Sales & s) {
		using namespace std;

		double ar[QUARTERS] {0.0};

		cout << "Podaj 4 wartości tablicy sales.\n";
		for (int i = 0; i < QUARTERS; i++) {
			cout << "Wartość " << i+1 << ": ";
			while (!(cin >> ar[i])) {
				cin.clear();
				while (cin.get() != '\n')
					;
				cout << "Nieprawidłowa wartość, podaj raz jeszcze. "
					<< "Wartość  " << i+1 << ": ";
			}
		}
		setSales(s, ar, QUARTERS);
	}
	void showSales(const Sales & s) {
		using namespace std;

		cout << "Tablica sales: ";
		for (int i = 0; i < QUARTERS-1; i++)
			cout << s.sales[i] << '\t';
		cout << s.sales[QUARTERS-1] << '\n';

		cout << "Wartość średnia: " << s.average << endl;
		cout << "Wartość maks.: " << s.max << endl;
		cout << "Wartość min.: " << s.min << endl;
	}
}
