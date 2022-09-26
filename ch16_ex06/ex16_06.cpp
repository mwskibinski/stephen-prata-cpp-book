#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

#include "ex16_06_customer.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main() {
	using std::cout;
	using std::endl;
	using std::cin;
	using std::queue;
	using std::ios_base;

	std::srand(std::time(0));

	cout << "Studium przypadku: bankomat Banku Stu Kas\n";
	cout << "Podaj maksymalną długość kolejki: ";
	int qs;
	cin >> qs;
	queue<Customer> line;

	cout << "Podaj symulowany czas (w godzinach): ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	cout << "Podaj średnią liczbę klientów na godzinę: ";
	double perhour;
	cin >> perhour;
	double min_per_cust = MIN_PER_HR / perhour;

	Customer temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)) {
			if (line.size() > qs)
				turnaways++;
			else {
				customers++;
				temp.set(cycle);
				line.push(temp);
			}
		}

		if (wait_time <= 0 && !line.empty()) {
			temp = line.front();
			line.pop();
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}

		if (wait_time > 0)
			wait_time--;

		sum_line += line.size();
	}

	if (customers > 0) {
		cout << " liczba klientów przyjętych: " << customers << endl;
		cout << "liczba klientów obsłużonych: " << served << endl;
		cout << " liczba klientów odesłanych: " << turnaways << endl;
		cout << "    średnia długość kolejki: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double) sum_line / cyclelimit << endl;
		cout << "    średni czas oczekiwania: "
			<< (double) line_wait / served << " minut\n";
	} else
		cout << "Brak klientów!\n";

	cout << "Gotowe!\n";

	return 0;
}

bool newcustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);
}
