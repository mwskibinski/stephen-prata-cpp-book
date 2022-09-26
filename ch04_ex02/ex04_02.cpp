#include <iostream>
#include <string>

using namespace std;

int main() {
    const int ArSize = 20;
    // string name(ArSize), dessert(ArSize);
    string name, dessert;

    cout << "Podaj swoje imię:\n";
    getline(cin, name);
    cout << "Podaj swój ulubiony deser:\n";
    getline(cin, dessert);
    cout << "Mam dla ciebie " << dessert;
    cout << ", " << name << ".\n";

    return 0;
}
