template <typename T>
NodoBST<T> *&bst<T>::getHead(){
    return m_pRoot;
}


template <typename T>
bool bst<T>::findIDP(T d, NodoBST<T>**&p){
    p = &(m_pRoot);
    while(*p){
        if( (*p)->m_Dato == d ) return true;
        p = &((*p)->m_pSon[(*p)->m_Dato < d]);
    }
    return false;
}



template <typename T>
bool bst<T>::addIDP(T d){
    NodoBST<T> **q;
    if( findIDP(d,q))return false;
    NodoBST<T> *nuevo = new NodoBST<T>(d);
    (*q) = nuevo;
    return true;
}


template<typename T>
void bst<T>::printInfijo(NodoBST<T> *p){
    if(!p){
        //std::cout << std::endl;
        return;
    }
    printInfijo(p->m_pSon[0]);
    std::cout << p->m_Dato << " ";
    printInfijo(p->m_pSon[1]);
}


template<typename T>
void bst<T>::printInfijoI(NodoBST<T> *p){
    if(!p){
       // std::cout <<  std::endl;
        return;
    }
    printInfijoI(p->m_pSon[0]);
    std::cout << *(p->m_Dato) << " ";
    printInfijoI(p->m_pSon[1]);
}


template <typename T>
void bst<T>::printPorNiveles(){
    Queue< NodoBST<T>* > *treeQueue = new Queue< NodoBST<T>* >();
    treeQueue->push(m_pRoot);
    while( !treeQueue->isEmpty() ){
        NodoBST<T> *nodo = treeQueue->top();treeQueue->pop();

        //std::cout << nodo->m_Dato << ' ';
        visitar(nodo);

        if(nodo->m_pSon[0]) treeQueue->push(nodo->m_pSon[0]);
        if(nodo->m_pSon[1]) treeQueue->push(nodo->m_pSon[1]);
    }

    std::cout  << '\n';
    delete treeQueue;
}
