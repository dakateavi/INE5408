#ifndef _LIST_H_
#define _LIST_H_

namespace dataStructures {

template <class T>
class List{
    virtual int size() const = 0;
    virtual bool isEmpty() const = 0;

    virtual void pushFront(const T&) = 0;
    virtual void pushBack(const T&) = 0;
    virtual void insert(int, const T&) = 0;

    virtual T popFront() = 0;
    virtual T popBack() = 0;
    virtual T remove(int position) = 0;

    virtual T front() = 0;
    virtual T back() = 0;
    virtual T at(int position) const = 0;
};

}

#endif