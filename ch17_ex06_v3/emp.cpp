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
	int str_size = fName.size();
	fout.write((char *) &str_size, sizeof str_size);
	fout.write((char *) fName.data(), str_size);

	str_size = lName.size();
	fout.write((char *) &str_size, sizeof str_size);
	fout.write((char *) lName.data(), str_size);

	str_size = job.size();
	fout.write((char *) &str_size, sizeof str_size);
	fout.write((char *) job.data(), str_size);
}

void AbstrEmp::getAll(std::fstream & fin) {
	int str_size = 0;
	fin.read((char *) &str_size, sizeof str_size);
	fName = std::string(str_size, ' ');
	fin.read((char *) &fName[0], str_size);

	str_size = 0;
	fin.read((char *) &str_size, sizeof str_size);
	lName = std::string(str_size, ' ');
	fin.read((char *) &lName[0], str_size);

	str_size = 0;
	fin.read((char *) &str_size, sizeof str_size);
	job = std::string(str_size, ' ');
	fin.read((char *) &job[0], str_size);
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
	int ck = int(classkind::Employee);
	fout.write((char *) &ck, sizeof ck);
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
	int ck = int(classkind::Manager);
	fout.write((char *) &ck, sizeof ck);
	AbstrEmp::writeAll(fout);
	fout.write((char *) &inChargeOf, sizeof inChargeOf);
}

void Manager::getAll(std::fstream & fin) {
	AbstrEmp::getAll(fin);
	fin.read((char *) &inChargeOf, sizeof inChargeOf);
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
	int ck = int(classkind::Fink);
	fout.write((char *) &ck, sizeof ck);

	AbstrEmp::writeAll(fout);

	int str_len = reportsTo.size();
	fout.write((char *) &str_len, sizeof str_len);
	fout.write((char *) reportsTo.data(), str_len);
}

void Fink::getAll(std::fstream & fin) {
	AbstrEmp::getAll(fin);

	int str_len = 0;
	fin.read((char *) &str_len, sizeof str_len);
	reportsTo = std::string(str_len, ' ');
	fin.read((char *) &reportsTo[0], str_len);
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
	int ck = int(classkind::HighFink);
	fout.write((char *) &ck, sizeof ck);

	AbstrEmp::writeAll(fout);

	int ico = getInChargeOf();
	fout.write((char *) &ico, sizeof ico);

	int str_len = getReportsTo().size();
	fout.write((char *) &str_len, sizeof str_len);
	fout.write((char *) getReportsTo().data(), str_len);
}

void HighFink::getAll(std::fstream & fin) {
	AbstrEmp::getAll(fin);

	fin.read((char *) &getInChargeOf(), sizeof getInChargeOf());

	int str_len = 0;
	fin.read((char *) &str_len, sizeof str_len);
	getReportsTo() = std::string(str_len, ' ');
	fin.read((char *) &getReportsTo()[0], str_len);
}
