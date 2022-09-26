#include <iostream>

int age_in_months(int age);

int main()
{
    std::cout << "Podaj swój wiek: ";
    int age;
    std::cin >> age;
    std::cout << "Twój wiek w miesiącach to: " << age_in_months(age) << std::endl;

    return 0;
}

int age_in_months(int age)
{
    return age * 12;
}
