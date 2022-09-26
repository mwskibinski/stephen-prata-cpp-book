#include <iostream>
#include <cstring>

using namespace std;

int main() {
    struct Batonik {
        char marka[20];
        double waga;
        int kalorie;
    };

//    Batonik bat_tbl[3] = {
//        { "snikers", 4.5, 567 },
//        { "milki łej", 14.78, 123 },
//        { "trzy bit", 0.0034, 420 }
//    };

    Batonik * bat_ptr = new Batonik [3];

    strncpy(bat_ptr[0].marka, "Wielgachny Batonus", 19);
    bat_ptr[0].waga = 5.6;
    bat_ptr[0].kalorie = 3456;

    strncpy(bat_ptr[1].marka, "czokogiganciorex", 19);
    bat_ptr[1].waga = 0.034;
    bat_ptr[1].kalorie = 2;

    strcpy(bat_ptr[2].marka, "Seler naciowy");
    bat_ptr[2].waga = 90.67;
    bat_ptr[2].kalorie = 12345;

    cout << "Batoniki:\n";
    cout << "0:\n";
    cout << bat_ptr[0].marka << ", " << bat_ptr[0].waga << ", " << bat_ptr[0].kalorie << endl;
    cout << "1:\n";
    cout << bat_ptr[1].marka << ", " << bat_ptr[1].waga << ", " << bat_ptr[1].kalorie << endl;
    cout << "2:\n";
    cout << bat_ptr[2].marka << ", " << bat_ptr[2].waga << ", " << bat_ptr[2].kalorie << endl;
    cout << "Tyle\n\n";

    delete [] bat_ptr;

    return 0;
}
