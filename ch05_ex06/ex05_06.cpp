#include <iostream>

const int Years = 3;
const int People = 2;

int main() {
    using namespace std;
    enum people { Dafne = 0, Cloe = 1 };
    const double start = 100.0;
    double yearSale[Years][People] { {start, start} };

    for (int y = 1; y < Years; ++y)
        for (int p = 0; p < People; ++p) {
            yearSale[y][Dafne] = yearSale[y-1][Dafne] + yearSale[0][Dafne] * 0.1;
            yearSale[y][Cloe] = yearSale[y-1][Cloe] + yearSale[y-1][Cloe] * 0.05;
        }

    std::cout << "\n\n***\n\n";
    for (int p = 0; p < People; ++p) {
        for (int y = 0; y < Years; ++y)
            std::cout << yearSale[y][p] << "\t";
        std::cout << "\n";
    }

    std::cout << "\n\n***\n\n";
    std::cout << "Łączna sprzedaż w każdym roku:\n";
    for (int y = 0; y < Years; ++y)
        std::cout << yearSale[y][Dafne] + yearSale[y][Cloe] << "\t";
    std::cout << std::endl;

    std::cout << "Łączna sprzedaż dla wszystkich lat:\n";
    double saleEveryYear[People] {0};
    for (int p = 0; p < People; ++p)
        for (int y = 0; y < Years; ++y)
            saleEveryYear[p] += yearSale[y][p];
    std::cout << "Dafne (wszystkie lata): " << saleEveryYear[Dafne] << std::endl;
    std::cout << "Cloe (wszystkie lata): " << saleEveryYear[Cloe] << std::endl;
    std::cout << std::endl;

    return 0;
}
