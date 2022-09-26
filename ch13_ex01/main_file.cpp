#include <iostream>
#include "classic.h"
#include "cd.h"

using namespace std;

void bravo(const Cd & disk);

int main() {
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Sonata fortepianowa B-dur, Fantazja C-moll",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;

	cout << "Bezpośrednie użycie obiektu:\n";
	c1.report();
	c2.report();
	cout << '\n';

	cout << "Użycie wskaźnika na typ Cd:\n";
	pcd->report();
	pcd = &c2;
	pcd->report();
	cout << '\n';

	cout << "Wywołanie funkcji z argumentem w postaci referencji do typu Cd:\n";
	bravo(c1);
	bravo(c2);
	cout << '\n';

	cout << "Test przypisania:\n";
	Classic copy;
	copy = c2;
	copy.report();
	cout << '\n';

	return 0;
}

void bravo(const Cd & disk) {
	disk.report();
}
