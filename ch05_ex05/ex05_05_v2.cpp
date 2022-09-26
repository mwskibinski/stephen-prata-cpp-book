#include <iostream>

const int Months = 12;

int main() {
    struct {
        const char * month;
        int sale;
    } monthlySale[Months] = {
        {"Styczeń", 0}, {"Luty", 0}, {"Marzec", 0}, {"Kwiecień", 0}, {"Maj", 0}, {"Czerwiec", 0},
        {"Lipiec", 0}, {"Sierpień", 0}, {"Wrzesień", 0}, {"Październik", 0}, {"Listopad", 0}, {"Grudzień", 0}
    };

    int sum = 0;
    for (int i = 0; i < Months; i++) {
        std::cout << "Miesiąc: " << monthlySale[i].month << std::endl;
        std::cout << "Sprzedaż: ";
        std::cin >> monthlySale[i].sale;
        std::cout << "***" << std::endl;
        sum += monthlySale[i].sale;
    }
    std::cout << std::endl << "### ### ###" << std::endl;
    std::cout << "Suma: " << sum << std::endl;

    return 0;
}
