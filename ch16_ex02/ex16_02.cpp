#include <iostream>
#include <string>
#include <cctype>

bool isPalindrom(const std::string & word);
bool isPalindrom_2(const std::string & word);
std::string & prepare(std::string & word);

int main() {
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;

	string word;

	cout << "Podaj słowo (\"koniec\" by skończyć)\n> ";
	while (getline(cin, word) && word != "koniec") {
		cout << "init: " << word << '\n';
		cout << "prep: " << prepare(word) << '\n';

		if (isPalindrom_2(prepare(word)))
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

std::string & prepare(std::string & word) {
	std::string prep(word.size(), 0);
	auto prep_ptr = prep.begin();

	for (const auto & ch : word)
		if (!std::isspace(ch))
			*prep_ptr++ = std::tolower(ch);
	prep.erase(prep_ptr, prep.end());

	word = prep;

	return word;
}
