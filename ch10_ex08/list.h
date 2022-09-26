#ifndef LIST_H_
#define LIST_H_

typedef double Item;

class List {
private:
	enum { LIST_MAX = 50u };
	Item list[LIST_MAX];
	unsigned number;
public:
	List();
	~List();
	bool add(const Item &);
	bool remove();
	bool isempty() const;
	bool isfull() const;
	void visit(void (*mod_func)(Item &));
	// Dodaję dwie metody od siebie, by sprawdzić zawartość tablicy.
	bool check(Item &, unsigned n) const;
	void printList() const;
};

#endif // LIST_H_
