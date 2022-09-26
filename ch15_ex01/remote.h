#ifndef REMOTE_H_
#define REMOTE_H_

#include <iostream>
#include "tv.h"

class Tv;

class Remote {
public:
	friend class Tv;
private:
	Input mode;
	enum class RemoteMode {Normal, Interactive} remoteMode;
public:
	Remote(Input m = Input::TV, RemoteMode r = RemoteMode::Normal)
		: mode(m), remoteMode(r) {}

	bool volup(Tv & t);
	bool voldown(Tv & t);
	void onoff(Tv & t);
	void chanup(Tv & t);
	void chandown(Tv & t);
	void set_mode(Tv & t);
	void set_input(Tv & t);
	void set_chan(Tv & t, int c);

	void showRemoteMode() const;
};

inline bool Remote::volup(Tv & t) {
	return t.volup();
}
inline bool Remote::voldown(Tv & t) {
	return t.voldown();
}
inline void Remote::onoff(Tv & t) {
	t.onoff();
}
inline void Remote::chanup(Tv & t) {
	t.chanup();
}
inline void Remote::chandown(Tv & t) {
	t.chandown();
}
inline void Remote::set_mode(Tv & t) {
	t.set_mode();
}
inline void Remote::set_input(Tv & t) {
	t.set_input();
}
inline void Remote::set_chan(Tv & t, int c) {
	t.channel = c;
}

#endif // REMOTE_H_
