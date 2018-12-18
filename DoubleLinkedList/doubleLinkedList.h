#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "nodoDoubleLL.h"
template<typename T>
class DoubleLinkedList{
private:
    NodoDLL<T> *m_pHead;
    NodoDLL<T> *m_pLast;
public:
    DoubleLinkedList(){
        m_pHead = 0;
        m_pLast = 0;
        // std::cout << "Constructor" << '\n';
    }
    ~DoubleLinkedList(){
        // std::cout << "Destructor" << '\n';
        destruir(m_pHead);
    }
    NodoDLL<T> *getHead(){return m_pHead;};


    void destruir(NodoDLL<T>*);
    bool isEmpty();

    bool addFront(T);
    bool addLast(T);
    bool Add(T);

    bool deleteFront();
    bool deleteLast();
    bool Delete(T);


    void printI();
    void printR(NodoDLL<T>*);

    bool findI(T d, NodoDLL<T>**&);
    bool findR(T d, NodoDLL<T>*);

};

#include "doubleLinkedList.tpp"

#endif // DOUBLELINKEDLIST_H
