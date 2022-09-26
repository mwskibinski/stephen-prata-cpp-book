#include <iostream>
#include <cstring>

typedef char * char_ptr;

template <typename T> const T & maxn(const T arr[], int size);
template <> const char * const & maxn(const char * const arr[], int size);

template <typename T> void printArray(const T arr[], int size);

int main() {
	int i[] {1, 45, 4, -3, 666, 4, 12, 88};
	double d[] {5.5, 1.1, -4.4, 1e+34, 1111.111};
	const char * ccp[] {
		"Alaska", "Nevada", "North Dakota", "Arizona", "California", "New Hampshire"
	};

	int i_size = (sizeof i) / (sizeof i[0]);
	int d_size = (sizeof d) / (sizeof d[0]);
	int ccp_size = (sizeof ccp) / (sizeof ccp[0]);

	printArray(i, i_size);
	std::cout << "**************\n";
	printArray(d, d_size);
	std::cout << "**************\n";
	printArray(ccp, ccp_size);
	std::cout << "**************\n";

	const int & i_max = maxn(i, i_size);
	const double & d_max = maxn(d, d_size);
	const char * const & ccp_max = maxn(ccp, ccp_size);

	std::cout << "i_max: " << i_max << ", &i_max: " << &i_max << std::endl;
	std::cout << "d_max: " << d_max << ", &d_max: " << &d_max << std::endl;
	std::cout << "ccp_max: " << ccp_max << ", &ccp_max: " << &ccp_max << std::endl;

	return 0;
}

// Co powinny robić funkcje zwracające referencje, gdy tablica jest pusta?

template <typename T>
const T & maxn(const T arr[], int size) {
	const T * max_ptr = &arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > *max_ptr)
			max_ptr = &arr[i];
	return *max_ptr;
}
template <>
const char * const & maxn(const char * const arr[], int size) {
	const char * const * max_p = &arr[0];
	int max_len = strlen(*max_p);
	for (int i = 1; i < size; i++)
//		if (strlen(arr[i]) > strlen(*max_p))
//			max_p = &arr[i];
		if (strlen(arr[i]) > max_len) {
			max_p = &arr[i];
			max_len = strlen(*max_p);
		}
	return *max_p;
}
template <typename T> void printArray(const T arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "--- i: " << i << std::endl;
		std::cout << "&arr[i]: " << &arr[i] << std::endl;
		std::cout << "arr[i]: " << arr[i] << std::endl;
	}
}
