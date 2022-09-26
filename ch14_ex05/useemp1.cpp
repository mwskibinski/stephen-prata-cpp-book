#include <iostream>
using namespace std;
#include "emp.h"

int main() {
	Employee em("Tadeusz", "Hubert", "Sprzedawca");
	cout << em << endl;
	em.showAll();
	cout << '\n';

	Manager ma("Amforiusz", "Smoczewski", "Malarz", 5);
	cout << ma << endl;
	ma.showAll();
	cout << '\n';

	Fink fi("Maurycy", "Olkuski", "Hydraulik", "Julian Bar");
	cout << fi << endl;
	fi.showAll();
	cout << '\n';

	HighFink hf(ma, "Jan Kudłaty");
	hf.showAll();
	cout << "Wciśnij dowolny przycisk, aby przejść do następnego etapu:\n";
	cin.get();

	HighFink hf2;
	hf2.setAll();
	cout << '\n';

	cout << "Używa wskaźnika AbstrEmp *:\n";
	AbstrEmp * tri[4] = {&em, &fi, &hf, &hf2};
	for (int i = 0; i < 4; i++) {
		tri[i]->showAll();
		std::cout << '\n';
	}

	return 0;
}

//	Odpowiedzi do pytań:
//		a) Jawnie zaimplementowany operator przypisania nie jest potrzebny, gdyż żadna z klas nie zarządza dynamicznie pamięcią, więc
//			domyślny wystarczy.
//		b) Każda z klas ma pewne swoje unikalne składowe, poza tymi pochodzącymi z klas bazowych, zatem każda z nich musi implementować te metody
//			w odpowiedni sposób dla siebie. Następnie tak zaimplementowane metody możemy wykorzystywać przy używaniu referencji albo wskaźnika
//			na klasę bazową.
//		c) W ten sposób klasa HighFink dziedziczy tylko jedną kopię składowych pochodzących od tej klasy bazowej. W przeciwnym razie klasa ta
//			miałaby dwie kopie, które pochodziłyby od obu klas po których dziedziczy (Manager, Fink) osobno.
//		d) Klasa HighFink po prostu nie potrzebuje żadnych dodatkowych danych składowych -- wystarczają je te, które dziedziczy.
//		e) Wszystkie klasy dziedziczące po klasie AbstrEmp korzystają z tej samej funkcji zaprzyjaźnionej, ale trzeba pamiętać, że w porównaniu do
//			metod showAll, ta funkcja pokazuje tylko dane pochodzące od klasy bazowej.
//		f) Kod nie zadziała, gdyż klasa AbstrEmp jest klasą abstrakcyjną, więc nie można tworzyć obiektów tej klasy.
