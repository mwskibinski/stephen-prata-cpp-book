//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include "queue.h"
//#include <cmath>
//
//const int MIN_PER_HR = 60;
//
//bool newcustomer(double x);
//template <typename T> void printArray(T arr[], int size);
//void printResults(double perhours[], double avg_times[], int size);
//template <typename T> int findClosestInArray(T arr[], T value, int size);
//
//int main2() {
//	using std::cin;
//	using std::cout;
//	using std::endl;
//	using std::ios_base;
//
//	std::srand(std::time(0));
//
//	cout << "Studium przypadku: bankomat Banku Stu Kas\n";
//
//	// Maksymalna długość kolejki
//	int qs = 100;
//	Queue line1(qs);
//	Queue line2(qs);
//
//	// Symulowany czas w godzinach
//	int hours = 100;
//	long cyclelimit = MIN_PER_HR * hours;
//
//	// Zmienne używane w trakcie symulacji
//	// Item temp;
//	Item temp1, temp2;
//	long turnaways = 0;
//	long customers = 0;
//	long served = 0;
//	long sum_line = 0;
//	// int wait_time = 0;
//	int wait_time1 = 0, wait_time2 = 0;
//	// long long line_wait = 0;
//	long long line_wait1 = 0, line_wait2 = 0;
//	double perhour = 0.0;
//	double min_per_cust = 0.0;
//
//	// Zakres badanych wartości średniej liczby klientów na godzinę
//	double perhour_start = 50.0;
//	double perhour_end = 60.0;
//	double perhour_step = 0.1;
//	int perhour_n = ceil((perhour_end - perhour_start) / perhour_step + 1);
//
//	// Inicjalizacja tablicy
//	double * perhour_mat = new double [perhour_n];
//	for (int i = 0; i < perhour_n; i++)
//		perhour_mat[i] = perhour_start + perhour_step * i;
//
//	// printArray(perhour_mat, perhour_n);
//
//	// Średni czas przypadający na klienta
//	double * avg_time = new double [perhour_n];
//	// Średnia z prób
//	double avg_time_avg = 0.0;
//	int perhour_tries = 100;
//
//	// Pierwsza pętla: wybór średniego czasu klienta
////	std::cout << "*** *** ***\n";
////	std::cout << "Procent wykonania programu:\n";
////	std::ios_base::fmtflags orig_flags;
////	orig_flags = std::cout.setf(std::ios_base::showpoint);
////	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
////	std::ios_base::precision orig_prec;
////	orig_prec = std::cout.precision(1);
//	for (int i = 0; i < perhour_n; i++) {
//		std::cout << (double (i) / perhour_n * 100.0) << "%" << (i % 10 == 9 ? '\n' : '\t');
//
//		perhour = perhour_mat[i];
//		avg_time_avg = 0.0;
//		// Druga pętla: Jako że symulacje są (pseudo)losowe wykonuję ich 'perhour_tries' na każdą wartość 'perhour'. Z czasów wyznaczam średnią
//		for (int j = 0; j < perhour_tries; j++) {
//			// Inicjalizacja
//			line1.empty();
//			line2.empty();
//			min_per_cust = MIN_PER_HR / perhour;
//			turnaways = 0;
//			customers = 0;
//			served = 0;
//			sum_line = 0;
//			wait_time1 = 0;
//			wait_time2 = 0;
//			line_wait1 = 0;
//			line_wait2 = 0;
//
//			// Właściwa symulacja
//			for (int cycle = 0; cycle < cyclelimit; cycle++) {
//				if (newcustomer(min_per_cust)) {
//					if (line1.isfull() && line2.isfull())
//						turnaways++;
//					else if (line1.queuecount() < line2.queuecount()) {
//						customers++;
//						temp1.set(cycle);
//						line1.enqueue(temp1);
//					} else {
//						customers++;
//						temp2.set(cycle);
//						line2.enqueue(temp2);
//					}
//				}
//				if (wait_time1 <= 0 && !line1.isempty()) {
//					line1.dequeue(temp1);
//					wait_time1 = temp1.ptime();
//					line_wait1 += cycle - temp1.when();
//					served++;
//				}
//				if (wait_time2 <= 0 && !line2.isempty()) {
//					line2.dequeue(temp2);
//					wait_time2 = temp2.ptime();
//					line_wait2 += cycle - temp2.when();
//					served++;
//				}
//				if (wait_time1 > 0)
//					wait_time1--;
//				if (wait_time2 > 0)
//					wait_time2--;
//
//				sum_line += line1.queuecount() + line2.queuecount();
//			}
//			// Aktualizacja średniej z danej próby
//			// avg_time_avg += ((double) line_wait / served) / perhour_tries;
//			avg_time_avg += ((double) (line_wait1 + line_wait2) / served) / perhour_tries;
//		}
//		// Zapis wartości średniej
//		avg_time[i] = avg_time_avg;
//	}
//	std::cout << "*** *** ***\n";
//	// Wydruk wyników
//	printResults(perhour_mat, avg_time, perhour_n);
//
//	// Poszukiwana wartość
//	int closest_idx = findClosestInArray(avg_time, 1.0, perhour_n);
//	cout << "Poszukiwana średnia liczba klientów na godzinę:\n\t" << perhour_mat[closest_idx] << '\n';
//	cout << "Wtedy, średni czas oczekiwania w kolejce:\n\t" << avg_time[closest_idx] << '\n';
//
//	delete [] perhour_mat;
//	delete [] avg_time;
//
//	return 0;
//}
//
//bool newcustomer(double x) {
//	return (std::rand() * x / RAND_MAX < 1);
//}
//// Zawartość tablicy
//template <typename T> void printArray(T arr[], int size) {
//	for (int i = 0; i < size; i++)
//		std::cout << i << ": " << arr[i] << std::endl;
//}
//// Wydruk wyników końcowych
//void printResults(double perhours[], double avg_times[], int size) {
//	std::cout << "-------------------------------\n";
//	std::cout << "Klienci, czas\n";
//	std::cout << "===============================\n";
//	std::cout << std::right;
//	for (int i = 0; i < size; i++) {
//		std::cout.width(6);
//		std::cout << perhours[i];
//		std::cout << ": ";
//		std::cout.width(10);
//		std::cout << avg_times[i];
//		std::cout << std::endl;
//	}
//	std::cout << std::left;
//	std::cout << "-------------------------------\n";
//}
//// Znajdź indeks tablicy, dla którego wartość jest najbliższa poszukiwanej.
//template <typename T> int findClosestInArray(T arr[], T value, int size) {
//	if (size <= 0)
//		return -1;
//
//	int closest_idx = 0;
//	double min_diff = std::abs(arr[0] - value);
//	for (int i = 1; i < size; i++)
//		if (std::abs(arr[i] - value) < min_diff) {
//			min_diff = std::abs(arr[i] - value);
//			closest_idx = i;
//		}
//
//	return closest_idx;
//}
