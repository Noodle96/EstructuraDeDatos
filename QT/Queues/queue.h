#ifndef QUEUE_H
#define QUEUE_H

#include "nodoQueue.h"
template <typename T>
class Queue{
private:
    NodoQ<T> *m_pFirst;
    NodoQ<T> *m_pLast;
public:
    Queue(){
        m_pFirst = m_pLast = 0;
    }
    ~Queue(){}

    //members functions
    bool isEmpty();
    bool push(T);
    bool pop();
    T top();
    void print();


};

#include "queue.tpp"

#endif // QUEUE_H
