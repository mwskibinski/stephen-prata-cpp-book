#include <iostream>
#include <cstring>
#include <new>

const int BUF_SIZE = 512;

struct chaff {
	char dross[20];
	int slag;
};

char buf[BUF_SIZE];

int main() {
	using namespace std;

	chaff * chaff_ptr_buff = new (buf) chaff[2];
	chaff * chaff_ptr_heap = new chaff[2];

	strcpy(chaff_ptr_buff[0].dross, "Abc Dfg");
	chaff_ptr_buff[0].slag = 123;
	strcpy(chaff_ptr_buff[1].dross, "Inny dross!!!");
	chaff_ptr_buff[1].slag = -6922;

	strcpy(chaff_ptr_heap[0].dross, "Heap 0 nae");
	chaff_ptr_heap[0].slag = 5;
	strcpy(chaff_ptr_heap[1].dross, "John Cena");
	chaff_ptr_heap[1].slag = 1e+3;

	cout << "--- buff:\n";
	for (int i = 0; i < 2; i++) {
		cout << i << ": " << endl;
		cout << "dross: " << chaff_ptr_buff[i].dross << endl;
		cout << "slag: " << chaff_ptr_buff[i].slag << endl;
	}
	cout << "--- heap:\n";
	for (int i = 0; i < 2; i++) {
		cout << i << ": " << endl;
		cout << "dross: " << chaff_ptr_heap[i].dross << endl;
		cout << "slag: " << chaff_ptr_heap[i].slag << endl;
	}

	cout << endl;
	cout << "&buf: " << &buf << endl;
	cout << "chaff_ptr_buff: " << chaff_ptr_buff << endl;
	cout << "chaff_ptr_heap: " << chaff_ptr_heap << endl;

	delete [] chaff_ptr_heap;

	return 0;
}
