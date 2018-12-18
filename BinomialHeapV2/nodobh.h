#ifndef NODOBH_H
#define NODOBH_H
#include<iostream>
#include<list>
using namespace std;

template<typename T>
class NodoBH{
public:
    T m_datoNBH;
    int orderNBH;
    std::list< NodoBH<T>* > m_ChildrenNBH;
    NodoBH<T> *m_fatherNBH;
public:
    NodoBH(T dato, int order = 0, NodoBH<T> *m_padre = 0){
        this->m_datoNBH = dato;
        this->orderNBH = order;
        this->m_fatherNBH = m_padre;
    }
    ~NodoBH(){}

    friend bool operator == (const NodoBH<T> &p1, const NodoBH<T>&p2){
        return p1.m_datoNBH == p2.m_datoNBH;
    }


    friend std::ostream &operator << (std::ostream &out, NodoBH<T>&p){
        out << "Dato " << p.m_datoNBH
            << " Order: " << p.orderNBH << " ";
            if(p.m_fatherNBH) out << "FatherDato: " << p.m_fatherNBH->m_datoNBH << std::endl;
            else{ out << " FatherDato: ///" << std::endl;}
        return out;
    }


};



#endif // NODOBH_H
