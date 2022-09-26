#include <iostream>

using namespace std;

int fill_array(double [], int);
void show_array(const double [], int);
void reverse_array(double [], int);

int main() {
	const int Size = 10;
	double arr[Size] {0};
	int size = fill_array(arr, Size);
	show_array(arr, size);
	reverse_array(arr, size);
	show_array(arr, size);

	return 0;
}

int fill_array(double arr[], int size) {
	cout << "--- fill_array ---\n";
	int i;
	cout << "Wprowadź dane do tablicy.\n";
	for (i = 0; i < size; i++) {
		cout << "Liczba " << i+1 << ": ";
		if (!(cin >> arr[i]))
			break;
	}
	// return cin ? i : i-1;
	return i;
}
void show_array(const double arr[], int size) {
	cout << "--- show_array ---\n";
	for (int i = 0; i < size; i++)
		cout << "[" << i << "]: " << arr[i] << endl;
}
void reverse_array(double arr[], int size) {
	cout << "--- reverse_array ---\n";
	double tmp;
	for (int i = 0, j = size-1; i < size/2; i++, j--) {
		// cout << i << endl;
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}
