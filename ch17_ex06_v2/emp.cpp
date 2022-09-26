
#include "emp.h"
#include <iostream>
#include <string>


// AbstrEmp
AbstrEmp::AbstrEmp()
	: fName("brak"), lName("brak"), job("brak")
{}

AbstrEmp::AbstrEmp(const std::string & fn, const std::string & ln, const std::string & j)
	: fName(fn), lName(ln), job(j)
{}

AbstrEmp::~AbstrEmp()
{}

void AbstrEmp::showAll() const
{
	std::cout << "Imię: " << fName << '\n';
	std::cout << "Nazwisko: " << lName << '\n';
	std::cout << "Zawód: " << job << '\n';
}

void AbstrEmp::setAll()
{
	std::cout << "Wprowadź imię.\n" << "> ";
	std::getline(std::cin, fName);

	std::cout << "Wprowadź nazwisko.\n" << "> ";
	std::getline(std::cin, lName);

	std::cout << "Wprowadź zawód.\n" << "> ";
	std::getline(std::cin, job);
}

void AbstrEmp::writeAll(std::fstream & fout) const {
	fout << fName << '\n';
	fout << lName << '\n';
	fout << job << '\n';
}

void AbstrEmp::getAll(std::fstream & fin) {
	std::getline(fin, fName);
	std::getline(fin, lName);
	std::getline(fin, job);
}

std::ostream & operator<<(std::ostream & os, const AbstrEmp & ae)
{
	os << ae.fName << ", " << ae.lName << ", " << ae.job;
	return os;
}


// Employee
Employee::Employee()
	: AbstrEmp()
{}

Employee::Employee(const std::string & fn, const std::string & ln, const std::string & j)
	: AbstrEmp(fn, ln, j)
{}

void Employee::showAll() const
{
	AbstrEmp::showAll();
}

void Employee::setAll()
{
	AbstrEmp::setAll();
}

void Employee::writeAll(std::fstream & fout) const {
	fout << int(classkind::Employee) << '\n';
	AbstrEmp::writeAll(fout);
}

void Employee::getAll(std::fstream & fin) {
	AbstrEmp::getAll(fin);
}


// Manager
Manager::Manager()
	: AbstrEmp(), inChargeOf(0)
{}

Manager::Manager(const std::string & fn, const std::string & ln, const std::string & j, int ico)
	: AbstrEmp(fn, ln, j), inChargeOf(ico)
{}

Manager::Manager(const AbstrEmp & ae, int ico)
	: AbstrEmp(ae), inChargeOf(ico)
{}

Manager::Manager(const Manager & m)
	: AbstrEmp(m), inChargeOf(m.inChargeOf)
{}

void Manager::showAll() const
{
	AbstrEmp::showAll();
	std::cout << "Liczba podwładnych: " << getInChargeOf() << '\n';
}

void Manager::setAll()
{
	AbstrEmp::setAll();

	std::cout << "Wprowadź liczbę podwładnych.\n" << "> ";
	(std::cin >> getInChargeOf()).get();
}

void Manager::writeAll(std::fstream & fout) const {
	fout << int(classkind::Manager) << '\n';
	AbstrEmp::writeAll(fout);
	fout << inChargeOf << '\n';
}

void Manager::getAll(std::fstream & fin) {
	AbstrEmp::getAll(fin);
	fin >> inChargeOf;
}


// Fink
Fink::Fink()
	: AbstrEmp(), reportsTo("brak")
{}

Fink::Fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo)
	: AbstrEmp(fn, ln, j), reportsTo(rpo)
{}

Fink::Fink(const AbstrEmp & ae, const std::string & rpo)
	: AbstrEmp(ae), reportsTo(rpo)
{}

Fink::Fink(const Fink & f)
	: AbstrEmp(f), reportsTo(f.reportsTo)
{}

void Fink::showAll() const
{
	AbstrEmp::showAll();
	std::cout << "Osoba do której donosi: " << getReportsTo() << '\n';
}

void Fink::setAll()
{
	AbstrEmp::setAll();

	std::cout << "Wprowadź osobę do której donosi.\n" << "> ";
	std::getline(std::cin, getReportsTo());
}

void Fink::writeAll(std::fstream & fout) const {
	fout << int(classkind::Fink) << '\n';
	AbstrEmp::writeAll(fout);
	fout << reportsTo << '\n';
}

void Fink::getAll(std::fstream & fin) {
	AbstrEmp::getAll(fin);
	std::getline(fin, reportsTo);
}


// HighFink
HighFink::HighFink()
	: AbstrEmp(), Manager(), Fink()
{}

HighFink::HighFink(
	const std::string & fn, const std::string & ln, const std::string & j,
	const std::string & rpo, int ico
)
	: AbstrEmp(fn, ln, j), Manager(fn, ln, j, ico), Fink(fn, ln, j, rpo)
{}

HighFink::HighFink(const AbstrEmp & ae, const std::string & rpo, int ico)
	: AbstrEmp(ae), Manager(ae, ico), Fink(ae, rpo)
{}

HighFink::HighFink(const Fink & f, int ico)
	: AbstrEmp(f), Manager(f, ico), Fink(f)
{}

HighFink::HighFink(const Manager & m, const std::string & rpo)
	: AbstrEmp(m), Manager(m), Fink(m, rpo)
{}

HighFink::HighFink(const HighFink & h)
	: AbstrEmp(h), Manager(h), Fink(h)
{}

void HighFink::showAll() const
{
	AbstrEmp::showAll();
	std::cout << "Liczba podwładnych: " << getInChargeOf() << '\n';
	std::cout << "Osoba do której donosi: " << getReportsTo() << '\n';

}

void HighFink::setAll()
{
	AbstrEmp::setAll();

	std::cout << "Wprowadź liczbę podwładnych.\n" << "> ";
	(std::cin >> getInChargeOf()).get();

	std::cout << "Wprowadź osobę do której donosi.\n" << "> ";
	std::getline(std::cin, getReportsTo());
}

void HighFink::writeAll(std::fstream & fout) const {
	fout << int(classkind::HighFink) << '\n';
	AbstrEmp::writeAll(fout);
	fout << getInChargeOf() << '\n';
	fout << getReportsTo() << '\n';
}

void HighFink::getAll(std::fstream & fin) {
	AbstrEmp::getAll(fin);
	(fin >> getInChargeOf()).get();
	std::getline(fin, getReportsTo());
}
