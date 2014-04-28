#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdexcept>
#include <string>

using std::string;

template <class T>
class List{
	class Node{
	public:
		Node(Node* next, const T& item):
			next(next),
			item(item)
		{}

		Node* getNextNode() const
		{
			return next;
		}

		void setNextNode(Node* nextNode){
			next = nextNode;
		}

		T& getItem() 
		{
			return item;
		}

	private:
		Node* next;
		T item;
	};

public:
	class Iterator {
	public:	
		Iterator(Node* pointer):
			pointer(pointer)
		{}

		Node* getNode() const
		{
			return pointer;
		}

        Iterator& operator++()
        {
            pointer = pointer->getNextNode();
        	return *this;
        }

        Iterator& operator++(int){
            Iterator& aux(this);
            ++this;
            return aux;
        }

        T& operator*() const
        {
            return pointer->getItem();
        }

		bool operator==(const Iterator& aux) const
		{
			return this->pointer == aux.getNode();
		}

		bool operator!=(const Iterator& aux) const
		{
			return this->pointer != aux.getNode();
		}

	private:
		Node* pointer;
	};

	List():
		size(0),
	  	firstNode(0)
	{}

	~List() 
	{
		for (int i = 0; i < size; i++) {
			Node* next = firstNode->getNextNode();
			delete firstNode;
			firstNode = next;
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

	Iterator begin()
	{
		return Iterator(firstNode);
	}

	Iterator end()
	{
		return Iterator(0);
	}

	void pushBack(const T& element)
	{
		this->pushPosition(size, element);
	}

	void pushFront(const T& element)
	{
		Node* newNode = new Node(firstNode, element);
		firstNode = newNode;
		++size;
	}

	void pushPosition(int position, const T& element)
	{
		if (position == 0) {
			return pushFront(element);
		}

		if (position < 0 || position > size) {
			throw std::range_error("Position out of range.");
		}

		Node* previous = firstNode;
		for (int i = 1; i < position; ++i) {
			previous = previous->getNextNode();
		}
		
		Node* current = new Node(previous->getNextNode(), element);
		previous->setNextNode(current);
		++size;
	}

	void pushOrder(const T& element)
	{

	}

	T popBack()
	{
		return popPosition(size -1);
	}

	T popFront()
	{
		if (size == 0) {
			throw std::range_error("Empty List.");
		}

		T value = firstNode->getItem();
		Node* deletedNode = firstNode;
		firstNode = firstNode->getNextNode();
		delete[] deletedNode;
		--size;
		return value;
	}

	T popPosition(int position)
	{
		if (position < 0 || size < position) {
			string error;
			error = "Número inválido... Entre com um número válido, inteiro, maior ou igual a 0 e menor ou igual a" + length();
			throw std::range_error(error);
		}

		if (position == 0) {
			return this->popFront();
		}

		Node *previous = firstNode;
		for (int i = 1; i < position; ++i) {
			previous = previous->getNextNode();
		}

		T poped = previous->getNextNode()->getItem();
		previous->setNextNode(previous->getNextNode()->getNextNode());
		--size;
		return poped;
	}

private:
	Node* firstNode;
	int size;
};

#endif