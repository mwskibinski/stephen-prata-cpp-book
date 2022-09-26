#include <iostream>

int main() {
    using namespace std;

    int n1, n2;
    cout << "Podaj dwie liczby całkowite\n";
    cout << "n1 = ";
    cin >> n1;
    cout << "n2 = ";
    cin >> n2;
    // cin >> n1 >> n2;
    // cout << "n1 = " << n1 << ", n2 = " << n2 << endl;

    int sum = 0;
    for (int i = n1; i <= n2; i++)
        sum += i;

    cout << "Suma: " << sum << endl;

    return 0;
}
