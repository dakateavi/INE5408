#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "DoublyLikedList.h"

namespace structures {

template <class T, class Container = structures::DoublyLikedList<T> >
class Queue {
public:
  int size() const
  {
    return container.size();
  }

  bool isEmpty() const 
  {
    return container.isEmpty();
  }

  void push(const T& element)
  {
    container.pushBack(element);
  }

  T front() const
  {
    return container.at(0);
  }

  T back()
  {
    return container.at(container.size()-1);
  }

  T pop()
  {
    return container.popFront();
  }

private:
  Container<T> container;
};

}
#endif
