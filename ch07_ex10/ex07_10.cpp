#include <iostream>

using namespace std;

double calculate(double, double, double (*)(double, double));
double add(double, double);
double sub(double, double);
double mult(double, double);
double div(double, double);

int main() {
 	const int Func_n = 4;
 	double (*calc_func_arr[Func_n])(double, double) = {add, sub, mult, div};
 	const char * func_names[Func_n] = {"add", "sub", "mult", "div"};

	double num1, num2;
	cout << "*** Wprowadź dwie liczby, znak niebędący liczbą kończy\n> ";
	while (cin >> num1 >> num2) {
		for (int i = 0; i < Func_n; i++)
			cout << func_names[i] << ": " << calculate(num1, num2, calc_func_arr[i]) << endl;
		cout << "*** Wprowadź kolejne dwie liczby\n> ";
	}

	return 0;
}

double calculate(double n1, double n2, double (*calc_f)(double, double)) {
	return calc_f(n1, n2);
}
double add(double n1, double n2) {
	return n1 + n2;
}
double sub(double n1, double n2) {
	return n1 - n2;
}
double mult(double n1, double n2) {
	return n1 * n2;
}
double div(double n1, double n2) {
	if (n2 == 0.0) {
		cout << "Błąd. Mianownik nie może być zerem. Zwracam liczbę 0.\n";
		return 0.0;
	}
	return n1 / n2;
}
