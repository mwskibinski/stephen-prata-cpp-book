#include <iostream>
#include "sales.h"

int main() {
	using namespace SALES;
	using namespace std;

	Sales s1, s2;

	// double dbl_arr[] {1.4, 5.7, 2.3, 8.8, 9.9, 1.1, 5.345};
	double dbl_arr[] {1, 10, 100, 1000};
	const int dbl_arr_n = (sizeof dbl_arr) / (sizeof dbl_arr[0]);

	setSales(s1);
	setSales(s2, dbl_arr, dbl_arr_n);

	cout << endl << "Dane obu struktur:" << endl;
	cout << "s1:" << endl;
	showSales(s1);
	cout << "s2:" << endl;
	showSales(s2);

	return 0;
}
