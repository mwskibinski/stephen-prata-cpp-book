#include <iostream>
#include <fstream>
#include "vect.h"
#include <cstdlib>
#include <ctime>

void getDouble(double & dbl, const char * text);

int main() {
	double distance, step;
	getDouble(distance, "Podaj dystans do przejścia: ");
	getDouble(step, "Podaj rozmiar kroku: ");

	std::ofstream outFile;
	outFile.open("ex11_01_out.txt");
	if (!outFile.is_open()) {
		std::cout << "Nie można otworzyć pliku do zapisu danych. Program kończy działanie\n";
		return -1;
	}

	srand(time(0));
	VECTOR::Vector result;
	int steps = 0;

	std::cout << "*** *** ***\n";
	std::cout << "Dystans do przejścia: " << distance << ", długość kroku: " << step << std::endl;
	outFile << "Dystans do przejścia: " << distance << ", długość kroku: " << step << std::endl;

	while (result.magval() < distance) {
		std::cout << steps << ": (x, y) = (" << result.xval() << ", " << result.yval() << ")\n";
		outFile << steps << ": (x, y) = (" << result.xval() << ", " << result.yval() << ")\n";
		// std::cout << "\t" << "(mag, ang) = (" << result.magval() << ", " << result.angval() << ")\n";
		result = result +
			VECTOR::Vector(step, rand() % 360, VECTOR::Vector::POL);
		steps++;
	}

	std::cout << "Po " << steps << " krokach delikwent osiągnął położenie:\n";
	std::cout << "(x, y) = (" << result.xval() << ", " << result.yval() << ")\n";
	std::cout << "czyli\n";
	std::cout << "(m, a) = (" << result.magval() << ", " << result.angval() << ")\n";
	std::cout << "Średnia długość kroku pozornego = " << result.magval() / steps << std::endl;

	outFile << "Po " << steps << " krokach delikwent osiągnął położenie:\n";
	outFile << "(x, y) = (" << result.xval() << ", " << result.yval() << ")\n";
	outFile << "czyli\n";
	outFile << "(m, a) = (" << result.magval() << ", " << result.angval() << ")\n";
	outFile << "Średnia długość kroku pozornego = " << result.magval() / steps << std::endl;

	outFile.close();

	return 0;
}

void getDouble(double & dbl, const char * text) {
	std::cout << text;
	while (!(std::cin >> dbl)) {
		std::cin.clear();
		while (std::cin.get() != '\n')
			;
		std::cout << "\t*** Nieprawidłowe dane.\n";
		std::cout << text;
	}
	// Gdy dane są w dobrej postaci dla double, ale po nich są śmieci, program zostawia te śmieci.
	// Tutaj je usuwam.
	std::cin.clear();
	while (std::cin.get() != '\n')
		;
}
