#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdexcept>
#include <iostream>

template <class T>
class List{
	class Node{
	public:
		Node(Node* next, const T& item):
			next(next),
			item(item)
		{}

		Node* getNextNode()
		{
			return next;
		}

		void setNextNode(Node* nextNode){
			next = nextNode;
		}

		T getItem()
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

		void next() 
		{
			pointer = pointer->getNextNode();
		}

		Node* getNode() const 
		{
			return pointer;
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
			throw std::range_error("Position out of range.");
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