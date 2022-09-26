#include <iostream>
#include "stonewt.h"

int main() {
	using namespace std;

	Stonewt a, b(10), c(3, 6), d(2, 3.45);

	cout << "*** Testowanie przeciążonego operatora << funkcją zaprzyjaźnioną.\n";
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;

	cout << "*** Testowanie funkcji zmieniającej stan.\n";
	cout << "*** Reprezentacja kamienna\n";
	a.stoneMode();
	b.stoneMode();
	c.stoneMode();
	d.stoneMode();
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;

	cout << "*** Reprezentacja funtowa\n";
	a.poundsMode();
	b.poundsMode();
	c.poundsMode();
	d.poundsMode();
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;

	cout << "*** Reprezentacja funtowa bez ułamka\n";
	a.poundsNoFractionMode();
	b.poundsNoFractionMode();
	c.poundsNoFractionMode();
	d.poundsNoFractionMode();
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;

	cout << "*** Testowanie przeciążonych operatorów arytmetycznych\n";
	cout << "b + c = " << b + c << endl;
	cout << "c - d = " << c - d << endl;
	cout << "(a + 2.3) * 5.6 = " << (a + 2.3) * 5.6 << endl;
	cout << "0.1 * d = " << 0.1 * d << endl;

	return 0;
}
