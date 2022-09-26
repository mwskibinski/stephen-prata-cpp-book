#include <iostream>

int main()
{
    using namespace std;

    cout << "Podaj liczbę ludności świata: ";
    long long world_population;
    cin >> world_population;

    cout << "Podaj liczbę ludności Polski: ";
    long long poland_population;
    cin >> poland_population;

    cout << "Populacja Polski stanowi ";
    cout << double (poland_population) / world_population * 100;
    cout << "% populacji świata" << endl;

    return 0;
}
