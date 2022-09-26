#include <iostream>

unsigned printStringCnt = 0;
void printString(const char * str, int n = 0);

int main() {
	printString("abc");
	printString("Inny napis");
	printString("lorem IPSUM");

	printString("rintStrin", -1);

	printString("txt");

	return 0;
}

void printString(const char * str, int n) {
	if (n == 0)
		std::cout << str << std::endl;
	else
		for (int i = 0; i < printStringCnt; i++)
			std::cout << str << std::endl;
	// Skoro "tyle razy, ile razy dotąd wywołano tę funkcję", to chyba te aktualne
	// wywołanie się nie liczy, zatem inkrementacja jest na końcu. W przeciwnym wypadku umieścił by to powyżej.
	printStringCnt++;
}
