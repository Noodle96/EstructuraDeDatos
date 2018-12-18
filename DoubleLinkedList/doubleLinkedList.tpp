// as doubleLinkedList.cc

/*
    FUNCIONES PRINCIPALES DE LA  LISTA DOBLEMENTE ENLAZADA:

    void destruir(NodoDLL<t>*head);
    bool isEmpty();
    bool addFront(T);
    bool addLast(T);
    void printI();
    void printR(NodoDLL<T>*);
    bool findI(T d, NodoDLL<T>**&);
    bool findR(T d, NodoDLL<T>*);
    bool Add(T);
    bool deleteFront();
    bool deleteLast();
    bool Delete(T);

*/



template <typename T>
void DoubleLinkedList<T>::destruir(NodoDLL<T> *head){
    if(head){
        destruir(head->m_pNext);
        delete head;
    }
}



template<typename T>
bool DoubleLinkedList<T>::isEmpty(){
    if(!m_pHead)return true;
    return false;
}



template <typename T>
bool DoubleLinkedList<T>::addFront(T dato){
    NodoDLL<T> *nuevo = new NodoDLL<T>(dato);
    if(!m_pHead){
        m_pHead = m_pLast = nuevo;
        return true;
    }
    m_pHead->m_pPrev = nuevo;
    nuevo->m_pNext = m_pHead;
    m_pHead = nuevo;
    return true;

}



template <typename T>
bool DoubleLinkedList<T>::addLast(T dato){
    NodoDLL<T> *nuevo = new NodoDLL<T>(dato);
    if(!m_pHead){
        m_pHead = m_pLast = nuevo;
        return true;
    }
    nuevo->m_pPrev = m_pLast;
    m_pLast->m_pNext = nuevo;
    m_pLast = nuevo;
    return true;
}




template <typename T>
void DoubleLinkedList<T>::printI(){
    NodoDLL<T> *temp = m_pHead;
    for( ; temp != m_pLast; temp = temp->m_pNext ){
        std::cout << temp->m_dato << ' ';
    }
    std::cout << temp->m_dato << '\n';
}




template <typename T>
void DoubleLinkedList<T>::printR(NodoDLL<T>*p){
    if(!p){
        std::cout << '\n';return;
    }
    std::cout << p->m_dato << ' ';
    printR(p->m_pNext);
}


template <typename T>
bool DoubleLinkedList<T>::findI(T d, NodoDLL<T>**&p){
    p = &(m_pHead);
    while(*p){
        if( (*p)->m_dato == d ) return true;
        if( (*p)->m_dato > d ) return false;
        p = &( (*p)->m_pNext );
    }
    return false;
}



template <typename T>
bool findR(T d, NodoDLL<T>*p){
    if(!p) return false;
    if( p->m_dato == d ) return true;
    if(p->m_dato > d) return false;
    return findR(d,p->m_pNext);
}



template <typename T>
bool DoubleLinkedList<T>::Add(T d){
    NodoDLL<T>**q;
    if( findI(d,q) )return false;
    // std::cout << "paso el find" << '\n';
    NodoDLL<T> *nuevo = new NodoDLL<T>(d);
    if(isEmpty()){ //cabeza vacia;
        m_pHead = m_pLast = nuevo;
        return true;
    }
    //para el cuerpo y el cuerpo
    if(*q){
        nuevo->m_pNext = *q;
        nuevo->m_pPrev = (*q)->m_pPrev;
        (*q)->m_pPrev = nuevo;
        (*q) = nuevo;return true;
    }
    //para el ultimo
    nuevo->m_pPrev = m_pLast;
    m_pLast->m_pNext = nuevo;
    m_pLast = nuevo; return true;
}



template <typename T>
bool DoubleLinkedList<T>::deleteFront(){
    if(!m_pHead)return false;
    NodoDLL<T>*temp = m_pHead;
    m_pHead = m_pHead->m_pNext;
    m_pHead->m_pPrev = 0;
    delete temp;
}

template <typename T>
bool DoubleLinkedList<T>::deleteLast(){
    if(!m_pHead)return false;
    NodoDLL<T> *temp =m_pLast;
    m_pLast = m_pLast->m_pPrev;
    m_pLast->m_pNext = 0;
    delete temp;
}

template <typename T>
bool DoubleLinkedList<T>::Delete(T d){
    NodoDLL<T>**q;
    if( findI(d,q) ){
        NodoDLL<T> *temp = (*q);
        if( (*q) == m_pHead ){ //elimina el primero
            m_pHead = m_pHead->m_pNext;
            m_pHead->m_pPrev =0;
            delete temp; return true;
        }
        if( (*q) == m_pLast ){
            m_pLast = m_pLast->m_pPrev;
            m_pLast->m_pNext = 0;
            delete temp; return true;
        }
        temp->m_pPrev->m_pNext = temp->m_pNext;
        temp->m_pNext->m_pPrev = temp->m_pPrev;
        delete temp;return true;
    }
    return false;
}








// end doubleLinkedList.tpp
