#include <iostream>
#include <cstring>

const int WordSize = 50;

using namespace std;

int main() {
    // cout << "Podawaj słowa (kiedy skończysz, napisz \"gotowe\")" << endl;
    cout << R"(Podawaj słowa (kiedy skończysz, napisz "gotowe"))" << endl;
    char word[WordSize];
    unsigned int wordCnt = 0u;

    cin >> word;
    while (strcmp(word, "gotowe")) {
        wordCnt++;
        cin >> word;
    }
    cout << "Podano " << wordCnt << " słów" << endl;

    return 0;
}
