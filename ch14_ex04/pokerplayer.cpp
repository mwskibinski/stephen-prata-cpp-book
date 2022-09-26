//#include "pokerplayer.h"
//#include <cstdlib>
//#include <ctime>
//#include <iostream>
//
//PokerPlayer::PokerPlayer(const std::string & fn, int a, int lc)
//	: Person(fn, a), luckyCard(lc)
//{
//	std::srand(std::time(0));
//}
//
//PokerPlayer::PokerPlayer(const Person & p, int lc)
//	: Person(p), luckyCard(lc)
//{
//	std::srand(std::time(0));
//}
//
//PokerPlayer::~PokerPlayer()
//{}
//
//int PokerPlayer::draw() const
//{
//	return std::rand() % 52 + 1;
//}
//
//void PokerPlayer::show() const
//{
//	Person::show();
//	PokerPlayer::showUnique();
//}
//
//void PokerPlayer::showUnique() const
//{
//	std::cout << "Szczesliwa karta: " << luckyCard << '\n';
//}
