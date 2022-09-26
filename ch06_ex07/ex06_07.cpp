#include <iostream>

int main() {
	using namespace std;

	unsigned vowel_n = 0, consonant_n = 0, other_n = 0;
	bool word = false, q = false;
	char ch;

	cout << "Podawaj słowa (pojedyncze q kończy):\n";

	while (cin.get(ch)) {
		if (q) {
			if (isspace(ch)) {
				break;
			} else {
				consonant_n++;
				q = false;
			}
		} else if (!word && isgraph(ch)) {
			word = true;
			if (ch == 'q') {
				q = true;
				continue;
			} else if (isalpha(ch)) {
				switch (ch) {
				case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
				case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
					vowel_n++;
					break;
				default:
					consonant_n++;
					break;
				}
			} else {
				other_n++;
			}
		} else if (word && isspace(ch)) {
			word = false;
		}
	}

	cout << consonant_n << " słów zaczyna się od spółgłosek." << endl;
	cout << vowel_n << " słów zaczyna się od samogłosek." << endl;
	cout << other_n << " słów nie zalicza się do żadnej z tych kategorii." << endl;

	return 0;
}
