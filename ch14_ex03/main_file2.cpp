#include <iostream>
#include "queuetp.h"
#include "workermi.h"
// #include <ctime>
// #include <cstdlib>
#include <cstring>

int main() {
	using std::cout;
	using std::endl;
	using std::cin;
	using std::strchr;

	using WorkerPtrQueue = QueueTP<Worker *>;

	const int Q_SIZE = 5;

	WorkerPtrQueue wpq(Q_SIZE);
	Worker * tmp_elem = nullptr;

	int ct = 0;
	char choice = 0;
	for (ct = 0; ct < Q_SIZE; ct++) {
		cout << "Podaj kategorię pracownika:\n"
			<< "k: kelner, p: piosenkarz, s: śpiewający kelner;   w: wyjście\n";
		cin >> choice;
		while (strchr("kpsw", choice) == NULL) {
			cout << "Wpisz k, p, s lub w: ";
			cin >> choice;
		}
		cin.get();

		if (choice == 'w')
			break;

		switch (choice) {
		case 'k': case 'K':
			tmp_elem = new Waiter;
			break;
		case 'p': case 'P':
			tmp_elem = new Singer;
			break;
		case 's': case 'S':
			tmp_elem = new SingingWaiter;
			break;
		}

		tmp_elem->Set();
		wpq.enQueue(tmp_elem);
	}

	cout << "\nLista pracowników:\n";
	 for (int i = 0; i < ct; i++) {
		cout << endl;
		wpq.deQueue(tmp_elem);
		tmp_elem->Show();
		delete tmp_elem;
	}

	cout << "\n\tKoniec\n";

	return 0;
}
