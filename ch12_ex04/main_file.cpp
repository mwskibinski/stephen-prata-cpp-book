#include <iostream>
#include "stack.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	Item pop_item = 0ul;
	Stack s;

	cout << "\tStos skonstruowany \"domyślnie\"\n";
	cout << "pusty?: " << s.isempty() << '\n';
	cout << "pełny?: " << s.isfull() << '\n';
	cout << '\n';

	cout << "\tZapełnienie stosu losowymi liczbami\n";
	while (s.push(rand() % 50))
		;
	cout << "pusty?: " << s.isempty() << '\n';
	cout << "pełny?: " << s.isfull() << '\n';
	cout << "Liczby:\n";
	for (int i = 0; s.pop(pop_item); i++)
		cout << i << ": " << pop_item << endl;
	cout << '\n';

	cout << "\tPonowne zapełnienie stosu losowymi liczbami\n";
	while (s.push(rand() % 10 + 1000))
		;
	cout << '\n';

	cout << "\tNowy stos (konstruktor kopiujący)\n";
	Stack s_cpy(s);
	cout << "Stos oryginalny:\n";
	cout << "pusty?: " << s.isempty() << '\n';
	cout << "pełny?: " << s.isfull() << '\n';
	cout << "Stos skopiowany:\n";
	cout << "pusty?: " << s_cpy.isempty() << '\n';
	cout << "pełny?: " << s_cpy.isfull() << '\n';
	cout << "Stos oryginalny -- liczby:\n";
	for (int i = 0; s.pop(pop_item); i++)
		cout << i << ": " << pop_item << endl;
	cout << "Stos skopiowany -- liczby:\n";
	for (int i = 0; s_cpy.pop(pop_item); i++)
		cout << i << ": " << pop_item << endl;
	cout << '\n';

	cout << "\tPonowne zapełnienie stosu losowymi liczbami\n";
	while (s.push(rand() % 5 + 9876))
		;
	cout << '\n';

	cout << "\tPrzypisanie stosu do innego\n";
	s_cpy = s;
	cout << "Stos oryginalny:\n";
	cout << "pusty?: " << s.isempty() << '\n';
	cout << "pełny?: " << s.isfull() << '\n';
	cout << "Stos drugi:\n";
	cout << "pusty?: " << s_cpy.isempty() << '\n';
	cout << "pełny?: " << s_cpy.isfull() << '\n';
	cout << "Stos oryginalny -- liczby:\n";
	for (int i = 0; s.pop(pop_item); i++)
		cout << i << ": " << pop_item << endl;
	cout << "Stos drugi -- liczby:\n";
	for (int i = 0; s_cpy.pop(pop_item); i++)
		cout << i << ": " << pop_item << endl;

	cout << "Stos oryginalny:\n";
	cout << "pusty?: " << s.isempty() << '\n';
	cout << "pełny?: " << s.isfull() << '\n';
	cout << "Stos drugi:\n";
	cout << "pusty?: " << s_cpy.isempty() << '\n';
	cout << "pełny?: " << s_cpy.isfull() << '\n';
	cout << '\n';

	return 0;
}
