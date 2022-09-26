#include <iostream>

int main()
{
    using namespace std;

    cout << "Podaj liczbę sekund: ";
    long long seconds;
    cin >> seconds;

    // Wersja nr 1
//    const int sec_per_min = 60;
//    const int min_per_h = 60;
//    const int h_per_day = 24;
//
//    int days = seconds / (sec_per_min * min_per_h * h_per_day);
//    int hours = (seconds - days * (sec_per_min * min_per_h * h_per_day)) / (sec_per_min * min_per_h);
//    int minutes = (seconds - hours * (sec_per_min * min_per_h) - days * (sec_per_min * min_per_h * h_per_day)) / sec_per_min;
//    int seconds_remaining = seconds - minutes * sec_per_min - hours * (sec_per_min * min_per_h) - days * (sec_per_min * min_per_h * h_per_day);

    // Wersja nr 2
//    const int sec_per_min = 60;
//    const int sec_per_hour = 60 * 60;
//    const int sec_per_day = 60 * 60 * 24;
//
//    int days = seconds / sec_per_day;
//    int hours = (seconds - days * sec_per_day) / sec_per_hour;
//    int minutes = (seconds - hours * sec_per_hour - days * sec_per_day) / sec_per_min;
//    int seconds_remaining = seconds - minutes * sec_per_min - hours * sec_per_hour - days * sec_per_day;

    // Wersja nr 3
    const int sec_per_min = 60;
    const int sec_per_hour = 60 * 60;
    const int sec_per_day = 60 * 60 * 24;

    int days = seconds / sec_per_day;
    int hours = (seconds % sec_per_day) / sec_per_hour;
    int minutes = (seconds % sec_per_hour) / sec_per_min;
    int seconds_remaining = seconds % sec_per_min;

    cout << seconds << " sekund = ";
    cout << days << " dni, " << hours << " godzin, " << minutes << " minut, " << seconds_remaining << " sekund.";
    cout << endl;

    return 0;
}
