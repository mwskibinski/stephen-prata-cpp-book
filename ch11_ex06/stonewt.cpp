#include <iostream>
#include "stonewt.h"

Stonewt::Stonewt(double lbs) {
	mode = POUNDS;
	pounds = lbs;
	stone = int (lbs) / Lbs_per_stn;
	pds_left = int (lbs) % Lbs_per_stn + lbs - int (lbs);
}
Stonewt::Stonewt(int stn, double lbs) {
	mode = STONE;
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}
Stonewt::Stonewt() {
	mode = STONE;
	stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt() {

}

Stonewt Stonewt::operator+(const Stonewt & right) const {
	return Stonewt(stone + right.stone, pds_left + right.pds_left);
}
Stonewt Stonewt::operator-(const Stonewt & right) const {
	return Stonewt(pounds - right.pounds);
}
Stonewt Stonewt::operator*(double n) const {
	return Stonewt(pounds * n);
}

bool Stonewt::operator==(const Stonewt & right) const {
	return pounds == right.pounds;
}
bool Stonewt::operator!=(const Stonewt & right) const {
	return pounds != right.pounds;
}
bool Stonewt::operator>(const Stonewt & right) const {
	return pounds > right.pounds;
}
bool Stonewt::operator>=(const Stonewt & right) const {
	return pounds >= right.pounds;
}
bool Stonewt::operator<(const Stonewt & right) const {
	return pounds < right.pounds;
}
bool Stonewt::operator<=(const Stonewt & right) const {
	return pounds <= right.pounds;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s) {
	if (s.mode == Stonewt::STONE)
		os << s.stone << " kamieni, " << s.pds_left << " funtów ";
	else if (s.mode == Stonewt::POUNDS)
		os << s.pounds << " funtów ";
	else if (s.mode == Stonewt::POUNDS_NO_FRACTION)
		os << int (s.pounds) << " funtów ";
	else
		os << "*** Błąd: Niewłaściwy stan obiektu.\n";
	return os;
}
