#ifndef NODOLINKEDLIST_H
#define NODOLINKEDLIST_H

template<typename T>
class NodoLL{
public:
    T m_datoLL;
    NodoLL<T> *m_pSgteLL;
public:
    NodoLL(T dato):m_datoLL(dato),m_pSgteLL(0){}
    ~NodoLL(){}
};


#endif // NODOLINKEDLIST_H
