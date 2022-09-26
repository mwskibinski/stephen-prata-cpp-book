#ifndef PLORG_H_
#define PLORG_H_

class Plorg {
private:
	enum { MAX_LEN = 20 };
	char name[MAX_LEN];
	int satietyFactor;
public:
	Plorg(const char * name_init = "Plorg");
	~Plorg();
	void changeSatiety(int sf);
	void print() const;
};

#endif // PLORG_H_
