#include <iostream>
#include "mytime3.h"

Time::Time() {
	hours = minutes = 0;
}
Time::Time(int h, int m) {
	hours = h;
	minutes = m;
}

void Time::AddMin(int m) {
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::AddHr(int h) {
	hours += h;
}
void Time::Reset(int h, int m) {
	hours = h;
	minutes = m;
}
void Time::Show() const {
	std::cout << hours << " godzin, " << minutes << " minut";
}

Time operator+(const Time & t1, const Time & t2) {
	return Time(
		t1.hours + t2.hours + (t1.minutes + t2.minutes) / 60,
		(t1.minutes + t2.minutes) % 60
	);
}
Time operator-(const Time & t_left, const Time & t_right) {
	int tot_left = t_left.minutes + 60 * t_left.hours;
	int tot_right = t_right.minutes + 60 * t_right.hours;
	return Time((tot_left - tot_right) / 60, (tot_left - tot_right) % 60);
//	if (tot_right > tot_left) {
//		std::cout << "Błąd: czas po prawej nie może być większy od tego po lewej!\n";
//		return Time();
//	} else {
//		return Time((tot_left - tot_right) / 60, (tot_left - tot_right) % 60);
//	}
}
Time operator*(const Time & t, double n) {
	long totalminutes = (t.hours * 60 + t.minutes) * n;
	return Time(totalminutes / 60, totalminutes % 60);
}

ostream & operator<<(ostream & os, const Time & t) {
	os << t.hours << " godzin, " << t.minutes << " minut";
	return os;
}
