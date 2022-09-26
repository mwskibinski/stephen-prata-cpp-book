#include <iostream>
#include "move.h"

Move::Move(double a, double b) {
	x = a;
	y = b;
}
void Move::showmove() const {
	std::cout << "--- showmove():\n";
	std::cout << "x: " << x << "\n";
	std::cout << "y: " << y << "\n";
}
Move Move::add(const Move & n) const {
	return Move(x + n.x, y + n.y);
}
void Move::reset(double a, double b) {
	x = a;
	y = b;
}
