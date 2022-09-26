#include <iostream>
#include <cstring>

using namespace std;

int main() {
    cout << "Podaj imię: ";
    const int ArSize = 30;
    char firstName[ArSize];
    // Zakładam, że może być więcej niż jedno słowo na imię/nazwisko.
    cin.getline(firstName, ArSize);

    cout << "Podaj nazwisko: ";
    char lastName[ArSize];
    cin.getline(lastName, ArSize);

    const int ArSize_mod = ArSize * 2 - 1;
    char modifiedName[ArSize_mod];

    strcpy(modifiedName, lastName);
    strcat(modifiedName, ", ");
    strcat(modifiedName, firstName);

    cout << endl;
    cout << "Oto informacje zestawione w jeden napis: " << modifiedName << endl;

    return 0;
}
