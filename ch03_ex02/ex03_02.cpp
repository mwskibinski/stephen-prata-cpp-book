#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Zakładam, że będą to wartości całkowite, bo chyba tak się zazwyczaj podaje te wartości.
    int height_ft, height_in, weight_lbs;

    cout << "Podaj wzrost w stopach i calach, oraz wagę w funtach." << endl;
    cout << "Wzrost, część w stopach: ";
    cin >> height_ft;
    cout << "Wzrost, pozostała część w calach: ";
    cin >> height_in;
    cout << "Waga w funtach: ";
    cin >> weight_lbs;

    const int in_per_ft = 12;
    const double m_per_in = 2.54 / 100;
    const double kg_per_lbs = 1 / 2.2;

//    double height_m = (double (height_ft) * in_per_ft + height_in) * m_per_in;
//    double weight_kg = weight_lbs * kg_per_lbs;
//    double bmi = weight_kg / (height_m * height_m);
//
//    cout << "Twój BMI: " << bmi << endl;

    cout << "Twój BMI: ";
    cout << weight_lbs * kg_per_lbs / pow((double (height_ft) * in_per_ft + height_in) * m_per_in, 2);
    cout << endl;

    return 0;
}
