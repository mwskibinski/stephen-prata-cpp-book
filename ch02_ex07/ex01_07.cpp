#include <iostream>

void show_time(int hour, int minute);

int main()
{
    std::cout << "Podaj liczbę godzin: ";
    int hour;
    std::cin >> hour;
    std::cout << "Podaj liczbę minut: ";
    int min;
    std::cin >> min;

    show_time(hour, min);

    return 0;
}

void show_time(int hour, int minute)
{
    std::cout << "Czas: " <<
        hour << ":" << minute << std::endl;
}
