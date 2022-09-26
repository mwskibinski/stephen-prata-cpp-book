#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	using namespace std;

	ifstream bolek_file("bolek.dat");
	vector<string> bolek_friends;
	string name;

	while (bolek_file >> name)
		bolek_friends.push_back(name);
	sort(bolek_friends.begin(), bolek_friends.end());

	cout << "--- Przyjaciele Bolka:\n";
	for (const auto & x : bolek_friends)
		cout << x << '\n';
	cout << '\n';

	ifstream lolek_file("lolek.dat");
	vector<string> lolek_friends;

	while (lolek_file >> name)
		lolek_friends.push_back(name);
	sort(lolek_friends.begin(), lolek_friends.end());

	cout << "--- Przyjaciele Lolka:\n";
	for (const auto & x : lolek_friends)
		cout << x << '\n';
	cout << '\n';

	vector<string> friends(bolek_friends.size() + lolek_friends.size());
	auto first_part = copy(bolek_friends.begin(), bolek_friends.end(), friends.begin());
	copy(lolek_friends.begin(), lolek_friends.end(), first_part);
	sort(friends.begin(), friends.end());
	auto uniq_end = unique(friends.begin(), friends.end());
	friends.erase(uniq_end, friends.end());

	cout << "--- Lista przyjaciół:\n";
	for (const auto & x : friends)
		cout << x << '\n';
	cout << '\n';

	ofstream friends_file("bolilol.dat");
	for (const auto & x : friends)
		friends_file << x << '\n';

	cout << "Koniec.\n";

	bolek_file.close();
	lolek_file.close();
	friends_file.close();

	return 0;
}
