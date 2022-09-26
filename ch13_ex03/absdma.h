#ifndef ABSDMA_H_
#define ABSDMA_H_

class AbsDMA {
	char * label;
	int rating;
public:
	AbsDMA(const char * label_init = "empty", int r = 0);
	AbsDMA(const AbsDMA & a);
	virtual ~AbsDMA();

	virtual void view() const = 0;

	AbsDMA & operator=(const AbsDMA & a);
};

#endif // ABSDMA_H_
