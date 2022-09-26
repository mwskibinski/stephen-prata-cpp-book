#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Podaj imię: ";
    string firstName;
    // Zakładam, że może być więcej niż jedno słowo na imię/nazwisko.
    getline(cin, firstName);

    cout << "Podaj nazwisko: ";
    string lastName;
    getline(cin, lastName);

    string modifiedName;

    modifiedName = lastName + ", " + firstName;

    cout << endl;
    cout << "Oto informacje zestawione w jeden napis: " << modifiedName << endl;

    return 0;
}
