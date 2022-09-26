#include <iostream>

using namespace std;

int main() {
    const int name_maxsize = 80;
    char first_name[name_maxsize], last_name[name_maxsize];
    cout << "Jak masz na imię? ";
    cin.getline(first_name, name_maxsize);
    // cin.get(first_name, name_maxsize);
    // cin.get(first_name, name_maxsize).get();
    // cin >> first_name;
    // (cin >> first_name).get();
    cout << "Jak się nazywasz? ";
    cin.getline(last_name, name_maxsize);
    // cin.get(last_name, name_maxsize);

    int age, grade;
    cout << "Na jaką ocenę zasługujesz? ";
    cin >> grade;
    grade = grade - 1;
    cout << "Ile masz lat? ";
    cin >> age;

    cout << "Nazwisko: " << last_name << ", " << first_name << endl;
    cout << "Ocena: " << grade << endl;
    cout << "Wiek: " << age << endl;

    return 0;
}
