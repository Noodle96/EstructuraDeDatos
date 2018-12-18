#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "nodoLinkedList.h"
#include<iostream>
#include<fstream>
#include <list>
#include<map>

template<typename T>
class LinkedList{
private:
    NodoLL<T> *m_pHeadLL;
public:
    LinkedList():m_pHeadLL(0){}
     ~LinkedList(){}

    NodoLL<T> *&getHead(){return m_pHeadLL;}

    void push_front(T);
    void push_frontNode(NodoLL<T>*&);
    bool findR(T, NodoLL<T>**&);
    void printReference();
    void print();
    bool isEmpty(){return !m_pHeadLL;}


    bool isUnique();
    NodoLL<T> *&beginRef(){return m_pHeadLL;}
    NodoLL<T> *begin(){return m_pHeadLL;}

    bool findByOrder(T d , NodoLL<T> **&p);
    bool insertByOrder(T d);
    void areglar(T d);
    void areglarWithNode(NodoLL<T> *&p);
    void printInGraphviz();
    void InNodo(NodoLL<T>*&);

    void print_map_global();

    void makeDotPrint();
};

#include "linkedList.tpp"



#endif // LINKEDLIST_H
