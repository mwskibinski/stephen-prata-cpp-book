#include "remote.h"

void Remote::showRemoteMode() const {
	std::cout << "Tryb pracy pilota = "
		<< (remoteMode == RemoteMode::Normal ? "normalny" : "interaktywny")
		<< '\n';
}

void Tv::changeRemoteMode(Remote & r) {
	if (state == State::On) {
		r.remoteMode =
			(r.remoteMode == Remote::RemoteMode::Normal) ?
			Remote::RemoteMode::Interactive : Remote::RemoteMode::Normal;
	}
}
