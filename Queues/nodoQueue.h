#ifndef NODOQUEUE_H
#define NODOQUEUE_H

template <typename T>
class NodoQ{
public:
    T m_Dato;
    NodoQ<T> *m_pSgte;
public:
    NodoQ(T data, NodoQ<T>*next=0):m_Dato(data), m_pSgte(next){}
    ~NodoQ(){}
    T getDato()const {return m_Dato;}
    NodoQ<T> *getSgte(){return m_pSgte;}
};


#endif // NODOQUEUE_H
