#include <iostream>
#include <list>
#include <string>
#include <algorithm>

void print_name(const std::string & str) {
	std::cout << str << '\n';
}

int main() {
	using std::cout;
	using std::cin;
	using std::list;
	using std::string;

	list<string> bolek_names;
	list<string> lolek_names;

	string tmp;

	cout << "\tImiona Bolka <\"koniec\", by skończyć>:\n";
	cout << "> ";
	while (cin >> tmp && tmp != "koniec") {
		bolek_names.push_back(tmp);
		cout << "> ";
	}
	bolek_names.sort();

	cout << "\tImiona Lolka <\"koniec\", by skończyć>:\n";
	cout << "> ";
	while (cin >> tmp && tmp != "koniec") {
		lolek_names.push_back(tmp);
		cout << "> ";
	}
	lolek_names.sort();

	cout << '\n';

	list<string> bl_names(bolek_names.size() + lolek_names.size());
	auto first_half = copy(bolek_names.begin(), bolek_names.end(), bl_names.begin());
	copy(lolek_names.begin(), lolek_names.end(), first_half);
	bl_names.sort();
	bl_names.unique();

	cout << "***\tScalona posortowana lista unikalnych imion:\n";
	std::for_each(bl_names.begin(), bl_names.end(), print_name);

	return 0;
}
