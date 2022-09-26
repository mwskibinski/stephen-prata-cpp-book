#include <iostream>

class Cpmv {
public:
	struct Info {
		std::string qcode;
		std::string zcode;
	};
private:
	Info * pi;
public:
	Cpmv();
	Cpmv(const std::string & q, const std::string & z);
	Cpmv(const Cpmv & cp);
	Cpmv(Cpmv && mv);
	~Cpmv();

	Cpmv & operator=(const Cpmv & cp);
	Cpmv & operator=(Cpmv && cp);
	Cpmv operator+(const Cpmv & obj) const;

	void display();
};

Cpmv::Cpmv()
	: pi(nullptr)
{
	std::cout << "ctor default\n";
}

Cpmv::Cpmv(const std::string & q, const std::string & z)
	: pi(new Info {q, z})
{
	std::cout << "ctor (str, str)\n";
}

Cpmv::Cpmv(const Cpmv & cp)
	: pi(new Info {cp.pi->qcode, cp.pi->zcode})
{
	std::cout << "ctor copy\n";
}

Cpmv::Cpmv(Cpmv && cp) {
	std::cout << "ctor move\n";
	pi = cp.pi;
	cp.pi = nullptr;
}

Cpmv::~Cpmv() {
	std::cout << "dtor\n";
	delete pi;
}

Cpmv & Cpmv::operator=(const Cpmv & cp) {
	std::cout << "copy assign=\n";
	if (&cp != this) {
		delete pi;
		pi = new Info {cp.pi->qcode, cp.pi->zcode};
	}
	return *this;
}

Cpmv & Cpmv::operator=(Cpmv && cp) {
	std::cout << "move assign=\n";
	if (&cp != this) {
		delete pi;
		pi = cp.pi;
		cp.pi = nullptr;
	}
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const {
	std::cout << "operator+\n";
	return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
}

void Cpmv::display() {
	if (pi != nullptr) {
		std::cout << "qcode: " << pi->qcode << '\n';
		std::cout << "zcode: " << pi->zcode << '\n';
	} else {
		std::cout << "obiekt pusty\n";
	}
}


int main() {
	using namespace std;

	// Konstrukcja
	Cpmv c, c1("Alfa", "Beta"), c2("Sosnowiec", "Silesia");
	cout << '\n';

	// Dane obiektów
	cout << "--- c:\n";
	c.display();
	cout << "--- c1:\n";
	c1.display();
	cout << "--- c2:\n";
	c2.display();
	cout << '\n';

	// Konstruktor kopiujący i przenoszący (teoretycznie)
	Cpmv c3(c1), c4(c1 + c2);

	// Dane tych obiektów
	cout << '\n';
	cout << "--- c3:\n";
	c3.display();
	cout << "--- c4:\n";
	c4.display();
	cout << '\n';

	// Wymuszenie użycia konstruktora przenoszącego
	Cpmv c5(static_cast<Cpmv &&>(c2));

	// Obiekt skonstruowany i źródłowy
	cout << '\n';
	cout << "--- c5:\n";
	c5.display();
	cout << "--- c2:\n";
	c2.display();
	cout << '\n';

	// Przypisanie kopiujące
	c2 = c5;

	// Dane
	cout << '\n';
	cout << "--- c5:\n";
	c5.display();
	cout << "--- c2:\n";
	c2.display();
	cout << '\n';

	// Przypisanie przenoszące
	c2 = move(c5);

	// Dane
	cout << '\n';
	cout << "--- c5:\n";
	c5.display();
	cout << "--- c2:\n";
	c2.display();
	cout << '\n';

	cout << "k o n i e c\n";
	cout << '\n';

	return 0;
}
