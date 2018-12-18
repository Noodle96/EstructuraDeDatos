#ifndef NODOAVL_H
#define NODOAVL_H

template <typename T>
class NodoAVL{
public:
    T m_Dato;
    NodoAVL<T> *m_pSon[2];
    short int FE;
public:
    NodoAVL(T data): m_Dato(data){
        m_pSon[0] = m_pSon[1] = 0;
        FE =0;
    }
    ~NodoAVL(){}
};

#endif // NODOAVL_H
