#include <iostream>

using namespace std;

int main()
{
    const double in_per_cm = 1 / 2.54;
    const double ft_per_cm = 1 / 30.48;
    const double in_per_ft = 12.0;

    cout << "Podaj wzrost w centymetrach: ";
    double height;
    cin >> height;

    // Rozwiązanie nr 1
    cout << "Ten wzrost w stopach to: " << height * ft_per_cm << endl;
    cout << "Ten wzrost w calach to: " << height * in_per_cm << endl;

    // Rozwiązanie nr 2
    cout << "Inaczej, wzrost w stopach i calach: ";
    cout << int (height * ft_per_cm) << " stóp, ";
    cout << height * in_per_cm - int (height * ft_per_cm) * in_per_ft <<  " cali." << endl;

    return 0;
}
