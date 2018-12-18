#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H

#include "nodobh.h"

//using  vfg = int;
template <class RandomAccessIterator, class T>
using Iter = class std::list<NodoBH<T>*>;


template<typename T>
class BinomialHeap{
private:
    std::list< NodoBH<T>* > m_listBH;
    NodoBH<T>* m_Minimo;
public:
    BinomialHeap(){
        m_Minimo = new NodoBH<T>(10000);
    }
    ~BinomialHeap(){}


    void insertByOrder(T d);//interna
    void removeByDato(T);
    void printOnlyListBH();
    void AsignarPadre(NodoBH<T> *&);
    void pushFront(NodoBH<T>*&); // interna

    void insertar(T); //externa

    void normalize();

    //void merge( std::list< NodoBH<T>* >::iterator , std::list< NodoBH<T>* >::iterator , std::list< NodoBH<T>* >::iterator   );
    void merge(NodoBH<T>*&, NodoBH<T>*&, NodoBH<T>*&);




};

#include "binomialheap.tpp"


#endif // BINOMIALHEAP_H
