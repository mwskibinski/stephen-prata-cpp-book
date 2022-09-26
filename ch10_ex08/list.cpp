#include <iostream>
#include "list.h"

List::List() {
	number = 0u;
}
List::~List() {

}
bool List::add(const Item & item) {
	if (number < LIST_MAX) {
		list[number++] = item;
		return true;
	} else
		return false;
}
bool List::remove() {
	if (number > 0u) {
		--number;
		return true;
	} else
		return false;
}
bool List::isempty() const {
	return number == 0u;
}
bool List::isfull() const {
	return number == LIST_MAX;
}
void List::visit(void (*mod_func)(Item &)) {
	for (unsigned i = 0u; i < number; i++)
		mod_func(list[i]);
}
bool List::check(Item & item, unsigned n) const {
	if (n < number) {
		std::cout << "Element nr " << n << " listy to: " << list[n];
		std::cout << std::endl;
		item = list[n];
		return true;
	} else {
		std::cout << "Lista nie ma tylu elementów!\n";
		return false;
	}
}
void List::printList() const {
	std::cout << "--- printList:\n";
	for (unsigned i = 0u; i < number; i++)
		std::cout << "list[" << i << "] = " << list[i] << std::endl;
}
