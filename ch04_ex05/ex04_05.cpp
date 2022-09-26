#include <iostream>

using namespace std;

int main() {
    struct Batonik {
        char marka[20];
        double waga;
        int kalorie;
    } snack = { "Moncha Munch", 2.3, 350 };

    cout << "Zawartość zmiennej 'snack':\n";
    cout << "Marka: " << snack.marka << endl;
    cout << "Waga: " << snack.waga << endl;
    cout << "Kalorie: " << snack.kalorie << endl;

    return 0;
}
