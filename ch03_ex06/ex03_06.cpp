#include <iostream>

int main()
{
    using namespace std;

    cout << "Ile mil przejechano? ";
    double miles;
    cin >> miles;

    cout << "Ile galonów benzyny zużyto? ";
    double gallons;
    cin >> gallons;

    cout << "Wygląda na to, że twój samochód może przejechać ";
    cout << miles / gallons;
    cout << " mil na jednym galonie benzyny";
    cout << endl;

    cout << endl;

    cout << "Ile kilometrów przejechano? ";
    double km;
    cin >> km;

    cout << "Ile litrów benzyny zużyto? ";
    double ltr;
    cin >> ltr;

    cout << "Wygląda na to, że twój samochód może przejechać ";
    cout << km / ltr;
    cout << " km na jednym litrze benzyny";
    cout << endl;

    return 0;
}
