#ifndef AVL_H
#define AVL_H
#include<iostream>
#include<fstream>
enum Rotation {Left, Right};
#include "../Queues/queue.h"
#include "nodoavl.h"

template <typename T>
class AVL{
private:
    NodoAVL<T> *m_pRoot;
public:
    AVL():m_pRoot(0){}
    ~AVL(){}
    NodoAVL<T> *&getHeadA(){return m_pRoot;}
    NodoAVL<T> *getHead(){return m_pRoot;}

    void RotationSimple(NodoAVL<T>*&, Rotation); //Izq-Izq => 0 , Der-Der => 1;
    void RotationDouble(NodoAVL<T>*&, Rotation); // izq-Der => 0, Der-Izq => 1
    void Add(T d, NodoAVL<T> *&p);
    void printSVG();

};

#include "avl.tpp"

#endif // AVL_H
