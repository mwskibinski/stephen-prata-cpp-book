//#ifndef BADDUDE_H_
//#define BADDUDE_H_
//
//#include "gunslinger.h"
//#include "pokerplayer.h"
//
//class BadDude : public Gunslinger, public PokerPlayer
//{
//private:
//	long badnessCoeff;
//protected:
//	void showUnique() const;
//public:
//	BadDude(const std::string & fn = "brak", int a = 0, double dt = 0.0, int n = 0, int lc = 0);
//	BadDude(const Person & p, const Gunslinger & g, const PokerPlayer & pp);
//	~BadDude();
//
//	void show() const;
//	double gDraw() const;
//	int cDraw() const;
//
//	long getBadnessCoeff() const;
//	void setBadnessCoeff(long bc);
//};
//
//inline double BadDude::gDraw() const
//{
//	Gunslinger::draw();
//}
//inline int BadDude::cDraw() const
//{
//	PokerPlayer::draw();
//}
//inline long BadDude::getBadnessCoeff() const
//{
//	return badnessCoeff;
//}
//inline void BadDude::setBadnessCoeff(long bc)
//{
//	badnessCoeff = bc;
//}
//
//#endif // BADDUDE_H_
