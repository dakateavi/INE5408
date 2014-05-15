#ifndef _LIST_H_
#define _LIST_H_

namespace structures {

template <class T>
class List{
    int size() const = 0;
    bool isEmpty() const = 0;

    void pushFront(const T&) = 0;
    void pushBack(const T&) = 0;
    void insert(int, const T&) = 0;

    T popFront() = 0;
    T popBack() = 0;
    T remove(int position) = 0;

    T front() = 0;
    T back() = 0;
    T at(int position) const = 0;
};

}

#endif