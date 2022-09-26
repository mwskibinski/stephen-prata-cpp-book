#include <iostream>

const int Datki = 10;

int main() {
	using namespace std;

	cout << "Podaj 10 wartości datków. Wartość nieliczbowa kończy wprowadzanie liczb.\n";

	double datki[Datki] {0.0}, avg = 0.0;

//	int i;
//	cout << "datki[0]: ";
//	for (i = 0; i < Datki && cin >> datki[i]; i++) {
//		avg += datki[i];
//		cout << "datki[" << i+1 << "]: ";
//	}

//	int i = 0;
//	while (i < Datki) {
//		cout << "datki[" << i << "]: ";
//		if (!(cin >> datki[i]))
//			break;
//		avg += datki[i];
//		i++;
//	}
	int i;
	for (i = 0; i < Datki; avg += datki[i], i++) {
		cout << "datki[" << i << "]: ";
		if (!(cin >> datki[i]))
			break;
	}
	// avg /= i;
	avg = i > 0 ? avg/i : 0.0;

	cout << "\nŚrednia: " << avg << endl;

	cout << "Wartości większe od tej średniej:\n";
	for (int j = 0; j < i; j++)
		if (datki[j] > avg)
			cout << "datki[" << j << "] = " << datki[j] << endl;

	return 0;
}
