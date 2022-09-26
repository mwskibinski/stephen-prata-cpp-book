#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
#include <cmath>

const int MIN_PER_HR = 60;

bool newcustomer(double x);
template <typename T> void printArray(T arr[], int size);
void printResults(double perhours[], double avg_times[], int size);
template <typename T> int findClosestInArray(T arr[], T value, int size);

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));

	cout << "Studium przypadku: bankomat Banku Stu Kas\n";

	// Maksymalna długość kolejki
	int qs = 100;
	Queue line(qs);

	// Symulowany czas w godzinach
	int hours = 100;
	long cyclelimit = MIN_PER_HR * hours;

	// Zmienne używane w trakcie symulacji
	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long long line_wait = 0;
	double perhour = 0.0;
	double min_per_cust = 0.0;

	// Zakres badanych wartości średniej liczby klientów na godzinę
	double perhour_start = 17.0;
	double perhour_end = 19.0;
	double perhour_step = 0.1;
	int perhour_n = ceil((perhour_end - perhour_start) / perhour_step + 1);

	// Inicjalizacja tablicy
	double * perhour_mat = new double [perhour_n];
	for (int i = 0; i < perhour_n; i++)
		perhour_mat[i] = perhour_start + perhour_step * i;

	// printArray(perhour_mat, perhour_n);

	// Średni czas przypadający na klienta
	double * avg_time = new double [perhour_n];
	// Średnia z prób
	double avg_time_avg = 0.0;
	int perhour_tries = 100;

	// Pierwsza pętla: wybór średniego czasu klienta
	for (int i = 0; i < perhour_n; i++) {
		perhour = perhour_mat[i];
		avg_time_avg = 0.0;
		// Druga pętla: Jako że symulacje są (pseudo)losowe wykonuję ich 'perhour_tries' na każdą wartość 'perhour'. Z czasów wyznaczam średnią
		for (int j = 0; j < perhour_tries; j++) {
			// Inicjalizacja
			line.empty();
			min_per_cust = MIN_PER_HR / perhour;
			turnaways = 0;
			customers = 0;
			served = 0;
			sum_line = 0;
			wait_time = 0;
			line_wait = 0;

			// Właściwa symulacja
			for (int cycle = 0; cycle < cyclelimit; cycle++) {
				if (newcustomer(min_per_cust)) {
					if (line.isfull())
						turnaways++;
					else {
						customers++;
						temp.set(cycle);
						line.enqueue(temp);
					}
				}
				if (wait_time <= 0 && !line.isempty()) {
					line.dequeue(temp);
					wait_time = temp.ptime();
					line_wait += cycle - temp.when();
					served++;
				}
				if (wait_time > 0)
					wait_time--;

				sum_line += line.queuecount();
			}
			// Aktualizacja średniej z danej próby
			avg_time_avg += ((double) line_wait / served) / perhour_tries;
		}
		// Zapis wartości średniej
		avg_time[i] = avg_time_avg;
	}
	// Wydruk wyników
	printResults(perhour_mat, avg_time, perhour_n);

	// Poszukiwana wartość
	int closest_idx = findClosestInArray(avg_time, 1.0, perhour_n);
	cout << "Poszukiwana średnia liczba klientów na godzinę:\n\t" << perhour_mat[closest_idx] << '\n';
	cout << "Wtedy, średni czas oczekiwania w kolejce:\n\t" << avg_time[closest_idx] << '\n';

	delete [] perhour_mat;
	delete [] avg_time;

	return 0;
}

bool newcustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);
}
// Zawartość tablicy
template <typename T> void printArray(T arr[], int size) {
	for (int i = 0; i < size; i++)
		std::cout << i << ": " << arr[i] << std::endl;
}
// Wydruk wyników końcowych
void printResults(double perhours[], double avg_times[], int size) {
	std::cout << "-------------------------------\n";
	std::cout << "Klienci, czas\n";
	std::cout << "===============================\n";
	std::cout << std::right;
	for (int i = 0; i < size; i++) {
		std::cout.width(6);
		std::cout << perhours[i];
		std::cout << ": ";
		std::cout.width(10);
		std::cout << avg_times[i];
		std::cout << std::endl;
	}
	std::cout << std::left;
	std::cout << "-------------------------------\n";
}
// Znajdź indeks tablicy, dla którego wartość jest najbliższa poszukiwanej.
template <typename T> int findClosestInArray(T arr[], T value, int size) {
	if (size <= 0)
		return -1;

	int closest_idx = 0;
	double min_diff = std::abs(arr[0] - value);
	for (int i = 1; i < size; i++)
		if (std::abs(arr[i] - value) < min_diff) {
			min_diff = std::abs(arr[i] - value);
			closest_idx = i;
		}

	return closest_idx;
}
