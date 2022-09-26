#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt {
private:
	enum {Lbs_per_stn = 14};
	enum Mode {STONE, POUNDS, POUNDS_NO_FRACTION};
	int stone;
	double pds_left;
	double pounds;
	Mode mode;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();

	void stoneMode() {
		mode = STONE;
	}
	void poundsMode() {
		mode = POUNDS;
	}
	void poundsNoFractionMode() {
		mode = POUNDS_NO_FRACTION;
	}

	Stonewt operator+(const Stonewt & right) const;
	Stonewt operator-(const Stonewt & right) const;
	// Mnożenie implementuję jako mnożenie przez skalar.
	// Nie ma sensu mnożyć dwóch obiektów typu Stonewt, bo wychodzą nieprawidłowe jednostki.
	Stonewt operator*(double n) const;

	friend Stonewt operator*(double n, const Stonewt & right) {
		return right * n;
	}
	friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
};

#endif // STONEWT_H_
