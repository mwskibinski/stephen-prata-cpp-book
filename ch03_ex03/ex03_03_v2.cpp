#include <iostream>

int main()
{
    using namespace std;

    cout << "Podaj długość w stopniach, minutach i sekundach: " << endl;

    int degrees, minutes, seconds;
    cout << "Stopnie: ";
    cin >> degrees;
    cout << "Minuty stopnia łuku: ";
    cin >> minutes;
    cout << "Sekundy łuku: ";
    cin >> seconds;
    cout << endl;

    const int sec_per_min = 60;
    const int min_per_deg = 60;
    cout << degrees << " stopni, " << minutes << " minut, " << seconds << " sekund = ";
//    cout << (double (seconds) / sec_per_min) / min_per_deg + double (minutes) / min_per_deg + degrees;
    cout << (double (seconds) / sec_per_min + minutes) / min_per_deg + degrees;
    cout << " stopni" << endl;

    return 0;
}
