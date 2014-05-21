#ifndef _DoublyLinkedList_h_
#define _DoublyLinkedList_h_

#include <stdexcept>
#include "List.h"

namespace dataStructures {

template <class T>
class DoublyLinkedList : public dataStructures::List<T> {
	struct Node{
		Node(Node* previous, Node* next, const T& element):
		previous(previous),
		next(next),
		element(element)
		{}

		Node* previous;
		Node* next;
		T element;
	};
public:
	DoublyLinkedList():
	_size(0),
	first(0),
	last(0)
	{}

	~DoublyLinkedList()
	{
		Node* aux;
		for(int i = 0; i < _size; ++i){
			aux = first;
			first = first->next;
			delete aux;
		}
	}

	int size() const
	{
		return _size;
	}

	bool isEmpty() const
	{
		return _size == 0;
	}

	void pushBack(const T &element)
	{
		if (_size == 0) {
			first = last = new Node(0, 0, element);
			++_size;
			return;
		}

		last->next = new Node(last, 0, element);
		last = last->next;

		++_size;
	}

	void pushFront(const T &element)
	{
		if (_size == 0) {
			first = last = new Node(0, 0, element);
			++_size;
			return;
		}

		first->previous = new Node(0, first, element);
		first = first->previous;

		++_size;
	}

	void insert(int position, const T &element)
	{
		if (position > _size || position < 0) throw std::out_of_range("Out of bounds!");

		if (position == 0) {
			return pushFront(element);
		}

		if (position == _size) {
			return pushBack(element);
		}

		Node *aux = first;
		for (int i = 0; i < position; ++i) {
			aux = aux->next;
		}

		aux->previous->next = new Node(aux->previous, aux, element);
		aux->previous = aux->previous->next;

		++_size;
	}

	T popBack()
	{
		checkEmpty();

		Node *removed = last;
		last = removed->previous;
		if (_size > 1) {
			last->next = 0;
		} else {
			first = 0;
		}
		T element(removed->element);
		--_size;
		delete removed;
		return element;
	}

	T popFront()
	{
		checkEmpty();

		Node *removed = first;
		first = removed->next;
		if (_size > 1) {
			first->previous = 0;
		} else {
			last = 0;
		}
		T element(removed->element);
		--_size;
		delete removed;
		return element;
	}

	T remove(int position)
	{
		checkBounds(position);

		if (position == 0) {
			return popFront();
		}

		if (position == _size-1) {
			return popBack();
		}

		Node *aux = first;
		for (int i = 0; i < position; ++i) {
			aux = aux->next;
		}

		aux->previous->next = aux->next;
		aux->next->previous = aux->previous;
		T element(aux->element);
		delete aux;
		--_size;

		return element;
	}

	T front()
	{
		checkEmpty();
		return first->element;
	}

	T back()
	{
		checkEmpty();
		return last->element;
	}

	T at(int position) const
	{
		checkBounds(position);

		Node *p = first;
		for (int i = 0; i < position; ++i) {
			p = p->next;
		}
		return p->element;
	}

private:
	void checkEmpty() const
	{
		if (_size == 0) throw std::out_of_range("Empty list!");
	}

	void checkBounds(int position) const
	{
		if (position >= _size || position < 0) throw std::out_of_range("Out of bounds!");
	}

	int _size;

	Node* first;
	Node* last;
};

}

#endif