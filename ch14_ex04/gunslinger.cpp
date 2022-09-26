#include "gunslinger.h"
#include <iostream>

Gunslinger::Gunslinger(const std::string & fn, int a, double dt, int n)
	: Person(fn, a), drawTime(dt), notches(n)
{}

Gunslinger::Gunslinger(const Person & p, double dt, int n)
	: Person(p), drawTime(dt), notches(n)
{}

Gunslinger::~Gunslinger()
{}

void Gunslinger::show() const
{
	Person::show();
	showUnique();
}

void Gunslinger::showUnique() const
{
	std::cout << "Czas wyciągania rewolweru: " << drawTime << '\n';
	std::cout << "Liczba nacięć na rewolwerze: " << notches << '\n';
}

void Gunslinger::set()
{
	Person::set();
	setUnique();
}

void Gunslinger::setUnique()
{
	std::cout << "Wprowadź czas wyciągania rewolweru:\n";
	std::cout << "> ";
	std::cin >> drawTime;

	std::cout << "Wprowadź liczbę nacięć na rewolwerze:\n";
	std::cout << "> ";
	std::cin >> notches;

	while (std::cin.get() != '\n')
		continue;
}
