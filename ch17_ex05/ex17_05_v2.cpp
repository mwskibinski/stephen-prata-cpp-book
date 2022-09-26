#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>

int main() {
	using namespace std;

	ifstream bolek_file("bolek.dat");
	// list<string> bolek_friends;
	list<string> friends;
	string name;

	while (bolek_file >> name)
		friends.push_back(name);
	friends.sort();

	cout << "--- Przyjaciele Bolka:\n";
	for (const auto & x : friends)
		cout << x << '\n';
	cout << '\n';

	ifstream lolek_file("lolek.dat");
	list<string> lolek_friends;

	while (lolek_file >> name)
		lolek_friends.push_back(name);
	lolek_friends.sort();

	cout << "--- Przyjaciele Lolka:\n";
	for (const auto & x : lolek_friends)
		cout << x << '\n';
	cout << '\n';

//	list<string> friends(bolek_friends.size() + lolek_friends.size());
//	auto first_part = copy(bolek_friends.begin(), bolek_friends.end(), friends.begin());
//	copy(lolek_friends.begin(), lolek_friends.end(), first_part);
//	friends.sort();
//	friends.unique();

	friends.merge(lolek_friends);
	friends.unique();

//	cout << "--- Lista przyjaciół:\n";
//	for (const auto & x : friends)
//		cout << x << '\n';
//	cout << '\n';

	ofstream friends_file("bolilol.dat");
	for (const auto & x : friends)
		friends_file << x << '\n';

	cout << "Koniec.\n";

	bolek_file.close();
	lolek_file.close();
	friends_file.close();

	return 0;
}
