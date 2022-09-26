#include <iostream>
#include "move.h"

int main() {
	using namespace std;

	Move m1, m2(2.34), m3(5.55, -10.111);
	m1.showmove();
	m2.showmove();
	m3.showmove();

	cout << "\tUżycie funkcji add:\n";
	Move m_add = m2.add(m3);
	m_add.showmove();

	cout << "\tUżycie funkcji reset:\n";
	m1.reset(9, 9);
	m2.reset(-111, -222);
	m3.reset(3.14159, 2.718);

	m1.showmove();
	m2.showmove();
	m3.showmove();

	return 0;
}
