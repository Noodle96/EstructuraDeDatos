/*
    FUNCIONES QUE SERAN UTILIZADAS EN APLICACIONES VERDADERAS
    bool findR(T,Nodo<T>**&);
    bool AddR(T);
    bool deleteR(T);
    void printR(Nodo<T>*)
*/



/*
    FUNCION QUE BUSCA CIERTO NODO EN CASO NO, PUES LE DEJA JUSTO EN LA POSICION
    DONDE DEBE DE SER AGREGADO
*/
template <typename T>
bool LinkedList<T>::findR(T d, Nodo<T>**&p){
    p = &(m_pHead); // p guarda la direccion de la direccion de un nodo
    while(*p){
        if( ((*p)->m_Dato)==(d) ) return true;
        if( ((*p)->m_Dato)>(d) ) return false;
        p = &((*p)->m_pSig);
    }
    return false;
}



/*
    FUNCION QUE INSERTA UN NODO, USANDO LA FUNCION FINDR EL CUAL EVITA
    REPETICIONES
*/
template <typename T>
bool LinkedList<T>::AddR(T d){
    Nodo<T>**q;
    if( !findR(d,q) ){
        Nodo<T> *nuevo = new Nodo<T>(d);
        nuevo->m_pSig = *q;
        // cout << "aqui error" << endl;
        *q = nuevo;
        return true;
    }
    return false;
}


template <typename T>
bool LinkedList<T>::deleteR(T d){
    Nodo<T>**q;
    if( findR(d,q) ){
        Nodo<T> *temp = (*q)->m_pSig;
        delete *q;
        *q = temp;
        return true;
    }
    return false;
}



/*
    IMPRIME LA LISTA ENLZADA
*/
template <typename T>
void LinkedList<T>::printR(Nodo<T>*p){
    if(!p){std::cout<< '\n';return;}
    std::cout << p->m_Dato << "\n" ;
    printR(p->m_pSig);
}





























//end funcionesPrincipales.tpp
