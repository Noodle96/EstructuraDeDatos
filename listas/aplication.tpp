
/*
    AGREGA ORDENADAMENTE CADA NODO DESDE EL PRINCIPIO
*/
template <typename T>
void LinkedList<T>::addOrdenadamente(T d){
    if(!m_pHead){
        Nodo<T>*nuevo = new Nodo<T>(d);
        m_pHead = m_pLast = nuevo; return;
    }
    //primer caso cuando el dato es menor que la cabeza
    Nodo<T> *cur, *next; cur = next = m_pHead;
    if(d == cur->m_Dato) return;
    if(d < cur->m_Dato){
        Nodo<T>*nuevo = new Nodo<T>(d);
        nuevo->m_pSig = cur;
        m_pHead = nuevo; return;
    }
    //si no es igual ni menor es mayor ; empezamos con el next
    next = cur->m_pSig;
    while(next){
        if(d == next->m_Dato)return;
        if(d < next->m_Dato){
            Nodo<T>*nuevo = new Nodo<T>(d);
            //hacemos el puente
            nuevo->m_pSig = next;
            cur->m_pSig = nuevo;return;
        }
        //si no es menor o igual es mayor , entonces
        cur = cur->m_pSig;
        next = next->m_pSig;

    }
    Nodo<T>*nuevo = new Nodo<T>(d);
    cur->m_pSig = nuevo;
    m_pLast = nuevo;return;
}




/*
    INVIERTE UNA LISTA UTILIZANDO SOLO PUNTEROS (SIN UTILZAR OTRA LISTA)
*/
template <typename T>
void LinkedList<T>::invertir(){
    if(!m_pHead)return;
    Nodo<T> *first, *flotante; first = m_pHead; flotante = first->m_pSig;
    if(!flotante)return;
    while(first->m_pSig){
        first->m_pSig = flotante->m_pSig;
        //como ya guardamos en sgte de flotante, a este le movemos a la cabeza
        flotante->m_pSig = m_pHead;
        m_pHead = flotante;
        flotante = first->m_pSig;
    }
    m_pLast = first;
}



/*
    IMPRIME RECURSIVAMENTE PERO DE ATRAS PARA ADELANTE
*/
template <typename T>
void LinkedList<T>::imprimirRecursivoAlReves(Nodo<T>*p){
    if(!p)return;
    imprimirRecursivoAlReves(p->m_pSig);
    std::cout << p->m_Dato << ' ';
}




/*
    DE UNA ARCHIVO .TXT DE NOMBRE INSERTA A UNA LISTA ENLAZADA
*/
template <typename T>
void LinkedList<T>::insertaOfFile(){
    fstream data;
    std::string name;
    data.open("nombres.txt");
    data >> name;
        while(!data.eof()){
            push_back(name);
            data >> name;
        }
    data.close();
}



/*
    UNION E INTERSECCION DE DOS LISTAS
*/

template <typename T>
LinkedList<T> *LinkedList<T>::InterseccionL(LinkedList<T> *l2){
    LinkedList<T> *nueva = new LinkedList<T>();
    Nodo<T> *temp1 = m_pHead;
    Nodo<T> *temp2 = l2->getHeadP();

    for( ; temp1 ; temp1 = temp1->m_pSig){
        if( find_recursivo(temp1->m_Dato,temp2) ){
            // nueva->Add(temp1->m_Dato, nueva->getHead());
            nueva->push_back(temp1->m_Dato);
        }
    }
    return nueva;
}

template <typename T>
LinkedList<T> *LinkedList<T>::UnionL(LinkedList<T>*l2){
    LinkedList<T> *nueva = new LinkedList<T>();
    //copiando la primera lista entera a la nueva
    nueva->setHead(m_pHead);
    nueva->setLast(m_pLast);
    Nodo<T> *temp1 = m_pHead;
    Nodo<T> *temp2 = l2->getHeadP();
    for( ; temp2 ; temp2 = temp2->m_pSig){
        if( !find_recursivo(temp2->m_Dato,temp1) ){
            // nueva->Add(temp1->m_Dato, nueva->getHead());
            nueva->push_back(temp2->m_Dato);
        }
    }
    return nueva;

}
























//end aplication.tpp
