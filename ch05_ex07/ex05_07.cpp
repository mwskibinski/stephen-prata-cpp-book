#include <iostream>

const int BrandName = 50;

int main() {
    struct car {
        char brand[BrandName];
        int year;
    };

    int car_n;
    std::cout << "Ile samochodów chcesz skatalogować? ";
    (std::cin >> car_n).get();
    car * car_ptr = new car [car_n];

    for (int i = 0; i < car_n; i++) {
        std::cout << "Samochód #" << i + 1 << ":\n";
        std::cout << "Proszę podać markę: ";
        std::cin.getline(car_ptr[i].brand, BrandName);
        std::cout << "Rok produkcji: ";
        (std::cin >> car_ptr[i].year).get();
    }

    std::cout << "***\n";
    for (int i = 0; i < car_n; i++)
        std::cout << car_ptr[i].year << " " << car_ptr[i].brand << "\n";

    delete [] car_ptr;

    return 0;
}
