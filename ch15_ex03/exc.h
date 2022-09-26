#ifndef EXC_H_
#define EXC_H_

#include <stdexcept>

class bad_mean : public std::logic_error
{
private:
	double v1;
	double v2;
	std::string funcName;
public:
	bad_mean(const std::string & s, double a, double b, const std::string & fn)
		: std::logic_error(s), v1(a), v2(b), funcName(fn) {}
	virtual ~bad_mean() throw() = 0;

	double get_v1() const;
	double get_v2() const;
	const std::string & get_funcName() const;
};

inline double bad_mean::get_v1() const {
	return v1;
}
inline double bad_mean::get_v2() const {
	return v2;
}
inline const std::string & bad_mean::get_funcName() const {
	return funcName;
}

class bad_hmean : public bad_mean
{
public:
	bad_hmean(const std::string & s, double a, double b)
		: bad_mean(
			"*** Wyjątek. Nazwa funkcji: hmean. Błąd: argument a nie może wynosić -b",
			a, b, "double hmean(double, double)"
		) {}
	virtual ~bad_hmean() {}
};

class bad_gmean : public bad_mean
{
public:
	bad_gmean(const std::string & s, double a, double b)
		: bad_mean(
			"*** Wyjątek. Nazwa funkcji: gmean. Błąd: żaden z argumentów nie może być ujemny",
			a, b, "double gmean(double, double)"
		) {}
	virtual ~bad_gmean() {}
};

#endif // EXC_H_
