#include <iostream>

int golf_fill(int [], int);
void golf_print(const int [], int);
double golf_mean(const int [], int);

int main() {
	const int Size = 10;
	int golf[Size];
	int golf_n = golf_fill(golf, Size);
	golf_print(golf, golf_n);
	std::cout << "Średnia: " << golf_mean(golf, golf_n);

	return 0;
}

int golf_fill(int golf[], int size) {
	std::cout << "Podaj do 10 wyników golfowych. Podanie -1 kończy wprowadzanie wcześniej.\n";
	int golf_n = 0;
	while (golf_n < size) {
		std::cout << "Wynik nr " << golf_n+1 << ": ";
		std::cin >> golf[golf_n];
		if (golf[golf_n] == -1)
			break;
		else
			golf_n++;
	}

	return golf_n;
}
void golf_print(const int golf[], int size) {
//	for (int i = 0; i < size; i++)
//		std::cout << golf[i] << (i == size-1 ? "\n" : ", ");
	for (int i = 0; i < size-1; i++)
		std::cout << golf[i] << ", ";
	std::cout << golf[size-1] << std::endl;
}
double golf_mean(const int golf[], int size) {
	double mean = 0.0;
	for (int i = 0; i < size; i++)
		mean += double (golf[i]) / size;
	return mean;
}
