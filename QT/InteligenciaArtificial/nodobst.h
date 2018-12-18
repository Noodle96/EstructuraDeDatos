#ifndef NODOBST_H
#define NODOBST_H


template <typename T>
class NodoBST{
public:
    T m_Dato;
    NodoBST<T> *m_pSon[2];
public:
    NodoBST(T data): m_Dato(data){
        m_pSon[0] = m_pSon[1] = 0;
    }
    ~NodoBST(){}
};


#endif // NODOBST_H
