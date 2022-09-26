#ifndef POKERPLAYER2_H_
#define POKERPLAYER2_H_

#include "person.h"

class PokerPlayer : virtual public Person
{
public:
	struct Card {
		enum class Rank {
			Two = 0, Three, Four, Five, Six, Seven,
			Eight, Nine, Ten, Jack, Queen, King, Ace
		} rank;
		enum class Suit {
			Clubs = 0, Diamonds, Spades, Hearts
		} suit;
	};
private:
	Card luckyCard;
	enum {RANKS = 13, SUITS = 4};
	static const char *rank_names[RANKS];
	static const char *suit_names[SUITS];
protected:
	void showUnique() const;
	void setUnique();
public:
	PokerPlayer(const std::string & fn = "brak", int a = 0, const Card & lc = {Card::Rank::Two, Card::Suit::Clubs});
	PokerPlayer(const Person & p, const Card & lc);
	virtual ~PokerPlayer();

	virtual void show() const;
	virtual void set();

	Card draw() const;
	const Card & getLuckyCard() const;
	void setLuckyCard(const Card & lc);

	friend std::ostream & operator<<(std::ostream & os, const Card & c);
};

inline const PokerPlayer::Card & PokerPlayer::getLuckyCard() const
{
	return luckyCard;
}
inline void PokerPlayer::setLuckyCard(const Card & lc)
{
	luckyCard = lc;
}

#endif // POKERPLAYER2_H_
