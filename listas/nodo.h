#ifndef NODE_H
#define NODE_H

template<typename T>
class Nodo{
public:
    Nodo<T>  *m_pSig;
    T m_Dato;
public:
    Nodo(T d){
        m_Dato=d;
        m_pSig=0;
    }
};

#endif //NODE_H
