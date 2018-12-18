/*
    Menbers functions of Stack:
    bool isEmpty();
    bool push(T);
    bool pop();
    T top();
    void print();
*/


template <typename T>
bool Stack<T>::isEmpty(){
    return(!m_pTope);
}


template <typename T>
bool Stack<T>::push(T d){
    NodoS<T> *nuevo = new NodoS<T>(d);
    if(!m_pTope){
        m_pTope = nuevo;return true;
    }
    nuevo->m_pSgte = m_pTope;
    m_pTope = nuevo;return true;
}


template <typename T>
bool Stack<T>::pop(){
    if(!m_pTope)return false;
    NodoS<T>  *temp = m_pTope;
    m_pTope = m_pTope->m_pSgte;
    delete temp;
    return true;
}

template <typename T>
T Stack<T>::top(){
    T res;
    if(m_pTope) res = m_pTope->getDato();
    return res;
}


template <typename T>
void Stack<T>::print(){
    NodoS<T>*temp = m_pTope;
    for( ; temp ; temp = temp->m_pSgte){
        std::cout << temp->getDato() << std::endl;
    }
    std::cout  << '\n';
}




//end stack.tpp
