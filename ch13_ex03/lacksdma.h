#ifndef LACKSDMA_H_
#define LACKSDMA_H_

#include "absdma.h"

class LacksDMA : public AbsDMA
{
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	LacksDMA(const char * label_init = "empty", int r = 0, const char * color_init = "no color");
	LacksDMA(const AbsDMA & a, const char * color_init);

	virtual void view() const;
};

#endif // LACKSDMA_H_
