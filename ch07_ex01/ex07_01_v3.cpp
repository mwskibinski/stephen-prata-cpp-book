#include <iostream>

double mean_harm(double num1, double num2);

int main() {
	using namespace std;

	double num1 = -1, num2 = -1;

	cout << "Podaj dwie liczby. Podanie 0 kończy działanie programu: ";
	while (true) {
		cin >> num1;
		if (cin && num1 == 0)
			break;
		cin >> num2;
		if (cin && num2 == 0)
			break;

		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				;
			cout << "Podano błędne dane. Spróbuj ponownie: ";
		} else {
			cout << mean_harm(num1, num2) << endl;
			cout << "Następnie dwie liczby: ";
		}
	}

	return 0;
}

double mean_harm(double num1, double num2) {
	return 2.0 * num1 * num2 / (num1 + num2);
}
