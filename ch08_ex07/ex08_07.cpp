#include <iostream>

template <typename T>
void ShowArray(T arr[], int n);
template <typename T>
void ShowArray(T * arr[], int n);

template <typename T>
T SumArray(T arr[], int n);
template <typename T>
T SumArray(T * arr[], int n);

struct debts {
	char name[50];
	double amount;
};

int main() {
	using namespace std;

	int things[6] = {13, 31, 103, 301, 310, 130};
	struct debts mr_E[3] = {
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double * pd[3];

	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;


	// Czy w treście zadania chodzi o to, żeby także
	// funkcje szablonu ShowArray były używane?
	cout << "Wyliczanie rzeczy pana E.:\n";
	ShowArray(things, 6);
	cout << "Suma rzeczy pana E.:\n";
	cout << SumArray(things, 6) << endl;
	cout << "Wyliczanie długów pana E.:\n";
	ShowArray(pd, 3);
	cout << "Suma długów pana E.:\n";
	cout << SumArray(pd, 3) << endl;

//	int i_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
//	const int i_size = (sizeof i_arr) / (sizeof i_arr[0]);
//	cout << SumArray(i_arr, i_size) << endl;
//
//	int * pi_arr[] = {&i_arr[0], &i_arr[1], &i_arr[2], &i_arr[3]};
//	const int pi_size = (sizeof pi_arr) / (sizeof pi_arr[0]);
//	cout << SumArray(pi_arr, pi_size) << endl;

	return 0;
}

template <typename T>
void ShowArray(T arr[], int n) {
	using namespace std;
	cout << "szablon A\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}
template <typename T>
void ShowArray(T * arr[], int n) {
	using namespace std;
	cout << "szablon B\n";
	for (int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}

template <typename T>
T SumArray(T arr[], int n) {
	T sum = 0.0;
	while (n--)
		sum += arr[n];
	return sum;
}
template <typename T>
T SumArray(T * arr[], int n) {
	T sum = 0.0;
	while (n--)
		sum += *arr[n];
	return sum;
}
