#ifndef PORT_H_
#define PORT_H_

#include <iostream>

class Port {
	enum {STYLE_LEN = 20};
	char * brand;
	char style[STYLE_LEN];
	int bottles;
public:
	Port(const char * br = "Brak", const char * st = "Brak", int b = 0);
	Port(const Port & p);
	virtual ~Port() {
		delete [] brand;
	}

	Port & operator=(const Port & p);
	Port & operator+=(int b);
	Port & operator-=(int b);

	int bottleCount() const {
		return bottles;
	}
	virtual void show() const;

	friend std::ostream & operator<<(std::ostream & os, const Port & p);
};

#endif // PORT_H_
