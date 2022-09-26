#ifndef QUEUETP_H_
#define QUEUETP_H_

#include <iostream>

template <typename T>
class QueueTP
{
private:
	enum {QSIZE = 10};
	struct Node {
		T item;
		Node * next;
	};

	int count;
	int qsize;
	Node * front;
	Node * rear;

	void empty();
public:
	QueueTP(int qs = QSIZE);
	QueueTP(const QueueTP & q);
	~QueueTP();

	bool isempty() const {
		return count == 0;
	}
	bool isfull() const {
		return count == qsize;
	}
	bool enQueue(const T & item);
	bool deQueue(T & item);

	QueueTP & operator=(const QueueTP &);
};

template <typename T>
QueueTP<T>::QueueTP(int qs)
	: count(0), qsize(qs), front(nullptr), rear(nullptr)
{}

template <typename T>
QueueTP<T>::QueueTP(const QueueTP & q)
	: count(q.count), qsize(q.qsize)
{
	if (count > 0) {
		rear = front = new Node;
		front->item = q.front->item;
		front->next = nullptr;
		for (Node * tmp = q.front->next; tmp != nullptr; tmp = tmp->next) {
			rear = (rear->next = new Node);
			rear->item = tmp->item;
			rear->next = nullptr;
		}
	} else {
		front = rear = nullptr;
	}
}

template <typename T>
QueueTP<T>::~QueueTP()
{
	empty();
}

template <typename T>
bool QueueTP<T>::enQueue(const T & item)
{
	if (count < qsize) {
		count++;
		if (count == 1) {
			front = new Node;
			front->item = item;
			front->next = nullptr;
			rear = front;
		} else {
			rear = (rear->next = new Node);
			rear->item = item;
			rear->next = nullptr;
		}
		return true;
	} else {
		return false;
	}
}

template <typename T>
bool QueueTP<T>::deQueue(T & item)
{
	if (count > 0) {
		count--;
		item = front->item;
		if (count == 0) {
			delete front;
			front = rear = nullptr;
		} else {
			Node * tmp = front;
			front = front->next;
			delete tmp;
		}
		return true;
	} else {
		return false;
	}
}

template <typename T>
QueueTP<T> & QueueTP<T>::operator=(const QueueTP & q) {
	if (this != &q) {
		empty();
		count = q.count;
		qsize = q.qsize;
		if (count > 0) {
			rear = front = new Node;
			front->item = q.front->item;
			front->next = nullptr;
			for (Node * tmp = q.front->next; tmp != nullptr; tmp = tmp->next) {
				rear = (rear->next = new Node);
				rear->item = tmp->item;
				rear->next = nullptr;
			}
		}
	} else {
		front = rear = nullptr;
	}
	return *this;
}

template <typename T>
void QueueTP<T>::empty() {
	for (Node * tmp = front; tmp != nullptr; front = tmp) {
		tmp = tmp->next;
		delete front;
	}
}

#endif // QUEUETP_H_
