#include "baddude2.h"
#include <iostream>

BadDude::BadDude(const std::string & fn, int a, double dt, int n, const PokerPlayer::Card & lc, long bc)
	: Person(fn, a), Gunslinger(fn, a, dt, n), PokerPlayer(fn, a, lc), badnessCoeff(bc)
{}

BadDude::BadDude(const Person & p, const Gunslinger & g, const PokerPlayer & pp, long bc)
	: Person(p), Gunslinger(g), PokerPlayer(pp), badnessCoeff(bc)
{}

BadDude::~BadDude()
{}

void BadDude::show() const
{
	Person::show();
	Gunslinger::showUnique();
	PokerPlayer::showUnique();
	showUnique();
}

void BadDude::showUnique() const
{
	std::cout << "Współczynnik zła: " << badnessCoeff << '\n';
}

void BadDude::set()
{
	Person::set();
	Gunslinger::setUnique();
	PokerPlayer::setUnique();
	setUnique();
}

void BadDude::setUnique()
{
	std::cout << "Wprowadź wartość współczynnika zła:\n";
	std::cout << "> ";
	std::cin >> badnessCoeff;

	while (std::cin.get() != '\n')
		continue;
}
