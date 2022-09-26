#include <iostream>
#include <cstring>

using namespace std;

const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main() {
	cout << "Podaj wielkość grupy: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++) {
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Gotowe\n";

	return 0;
}

int getinfo(student pa[], int n) {
	cout << "\n--- getinfo ---\n";
	int i = 0;
	for ( ; i < n; i++) {
		cout << "* Student nr " << i+1 << endl;
		cout << "Imię i nazwisko: ";
		cin.getline(pa[i].fullname, SLEN);
		if (!strcmp(pa[i].fullname, ""))
			break;
		cout << "Hobby: ";
		cin.getline(pa[i].hobby, SLEN);
		cout << "Ooplevel: ";
		(cin >> pa[i].ooplevel).get();
		while (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				;
			cout << "Nieprawidłowy poziom. Wprowadź ponownie: ";
			(cin >> pa[i].ooplevel).get();
		}
	}
	return i;
}
void display1(student st) {
	cout << "\n--- display1 ---\n";
	cout << "Dane studenta.\n";
	cout << "Imię i nazwisko: " << st.fullname << endl;
	cout << "Hobby: " << st.hobby << endl;
	cout << "Ooplevel: " << st.ooplevel << endl;
}
void display2(const student * ps) {
	cout << "\n--- display2 ---\n";
	cout << "Dane studenta.\n";
	cout << "Imię i nazwisko: " << ps->fullname << endl;
	cout << "Hobby: " << ps->hobby << endl;
	cout << "Ooplevel: " << ps->ooplevel << endl;
}
void display3(const student pa[], int n) {
	cout << "\n--- display3 ---\n";
	cout << "Dane całej grupy.\n";
	for (int i = 0; i < n; i++) {
		cout << "* Student nr " << i+1 << endl;
		cout << "Imię i nazwisko: " << pa[i].fullname << endl;
		cout << "Hobby: " << pa[i].hobby << endl;
		cout << "Ooplevel: " << pa[i].ooplevel << endl;
	}
}
