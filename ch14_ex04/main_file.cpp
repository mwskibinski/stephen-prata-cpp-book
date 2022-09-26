#include <iostream>
#include <cstring>

#include "person.h"
#include "gunslinger.h"
#include "pokerplayer2.h"
#include "baddude2.h"

int main() {
	using std::cout;
	using std::endl;
	using std::cin;
	using pkCard = PokerPlayer::Card;

	const int MAX = 5;
	Person * person_ptr[MAX];
	int person_n;
	char choice = 0;

	for (person_n = 0; person_n < MAX; person_n++) {
		cout << "Wybierz typ osoby:\n";
		cout << "o: osoba; r: rewolwerowiec; p: pokerzysta; z: zły koleś;   w: wyjście\n";
		cout << "> ";
		cin >> choice;
		while (std::strchr("orpzw", choice) == NULL) {
			cout << "Niepoprawny wybór. Wprowadź typ osoby raz jeszcze:\n";
			cout << "o: osoba; r: rewolwerowiec; p: pokerzysta; z: zły koleś;   w: wyjście\n";
			cout << "> ";
			cin >> choice;
		}
		cin.get();

		if (choice == 'w')
			break;

		switch (choice) {
		case 'o': case 'O':
			person_ptr[person_n] = new Person;
			break;
		case 'r': case 'R':
			person_ptr[person_n] = new Gunslinger;
			break;
		case 'p': case 'P':
			person_ptr[person_n] = new PokerPlayer;
			break;
		case 'z': case 'Z':
			person_ptr[person_n] = new BadDude;
			break;
		default:
			break;
		}
		person_ptr[person_n]->set();

		cout << endl;
	}
	cout << '\n';

	for (int i = 0; i < person_n; i++) {
		cout << "--- i: " << i << '\n';
		person_ptr[i]->show();
		delete person_ptr[i];
	}
	cout << '\n';

	return 0;
}
