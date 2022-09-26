#ifndef BADDUDE2_H_
#define BADDUDE2_H_

#include "gunslinger.h"
#include "pokerplayer2.h"

class BadDude : public Gunslinger, public PokerPlayer
{
private:
	long badnessCoeff;
protected:
	void showUnique() const;
	void setUnique();
public:
	BadDude(
		const std::string & fn = "brak", int a = 0, double dt = 0.0, int n = 0,
		const PokerPlayer::Card & lc = {PokerPlayer::Card::Rank::Two, PokerPlayer::Card::Suit::Spades},
		long bc = 0
	);
	BadDude(const Person & p, const Gunslinger & g, const PokerPlayer & pp, long bc);
	~BadDude();

	virtual void show() const;
	virtual void set();

	double gDraw() const;
	PokerPlayer::Card cDraw() const;

	long getBadnessCoeff() const;
	void setBadnessCoeff(long bc);
};

inline double BadDude::gDraw() const
{
	return Gunslinger::draw();
}
inline PokerPlayer::Card BadDude::cDraw() const
{
	return PokerPlayer::draw();
}
inline long BadDude::getBadnessCoeff() const
{
	return badnessCoeff;
}
inline void BadDude::setBadnessCoeff(long bc)
{
	badnessCoeff = bc;
}

#endif // BADDUDE2_H_
