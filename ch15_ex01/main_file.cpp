#include <iostream>

#include "tv.h"
#include "remote.h"

int main() {
	Tv t;
	Remote r;

	t.settings();
	t.onoff();
	t.settings();

	r.set_chan(t, 30);
	t.settings();

	r.showRemoteMode();
	t.changeRemoteMode(r);
	r.showRemoteMode();
	t.onoff();
	t.changeRemoteMode(r);
	r.showRemoteMode();

	return 0;
}
