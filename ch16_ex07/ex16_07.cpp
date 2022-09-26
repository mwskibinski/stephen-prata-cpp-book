#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

std::vector<int> lotto(int upper_bound, int n);

int main() {
	using std::cout;
	using std::cin;
	using std::vector;

	std::srand(std::time(0));

	cout << "Podaj liczbę pól oraz liczbę losowo wybieranych liczb <0, by skończyć>.\n> ";
	int upper, rand_nums;
	while (cin >> upper >> rand_nums && upper != 0 && rand_nums != 0) {
		vector<int> winners;

		try {
			winners = lotto(upper, rand_nums);
		} catch (std::out_of_range & oor) {
			cout << "*** Liczba pól nie może być mniejsza niż liczba losów!\n";
			cout << "Spróbuj ponownie.\n> ";
			continue;
		}

		cout << "Zwycięskie liczby:\n";
		int i;
		for (i = 0; i < winners.size(); i++) {
			cout.width(3);
			cout << *(winners.begin() + i) << ((i % 10 == 9) ? '\n' : ' ');
		}
		if (i % 10 != 0)
			cout << '\n';

		cout << "Podaj liczbę pól oraz liczbę losowo wybieranych liczb <0, by skończyć>.\n> ";
	}

	return 0;
}

std::vector<int> lotto(int upper_bound, int n) {
	if (n > upper_bound)
		throw std::out_of_range("error: n cannot be greater than upper_bound");

	std::vector<int> numbers(upper_bound);
	int i = 1;
	for (auto & x : numbers)
		x = i++;

	std::random_shuffle(numbers.begin(), numbers.end());

	return std::vector<int> (numbers.begin(), numbers.begin() + n);
}
