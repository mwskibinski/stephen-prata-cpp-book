#ifndef BASEDMA_H_
#define BASEDMA_H_

#include "absdma.h"

class BaseDMA : public AbsDMA
{
public:
	BaseDMA(const char * label_init = "empty", int r = 0);
	BaseDMA(const AbsDMA & a);

	virtual void view() const;
};

#endif // BASEDMA_H_
