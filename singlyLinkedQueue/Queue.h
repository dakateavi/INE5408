#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdexcept>

template <class T>
class Queue{
	struct Node{
		Node(Node* next, const T& element):
			next(next),
			element(element)
		{}

		Node* next;
		T element;
	};

public:
	Queue():
		size(0),
	  	first(0),
	  	last(0)
	{}

	~Queue() 
	{
		Node* next;
		for (int i = 0; i < size; i++) {
			next = first->next;
			delete first;
			first = next;
		}
	}

	bool isEmpty() const
	{
		return size == 0;
	}

	int length() const
	{
		return size;
	}

	void push(const T& element)
	{
		if(size == 0){
			first = last = new Node(0,element);
			++size;
			return;
		}

		Node* added = new Node(0, element);
		last->next = added;
		last = last->next;
		++size;
	}

	T pop()
	{
		if(size == 0){ 
			throw std::out_of_range("Poping From Empty List!");
		}

		T poped = first->element;
		Node* aux = first->next;
		delete first;
		first = aux;
		--size;
		return poped;
	}

private:
	Node* first;
	Node* last;
	int size;
};

#endif
