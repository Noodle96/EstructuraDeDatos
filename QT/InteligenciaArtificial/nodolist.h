#ifndef NODOLIST_H
#define NODOLIST_H

template <typename T>
class NodoList{
public:
    T datol;
    NodoList<T> *sgte;
public:
    NodoList(T da){
        datol = da;
        sgte = 0;
    }
    ~NodoList(){}
};

#endif // NODOLIST_H
