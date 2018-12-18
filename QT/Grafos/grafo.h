#ifndef GRAFO_H
#define GRAFO_H

#include "ladrillos.h"
#include <algorithm>
#include <fstream>

template<typename V, typename E>
class Grafo{
private:
    std::list< Vertice<V,E> > m_ListaG;
public:
    Grafo(){}
    bool addVertice(V);
    bool addArista(V,V,E);
    void print();
    void PrintInDot();
};

#include "grafo.tpp"

#endif // GRAFO_H
