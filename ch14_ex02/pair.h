#ifndef PAIR_H_
#define PAIR_H_

template <typename T1, typename T2>
class Pair {
	T1 a;
	T2 b;
public:
	Pair() {}
	Pair(const T1 & aval, const T2 & bval)
		: a(aval), b(bval) {}

	T1 & first() {
		return a;
	}
	T2 & second() {
		return b;
	}
	T1 first() const {
		return a;
	}
	T2 second() const {
		return b;
	};
};

#endif // PAIR_H_
