#include <iostream>
#include <string>
#include <array>

using std::string;

const int Months = 12;

struct monthSale {
    string month;
    int sale;
};

std::array<monthSale, Months> initArray(void);
void printArray(std::array<monthSale, Months>);

int main() {
    std::array<monthSale, Months> monthlySale = initArray();

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

    std::cout << std::endl << "### ### ###" << std::endl;
    printArray(monthlySale);

    return 0;
}

std::array<monthSale, Months> initArray(void) {
    std::array<monthSale, Months> monthlySale;
    const char * months[Months] = {
        "Styczeń", "Luty", "Marzec", "Kwiecień", "Maj", "Czerwiec",
        "Lipiec", "Sierpień", "Wrzesień", "Październik", "Listopad", "Grudzień"
    };
    for (int i = 0; i < 12; i++) {
        monthlySale[i].month = months[i];
        monthlySale[i].sale = 0;
    }

    return monthlySale;
}

void printArray(std::array<monthSale, Months> x) {
    for (int i = 0; i < 12; i++) {
        std::cout << "***" << std::endl;
        std::cout << "i: " << i << std::endl;
        std::cout << "month: " << x[i].month << std::endl;
        std::cout << "sale: " << x[i].sale << std::endl;
    }
}
