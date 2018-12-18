/*
    FUNCIONES QUE RECORREN LA LISTA :
    Nodo<T> *movePrevious(Nodo<T>*);
    Nodo<T> *moveNext(Nodo<T>*);
    Nodo<T> *moveLast(Nodo<T>*);
    Nodo<T> *moveBegin(Nodo<T>*);
*/

/*
    Dado un nodo , retorna el nodo anterior empezando desde el inicio
*/
template <typename T>
Nodo<T> *LinkedList<T>::movePrevious(Nodo<T>*p){
    // if(!p)return 0;
    if(p == m_pHead)return p;
    Nodo<T>*temp = m_pHead;
    for( ; temp->m_pSig != p  ; temp = temp->m_pSig);
    return temp;
}


template <typename T>
Nodo<T> *LinkedList<T>::moveNext(Nodo<T>*p){
    if(!p->m_pSig)return p;
    return p->m_pSig;
}


template <typename T>
Nodo<T> *LinkedList<T>::moveBegin(Nodo<T>*p){
    return m_pHead;
}


template <typename T>
Nodo<T> *LinkedList<T>::moveLast(Nodo<T>*p){
    Nodo<T>  *temp = p;
    for( ; temp->m_pSig ;temp = temp->m_pSig );
    return temp;
}




















// end moving.tpp
