#include <iostream>

int main()
{
    using namespace std;

    cout << "Podaj d³ugoœæ w stopniach, minutach i sekundach: " << endl;

    int degrees, minutes, seconds;
    cout << "Stopnie: ";
    cin >> degrees;
    cout << "Minuty stopnia luku: ";
    cin >> minutes;
    cout << "Sekundy ³uku: ";
    cin >> seconds;
    cout << endl;

    const int sec_per_min = 60;
    const int min_per_deg = 60;
    cout << degrees << " stopni, " << minutes << " minut, " << seconds << " sekund = ";
    cout << (double (seconds) / sec_per_min) / min_per_deg + double (minutes) / min_per_deg + double (degrees);
    cout << " stopni" << endl;

    return 0;
}
