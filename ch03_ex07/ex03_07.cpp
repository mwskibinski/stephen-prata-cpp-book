#include <iostream>

int main()
{
    using namespace std;

    cout << "Podaj zużycie benzyny (litry na 100 km): ";
    double ltr_per_100km;
    cin >> ltr_per_100km;

    const double km_per_mile = 100.0 / 62.14;
    const double gallon_per_liter = 1 / 3.785;

    double miles_per_gallon = 1.0 / (ltr_per_100km / 100 * km_per_mile * gallon_per_liter);

    cout << "To samo jako mile na galon: " << miles_per_gallon << endl;

    return 0;
}
