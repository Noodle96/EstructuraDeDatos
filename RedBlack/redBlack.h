#ifndef  REDBLACK_H
#define REDBLACK_H
#include<iostream>
#include <fstream>

#include "nodoRB.h"
#include "../Queues/queue.h"
template<typename T>
class RedBlack{
private:
    NodoRB<T> *m_pRoot;
public:
    RedBlack():m_pRoot(0){}
    ~RedBlack(){}

    void Add(T);

    //ROTACIONES
    void rotar_izda(NodoRB<T> *&);
    void rotar_dcha(NodoRB<T> *&);


    //PARIENTS
    NodoRB<T> *abuelo(NodoRB<T> *);
    NodoRB<T> *tio(NodoRB<T> *);


    //INSERCIONES CASOS
    void insercion_caso1(NodoRB<T> *&n);
    void insercion_caso2(NodoRB<T> *&n);
    void insercion_caso3(NodoRB<T> *&n);
    void insercion_caso4(NodoRB<T> *&n);
    void insercion_caso5(NodoRB<T> *&n);


    //print
    void print();
    void printSVG();

};

#include "RedBlack.tpp"


#endif // REDBLACK_H
