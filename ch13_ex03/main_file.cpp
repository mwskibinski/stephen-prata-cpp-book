#include <iostream>
#include <cstring>
#include "absdma.h"
#include "basedma.h"
#include "lacksdma.h"
#include "hasdma.h"

const int ARR_SIZE = 5;
const int TEXT_SIZE = 100;

int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	AbsDMA * ap[ARR_SIZE];
	char label_tmp[TEXT_SIZE];
	char style_tmp[TEXT_SIZE];
	char color_tmp[TEXT_SIZE];
	int rating_tmp;
	char type = '0';

	for (int i = 0; i < ARR_SIZE; i++) {
		cout << "--- i: " << i << endl;

		cout << "Wybierz typ nowo utworzonego obiektu: (1) BaseDMA, (2) LacksDMA, (3) HasDMA: ";
		while ((cin >> type) && type != '1' && type != '2' && type != '3') {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Niepoprawny typ. Podaj jeszcze raz.\n";
			cout << "(1) BaseDMA, (2) LacksDMA, (3) HasDMA: ";
		}
		while (cin.get() != '\n')
			continue;

		cout << "Wprowadź wartość 'label': ";
		cin.getline(label_tmp, TEXT_SIZE);

		cout << "Wprowadź wartość 'rating': ";
		(cin >> rating_tmp).get();

		switch (type) {
		case '1':
			ap[i] = new BaseDMA(label_tmp, rating_tmp);
			break;
		case '2':
			cout << "Wprowadź wartość 'color': ";
			cin.getline(color_tmp, TEXT_SIZE);
			ap[i] = new LacksDMA(label_tmp, rating_tmp, color_tmp);
			break;
		case '3':
			cout << "Wprowadź wartość 'style': ";
			cin.getline(style_tmp, TEXT_SIZE);
			ap[i] = new HasDMA(label_tmp, rating_tmp, style_tmp);
			break;
		default:
			break;
		}
	}
	cout << endl;

	for (int i = 0; i < ARR_SIZE; i++) {
		ap[i]->view();
		cout << endl;
		delete ap[i];
	}
	cout << "Gotowe!\n";

	return 0;
}
