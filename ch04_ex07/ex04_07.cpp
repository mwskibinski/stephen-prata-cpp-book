#include <iostream>

int main() {
    struct pizza {
        char name[40];
        float diameter;
        float weight;
    };

    pizza picca;

    std::cout << "Podaj informację o pizzy\n";
    std::cout << "Nazwa firmy: ";
    std::cin.getline(picca.name, 40);
    std::cout << "Średnica: ";
    std::cin >> picca.diameter;
    std::cout << "Waga: ";
    std::cin >> picca.weight;

    std::cout << std::endl << "Dane o wprowadzonej pitcy:\n";
    std::cout << "Nazwa firmy: " << picca.name << std::endl;
    std::cout << "Średnica: " << picca.diameter << std::endl;
    std::cout << "Waga: " << picca.weight << std::endl;

    return 0;
}
