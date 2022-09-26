#ifndef TV_H_
#define TV_H_

enum class State {Off, On};
enum class Mode {Antenna, Cable};
enum class Input {TV, DVD};

class Remote;

class Tv {
public:
	enum {MinVal, MaxVal = 20};
	friend class Remote;
private:
	State state;
	int volume;
	int maxchannel;
	int channel;
	Mode mode;
	Input input;
public:
	Tv(State s = State::Off, int mc = 125)
		: state(s), volume(5), maxchannel(mc), channel(2),
			mode(Mode::Cable), input(Input::TV) {}

	void onoff() {
		state = (state == State::On) ? State::Off : State::On;
	}
	bool ison() const {
		return state == State::On;
	}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() {
		mode = (mode == Mode::Antenna) ? Mode::Cable : Mode::Antenna;
	}
	void set_input() {
		input = (input == Input::TV) ? Input::DVD : Input::TV;
	}
	void settings() const;

	void changeRemoteMode(Remote & r);
};

#endif // TV_H_
