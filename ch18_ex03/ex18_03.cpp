#include <iostream>

template <typename T>
long double sum_values(const T & val) {
	return val;
}

template <typename T, typename... Args>
long double sum_values(const T & val, const Args & ... args) {
	return val + sum_values(args...);
}

int main() {
	using namespace std;

	cout << sum_values(1) << endl;
	cout << sum_values(1, 2) << endl;
	cout << sum_values(1, 2, 3) << endl;
	cout << sum_values(1, 2, 3, 4) << endl;
	cout << sum_values(1, 2, 3, 4, -1.123) << endl;
	cout << sum_values(1, 2, 3, 4, -1.123, -'A') << endl;
	cout << sum_values(1, 2, 3, 4, -1.123, -'A', 'B') << endl;

	return 0;
}
