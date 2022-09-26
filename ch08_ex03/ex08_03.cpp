#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

const std::string & stringToUpper(std::string & str);

int main() {
	std::string txt;

	cout << "Podaj łańcuch (q, aby skończyć): ";
	while (getline(cin, txt) && txt != "q") {
		cout << stringToUpper(txt) << endl;
		cout << "Następny łańcuch (q, aby skończyć): ";
	}

	return 0;
}

const std::string & stringToUpper(std::string & str) {
	for (int i = 0; i <= str.size(); i++)
		str[i] = toupper(str[i]);
	return str;
}
