#include <iostream>
#include <cstring>

const int SIZE = 50;

struct Batonik {
	char producent[SIZE];
	double waga;
	int kalorie;
};

void ustawBatonik(Batonik & b, const char * prod = "Millenium Munch", double waga = 2.85, int kal = 350);
void pokazBatonik(const Batonik &);

int main() {
	Batonik btn;
	ustawBatonik(btn, "Super Stefan0s", 2.34, 5000);
	pokazBatonik(btn);

	Batonik a;
	ustawBatonik(a);
	pokazBatonik(a);

	return 0;
}

void ustawBatonik(Batonik & bat, const char * prod, double waga, int kal) {
	strncpy(bat.producent, prod, SIZE);
	bat.waga = waga;
	bat.kalorie = kal;
}
void pokazBatonik(const Batonik & bat) {
	std::cout << "--- Twój batonik:\n";
	std::cout << "Producent: " << bat.producent << std::endl;
	std::cout << "Waga: " << bat.waga << std::endl;
	std::cout << "Liczba kalorii: " << bat.kalorie << std::endl;
}
