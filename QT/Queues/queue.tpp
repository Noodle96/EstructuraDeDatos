/*
    functions members
    bool isEmpty();
    bool push(T);
    bool pop();
    T top();
    void print();
*/

template <typename T>
bool Queue<T>::isEmpty(){
    return(!m_pFirst);
}


template <typename T>
bool Queue<T>::push(T d){
    NodoQ<T> *nuevo = new NodoQ<T>(d);
    if(!m_pFirst){
        m_pFirst = m_pLast = nuevo; return true;
    }
    m_pLast->m_pSgte = nuevo;
    m_pLast = nuevo;return true;
}


template <typename T>
bool Queue<T>::pop(){
    if(!m_pFirst) return false;
    NodoQ<T> *temp = m_pFirst;
    m_pFirst = m_pFirst->m_pSgte;
    delete temp;return true;
}


template <typename T>
T Queue<T>::top(){
    T res;
    if(m_pFirst) res = m_pFirst->getDato();
    return res;
}


template <typename T>
void Queue<T>::print(){
    NodoQ<T> *temp = m_pFirst;
    for( ;temp ; temp = temp->m_pSgte){
        std::cout << temp->getDato() << ' ';
    }
    std::cout  << '\n';
}


//end queue.tpp
