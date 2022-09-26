#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main() {
	using std::cout;
	using std::endl;
	using std::list;

	int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	list<int> yadayada(vals, vals+10);
	list<int> etcetera(vals, vals+10);

	auto show_int = [](int x){ std::cout << x << ' '; };

	cout << "Oryginalne listy:\n";
	for_each(yadayada.begin(), yadayada.end(), show_int);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), show_int);
	cout << endl;

	yadayada.remove_if([](int x){ return x > 100; });
	etcetera.remove_if([](int x){ return x > 200; });

	cout << "Przycięcie listy:\n";
	for_each(yadayada.begin(), yadayada.end(), show_int);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), show_int);
	cout << endl;

	return 0;
}
