#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>
#include <fstream>

enum class classkind {AbstrEmp, Employee, Manager, Fink, HighFink};

class AbstrEmp
{
private:
	std::string fName;
	std::string lName;
	std::string job;
public:
	AbstrEmp();
	AbstrEmp(const std::string & fn, const std::string & ln, const std::string & j);
	virtual ~AbstrEmp() = 0;

	virtual void showAll() const;
	virtual void setAll();
	virtual void writeAll(std::fstream &) const;
	virtual void getAll(std::fstream &);

	friend std::ostream & operator<<(std::ostream & os, const AbstrEmp & ae);
};

class Employee : public AbstrEmp
{
public:
	Employee();
	Employee(const std::string & fn, const std::string & ln, const std::string & j);

	virtual void showAll() const;
	virtual void setAll();
	virtual void writeAll(std::fstream &) const;
	virtual void getAll(std::fstream &);
};

class Manager : virtual public AbstrEmp
{
private:
	int inChargeOf;
protected:
	int getInChargeOf() const { return inChargeOf; }
	int & getInChargeOf() { return inChargeOf; }
public:
	Manager();
	Manager(const std::string & fn, const std::string & ln, const std::string & j, int ico = 0);
	Manager(const AbstrEmp & ae, int ico);
	Manager(const Manager & m);

	virtual void showAll() const;
	virtual void setAll();
	virtual void writeAll(std::fstream &) const;
	virtual void getAll(std::fstream &);
};

class Fink : virtual public AbstrEmp
{
private:
	std::string reportsTo;
protected:
	const std::string & getReportsTo() const { return reportsTo; }
	std::string & getReportsTo() { return reportsTo; }
public:
	Fink();
	Fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo);
	Fink(const AbstrEmp & ae, const std::string & rpo);
	Fink(const Fink & f);

	virtual void showAll() const;
	virtual void setAll();
	virtual void writeAll(std::fstream &) const;
	virtual void getAll(std::fstream &);
};

class HighFink : public Manager, public Fink
{
public:
	HighFink();
	HighFink(
		const std::string & fn, const std::string & ln, const std::string & j,
		const std::string & rpo, int ico
	);
	HighFink(const AbstrEmp & ae, const std::string & rpo, int ico);
	HighFink(const Fink & f, int ico);
	HighFink(const Manager & m, const std::string & rpo);
	HighFink(const HighFink & h);

	virtual void showAll() const;
	virtual void setAll();
	virtual void writeAll(std::fstream &) const;
	virtual void getAll(std::fstream &);
};

#endif // EMP_H_
