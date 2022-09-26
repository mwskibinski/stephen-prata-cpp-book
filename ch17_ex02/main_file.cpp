#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
	if (argc == 0) {
		std::cerr << "Błąd: brak nazwy pliku do zapisu.\n";
		return -1;
	}

	std::ofstream file_out(argv[1]);
	if (!file_out.is_open()) {
		std::cerr << "Błąd: nie można otworzyć pliku o nazwie " << argv[1] << '\n';
		return -1;
	}

//	int ch;
//	while ((ch = std::cin.get()) != EOF)
//		file_out.put(ch);
	char ch;
	while (std::cin.get(ch))
		file_out.put(ch);

	file_out.close();

	return 0;
}
