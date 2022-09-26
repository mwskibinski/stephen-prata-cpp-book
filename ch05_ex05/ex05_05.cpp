#include <iostream>

const int Months = 12;

int main() {
    const char * months[Months] = {
        "Styczeń", "Luty", "Marzec", "Kwiecień", "Maj", "Czerwiec",
        "Lipiec", "Sierpień", "Wrzesień", "Październik", "Listopad", "Grudzień"
    };
    int monthlySale[Months] {0}, sum {0};

    for (int i = 0; i < Months; i++) {
        std::cout << "Miesiąc: " << months[i] << std::endl;
        std::cout << "Sprzedaż: ";
        std::cin >> monthlySale[i];
        std::cout << "***" << std::endl;
        sum += monthlySale[i];
    }
    std::cout << std::endl << "### ### ###" << std::endl;
    std::cout << "Suma: " << sum << std::endl;

    return 0;
}
