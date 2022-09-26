#include <iostream>
using namespace std;
#include <cstring>
struct stringy {
	char * str;
	int ct;
};

void set(stringy & rs, const char * init);
void show(const stringy & crs, int show_n = 1);
void show(const char * ccp, int show_n = 1);

int main() {
	stringy beany {};
	// char testing[] = "Rzeczywistość to już nie to, co kiedyś.";
	char testing[] = "Rze";

	cout << (unsigned *) beany.str << endl;

	set(beany, testing);
	// set(beany, "");

	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Gotowe!");

	cout << "************\n";

	cout << beany.str << endl;
	cout << beany.ct << endl;

	delete [] beany.str;

	return 0;
}

void set(stringy & rs, const char * init) {
	// W zasadzie, to dobrze byłoby czyścić pamięć na początku, ale na samym początku to wskaźnik jest nie zainicjalizowany.
	// Trzeba by go initować nullptrem.
	delete [] rs.str;

	int n = strlen(init);
	rs.str = new char [n + 1];
	strcpy(rs.str, init);
	rs.ct = n;
}
void show(const stringy & crs, int show_n) {
	cout << "--- void show(const stringy & crs, int show_n) {" << endl;
	while (show_n-- > 0)
		cout << crs.str << endl;
}
void show(const char * ccp, int show_n) {
	cout << "--- void show(const char * ccp, int show_n) {" << endl;
	while (show_n-- > 0)
		cout << ccp << endl;
}
