#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		std::cerr << "Błąd: pierwszy arg. to nazwa pliku wejściowego, drugi arg. to nazwa pliku wyjściowego.\n";
		return -1;
	}

	std::ifstream file_in(argv[1]);
	std::ofstream file_out(argv[2]);

	if (!file_in.is_open()) {
		std::cerr << "Nie można otworzyć pliku wejściowego o nazwie " << argv[1] << '\n';
		return -1;
	}
	if (!file_out.is_open()) {
		std::cerr << "Nie można otworzyć pliku wyjściowego o nazwie " << argv[2] << '\n';
		return -1;
	}

	char c;
	while (file_in.get(c))
		file_out.put(c);

	file_in.close();
	file_out.close();

	return 0;
}
