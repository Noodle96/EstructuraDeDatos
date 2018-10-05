/*
    //parients.tpp
    NodoBST<T> *getParent(T);
    NodoBST<T> *getBrother(T);
    NodoBST<T> *getUncle(T);
    NodoBST<T> *getGrandFather(T);
*/


// en tres casos retorna 0 : que este vacia; que sea el m_pRoot; que el dato no este
template <typename T>
NodoBST<T> *Bst<T>::getParent(T d){
    if(!m_pRoot)return 0;
    NodoBST<T> *p, *q;
    p=m_pRoot;
    if(p->m_Dato == d)return 0;
    q = p;
    p = p->m_pSon[ p->m_Dato < d ];

    while(p){
        if(p->m_Dato == d) return q;
        q = p;
        p = p->m_pSon[ p->m_Dato < d ];
    }
    return 0;
}


template <typename T>
NodoBST<T> *Bst<T>::getBrother(T d){
    if(!getParent(d))return 0; // tres casos: que este vacia; que sea el m_pRoot; que el dato no este
    NodoBST<T> *parent = getParent(d);
    return parent->m_pSon[ parent->m_Dato > d ];
}


template <typename T>
NodoBST<T> *Bst<T>::getUncle(T d){
    NodoBST<T> *parent = getParent(d);
    if(!parent)return 0; // tres casos: que este vacia; que sea el m_pRoot; que el dato no este
    NodoBST<T> *brother = getBrother(parent->m_Dato);
    return brother;
}



template <typename T>
NodoBST<T> *Bst<T>::getGrandFather(T d){
    NodoBST<T> *parent = getParent(d);
    if(!parent)return 0;
    return  getParent(parent->m_Dato);
}





//end parients.tpp
