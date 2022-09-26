#include <iostream>

double nmi_2_m(double);

int main()
{
    double nautical_mile, meter;

    std::cout << "Podaj odległość w milach morskich: ";
    std::cin >> nautical_mile;
    std::cout << "Ta odległość w metrach to: " << nmi_2_m(nautical_mile) << " m" << std::endl;

    return 0;
}

double nmi_2_m(double nmi)
{
    return nmi * 1852.0;
}
