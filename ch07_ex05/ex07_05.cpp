#include <iostream>

using namespace std;

long double factorial(unsigned);

int main() {
//	unsigned limit = 30u;
//
//	for (unsigned i = 0u; i < limit; i++)
//		cout << i << ": " << factorial(i) << endl;

	int fact_n;
	cout << "Podaj liczbę, której silnie chcesz wyznaczyć (Liczba ujemna kończy): ";
	for (cin >> fact_n; fact_n > 0; cin >> fact_n) {
		cout << factorial(fact_n) << endl;
		cout << "Następna liczba: ";
	}

	return 0;
}

long double factorial(unsigned n) {
	if (n == 0u)
		return 1.0L;
	return n * factorial(n-1);
}
