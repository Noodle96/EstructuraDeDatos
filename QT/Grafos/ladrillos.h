#ifndef LADRILLOS_H
#define LADRILLOS_H
#include<iostream>
#include<list>

template<typename V, typename E>
class Arista;


template<typename V, typename E>
class Vertice{
public:
    V m_DatoV;
    std::list< Arista<V,E> > m_listAristaV;
public:
    Vertice(V dato){
        this->m_DatoV = dato;
    }
    friend bool operator >(const Vertice &p1,const Vertice &p2){
            return p1.m_DatoV > p2.m_DatoV;
    }
    friend bool operator <(const Vertice &p1,const Vertice &p2){
        return p1.m_DatoV < p2.m_DatoV;
    }
    friend bool operator !=(const Vertice &p1,const Vertice &p2){
        return p1.m_DatoV != p2.m_DatoV;
    }

    friend bool operator==(const Vertice &p1,const Vertice &p2){
        return p1.m_DatoV == p2.m_DatoV;
    }
};

template<typename V, typename E>
class Arista{
public:
    E m_DatoE;
    Vertice<V,E> *p_Destino;
public:
    Arista(E dato, Vertice<V,E> *p=0){
        this->m_DatoE = dato;
        p_Destino =p;
    }
    friend bool operator >(const Arista &p1,const Arista &p2){
          return p1.m_DatoE > p2.m_DatoE;
    }
    friend bool operator <(const Arista &p1,const Arista &p2){
        return p1.m_DatoE < p2.m_DatoE;
    }
    friend bool operator !=(const Arista &p1,const Arista &p2){
        return p1.m_DatoE != p2.m_DatoE;
    }

    friend bool operator==(const Arista &p1,const Arista &p2){
        return p1.m_DatoE == p2.m_DatoE;
    }
};



#endif // LADRILLOS_H
