#ifndef NODORB_H
#define NODORB_H

enum Color {RED, BLACK};
template<typename T>
class NodoRB{
public:
    T m_Dato;
    Color color;
    NodoRB<T> *m_pSon[2];
    NodoRB<T> *m_pFather;
public:
    NodoRB(T d){
        this->color= RED;
        m_Dato = d;
        m_pSon[0] = m_pSon[1] = m_pFather = 0;
    }
};

#endif //NODORB_H
