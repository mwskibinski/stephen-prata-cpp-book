#include "classic.h"
#include <cstring>
#include <iostream>

Classic::Classic(const char * mt, const char * s1, const char * s2, int n, double x)
	: Cd(s1, s2, n, x)
{
	std::strncpy(mainTrack, mt, MAINTRACK_LEN-1);
	mainTrack[MAINTRACK_LEN-1] = '\0';
}
Classic::Classic(const char * mt, const Cd & d)
	: Cd(d)
{
	std::strncpy(mainTrack, mt, MAINTRACK_LEN-1);
	mainTrack[MAINTRACK_LEN-1] = '\0';
}
Classic::Classic(const Classic & cl)
	 : Cd(cl)
{
	std::strcpy(mainTrack, cl.mainTrack);
}
Classic::Classic() {
	std::strcpy(mainTrack, "- no main track -");
}
Classic::~Classic() {

}

void Classic::report() const {
	Cd::report();
	std::cout << "Główny utwór: " << mainTrack << '\n';
}
