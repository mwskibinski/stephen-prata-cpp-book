#include <iostream>

int main() {
    using namespace std;
    cout << "Podaj liczbę wierszy: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n-(i+1); j++)
//            std::cout << '.';
//        for (int j = 0; j < (i+1); j++)
//            std::cout << '*';
        for (int j = i+1; j < n; j++)
            std::cout << '.';
        for (int j = n-(i+1); j < n; j++)
            std::cout << '*';

        std::cout << '\n';
    }

    return 0;
}
