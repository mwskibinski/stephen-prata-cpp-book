#include <iostream>
#include "list.h"

int main() {
	using namespace std;

	cout << "\tKonstrukcja listy.\n";
	List lst;
	Item it1 = 0.5;

	cout << "\tZwrócenie elementu nr 2 i wartość elementu pomocnicznego.\n";
	cout << "it1: " << it1 << "\n";
	lst.check(it1, 2);
	cout << "it1: " << it1 << "\n";

	cout << "\tDodanie pięciu elementów.\n";
	lst.add(1.56);
	lst.add(5.67);
	lst.add(-0.555);
	lst.add(1.1e+3);
	lst.add(8.7);

	cout << "\tWprowadzone elementy.\n";
	lst.printList();

	cout << "\tUsuwam dwa elementy.\n";
	lst.remove();
	lst.remove();

	cout << "\tPo dwukrotnym użyciu metody remove:\n";
	lst.printList();

	cout << "\tPo trzykrotnym dodaniu nowych elementów:\n";
	lst.add(111.111);
	lst.add(222.222);
	lst.add(333.333);

	lst.printList();

	cout << "\tStan listy.\n";
	cout << "isempty: " << lst.isempty() << ", isfull: " << lst.isfull() << "\n";

	cout << "\tOpróżnienie całej listy.\n";
	while (lst.remove())
		;

	cout << "\tStan listy.\n";
	cout << "isempty: " << lst.isempty() << ", isfull: " << lst.isfull() << "\n";

	cout << "\tZapełnienie całej listy:\n";
	for (unsigned i = 0u; lst.add(5*i*i + 4.5*i - 8.12); i++)
		;

	cout << "\tStan listy.\n";
	cout << "isempty: " << lst.isempty() << ", isfull: " << lst.isfull() << "\n";

	cout << "\tOpróżnienie całej listy.\n";
	while (lst.remove())
		;
	cout << "\tStan listy.\n";
	cout << "isempty: " << lst.isempty() << ", isfull: " << lst.isfull() << "\n";

	void square(Item &);
	void cube(Item &);
	void mod13(Item &);

	void (*fnc_ar[])(Item &) = {square, cube, mod13};
	int fnc_ar_n = (sizeof fnc_ar) / (sizeof fnc_ar[0]);
	const char *fnc_names[] = {"square", "cube", "mod13"};

	cout << "\tDodaję sześć liczb.\n";
	lst.add(1);
	lst.add(-1);
	lst.add(5.0999);
	lst.add(420.69);
	lst.add(21.37e+4);
	lst.add(15);

	cout << "\tWartości początkowe.\n";
	lst.printList();

	List lst_copy = lst;

	for (int i = 0; i < fnc_ar_n; i++) {
		cout << "--- i = " << i << endl;
		cout << "Używam funkcji: " << fnc_names[i] << endl;
		lst.visit(fnc_ar[i]);
		cout << "Lista po modyfikacji:\n";
		lst.printList();
		lst = lst_copy;
	}

	return 0;
}

void square(Item & a) {
	a = a*a;
}
void cube(Item & a) {
	a = a*a*a;
}
void mod13(Item & a) {
	a = int (a) % 13;
}
