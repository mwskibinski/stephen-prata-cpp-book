#include <iostream>
#include <cctype>
#include "stack.h"
#include "customer.h"

int main() {
	using namespace std;

	Stack stack;
	customer cst {0};
	char ch = 0;
	double payment = 0.0;
	cout << "1 -- umieść strukturę na stosie. 2 -- ściągnij strukturę ze stosu. Q -- wyjdź\n";
	while (cin.get(ch) && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			;

		switch (ch) {
		case '1':
			// cst = getCustomer();
			initCustomer(cst);
			if (!stack.push(cst))
				cout << "\tStos jest pełny!\n";
			break;
		case '2':
			if (!stack.pop(cst))
				cout << "\tStos jest pusty!\n";
			else {
				payment += cst.payment;
				cout << "\tSuma należności: " << payment << endl;
			}
			break;
		default:
			cout << "\tNiewłaściwa opcja. Wybierz ponownie.\n";
			break;
		}

		cout << "1 -- umieść strukturę na stosie. 2 -- ściągnij strukturę ze stosu. Q -- wyjdź\n";
	}

	return 0;
}

customer getCustomer() {
	customer tmp;
	std::cout << "Imię klienta: ";
	std::cin.getline(tmp.fullname, 35);
	std::cout << "Należności klienta: ";
	(std::cin >> tmp.payment).get();

	return tmp;
}
void initCustomer(customer & c) {
	std::cout << "Imię klienta: ";
	std::cin.getline(c.fullname, 35);
	std::cout << "Należności klienta: ";
	// Nie chce mi się myśleć o niewłaściwych wartościach.
	(std::cin >> c.payment).get();
}
