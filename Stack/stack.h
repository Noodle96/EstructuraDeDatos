#ifndef STACK_H
#define  STACK_H

#include "nodoStack.h"

template <typename T>
class Stack{
private:
    NodoS<T> *m_pTope;
public:
    Stack(NodoS<T>*tope = 0): m_pTope(tope){}
    ~Stack(){}

    NodoS<T> *getTope(){return m_pTope;}

    //members functions
    bool isEmpty();
    bool push(T);
    bool pop();
    T top();
    void print();
};

#include "stack.tpp"

#endif // STACK_H
