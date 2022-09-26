#include <iostream>

int main() {
    double num, sum = 0.0;

//    std::cout << "Liczba: ";
//    std::cin >> num;
//    sum += num;
//    std::cout << "Aktualna suma: " << sum << std::endl;
//    while (num != 0.0) {
//        std::cout << "Liczba: ";
//        std::cin >> num;
//        sum += num;
//        std::cout << "Aktualna suma: " << sum << std::endl;
//    }

//    std::cout << "Liczba: ";
//    std::cin >> num;
//    sum += num;
//    while (num != 0.0) {
//        std::cout << "Aktualna suma: " << sum << std::endl;
//        std::cout << "Liczba: ";
//        std::cin >> num;
//        sum += num;
//    }

    std::cout << "Liczba: ";
    std::cin >> num;
    while (num != 0.0) {
        sum += num;
        std::cout << "Aktualna suma: " << sum << std::endl;
        std::cout << "Liczba: ";
        std::cin >> num;
    }

//    do {
//        std::cout << "Liczba: ";
//        std::cin >> num;
//        sum += num;
//        std::cout << "Aktualna suma: " << sum << std::endl;
//    } while (num != 0.0);

//    for (
//        std::cout << "Liczba: ",
//            std::cin >> num,
//            sum += num,
//            std::cout << "Aktualna suma: " << sum << std::endl;
//        num != 0.0;
//        std::cout << "Liczba: ",
//            std::cin >> num,
//            sum += num,
//            std::cout << "Aktualna suma: " << sum << std::endl
//    )
//        ;

    // std::cout << "***\nSuma końcowa: " << sum << std::endl;
    // std::cout << std::endl;

    return 0;
}
