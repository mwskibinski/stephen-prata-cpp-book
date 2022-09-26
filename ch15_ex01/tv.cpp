#include "tv.h"
#include <iostream>

bool Tv::volup() {
	if (volume < MaxVal) {
		volume++;
		return true;
	} else
		return false;
}

bool Tv::voldown() {
	if (volume > MinVal) {
		volume--;
		return true;
	} else
		return false;
}

void Tv::chanup() {
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}

void Tv::chandown() {
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}

void Tv::settings() const {
	using std::cout;
	using std::endl;

	cout << "Telewizor jest " << (state == State::Off ? "Wyłączony" : "Włączony") << endl;
	if (state == State::On) {
		cout << "Głośność = " << volume << endl;
		cout << "Program = " << channel << endl;
		cout << "Tryb = " << (mode == Mode::Antenna ? "antena" : "kabel") << endl;
		cout << "Wejście = " << (input == Input::TV ? "TV" : "DVD") << endl;
	}
}
