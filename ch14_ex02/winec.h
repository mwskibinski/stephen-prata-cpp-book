#ifndef WINEC_H_
#define WINEC_H_

#include "pair.h"
#include <string>
#include <valarray>

using ArrayInt = std::valarray<int>;
using PairArray = Pair<ArrayInt, ArrayInt>;

class Wine : private std::string, private PairArray
{
private:
	int year_n;
public:
	Wine(const char * l = "- brak -", int y = 0);
	Wine(const char * l, int y, const int yr[], const int bot[]);

	void getBottles();
	const std::string & label() const;
	int sum() const;
	void show() const;
};

#endif // WINEC_H_
