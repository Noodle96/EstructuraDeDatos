#ifndef LINKED_LIST
#define LINKED_LIST
#include<fstream>

#include "nodo.h"

template<typename T>
class LinkedList{
    typedef Nodo<T>  * pNodo;
    private:
       pNodo m_pHead;
       pNodo m_pLast;
    public:
       LinkedList(){
         m_pHead = 0;
         m_pLast =0;
       }

    void setHead(Nodo<T> *newnodo){m_pHead = newnodo;}
    void setLast(Nodo<T> *newnodo){m_pLast = newnodo;}

    Nodo<T> * &getHead(){return m_pHead;}
    Nodo<T> * getHeadP(){return m_pHead;}
    Nodo<T> * &getLast(){return m_pLast;}


    void push_front(T d);
    void push_back(T d);

    void pop_front();
    void pop_back();

    bool find_iterativo(T d);
    bool find_recursivo(T d, Nodo<T>*);

    void print();
    void Add(T d, Nodo<T> * & p);//recursivo


    //isEmpty() => verifica si una lista esta vacia
    bool isEmpty();

    //operaciones basicas en una lista enlazada
    LinkedList<T>  * Union(LinkedList<T> *&);




    // en aplicartion.tpp
    // 1.- UNION DE DOS LISTA EN UNA TERCERA
    LinkedList<T> *UnionL(LinkedList<T>*);

    // 2,. INTERSECCION DE DOS LISTAS EN UNA TERCERA
    LinkedList<T> *InterseccionL(LinkedList<T>*);

    // 3.- INSERCION DE ELEMENTOS ORDENADAMENTE
    void addOrdenadamente(T);

    // 4.- INVERTIR UNA LISTA EN LA MISMA(NO USAR OTRA)
    void invertir();

    // 5.- IMPRIMIR RECURSIVAMENTE DESDE ATRAS PARA ADELANTE
    void imprimirRecursivoAlReves(Nodo<T>*);
    void insertaOfFile();





    //cuerpo de las funciones en : funcionesPrincipales.tpp
    //FUNCIONES PRINCIPALES PARA LA MANIPULACION DE ALGUNA APLICACION
    bool findR(T, Nodo<T>**&);
    bool AddR(T);
    void printR(Nodo<T>*);




};


 #include "linked_list.tpp"
 #include "aplication.tpp"
 #include "funcionesPrincipales.tpp"


#endif // LINKED_LIST
