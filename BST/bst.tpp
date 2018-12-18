
/*
    menbers functions
    bool AddR(T d, NodoBST<T>*&);
    bool findR(T d, NodoBST<T>*);
    bool findI(T);
    bool AddI(T);
*/


template <typename T>
bool Bst<T>::AddR(T d, NodoBST<T>*&p){
    if(!p){
        p = new NodoBST<T>(d);return true;
    }
    if (p->m_Dato == d)return false;
    return AddR(d,p->m_pSon[ p->m_Dato < d ]);
}


template <typename T>
bool Bst<T>::findR(T d, NodoBST<T>*p){
    if(!p) return false;
    if(p->m_Dato == d) return true;
    return findR(d,p->m_pSon[ p->m_Dato < d ]);
}



template <typename T>
bool Bst<T>::findI(T d){
    NodoBST<T>*temp = m_pRoot;
    if(!temp)return false;
    while(temp){
        if(temp->m_Dato==d)return true;
        temp = temp->m_pSon[ temp->m_Dato < d ];
    }
    return false;
}


template <typename T>
bool Bst<T>::AddI(T d){
    if(!m_pRoot){
        NodoBST<T>*nuevo = new NodoBST<T>(d);
        m_pRoot = nuevo;return true;
    }
    NodoBST<T> *p,*q;
    p = q = m_pRoot;
    while(p){
        q = p;
        if(p->m_Dato==d) return false;
        p = p->m_pSon[ p->m_Dato < d ];
    }
    q->m_pSon[ q->m_Dato < d ] = new NodoBST<T>(d);
    return true;
}
















//end bst.tpp
