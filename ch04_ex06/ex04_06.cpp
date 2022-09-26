#include <iostream>

using namespace std;

int main() {
    struct Batonik {
        char marka[20];
        double waga;
        int kalorie;
    };

    Batonik bat_tbl[3] = {
        { "snikers", 4.5, 567 },
        { "milki łej", 14.78, 123 },
        { "trzy bit", 0.0034, 420 }
    };

    cout << "Batoniki:\n";
    cout << "0:\n";
    cout << bat_tbl[0].marka << ", " << bat_tbl[0].waga << ", " << bat_tbl[0].kalorie << endl;
    cout << "1:\n";
    cout << bat_tbl[1].marka << ", " << bat_tbl[1].waga << ", " << bat_tbl[1].kalorie << endl;
    cout << "2:\n";
    cout << bat_tbl[2].marka << ", " << bat_tbl[2].waga << ", " << bat_tbl[2].kalorie << endl;
    cout << "Tyle\n\n";

    return 0;
}
