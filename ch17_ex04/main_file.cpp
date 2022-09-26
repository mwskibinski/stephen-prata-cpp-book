#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "Błąd: niepoprawna ilość argumentów.\n"
			<< "arg1 -- plik wejściowy 1, arg2 -- plik wejściowy 2, arg3 -- plik wyjściowy.\n";
		return -1;
	}

	std::ifstream fin1(argv[1]), fin2(argv[2]);
	std::ofstream fout(argv[3]);

	if (!fin1.is_open()) {
		std::cerr << "Błąd: nie można otworzyć pliku wejściowego o nazwie " << argv[1] << '\n';
		return -1;
	}
	if (!fin2.is_open()) {
		std::cerr << "Błąd: nie można otworzyć pliku wejściowego o nazwie " << argv[2] << '\n';
		return -1;
	}
	if (!fout.is_open()) {
		std::cerr << "Błąd: nie można otworzyć pliku wyjściowego o nazwie " << argv[3] << '\n';
		return -1;
	}

//	std::string line1, line2;
//	while (fin1 || fin2) {
//		getline(fin1, line1);
//		getline(fin2, line2);
//
//		fout << line1;
//		if (fin1 && fin2)
//			fout << ' ';
//		fout << line2;
//		if (fin1 || fin2)
//			fout << '\n';
//	}

//	std::string line1, line2;
//	getline(fin1, line1);
//	getline(fin2, line2);
//	while (fin1 || fin2) {
//		fout << line1;
//		if (fin1 && fin2)
//			fout << ' ';
//		fout << line2;
//		fout << '\n';
//
//		getline(fin1, line1);
//		getline(fin2, line2);
//	}

//	std::string line1, line2;
//	getline(fin1, line1);
//	getline(fin2, line2);
//	while (fin1 && fin2) {
//		fout << line1 << ' ' << line2 << '\n';
//		getline(fin1, line1);
//		getline(fin2, line2);
//	}
//	while (fin1) {
//		fout << line1 << '\n';
//		getline(fin1, line1);
//	}
//	while (fin2) {
//		fout << line2 << '\n';
//		getline(fin2, line2);
//	}

	char c;
	while (fin1 || fin2) {
		while (fin1.get(c) && c != '\n')
			fout.put(c);
		if (fin1 && fin2.peek() != EOF)
			fout.put(' ');
		while (fin2.get(c) && c != '\n')
			fout.put(c);
		if (fin1 || fin2)
			fout.put('\n');
	}

//	char c;
//	while (fin1.peek() != EOF || fin2.peek() != EOF) {
//		while (fin1.get(c) && c != '\n')
//			fout.put(c);
//		if (fin1 && fin2.peek() != EOF)
//			fout.put(' ');
//		while (fin2.get(c) && c != '\n')
//			fout.put(c);
//		fout.put('\n');
//	}

	fin1.close();
	fin2.close();
	fout.close();

	return 0;
}
