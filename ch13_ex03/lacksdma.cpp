#include "lacksdma.h"
#include <iostream>
#include <cstring>

LacksDMA::LacksDMA(const char * label_init, int r, const char * color_init)
	: AbsDMA(label_init, r)
{
	std::strncpy(color, color_init, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
LacksDMA::LacksDMA(const AbsDMA & a, const char * color_init)
	: AbsDMA(a)
{
	std::strncpy(color, color_init, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

void LacksDMA::view() const {
	AbsDMA::view();
	std::cout << "color = " << color << '\n';
}
