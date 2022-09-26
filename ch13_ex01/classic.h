#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd
{
	enum {MAINTRACK_LEN = 100};

	char mainTrack[MAINTRACK_LEN];
public:
	Classic(const char * mt, const char * s1, const char * s2, int n, double x);
	Classic(const char * mt, const Cd & d);
	Classic(const Classic & cl);
	Classic();
	virtual ~Classic();

	virtual void report() const;
};

#endif // CLASSIC_H_
