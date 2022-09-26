#ifndef CD_H_
#define CD_H_

class Cd {
	enum {PERFORMERS_LEN = 50, LABEL_LEN = 20};

	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(const char * s1, const char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();

	virtual void report() const;
	// Cd & operator=(const Cd & d);
};

#endif // CD_H_
