#include <iostream>

double cel_2_fahr(double temperature_celsius);

int main()
{
    std::cout << "Podaj temperaturę w stopniach Celsjusza: ";
    double cel;
    std::cin >> cel;
    std::cout << "Inaczej, w stopniach Fahrenheita: " << cel_2_fahr(cel) << std::endl;

    return 0;
}

double cel_2_fahr(double cel)
{
    return 9.0/5.0 * cel + 32.0;
}
