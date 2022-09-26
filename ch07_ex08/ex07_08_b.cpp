#include <iostream>
#include <string>

const int Seasons = 4;
const char * Snames[Seasons] = {"Wiosna", "Lato", "Jesień", "Zima"};

struct expenses_stc {
	double expenses[Seasons];
};

void fill(expenses_stc *);
void show(expenses_stc);

int main() {
	expenses_stc exp;
	fill(&exp);
	show(exp);

	return 0;
}

void fill(expenses_stc * pa) {
	using namespace std;
	for (int i = 0; i < Seasons; i++) {
		cout << "Podaj wydatki za okres >>" << Snames[i] << "<<: ";
		cin >> pa->expenses[i];
	}
}
void show(expenses_stc da) {
	using namespace std;
	double total = 0.0;
	cout << "\nWYDATKI\n";
	for (int i = 0; i < Seasons; i++) {
		cout << Snames[i] << ": " << da.expenses[i] << " zł" << endl;
		total += da.expenses[i];
	}
	cout << "Łącznie wydatki roczne: " << total << " zł" << endl;
}
