#include <iostream>

int main() {
    using namespace std;

    const double start = 100.0;
    double dafne, cloe;
    dafne = cloe = start;
    double dafne_zysk, cloe_zysk;

//    while (dafne > cloe) {
//        dafne += start * 0.1;
//        cloe += cloe * 0.05;
//    }

//    do {
//        dafne += start * 0.1;
//        cloe += cloe * 0.05;
//        std::cout << "Dafne: " << dafne << std::endl;
//        std::cout << "Cloe: " << cloe << std::endl;
//        std::cout << "***\n";
//    } while (dafne > cloe);

    int year;
//    for (year = 1; dafne >= cloe; ++year, dafne += start * 0.1, cloe += cloe * 0.05)
//        ;
//    {
//        std::cout << year << std::endl;
//        std::cout << "Dafne: " << dafne << std::endl;
//        std::cout << "Cloe: " << cloe << std::endl;
//        std::cout << "***\n";
//    }
    for (year = 1; dafne >= cloe; ++year) {
        dafne += start * 0.1;
        cloe += cloe * 0.05;
    }

    std::cout << "Rok: " << year << std::endl;
    std::cout << "Dafne: " << dafne << std::endl;
    std::cout << "Cloe: " << cloe << std::endl;

    return 0;
}
