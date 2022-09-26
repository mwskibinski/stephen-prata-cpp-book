#include "person.h"
#include <iostream>

Person::Person(const std::string & fn, int a)
	: fullname(fn), age(a)
{}

Person::~Person()
{}

void Person::show() const
{
	std::cout << "Imię i nazwisko: " << fullname << '\n';
	std::cout << "Wiek: " << age << '\n';
}

void Person::set()
{
	std::cout << "Wprowadź imię i nazwisko:\n";
	std::cout << "> ";
	std::getline(std::cin, fullname);

	std::cout << "Wprowadź wiek:\n";
	std::cout << "> ";
	std::cin >> age;

	while (std::cin.get() != '\n')
		continue;
}
