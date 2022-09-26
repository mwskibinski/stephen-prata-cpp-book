#include <iostream>
#include <cmath>
#include "exc.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "Podaj dwie liczby: ";
	while (cin >> x >> y) {
		try {
			z = hmean(x, y);
			cout << "Średnia harmoniczna liczb " << x << " i " << y
				<< " wynosi " << z << endl;
			cout << "Średnia geometryczna liczb " << x << " i " << y
				<< " wynosi " << gmean(x, y) << endl;
			cout << "Podaj kolejną parę liczb <w, aby wyjść>: ";
		} catch (bad_mean & bm) {
			cout << bm.what() << endl;
			cout << "Funkcja: " << bm.get_funcName() << endl;
			cout << "Argumenty funkcji: " << bm.get_v1()
				<< ", " << bm.get_v2() << endl;
			cout << "To koniec.\n";
			break;
		}
	}
	cout << "Koniec\n";

	return 0;
}

double hmean(double a, double b) {
	if (a == -b)
		throw bad_hmean(
			"*** Wyjątek. Funkcja: hmean. Błąd: a nie może równać się -b",
			a, b
		);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
	if (a < 0 || b < 0)
		throw bad_gmean(
			"*** Wyjątek. Funkcja: gmean. Błąd: argumenty nie mogą być ujemne",
			a, b
		);
	return std::sqrt(a * b);
}
