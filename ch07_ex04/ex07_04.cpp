#include <iostream>

long double probability(unsigned, unsigned, unsigned);

int main() {
	using namespace std;

	double total, choices, total2;
	cout << "Podaj największą liczbę, jaką można wybrać, liczbę skreśleń\n"
		"oraz dodatkową największa liczbę z dodatkowego zbioru:\n";
	while ((cin >> total >> choices >> total2) && choices <= total) {
		cout << "Szansa wybranej to jeden do ";
		cout << probability(total, choices, total2);
		cout << ".\n";
		cout << "Następne trzy liczby (q, aby zakończyć): ";
	}
	cout << "Do widzenia.\n";

	return 0;
}

long double probability(unsigned numbers, unsigned picks, unsigned numbers2) {
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n/p;
	result = result * numbers2;

	return result;
}
