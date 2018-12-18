#ifndef BST_H
#define BST_H
#include<iostream>
#include<vector>
//using namespace std;
#include "nodobst.h"

#include "../Queues/queue.h"
#include "../Stack/stack.h"


template<typename T>
class bst{
private:
    NodoBST<T> *m_pRoot;
public:
    bst(): m_pRoot(0){}
    ~bst(){}
    NodoBST<T> *&getHead();
    bool findIDP(T d, NodoBST<T>**&);
    bool addIDP(T);
    void printInfijo(NodoBST<T>*);
    void printInfijoI(NodoBST<T>*);
    void printPorNiveles();

};

#include "bst.tpp"


#endif // BST_H
