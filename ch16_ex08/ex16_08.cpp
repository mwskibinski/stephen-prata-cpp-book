#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void print_name(const std::string & str) {
	std::cout << str << '\n';
}

int main() {
	using std::cout;
	using std::cin;
	using std::vector;
	using std::string;

	vector<string> bolek_names;
	vector<string> lolek_names;

	string tmp;

	cout << "\tImiona Bolka:\n";
	cout << "> ";
	while (cin >> tmp && tmp != "koniec") {
		bolek_names.push_back(tmp);
		cout << "> ";
	}
	sort(bolek_names.begin(), bolek_names.end());

	cout << "\tImiona Lolka:\n";
	cout << "> ";
	while (cin >> tmp && tmp != "koniec") {
		lolek_names.push_back(tmp);
		cout << "> ";
	}
	sort(lolek_names.begin(), lolek_names.end());

	cout << '\n';

	vector<string> bl_names(bolek_names.size() + lolek_names.size());
	auto first_half = copy(bolek_names.begin(), bolek_names.end(), bl_names.begin());
	copy(lolek_names.begin(), lolek_names.end(), first_half);
	sort(bl_names.begin(), bl_names.end());
	auto uniq_end = unique(bl_names.begin(), bl_names.end());
	bl_names.erase(uniq_end, bl_names.end());

	cout << "***\tScalona posortowana lista unikalnych imion:\n";
	std::for_each(bl_names.begin(), bl_names.end(), print_name);

	return 0;
}
