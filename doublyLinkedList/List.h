#ifndef _LIST_H_
#define _LIST_H_

template <class T>
class List {
public:
	List():
		_size(0)
	{}

	bool isEmpty()
	{
		return _size == 0;
	}

	int size()
	{
		return _size;
	}

	void pushFront(const T& added)
	{
		singleton = added;
		++_size;
	}

	T popFront()
	{
		if(isEmpty()){
			throw std::length_error("Poping from empty list!");
		}
		return singleton;
	}
private:
	int _size;

	T singleton;
};

#endif