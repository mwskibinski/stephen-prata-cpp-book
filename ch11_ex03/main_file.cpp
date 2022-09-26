#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"
#include <cmath>

int main() {
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));

	double target;
	cout << "Podaj dystans: ";
	cin >> target;
	double dstep;
	cout << "Podaj długość kroku: ";
	cin >> dstep;
	unsigned tries;
	cout << "Podaj liczbę prób: ";
	cin >> tries;

	if (tries == 0u) {
		cout << "*********************\n";
		cout << "Brak prób\nKończę\n";
		return 0;
	}
//	if (tries == 0u)
//		return cout << "*********************\n" << "Brak prób\nKończę\n", 0;

	Vector result;
	unsigned long steps_i = 0ul, max = 0ul, min = 0ul;
	double avg = 0.0;

	// Próba pierwsza. Przypadek szczególny, gdyż należy zainicjalizować wartości max, min, a nie chcę dawać w pętli niepotrzebnych warunków.
	{ // proba == 0u
		while (result.magval() < target) {
			result = result + Vector(dstep, rand() % 360, Vector::POL);
			steps_i++;
		}
		avg += double (steps_i) / tries;
		max = min = steps_i++;

		steps_i = 0ul;
		result.reset(0, 0);
	}

	// Próby kolejne.
	for (unsigned tr = 1u; tr < tries; tr++) {
		while (result.magval() < target) {
			result = result + Vector(dstep, rand() % 360, Vector::POL);
			steps_i++;
		}
		avg += double (steps_i) / tries;
		if (steps_i > max)
			max = steps_i;
		else if (steps_i < min)
			min = steps_i;

		steps_i = 0ul;
		result.reset(0, 0);
	}

	cout << "*********************\n";
	cout << "Maksymalna liczba kroków:\n\t" << max << endl;
	cout << "Minimalna liczba kroków:\n\t" << min << endl;
	cout << "Średnia liczba kroków:\n\t" << avg << endl;
	cout << "Liczba kroków ze wzoru N = (D/s)^2:\n\t" << pow(target / dstep, 2.0) << endl;

	return 0;
}
