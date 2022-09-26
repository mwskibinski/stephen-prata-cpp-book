#include <iostream>
#include <algorithm>

int reduce(long ar[], int n);
int reduce_2(long ar[], int n);

int main() {
	using std::cout;

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

	arr_n = reduce_2(arr, arr_n);

	cout << "Tablica po:\n";
	for (int i = 0; i < arr_n; i++)
		cout << arr[i] << '\n';
	cout << '\n';

	return 0;
}

int reduce(long ar[], int n) {
	std::sort(ar, ar+n);
	auto ar_end = std::unique(ar, ar+n);

	return ar_end - ar;
}

int reduce_2(long ar[], int n) {
	std::sort(ar, ar+n);
	return std::unique(ar, ar+n) - ar;
}
