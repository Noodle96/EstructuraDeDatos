#ifndef NODODOUBLELL_H
#define NODODOUBLELL_H

template<typename T>
class NodoDLL{
public:
    NodoDLL *m_pPrev;
    NodoDLL *m_pNext;
    T m_dato;
    NodoDLL(T data, NodoDLL *prev = 0, NodoDLL * next = 0){
        m_dato = data;
        m_pPrev = prev;
        m_pNext = next;
    }
};


#endif // NODODOUBLELL_H
