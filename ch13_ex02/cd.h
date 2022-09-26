#ifndef CD_H_
#define CD_H_

class Cd {
	char * performers;
	char * label;
	int selections;
	double playtime;
public:
	Cd(const char * s1, const char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();

	virtual void report() const;
	Cd & operator=(const Cd & d);
};

#endif // CD_H_
