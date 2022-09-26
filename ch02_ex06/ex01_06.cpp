#include <iostream>

double ly_2_au(double ly);

int main()
{
    std::cout << "Podaj odległość w latach świetlnych: ";
    double ly;
    std::cin >> ly;
    std::cout << "W jednostkach astronomicznych: " << ly_2_au(ly) << std::endl;

    return 0;
}

double ly_2_au(double ly)
{
    return ly * 63240.0;
}
