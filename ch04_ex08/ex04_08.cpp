#include <iostream>

int main() {
    struct pizza {
        char name[40];
        float diameter;
        float weight;
    };

    pizza * piz_ptr = new pizza;

    std::cout << "Podaj informację o pizzy\n";
    std::cout << "Średnica: ";
    std::cin >> piz_ptr->diameter;
    std::cin.get();
    // (std::cin >> piz_ptr->diameter).get();
    std::cout << "Nazwa firmy: ";
    std::cin.getline(piz_ptr->name, 40);
    // std::cin.get(piz_ptr->name, 40);
    // std::cin.get();
    std::cout << "Waga: ";
    std::cin >> piz_ptr->weight;

    std::cout << std::endl << "Dane o wprowadzonej pitcy:\n";
    std::cout << "Nazwa firmy: " << piz_ptr->name << std::endl;
    std::cout << "Średnica: " << piz_ptr->diameter << std::endl;
    std::cout << "Waga: " << piz_ptr->weight << std::endl;

    return 0;
}
