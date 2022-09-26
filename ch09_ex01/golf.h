#ifndef GOLF_H_
#define GOLF_H_

const int Len = 40;
struct golf {
	char fullname[Len];
	int handicap;
};

void setgolf(golf & g, const char * name, int hc);
// vvv - chyba taki prototyp musi być skoro funkcja ma zwracać 0 lub 1 (a nie 'void' jak w książce)
int setgolf(golf & g);
void handicap(golf & g, int hc);
void showgolf(const golf & g);

#endif
