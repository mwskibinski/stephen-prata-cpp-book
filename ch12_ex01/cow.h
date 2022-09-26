#ifndef COW_H_
#define COW_H_

class Cow {
	enum {NAME_LEN = 20};
	char name[NAME_LEN];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	void showCow() const;
};

#endif // COW_H_
