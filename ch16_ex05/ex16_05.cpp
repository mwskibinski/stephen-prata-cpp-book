#include <iostream>
#include <algorithm>
#include <string>

template <typename T>
int reduce(T ar[], int n);

int main() {
	using std::cout;
	using std::string;

	// long arr[] = {1L, 2L, 3L, 4L, 100L, 100L};
	// long arr[] = {3L, 2L, 3L, 4L, 100L, 100L};
	// long arr[] = {100, 50, 20, 10, 1, 1, 1, 1, 1};
	// long arr[] = {100, 50, 20, 10, 1, 1, 1, 1, 1};
	long arr[] = {1, 1, 2, 3, 11, 1, 1};

	int arr_n = (sizeof arr) / (sizeof arr[0]);

	cout << "Tablica przed:\n";
	for (int i = 0; i < arr_n; i++)
		cout << arr[i] << '\n';
	cout << '\n';

	arr_n = reduce(arr, arr_n);

	cout << "Tablica po:\n";
	for (int i = 0; i < arr_n; i++)
		cout << arr[i] << '\n';
	cout << '\n';

	cout << "\tstring.\n";
	string str_arr[] = {
		"alfa", "beta", "gamma", "delta", "epsilon",
		"alfa", "gamma", "iota"
	};

	int str_arr_n  = (sizeof str_arr) / (sizeof str_arr[0]);

	cout << "Tablica przed:\n";
	for (int i = 0; i < str_arr_n; i++)
		cout << str_arr[i] << '\n';
	cout << '\n';

	str_arr_n = reduce(str_arr, str_arr_n);

	cout << "Tablica przed:\n";
	for (int i = 0; i < str_arr_n; i++)
		cout << str_arr[i] << '\n';
	cout << '\n';

	return 0;
}

template <typename T>
int reduce(T ar[], int n) {
	std::sort(ar, ar+n);
	return std::unique(ar, ar+n) - ar;
}
