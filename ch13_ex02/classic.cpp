#include "classic.h"
#include <cstring>
#include <iostream>

Classic::Classic(const char * mt, const char * s1, const char * s2, int n, double x)
	: Cd(s1, s2, n, x)
{
	mainTrack = new char[std::strlen(mt) + 1];
	std::strcpy(mainTrack, mt);
}
Classic::Classic(const char * mt, const Cd & d)
	: Cd(d)
{
	mainTrack = new char[std::strlen(mt) + 1];
	std::strcpy(mainTrack, mt);
}
Classic::Classic(const Classic & cl)
	 : Cd(cl)
{
	mainTrack = new char[std::strlen(cl.mainTrack) + 1];
	std::strcpy(mainTrack, cl.mainTrack);
}
Classic::Classic() {
	const char * init_text = "- no main track -";
	mainTrack = new char[std::strlen(init_text) + 1];
	std::strcpy(mainTrack, init_text);
}
Classic::~Classic() {
	delete [] mainTrack;
}

void Classic::report() const {
	Cd::report();
	std::cout << "Główny utwór: " << mainTrack << '\n';
}
Classic & Classic::operator=(const Classic & cl) {
	if (this != &cl) {
		Cd::operator=(cl);
		delete [] mainTrack;
		mainTrack = new char[std::strlen(cl.mainTrack) + 1];
		std::strcpy(mainTrack, cl.mainTrack);
	}
	return *this;
}
