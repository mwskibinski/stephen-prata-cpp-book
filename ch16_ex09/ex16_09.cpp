#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <algorithm>

int main() {
	using std::vector;
	using std::list;
	using std::cout;
	using std::endl;

	std::srand(std::time(0));

	int n = 4'000'000;
	vector<int> vi0(n);
	cout << "Inicjalizacja vi0...\n";
	for (int i = 0; i < n; i++)
		vi0.at(i) = std::rand() % 1000;

	cout << "Inicjalizacja vi...\n";
	vector<int> vi(vi0);
	cout << "Inicjalizacja li...\n";
	list<int> li(vi0.begin(), vi0.end());

	cout << "Sortowanie vi...\n";
	auto vsort_start = clock();
	sort(vi.begin(), vi.end());
	auto vsort_end = clock();

	cout << "Sortowanie li...\n";
	auto lsort_start = clock();
	li.sort();
	auto lsort_end = clock();

	cout << "Przywrócenie poprzedniego porządku w li...\n";
	li = list<int> (vi0.begin(), vi0.end());

	cout << "Sortowanie li v2...\n";
	auto l2sort_start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	auto l2sort_end = clock();

	cout << "\nZmierzone czasy:\n";
	cout.width(10);
	cout << "wektor" << ": " <<
		(double) (vsort_end - vsort_start) / CLOCKS_PER_SEC << '\n';
	cout.width(10);
	cout << "lista" << ": " <<
		(double) (lsort_end - lsort_start) / CLOCKS_PER_SEC << '\n';
	cout.width(10);
	cout << "lista v2" << ": " <<
		(double) (l2sort_end - l2sort_start) / CLOCKS_PER_SEC << '\n';

//	cout << "\tWektor vi0:\n";
//	copy(vi0.begin(), vi0.end(), std::ostream_iterator<int, char> (cout, " "));
//	cout << '\n';
//	cout << "\tWektor vi:\n";
//	copy(vi.begin(), vi.end(), std::ostream_iterator<int, char> (cout, " "));
//	cout << '\n';
//	cout << "\tLista li:\n";
//	copy(li.begin(), li.end(), std::ostream_iterator<int, char> (cout, " "));
//	cout << '\n';

	return 0;
}
