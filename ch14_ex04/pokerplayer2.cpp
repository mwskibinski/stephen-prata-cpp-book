#include "pokerplayer2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

PokerPlayer::PokerPlayer(const std::string & fn, int a, const Card & lc)
	: Person(fn, a), luckyCard(lc)
{}

PokerPlayer::PokerPlayer(const Person & p, const Card & lc)
	: Person(p), luckyCard(lc)
{}

PokerPlayer::~PokerPlayer()
{}

void PokerPlayer::show() const
{
	Person::show();
	showUnique();
}

PokerPlayer::Card PokerPlayer::draw() const
{
	return Card {
		Card::Rank(std::rand() % RANKS), Card::Suit(std::rand() % SUITS)
	};
}

void PokerPlayer::showUnique() const
{
	std::cout << "Szczęśliwa karta: " << luckyCard << '\n';
}

const char *PokerPlayer::rank_names[] = {
	"Two", "Three", "Four", "Five", "Six",
	"Seven", "Eight", "Nine", "Ten",
	"Jack", "Queen", "King", "Ace"
};
const char *PokerPlayer::suit_names[] = {
	"Clubs", "Diamonds", "Spades", "Hearts"
};

std::ostream & operator<<(std::ostream & os, const PokerPlayer::Card & c)
{
	os << PokerPlayer::rank_names[int(c.rank)]
		<< ' ' << PokerPlayer::suit_names[int(c.suit)];

	return os;
}

void PokerPlayer::set()
{
	Person::set();
	setUnique();
}

void PokerPlayer::setUnique()
{
	int lcRank, lcSuit;

	std::cout << "Wprowadź wartość karty:\n";
	for (int i = 0; i < RANKS; i++) {
		std::cout << i << ": " << PokerPlayer::rank_names[i]
			<< ((i == 5 || i == RANKS-1) ? "\n" : ", ");
	}
	std::cout << "> ";
	std::cin >> lcRank;

	std::cout << "Wprowadź kolor karty:\n";
	for (int i = 0; i < SUITS; i++) {
		std::cout << i << ": " << PokerPlayer::suit_names[i]
			<< ((i == SUITS-1) ? "\n" : ", ");
	}
	std::cout << "> ";
	std::cin >> lcSuit;

	luckyCard.rank = Card::Rank(lcRank);
	luckyCard.suit = Card::Suit(lcSuit);

	while (std::cin.get() != '\n')
		continue;
}
