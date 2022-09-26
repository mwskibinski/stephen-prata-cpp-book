#include "basedma.h"

// Niezwykle ciekawy plik zawierający implementacje metod klasy BaseDMA...

BaseDMA::BaseDMA(const char * label_init, int r)
	: AbsDMA(label_init, r)
{

}
BaseDMA::BaseDMA(const AbsDMA & a)
	: AbsDMA(a)
{

}

void BaseDMA::view() const {
	AbsDMA::view();
}
