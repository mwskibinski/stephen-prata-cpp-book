#ifndef EXC_H_
#define EXC_H_

#include <stdexcept>

class bad_hmean : public std::logic_error
{
private:
	double v1;
	double v2;
public:
	bad_hmean(const std::string & s, double a, double b)
		: std::logic_error(s), v1(a), v2(b) {}
	virtual ~bad_hmean() throw() {}

	double get_v1() const;
	double get_v2() const;
};

inline double bad_hmean::get_v1() const {
	return v1;
}
inline double bad_hmean::get_v2() const {
	return v2;
}


class bad_gmean : public std::logic_error
{
private:
	double v1;
	double v2;
public:
	bad_gmean(const std::string & s, double a, double b)
		: std::logic_error(s), v1(a), v2(b) {}
	virtual ~bad_gmean() throw() {}

	double get_v1() const;
	double get_v2() const;
};

inline double bad_gmean::get_v1() const {
	return v1;
}
inline double bad_gmean::get_v2() const {
	return v2;
}

#endif // EXC_H_
