#include <iostream>
#include <cctype>

int main() {
	using namespace std;

	char ch;

//	while (cin.get(ch) && ch != '@') {
//		if (!isdigit(ch)) {
//			if (isupper(ch))
//				cout << char (tolower(ch));
//			else if (islower(ch))
//				cout << char (toupper(ch));
//			else
//				cout << ch;
//		}
//	}

//	while (cin.get(ch) && ch != '@') {
//		if (!isdigit(ch)) {
//			if (isupper(ch))
//				cout << char (tolower(ch));
//			else
//				cout << char (toupper(ch));
//		}
//	}

	while (cin.get(ch) && ch != '@')
		if (!isdigit(ch))
			cout << char (isupper(ch) ? tolower(ch) : toupper(ch));

	return 0;
}
