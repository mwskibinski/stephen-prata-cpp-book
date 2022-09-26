#include <iostream>
#include "port.h"
#include "vintageport.h"

inline void printMyInfo(const char * info) {
	std::cout << '\t' << "*** " << info << ".\n";
}

int main() {
	using std::cout;
	using std::endl;

	printMyInfo("Tworzenie obiektów obu klas");
	Port p, p1("Winiary", "rosołowe", 10), p2("Le Szewenie", "białe", 20);
	VintagePort vp, vp1("l'Tusą", 2, "Szlachetny", 1800), vp2("Ziuasdfef!", 1000, "Cudowne", 100);

	printMyInfo("Używanie metody show");
	p.show();
	cout << endl;
	p1.show();
	cout << endl;
	p2.show();
	cout << endl;

	vp.show();
	cout << endl;
	vp1.show();
	cout << endl;
	vp2.show();
	cout << endl;

	printMyInfo("Używanie operatora <<");
	cout << "  p: " << p << endl;
	cout << " p1: " << p1 << endl;
	cout << " p2: " << p2 << endl;

	cout << " vp: " << vp << endl;
	cout << "vp1: " << vp1 << endl;
	cout << "vp2: " << vp2 << endl;
	cout << endl;

	printMyInfo("Użycie operatora przypisania: p = p2, vp1 = vp2");
	p = p2;
	cout << "  p: " << p << endl;
	vp1 = vp2;
	cout << "vp1: " << vp1 << endl;
	cout << endl;

	printMyInfo("Użycie operatora przypisania: p = vp1");
	p = vp1;
	cout << "  p: " << p << endl;
	cout << endl;

	printMyInfo("Liczba butelek");
	cout << "  p: " << p.bottleCount() << endl;
	cout << " p1: " << p1.bottleCount() << endl;
	cout << " p2: " << p2.bottleCount() << endl;
	cout << " vp: " << vp.bottleCount() << endl;
	cout << "vp1: " << vp1.bottleCount() << endl;
	cout << "vp2: " << vp2.bottleCount() << endl;
	cout << endl;

	printMyInfo("Użycie operatora += dla liczby 99");
	cout << "  p: " << (p += 99) << endl;
	cout << " p1: " << (p1 += 99) << endl;
	cout << " p2: " << (p2 += 99) << endl;
	cout << " vp: " << (vp += 99) << endl;
	cout << "vp1: " << (vp1 += 99) << endl;
	cout << "vp2: " << (vp2 += 99) << endl;
	cout << endl;

	printMyInfo("Użycie operatora -= dla liczby 50");
	cout << "  p: " << (p -= 50) << endl;
	cout << " p1: " << (p1 -= 50) << endl;
	cout << " p2: " << (p2 -= 50) << endl;
	cout << " vp: " << (vp -= 50) << endl;
	cout << "vp1: " << (vp1 -= 50) << endl;
	cout << "vp2: " << (vp2 -= 50) << endl;
	cout << endl;

	printMyInfo("Użycie operatora -= dla liczby 1000");
	cout << "  p: " << (p -= 1000) << endl;
	cout << " p1: " << (p1 -= 1000) << endl;
	cout << " p2: " << (p2 -= 1000) << endl;
	cout << " vp: " << (vp -= 1000) << endl;
	cout << "vp1: " << (vp1 -= 1000) << endl;
	cout << "vp2: " << (vp2 -= 1000) << endl;
	cout << endl;

	return 0;
}

/*	Odpowiedzi do pytań:
 *		a) Definicje metod klasy Port są zawarte w pliku "port.h"
 *		b) - Konstruktory -- nie są dziedziczone, każda klasa musi mieć swoje.
 *		   - Destruktory -- wszystkie klasy, które dynamicznie alokują pamięć, powinny implementować swoje destruktory do zwalniania
 *				tej pamięci. Jako że i klasa bazowa i pochodna angażują mechanizm dynamicznego zarządzania pamięcią muszą mieć swoje osobne
 *				destruktory do zwalniania pamięci odpowiednich składowych. Trzeba też pamiętać o tym, że klasa pochodna nie musi troszczyć się
 *				o pamięć nad którą kontrolę sprawuje klasa bazowa. Destruktory muszą być wirtualne, by były wywoływane oba nawet, gdy obiektów
 *				używa się poprzez wskaźnik/referencję na klasę bazową.
 *		   - Operator przypisania -- Tak jak i w przypadku konstruktorów kopiujących i destruktorów, dynamiczne zarządzanie pamięcią wymaga jawnej
 *				implementacji metody operatora przypisania. Obie klasy muszą mieć swoje metody, by dbać o odpowiednie przypisanie swoich składowych.
 *				Pamiętać należy także, by klasa pochodna wywoływała także operator przypisania klasy bazowej.
 *		   - Operatory +=, -= -- zostały zdefiniowane tylko w klasie bazowej, gdyż klasa pochodna używa ich w taki sam sposób, więc nie ma potrzeby
 *				ich redefiniować.
 *		   - Funkcja bottleCount() -- podobnie jak z operatorami +=, -=.
 *		   - Funkcja show() -- klasa pochodna ma dodatkowe składowe, które powinny być także wypisane przy użyciu funkcji show(). Z tego powodu,
 *				funkcja jest wirtualna. Poza tym, funkcja klasy pochodnej wywołuje tę samą funkcję klasy bazowej, by zacząć od wypisania
 *				danych wspólnych obu klas, a dopiero potem przechodzi do wypisania pozostałych składowych.
 *		c) Dla obu klasy operator przypisania mają inne sygnatury: klasa Port przyjmuje jako argument 'const Port &',
 *			zaś klasa VintagePort 'const VintagePort &'. Deklarowanie tych metod jako wirtualnych zatem nic nie wniesie.
 *			Operator << nie jest częścią metod klasy, a funkcją zaprzyjaźnioną, a tych się wirtualizuje.
 *		d) Definicje metod klasy VintagePort są zawarte w pliku "vintageport.h"
 */
