
template<typename T>
void LinkedList<T>::push_front(T d){
     Nodo<T>  *pNuevo   =  new Nodo<T>(d);
     if ( !m_pHead )
          m_pHead = m_pLast = pNuevo;
     else
      {
          pNuevo->m_pSig = m_pHead;
          m_pHead = pNuevo;
      }
}



template<typename T>
void LinkedList<T>::push_back(T d){
    Nodo<T>  *pNuevo   =  new Nodo<T>(d);
     if ( !m_pHead )
          m_pHead = m_pLast = pNuevo;
     else
      {
          m_pLast->m_pSig = pNuevo;
          m_pLast=pNuevo;
      }
}


template<typename T>
void LinkedList<T>::pop_front(){
    if(!m_pHead) return;
    Nodo<T>  *temp = m_pHead;
    m_pHead = m_pHead->m_pSig;
    delete temp;
}



template<typename T>
void LinkedList<T>::pop_back(){
    if(!m_pHead) return;
    if(m_pHead == m_pLast){
        delete m_pHead;
        m_pHead = m_pLast =0;
    }
    Nodo<T>  *tmp = m_pHead;
    for(  ; tmp->m_pSig!=m_pLast; tmp = tmp->m_pSig);
    delete m_pLast;
    m_pLast = tmp;
    m_pLast->m_pSig = 0;
}

template <typename T>
bool LinkedList<T>::find_iterativo(T d){
    if(!m_pHead)return false;
    Nodo<T> *temp = m_pHead;
    while(temp){
        if(temp->m_Dato == d)return true;
        temp = temp->m_pSig;
    }
    return false; //llego al final y no esta dicho dato
}


template<typename T>
bool LinkedList<T>::find_recursivo(T d, Nodo<T>*p){
    if(!p)return false;
    if(p->m_Dato == d) return true;
    find_recursivo(d,p->m_pSig);
}


template<typename T>
void LinkedList<T>::print(){
    Nodo<T> *temp = m_pHead;
    for( ; temp != m_pLast; temp = temp->m_pSig){
        std::cout << temp->m_Dato << ' ';
    }
    //temp queda al nodo final
    std::cout << temp->m_Dato;
    std::cout << "\n";
}



template<typename T>
void LinkedList<T>::Add(T d, Nodo<T> * & p){
  if(!p){
      p = new Nodo<T>(d);
      m_pLast = p;
       return;
  }
  Add(d, p->m_pSig);
}


template<typename type>
bool LinkedList<type>::isEmpty(){
    if(!m_pHead)return true;
    return false;
}


/*
    UNION DE DOS LISTAS ENLAZADAS
*/
template<typename T>
LinkedList<T> *LinkedList<T>::Union(LinkedList<T> *&ll){
    LinkedList<T> *nueva  = new LinkedList<T>();
    nueva->setHead(m_pHead);
    m_pLast->m_pSig = ll->getHead();
    nueva->setLast(ll->getLast());
    return nueva;
}





//end .tpp
