
/*
    int nivelNodo(T);
*/

template <typename T>
int Bst<T>::nivelNodo(T d){
    if(!m_pRoot)return 0;
    int cont = 0;
    NodoBST<T> *p = m_pRoot;
    while(p){
        if(p->m_Dato == d)return cont;
        p = p->m_pSon[ p->m_Dato < d ];
        cont++;
    }
    return -1;
}
