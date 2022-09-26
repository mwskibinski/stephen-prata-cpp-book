#include <iostream>

int main() {
	using namespace std;

	int ct = 0;
	// Wersja nr 1
//	while (cin.peek() != '$') {
//		cin.get();
//		ct++;
//	}
	// Wersja nr 2
	while (cin.get() != '$')
		ct++;
	cin.putback('$');

	cout << "liczba znaków: " << ct << endl;

	return 0;
}
