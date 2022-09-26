#include <iostream>
#include <string>

bool isPalindrom(const std::string & word);
bool isPalindrom_2(const std::string & word);

int main() {
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;

	string word;

	cout << "Podaj słowo (\"koniec\" by skończyć)\n> ";
	while (cin >> word && word != "koniec") {
		if (isPalindrom_2(word))
			cout << "\tTAK, to słowo to palindrom.\n";
		else
			cout << "\tNIE, to słowo nie jest palindromem.\n";

		cout << "Podaj kolejne słowo (\"koniec\" by skończyć)\n> ";
	}

	return 0;
}

bool isPalindrom(const std::string & word) {
	int n = word.size() / 2;

	for (int i = 0; i < n; i++) {
		if (*(word.begin() + i) != *(word.end() - i - 1))
			return false;
	}
	return true;
}

bool isPalindrom_2(const std::string & word) {
	int n = word.size() / 2;
	auto front = word.cbegin();
	auto back = word.crbegin();

	for (int i = 0; i < n; i++) {
		if (*front++ != *back++)
			return false;
	}
	return true;
}
