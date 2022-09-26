#include <iostream>

double mean_harm(double num1, double num2);

int main() {
	using namespace std;

	double num1, num2;

	cout << "Podaj dwie liczby. Podanie 0 kończy działanie programu: ";
	while ((cin >> num1 >> num2) && num1 != 0 && num2 != 0) {
		cout << mean_harm(num1, num2) << endl;
		cout << "Następnie dwie liczby: ";
	}

	return 0;
}

double mean_harm(double num1, double num2) {
	return 2.0 * num1 * num2 / (num1 + num2);
}
