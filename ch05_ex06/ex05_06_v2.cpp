#include <iostream>

const int Years = 3;
const int People = 2;

int main() {
    using namespace std;
    enum people { Dafne = 0, Cloe = 1 };
    const double start = 100.0;
    // double yearSale[People][Years] { {start, 0.0, 0.0}, {start, 0.0, 0.0} };
    double yearSale[Years][People] { {start, start} };

    for (int y = 1; y < Years; ++y) {
        for (int p = 0; p < People; ++p) {
            yearSale[y][Dafne] = yearSale[y-1][Dafne] + yearSale[0][Dafne] * 0.1;
            yearSale[y][Cloe] = yearSale[y-1][Cloe] + yearSale[y-1][Cloe] * 0.05;
        }
    }

    std::cout << "\n\n***\n\n";
    for (int p = -2; p < People; ++p) {
        if (p == -2)
            std::cout << "Rok:\t";
//        else if (p == -1)
//            std::cout << "=============================";
        else if (p == Dafne)
            std::cout << "Dafne:\t";
        else if (p == Cloe)
            std::cout << "Cloe:\t";

        for (int y = 0; y < Years; ++y) {
            if (p == -2)
                std::cout << y << "\t";
            else if (p == -1)
                std::cout << "==========";
            else
                std::cout << yearSale[y][p] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\n\n***\n\n";
    std::cout << "Łączna sprzedaż w każdym roku:\n";
    std::cout << "\t";
    for (int y = 0; y < Years; ++y) {
        std::cout << yearSale[y][Dafne] + yearSale[y][Cloe] << "\t";
    }
    std::cout << std::endl;

    return 0;
}
