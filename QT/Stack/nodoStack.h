#ifndef NODOSTACK_H
#define NODOSTACK_H

template <typename T>
class NodoS{
public:
    T  m_Dato;
    NodoS<T> *m_pSgte;
public:
    NodoS(T data, NodoS<T>*sgte=0): m_Dato(data), m_pSgte(sgte){}
    ~NodoS(){}
    T getDato()const{return m_Dato;}
    NodoS<T> *getSgte(){return m_pSgte;}
};



#endif // NODOSTACK_H
