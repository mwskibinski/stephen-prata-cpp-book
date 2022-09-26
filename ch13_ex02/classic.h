#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd
{
	char * mainTrack;
public:
	Classic(const char * mt, const char * s1, const char * s2, int n, double x);
	Classic(const char * mt, const Cd & d);
	Classic(const Classic & cl);
	Classic();
	virtual ~Classic();

	virtual void report() const;
	Classic & operator=(const Classic & cl);
};

#endif // CLASSIC_H_
