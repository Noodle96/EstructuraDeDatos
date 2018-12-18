#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H

#include"nodoBinomialHeap.h"
#include <iostream>
#include<fstream>

template<typename T>
class BinomialHeap{
private:
    //std::list< NodoBH<T>* > m_listaBH;
    LinkedList< NodoBH<T> * > m_listaBH;
    NodoBH<T> *m_pMin;
public:
    BinomialHeap():m_pMin(0){
        m_pMin = new NodoBH<T>(1000000);
    }
    ~BinomialHeap(){}

    bool insert(T);
    void merge( NodoLL< NodoBH<T>* >  *&temp, NodoLL< NodoBH<T>* >  *&tempN, NodoLL< NodoBH<T>* >  *&ptrCmp );
    T getMin();
    bool deleteMin();
    void decreadeKey();
    void printList();


    //FUNCTION SUPPORT
    void normalizarBinomialHeap();
    void findByOrder(T dato, NodoLL< NodoBH<T>* > **&p);
    void insertByOrder(NodoBH<T>*&);
    bool isUniqueBH();


    //void printGraphviz();
    void printInGraphviz();

};

#include "binomialHeap.tpp"

#endif // BINOMIALHEAP_H
