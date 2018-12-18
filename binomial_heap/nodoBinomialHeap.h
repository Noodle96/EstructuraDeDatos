#ifndef NODOBINOMIALHEAP_H
#define NODOBINOMIALHEAP_H

using Order = unsigned short int ;
#include "linkedList.h"

template<typename T>
class NodoBH{
public:
    T m_dato;
    Order m_order;
    LinkedList< NodoBH<T>* > m_Children;
    //std::list<  NodoBH<T>* > m_Children;
public:
    NodoBH(T dato, Order ord = 0): m_dato(dato), m_order(ord){}
    ~NodoBH(){}



    //setters and getters
    T getDato()const {return m_dato;}
    Order getOrder()const{return m_order;}

    friend std::ostream& operator << (std::ostream &out, NodoBH &p){
        out << p.m_dato << " " << p.m_order
            << "\n";
        return out;
    }
};




#endif // NODOBINOMIALHEAP_H
