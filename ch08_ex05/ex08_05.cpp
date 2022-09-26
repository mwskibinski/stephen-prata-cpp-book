#include <iostream>

template <typename T> T max5(const T []);
template <typename T> const T & max5_c(const T []);

int main() {
	using namespace std;

	// int i_arr[5] = {1, 5, 38, -5, 2};
	// double d_arr[5] = {1.0, 0.0, 4.56, -3333, 1e+5};
	// int i_arr[5] = {14567, 5, 38, -5, 2};
	// double d_arr[5] = {1.0e+20, 0.0, 4.56, -3333, 1e+5};
	int i_arr[5] = {14567, 5, 38, -5, 21234567};
	double d_arr[5] = {1.0e+20, 0.0, 4.56, -3333, 1e+50};

	cout << i_arr << endl;
	cout << d_arr << endl;

	cout << max5(i_arr) << endl;
	cout << max5(d_arr) << endl;

	cout << max5_c(i_arr) << endl;
	cout << max5_c(d_arr) << endl;

	cout << &max5_c(i_arr) << endl;
	cout << &max5_c(d_arr) << endl;

	return 0;
}

template <typename T> T max5(const T arr[]) {
	T max = arr[0];
	for (int i = 1; i < 5; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
template <typename T> const T & max5_c(const T arr[]) {
	const T * max_ptr = &arr[0];
	for (int i = 1; i < 5; i++)
		if (arr[i] > *max_ptr)
			max_ptr = &arr[i];
	return *max_ptr;
}
