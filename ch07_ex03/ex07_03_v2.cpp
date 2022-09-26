#include <iostream>

struct pudlo {
	char producent[40];
	float wysokosc;
	float szerokosc;
	float dlugosc;
	float objetosc;
};

void print_pudlo(pudlo);
void calc_volume(pudlo *);

int main() {
	std::cout << "Wprowadź parametry swojego pudełka.\n";
	pudlo box;
	std::cout << "Producent: ";
	std::cin.getline(box.producent, 40);

	std::cout << "Wysokość: ";
	std::cin >> box.wysokosc;
	while (!std::cin || box.wysokosc < 0.0) {
		std::cin.clear();
		while (std::cin.get() != '\n')
			;
		std::cout << "Nieprawidłowe dane. Raz jeszcze. Wysokość: ";
		std::cin >> box.wysokosc;
	}

	std::cout << "Szerokość: ";
	std::cin >> box.szerokosc;
	while (!std::cin || box.szerokosc < 0.0) {
		std::cin.clear();
		while (std::cin.get() != '\n')
			;
		std::cout << "Nieprawidłowe dane. Raz jeszcze. Szerokość: ";
		std::cin >> box.szerokosc;
	}

	std::cout << "Długość: ";
	std::cin >> box.dlugosc;
	while (!std::cin || box.dlugosc < 0.0) {
		std::cin.clear();
		while (std::cin.get() != '\n')
			;
		std::cout << "Nieprawidłowe dane. Raz jeszcze. Długość: ";
		std::cin >> box.dlugosc;
	}

	calc_volume(&box);

	std::cout << "\nTwoje pudełko:\n";
	print_pudlo(box);

	return 0;
}

void print_pudlo(pudlo p) {
	std::cout << "--- Pudło:\n";
	std::cout << "producent: " << p.producent << std::endl;
	std::cout << "wysokosc: " << p.wysokosc << std::endl;
	std::cout << "szerokosc: " << p.szerokosc << std::endl;
	std::cout << "dlugosc: " << p.dlugosc << std::endl;
	std::cout << "obejtosc: " << p.objetosc << std::endl;
}
void calc_volume(pudlo * p) {
	p->objetosc = p->dlugosc * p->szerokosc * p->wysokosc;
}
