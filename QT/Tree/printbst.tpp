/*
    void printInfijo(NodoBST<T>*);
    void printPrefijo(NodoBST<T>*);
    void printPosfijo(NodoBST<T>*);
    void printPorNiveles();

*/

template <typename T>
void Bst<T>::printInfijo(NodoBST<T>*p){
    if(!p){
        //std::cout  << '\n';
        return;
    }
    printInfijo(p->m_pSon[0]);
    std::cout  << p->m_Dato << " ";
    printInfijo(p->m_pSon[1]);
}

template<typename T>
void Bst<T>::formarVectorInfijo( NodoBST<T>*p,std::vector<T> *&vec){
    if(!p){return ;}
    formarVectorInfijo(p->m_pSon[0],vec);
    vec->push_back(p->m_Dato);
    formarVectorInfijo(p->m_pSon[1],vec);
}

template <typename T>
void Bst<T>::printPrefijo(NodoBST<T>*p){
    if(!p){
        // std::cout  << '\n';
        return;
    }
    std::cout  << p->m_Dato << " ";
    printPrefijo(p->m_pSon[0]);
    printPrefijo(p->m_pSon[1]);
}


template <typename T>
void Bst<T>::printPosfijo(NodoBST<T>*p){
    if(!p){
        // std::cout  << '\n';
        return;
    }
    printPosfijo(p->m_pSon[0]);
    printPosfijo(p->m_pSon[1]);
    std::cout  << p->m_Dato << " ";
}



template <typename T>
void Bst<T>::printPorNiveles(){
    Queue< NodoBST<T>* > *treeQueue = new Queue< NodoBST<T>* >();
    treeQueue->push(m_pRoot);
    while( !treeQueue->isEmpty() ){
        NodoBST<T> *nodo = treeQueue->top();treeQueue->pop();
        std::cout << nodo->m_Dato << ' ';
        if(nodo->m_pSon[0]) treeQueue->push(nodo->m_pSon[0]);
        if(nodo->m_pSon[1]) treeQueue->push(nodo->m_pSon[1]);
    }
    std::cout  << '\n';
    delete treeQueue;
}



template <typename T>
void Bst<T>::printPorNivelesPares(){
    Queue< NodoBST<T>* > *treeQueue = new Queue< NodoBST<T>* >();
    treeQueue->push(m_pRoot);
    while( !treeQueue->isEmpty() ){
        NodoBST<T> *nodo = treeQueue->top();treeQueue->pop();
        if(nodo->m_Dato % 2 == 0)std::cout << nodo->m_Dato << ' ';
        if(nodo->m_pSon[0]) treeQueue->push(nodo->m_pSon[0]);
        if(nodo->m_pSon[1]) treeQueue->push(nodo->m_pSon[1]);
    }
    std::cout  << '\n';
    delete treeQueue;
}



//imprime el arbol de abajo hacia arriba y de izq a der
/*
    meter a una cola la raiz;
    mientras no este vacia:
        desencolar el nodo y meterlo a un a pila
        luego meter el hijo derecho y luego el izq;
*/
template <typename T>
void Bst<T>::printPorNivelesAbajoArribaDI(){
    Queue< NodoBST<T>* > *treeQueue = new Queue< NodoBST<T>* >();
    Stack< NodoBST<T>* > *treeStack = new Stack< NodoBST<T>* >();
    treeQueue->push(m_pRoot);
    while( !treeQueue->isEmpty() ){
        NodoBST<T> *nodo = treeQueue->top();treeQueue->pop();
        treeStack->push(nodo);
        if(nodo->m_pSon[1]) treeQueue->push(nodo->m_pSon[1]);
        if(nodo->m_pSon[0]) treeQueue->push(nodo->m_pSon[0]);
    }

    while(!treeStack->isEmpty()){
        std::cout << treeStack->top()->m_Dato << ' '; treeStack->pop();
    }
    std::cout << '\n';


    delete treeQueue;
    delete treeStack;
}


//end printbst.tpp
