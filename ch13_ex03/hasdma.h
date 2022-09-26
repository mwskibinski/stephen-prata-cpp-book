#ifndef HASDMA_H_
#define HASDMA_H_

#include "absdma.h"

class HasDMA : public AbsDMA
{
	char * style;
public:
	HasDMA(const char * label_init = "empty", int r = 0, const char * style_init = "no style");
	HasDMA(const AbsDMA & a, const char * style_init);
	HasDMA(const HasDMA & h);
	virtual ~HasDMA();

	virtual void view() const;

	HasDMA & operator=(const HasDMA & h);
};

#endif // HASDMA_H_
