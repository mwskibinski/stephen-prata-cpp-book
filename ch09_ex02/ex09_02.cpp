#include <iostream>

void strcount(const std::string * str);

int main() {
	using namespace std;
	string input;

	cout << "Wprowadź wiersz:\n";
	while (getline(cin, input) && input != "") {
		strcount(&input);
		cout << "Wprowadź następny wiersz (wiersz pusty kończy wprowadzanie):\n";
	}
	cout << "Koniec\n";

	return 0;
}

void strcount(const std::string * str) {
	using namespace std;
	static int total = 0;
	int count = 0;

	cout << "\"" << *str << "\" zawiera ";
	for (int i = 0; i < str->size(); i++)
		count++;
	total += count;
	cout << count << " znaków\n";
	cout << "Łącznie " << total << " znaków\n";
}
