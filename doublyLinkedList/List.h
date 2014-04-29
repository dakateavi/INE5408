#ifndef _LIST_H_
#define _LIST_H_

template <class T>
class List {
	class Node{
	public:
		Node(Node* previous, Node* next, const T& element):
			previous(previous),
			next(next),
			element(element)
		{}

		Node* next;
		Node* previous;
		T element;
	};
public:
	List():
		_size(0),
		first(0),
		last(0)
	{}

	~List()
	{
		Node* aux;
		for(int i = 0; i < _size; ++i){
			aux = first;
			first = first->next;
			delete aux;
		}
	}

	bool isEmpty() const
	{
		return _size == 0;
	}

	int size() const
	{
		return _size;
	}

	void pushFront(const T& added)
	{
		if(_size == 0){
			first = last = new Node(0, 0, added);
			++_size;
			return;
		}

		first = new Node(0, first, added);
		first->next->previous = first;
		++_size;
	}

	T popFront()
	{
		if(isEmpty()){
			throw std::length_error("Poping from empty list!");
		}

		if(_size == 1){
			T element = first->element;
			delete first;
			first = 0;
			last = 0;
			--_size;
			return element;
		}

		T element = first->element;
		Node* aux = first;
		first = first->next;
		first->previous = 0;
		delete aux;
		--_size;

		return element;
	}

	void pushBack(const T& added)
	{
		if(_size == 0){
			first = last = new Node(0, 0, added);
			++_size;
			return;
		}

		last->next = new Node(last, 0, added);
		last = last->next;
		++_size;
	}

	T popBack()
	{
		if(isEmpty()){
			throw std::length_error("Poping from empty list!");
		}

		if(_size == 1){
			T element = last->element;
			Node* aux = last;
			first = 0;
			last = 0;
			delete aux;
			--_size;
			return element;
		}

		T element = last->element;
		Node* p = last;
		last = last->previous;
		last->next = 0;
		delete p;
		--_size;

		return element;
	}

private:
	int _size;

	Node* first;
	Node* last;
};

#endif