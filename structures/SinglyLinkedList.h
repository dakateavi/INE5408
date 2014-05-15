#ifndef _SinglyLinkedList_h_
#define _SinglyLinkedList_h_

#include <stdexcept>
#include "List.h"

namespace structures {

template <class T>
class SinglyLinkedList : public structures::List<T> {
	struct Node {
		Node(Node *next, const T &element):
		next(next),
		element(element)
		{}

		Node *next;
		T element;
	};

public:
	SinglyLinkedList():
	_size(0),
	first(0)
	{}

	~SinglyLinkedList()
	{
		Node *p = first;
		for (int i = 0; i < _size; ++i) {
			Node *aux = p->next;
			delete p;
			p = aux;
		}
	}

	int size() const
	{
		return _size;
	}

	void pushBack(const T &element)
	{
		return insert(_size, element);
	}

	void pushFront(const T &element)
	{
		first = new Node(first, element);
		++_size;
	}

	void insert(int position, const T &element)
	{
		if (position > _size || position < 0) throw std::out_of_range("Out of bounds!");

		if (position == 0) {
			return pushFront(element);
		}

		Node *p = previousNode(position);

		p->next = new Node(p->next, element);

		++_size;
	}

	T popBack()
	{
		return remove(_size-1);
	}

	T popFront()
	{
		checkEmpty();

		T element = first->element;
		Node *aux = first->next;
		delete first;
		--_size;
		first = aux;
		return element;
	}

	T remove(int position)
	{
		checkBounds();

		if (position == 0) {
			return popFront();
		}

		Node *p = previousNode(position);

		Node *aux = p->next;
		T element = aux->element;
		p->next = aux->next;
		delete aux;

		--_size;
		return element;
	}

	T at(int position) const
	{
		checkBounds();

		Node *p = first;
		for (int i = 0; i < position; ++i) {
			p = p->next;
		}
		return p->element;
	}

	T front()
	{
		checkEmpty();
		return first->element;
	}

    T back()
    {
    	return at(_size - 1);
    }

private:
	void checkEmpty() const
	{
		if (_size == 0) throw std::out_of_range("Empty list!");
	}

	void checkBounds()
	{
		if (position >= _size || position < 0) throw std::out_of_range("Out of bounds!");
	}

	Node *previousNode(int position)
	{
		Node *p = first;
		for (int i = 0; i < position-1; ++i) {
			p = p->next;
		}
		return p;
	}

	int _size;

	Node *first;
};

}

#endif
