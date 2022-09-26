#include <iostream>
#include "stonewt.h"

int main() {
	using namespace std;

	const int ARR_SIZE = 6;
	Stonewt arr[ARR_SIZE] = {Stonewt(40, 5), Stonewt(73), Stonewt(0, 1)};
	double lbs_init;

	cout << "Zainicjalizuj w funtach trzy ostatnie elementy tablicy obiektów Stonewt.\n";
	for (int i = ARR_SIZE - 3; i < ARR_SIZE; i++) {
		cout << i << ": ";
		cin >> lbs_init;
		arr[i] = Stonewt(lbs_init);
	}

	cout << "\n*** Tablica:\n";
	for (int i = 0; i < ARR_SIZE; i++)
		cout << "arr[" << i << "] = " << arr[i] << endl;

	cout << "\n***\n";
	int idx_max, idx_min, greaterThan11_n;
	idx_max = idx_min = greaterThan11_n = 0;
	Stonewt elevenLbs = 11;
	for (int i = 0; i < ARR_SIZE; i++) {
		// Czy każdorazowo tworzyć Stonewt(11) ?
		// if (arr[i] > Stonewt(11))
		if (arr[i] > elevenLbs)
			greaterThan11_n++;

		// Nadmiarowo, dla i == 0.
		if (arr[i] > arr[idx_max])
			idx_max = i;
		else if (arr[i] < arr[idx_min])
			idx_min = i;
	}

	cout << "max: " << arr[idx_max] << endl;
	cout << "min: " << arr[idx_min] << endl;
	cout << "większych niż 11 funtów: " << greaterThan11_n << endl;

	return 0;
}
