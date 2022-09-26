#include <iostream>

using namespace std;

void menu();

int main() {
	char ch = 0;
	bool showmenu = true;

//	while (ch != 'x') {
//		if (showmenu == true)
//			menu();
//		cout << "Proszę podać literę r, p, d lub g: ";
//		cin.get(ch);
//		// cin.get();
//		while (cin.get() != '\n')
//			;
//		showmenu = true;
//
//		switch (ch) {
//		case 'r':
//			cout << "*** Mniam, mniam, pyszny batat!\n";
//			break;
//		case 'p':
//			cout << "*** brzdęk, brzdęk, brzdęk...\n";
//			break;
//		case 'd':
//			cout << "*** DRZEWO\n";
//			break;
//		case 'g':
//			cout << "*** jeden zero dla węgier\n";
//			break;
//		case 'x':
//			break;
//		default:
//			showmenu = false;
//			break;
//		}
//	}

	while (ch != 'x') {
		menu();

		ch = 0;
		while (ch != 'r' && ch != 'p' && ch != 'd' && ch != 'g' && ch != 'x') {
			cout << "Proszę podać literę r, p, d, g lub x: ";
			cin.get(ch);
			while (ch != '\n' && cin.get() != '\n')
				;
		}

		switch (ch) {
		case 'r':
			cout << "*** Mniam, mniam, pyszny batat!\n";
			break;
		case 'p':
			cout << "*** brzdęk, brzdęk, brzdęk...\n";
			break;
		case 'd':
			cout << "*** DRZEWO\n";
			break;
		case 'g':
			cout << "*** jeden zero dla węgier\n";
			break;
		default:
			break;
		}
	}

	return 0;
}

void menu() {
	cout << "r) roślinożerca" << "\t" << "p) pianista" << "\n"
		<< "d) drzewo" << "\t" << "g) gra" << "\n"
		<< "x) wyjście" << "\n";
}
