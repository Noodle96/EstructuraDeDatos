#ifndef BST_H
#define BST_H
#include<cmath>
#include "../Queues/queue.h"
#include "../Stack/stack.h"
#include "NodoBst.h"
#include "functions.h"

template <typename T>
class Bst{
private:
    NodoBST<T> *m_pRoot;
public:
    Bst():m_pRoot(0){}
    ~Bst(){}
    NodoBST<T> *&getHeadA(){return m_pRoot;}
    NodoBST<T> *getHead(){return m_pRoot;}

    //bst.tpp
    bool AddR(T d, NodoBST<T>*&);
    bool findR(T d, NodoBST<T>*);
    bool findI(T);
    bool AddI(T);


    //printBST.tpp
    void printInfijo(NodoBST<T>*);
    void printPrefijo(NodoBST<T>*);
    void printPosfijo(NodoBST<T>*);
    void printPorNiveles();
    void printPorNivelesPares();
    void printPorNivelesAbajoArribaDI();

    //altura.tpp
    int altura(NodoBST<T>*);

    //parients.tpp
    NodoBST<T> *getParent(T);
    NodoBST<T> *getBrother(T);
    NodoBST<T> *getUncle(T);
    NodoBST<T> *getGrandFather(T);

    //nivelNodo.tpp
    int nivelNodo(T);



    //manipulacion.tpp
    bool findDP(T d, NodoBST<T>**&);



    //deletes.tpp
    //bool eliminarHoja(T d);




};

#include "bst.tpp"
#include "altura.tpp"
#include "parients.tpp"
#include "nivelNodo.tpp"
#include "printBST.tpp"
//#include "deletes.tpp"

#endif // BST_H
