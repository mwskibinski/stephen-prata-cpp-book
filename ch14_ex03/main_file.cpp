//#include <iostream>
//#include "queuetp.h"
//#include "workermi.h"
//#include <ctime>
//#include <cstdlib>
//
//int main() {
//	using std::cout;
//	using std::endl;
//	using std::cin;
//
//	using WorkerPtrQueue = QueueTP<Worker *>;
//
//	const int Q_SIZE = 5;
//
//	WorkerPtrQueue wpq_arr(Q_SIZE);
//
//	int ct;
//	char choice;
//	for (ct = 0; ct < Q_SIZE; ct++) {
//		cout << "Podaj kategoriê pracownika:\n"
//			<< "k: kelner, p: piosenkarz, s: œpiewaj¹cy piosenkarz;   w: wyjœcie\n";
//	}
//
//	return 0;
//}
//
////int main() {
////	using std::cout;
////	using std::endl;
////
////	// QueueTP<double> * qp = nullptr;
////	// QueueTP<double> * qp_copy = nullptr;
////
////	using WorkerPtrQueue = QueueTP<Waiter *>;
////
////	WorkerPtrQueue * qp = nullptr;
////	WorkerPtrQueue * qp_copy = nullptr;
////
////	std::srand(std::time(0));
////
////	int iters = 10;
////	int numel = 0;
////	int new_i_n = 5;
////	// double item = 0.0;
////	Waiter * item = nullptr;
////
////	for (int new_i = 0; new_i < new_i_n; new_i++) {
////		cout << "\t*** new_i: " << new_i << endl;
////		qp = new WorkerPtrQueue;
////		qp_copy = new WorkerPtrQueue;
////		for (int i = 0; i < iters; i++) {
////			numel = rand() % 11;
////			for (int j = 0; j < numel; j++) {
////				item = new Waiter("Waiter", rand() % 10000, rand() % 10);
////				qp->enQueue(item);
////				// cout << item << ", ";
////			}
////			cout << endl;
////			// qp_copy = new QueueTP<double>(*qp);
////			*qp_copy = *qp;
////			cout << "\ti: " << i << ", numel = " << numel << ", elementy:\n";
////			for (int j = 0; qp->deQueue(item); j++) {
////				// cout << j << ": " << item << endl;
////				cout << j << ": ";
////				item->Show();
////				cout << endl;
////				// delete item;
////			}
////			cout << "\t- kopia:\n";
////			for (int j = 0; qp_copy->deQueue(item); j++) {
////				// cout << j << ": " << item << endl;
////				cout << j << ": ";
////				item->Show();
////				cout << endl;
////				delete item;
////			}
//////			cout << "\t- kopia:\n";
//////			for (int j = 0; qp_copy->deQueue(item); j++)
//////				cout << j << ": " << item << endl;
//////			cout << endl;
////			// delete qp_copy;
////		}
////		delete qp;
////		delete qp_copy;
////	}
////
//////	for (int new_i = 0; true; new_i++) {
//////		qp = new QueueTP<double>;
//////		qp_copy = new QueueTP<double>;
//////		for (int i = 0; i < iters; i++) {
//////			numel = rand() % 11;
//////			for (int j = 0; j < numel; j++) {
//////				item = (rand() % 100) * 0.1;
//////				qp->enQueue(item);
//////			}
//////			qp_copy = new QueueTP<double>(*qp);
//////			// *qp_copy = *qp;
//////			for (int j = 0; qp->deQueue(item); j++)
//////				;
//////			for (int j = 0; qp_copy->deQueue(item); j++)
//////				;
//////			delete qp_copy;
//////		}
//////		delete qp;
//////		// delete qp_copy;
//////	}
////
////
////
////	return 0;
////}
