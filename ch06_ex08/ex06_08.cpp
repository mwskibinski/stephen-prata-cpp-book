#include <iostream>
#include <fstream>

using namespace std;

int main() {
	cout << "Podaj nazwę pliku do odczytu: ";
	string filename;
	// Zakładam że nazwa pliku może mieć spacje.
	// filename = "readFile.txt";
	getline(cin, filename);

	ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		cout << "Nie można otworzyć pliku o tej nazwie\n";
		exit(EXIT_FAILURE);
	}

	// Zakładam, że chodzi o jakikolwiek znak
	unsigned char_n = 0;
	while (file.get() != EOF)
		char_n++;
	char ch;
//	while (file.get(ch) && !file.eof())
//		char_n++;

	cout << "\nLiczba znaków: " << char_n << endl;

	return 0;
}
