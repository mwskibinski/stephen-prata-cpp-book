#include <iostream>
#include <array>

int main() {
    std::array<double, 3> ar;

    std::cout << "Podaj trzykrotnie wynik sprintu na 100 metrów\n";
    std::cout << "uno: ";
    std::cin >> ar[0];
    std::cout << "dos: ";
    std::cin >> ar[1];
    std::cout << "tres: ";
    std::cin >> ar[2];

    std::cout << "\nA oto wyniki:\n";
    std::cout << "adin: " << ar[0] << std::endl;
    std::cout << "dva: " << ar[1] << std::endl;
    std::cout << "tri: " << ar[2] << std::endl;
    std::cout << "Średnia: " << (ar[0] + ar[1] + ar[2]) / 3.0 << std::endl;

    return 0;
}
