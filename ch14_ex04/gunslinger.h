#ifndef GUNSLINGER_H_
#define GUNSLINGER_H_

#include "person.h"

class Gunslinger : virtual public Person
{
private:
	double drawTime;
	int notches;
protected:
	void showUnique() const;
	void setUnique();
public:
	Gunslinger(const std::string & fn = "brak", int a = 0, double dt = 0.0, int n = 0);
	Gunslinger(const Person & p, double dt, int n);
	virtual ~Gunslinger();

	virtual void show() const;
	virtual void set();

	double draw() const;
	int getNotches() const;
	void setDrawTime(double dt);
	void setNotches(int n);
};

inline double Gunslinger::draw() const
{
	return drawTime;
}
inline int Gunslinger::getNotches() const
{
	return notches;
}
inline void Gunslinger::setDrawTime(double dt)
{
	drawTime = dt;
}
inline void Gunslinger::setNotches(int n)
{
	notches = n;
}

#endif // GUNSLINGER_H_
