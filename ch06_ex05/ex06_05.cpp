#include <iostream>

int main() {
	using namespace std;

	double podatek1, podatek2, podatek3, podatek4;
	double number;

	// cout << "Podaj swój dochód w twarpach: ";
	// while (cin >> number && number >= 0.0) {
	for (cout << "Podaj swój dochód w twarpach: ";
		cin >> number && number >= 0.0;
		cout << "Podaj swój dochód w twarpach: ")
	{
		podatek1 = number > 5000 ? 5000 : number;
		podatek2 = number > 15000 ? 10000 : number - podatek1;
		podatek3 = number > 35000 ? 20000 : number - (podatek2 + podatek1);
		podatek4 = number - (podatek3 + podatek2 + podatek1);

		cout << "Twój podatek: "
			<< podatek1 * 0.0 + podatek2 * 0.1 + podatek3 * 0.15 + podatek4 * 0.2
			<< " twarpów" << endl;

		// cout << "Podaj swój dochód w twarpach: ";
	}

	return 0;
}
