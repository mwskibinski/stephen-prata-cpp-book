#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cctype>
#include <cstdlib>

int main() {
	using std::cout;
	using std::cin;
	using std::endl;
	using std::vector;
	using std::string;

	std::fstream input;
	input.open("ex16_03_words.txt");
	if (!input.is_open()) {
		std::cerr << "Nie można otworzyć podanego pliku.\n";
		return -1;
	}

	string word;
	vector<string> wordlist;
	while (input >> word)
		wordlist.push_back(word);
	int word_n = wordlist.size();

	std::srand(std::time(0));
	char play;
	cout << "Czy chcesz zagrać w grę słowną? <t/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 't') {
		string target = wordlist[std::rand() % word_n];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;

		cout << "Zgadnij moje sekretne słowo. Ma ono " << length
			<< " liter. Możesz zgadywać\n"
			<< "po jednej literze naraz. Możesz pomylić się " << guesses
			<< " razy.\n";

		cout << "*** Twoje słowo: " << attempt << endl;
		while (guesses > 0 && attempt != target) {
			char letter;
			cout << "Zgadnij literę: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "Ta litera już była. Spróbuj innej.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos) {
				cout << "Nie ma takiej litery!\n";
				--guesses;
				badchars += letter;
			} else {
				cout << "Poprawna litera!\n";
				attempt[loc] = letter;

				while ((loc = target.find(letter, loc + 1)) != string::npos)
					attempt[loc] = letter;
			}
			cout << "*** Twoje słowo: " << attempt << endl;
			if (attempt != target) {
				if (badchars.length() > 0)
					cout << "Niepoprawne litery: " << badchars << endl;
				cout << "Możesz pomylić się jeszcze " << guesses << " razy\n";
			}
		}
		if (guesses > 0)
			cout << "To już całe słowo!\n";
		else
			cout << "Niestety, to słowo to " << target << ".\n";

		cout << "Czy chcesz zagrać jeszcze raz? <t/n> ";
		cin >> play;
		play = tolower(play);
	}
	cout << "Koniec\n";


	return 0;
}
