#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "nodolist.h"

template <typename T>
class LinkedList{
public:
    NodoList<T> *m_pHead;
    NodoList<T> *m_pLast;
    int len;
public:
    LinkedList(){
    m_pHead = m_pLast = 0;
    len = 0;
    }

};


#include "linkedlist.tpp"

#endif // LINKEDLIST_H
