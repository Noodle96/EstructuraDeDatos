/*
    funciones de manipulacion en un bst
    bool findDP(T d, NodoBST<T>**&);
*/

template <class T>
bool Bst<T>::findDP(T d, NodoBST<T>**&p ){
    p = &(m_pRoot);
    while(*p){
        if( (*p)->m_Dato == d )return true;
        p = &((*p)->m_pSon[(*p)->m_Dato < d]);
    }
    return false;

}



//end manipulacion.tpp
